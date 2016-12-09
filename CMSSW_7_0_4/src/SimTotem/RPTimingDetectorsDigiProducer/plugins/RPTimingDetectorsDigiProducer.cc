#include <memory>
#include <vector>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/TotemRPDataTypes/interface/RPTimingDetectorHit.h"
#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetector.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetectorFactory.h"
#include "Geometry/TotemRecords/interface/RealGeometryRecord.h"
#include "Geometry/TotemRPGeometryBuilder/interface/TotemRPGeometry.h"
#include "CLHEP/Vector/ThreeVector.h"
#include "CLHEP/Vector/Rotation.h"

#define PROTON_ID 2212

using namespace std;

class RPTimingDetectorsDigiProducer : public edm::EDProducer {
public:
    explicit RPTimingDetectorsDigiProducer(const edm::ParameterSet&);
    ~RPTimingDetectorsDigiProducer();
private:
    virtual void beginJob() override;
    virtual void produce(edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    std::map<unsigned int, RPTimingDetector*> timing_detectors;
    std::set<unsigned int> timing_detectors_ids;
    std::map< unsigned int, CLHEP::Hep3Vector> rp_translations;
    std::map< unsigned int, CLHEP::HepRotation> rp_rotations;

    Local2DVector beam_misalignment;
};

#define TIMING_DETECTOR_X_OFFSET -2.0
//mm

RPTimingDetectorsDigiProducer::RPTimingDetectorsDigiProducer(const edm::ParameterSet& iConfig)
{
    produces<std::vector<RPTimingDetectorHit> > ();

    /* Creating timing detectors with roman pots ids:
     * arm | station | roman pot | plane
     * 1   | 2       | 0         | 0-3
     * 1   | 2       | 1         | 0-3
     * 0   | 2       | 0         | 0-3
     * 0   | 2       | 1         | 0-3
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
        for (int j = 0; j < 4; ++j) {
            unsigned int id = TotRPDetId(i, 2, 0, j).rawId();
            timing_detectors_ids.insert(id);
            timing_detectors[id] = (RPTimingDetectorFactory::GetRPTimingDetector(
                    Local2DVector(TIMING_DETECTOR_X_OFFSET, upper_y_offset[i]),
                    RPTimingDetectorFactory::UPPER,
                    TotRPDetId(i, 2, 0, j) // arm = 0, 1 | station = 2 | roman pot = 0 | plane = 0-3
            ));
            id = TotRPDetId(i, 2, 1, j).rawId();
            timing_detectors_ids.insert(id);
            timing_detectors[id] = (RPTimingDetectorFactory::GetRPTimingDetector(
                    Local2DVector(TIMING_DETECTOR_X_OFFSET, lower_y_offset[i]),
                    RPTimingDetectorFactory::LOWER,
                    TotRPDetId(i, 2, 1, j) // arm = 0, 1 | station = 2 | roman pot = 1 | plane = 0-3
            ));
        }
    }
}


RPTimingDetectorsDigiProducer::~RPTimingDetectorsDigiProducer()
{
}

void
RPTimingDetectorsDigiProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;
    // get translation and rotation

    edm::ESHandle<TotemRPGeometry> totem_rp_geometry;
    iSetup.get<RealGeometryRecord>().get(totem_rp_geometry);

    for (auto &detector: timing_detectors) {
        // create id of first detector in RP station
        unsigned int rp_id_raw = detector.first;
        TotRPDetId rp_id_obj(rp_id_raw);

        // add translation of detector to list
        if (rp_translations.find(rp_id_raw) == rp_translations.end()){
            CLHEP::Hep3Vector trans = totem_rp_geometry->GetDetTranslation(rp_id_obj);
            rp_translations[rp_id_raw] = trans;
        }

        // add rotation of detector to list
        if (rp_rotations.find(rp_id_raw) == rp_rotations.end()){
            double xx, xy, xz, yx, yy, yz, zx, zy, zz;
            (totem_rp_geometry->GetDetector(rp_id_obj)->rotation()).GetComponents(xx, xy, xz, yx, yy, yz, zx, zy, zz);
            CLHEP::HepRep3x3 rot_mat( xx, xy, xz, yx, yy, yz, zx, zy, zz);
            CLHEP::HepRotation rot(rot_mat);
            rp_rotations[rp_id_raw] = rot;
        }
    }

    //extract PSimHits
    edm::Handle<vector<PSimHit> > cf;
    iEvent.getByLabel("g4SimHits", "TotemHitsRP", cf);

    // Timing Detectors hits
    std::auto_ptr<vector<RPTimingDetectorHit> > timing_detector_hits(
      new vector<RPTimingDetectorHit>());

    RPTimingDetectorHit* detector_hit;
    for (auto const &particle : *cf.product()) {
        if (particle.particleType() != PROTON_ID) continue;

        unsigned int particle_det_id = particle.detUnitId();
        if (timing_detectors_ids.find(particle_det_id) != timing_detectors_ids.end()){

            // point translation
            CLHEP::Hep3Vector point;
            point.setX(particle.entryPoint().x());
            point.setY(particle.entryPoint().y());
            CLHEP::Hep3Vector aligned_point = rp_rotations[particle_det_id] * point +
                                              rp_translations[particle_det_id];

            detector_hit = timing_detectors[particle_det_id]->CheckHitAndGetRPTimingDetectorHit(
                    particle_det_id,
                    Local2DPoint(aligned_point.x(), aligned_point.y()) + beam_misalignment
            );

            if (detector_hit != NULL){
                // TODO verbosity flag
//                cout << "TD Geant Hit " << TotRPDetId::RawToDecId(detector_hit->GetDetId())
//                << " (" << aligned_point.x() << "," << aligned_point.y() << ")"
//                << detector_hit->GetElectrodeId() << endl;

                timing_detector_hits->push_back(*detector_hit);
            }
        }
    }

    iEvent.put(timing_detector_hits);
}

void
RPTimingDetectorsDigiProducer::beginJob()
{
}

void
RPTimingDetectorsDigiProducer::endJob() {
}

DEFINE_FWK_MODULE(RPTimingDetectorsDigiProducer);
