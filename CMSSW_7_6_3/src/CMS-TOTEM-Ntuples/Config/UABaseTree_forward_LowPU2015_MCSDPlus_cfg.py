
import FWCore.ParameterSet.Config as cms

from UATree.UABaseTree.UABaseTree_forward_MC_cfg import process
process.source.fileNames = [
"file:/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/test/CMSSW_7_6_3/src/step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO.root"
# "file:/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src/step1_DijetsPythia8_RPRECO_CMS_RECO.root"
#'root://eoscms//eos/cms/store/group/phys_diffraction/CMSTotemLowPU2015/Production_CMSSIM-DIGI-HLT-RECO-RPRECO-NewFormat-Test-v3/crab_RECO_Production_CMS-RP-NewFormat-Test-v3/160622_133507/0000/step1_MBRPythia8_RPRECO_CMS_RECO_1.root',
#'root://eoscms//eos/cms/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pythia8/step3/Production_CMSSIM-RPRECO_PYTHIA8-Dijets_v2/Production_CMSSIM-DIGI-HLT-RECO-RPRECO-NewFormat-PYTHIA8Dijets-pT20GeV/161028_122027/0000/step1_DijetsPythia8_RPRECO_CMS_RECO_1.root'
#"root://eoscms//eos/cms/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pomwig/sdminus/step3/Production_CMSSIM-RPRECO_POMWIG-SDMinusDijets_v1/Production_CMSSIM-DIGI-HLT-RECO-RPRECO-NewFormat-POMWIGSDMinusDijets-pT20GeV/161113_190226/0000/step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO_1.root"
#'root://eoscms//eos/cms/store/group/phys_diffraction/CMSTotemLowPU2015/emc/MC/pomwig/sdminus/step3/Production_CMSSIM-RPRECO_POMWIG-SDMinusDijets_v1/Production_CMSSIM-DIGI-HLT-RECO-RPRECO-NewFormat-POMWIGSDMinusDijets-pT20GeV/161113_190226/0000/step1_DijetsPomwigSDMinus_RPRECO_CMS_RECO_8.root'

]
#process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')

process.maxEvents.input = -1
process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_RunIIFall15DR76_v1'

#process.uabasetree.hlt_paths = []

#process.load("UATree.UABaseTree.hltFilter_cfi")
#process.hltZeroBias = process.hltFilter.clone(HLTPaths = ['HLT_ZeroBias_v1'])
#process.p.replace(process.uabasetree, process.hltZeroBias+process.uabasetree) 

process.uabasetree.storeTotemRP = True
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

#process.uabasetree.outputfilename = "UABaseTree_LowPU2015_MC-all-test-2k-v2.root"
#process.uabasetree.outputfilename = "UABaseTree_LowPU2015_MC-DijetsPythia8_all.root" 
#process.uabasetree.outputfilename = "UABaseTree_LowPU2015_MC-test-Pythia8_all.root"                                                                          
process.uabasetree.outputfilename = "UABaseTree_LowPU2015_MC-DijetsPomwigSDMinus_DijetsPomwigSDMinus_RPRECO_CMS_RECO_200.root"
