/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _CorrelationPlotsSelectorT2_h
#define _CorrelationPlotsSelectorT2_h

#include <string>
#include <map>
#include <set>

class CorrelationPlotsSelectorT2 {
  private:
    std::set<int> defaultPlaneIds;                              // default Planes for Correlation Plots
    std::set<int> emptyHalfTeles;                               // HalfTele with no Planes for Correlation Plots
    std::map<int, std::set<int> > specifiedHalfTelePlaneIds;    // HalfTele with other than default Planes for Correlation Plots

    bool MatrixHalfPlane[4][10];                                // [HalfId][PlaneId] - if Plane is v


  public:
    CorrelationPlotsSelectorT2(std::string filter);

    void ReadFilterString(std::string filter); // parsing configuration string "default=planeId1, planeId2, ...;  HTId1=planeId1,...; HTId2=planeId1,...;..."
    //bool IfCorrelate(unsigned int DetId);
    bool IfCorrelate(unsigned int HalfTeleTId, unsigned int PlaneId,unsigned int arm);
    // bool IfTwoCorrelate(unsigned int DetId1, unsigned int DetId2);
    // bool IfTwoCorrelate(unsigned int RPId1, unsigned int PlaneId1, unsigned int RPId2, unsigned int PlaneId2);
};

#endif
