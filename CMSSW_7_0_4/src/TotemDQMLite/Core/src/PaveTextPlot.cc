/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/PaveTextPlot.h"

#include "TClass.h"
#include "TPaveText.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

PaveTextPlot::PaveTextPlot(std::string _l, TPaveText *_obj, bool _own) : 
  DQMPlot(_l, _own), obj(_obj)
{
}

//----------------------------------------------------------------------------------------------------

PaveTextPlot::~PaveTextPlot()
{
  if (isOwner && obj)
    delete obj;
}

//----------------------------------------------------------------------------------------------------

void PaveTextPlot::SetNameTitle(std::string name, std::string title)
{
}

//----------------------------------------------------------------------------------------------------

void PaveTextPlot::Reset()
{
  if (!obj)
    return;

  obj->Clear();
}

//----------------------------------------------------------------------------------------------------

void PaveTextPlot::Draw()
{
  if (!obj)
	  return;

  obj->Draw();
}

//----------------------------------------------------------------------------------------------------

void PaveTextPlot::Write()
{
  if (obj)
    obj->Write(label.c_str());
}

//----------------------------------------------------------------------------------------------------

void PaveTextPlot::Print()
{
  printf("PaveTextPlot at %p\n", (void *)this);
}
