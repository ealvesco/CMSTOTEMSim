#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetectorFactory.h"
#include "SimTotem/RPTimingDetectorsDigiProducer/interface/RPTimingDetectorElectrode.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"

#include <vector>
#include <iostream>

using namespace std;
/*
 * Upper detector:
 *
 * Segments:
 * 3 4
 * 2 5
 * 1 6
 * 0 7
 *
 * Segment 0:
 *  Electrode 4
 *  Electrode 3
 *  Electrode 2
 *  Electrode 1
 *
 * Segment 1:
 *  Electrode 6
 *  Electrode 5
 *
 * Segment n:
 *  Electrode n + 5
 *
 * To properly create timing detector you need to specify detector alignment to beam.
 * (position of lower left corner of detector). If you want 'lower' detector (flipped
 * upside down) you need to pass Lower Orientation as argument. This will result with
 * flipping detector by x axis (y*(-1)). Alignment to beam is applied before flipping detector.
 *
 */
inline void RPTimingDetectorFactory::pushBackElectrodeWithOrientation(
        vector<RPTimingDetectorElectrode> &electrodes, int id, Local2DPoint lower_left,
        Local2DPoint upper_right, Orientation orientation){


    double left_boundary = lower_left.x();
    double right_boundary = upper_right.x();
    double lower_boundary = min(lower_left.y()*((double)orientation), upper_right.y()*((double)orientation));
    double upper_boundary = max(lower_left.y()*((double)orientation), upper_right.y()*((double)orientation));

    electrodes.push_back(
            RPTimingDetectorElectrode(
                    id,
                    left_boundary,
                    right_boundary,
                    lower_boundary,
                    upper_boundary
            )
    );

}

RPTimingDetector * RPTimingDetectorFactory::GetRPTimingDetector(
        Local2DVector detector_alignment_to_beam,
        Orientation orientation, TotRPDetId det_id) {
    vector<RPTimingDetectorElectrode> electrodes;

    Local2DVector segment_alignment_to_detector(detector_alignment_to_beam);
    Local2DPoint full_size_electrode_lower_left_corner(RPTDSegmentElectrodeGap, RPTDSegmentElectrodeGap);
    Local2DPoint full_size_electrode_upper_right_corner(
            RPTDSegmentSize - RPTDSegmentElectrodeGap,
            RPTDSegmentSize - RPTDSegmentElectrodeGap
    );

    // Segment 0

    // Electrode 1
    Local2DPoint electrode_1_upper_right_corner(
            full_size_electrode_lower_left_corner + Local2DVector(RPTDElectrodeSize, RPTDElectrode1GHeight)
    );
    pushBackElectrodeWithOrientation(electrodes, 1,
        full_size_electrode_lower_left_corner + segment_alignment_to_detector,
        electrode_1_upper_right_corner + segment_alignment_to_detector,
        orientation
    );
    // Electrode 2
    Local2DPoint electrode_2_lower_left_corner(
            full_size_electrode_lower_left_corner + Local2DVector(
                    0,
                    RPTDElectrode1GHeight + RPTDElectrodesMiddleGap
            )
    );
    Local2DPoint electrode_2_upper_right_corner(
            electrode_1_upper_right_corner + Local2DVector(
                    0,
                    RPTDElectrode2GHeight + RPTDElectrodesMiddleGap
            )
    );
    pushBackElectrodeWithOrientation(electrodes, 2,
                                     electrode_2_lower_left_corner + segment_alignment_to_detector,
                                     electrode_2_upper_right_corner + segment_alignment_to_detector,
                                     orientation
    );
    // Electrode 3
    Local2DPoint electrode_3_lower_left_corner(
            electrode_2_lower_left_corner + Local2DVector(
                    0,
                    RPTDElectrode2GHeight + RPTDElectrodesMiddleGap
            )
    );
    Local2DPoint electrode_3_upper_right_corner(
            electrode_2_upper_right_corner + Local2DVector(
                    0,
                    RPTDElectrode3GHeight + RPTDElectrodesMiddleGap
            )
    );

    pushBackElectrodeWithOrientation(electrodes, 3,
                                     electrode_3_lower_left_corner + segment_alignment_to_detector,
                                     electrode_3_upper_right_corner + segment_alignment_to_detector,
                                     orientation
    );

    // Electrode 4
    Local2DPoint electrode_4_lower_left_corner(
            electrode_3_lower_left_corner + Local2DVector(
                    0,
                    RPTDElectrode3GHeight + RPTDElectrodesMiddleGap
            )
    );

    pushBackElectrodeWithOrientation(electrodes, 4,
                                     electrode_4_lower_left_corner + segment_alignment_to_detector,
                                     full_size_electrode_upper_right_corner + segment_alignment_to_detector,
                                     orientation
    );

    // Segment 1
    segment_alignment_to_detector += Local2DVector(0, RPTDSegmentSize);

    // Electrode 5

    Local2DPoint electrode_5_upper_right_corner(
            full_size_electrode_lower_left_corner + Local2DVector(
                    RPTDElectrodeSize,
                    RPTDElectrode5GHeight
            )
    );

    pushBackElectrodeWithOrientation(electrodes, 5,
                                     full_size_electrode_lower_left_corner + segment_alignment_to_detector,
                                     electrode_5_upper_right_corner + segment_alignment_to_detector,
                                     orientation
    );

    // Electrode 6
    Local2DPoint electrode_6_lower_left_corner(
            full_size_electrode_lower_left_corner + Local2DVector(
                    0,
                    RPTDElectrode5GHeight + RPTDElectrodesMiddleGap
            )
    );

    pushBackElectrodeWithOrientation(electrodes, 6,
                                     electrode_6_lower_left_corner + segment_alignment_to_detector,
                                     full_size_electrode_upper_right_corner + segment_alignment_to_detector,
                                     orientation
    );

    // Segments 2-3
    // Electrodes 7-8
    for (int i = 7; i <=8 ; ++i) {
        segment_alignment_to_detector += Local2DVector(0, RPTDSegmentSize);
        pushBackElectrodeWithOrientation(electrodes, i,
                                         full_size_electrode_lower_left_corner + segment_alignment_to_detector,
                                         full_size_electrode_upper_right_corner + segment_alignment_to_detector,
                                         orientation
        );
    }

    // Segments 4-7
    // Electrodes 9-12
    // Electrodes are constructed form the lower-right electrode up to upper-right one
    segment_alignment_to_detector = Local2DVector(RPTDSegmentSize, 0);
    segment_alignment_to_detector += detector_alignment_to_beam;
    for (int i = 12; i >= 9; --i) {
        pushBackElectrodeWithOrientation(electrodes, i,
                                         full_size_electrode_lower_left_corner + segment_alignment_to_detector,
                                         full_size_electrode_upper_right_corner + segment_alignment_to_detector,
                                         orientation
        );
        segment_alignment_to_detector += Local2DVector(0, RPTDSegmentSize);
    }

    return new RPTimingDetector(electrodes, det_id);
}
