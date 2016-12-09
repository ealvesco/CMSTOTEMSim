import FWCore.ParameterSet.Config as cms

TotemDQMModuleDAQ = cms.PSet(
    tagRawEvent = cms.InputTag("source")
)

TotemDQMModuleRP = cms.PSet(
	tagRawEvent = cms.InputTag("source"),
	tagStripDigi = cms.InputTag("Raw2DigiProducer", "rpDataOutput"),
	tagDigiCluster = cms.InputTag("RPClustProd"),
	tagRecoHit = cms.InputTag("RPHecoHitProd"),
	tagPatternColl = cms.InputTag("NonParallelTrackFinder"),
	tagTrackColl = cms.InputTag("RPSingleTrackCandCollFit"),
	tagTrackCandColl = cms.InputTag("NonParallelTrackFinder"),
	tagMultiTrackColl = cms.InputTag(""),
	correlationPlotsFilter = cms.untracked.string("default=0,1")
)
