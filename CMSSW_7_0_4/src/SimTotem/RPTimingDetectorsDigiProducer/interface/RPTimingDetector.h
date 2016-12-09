#ifndef SimTotem_RPDigiProducer_RPTimingDetector_H
#define SimTotem_RPDigiProducer_RPTimingDetector_H

#include <vector>
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/TotemRPDataTypes/interface/RPTimingDetectorHit.h"
#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetectorElectrode.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"

using namespace std;

/*
 * To properly check whether particles hits detector you need to specify detector
 * alignment to beam when creating instance by GetRPTimingDetector (RPTimingDetectorFactory method).
 */
class RPTimingDetector {
public:
    RPTimingDetector(const vector<RPTimingDetectorElectrode> &electrodes, TotRPDetId detector_id) :
            electrodes(electrodes), detector_id(detector_id) { }


    // For given particle on hit return RPTimingDetectorHit, otherwise return null
    RPTimingDetectorHit* CheckHitAndGetRPTimingDetectorHit(unsigned int particle_detector_id,
                                                           Local2DPoint particle_position_2d);

    vector<RPTimingDetectorElectrode> & GetElectrodes() { return electrodes; }
    TotRPDetId getDetectorId() { return detector_id; }

private:
    vector<RPTimingDetectorElectrode> electrodes;
    TotRPDetId detector_id;
};

#endif
