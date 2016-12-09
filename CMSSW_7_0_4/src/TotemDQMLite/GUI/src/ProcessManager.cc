/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#include <csignal>
#include <cassert>

#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/FWLite/interface/Handle.h"
#include "FWCore/FWLite/interface/AutoLibraryLoader.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h"

#include "TotemDQMLite/GUI/interface/ProcessManager.h"

#include "TotemDQMLite/Modules/interface/TotemDQMModuleDAQ.h"
#include "TotemDQMLite/Modules/interface/TotemDQMModuleRP.h"
#include "TotemDQMLite/Modules/interface/TotemDQMModuleT1.h"
#include "TotemDQMLite/Modules/interface/TotemDQMModuleT2.h"

#include "TSystem.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

string ProcessManager::GetDefaultConfigFile()
{
  return string(getenv("CMSSW_BASE")) + "/src/TotemDQMLite/GUI/python/TotemDQMLite_all_cfg.py";
}

//----------------------------------------------------------------------------------------------------

ProcessManager::ProcessManager() :
  chainEvent(NULL)
{
  // load FWLite libraries
  gSystem->Load("libFWCoreFWLite");
  AutoLibraryLoader::enable();
}

//----------------------------------------------------------------------------------------------------

ProcessManager::~ProcessManager()
{
  if (!modules.empty())
    ReleaseModules();
  
  if (chainEvent != NULL)
    CloseInputFiles();
}

//----------------------------------------------------------------------------------------------------

int ProcessManager::InitializeModules(const std::string &configFileName)
{
  assert(modules.empty());
  
  // use default config if nothing specified
  string cfn = (configFileName.empty()) ? GetDefaultConfigFile() : configFileName;
  
  try
  {
    // load config file
    boost::shared_ptr<edm::ParameterSet> cfg = edm::readPSetsFrom(cfn);
  
    // load configuration of each module (if exists)
    if (cfg->existsAs<edm::ParameterSet>("TotemDQMModuleDAQ"))
    {
      const edm::ParameterSet &ps = cfg->getParameter<edm::ParameterSet>("TotemDQMModuleDAQ");
      modules.push_back(new TotemDQMModuleDAQ(ps));
    }
  
    if (cfg->existsAs<edm::ParameterSet>("TotemDQMModuleRP"))
    {
      const edm::ParameterSet &ps = cfg->getParameter<edm::ParameterSet>("TotemDQMModuleRP");
      modules.push_back(new TotemDQMModuleRP(ps));
    }
  
    if (cfg->existsAs<edm::ParameterSet>("TotemDQMModuleT1"))
    {
      const edm::ParameterSet &ps = cfg->getParameter<edm::ParameterSet>("TotemDQMModuleT1");
      modules.push_back(new TotemDQMModuleT1(ps));
    }
  
    if (cfg->existsAs<edm::ParameterSet>("TotemDQMModuleT2"))
    {
      const edm::ParameterSet &ps = cfg->getParameter<edm::ParameterSet>("TotemDQMModuleT2");
      modules.push_back(new TotemDQMModuleT2(ps));
    }
  }

  catch (cms::Exception &e)
  {
    printf(">> ProcessManager::InitializeModules > Caught CMS exception:\n%s\n", e.what());
    return 1;
  }
  
  return 0;
}

//----------------------------------------------------------------------------------------------------

void ProcessManager::ReleaseModules()
{
  for (auto m : modules)
    delete m;

  modules.clear();
}

//----------------------------------------------------------------------------------------------------

int ProcessManager::LoadInputFiles(const vector<std::string> &inputRecoFiles)
{
  assert(chainEvent == NULL);

  // check whether all files are readable
  bool allReadable = true;
  for (const auto &fn : inputRecoFiles)
  {
    TFile *file = TFile::Open(fn.c_str());
    if (!file)
      allReadable = false;
    if (file)
      delete file;
  }

  if (!allReadable)
    return 1;

  // open the file collection
  try
  {
    chainEvent = new fwlite::ChainEvent(inputRecoFiles);
  }

  catch (cms::Exception &e)
  {
    printf(">> ProcessManager::LoadInputFiles > Caught CMS exception:\n%s\n", e.what());
    return 2;
  }

  return 0;
}

//----------------------------------------------------------------------------------------------------

