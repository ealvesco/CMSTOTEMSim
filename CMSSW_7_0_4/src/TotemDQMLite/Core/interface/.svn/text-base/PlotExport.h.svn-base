/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakovski
*
****************************************************************************/

#ifndef _PlotExport_h_
#define _PlotExport_h_

#include "TCanvas.h"

#include <string>
#include <vector>

class PlotExport
{
  public:
    PlotExport(std::string rootFileName, std::string plotFilePrefix, std::string plotFileSuffix, std::vector<std::string> layouts);
    void Save();

  private:
    TCanvas* MakeLayoutCanvas(const std::string &file);

    std::string rootFileName;
    std::string plotFilePrefix;
    std::string plotFileSuffix;
    std::vector<std::string> layouts;
};

#endif
