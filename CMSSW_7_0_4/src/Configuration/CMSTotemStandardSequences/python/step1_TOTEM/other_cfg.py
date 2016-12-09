from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

process.source.__delattr__('secondaryFileNames')
del process.__dict__['_Process__paths']['simulation_step'] 
del process.__dict__['_Process__endpaths']['endjob_step']
del process.__dict__['_Process__endpaths']['RAWSIMoutput_step']
process.__dict__['_Process__schedule'] = None

attrs = ['ALCARECOEventContent',
    'AODEventContent',
    'AODSIMEventContent',
    'BeamSpotAOD',
    'BeamSpotFEVT',
    'BeamSpotRECO',
    'CSCGeometryESModule',
    'CaloGeometryBuilder',
    'CaloTopologyBuilder',
    'CaloTowerHardcodeGeometryEP',
    'CastorDbProducer',
    'CastorHardcodeGeometryEP',
    'CommonEventContent',
    'CondDBSetup',
    'DATAMIXEREventContent',
    'DQMEventContent',
    'DQMStore',
    'DTGeometryESModule',
    'DigiToRawFEVT',
    'EITopPAGEventContent',
    'EcalBarrelGeometryEP',
    'EcalElectronicsMappingBuilder',
    'EcalEndcapGeometryEP',
    'EcalLaserCorrectionService',
    'EcalPreshowerGeometryEP',
    'EcalTrigTowerConstituentsMapBuilder',
    'EvtScalersAOD',
    'EvtScalersRECO',
    'FEVTDEBUGEventContent',
    'FEVTDEBUGHLTEventContent',
    'FEVTEventContent',
    'FEVTHLTALLEventContent',
    'FEVTSIMEventContent',
    'GENRAWEventContent',
    'GeneratorInterfaceAOD',
    'GeneratorInterfaceLHE',
    'GeneratorInterfaceRAW',
    'GeneratorInterfaceRECO',
    'GlobalTag',
    'GlobalTrackingGeometryESProducer',
    'HLTDEBUGEventContent',
    'HLTDebugFEVT',
    'HLTDebugRAW',
    'HLTriggerAOD',
    'HLTriggerRAW',
    'HLTriggerRECO',
    'HcalHardcodeGeometryEP',
    'HcalReLabel',
    'IOMCRAW',
    'L1TriggerAOD',
    'L1TriggerFEVTDEBUG',
    'L1TriggerRAW',
    'L1TriggerRAWDEBUG',
    'L1TriggerRECO',
    'LHEEventContent',
    'MEtoEDMConverter',
    'MEtoEDMConverterAOD',
    'MEtoEDMConverterFEVT',
    'MEtoEDMConverterRECO',
    'MEtoMEComparitor',
    'MIXINGMODULEEventContent',
    'MuonDetLayerGeometryESProducer',
    'MuonNumberingInitialization',
    'OutALCARECODtCalib',
    'OutALCARECODtCalibCosmics',
    'OutALCARECODtCalibCosmics_noDrop',
    'OutALCARECODtCalibHI',
    'OutALCARECODtCalibHI_noDrop',
    'OutALCARECODtCalib_noDrop',
    'OutALCARECOEcalCalElectron',
    'OutALCARECOEcalCalElectron_noDrop',
    'OutALCARECOEcalCalEtaCalib',
    'OutALCARECOEcalCalEtaCalib_noDrop',
    'OutALCARECOEcalCalPhiSym',
    'OutALCARECOEcalCalPhiSym_noDrop',
    'OutALCARECOEcalCalPi0Calib',
    'OutALCARECOEcalCalPi0Calib_noDrop',
    'OutALCARECOHcalCalDijets',
    'OutALCARECOHcalCalDijets_noDrop',
    'OutALCARECOHcalCalGammaJet',
    'OutALCARECOHcalCalGammaJet_noDrop',
    'OutALCARECOHcalCalHO',
    'OutALCARECOHcalCalHOCosmics',
    'OutALCARECOHcalCalHOCosmics_noDrop',
    'OutALCARECOHcalCalHO_noDrop',
    'OutALCARECOHcalCalIsoTrk',
    'OutALCARECOHcalCalIsoTrkNoHLT',
    'OutALCARECOHcalCalIsoTrkNoHLT_noDrop',
    'OutALCARECOHcalCalIsoTrk_noDrop',
    'OutALCARECOHcalCalMinBias',
    'OutALCARECOHcalCalMinBiasHI',
    'OutALCARECOHcalCalMinBiasHI_noDrop',
    'OutALCARECOHcalCalMinBias_noDrop',
    'OutALCARECOHcalCalNoise',
    'OutALCARECOHcalCalNoise_noDrop',
    'OutALCARECOLumiPixels',
    'OutALCARECOLumiPixels_noDrop',
    'OutALCARECOMuAlBeamHalo',
    'OutALCARECOMuAlBeamHaloOverlaps',
    'OutALCARECOMuAlBeamHaloOverlaps_noDrop',
    'OutALCARECOMuAlBeamHalo_noDrop',
    'OutALCARECOMuAlCalIsolatedMu',
    'OutALCARECOMuAlCalIsolatedMu_noDrop',
    'OutALCARECOMuAlGlobalCosmics',
    'OutALCARECOMuAlGlobalCosmicsInCollisions',
    'OutALCARECOMuAlGlobalCosmicsInCollisions_noDrop',
    'OutALCARECOMuAlGlobalCosmics_noDrop',
    'OutALCARECOMuAlOverlaps',
    'OutALCARECOMuAlOverlaps_noDrop',
    'OutALCARECOMuAlStandAloneCosmics',
    'OutALCARECOMuAlStandAloneCosmics_noDrop',
    'OutALCARECOMuAlZMuMu',
    'OutALCARECOMuAlZMuMu_noDrop',
    'OutALCARECOPromptCalibProd',
    'OutALCARECOPromptCalibProdSiStrip',
    'OutALCARECOPromptCalibProdSiStrip_noDrop',
    'OutALCARECOPromptCalibProd_noDrop',
    'OutALCARECORpcCalHLT',
    'OutALCARECORpcCalHLT_noDrop',
    'OutALCARECOSiPixelLorentzAngle',
    'OutALCARECOSiPixelLorentzAngle_noDrop',
    'OutALCARECOSiStripCalMinBias',
    'OutALCARECOSiStripCalMinBias_noDrop',
    'OutALCARECOSiStripCalZeroBias',
    'OutALCARECOSiStripCalZeroBias_noDrop',
    'OutALCARECOSiStripPCLHistos',
    'OutALCARECOSiStripPCLHistos_noDrop',
    'OutALCARECOTkAlBeamHalo',
    'OutALCARECOTkAlBeamHalo_noDrop',
    'OutALCARECOTkAlCosmics',
    'OutALCARECOTkAlCosmics0T',
    'OutALCARECOTkAlCosmics0THLT',
    'OutALCARECOTkAlCosmics0THLT_noDrop',
    'OutALCARECOTkAlCosmics0T_noDrop',
    'OutALCARECOTkAlCosmicsHLT',
    'OutALCARECOTkAlCosmicsHLT_noDrop',
    'OutALCARECOTkAlCosmicsInCollisions',
    'OutALCARECOTkAlCosmicsInCollisions_noDrop',
    'OutALCARECOTkAlCosmics_noDrop',
    'OutALCARECOTkAlJpsiMuMu',
    'OutALCARECOTkAlJpsiMuMu_noDrop',
    'OutALCARECOTkAlLAS',
    'OutALCARECOTkAlLAS_noDrop',
    'OutALCARECOTkAlMinBias',
    'OutALCARECOTkAlMinBiasHI',
    'OutALCARECOTkAlMinBiasHI_noDrop',
    'OutALCARECOTkAlMinBias_noDrop',
    'OutALCARECOTkAlMuonIsolated',
    'OutALCARECOTkAlMuonIsolatedPA',
    'OutALCARECOTkAlMuonIsolatedPA_noDrop',
    'OutALCARECOTkAlMuonIsolated_noDrop',
    'OutALCARECOTkAlUpsilonMuMu',
    'OutALCARECOTkAlUpsilonMuMu_noDrop',
    'OutALCARECOTkAlZMuMu',
    'OutALCARECOTkAlZMuMu_noDrop',
    'PREMIXEventContent',
    'PREMIXRAWEventContent',
    'RAWDEBUGEventContent',
    'RAWDEBUGHLTEventContent',
    'RAWEventContent',
    'RAWRECODEBUGHLTEventContent',
    'RAWRECOEventContent',
    'RAWRECOSIMHLTEventContent',
    'RAWSIMEventContent',
    'RAWSIMHLTEventContent',
    'RAWSIMoutput',
    'RECODEBUGEventContent',
    'RECOEventContent',
    'RECOSIMEventContent',
    'REDIGIEventContent',
    'REGENEventContent',
    'REPACKRAWEventContent',
    'REPACKRAWSIMEventContent',
    'RESIMEventContent',
    'RPCGeometryESModule',
    'RecoBTagAOD',
    'RecoBTagFEVT',
    'RecoBTagRECO',
    'RecoBTauAOD',
    'RecoBTauFEVT',
    'RecoBTauRECO',
    'RecoEcalAOD',
    'RecoEcalFEVT',
    'RecoEcalRECO',
    'RecoEgammaAOD',
    'RecoEgammaFEVT',
    'RecoEgammaRECO',
    'RecoGenJetsAOD',
    'RecoGenJetsFEVT',
    'RecoGenJetsRECO',
    'RecoGenMETAOD',
    'RecoGenMETFEVT',
    'RecoGenMETRECO',
    'RecoHcalNoiseAOD',
    'RecoHcalNoiseFEVT',
    'RecoHcalNoiseRECO',
    'RecoJetsAOD',
    'RecoJetsFEVT',
    'RecoJetsRECO',
    'RecoLocalCaloAOD',
    'RecoLocalCaloFEVT',
    'RecoLocalCaloRECO',
    'RecoLocalMuonAOD',
    'RecoLocalMuonFEVT',
    'RecoLocalMuonRECO',
    'RecoLocalTrackerAOD',
    'RecoLocalTrackerFEVT',
    'RecoLocalTrackerRECO',
    'RecoMETAOD',
    'RecoMETFEVT',
    'RecoMETRECO',
    'RecoMuonAOD',
    'RecoMuonFEVT',
    'RecoMuonIsolationAOD',
    'RecoMuonIsolationFEVT',
    'RecoMuonIsolationParamGlobal',
    'RecoMuonIsolationRECO',
    'RecoMuonRECO',
    'RecoParticleFlowAOD',
    'RecoParticleFlowFEVT',
    'RecoParticleFlowRECO',
    'RecoPixelVertexingFEVT',
    'RecoPixelVertexingRECO',
    'RecoTauTagAOD',
    'RecoTauTagFEVT',
    'RecoTauTagRECO',
    'RecoTrackerAOD',
    'RecoTrackerFEVT',
    'RecoTrackerRECO',
    'RecoVertexAOD',
    'RecoVertexFEVT',
    'RecoVertexRECO',
    'SiStripRecHitMatcherESProducer',
    'SiStripSimBlock',
    'SimCalorimetryAOD',
    'SimCalorimetryFEVTDEBUG',
    'SimCalorimetryRAW',
    'SimCalorimetryRECO',
    'SimG4CoreAOD',
    'SimG4CoreRAW',
    'SimG4CoreRECO',
    'SimGeneralAOD',
    'SimGeneralFEVTDEBUG',
    'SimGeneralRAW',
    'SimGeneralRECO',
    'SimMuonAOD',
    'SimMuonFEVTDEBUG',
    'SimMuonRAW',
    'SimMuonRECO',
    'SimTrackerAOD',
    'SimTrackerDEBUG',
    'SimTrackerFEVTDEBUG',
    'SimTrackerRAW',
    'SimTrackerRECO',
    'StripCPEfromTrackAngleESProducer',
    'TrackerRecoGeometryESProducer',
    'TrackingToolsAOD',
    'TrackingToolsFEVT',
    'TrackingToolsRECO',
    'ZdcHardcodeGeometryEP',
    'apd_sim_parameters',
    'castorDigitizer',
    'configurationMetadata',
    'ecalDigitizer',
    'ecalLocalRecoAOD',
    'ecalLocalRecoFEVT',
    'ecalLocalRecoRECO',
    'ecal_cosmics_sim',
    'ecal_digi_parameters',
    'ecal_electronics_sim',
    'ecal_notCont_sim',
    'ecal_sim_parameter_map',
    'eegeom',
    'endOfProcess',
    'endOfProcess_withComparison',
    'es_electronics_sim',
    'es_hardcode',
    'es_prefer_hcalHardcode',
    'fakeForIdealAlignment',
    'hcalDigitizer',
    'hcalSimBlock',
    'hcalTopologyIdeal',
    'hcal_db_producer',
    'idealForDigiCSCGeometry',
    'idealForDigiDTGeometry',
    'idealForDigiTrackerGeometry',
    'options',
    'pixelDigitizer',
    'psim',
    'randomEngineStateProducer',
    'siPixelQualityESProducer',
    'siStripBackPlaneCorrectionDepESProducer',
    'siStripGainESProducer',
    'siStripGainSimESProducer',
    'siStripLorentzAngleDepESProducer',
    'siStripQualityESProducer',
    'simCastorDigis',
    'simEcalUnsuppressedDigis',
    'simHcalUnsuppressedDigis',
    'simSiPixelDigis',
    'simSiStripDigis',
    'sistripconn',
    'stripDigitizer',
    'theDigitizers',
    'theDigitizersValid',
    'theMixObjects',
    'trackerGeometry',
    'trackerNumberingGeometry',
    'trackerTopologyConstants',
    'trackingParticles'
    ]

for attr in attrs:
    process.__delattr__(attr)
