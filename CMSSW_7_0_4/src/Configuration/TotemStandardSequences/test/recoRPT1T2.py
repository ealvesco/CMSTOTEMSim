import FWCore.ParameterSet.Config as cms

process = cms.Process("recoRPT1T2")

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

# Configure if you want to detail or simple log information.
# LoggerMax -- detail log info output including: errors.log, warnings.log, infos.log, debugs.log
# LoggerMin -- simple log info output to the standard output (e.g. screen)
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# Geometry
process.load("Configuration.TotemCommon.geometryGlobal_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/2015_08_25_fill4269_2/RP_Dist_Beam_Cent.xml")

process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
process.TotemRPIncludeAlignments.RealFiles = cms.vstring(
  "TotemAlignment/RPData/alignment_tb_run9509_45_no20.xml",
  "TotemAlignment/RPData/alignment_tb_run9509_56.xml"
)

# Alignments
process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")

# Optics
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_19p2_cfi")

# RawDataSource
process.load('TotemRawData.Readers.RawDataSource_cfi')
process.source.fileNames.append('/afs/cern.ch/user/k/ktrzepla/public/CMSSW_7_0_4/data/run_9510_EVB13_1.000.srs')

# Raw to digi conversion
process.load('TotemCondFormats.DAQInformation.DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_220_210far.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t1_all_run2.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t2_3quarters.xml')
process.DAQMappingSourceXML.maskFileNames.append('TotemCondFormats/DAQInformation/test/T1DeadChannelsList_9255_onlyStrips.xml')

# Random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

################## STEP 1 process.Raw2DigiProducer*process.TriggerBits

process.load('TotemRawData.RawToDigi.Raw2DigiProducer_cfi')
process.Raw2DigiProducer.rpDataProductLabel = cms.untracked.string("")
process.Raw2DigiProducer.rpCCProductLabel = cms.untracked.string("")

process.TriggerBits = cms.EDProducer("RPTriggerBitsProducer", verbose=cms.bool(False))
process.TriggerBits.StripDigiLabel = cms.InputTag("Raw2DigiProducer")

################## STEP 2 process.t1cluster*process.t1rechit*process.t1roads*process.t1tracks

process.load("RecoTotemT1T2.T1MakeCluster.T1MakeCluster_cfi")
process.t1cluster.T1DigiVfatCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.t1cluster.ActivateDeadChannels = cms.bool(True)
process.load("RecoTotemT1T2.T1RecHit.T1RecHit_cfi")
process.t1rechit.T1DigiWireCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.load("RecoTotemT1T2.T1RoadProducer.T1RoadProducer_cfi")
process.t1roads.Alignment = cms.bool(True)
process.load("RecoTotemT1T2.T1TrackProducer2.T1TrackProducer2_cfi")

################## STEP 3 process.T2MCl*process.T2Hits*process.T2RoadColl*process.T2TrackColl2

process.load("RecoTotemT1T2.T2MakeCluster.T2MakeCluster_cfi")
process.T2MCl.T2PadDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2PadDigi")
process.T2MCl.T2StripDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2StripDigi")
process.load("RecoTotemT1T2.T2RecHit.T2RecHit_cfi")
process.load("RecoTotemT1T2.T2RoadPadFinder.NewLabelT2RoadPadFinder_cfi")
process.load("RecoTotemT1T2.T2TrackProducer3.T2TrackColl3_cfi")
process.T2TrackColl3.RoadModuleLabel = "T2RoadPadFinder"

################## STEP 4 process.RPClustProd*process.RPHecoHitProd*process.RPSinglTrackCandFind*process.RPSingleTrackCandCollFit

process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")
process.RPClustProd.DigiLabel = cms.InputTag("Raw2DigiProducer")
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")
process.load("RecoTotemRP.RPSingleCandidateTrackFinder.RPSingleTrackCandFindConf_cfi")
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder'
process.load("RecoTotemRP.RPMulTrackCandidateCollectionFitter.RPMulTrackNonParallelRecoFitter_cfi")

################## STEP 5 process.RPCC*process.T2CC

process.load("L1TriggerTotem.CoincidenceChip.RPCoincidenceProducer_cfi")
process.RPCC.DetTriggerLabel = cms.InputTag("TriggerBits")
process.load("L1TriggerTotem.CoincidenceChip.T2CoincidenceProducer_cfi")
process.T2CC.src = cms.InputTag("Raw2DigiProducer", "T2PadDigi")

################## STEP 6 process.RP220Reconst

process.load("RecoTotemRP.RPInelasticReconstruction.RPRec220_19p2_cfi")              
process.RP220Reconst.BeamProtTransportSetup = process.BeamProtTransportSetup

################## STEP 7 process.TotemNtuplizer

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = "recoRPT1T2.ntuple.root"
process.TotemNtuplizer.RawEventLabel = 'source'
process.TotemNtuplizer.T1DigiVfatCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.TotemNtuplizer.T1DigiWireCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.TotemNtuplizer.T2PadDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2PadDigi")
process.TotemNtuplizer.T2StripDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2StripDigi")
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")
process.TotemNtuplizer.includeDigi = cms.bool(True)
process.TotemNtuplizer.includePatterns = cms.bool(True)
process.TotemNtuplizer.T2IncludePadAndStripDigi = cms.bool(True)

# Configure the output module (save the result in a file)
process.output = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('file:recoRPT1T2.root'),
    outputCommands = cms.untracked.vstring('keep *')
)

process.path = cms.Path(
    process.Raw2DigiProducer
    * process.TriggerBits

    * process.t1cluster
    * process.t1rechit
    * process.t1roads
    * process.t1tracks2

    * process.T2MCl
    * process.T2Hits
    * process.T2RoadPadFinder
    * process.T2TrackColl3

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

