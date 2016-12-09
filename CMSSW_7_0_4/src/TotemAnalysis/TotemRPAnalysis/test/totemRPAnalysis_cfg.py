import FWCore.ParameterSet.Config as cms

#process = cms.Process("NTUPLETOTEM")
from Configuration.TotemStandardSequences.valRPinelasticDefault_cfg import *

process.setName_("valRPinelasticBeta90Energy6500GeV")
process.source = cms.Source("PoolSource",
        fileNames = cms.untracked.vstring(),
        noEventSort = cms.untracked.bool(True)
   )

process.source.fileNames = ['file:/afs/cern.ch/work/e/eliza/public/val/cmssw_704/MinimumBias_RPRECO_CMSSIM_1_test-v2.root']

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
  input = cms.untracked.int32(-1)
)

process.TotemRPGeometryESModule = cms.ESProducer("TotemRPGeometryESModule")
# geometry
process.load("Configuration.TotemCommon.geometryRP_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/2015_10_17_fill4509/RP_Dist_Beam_Cent.xml")
#process.load("Configuration.TotemCommon.geometryRPT1T2CMS_cfi")
#process.XMLIdealGeometryESSource.geomXMLFiles.append('Geometry/TotemRPData/data/RP_Beta_90/RP_Dist_Beam_Cent.xml')
#process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_cfi")
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_50urad_cfi")
######################################
process.load("TotemRPValidation.RPReconstructedTracksValidation.ReconstTracksVal_beta_90_6500GeV_cfi")
process.load("TotemRPValidation.RPAngleValidation.AngleVal_6500_90_cfi")
process.load("TotemRPValidation.InelasticReconstructionValidation.InelasticReconstVal_90_6500GeV_cfi")

process.RPHitDists.outputFile = cms.string('file:'+process.name_()+'_RPHitDists.root')
process.RPRecTracksVal.HistogramFileName = cms.string('file:'+process.name_()+'_RPRecTracksVal.root')
process.RPAngleVal.HistogramFileName = 'file:'+process.name_()+'_RPAngleVal.root'
process.RPInelProtRecVal.HistogramFileName = cms.string('file:'+process.name_()+'_RPInelProtRecVal.root')
process.SmearingValidation.outputFile = cms.string('file:'+process.name_()+'_SmearingValidation.root')
process.TotemNtuplizer.outputFileName = cms.untracked.string('file:'+process.name_()+'_ntuple.root')

process.p = cms.Path(process.RPHitDists*process.RPRecTracksVal*process.RPAngleVal*process.RPInelProtRecVal*process.SmearingValidation*process.TotemNtuplizer) 

######################################
process.load("TotemRPValidation.HitDistributions.HitDistributions_cfi")
process.RPHitDists.outputFile = cms.string('file:valMinbiasPythia8_RPHITS_TOTEM.root')

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = 'file:valMinbiasPythia8_NTUPLE_TOTEM.root'
process.TotemNtuplizer.verbosity = 2
process.TotemNtuplizer.ProductLabelSimu = 'RPCCRawBits'
process.TotemNtuplizer.ModulLabelSimu = 'RPDataCCProducer'
process.TotemNtuplizer.RPReconstructedProtonCollectionLabel = cms.InputTag('RP220Reconst')
process.TotemNtuplizer.RPReconstructedProtonPairCollectionLabel = cms.InputTag('RP220Reconst')
#process.TotemNtuplizer.T1TrackLabel = 't1tracks2'
process.TotemNtuplizer.modules = cms.vstring('rp')

from TotemAnalysis.TotemRPAnalysis.TotemRPAnalysis_cfi import TotemRPAnalysis
process.totemRPAnalysis = cms.EDProducer("TotemRPEDMProducer",
	TotemRPAnalysis = TotemRPAnalysis
	)

process.totemRPTreeAnalysis = cms.EDAnalyzer("TotemRPTreeProducer",

        TotemRPAnalysis = TotemRPAnalysis)

process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('drop *',
        'keep *_totemRPAnalysis_*_*',
        'keep *_TriggerResults_*_*'
    ),
    fileName = cms.untracked.string('file:totemRPAnalysis.root'),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('analysis_step')
    )
)
process.TFileService = cms.Service("TFileService",
	fileName = cms.string("forwardEDMAnalysis_TFileService.root" )
	)
process.analysis_step = cms.Path(process.RPHitDists*process.TotemNtuplizer+process.totemRPAnalysis+process.totemRPTreeAnalysis)

process.out_step = cms.EndPath(process.output)

#print process.dumpPython()
