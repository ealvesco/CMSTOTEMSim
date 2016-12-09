import FWCore.ParameterSet.Config as cms

process = cms.Process("recoT1")

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
     input = cms.untracked.int32(100)
)

# Configure if you want to detail or simple log information.
# LoggerMax -- detail log info output including: errors.log, warnings.log, infos.log, debugs.log
# LoggerMin -- simple log info output to the standard output (e.g. screen)
process.load("Configuration.TotemCommon.LoggerMin_cfi")



# RawDataSource
process.load('TotemRawData.Readers.RawDataSource_cfi')
#process.source.fileNames.append('/project/gruppo1/totem/IP5_2015/Data/run_EVB-wn10_9261.000.vmeb')
process.source.fileNames.append('$input_file')

# Raw to digi conversion
process.load('TotemCondFormats.DAQInformation.DAQMappingSourceXML_cfi')

process.DAQMappingSourceXML.mappingFileNames.append('TotemCondFormats/DAQInformation/data/t1_all_run2.xml')

process.DAQMappingSourceXML.maskFileNames.append('TotemCondFormats/DAQInformation/test/T1DeadChannelsList_9255_onlyStrips.xml')

# Random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

################## STEP 1process.Raw2DigiProducer*process.TriggerBits

process.load('TotemRawData.RawToDigi.Raw2DigiProducer_cfi')


process.load("RecoTotemT1T2.T1MakeCluster.T1MakeCluster_cfi")
process.t1cluster.T1DigiVfatCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.t1cluster.ActivateDeadChannels = cms.bool(True)
process.load("RecoTotemT1T2.T1RecHit.T1RecHit_cfi")
process.t1rechit.T1DigiWireCollectionLabel = cms.InputTag("Raw2DigiProducer", "t1DataOutput")
process.load("RecoTotemT1T2.T1RoadProducer.T1RoadProducer_cfi")
process.t1roads.Alignment = cms.bool(True)
process.load("RecoTotemT1T2.T1TrackProducer2.T1TrackProducer2_cfi")


# Configure the output module (save the result in a file)
process.output = cms.OutputModule("PoolOutputModule",
     fileName = cms.untracked.string('$output_file'),
     outputCommands = cms.untracked.vstring('keep *')
)

process.path = cms.Path(
process.Raw2DigiProducer

     *process.t1cluster
     *process.t1rechit
#     *process.t1roads
#     *process.t1tracks2


     )

process.outpath = cms.EndPath(process.output)
