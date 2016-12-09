import FWCore.ParameterSet.Config as cms

process = cms.Process("simRPT1T2")

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
  input = cms.untracked.int32(1000)
)

# Configure if you want to detail or simple log information.
# LoggerMax -- detail log info output including: errors.log, warnings.log, infos.log, debugs.log
# LoggerMin -- simple log info output to the standard output (e.g. screen)
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# Raw to digi conversion
process.load('TotemCondFormats/DAQInformation/DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_220_210far.xml') # Scenario #1, #2
# process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_210.xml')      # Scenario #3
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t1_all_run2.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t2_3quarters.xml')

################## STEP 0 - empty source

process.source = cms.Source("EmptySource")

################## STEP 1 - process.generator

# Random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

# Pythia generator
process.generator = cms.EDFilter("Pythia8GeneratorFilter",
     maxEventsToPrint = cms.untracked.int32(1),
     pythiaPylistVerbosity = cms.untracked.int32(1),
     filterEfficiency = cms.untracked.double(1.0),
     pythiaHepMCVerbosity = cms.untracked.bool(False),
     comEnergy = cms.double(13000),
     PythiaParameters = cms.PSet(
        processParameters = cms.vstring(
            'Main:timesAllowErrors    = 10000',
            'ParticleDecays:limitTau0 = on',
            'ParticleDecays:tauMax = 10',
            'SoftQCD:minBias = off',
            'SoftQCD:singleDiffractive = on',
            'SoftQCD:doubleDiffractive = off',
            'Tune:pp 2',
            'Tune:ee 3'),
        parameterSets = cms.vstring('processParameters')
    )
)

################## STEP 2 process.SmearingGenerator

# Optics
# process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_0p8_145urad_cfi") # Scenario #1
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_19p2_cfi")          # Scenario #2
# process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_cfi")          # Scenario #3

# Smearing
process.load("IOMC.SmearingGenerator.SmearingGenerator_cfi")

################## STEP 3 process.g4SimHits

# Geometry
process.load("Configuration.TotemCommon.geometryGlobal_cfi")
# process.XMLIdealGeometryESSource.geomXMLFiles.append('Geometry/TotemRPData/data/RP_Beta_0p8/RP_Dist_Beam_Cent.xml') # Scenario #1
process.XMLIdealGeometryESSource.geomXMLFiles.append('Geometry/TotemRPData/data/RP_Beta_19/RP_Dist_Beam_Cent.xml')    # Scenario #2
# process.XMLIdealGeometryESSource.geomXMLFiles.append('Geometry/TotemRPData/data/RP_Beta_90/RP_Dist_Beam_Cent.xml')  # Scenario #3

# Magnetic Field, by default we have 3.8T
process.load("Configuration.StandardSequences.MagneticField_cff")

# G4 simulation & proton transport
process.load("Configuration.TotemCommon.g4SimHits_cfi")
process.g4SimHits.Generator.HepMCProductLabel = 'generator'
process.g4SimHits.Physics.BeamProtTransportSetup = process.BeamProtTransportSetup

process.load("Configuration.TotemCommon.mixNoPU_cfi")

################## STEP 4 process.mix*process.T1Digis*process.t1cluster*process.t1rechit*process.t1roads*process.t1tracks

process.load("SimTotem.T1Digitizer.T1DigisVFAT_cfi")

process.load("RecoTotemT1T2.T1MakeCluster.T1MakeCluster_cfi")
process.load("RecoTotemT1T2.T1RecHit.T1RecHit_cfi")
process.load("RecoTotemT1T2.T1RoadProducer.T1RoadProducer_cfi")
process.load("RecoTotemT1T2.T1TrackProducer2.T1TrackProducer2_cfi")

################## STEP 5 process.mix*process.T2Digis*process.T2MCl*process.T2Hits*process.T2RoadColl*process.T2TrackColl2

process.load("SimTotem.T2Digitizer.T2Digis_TuneG_5525_5535_May2011Effi_Internal_GlobalMisalBBConf_cfi")

