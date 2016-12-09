import FWCore.ParameterSet.Config as cms

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
