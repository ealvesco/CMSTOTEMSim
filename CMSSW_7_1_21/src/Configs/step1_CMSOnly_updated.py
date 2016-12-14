from step1_CMSOnly_generated import *
import random
# set proper geometry
process.__delattr__("MuonNumberingInitialization")
process.__delattr__("XMLFromDBSource")
process.load('Geometry.CMSCommonData.cmsExtendedGeometry2015XML_cfi')
# # set RNG seed
process.RandomNumberGeneratorService.generator.initialSeed = cms.untracked.uint32(random.randint(0,900000000))#456789
process.RandomNumberGeneratorService.g4SimHits.initialSeed = cms.untracked.uint32(random.randint(0,900000000)) #9876
process.RandomNumberGeneratorService.VtxSmeared.initialSeed = cms.untracked.uint32(random.randint(0,900000000)) #123456789

outputCommandsRP = [
     'keep *_totemRPAnalysis_*_*',
     'drop *_*_TotemHitsRP_SIM',
     'drop *_*_TotemHitsT1_SIM',
     'drop *_*_TotemHitsT2Gem_SIM'
             ]
process.RAWSIMoutput.outputCommands.extend( outputCommandsRP )
