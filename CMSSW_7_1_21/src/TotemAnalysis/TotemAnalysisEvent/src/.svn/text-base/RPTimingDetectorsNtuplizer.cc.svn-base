#include <iostream>
#include <DataFormats/Common/interface/Handle.h>
#include "TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizer.h"
#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "DataFormats/TotemRPDataTypes/src/classes.h"


RPTimingDetectorsNtuplizer::RPTimingDetectorsNtuplizer(const edm::ParameterSet &set): Ntuplizer(set) {
}

void RPTimingDetectorsNtuplizer::CreateBranches(const edm::EventSetup &setup, TTree *tree) {
    char name[30];
    for (auto &det_id: rp_ids) {
        timing_detectors_hits[det_id] = std::vector<RPTimingDetectorsNtuplizerHit>();
        sprintf(name, "rp_timing_detector_%04d_hits.", det_id);
        tree->Branch(name, &timing_detectors_hits[det_id]);
    }
    for (auto &det_id: rp_reco_ids) {
        timing_detectors_reco_hits[det_id] = std::vector<RPTimingDetectorsNtuplizerHit>();
        sprintf(name, "rp_timing_detector_%03d_reco_hits.", det_id);
        tree->Branch(name, &timing_detectors_reco_hits[det_id]);
    }
}

void RPTimingDetectorsNtuplizer::FillEvent(const edm::Event &event, const edm::EventSetup &setup) {
    edm::Handle<std::vector<RPTimingDetectorHit> > td_hits;
    bool present = event.getByLabel("RPTimingDetectorsDigiProducer", td_hits);
    if (present) {
        for (auto &det_id: rp_ids) {
            timing_detectors_hits[det_id].clear();
        }
        for (auto &td_hit: *td_hits.product()) {
            timing_detectors_hits[TotRPDetId::RawToDecId(td_hit.GetDetId())]
                    .push_back(RPTimingDetectorsNtuplizerHit(
                            td_hit.GetElectrodeId(),
                            Point(td_hit.GetPosition().x(), td_hit.GetPosition().y())
                    ));
        }
    }

    edm::Handle<std::vector<RPTimingDetectorHit> > td_reco_hits;
    present = event.getByLabel("RPTimingDetectorsRecoHitsProducer", td_reco_hits);
    if (present) {
        for (auto &det_id: rp_reco_ids) {
            timing_detectors_reco_hits[det_id].clear();
        }
        for (auto &td_hit: *td_reco_hits.product()) {
            timing_detectors_reco_hits[TotRPDetId::RawToDecId(td_hit.GetDetId())/10]
                    .push_back(RPTimingDetectorsNtuplizerHit(
                            td_hit.GetElectrodeId(),
                            Point(td_hit.GetPosition().x(), td_hit.GetPosition().y())
                    ));
        }
    }
}


