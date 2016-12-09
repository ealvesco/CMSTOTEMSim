import FWCore.ParameterSet.Config as cms

process = cms.Process("rpReconstruction")

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# raw-data source
process.load('TotemRawData.Readers.RawDataSource_cfi')
process.source.verbosity = 0
process.source.printProgressFrequency = 0
process.source.fileNames.append('$input_file')

# selection of events to process
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)

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
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/RP_Garage/RP_Dist_Beam_Cent.xml")

process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
process.TotemRPIncludeAlignments.RealFiles = cms.vstring()

# non-parallel pattern recognition
process.load("RecoTotemRP.RPNonParallelTrackCandidateFinder.RPNonParallelTrackCandidateFinder_cfi")
process.NonParallelTrackFinder.verbosity = 0
process.NonParallelTrackFinder.maxHitsPerPlaneToSearch = 5
process.NonParallelTrackFinder.minPlanesPerProjectionToSearch = 3
process.NonParallelTrackFinder.minPlanesPerProjectionToFit = 3
process.NonParallelTrackFinder.threshold = 1.99
#process.NonParallelTrackFinder.threshold = 2.99

# track fitting
process.load("RecoTotemRP.RPTrackCandidateCollectionFitter.RPSingleTrackCandCollFitted_cfi")
process.RPSingleTrackCandCollFit.Verbosity = 0
process.RPSingleTrackCandCollFit.RPTrackCandCollProducer = 'NonParallelTrackFinder' # takes up the non-parallel pattern recognition

process.p = cms.Path(
    process.Raw2DigiProducer *
    process.RPClustProd * 
    process.RPHecoHitProd *
    process.NonParallelTrackFinder *
    process.RPSingleTrackCandCollFit
)

# store desired results
process.output = cms.OutputModule("PoolOutputModule",
  fileName = cms.untracked.string("$output_file"),
  outputCommands = cms.untracked.vstring(
    'keep *',
    'drop *_*_conversionStatus_*'
  )
)

process.outpath = cms.EndPath(process.output)
