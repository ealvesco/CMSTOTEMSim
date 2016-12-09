import FWCore.ParameterSet.Config as cms

from Configuration.Info.job_info import *

getInfo()





process = cms.Process("t2Reconstructor")



process.maxEvents = cms.untracked.PSet(

    input = cms.untracked.int32(100) #-1

)



# raw data source run_9510_EVB13_1.000.srs

process.load("TotemRawData.Readers.RawDataSource_cfi")

#process.source.fileNames.append('/tmp/berretti/run_9744_EVB12_1.019.srs')
process.source.fileNames.append('$input_file')

process.source.verbosity = 0

process.source.printProgressFrequency = 0



# mapping files run_8372.000.vmea

process.load('TotemCondFormats.DAQInformation.DAQMappingSourceXML_cfi')

process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/rp_220.xml')

process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t2_3quarters.xml')



# mask files

#process.DAQMappingSourceXML.maskFileNames.append ('TotemAnalysis/T2ValidRawData/test/analysisMaskFileName9261.xml')  

#process.DAQMappingSourceXML.maskFileNames.append('TotemCondFormats/DAQInformation/data/T1DeadChannelsList.xml')



# raw to digi 

process.load('TotemRawData.RawToDigi.Raw2DigiProducer_cfi')

process.Raw2DigiProducer.verbosity = 0



#process.source = cms.Source("PoolSource",

#                            fileNames = cms.untracked.vstring('file:inputfilena#me'),

#                            skipEvents = cms.untracked.uint32(0)#                              

#                            )



process.output = cms.OutputModule("PoolOutputModule",

    fileName = cms.untracked.string("$output_file"),                           

     outputCommands = cms.untracked.vstring('keep *')

)
#('file:run_RECOSIMUStart0run_EVB-wn10_9744.000.root')




process.source.skipEvents = cms.untracked.uint32(0)



process.load("Configuration.TotemCommon.LoggerMin_cfi")


process.load("Configuration.TotemStandardSequences/T2_Digi_and_TrackReconstruction_cfi")



process.load("SimTotem.T2Digitizer.T2DigisSTDGeoEffi_cfi")#T2DigisOnlyPrim_cfi

process.T2Digis.saveDigiVFAT=cms.bool(True)

process.T2Digis.Misalignment.simulatemisalign=cms.untracked.bool(True)

#Decomment for alignment multi-scenario validation

process.T2Digis.Misalignment.inputFileNameMisal= "/afs/cern.ch/work/b/berretti/CMSSW_7_0_4/CMSSW_7_0_4/src/TotemAlignment/T2TrkBasedInternalAlignment/test/T2AlignGlobInt2015_9241to9271_V0.dat" 

process.load("RecoTotemT1T2.T2MakeCluster.T2MakeCluster_cfi")


process.T2MCl.T2PadDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2PadDigi")

process.T2MCl.T2StripDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2StripDigi")



process.T2MCl.TakeCleanEventOnly=cms.bool(False) #IMPORTANT

#process.T2MCl.maskvect = cms.vuint32(21,23,25,27,29)

process.T2MCl.SimuClusterEfficiency=cms.bool(False)

process.T2MCl.EffiGeoRootFileName= cms.string("RecoTotemT1T2/T2MakeCluster/data/Geom_effiOutput_All8372_Effi_V2Pl.root")

process.load("Configuration.TotemCommon.RandomNumbers_cfi")


process.load("RecoTotemT1T2.T2RecHit.T2RecHit_cfi")

process.T2Hits.Cl1MaxPad = cms.uint32(25) #Tune better

process.T2Hits.Cl1MaxStrip = cms.uint32(25)

process.T2Hits.IncludeClass0Hits = True

process.T2Hits.inputFileNameMisal=cms.untracked.string('TotemAlignment/T2TrkBasedInternalAlignment/test/T2AlignGlobInt2015_9241to9271_V0.dat')




process.T2Hits.useTXTfile=cms.bool(True)

process.T2Hits.InsertAlignmentbyCFG=cms.bool(True) # True for data True

process.T2Hits.verbosity=cms.untracked.bool(False)

process.T2Hits.CorrectWithResolution=cms.bool(True) #False:Old Strategy True:New Strategy




process.load("RecoTotemT1T2.T2RoadPadFinder.NewLabelT2RoadPadFinder_cfi")#T2RoadPadFinder_cfi




