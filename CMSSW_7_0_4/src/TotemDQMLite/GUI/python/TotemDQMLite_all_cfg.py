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

TotemDQMModuleT1 = cms.PSet(
	tagDigiColl = cms.InputTag("Raw2DigiProducer", "t1DataOutput"),
	tagDigiCollStrip = cms.InputTag("Raw2DigiProducer", "t1DataOutput"),
	tagRecoColl = cms.InputTag("t1rechit")
)

TotemDQMModuleT2 = cms.PSet(
    tagRawEvent = cms.InputTag("source"),
	tagDigiVfatColl = cms.InputTag("Raw2DigiProducer", "T2Digivfat"),
	tagPadDigiColl = cms.InputTag("Raw2DigiProducer", "T2PadDigi"),
	tagStripDigiColl = cms.InputTag("Raw2DigiProducer", "T2StripDigi"),
	tagStripClusterColl = cms.InputTag("T2MCl", "T2StripClusters"),
	tagPadClusterColl = cms.InputTag("T2MCl", "T2PadClusters"),
	tagHitColl = cms.InputTag("T2Hits", "T2Hits"),
	tagRoadColl = cms.InputTag("T2RoadPadFinder", "T2RoadColl"),
	tagT1T2TrackColl = cms.InputTag("T2TrackColl3", "T2TrackColl"),
	correlationPlotsFilter = cms.untracked.string("ForEachHalf=;0=0,2;1=2,3;2=5,6;3=7,8")
)
