import FWCore.ParameterSet.Config as cms

process = cms.Process("Test")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.load('TotemRawData.Readers.RawDataSource_cfi')
process.source.verbosity = 0
process.source.printProgressFrequency = 0

process.source.fileNames = cms.untracked.vstring("run_EVB-wn10_9221.000.vmeb")

process.source.skipEvents = cms.untracked.uint32(0)

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")
#process.load("Configuration.TotemCommon.LoggerMax_cfi")


# Use random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

process.load("Configuration/TotemOpticsConfiguration/OpticsConfig_6500GeV_90_cfi")


process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
process.TotemRPIncludeAlignments.RealFiles = cms.vstring('/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_07_12-13/sr+hsx/45_220.xml', '/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_07_12-13/sr+hsx/56_220.xml', '/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_07_12-13/el/corrections.xml')


# raw to digi conversion
process.load('TotemCondFormats/DAQInformation/DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_220.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_147.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t1_all_run2.xml')
process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t2_4quarters.xml')
process.DAQMappingSourceXML.maskFileNames.append('TotemCondFormats/DAQInformation/test/T1DeadChannelsList_6874_onlyStrips.xml')


#process.load('TotemRawData.RawToDigi.RPDataDigiProducer_cfi')
process.load('TotemRawData.RawToDigi.Raw2DigiProducer_cfi')
process.Raw2DigiProducer.verbosity = 0


# clusterization
process.load("RecoTotemRP.RPClusterSigmaService.ClusterSigmaServiceConf_cfi")
process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")


# reco hit production
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")


# geometry
process.load("Configuration/TotemCommon/geometryGlobal_real_cfi")
toberemoved = []
for xmlfile in process.XMLIdealGeometryESSource.geomXMLFiles:
    if xmlfile.endswith("RP_Dist_Beam_Cent.xml"):
       toberemoved.append(xmlfile)
for xmlfile in toberemoved:
    process.XMLIdealGeometryESSource.geomXMLFiles.remove(xmlfile)
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/RP_Beta_90/RP_Dist_Beam_Cent.xml")
process.TotemRPGeometryESModule = cms.ESProducer("TotemRPGeometryESModule")


# parallel pattern recognition
process.load("RecoTotemRP.RPSingleCandidateTrackFinder.RPSingleTrackCandFindConf_cfi")
process.RPSinglTrackCandFind.Verbosity = 0
process.RPSinglTrackCandFind.RoadSize = 0.3 # mm
process.RPSinglTrackCandFind.MinHitsPerCoord = 3
process.RPSinglTrackCandFind.MaxHitsPerDetector = 5
process.RPSinglTrackCandFind.ReduceWeightsWithMultiplicity = False


# non-parallel pattern recognition
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.NonParallelTrackFinder.verbosity = 0
process.NonParallelTrackFinder.maxHitsPerPlaneToSearch = 5
process.NonParallelTrackFinder.minPlanesPerProjectionToSearch = 3
process.NonParallelTrackFinder.minPlanesPerProjectionToFit = 3
process.NonParallelTrackFinder.threshold = 2.99


# track fitting
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.Verbosity = 0
#process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'RPSinglTrackCandFind' # takes up the parallel pattern recognition
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder' # takes up the non-parallel pattern recognition


#process.load("RecoTotemRP/RPInelasticReconstruction/Rec_6500GeV_beta_90_cfi")
#process.RP2202ArmReconst.BeamProtTransportSetup = process.BeamProtTransportSetup
#process.RP2202ArmReconst.ExpectedRPResolution = 0.020 #mm
#process.RP2202ArmReconst.Verbosity = 0


process.load("RecoTotemRP/RPInelasticReconstruction/Rec_6500GeV_beta_90_cfi")
process.RP220Reconst.BeamProtTransportSetup = process.BeamProtTransportSetup
process.RP220Reconst.ExpectedRPResolution = 0.020 #mm
process.RP220Reconst.Verbosity = 0
process.RP220Reconst.ElasticScatteringReconstruction = False


process.TriggerBits = cms.EDProducer("RPTriggerBitsProducer",
    verbose = cms.bool(False)
)

process.load('L1TriggerTotem.CoincidenceChip.RPCoincidenceProducer_cfi')

process.load("RecoTotemRP.RPMulTrackCandidateCollectionFitter.RPMulTrackNonParallelRecoFitter_cfi")

# T2 ##############
#Fill T2 digi and vfat object
process.RawToDigi = cms.EDProducer("T2XMLDataDigiProducer",
  verbosity = cms.untracked.uint32(0),  #was 10
  discardHighOccupancyVfatverbosity= cms.untracked.bool(False)#IMPORTANT
)


process.load("SimTotem.T2Digitizer.T2Digis_TuneG_5525_5535_May2011Effi_Internal_GlobalMisalBBConf_cfi")
process.T2Digis.saveDigiVFAT=cms.bool(True) #False DEF


