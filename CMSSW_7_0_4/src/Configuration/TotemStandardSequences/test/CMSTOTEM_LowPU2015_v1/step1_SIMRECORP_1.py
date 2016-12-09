import FWCore.ParameterSet.Config as cms                                                                                                                    
import random 
process = cms.Process("RP")

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
  input = cms.untracked.int32(1000)
)

# Specify the output filename
# Configure the output module 
process.o1 = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('drop *',
        'keep *_*_*_GEN',
        'keep *_*_*_SIM',
        'keep *_generator_*_*',
        'keep *_TriggerResults_*_*',
        "keep *_RPSingleTrackCandCollFit_*_*",
        "keep *_totemRPAnalysis_*_*",
        "keep *_NonParallelTrackFinder_*_*",                           
        "keep *_RP220Reconst_*_*",
        "keep *_NonParallelTrackFinder_*_*",
        "keep *_RPSiDetDigitizer_*_*",
        "keep *_RPClustProd_*_*",
        "keep *_RPHecoHitProd_*_*",
        'keep *_SmearingGenerator_*_*',
        'keep *_*_TotemHitsRP_*'
    ),
    fileName = cms.untracked.string('file:PYTHIA8_MB_13TeV_RPRECO_1.root')
)
#process.outpath = cms.EndPath(process.o1)
#process.options = cms.untracked.PSet( SkipEvent = cms.untracked.vstring('ProductNotFound'))

# Configure if you want to detail or simple log information.
# LoggerMax -- detail log info output including: errors.log, warnings.log, infos.log, debugs.log
# LoggerMin -- simple log info output to the standard output (e.g. screen)
process.load("Configuration.TotemCommon.LoggerMin_cfi")

process.source = cms.Source("EmptySource")

# Use random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")
process.RandomNumberGeneratorService.generator.initialSeed= cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.g4SimHits.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.RPSiDetDigitizer.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.SmearingGenerator.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.T2Digis.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.T2MCl.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.mix.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.SimG4Object.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.RPFastStationSimulation.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.RPFastFullSimulation.initialSeed = cms.untracked.uint32(random.randint(0,900000000))
process.RandomNumberGeneratorService.LHCTransport.initialSeed = cms.untracked.uint32(random.randint(0,900000000))

# particle generator paramteres
#process.load("IOMC.FlatProtonLogKsiLogTGun.Beta90Energy6500GeV_cfi")
process.load("Pythia8MBR_generated_cfi")
# declare optics parameters
# Optics
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_50urad_cfi")

# Smearing                                                                         
process.load("IOMC.SmearingGenerator.SmearingGenerator_cfi")   

#geometry -beta* specific
# Geometry
#process.load("Configuration.TotemCommon.geometryGlobal_cfi")
process.load("Configuration.TotemCommon.geometryRP_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/2015_10_17_fill4509/RP_Dist_Beam_Cent.xml")


#alignment
process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
#process.TotemRPIncludeAlignments.RealFiles = cms.vstring("TotemAlignment/RPData/LHC/2015_10_17_fill4509/version2/sr+el/45.xml", "TotemAlignment/RPData/LHC/2015_10_17_fill4509/version2/sr+el/56.xml")

# Magnetic Field, by default we have 3.8T                                          
process.load("Configuration.StandardSequences.MagneticField_cff")

# G4 simulation & proton transport
process.load("Configuration.TotemCommon.g4SimHits_cfi")
process.g4SimHits.Physics.BeamProtTransportSetup = process.BeamProtTransportSetup
process.g4SimHits.Generator.HepMCProductLabel = 'generator'    # The input source for G4 module is connected to "process.source".
process.g4SimHits.G4TrackingManagerVerbosity = cms.untracked.int32(3)

# Use particle table
process.load("SimGeneral.HepPDTESSource.pdt_cfi")

process.g4SimHits.PPSSD = cms.PSet(Verbosity = cms.untracked.int32(1))
process.load("Configuration.TotemCommon.mixNoPU_cfi") 

