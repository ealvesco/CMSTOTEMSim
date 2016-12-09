/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _TrackInRPFigure_h_
#define _TrackInRPFigure_h_

#include "TotemDQMLite/Core/interface/DQMPlot.h"
#include "TotemDQMLite/Geometry/interface/TotemRPGeometryLite.h"

#include "TPolyLine3D.h"

#include <string>

/**
 * \ingroup TotemDQM
 * \brief Shows RP track(s) in 3D scene.
 **/
class TrackInRPFigure : public DQMPlot
{
  private:
    double z1, z2;                        ///< reduced (i.e. z - z0) positions of first and last plane
    double sh_x, sh_y;                    ///< shift of detector's center
    std::vector<TPolyLine3D *> dets;
    std::vector<TPolyLine3D *> tracks;

  public:
    TrackInRPFigure(unsigned int RPId, const TotemRPGeometryLite *geom, std::string _l = "Track in RP (3D)", bool drawAllPlanes = true);
    virtual ~TrackInRPFigure();

    virtual void SetNameTitle(std::string name, std::string title) {}
    virtual void Draw();
    virtual void Write();
    virtual void Reset();
    virtual void Print() {}

    /// adds a track to the list of tracks to be drawn
    /// bx and by are intercepts at z = z0
    virtual void AddTrack(double ax, double bx, double ay, double by);
};


#endif