void ProcessManager::CloseInputFiles()
{
  // reset state
  runInfo.clear();

  delete chainEvent;
  chainEvent = NULL;

}

//----------------------------------------------------------------------------------------------------

void ProcessManager::RunCumulativeProcessing()
{
  // run beginJob for all modules
  for (auto m : modules)
    m->beginJob();

  // setup interrupt handler for Ctrl-C
  stopFlag = false;
  signal(SIGINT, InterruptHandler);

  // declare cumulative processing
  dqmCumulativeMode = true;

  // reset run info
  runInfo.clear();

  // event loop
  for (chainEvent->toBegin(); !chainEvent->atEnd(); ++(*chainEvent))
  {
    // has been interrupted by user?
    if (stopFlag)
      break;

    edm::EventBase const &event = *chainEvent;

    // update run info
    unsigned int runNr = chainEvent->id().run();
    unsigned int eventNr = chainEvent->id().event();
    auto it = runInfo.find(runNr);
    if (it == runInfo.end())
    {
      runInfo[runNr] = {eventNr, eventNr};
    } else {
      it->second.minEventNr = min(it->second.minEventNr, eventNr);
      it->second.maxEventNr = max(it->second.maxEventNr, eventNr);
    }

    // run analysis by modules
    for (auto m : modules)
      m->analyze(event);
  }

  // disable the interrupt handler
  signal(SIGINT, SIG_DFL);

  // run endJob for all modules
  for (auto m : modules)
    m->endJob();
}

//----------------------------------------------------------------------------------------------------

bool ProcessManager::stopFlag = false;

//----------------------------------------------------------------------------------------------------

void ProcessManager::InterruptHandler(int signum)
{
  stopFlag = true;
}

//----------------------------------------------------------------------------------------------------

bool ProcessManager::RunSingleEventProcessing(unsigned int runNr, unsigned int eventNr)
{
  dqmCumulativeMode = false;

  int runNum = runNr;
  int evNum = eventNr;
  bool jumpResult = chainEvent->to(runNum, evNum);
  if (!jumpResult)
    return false;

  edm::EventBase const & event = *chainEvent;
  for (auto m : modules)
    m->analyze(event);

  return true;
}

//----------------------------------------------------------------------------------------------------

ProcessManager::RunEventStruct ProcessManager::NextEvent()
{
  ++(*chainEvent);
  RunEventStruct runEventStruct;
  runEventStruct.runNr = chainEvent->id().run();
  runEventStruct.eventNr = chainEvent->id().event();
  return runEventStruct;
}

//----------------------------------------------------------------------------------------------------

ProcessManager::RunEventStruct ProcessManager::PreviousEvent()
{
  ProcessManager::RunEventStruct runEventStruct;
  bool jumpResult = false;
  unsigned int runNum = chainEvent->id().run();
  unsigned int inputRunNum = chainEvent->id().run();
  unsigned int inputEvNum = chainEvent->id().event();
  unsigned int newEvNum = chainEvent->id().event()-1;
  while (!jumpResult && newEvNum>=runInfo[runNum].minEventNr)
  {
    jumpResult = chainEvent->to(runNum, newEvNum);
    --newEvNum;
  }

  if (jumpResult)
  {
    ++newEvNum;

    runEventStruct.runNr = runNum;
    runEventStruct.eventNr = newEvNum;
    return runEventStruct;
  } else {
    vector<int> lowerRunNumbers;
    for(map<unsigned int, RunInfo>::iterator it = runInfo.begin(); it != runInfo.end(); ++it)
    {
      if(it->first < runNum)
        lowerRunNumbers.push_back(it->first);
    }
    sort(lowerRunNumbers.begin(), lowerRunNumbers.end(), greater<int>());

    for (auto runNr : lowerRunNumbers)
    {
      newEvNum = runInfo[runNr].maxEventNr;
      while (!jumpResult && newEvNum>=runInfo[runNr].minEventNr)
      {
        jumpResult = chainEvent->to(runNum, newEvNum);
        --newEvNum;
      }

      if (jumpResult)
      {
        ++newEvNum;

        runEventStruct.runNr = runNr;
        runEventStruct.eventNr = newEvNum;
        return runEventStruct;
      }
    }
  }

  runEventStruct.runNr = inputRunNum;
  runEventStruct.eventNr = inputEvNum;
  return runEventStruct;
}