process.load("RecoTotemT1T2.T2MakeCluster.T2MakeCluster_cfi")
process.T2MCl.TakeCleanEventOnly=cms.bool(False) #IMPORTANT
process.load("RecoTotemT1T2.T2RecHit.T2RecHit_cfi")
process.T2Hits.Cl1MaxPad = cms.uint32(25) #Tune better
process.T2Hits.Cl1MaxStrip = cms.uint32(25)
process.T2Hits.IncludeClass0Hits = True
process.T2Hits.inputFileNameMisal=cms.untracked.string('SimTotem/T2Digitizer/data/run_5525-5535_IntAlignHX50000Evt_XovY0.3HIP_ANDGLOB_BBConf.dat')

process.T2Hits.useTXTfile=cms.bool(False)   #True for data
process.T2Hits.InsertAlignmentbyCFG=cms.bool(False) # True for data 
process.T2Hits.verbosity=cms.untracked.bool(False)
process.T2Hits.CorrectWithResolution=cms.bool(True) #False:Old Strategy


process.load("RecoTotemT1T2.T2RoadPadFinder.NewLabelT2RoadPadFinder_cfi")
process.T2RoadPadFinder.HitLabel=cms.string("T2Hits")
process.T2RoadPadFinder.CluLabel=cms.string("T2MCl")
process.T2RoadPadFinder.verbosity = 0
process.T2RoadPadFinder.TwoPointsTubesAngularCollinearity=0.07
process.T2RoadPadFinder.MinCluSize_considered_asBlobs = cms.int32(5)
process.T2RoadPadFinder.MinimumNumCl1Hit= 3
process.T2RoadPadFinder.chi2XYProb_Thr= 0.01
process.T2RoadPadFinder.Nmin_padsFinal= 4
process.T2RoadPadFinder.T2RoadCollProdName="NewRoadFinderRELOAD"
process.T2RoadPadFinder.AllowsPadReAssociation=False
process.T2RoadPadFinder.AllowsConcurrentBranches=False
process.T2RoadPadFinder.useStraightPadTowers= cms.bool(True)#False

#################################################################################################################
process.T2RoadPadFinder.ResolveOverlapDoubleCount = cms.bool(True) #Default is True, False for shadow alignment
#################################################################################################################

process.T2RoadPadFinder.OverlapDoubleCountDR = cms.double(2.0) #Depend on your alignment Resol  
process.T2RoadPadFinder.OverlapDoubleCountDPhi =cms.double(3.5)
process.T2RoadPadFinder.OverlapDoubleCountDTheta =  cms.double(0.01)

process.T2RoadPadFinder.QuartedSelected = cms.vint32(0,1,2,3)
process.T2RoadPadFinder.BiggestTubeAngleConsidered =cms.double(0.3)
process.T2RoadPadFinder.NumSigma= cms.double(2.)
process.T2RoadPadFinder.NumPadCluOccupancyAlert= cms.double(50.)
process.T2RoadPadFinder.InefficiencyMaxJump= cms.int32(3)#2 is default


process.load("RecoTotemT1T2.T2TrackProducer3.T2TrackColl3_cfi")
process.T2TrackColl3.StripFitting=cms.bool(False)
process.T2TrackColl3.RoadModuleLabel="T2RoadPadFinder"
process.T2TrackColl3.RoadInstanceLabel="NewRoadFinderRELOAD"
process.T2TrackColl3.verbosity=False
process.T2TrackColl3.RemoveOutliers=True



process.load("RecoTotemT1T2.T1MakeCluster.T1MakeCluster_cfi")
process.t1cluster.ActivateDeadChannels=True
process.load("RecoTotemT1T2.T1RecHit.T1RecHit_cfi")
process.load("RecoTotemT1T2.T1RoadProducer.T1RoadProducer_cfi")
process.t1roads.Alignment = cms.bool(True)
process.load("RecoTotemT1T2.T1TrackProducer2.T1TrackProducer2_cfi")

#delete FROM EXISTING SCRIPT AND REPLACE BY THE LINES BELOW

process.Raw2DigiProducer.rpDataProductLabel = cms.untracked.string("")
process.Raw2DigiProducer.rpCCProductLabel = cms.untracked.string("")
process.TriggerBits.StripDigiLabel = cms.InputTag("Raw2DigiProducer")
process.RPCC.DetTriggerLabel = cms.InputTag("TriggerBits")
process.RPClustProd.DigiLabel  = cms.InputTag("Raw2DigiProducer")

process.p = cms.Path(
      process.Raw2DigiProducer 
    * process.TriggerBits 
    * process.RPCC 
    * process.RPClustProd
    * process.RPHecoHitProd 
    * process.RPSinglTrackCandFind
    * process.NonParallelTrackFinder
    * process.RPSingleTrackCandCollFit
    * process.RPMulTrackNonParallelCandCollFit
    * process.RP220Reconst
 #   * process.RP2202ArmReconst
    * process.T2MCl
    * process.T2Hits
    * process.T2RoadPadFinder
    * process.T2TrackColl3
    * process.t1cluster
    * process.t1rechit
    * process.t1roads
    * process.t1tracks2
)

# store desired results
process.output = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string("out.root"),
    outputCommands = cms.untracked.vstring(
        'keep *'
    )
)

process.outpath = cms.EndPath(process.output)
