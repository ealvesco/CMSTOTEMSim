/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/SingleRootPlot.h"

#include "TClass.h"
#include "TH1.h"
#include "TH2.h"
#include "THnSparse.h"
#include "TGraph.h"
#include "TPad.h"

using namespace std;

SingleRootPlot singleRootOutputEmpty;

//----------------------------------------------------------------------------------------------------

SingleRootPlot::SingleRootPlot(std::string _l, TNamed *_obj, std::string _opt, bool _own) : 
  DQMPlot(_l, _own), obj(_obj), opt(_opt)
{
  if (opt.empty())
    GetDefaultOption(obj, opt);
}

//----------------------------------------------------------------------------------------------------

SingleRootPlot::~SingleRootPlot()
{
  if (isOwner && obj)
    delete obj;
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::GetDefaultOption(TNamed *n, string &opt)
{
  opt = "";
    
  if (!n)
    return;

  if (n->IsA()->InheritsFrom("TGraph"))
    opt = "ap";
  if (n->IsA()->InheritsFrom("TH2"))
    opt = "colz";  
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::SetNameTitle(std::string name, std::string title)
{
  if (!obj)
    return;

  obj->SetTitle(title.c_str());
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::Reset(TNamed *o)
{
  if (!o)
    return;

  if ( o->InheritsFrom("TH") ) { ((TH1*)o)->Reset(); return; }
  if ( o->InheritsFrom("TGraph") ) { ((TGraph*)o)->Set(0); return; }
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::Draw()
{
  if (!obj) return;
  if ( obj->InheritsFrom("TGraph") ) 
  if (((TGraph*)obj)->GetN() == 0)return;

  TNamed *drawnObj = obj;
  if (drawnObj->InheritsFrom("THnSparse")) { 
    drawnObj = ((THnSparse*)drawnObj)->Projection(1, 0, "");
    drawnObj->SetTitle(label.c_str());
  }

  if ( drawnObj->InheritsFrom("TH2")) {
    gPad->SetTheta(75);
    gPad->SetPhi(-95);
  }

  drawnObj->Draw(opt.c_str());
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::Write()
{
  if (obj)
    obj->Write(label.c_str());
}

//----------------------------------------------------------------------------------------------------

void SingleRootPlot::Print()
{
  printf("SingleRootPlot at %p\n", (void *)this);
}
