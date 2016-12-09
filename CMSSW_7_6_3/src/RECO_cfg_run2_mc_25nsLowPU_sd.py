# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step2 --filein file:step1_DIGI_L1_DIGI2RAW_HLT.root --fileout file:step1_MBRPythia8_RPRECO_CMS_RECO.root --mc --eventcontent AODSIM --datatier AODSIM --conditions 76X_mcRun2_asymptotic_v12 --step RAW2DIGI,L1Reco,RECO --era Run2_25ns --python_filename RECO_cfg_run2_mc_25nsLowPU_v2.py --no_exec --customise Configuration/DataProcessing/Utils.addMonitoring -n 82
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('RECO',eras.Run2_25ns)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(#'/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pythia8/step2/Production_CMSSIM-RPRECO_PYTHIA8-Dijets_v2/Production_CMSSIM-DIGI-HLT-RPRECO-NewFormat-PYTHIA8Dijets-pT20GeV/161024_134301/0000/step1_DIGI_L1_DIGI2RAW_HLT_9.root'),
   'file:step1_DIGI_L1_DIGI2RAW_HLT_sdpwzplus.root'),#step1_DIGI_L1_DIGI2RAW_HLT.root
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step2 nevts:82'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.AODSIMoutput = cms.OutputModule("PoolOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(4),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('AODSIM'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(15728640),
    fileName = cms.untracked.string('file:step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO.root'),
    outputCommands = process.AODSIMEventContent.outputCommands
)

# Additional output definition
outputCommandsRP = [
        'keep *_TriggerResults_*_*',
       'keep *_totemRPAnalysis_*_*',
        'keep *_SmearingGenerator_*_*',
        'keep *_siStripClusters_*_*',
        'keep *_siPixelClusters_*_*',
        'keep *_generalTracks_*_*',
        'keep *_generator_*_*'
]
process.AODSIMoutput.outputCommands.extend( outputCommandsRP )
# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.AODSIMoutput_step = cms.EndPath(process.AODSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.endjob_step,process.AODSIMoutput_step)

# customisation of the process.

# Automatic addition of the customisation function from Configuration.DataProcessing.Utils
from Configuration.DataProcessing.Utils import addMonitoring 

#call to customisation function addMonitoring imported from Configuration.DataProcessing.Utils
process = addMonitoring(process)

# End of customisation functions

