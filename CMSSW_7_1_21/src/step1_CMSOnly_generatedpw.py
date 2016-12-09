# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: --filein file:MBRPythia8_RPRECO.root --fileout file:step1_MBRPythia8_RPRECO_CMS_SIM.root --mc --eventcontent RAWSIM --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1,Configuration/DataProcessing/Utils.addMonitoring --datatier SIM --conditions MCRUN2_71_V3::All --beamspot Realistic25ns13TeVCollision --step SIM --magField 38T_PostLS1 --python_filename step1_CMSOnly_generated.py --no_exec -n -1
import FWCore.ParameterSet.Config as cms

process = cms.Process('SIM')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.Geometry.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
     fileNames = cms.untracked.vstring('/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pomwig/SDPlus/step0/Dijets_v1/RP-GEN-SIM-RECO-PomwigDijetsPlus-newformat-v1//POMWIGPlus_13TeV_RPRECO_119.root')
#'/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pomwig/sdminus/step0/Dijets_v1/RP-GEN-SIM-RECO-PomwigDijetsMinus-newformat-v1//POMWIGPlus_13TeV_RPRECO_184.root')
#    fileNames = cms.untracked.vstring('file:/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_0_4/src/Configuration/TotemStandardSequences/test/CMSTOTEM_LowPU2015/PYTHIA8_MB_13TeV_RPRECO_1.root')
#     fileNames = cms.untracked.vstring('file:/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_0_4/src/Configuration/TotemStandardSequences/test/CMSTOTEM_LowPU2015/POMWIGPlus_13TeV_RPRECO_1.root')
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.19 $'),
    annotation = cms.untracked.string('--filein nevts:-1'),
    name = cms.untracked.string('Applications')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string('file:step1_SDPlusPomwig_RPRECO_CMS_SIM.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('SIM')
    )
)

# Additional output definition
outputCommandsRP = [
     'keep *_totemRPAnalysis_*_*',
     'drop *_*_TotemHitsRP_SIM',
     'drop *_*_TotemHitsT1_SIM',
     'drop *_*_TotemHitsT2Gem_SIM',
     'keep *_SmearingGenerator_*_*',
     'keep *_genParticles_*_*', 
     'keep *_genParticlesForJets_*_*', 
     'keep *_kt4GenJets_*_*', 
     'keep *_kt6GenJets_*_*', 
     'keep *_iterativeCone5GenJets_*_*', 
     'keep *_ak4GenJets_*_*', 
     'keep *_ak7GenJets_*_*', 
     'keep *_ak8GenJets_*_*', 
     'keep *_ak4GenJetsNoNu_*_*', 
     'keep *_ak8GenJetsNoNu_*_*', 
     'keep *_genCandidatesForMET_*_*', 
     'keep *_genParticlesForMETAllVisible_*_*', 
     'keep *_genMetCalo_*_*', 
     'keep *_genMetCaloAndNonPrompt_*_*', 
     'keep *_genMetTrue_*_*', 
     'keep *_genMetIC5GenJs_*_*',
     'keep *_generator_*_*'


             ]
process.RAWSIMoutput.outputCommands.extend( outputCommandsRP )

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'MCRUN2_71_V3::All', '')

# Path and EndPath definitions
process.simulation_step = cms.Path(process.psim)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)

# customisation of the process.

# Automatic addition of the customisation function from Configuration.DataProcessing.Utils
from Configuration.DataProcessing.Utils import addMonitoring 

#call to customisation function addMonitoring imported from Configuration.DataProcessing.Utils
process = addMonitoring(process)

# Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.postLS1Customs
from SLHCUpgradeSimulations.Configuration.postLS1Customs import customisePostLS1 

#call to customisation function customisePostLS1 imported from SLHCUpgradeSimulations.Configuration.postLS1Customs
process = customisePostLS1(process)

# End of customisation functions
