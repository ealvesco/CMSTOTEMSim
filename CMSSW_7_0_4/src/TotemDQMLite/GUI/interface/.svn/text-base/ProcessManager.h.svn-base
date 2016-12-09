/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#ifndef _ProcessManager_h_
#define _ProcessManager_h_

#include <string>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>

#include "DataFormats/FWLite/interface/ChainEvent.h"

#include "TotemDQMLite/Core/interface/DQMModule.h"
#include "TotemDQMLite/Core/interface/PlotManager.h"

#include "TFile.h"

/**
 * \ingroup TotemDQM
 * \brief A singleton class responsible for processing the events
 */
class ProcessManager
{
  public:
    /// TODO: describe
    ProcessManager();

    /// TODO: describe
    ~ProcessManager();

    /// Loads python config file and initialises the requested modules.
    /// Returns 0 in case of success.
    int InitializeModules(const std::string &configFileName);

    /// Deletes each of the modules and clears their collection.
    void ReleaseModules();
    
    /// Checks whether all input files are readable and initializes the chain Event.
    /// Returns 0 in case of success.
    int LoadInputFiles(const std::vector<std::string> &inputRecoFiles);

    /// TODO: describe
    void CloseInputFiles();
    
    /// starts cumulative processing of events
    void RunCumulativeProcessing();

    /// re-processes a selected event
    /// returns true in case of success (event exists)
    bool RunSingleEventProcessing(unsigned int runNr, unsigned int eventNr);

    /// returns the path to the default configuration file
    static std::string GetDefaultConfigFile();

    /// returns the single instance of ProcessManager
    static ProcessManager& GetInstance()
    {
      static ProcessManager instance;
      return instance;
    }
    
    struct RunEventStruct
    {
      unsigned int runNr;
      unsigned int eventNr;
    };

    /// Moves to the next event
    RunEventStruct NextEvent();

    /// Moves to the previous event
    RunEventStruct PreviousEvent();

    /// Structure holding min/max event number per run.
    struct RunInfo
    {
      unsigned int minEventNr;
      unsigned int maxEventNr;
    };

    const std::map<unsigned int, RunInfo>& GetRunInfo() const
    {
      return runInfo;
    }

  private:
    /// collection of DQM modules
    std::vector<DQMModule*> modules;
    
    /// current event
    /// NULL, when no files open
    fwlite::ChainEvent *chainEvent;
    
    /// map: run id --> run info
    std::map<unsigned int, RunInfo> runInfo;

    /// flag whether the cumulative-processing loop should be interrupted
    static bool stopFlag;

    /// handler for Ctrl-C signal
    static void InterruptHandler(int signum);
};

#endif