process.T2RoadPadFinder.HitLabel=cms.string("T2Hits")#T2HitsSTD for effi reco |  #T2Hits for std reco

process.T2RoadPadFinder.CluLabel=cms.string("T2MCl")#T2MClSTD for effi reco |   T2MCl  for std reco

process.T2RoadPadFinder.verbosity = 0

process.T2RoadPadFinder.TwoPointsTubesAngularCollinearity=0.09#0.07 default

process.T2RoadPadFinder.MinCluSize_considered_asBlobs = cms.int32(5)

process.T2RoadPadFinder.MinimumNumCl1Hit= 3

process.T2RoadPadFinder.chi2XYProb_Thr= 0.01

process.T2RoadPadFinder.Nmin_padsFinal= 4

process.T2RoadPadFinder.T2RoadCollProdName="NewRoadFinderRELOAD"

process.T2RoadPadFinder.AllowsPadReAssociation=False

process.T2RoadPadFinder.AllowsConcurrentBranches=False

process.T2RoadPadFinder.useStraightPadTowers= cms.bool(True)#False for internal alignment studies

process.T2RoadPadFinder.ResolveOverlapDoubleCount = cms.bool(False) #Default is True, False for shadow alignment and dndeta An

process.T2RoadPadFinder.OverlapDoubleCountDR = cms.double(2.0) #Depend on your alignment Resol

process.T2RoadPadFinder.OverlapDoubleCountDPhi =cms.double(3.5)

process.T2RoadPadFinder.OverlapDoubleCountDTheta =  cms.double(0.01)




process.T2RoadPadFinder.QuartedSelected = cms.vint32(0,1,2,3)

process.T2RoadPadFinder.BiggestTubeAngleConsidered =cms.double(0.3)

process.T2RoadPadFinder.NumSigma= cms.double(2.)#Important for ALignment (6) istead of 2

#TolleranceDX

process.T2RoadPadFinder.NumPadCluOccupancyAlert= cms.double(60.)#default 50 also in the 8 TeV.

process.T2RoadPadFinder.InefficiencyMaxJump= cms.int32(3)#2 is default

process.T2RoadPadFinder.Nmin_padsFinal= 4







process.load("RecoTotemT1T2.T2TrackProducer3.T2TrackColl3_cfi")

process.T2TrackColl3.StripFitting=cms.bool(False)

process.T2TrackColl3.RoadModuleLabel="T2RoadPadFinder"

process.T2TrackColl3.RoadInstanceLabel="NewRoadFinderRELOAD"

process.T2TrackColl3.verbosity=False

process.T2TrackColl3.RemoveOutliers=True #False for Internal  ALignment studies

process.T2TrackColl3.GhostSuppression=True

process.T2TrackColl3.PickUpDisplacedHit=False

process.T2TrackColl3.PickUpRadius=2.0











# ntuplizer scratch/src/Configuration/TotemOpticsConfiguration/python/OpticsConfig_6500GeV_90_cfi.py



process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_cfi")

# ntuplizer

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")

#process.TotemNtuplizer.outputFileName = 'BARAB5_rpt2_nolook.root'

process.TotemNtuplizer.outputFileName = 'T2Ntple_run_RECOSIMUStart0run_EVB-wn10_9250.000.vmeb.root'

process.TotemNtuplizer.verbosity = cms.untracked.uint32(0)

process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')

process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')

process.TotemNtuplizer.RPFittedTrackCollectionLabel = cms.InputTag("RPSingleTrackCandCollFit")

process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")





process.TriggerBits = cms.EDProducer("RPTriggerBitsProducer",

    verbose = cms.bool(False)

)



process.TotemNtuplizer.ProductLabelSimu = 'rpCCOutput'

process.TotemNtuplizer.ModulLabelSimu = 'Raw2DigiProducer'

process.TotemNtuplizer.RawEventLabel = 'source'

process.Raw2DigiProducer.rpDataProductLabel = cms.untracked.string("")

process.Raw2DigiProducer.rpCCProductLabel = cms.untracked.string("")

process.TriggerBits.StripDigiLabel = cms.InputTag("Raw2DigiProducer")



process.p1 = cms.Path(process.Raw2DigiProducer*process.TriggerBits*process.T2MCl*process.T2Hits*process.T2RoadPadFinder*process.T2TrackColl3)

#*process.T2Hits*process.T2RoadPadFinder*process.T2TrackColl3



process.outpath = cms.EndPath(process.output) 













