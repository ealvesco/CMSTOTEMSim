#ifndef TotemAnalysis_TotemNtuplizer_RPTimingDetectorsNtuplizer_h
#define TotemAnalysis_TotemNtuplizer_RPTimingDetectorsNtuplizer_h

#include <DataFormats/TotemRPDataTypes/interface/RPTimingDetectorHit.h>
#include "TotemAnalysis/TotemNtuplizer/interface/Ntuplizer.h"
#include "FWCore/Framework/interface/Event.h"
#include "TTree.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizerHit.h"
#include <vector>
#include <map>

class RPTimingDetectorsNtuplizer : public Ntuplizer {
public:

    RPTimingDetectorsNtuplizer(const edm::ParameterSet&);
    virtual void CreateBranches(const edm::EventSetup&, TTree *);
    virtual void FillEvent(const edm::Event&, const edm::EventSetup&);

private:
    std::set<unsigned int> rp_ids = {
            1200, 1201, 1202, 1203,
            1210, 1211, 1212, 1213,
            200,  201,  202,  203,
            210,  211,  212,  213
    };
    std::set<unsigned int> rp_reco_ids = {
            20, 21, 120, 121
    };
    std::map<int, std::vector<RPTimingDetectorsNtuplizerHit> > timing_detectors_hits;
    std::map<int, std::vector<RPTimingDetectorsNtuplizerHit> > timing_detectors_reco_hits;
};

#endif
