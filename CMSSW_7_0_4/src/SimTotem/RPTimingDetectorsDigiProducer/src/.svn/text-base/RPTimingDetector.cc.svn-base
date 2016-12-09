#include "DataFormats/TotemRPDataTypes/interface/RPTimingDetectorHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetector.h"

RPTimingDetectorHit *RPTimingDetector::CheckHitAndGetRPTimingDetectorHit(
        unsigned int particle_detector_id, Local2DPoint particle_position_2d) {
    if (particle_detector_id != detector_id.rawId()) {
        return NULL;
    }
    for (auto &electrode: electrodes) {
        if (electrode.CheckParticleHitsElectrode(particle_position_2d)) {
            return new RPTimingDetectorHit(detector_id.rawId(), electrode.GetElecetrodeId(), particle_position_2d);
        }
    }
    return NULL;
}
