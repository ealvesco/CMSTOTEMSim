/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "TotemDQMLite/Modules/interface/TrackInRPFigure.h"

#include "Geometry/TotemRPDetTopology/interface/RPTopology.h"

#include "TView.h"
#include "TPad.h"
#include "TAxis3D.h"

#include <cmath>

TrackInRPFigure::TrackInRPFigure(unsigned int RPId, const TotemRPGeometryLite *geom, std::string l, bool drawAllPlanes) : DQMPlot(l, true)
{
#ifdef DEBUG
  cout << ">> TrackInRPFigure::TrackInRPFigure(" << RPId << ")\n";
#endif

  // shape of one plane in U-V projection
  double C1 = RPTopology::x_width_ / 2.;
  double C2 = C1 - RPTopology::phys_edge_lenght_ / sqrt(2.);

  double u[6] = {+C1, +C1, -C1, -C1, -C2, +C1};
  double v[6] = {-C1, +C1, +C1, -C2, -C1, -C1};

  // RP geometry
  sh_x = geom->GetRPPosition(RPId).x();
  sh_y = geom->GetRPPosition(RPId).y();

  double z0 = geom->GetRPPosition(RPId).z();   // "common" z
  CLHEP::Hep3Vector rod_U = geom->GetRPMeanUDirection(RPId);
  CLHEP::Hep3Vector rod_V = geom->GetRPMeanVDirection(RPId);

  // build shapes of all planes
  for (unsigned int i = 0; i < 10; i++)
  {
    unsigned int plId = RPId*10 + i; 

    // if not all planes shall be drawn, skip middle ones
    if (!drawAllPlanes && i > 0)
      i = 9;
    
    CLHEP::Hep3Vector pos = geom->GetSensorPosition(plId);

    double z = pos.z() - z0;
    if (i == 0)
      z1 = z;
    if (i == 9)
      z2 = z;

    double a_x[6], a_y[6], a_z[6];
    for (unsigned int i = 0; i < 6; i++)
    {
      a_x[i] = rod_U.x() * u[i] + rod_V.x() * v[i] + pos.x();
      a_y[i] = rod_U.y() * u[i] + rod_V.y() * v[i] + pos.y();
      a_z[i] = z;
    }

    TPolyLine3D *det = new TPolyLine3D(6, a_z, a_x, a_y);
    det->ResetBit(kCanDelete);
    dets.push_back(det);
  }

  if (z1 > z2)
    swap(z1, z2);

#ifdef DEBUG
  cout << "\t" << "z0 = " << z0 << ", z1 = " << z1 << ", z2 = " << z2 << endl;
#endif
}

//----------------------------------------------------------------------------------------------------

TrackInRPFigure::~TrackInRPFigure()
{
  Reset();

  for (unsigned int i = 0; i < dets.size(); ++i)
    delete dets[i];
}

//----------------------------------------------------------------------------------------------------

void TrackInRPFigure::Draw()
{
#ifdef DEBUG
  printf(">> TrackInRPFigure::Draw\n");
#endif

  // TODO: x increases left to right!
  TView *view = gPad->GetView();
  if (!view)
    view = TView::CreateView(1, 0, 0);

  for (unsigned int i = 0; i < dets.size(); ++i)
    dets[i]->Draw();

  for (unsigned int i = 0; i < tracks.size(); i++)
    tracks[i]->Draw();

#ifdef DEBUG
  printf("SetRange(%f, %f, %f, %f, %f, %f)\n", z1-10, sh_x-30, sh_y-30, z2+10, sh_x+30, sh_y+30);
#endif
  view->SetRange(z1-10, sh_x-30, sh_y-30, z2+10, sh_x+30, sh_y+30); // order z, x, y
  //view->SetPerspective();
  view->SetParallel();
  //view->Centered();
  view->AdjustScales();
  view->ShowAxis();

  TAxis3D *axis = TAxis3D::GetPadAxis();
  if (axis)
  {
    axis->SetXTitle("z - z_{0}");
    axis->SetYTitle("x");
    axis->SetZTitle("y");
  } 

#ifdef DEBUG
  printf("\tend\n");
#endif
}

//----------------------------------------------------------------------------------------------------

void TrackInRPFigure::Write()
{
  printf(">> TrackInRPFigure::Write : not yet implemented\n");
}

//----------------------------------------------------------------------------------------------------

void TrackInRPFigure::Reset()
{
  for (unsigned int i = 0; i < tracks.size(); i++)
    delete tracks[i];
  tracks.clear();
}

//----------------------------------------------------------------------------------------------------

void TrackInRPFigure::AddTrack(double ax, double bx, double ay, double by)
{
  double x[] = {ax*z1 + bx, ax*z2 + bx};
  double y[] = {ay*z1 + by, ay*z2 + by};
  double z[] = {z1, z2};

  TPolyLine3D *bla = new TPolyLine3D(2, z, x, y);
  bla->ResetBit(kCanDelete);
  bla->SetLineColor(4);
  bla->SetLineWidth(3);
  tracks.push_back(bla);
}
