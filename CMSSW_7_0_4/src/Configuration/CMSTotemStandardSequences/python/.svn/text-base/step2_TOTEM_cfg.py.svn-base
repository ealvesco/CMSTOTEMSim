from Configuration.CMSTotemStandardSequences.step1_TOTEM_cfg import *

import os
BASE_DIR = os.path.dirname(os.path.realpath('__file__'))

process.__dict__['_Process__name'] = 'step2TOTEM'

# Input file
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:' + os.path.join(BASE_DIR, 'data/step1_TOTEM.root'))
)

# Raw to digi conversion
process.load('TotemCondFormats/DAQInformation/DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_220_210far.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t1_all_run2.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t2_3quarters.xml')

process.load("Configuration.TotemCommon.mixNoPU_cfi")

################## STEP 1 process.mix*process.T1Digis*process.t1cluster*process.t1rechit*process.t1roads*process.t1tracks

process.load("SimTotem.T1Digitizer.T1DigisVFAT_cfi")

process.load("RecoTotemT1T2.T1MakeCluster.T1MakeCluster_cfi")
process.load("RecoTotemT1T2.T1RecHit.T1RecHit_cfi")
process.load("RecoTotemT1T2.T1RoadProducer.T1RoadProducer_cfi")
process.load("RecoTotemT1T2.T1TrackProducer2.T1TrackProducer2_cfi")

################## STEP 2 process.mix*process.T2Digis*process.T2MCl*process.T2Hits*process.T2RoadColl*process.T2TrackColl2

process.load("SimTotem.T2Digitizer.T2Digis_TuneG_5525_5535_May2011Effi_Internal_GlobalMisalBBConf_cfi")

process.load("RecoTotemT1T2.T2MakeCluster.T2MakeCluster_cfi")
process.T2MCl.maskvect = cms.vuint32()

process.load("RecoTotemT1T2.T2RecHit.T2RecHit_cfi")
process.T2Hits.inputFileNameMisal = cms.untracked.string('SimTotem/T2Digitizer/data/run_5525-5535_IntAlignHX50000Evt_XovY0.3HIP_ANDGLOB_BBConf.dat')
process.T2Hits.useTXTfile = cms.bool(False)
process.T2Hits.InsertAlignmentbyCFG = cms.bool(False)
process.T2Hits.verbosity = cms.untracked.bool(False)
process.T2Hits.CorrectWithResolution = cms.bool(True)

process.load("RecoTotemT1T2.T2RoadPadFinder.NewLabelT2RoadPadFinder_cfi")
process.T2RoadPadFinder.T2RoadCollProdName = "NewRoadFinderRELOAD"
process.T2RoadPadFinder.useStraightPadTowers = cms.bool(True)
process.T2RoadPadFinder.ResolveOverlapDoubleCount = cms.bool(False)
process.T2RoadPadFinder.BiggestTubeAngleConsidered = cms.double(0.3)


process.load("RecoTotemT1T2.T2TrackProducer3.T2TrackColl3_cfi")
process.T2TrackColl3.RoadModuleLabel="T2RoadPadFinder"
process.T2TrackColl3.RoadInstanceLabel="NewRoadFinderRELOAD"
process.T2TrackColl3.RemoveOutliers=True
process.T2TrackColl3.GhostSuppression=True

################## STEP 3 process.mix*process.RPSiDetDigitizer*process.RPClustProd*process.RPHecoHitProd*process.RPSinglTrackCandFind*process.RPSingleTrackCandCollFit

process.load("SimGeneral.HepPDTESSource.pdt_cfi")
process.load("SimTotem.RPDigiProducer.RPSiDetConf_cfi")
process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")
process.load("RecoTotemRP.RPSingleCandidateTrackFinder.RPSingleTrackCandFindConf_cfi")
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder'
process.load("RecoTotemRP.RPMulTrackCandidateCollectionFitter.RPMulTrackNonParallelRecoFitter_cfi")

################## STEP 4 process.RPCC*process.T2CC

process.load("L1TriggerTotem.CoincidenceChip.RPCoincidenceProducer_cfi")
process.load("L1TriggerTotem.CoincidenceChip.T2CoincidenceProducer_cfi")

################## STEP 5 process.RP220Reconst

process.load("RecoTotemRP.RPInelasticReconstruction.RPRec220_19p2_cfi")
process.RP220Reconst.BeamProtTransportSetup = process.BeamProtTransportSetup

################## STEP 6 process.TotemNtuplizer

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = cms.untracked.string(os.path.join(BASE_DIR, 'data/step2_TOTEM.ntuple.root'))
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")
process.TotemNtuplizer.includeDigi = cms.bool(True)
process.TotemNtuplizer.includePatterns = cms.bool(True)

# Configure the output module (save the result in a file)
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('keep *'),
    fileName = cms.untracked.string(os.path.join(BASE_DIR, 'data/step2_TOTEM.root'))
)

process.path = cms.Path(
    process.mix

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