process.load("RecoTotemT1T2.T2MakeCluster.T2MakeCluster_cfi")
process.T2MCl.maskvect = cms.vuint32()  #no masking by default

process.load("RecoTotemT1T2.T2RecHit.T2RecHit_cfi")
process.T2Hits.inputFileNameMisal=cms.untracked.string('SimTotem/T2Digitizer/data/run_5525-5535_IntAlignHX50000Evt_XovY0.3HIP_ANDGLOB_BBConf.dat')# put useTXTfile and InsertAlignmentbyCFG to False in order to avoid Hit alignment correction.
process.T2Hits.useTXTfile=cms.bool(False)   
process.T2Hits.InsertAlignmentbyCFG=cms.bool(False)  
process.T2Hits.verbosity=cms.untracked.bool(False)
process.T2Hits.CorrectWithResolution=cms.bool(True)

process.load("RecoTotemT1T2.T2RoadPadFinder.NewLabelT2RoadPadFinder_cfi")
process.T2RoadPadFinder.T2RoadCollProdName="NewRoadFinderRELOAD"
process.T2RoadPadFinder.useStraightPadTowers= cms.bool(True) #False: Old Strategy
process.T2RoadPadFinder.ResolveOverlapDoubleCount = cms.bool(False) # False for shadow alignment and dndeta An
process.T2RoadPadFinder.BiggestTubeAngleConsidered =cms.double(0.3)


process.load("RecoTotemT1T2.T2TrackProducer3.T2TrackColl3_cfi")
process.T2TrackColl3.RoadModuleLabel="T2RoadPadFinder"
process.T2TrackColl3.RoadInstanceLabel="NewRoadFinderRELOAD"
process.T2TrackColl3.RemoveOutliers=True
process.T2TrackColl3.GhostSuppression=True

################## STEP 6 process.mix*process.RPSiDetDigitizer*process.RPClustProd*process.RPHecoHitProd*process.RPSinglTrackCandFind*process.RPSingleTrackCandCollFit

process.load("SimGeneral.HepPDTESSource.pdt_cfi")
process.load("SimTotem.RPDigiProducer.RPSiDetConf_cfi")
process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")
process.load("RecoTotemRP.RPSingleCandidateTrackFinder.RPSingleTrackCandFindConf_cfi")
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder'
process.load("RecoTotemRP.RPMulTrackCandidateCollectionFitter.RPMulTrackNonParallelRecoFitter_cfi")

################## STEP 7 process.RPCC*process.T2CC

process.load("L1TriggerTotem.CoincidenceChip.RPCoincidenceProducer_cfi")
process.load("L1TriggerTotem.CoincidenceChip.T2CoincidenceProducer_cfi")

################## STEP 8 process.RP220Reconst

process.load("RecoTotemRP.RPInelasticReconstruction.RPRec220_19p2_cfi")
process.RP220Reconst.BeamProtTransportSetup = process.BeamProtTransportSetup

################## STEP 9 process.TotemNtuplizer

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = "simRPT1T2.ntuple.root"
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")
process.TotemNtuplizer.includeDigi = cms.bool(True)
process.TotemNtuplizer.includePatterns = cms.bool(True)

# Configure the output module (save the result in a file)
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('keep *'),
    fileName = cms.untracked.string('file:simRPT1T2.root')
)

process.path = cms.Path(
    process.generator
    * process.SmearingGenerator
    * process.g4SimHits
    * process.mix

    * process.T1Digis
    * process.t1cluster
    * process.t1rechit
    * process.t1roads
    * process.t1tracks2
    
    * process.T2Digis
    * process.T2MCl
    * process.T2Hits
    * process.T2RoadPadFinder
    * process.T2TrackColl3
    
    * process.RPSiDetDigitizer
    * process.RPClustProd
    * process.RPHecoHitProd 
    * process.RPSinglTrackCandFind
    * process.NonParallelTrackFinder
    * process.RPSingleTrackCandCollFit
    * process.RPMulTrackNonParallelCandCollFit
    
    * process.RPCC
    * process.T2CC
    * process.RP220Reconst
    
    * process.TotemNtuplizer
    )

process.outpath = cms.EndPath(process.output)
