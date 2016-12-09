#ifndef HeavyFlavorAnalysis_h
#define HeavyFlavorAnalysis_h

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/Math/interface/LorentzVector.h"

#include <vector>
#include <string>
#include <map>

class HeavyFlavorEvent;

namespace heavyFlavorAnalysis {

class HeavyFlavorAnalysis {
   public:
      typedef HeavyFlavorEvent event_type;
      static const char* name;

      HeavyFlavorAnalysis() {} 
      HeavyFlavorAnalysis(const edm::ParameterSet&);
      ~HeavyFlavorAnalysis();

      void begin();
      void begin(const edm::Run&, const edm::EventSetup&);
      void fill(HeavyFlavorEvent&, const edm::Event&, const edm::EventSetup&);
      void end();
   private:
      //void fillEventInfo(HeavyFlavorEvent&, const edm::Event&, const edm::EventSetup&);
 
      edm::InputTag jetTag_;

};

} // namespace
#endif 
