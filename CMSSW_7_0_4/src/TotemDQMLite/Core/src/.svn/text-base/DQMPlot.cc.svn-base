/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/DQMPlot.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

void DQMPlot::ProcessLabel()
{
  guiLabel = label;
  size_t idx = guiLabel.find(";");
  if (idx != string::npos)
    guiLabel.erase(idx);
}
