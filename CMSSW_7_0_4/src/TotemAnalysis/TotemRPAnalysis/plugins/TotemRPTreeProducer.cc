
#include "FWCore/Framework/interface/MakerMacros.h"

#include "TotemAnalysis/TotemRPAnalysis/interface/RPNtuplizer.h"
#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"

#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ForwardTTreeProducer.h"

typedef forwardTTreeAnalysis::ForwardTTreeProducer<totemRPAnalysis::RPNtuplizer> TotemRPTreeProducer;
DEFINE_FWK_MODULE(TotemRPTreeProducer);
