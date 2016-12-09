#ifndef TotemAnalysis_TotemNtuplizer_RPTimingDetectorsNtuplizerHit_h
#define TotemAnalysis_TotemNtuplizer_RPTimingDetectorsNtuplizerHit_h

#include "TObject.h"
#include "vector"

struct Point {
    Point() {};
    Point(double x, double y): x(x), y(y) {};
    virtual ~Point() { }

    double x;
    double y;
    ClassDef(Point, 1)
};

struct  RPTimingDetectorsNtuplizerHit{
public:
    RPTimingDetectorsNtuplizerHit() {}
    RPTimingDetectorsNtuplizerHit(unsigned short electrode_id, Point position) : electrode_id(
            electrode_id), position(position) { }

    virtual ~RPTimingDetectorsNtuplizerHit() { }

    unsigned short electrode_id;
    Point position;
    ClassDef(RPTimingDetectorsNtuplizerHit,1)
};

// Hack needed to use vector of RPTimingDetectorsNtuplizerHit and Point in root macro.
// If you have better idea than this solution please change it.
#ifdef __CINT__
#pragma link C++ class std::vector<RPTimingDetectorsNtuplizerHit>+;
#pragma link C++ class std::vector<Point>+;
#endif

#endif
