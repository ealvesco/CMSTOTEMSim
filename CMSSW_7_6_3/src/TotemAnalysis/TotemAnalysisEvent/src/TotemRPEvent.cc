
#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"

const char* TotemRPEvent::name = "TotemRPEvent";

void TotemRPEvent::reset() {

   track_info_.clear();
   digi_info_.clear();
   par_patterns_info_.clear();
   nonpar_patterns_info_.clear();

   multi_track_info_.clear();
   rec_pr_info_.clear();
   sim_pr_info_.clear();
   rec_pr_pair_info_ = RPRootDumpReconstructedProtonPair();
}
