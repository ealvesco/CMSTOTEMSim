#ifndef SimTotem_RPDigiProducer_RPTimingDetectorFactory_H
#define SimTotem_RPDigiProducer_RPTimingDetectorFactory_H

#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "DataFormats/GeometryVector/interface/LocalTag.h"
#include "DataFormats/GeometryVector/interface/Vector2DBase.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetector.h"

typedef Vector2DBase< float, LocalTag> Local2DVector;

// all values are in millimeters
#define RPTDSegmentSize 4.5
#define RPTDElectrodeSize 4.2
#define RPTDSegmentElectrodeGap 0.15
#define RPTDElectrodesMiddleGap 0.1
#define RPTDElectrode1GHeight 0.81
#define RPTDElectrode2GHeight 0.91
#define RPTDElectrode3GHeight 1.02
#define RPTDElectrode4GHeight 1.16
#define RPTDElectrode5GHeight 1.75
#define RPTDElectrode6GHeight 2.35

/*
 * This class produces RPTimingDetector instances with proper detector alignment to beam.
 */
class RPTimingDetectorFactory {
public:
    enum Orientation {
        LOWER = -1,
        UPPER = 1,
    };
    static RPTimingDetector* GetRPTimingDetector(Local2DVector detector_alignment_to_beam,
                                                 Orientation orientation, TotRPDetId det_id);

    inline static void pushBackElectrodeWithOrientation(vector<RPTimingDetectorElectrode> &electrodes,
                                                        int id, Local2DPoint lower_left,
                                                        Local2DPoint upper_right, Orientation orientation);

private:
    RPTimingDetectorFactory() { }
};

#endif
