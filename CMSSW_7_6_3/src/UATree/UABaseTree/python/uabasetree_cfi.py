#   For all possibilities that are not here (like some of the input collections),
#   please look at all parameters retrieved in src/GetParameters.cc
#   All the parameters have anyway a default value !

import FWCore.ParameterSet.Config as cms

# Standard Parameters For UABaseTree Process   ----------------------------------------
uabasetree = cms.EDAnalyzer('UABaseTree',
  filterEvents = cms.untracked.bool(False),		#filterEvents for data. Switched Off for MC
  storeEvtId = cms.untracked.bool(True),		
  storeFwdGap = cms.untracked.bool(False),
  storeL1Trig = cms.untracked.bool(True),
  storeL1TrigOld = cms.untracked.bool(True),		#old simple version. Deprecated.
  storeTotemRP = cms.untracked.bool(False),
  #hlt_paths = cms.untracked.vstring( 'HLT_DoubleMu3_v3',
  #                                   'HLT_Ele8_v2' ,
  #                                   'HLT_Jet20_v1' ,
  #                                   'HLT_Jet40_v1' ,
  #                                   'HLT_Jet60_v1' ,
  #                                   'HLT_L1DoubleForJet32_EtaOpp_v1' ,
  #                                   'HLT_L1DoubleForJet8_EtaOpp_v1' ,
  #                                   'HLT_L1DoubleMu0_v1' ,
  #                                   'HLT_L2DoubleMu0_v2' ,
  #                                   'HLT_L1SingleEG12_v1',
  #                                   "HLT_L1SingleEG5_v1",
  #                                   "HLT_L1SingleJet36_v1",
  #                                   "HLT_L1SingleMuOpen_AntiBPTX_v1",
  #                                   "HLT_L1SingleMuOpen_DT_v1",
  #                                   "HLT_L1SingleMuOpen_v1" ,
  #                                   'HLT_L1BscMinBiasORBptxPlusANDMinus_v1' ,
  #                                   'HLT_Mu0_v3' ,
  #                                   'HLT_Mu3_v3' ,
  #                                   'HLT_Mu5_v3' ,
  #                                   'HLT_Photon10_CaloIdVL_v1' ,
  #                                   'HLT_Photon15_CaloIdVL_v1' ,
  #                                   'HLT_PixelTracks_Multiplicity50_Loose' ,
  #                                   'HLT_PixelTracks_Multiplicity60_Loose' ,
  #                                   'HLT_PixelTracks_Multiplicity70_Loose' ,
  #                                   'HLT_ZeroBiasPixel_SingleTrack_v1' ,
  #                                   'HLT_ZeroBias_v1',
  #                                   'HLT_L1Tech53_MB_1_v1',
  #                                   'HLT_L1Tech53_MB_2_v1')
  #hlt_paths = cms.untracked.vstring( 'HLT_ZeroBias_v6',
  #                                   'HLT_L1Tech54_ZeroBias_v1',
  #                                   'HLT_L1Tech40_BPTXAND_1_v1',
  #                                   'HLT_L1Tech53_MB_1_v1',
  #                                   'HLT_L1Tech40_BPTXAND_2_v1',
  #                                   'HLT_L1Tech53_MB_2_v1', 
  #                                   'HLT_SingleJetC5_BHC_v1',
  #                                   'HLT_SingleJetC5_HF_v1',
  #                                   'HLT_TripleTrack02_BHC_v1',
  #                                   'LT_TripleTrack02_HF_v1',
  #                                   'HLT_L1RomanPots_OR_v1',
  #                                   'HLT_SingleForJet15_BHC_v1',
  #                                   'HLT_SingleForJet15_HF_v1' )  
  #hlt_paths = cms.untracked.vstring( 'HLT_L1DoubleEG3_FwdVeto_v1',
  #                                   'HLT_L1DoubleMu0_v1',
  #                                   'HLT_L1DoubleJet20_RomanPotsOR_v1',
  #                                   'HLT_L1DoubleJet20part1_v1',
  #                                   'HLT_L1DoubleJet24_v1',
  #                                   'HLT_L1DoubleJet20part2_v1',
  #                                   'HLT_L1Tech40_BPTXAND_v1',
  #                                   'HLT_L1Tech53_MB_1_v1',
  #                                   'HLT_L1Tech_HF9OR10_v1',
  #                                   'HLT_T1minbias_Tech55_v1',
  #                                   'HLT_L1Tech53_MB_2_v1',
  #                                   'HLT_L1Tech53_MB_3_v1',
  #                                   'HLT_RomanPots_Tech52_v1',
  #                                   'HLT_L1Tech54_ZeroBias_v1',
  #                                   'HLT_ZeroBias_v7'
  #                                   ) 
  hlt_paths = cms.untracked.vstring(
    "HLT_JetE30_NoBPTX3BX_NoHalo_v2",
    "HLT_JetE30_NoBPTX_v2",
    "HLT_JetE50_NoBPTX3BX_NoHalo_v2",
    "HLT_JetE70_NoBPTX3BX_NoHalo_v2",
    "HLT_L1SingleMuOpen_v1",
    "HLT_L1SingleMuOpen_DT_v1",
    "HLT_L1Tech_DT_GlobalOR_v1",
    "HLT_L1RomanPots_SinglePixelTrack04_v2",
    "HLT_PFJet15_NoCaloMatched_v2",
    "HLT_PixelTracks_Multiplicity60_v2",
    "HLT_PixelTracks_Multiplicity85_v2",
    "HLT_PixelTracks_Multiplicity110_v2",
    "HLT_PixelTracks_Multiplicity135_v2",
    "HLT_PixelTracks_Multiplicity160_v2",
    "HLT_Ele5_SC5_JPsi_Mass2to4p5_v2",
    "HLT_DiPFJet15_NoCaloMatched_v2",
    "HLT_DiPFJet15_FBEta2_NoCaloMatched_v2",
    "HLT_DiPFJet15_FBEta3_NoCaloMatched_v2",
    "HLT_PFJet15_FwdEta2_NoCaloMatched_v2",
    "HLT_PFJet15_FwdEta3_NoCaloMatched_v2",
    "HLT_PFJet25_NoCaloMatched_v2",
    "HLT_PFJet25_FwdEta2_NoCaloMatched_v2",
    "HLT_PFJet25_FwdEta3_NoCaloMatched_v2",
    "HLT_PFJet40_NoCaloMatched_v2",
    "HLT_DiPFJetAve15_HFJEC_v2",
    "HLT_DiPFJetAve25_HFJEC_v2",
    "HLT_DiPFJetAve35_HFJEC_v2",
    "HLT_DiPFJetAve15_Central_v2",
    "HLT_DiPFJetAve25_Central_v2",
    "HLT_DiPFJetAve35_Central_v2",
    "HLT_L1RomanPots_SinglePixelTrack02_v2",
    "HLT_Physics_v1",
    "DST_Physics_v1",
    "HLT_Random_v1",
    "HLT_ZeroBias_v1",
    "HLT_ZeroBias_part0_v1",
    "HLT_ZeroBias_part1_v1",
    "HLT_ZeroBias_part2_v1",
    "HLT_ZeroBias_part3_v1",
    "HLT_ZeroBias_part4_v1",
    "HLT_ZeroBias_part5_v1",
    "HLT_ZeroBias_part6_v1",
    "HLT_ZeroBias_part7_v1",
    "HLT_AK4CaloJet30_v2",
    "HLT_AK4CaloJet40_v2",
    "HLT_AK4CaloJet50_v2",
    "HLT_AK4CaloJet80_v2",
    "HLT_AK4CaloJet100_v2",
    "HLT_AK4PFJet30_v2",
    "HLT_AK4PFJet50_v2",
    "HLT_AK4PFJet80_v2",
    "HLT_AK4PFJet100_v2",
    "HLT_HISinglePhoton10_v2",
    "HLT_HISinglePhoton15_v2",
    "HLT_HISinglePhoton20_v2",
    "HLT_HISinglePhoton40_v2",
    "HLT_HISinglePhoton60_v2",
    "HLT_HIL1DoubleMu0_v1",
    "HLT_HIL2Mu3_v2",
    "HLT_HIL2DoubleMu0_v2",
    "HLT_HIL3Mu3_v2",
    "HLT_FullTrack12_v2",
    "HLT_FullTrack20_v2",
    "HLT_FullTrack30_v2",
    "HLT_FullTrack50_v2",
    "HLT_Activity_Ecal_SC7_v1",
    "HLT_EcalCalibration_v1",
    "HLT_HcalCalibration_v1",
    "AlCa_EcalPhiSym_v1",
    "AlCa_EcalPi0EBonly_LowPU_v1",
    "AlCa_EcalPi0EEonly_LowPU_v1",
    "AlCa_EcalEtaEBonly_LowPU_v1",
    "AlCa_EcalEtaEEonly_LowPU_v1",
    "HLT_GlobalRunHPDNoise_v1",
    "HLT_L1Tech_HBHEHO_totalOR_v1",
    "HLT_L1Tech_HCAL_HF_single_channel_v1",
    "HLT_L1Tech6_BPTX_MinusOnly_v1",
    "HLT_L1Tech5_BPTX_PlusOnly_v1",
    "HLT_L1Tech7_NoBPTX_v1",
    "HLT_L1DoubleJet20_v1",
    "HLT_L1DoubleJet28_v1",
    "HLT_L1DoubleJet32_v1",
    "HLT_L1DoubleMuOpen_v1",
    "HLT_L1TOTEM0_RomanPotsAND_part0_v1",
    "HLT_L1TOTEM0_RomanPotsAND_part1_v1",
    "HLT_L1TOTEM0_RomanPotsAND_part2_v1",
    "HLT_L1TOTEM1_MinBias_part0_v1",
    "HLT_L1TOTEM1_MinBias_part1_v1",
    "HLT_L1TOTEM2_ZeroBias_part0_v1",
    "HLT_L1TOTEM2_ZeroBias_part1_v1",
    "HLT_L1MinimumBiasHF1OR_v1",
    "HLT_L1MinimumBiasHF1OR_part0_v1",
    "HLT_L1MinimumBiasHF1OR_part1_v1",
    "HLT_L1MinimumBiasHF1OR_part2_v1",
    "HLT_L1MinimumBiasHF1OR_part3_v1",
    "HLT_L1MinimumBiasHF1OR_part4_v1",
    "HLT_L1MinimumBiasHF1OR_part5_v1",
    "HLT_L1MinimumBiasHF1OR_part6_v1",
    "HLT_L1MinimumBiasHF1OR_part7_v1",
    "HLT_L1MinimumBiasHF2OR_v1",
    "HLT_L1MinimumBiasHF2OR_NoBptxGate_v1",
    "HLT_L1MinimumBiasHF1AND_v1",
    "HLT_L1MinimumBiasHF2AND_v1",
    "HLT_HcalNZS_v1",
    "HLT_HcalPhiSym_v1",
    "HLT_HcalUTCA_v1",
    "AlCa_LumiPixels_Random_v1",
    "AlCa_LumiPixels_ZeroBias_v1",
    "HLT_IsoTrackHE_v1",
    "HLT_IsoTrackHB_v1"

  )
)