#ifndef SimTotem_RPDigiProducer_RPTimingDetectorElectrode_H
#define SimTotem_RPDigiProducer_RPTimingDetectorElectrode_H

#include "DataFormats/GeometryVector/interface/LocalPoint.h"

#include <iostream>
using namespace std;

class RPTimingDetectorElectrode {
public:

    RPTimingDetectorElectrode(unsigned short electrode_id, double left_boundary, double right_boundary,
                              double lower_boundary, double upper_boundary) :
            electrode_id(electrode_id),
            left_boundary(left_boundary),
            right_boundary(right_boundary),
            lower_boundary(lower_boundary),
            upper_boundary(upper_boundary) { }

    unsigned short GetElecetrodeId() {
        return electrode_id;
    }

    // Checks if particle on given position hits electrode.
    bool CheckParticleHitsElectrode(Local2DPoint particle_position) {
        return (
                left_boundary <= particle_position.x() &&
                particle_position.x() <= right_boundary &&
                lower_boundary <= particle_position.y() &&
                particle_position.y() <= upper_boundary
        );
    }

    double GetLeftBoundary() { return left_boundary; }
    double GetRightBoundary() { return right_boundary; }
    double GetLowerBoundary() { return lower_boundary; }
    double GetUpperBoundary() { return upper_boundary; }

private:
    unsigned short electrode_id;
    double left_boundary;
    double right_boundary;
    double lower_boundary;
    double upper_boundary;
};

#endif

