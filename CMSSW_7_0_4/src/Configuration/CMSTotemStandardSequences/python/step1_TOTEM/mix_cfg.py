from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

process.mix.digitizers = cms.PSet()
process.mix.mixObjects.mixCH = cms.PSet(
    crossingFrames = cms.untracked.vstring(),
    input = cms.VInputTag(
        cms.InputTag("g4SimHits","CaloHitsTk"),
        cms.InputTag("g4SimHits","CastorBU"),
        cms.InputTag("g4SimHits","CastorFI"),
        cms.InputTag("g4SimHits","CastorPL"),
        cms.InputTag("g4SimHits","CastorTU"),
        cms.InputTag("g4SimHits","EcalHitsEB"),
        cms.InputTag("g4SimHits","EcalHitsEE"),
        cms.InputTag("g4SimHits","EcalHitsES"),
        cms.InputTag("g4SimHits","EcalTBH4BeamHits"),
        cms.InputTag("g4SimHits","HcalHits"),
        cms.InputTag("g4SimHits","HcalTB06BeamHits"),
        cms.InputTag("g4SimHits","ZDCHITS")
    ),
    type = cms.string('PCaloHit'),
    subdets = cms.vstring(
        'CaloHitsTk',
        'CastorBU',
        'CastorFI',
        'CastorPL',
        'CastorTU',
        'EcalHitsEB',
        'EcalHitsEE',
        'EcalHitsES',
        'EcalTBH4BeamHits',
        'HcalHits',
        'HcalTB06BeamHits',
        'ZDCHITS'
    )
)
process.mix.mixObjects.mixSH.crossingFrames.append('TotemHitsT1') 
process.mix.mixObjects.mixSH.crossingFrames.append('TotemHitsT2Gem') 
process.mix.mixObjects.mixSH.crossingFrames.append('TotemHitsRP') 

