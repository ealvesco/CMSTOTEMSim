
#include "FWCore/Framework/interface/MakerMacros.h"

#include "TotemAnalysis/TotemRPAnalysis/interface/RPNtuplizer.h"
#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"

#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ForwardEDMProducer.h"

typedef forwardEDMAnalysis::ForwardEDMProducer<totemRPAnalysis::RPNtuplizer> TotemRPEDMProducer;
DEFINE_FWK_MODULE(TotemRPEDMProducer);
