#include <memory>
#include <map>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetector.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetectorFactory.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPFittedTrackCollection.h"


class RPTimingDetectorsRecoHitsProducer : public edm::EDProducer {
public:
    explicit RPTimingDetectorsRecoHitsProducer(const edm::ParameterSet&);
    ~RPTimingDetectorsRecoHitsProducer();

private:
    virtual void beginJob() override;
    virtual void produce(edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    std::map<unsigned int, RPTimingDetector*> timing_detectors;
    std::set<unsigned int> timing_detectors_ids;

    Local2DVector beam_misalignment;

};

#define TIMING_DETECTOR_X_OFFSET -2.0
//mm

RPTimingDetectorsRecoHitsProducer::RPTimingDetectorsRecoHitsProducer(const edm::ParameterSet& iConfig)
{
    produces<std::vector<RPTimingDetectorHit> > ();

    /* Creating timing detectors with roman pots ids:
     * arm | station | roman pot | plane
     * 1   | 2       | 0         | 0
     * 1   | 2       | 1         | 0
     * 0   | 2       | 0         | 0
     * 0   | 2       | 1         | 0
     */

    double upper_y_offset[2] = {
            iConfig.getUntrackedParameter<double>("detector_020_y_offset_mm", 0.0),
            iConfig.getUntrackedParameter<double>("detector_120_y_offset_mm", 0.0)
    }; // index = arm
    double lower_y_offset[2] = {
            iConfig.getUntrackedParameter<double>("detector_021_y_offset_mm", 0.0),
            iConfig.getUntrackedParameter<double>("detector_121_y_offset_mm", 0.0)
    };

    beam_misalignment = Local2DVector(
        iConfig.getUntrackedParameter<double>("beam_x_misalignment_mm", 0.0),
        iConfig.getUntrackedParameter<double>("beam_y_misalignment_mm", 0.0)
    );

    for (int i=0; i < 2; ++i) {
        unsigned int id = TotRPDetId(i, 2, 0, 0).DetectorDecId()/10;
        timing_detectors_ids.insert(id);
        timing_detectors[id] = RPTimingDetectorFactory::GetRPTimingDetector(
                Local2DVector(TIMING_DETECTOR_X_OFFSET, upper_y_offset[i]),
                RPTimingDetectorFactory::UPPER,
                TotRPDetId(i, 2, 0, 0) // arm = 0, 1 | station = 2 | roman pot = 0 | plane = 0
        );
        id = TotRPDetId(i, 2, 1, 0).DetectorDecId()/10;
        timing_detectors_ids.insert(id);
        timing_detectors[id] = RPTimingDetectorFactory::GetRPTimingDetector(
                Local2DVector(TIMING_DETECTOR_X_OFFSET, lower_y_offset[i]),
                RPTimingDetectorFactory::LOWER,
                TotRPDetId(i, 2, 1, 0) // arm = 0, 1 | station = 2 | roman pot = 1 | plane = 0
        );
    }
}


RPTimingDetectorsRecoHitsProducer::~RPTimingDetectorsRecoHitsProducer()
{

}

void RPTimingDetectorsRecoHitsProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    edm::Handle<RPFittedTrackCollection> tracks_handle;
    iEvent.getByLabel("RPSingleTrackCandCollFit", tracks_handle);
    RPFittedTrackCollection tracks = *tracks_handle.product();

    std::auto_ptr<vector<RPTimingDetectorHit> > timing_detector_hits(new vector<RPTimingDetectorHit>());

    for (auto &id: timing_detectors_ids) {
        if(tracks[id].IsValid()) {
        // TODO verbosity flag
//            std::cout << "TD Reco Hit  " << id << " (" << tracks[id].X0() << "," << tracks[id].Y0() << ") ";
            RPTimingDetectorHit *hit = timing_detectors[id]->CheckHitAndGetRPTimingDetectorHit(
                    timing_detectors[id]->getDetectorId().rawId(),
                    Local2DPoint(tracks[id].X0(), tracks[id].Y0()) + beam_misalignment
            );
            if(hit != NULL) {
                timing_detector_hits->push_back(*hit);
//                std::cout << hit->GetElectrodeId() << std::endl;
            }
//            else {
//                std::cout << "miss" << std::endl;
//            }
        }
    }
    iEvent.put(timing_detector_hits);
}

void RPTimingDetectorsRecoHitsProducer::beginJob()
{
}

void RPTimingDetectorsRecoHitsProducer::endJob() {
}

DEFINE_FWK_MODULE(RPTimingDetectorsRecoHitsProducer);
