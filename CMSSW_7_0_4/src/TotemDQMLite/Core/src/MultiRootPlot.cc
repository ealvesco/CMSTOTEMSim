/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/SingleRootPlot.h"
#include "TotemDQMLite/Core/interface/MultiRootPlot.h"

#include "TGraph.h"
#include "TPaveText.h"
#include "TF1.h"
#include "TFile.h"

#include <cassert>

using namespace std;

//----------------------------------------------------------------------------------------------------

MultiRootPlot::MultiRootPlot(std::string _l, bool _own) : DQMPlot(_l, _own)
{
  emptyGraph = new TPaveText();
  emptyGraph->SetTextSize(0.1);
  emptyGraph->SetTextAlign(11);
  emptyGraph->AddText("EMPTY GRAPH");
}

//----------------------------------------------------------------------------------------------------

MultiRootPlot::~MultiRootPlot()
{
  if (emptyGraph)
    delete emptyGraph;

  if (!isOwner)
    return;
  
  for (unsigned int i = 0; i < objs.size(); i++)
    delete objs[i].first;
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::SetNameTitle(std::string name, std::string title)
{
  if (!objs.size())
    return;

  // title of the first object drawn is shown
  assert(objs.size() > 0);
  objs[0].first->SetTitle(title.c_str());
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::Reset()
{
  for (unsigned int i = 0; i < objs.size(); i++)
    SingleRootPlot::Reset(objs[i].first);
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::Draw()
{
  for (unsigned int i = 0; i < objs.size(); i++)
  {
    TNamed *obj =  objs[i].first;
    if (!obj)
    {
      if (i == 0)
      {
        emptyGraph->Draw();
        break;
      } else {
        continue;
      }
    }

    if (obj->InheritsFrom("TGraph"))
    {
      if (((TGraph*)obj)->GetN() == 0)
      {
        if (i == 0)
        {
          emptyGraph->Draw();
          break;
        } else {
          continue;
        }
      }
    }

    obj->Draw(objs[i].second.c_str());
  }
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::Write()
{
  const char *dn = guiLabel.c_str();
  if (gDirectory->Get(dn))
  {
    printf("ERROR in MultiRootPlot::Write > Directory `%s' already exists.\n", dn);
    return;
  }

  gDirectory = gDirectory->mkdir(dn);
  for (unsigned int i = 0; i < objs.size(); i++)
      objs[i].first->Write();
  gDirectory->cd("..");
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::Print()
{
  printf("MultiRootPlot at %p\n", (void *)this);
}

//----------------------------------------------------------------------------------------------------

void MultiRootPlot::Release(unsigned int keepFirstN)
{
  for (unsigned int i = keepFirstN; i < objs.size(); i++)
    delete objs[i].first;

  objs.resize(keepFirstN);
}
