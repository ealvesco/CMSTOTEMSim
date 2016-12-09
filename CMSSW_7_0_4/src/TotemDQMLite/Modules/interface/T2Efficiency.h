/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*  Rafał Leszko (rafal.leszko@gmail.com)
*  Mirko Berretti (mirko.berretti@gmail.com)  
*
****************************************************************************/

#ifndef _T2Efficiency_h_
#define _T2Efficiency_h_

#include "FWCore/Utilities/interface/InputTag.h"

#include <map>
#include <set>
#include <memory>

#include <TH1D.h>
#include <TH2D.h>

namespace edm {
  class EventSetup;
  class EventBase;
}

class T2Efficiency {
  public:

    struct HalfTelePlots {
      TH1D *hit_pos_det[10];
      TH1D *hit_fit_det[10];
      TH1D *h_array_eff[10];
      TH1D *halfMeasRate;
      TH1D *halfExpRate;
      TH1D *halfEffi;
      //std::auto_ptr<TH1D> halfMeasRate;
      //std::auto_ptr<TH1D> halfExpRate;
      //std::auto_ptr<TH1D> halfEffi;

      HalfTelePlots();
    };

    std::map<unsigned int, HalfTelePlots> plots;

    void beginJob();
    void analyze(const edm::EventBase &e, const edm::InputTag &tagHitColl, const edm::InputTag &tagT1T2TrackColl);
    void endJob();
};

#endif
