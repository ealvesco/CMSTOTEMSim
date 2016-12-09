import FWCore.ParameterSet.Config as cms

#from Configuration.Info.job_info import *
#getInfo()

process = cms.Process("rpReconstruction")

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5000)
)

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")

process.load('TotemRawData.Readers.RawDataSource_cfi')
process.source.verbosity = 0
process.source.printProgressFrequency = 0
# process.source.fileNames.append('root://eostotem/eos/totem/data/rawdata/2015/run_9976_EVB12_2.077.srs')
process.source.fileNames.append('/afs/cern.ch/work/h/hniewiad/private/20151102_90m/eos/totem/data/rawdata/2015/run_9976_EVB12_2.077.srs')

# raw to digi conversion
process.load('TotemCondFormats.DAQInformation.DAQMappingSourceXML_cfi')
process.DAQMappingSourceXML.mappingFileNames = cms.untracked.vstring("TotemCondFormats/DAQInformation/data/rp_220_210far.xml")

process.load('TotemRawData.RawToDigi.Raw2DigiProducer_cfi')
process.Raw2DigiProducer.verbosity = 0

# clusterization
process.load("RecoTotemRP.RPClusterSigmaService.ClusterSigmaServiceConf_cfi")
process.load("RecoTotemRP.RPClusterizer.RPClusterizationConf_cfi")
process.RPClustProd.DigiLabel = cms.InputTag("Raw2DigiProducer", "rpDataOutput")

# reco hit production
process.load("RecoTotemRP.RPRecoHitProducer.RPRecoHitProdConf_cfi")

# geometry
process.load("Configuration.TotemCommon.geometryRP_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/2015_10_17_fill4509/RP_Dist_Beam_Cent.xml")

#alignment
process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
process.TotemRPIncludeAlignments.RealFiles = cms.vstring("TotemAlignment/RPData/LHC/2015_10_17_fill4509/version1/sr/45.xml", "TotemAlignment/RPData/LHC/2015_10_17_fill4509/version1/sr/56.xml")

# Optics
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_50urad_cfi")

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


#ntuplizer
process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = "output.ntuple.root"
process.TotemNtuplizer.RawEventLabel = 'source'
process.TotemNtuplizer.verbosity = 0
# process.TotemNtuplizer.T1DigiVfatCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
# process.TotemNtuplizer.T1DigiWireCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
# process.TotemNtuplizer.T2PadDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2PadDigi")
# process.TotemNtuplizer.T2StripDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2StripDigi")
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
# process.TotemNtuplizer.RPMulFittedTrackCollectionLabel = cms.InputTag("RPMulTrackNonParallelCandCollFit")
process.TotemNtuplizer.includeDigi = cms.bool(True)
process.TotemNtuplizer.includePatterns = cms.bool(True)
# process.TotemNtuplizer.T2IncludePadAndStripDigi = cms.bool(True)


process.p = cms.Path(
    process.Raw2DigiProducer *
    process.RPClustProd * 
    process.RPHecoHitProd *
    process.NonParallelTrackFinder *
    process.RPSingleTrackCandCollFit *
    process.RP220Reconst *
    process.TotemNtuplizer
)

# store desired results
process.output = cms.OutputModule("PoolOutputModule",
  fileName = cms.untracked.string("out_reco_file.root")
#  outputCommands = cms.untracked.vstring(
#    'keep *',
#    'drop TotemRawEvent_*_*_*',
#    'drop *_*_conversionStatus_*'
#  )
)

process.outpath = cms.EndPath(process.output)

print("----------------------------------------------------------------------------------------------------")
print("")
print(process.dumpConfig())
print("")
print("----------------------------------------------------------------------------------------------------")
