import FWCore.ParameterSet.Config as cms

TotemDQMModuleT1 = cms.PSet(
	tagDigiColl = cms.InputTag("Raw2DigiProducer", "t1DataOutput"),
	tagDigiCollStrip = cms.InputTag("Raw2DigiProducer", "t1DataOutput"),
	tagRecoColl = cms.InputTag("t1rechit")
)
