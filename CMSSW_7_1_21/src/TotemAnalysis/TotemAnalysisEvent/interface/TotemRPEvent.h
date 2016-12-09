#ifndef TotemAnalysis_TotemAnalysisEvent_TotemRPEvent
#define TotemAnalysis_TotemAnalysisEvent_TotemRPEvent

//#include "TotemAnalysis/TotemAnalysisEvent/interface/RPTrackInfo.h"
#include "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h"

#include <vector>
#include <map>

namespace totemRPAnalysis {
   class TotemRPAnalysis;
}

struct TotemRPEvent {

    typedef totemRPAnalysis::TotemRPAnalysis analysis_type;
    static const char* name;

    TotemRPEvent() {}
    ~TotemRPEvent() {}

    void reset();

    std::map<unsigned int, RPRootDumpTrackInfo> track_info_;
    std::map<unsigned int, RPRootDumpDigiInfo> digi_info_;
    std::map<unsigned int, RPRootDumpPatternInfo > par_patterns_info_, nonpar_patterns_info_;

    std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > multi_track_info_;
    std::map<unsigned int, RPRootDumpReconstructedProton> rec_pr_info_;
    std::map<unsigned int, RPRootDumpReconstructedProton> sim_pr_info_;
    RPRootDumpReconstructedProtonPair rec_pr_pair_info_;
};

#endif
