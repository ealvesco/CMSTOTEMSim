import FWCore.ParameterSet.Config as cms

from UATree.UABaseTree.UABaseTree_forward_MC_cfg import process
process.source.fileNames = [
'file:../../step3_PWSDPlus_RPRECO_CMS_RECO.root'
#'root://eoscms//eos/cms/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pomwig/sdminus/step3/Production_CMSSIM-RPRECO_POMWIG-SDMinusDijets_v1/Production_CMSSIM-DIGI-HLT-RECO-RPRECO-NewFormat-POMWIGSDMinusDijets-pT20GeV/161113_190226/0000/step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO_1.root'
#'file:../../step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO.root'
]
process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')

process.maxEvents.input = -1
process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_RunIIFall15DR76_v1'
#process.uabasetree.hlt_paths = []

#process.load("UATree.UABaseTree.hltFilter_cfi")
#process.hltZeroBias = process.hltFilter.clone(HLTPaths = ['HLT_ZeroBias_v1'])
#process.p.replace(process.uabasetree, process.hltZeroBias+process.uabasetree) 

process.uabasetree.storeTotemRP = True
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.uabasetree.outputfilename = "UABaseTree_LowPU2015_MC-DijetsPomwigSDPlus_100.root"
