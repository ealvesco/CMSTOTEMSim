/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/PlotManager.h"
#include "TotemDQMLite/Core/interface/SingleRootPlot.h"
#include "TotemDQMLite/Core/interface/DQMExceptions.h"

#include "TFile.h"
#include <iostream>

using namespace std;

PlotManager plotManager;

//----------------------------------------------------------------------------------------------------

void PlotManager::Register(const std::string &path, const std::string &title, DQMPlot *n)
{
  plotManager.plots[path] = n;
  n->label = title;
  n->ProcessLabel();
  n->SetNameTitle(title, title);
  plotManager.plotsNameOrder.push_back(std::string(path));
}

//----------------------------------------------------------------------------------------------------

void PlotManager::Register(const std::string &path, const std::string &title, TNamed *n,
    const string &opt, bool own)
{
  SingleRootPlot *srp = new SingleRootPlot(title, n, opt, own);
  Register(path, title, srp);
}

//----------------------------------------------------------------------------------------------------

void PlotManager::RegisterRP(TotRPDetId::ElementLevel level, unsigned int id,
    std::string label, const std::string &title, DQMPlot *n)
{
  Register(TotRPDetId::OfficialName(level, id, TotRPDetId::nPath) + "/" + label,
    TotRPDetId::OfficialName(level, id) + " : " + title, n);
}

//----------------------------------------------------------------------------------------------------

void PlotManager::RegisterRP(TotRPDetId::ElementLevel level, unsigned int id, std::string label,
    const std::string &title, TNamed *n, const std::string &opt, bool own) {
  RegisterRP(level, id, label, title, new SingleRootPlot(title, n, opt, own));
}

//----------------------------------------------------------------------------------------------------

void PlotManager::Clear()
{
  for (collection::const_iterator it = plotManager.plots.begin(); it != plotManager.plots.end(); it++)
    delete it->second;

  plotManager.plots.clear();
  plotManager.plotsNameOrder.clear();
}

//----------------------------------------------------------------------------------------------------

DQMPlot* PlotManager::Get(const std::string &path)
{
  collection::iterator it = plotManager.plots.find(path);
  return (it != plotManager.plots.end()) ? it->second : NULL;
}

//----------------------------------------------------------------------------------------------------

void PlotManager::SaveAs(std::string fileName)
{
  printf(">> PlotManager::SaveAs > Started.\n");

  TFile *f = new TFile(fileName.c_str(), "recreate");
  if (f->IsZombie())
    throw UnknownMonitorException();

  for (collection::iterator iter = plotManager.plots.begin(); iter != plotManager.plots.end(); iter++)
  {
    // make directory structure
    gDirectory = f;
    const string &path = iter->first;
    size_t index = 0;
    while (true)
    {
      size_t nIndex = path.find('/', index);
      if (nIndex == string::npos)
        break;
      
      string dirName = path.substr(index, nIndex-index);
      TDirectory *dir = (TDirectory *) gDirectory->Get(dirName.c_str());
      if (!dir)
        dir = gDirectory->mkdir(dirName.c_str());
      gDirectory = dir;

      index = nIndex+1;
    }   

    // write the object 
    iter->second->Write();
  }

  delete f;

  printf(">> PlotManager::SaveAs > Finished.\n");
}
