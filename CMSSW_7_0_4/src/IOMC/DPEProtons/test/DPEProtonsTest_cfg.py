import FWCore.ParameterSet.Config as cms

process = cms.Process("DPEProtonsTest")

# reasonable verbosity
process.load("Configuration.TotemCommon.LoggerMin_cfi")

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    sourceSeed = cms.untracked.uint32(98765)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(30)
)

process.load("IOMC.DPEProtons.DPEProtonsConf_cfi")

process.load("SimGeneral.HepPDTESSource.pdt_cfi")

################## STEP 1
process.source = cms.Source("EmptySource")

################## STEP 2 - process.generator

# Use random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

process.Out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('simul.root')
)

process.p1 = cms.Path(process.generator)

process.outpath = cms.EndPath(process.Out)

process.Tracer = cms.Service("Tracer")