#process.mix*process.RPSiDetDigitizer*process.RPClustProd*process.RPHecoHitProd*process.RPSinglTrackCandFind*process.RPSingleTrackCandCollFit

process.load("SimTotem.RPDigiProducer.RPSiDetConf_cfi")
process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")
#process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")
#process.load("RecoTotemRP.RPSingleCandidateTrackFinder.RPSingleTrackCandFindConf_cfi")
#process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
#process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
#process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder'
#process.load("RecoTotemRP.RPMulTrackCandidateCollectionFitter.RPMulTrackNonParallelRecoFitter_cfi")


# raw to digi conversion
process.load('TotemCondFormats.DAQInformation.DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames = cms.untracked.vstring("TotemCondFormats/DAQInformation/data/rp_220_210far.xml")

# reco hit production
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")

# non-parallel pattern recognition
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.NonParallelTrackFinder.verbosity = 0
process.NonParallelTrackFinder.maxHitsPerPlaneToSearch = 5
process.NonParallelTrackFinder.minPlanesPerProjectionToSearch = 2
process.NonParallelTrackFinder.minPlanesPerProjectionToFit = 3
process.NonParallelTrackFinder.threshold = 2.99
#process.NonParallelTrackFinder.exceptionalSettings = cms.VPSet(
#    cms.PSet(
#        rpId = cms.uint32(20),
#        minPlanesPerProjectionToFit_U = cms.uint32(2),
#        minPlanesPerProjectionToFit_V = cms.uint32(3),
#        threshold_U = cms.double(1.99),
#        threshold_V = cms.double(2.99)
#    )
#)

# track fitting
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.Verbosity = 0
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder' # takes up the non-parallel pattern recognition
#RP inel reco
process.load("RecoTotemRP.RPInelasticReconstruction.Rec_6500GeV_beta_90_50urad_cfi")              
process.RP220Reconst.BeamProtTransportSetup = process.BeamProtTransportSetup

################## STEP 6 process.mix*process.RPSiDetDigitizer*process.RPClustProd*process.RPHecoHitProd*process.RPSinglTrackCandFind*process.RPSingleTrackCandCollFit

process.load("Configuration.TotemStandardSequences.RP_Digi_and_TrackReconstruction_cfi")

#TotemRPAnalysis
from TotemAnalysis.TotemRPAnalysis.TotemRPAnalysis_cfi import TotemRPAnalysis
process.totemRPAnalysis = cms.EDProducer("TotemRPEDMProducer",
        TotemRPAnalysis = TotemRPAnalysis
       ) 
process.totemRPTreeAnalysis = cms.EDAnalyzer("TotemRPTreeProducer",

        TotemRPAnalysis = TotemRPAnalysis)
process.TFileService = cms.Service("TFileService",
        fileName = cms.string("TotemRPTreeEDMAnalysis_TFileService_1.root" )
        )
#ntuplizer
process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = "output.ntuple_1.root"
process.TotemNtuplizer.RawEventLabel = 'source'
process.TotemNtuplizer.verbosity = 0
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")
process.TotemNtuplizer.includeDigi = cms.bool(True)
process.TotemNtuplizer.includePatterns = cms.bool(True)
process.TotemNtuplizer.T2IncludePadAndStripDigi = cms.bool(True)

process.p1 = cms.Path(
    process.generator*
    process.SmearingGenerator*
    process.g4SimHits*
    process.mix* 
    process.RPSiDetDigitizer*
#    process.Raw2DigiProducer*
#    process.TriggerBits*
    process.RPClustProd * 
    process.RPHecoHitProd *
    process.NonParallelTrackFinder *
    process.RPSingleTrackCandCollFit *
    process.RP220Reconst *
    process.TotemNtuplizer *
    process.totemRPAnalysis *
    process.totemRPTreeAnalysis

)
process.outpath = cms.EndPath(process.o1)
 
