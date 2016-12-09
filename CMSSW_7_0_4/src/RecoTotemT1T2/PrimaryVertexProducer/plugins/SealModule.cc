#include "FWCore/PluginManager/interface/ModuleDef.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "RecoTotemT1T2/PrimaryVertexProducer/interface/PrimaryVertexFinder.h"
#include "RecoTotemT1T2/PrimaryVertexProducer/interface/VertexAnalyzer.h"
#include "RecoTotemT1T2/PrimaryVertexProducer/interface/VertexDumper.h"

DEFINE_FWK_MODULE(PrimaryVertexFinder);
DEFINE_FWK_MODULE(VertexAnalyzer);
DEFINE_FWK_MODULE(VertexDumper);

