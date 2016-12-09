import FWCore.ParameterSet.Config as cms

process = cms.Process("FlatProtonLogKsiLogTGunTest")

# reasonable verbosity
process.load("Configuration.TotemCommon.LoggerMin_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    sourceSeed = cms.untracked.uint32(98765)
)

################## STEP 1
process.source = cms.Source("EmptySource")

################## STEP 2 - process.generator
process.load("IOMC.FlatProtonLogKsiLogTGun.TotemGunConfig_cfi")

# Use random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

process.load("SimGeneral.HepPDTESSource.pdt_cfi")

process.Out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('file:FlatProtonLogKsiLogTGunTest.root')
)

process.p1 = cms.Path(process.generator)

process.outpath = cms.EndPath(process.Out)
