/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*  Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _Efficiency_h_
#define _Efficiency_h_

#include <map>
#include <set>

#include <TH1D.h>
#include <TH2D.h>

namespace edm
{
  class EventSetup;
  class Event;
}

class RPTrackCandidateCollection;
class RPFittedTrackCollection;
class TotemRPGeometry;

class Efficiency
{
  public:

    struct PotPlots
    {
      TH1D *hit_pos_det[10];
      TH1D *hit_fit_det[10];
      TH1D *h_array_eff[10];

      PotPlots();
    };

    std::map<unsigned int, PotPlots> plots;

    void Analyze(const RPTrackCandidateCollection *selHits, const RPFittedTrackCollection *tracks, const TotemRPGeometry *geometry);

    void beginJob();
    void endJob();
};

#endif
