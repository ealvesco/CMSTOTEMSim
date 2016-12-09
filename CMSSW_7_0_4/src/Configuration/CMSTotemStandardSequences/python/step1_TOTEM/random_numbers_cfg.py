from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

attrs = [
    'LHCTransport',
    'MuonSimHits',
    'VtxSmeared',
    'ecalPreshowerRecHit',
    'ecalRecHit',
    'externalLHEProducer',
    'famosPileUp',
    'famosSimHits',
    'hbhereco',
    'hfreco',
    'hiSignal',
    'hiSignalG4SimHits',
    'hiSignalLHCTransport',
    'horeco',
    'l1ParamMuons',
    'mixData',
    'mixGenPU',
    'mixRecoTracks',
    'mixSimCaloHits',
    'paramMuons',
    'saveFileName',
    'siTrackerGaussianSmearingRecHits',
    'simBeamSpotFilter',
    'simMuonCSCDigis',
    'simMuonDTDigis',
    'simMuonRPCDigis',
    'simSiStripDigiSimLink'
    ]

for attr in attrs:
    process.RandomNumberGeneratorService.__delattr__(attr)    

process.RandomNumberGeneratorService.generator.initialSeed = cms.untracked.uint32(98766)
process.RandomNumberGeneratorService.generator.__delattr__('engineName')
process.RandomNumberGeneratorService.g4SimHits.initialSeed = cms.untracked.uint32(9876)
process.RandomNumberGeneratorService.g4SimHits.__delattr__('engineName')
process.RandomNumberGeneratorService.mix.initialSeed = cms.untracked.uint32(24141)
process.RandomNumberGeneratorService.mix.__delattr__('engineName')

process.RandomNumberGeneratorService.RPSiDetDigitizer = cms.PSet(
    initialSeed = cms.untracked.uint32(137137)
)
process.RandomNumberGeneratorService.T2MCl = cms.PSet(
    initialSeed = cms.untracked.uint32(24141)
)
process.RandomNumberGeneratorService.SmearingGenerator = cms.PSet(
    initialSeed = cms.untracked.uint32(3849)
)
process.RandomNumberGeneratorService.RPFastFullSimulation = cms.PSet(
    initialSeed = cms.untracked.uint32(13)
)
process.RandomNumberGeneratorService.SimG4Object = cms.PSet(
    initialSeed = cms.untracked.uint32(9876)
)
process.RandomNumberGeneratorService.RPFastStationSimulation = cms.PSet(
    initialSeed = cms.untracked.uint32(12)
)
process.RandomNumberGeneratorService.LHCTransport = cms.PSet(
    initialSeed = cms.untracked.uint32(24143),
    engineName = cms.untracked.string('TRandom3')
)
process.RandomNumberGeneratorService.T2Digis = cms.PSet(
    initialSeed = cms.untracked.uint32(98765)
)
process.RandomNumberGeneratorService.sourceSeed = cms.PSet(
    initialSeed = cms.untracked.uint32(98765)
)
