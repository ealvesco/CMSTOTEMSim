from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

# /TOTEM_romanPots2_0/Run2015D-PromptReco-v4/AOD
runNumber = 259237
version = 1
taskName = 'UABaseTree_TOTEM_romanPots2_0_Run2015D-PromptReco-v4_RECO_Run%d-all-v%d' % (runNumber,version)
outputFileName = 'UABaseTree_PromptReco-all.root'

config.General.requestName = taskName
config.General.workArea = 'CRAB'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'UABaseTree_forward_LowPU2015_cfg.py'
config.JobType.outputFiles = [outputFileName]

config.Data.inputDataset = '/TOTEM_romanPots2_0/Run2015D-PromptReco-v4/RECO'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 40
config.Data.runRange = '%d' % runNumber
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/Cert_259152-259431_13TeV_PromptReco_Collisions15_25ns_Totem_JSON.txt'
config.Data.outLFNDirBase = '/store/group/phys_diffraction/CMSTotemLowPU2015' 
config.Data.outputDatasetTag = taskName
config.Data.publication = False
#config.Data.ignoreLocality = True

config.Site.storageSite = 'T2_CH_CERN'
