import FWCore.ParameterSet.Config as cms

process = cms.Process("nTuplize")


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(),
    noEventSort = cms.untracked.bool(True),
    skipBadFiles = cms.untracked.bool(True),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")


process.load("Configuration/TotemOpticsConfiguration/OpticsConfig_6500GeV_90_cfi")

process.load("TotemAnalysis/TotemNtuplizer/TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = 'ntuple.root'
process.TotemNtuplizer.ProductLabelSimu = 'rpCCOutput'
process.TotemNtuplizer.ModulLabelSimu = 'Raw2DigiProducer'
#process.TotemNtuplizer.includePatterns = cms.bool(True)

process.p = cms.Path(
   process.TotemNtuplizer
)
