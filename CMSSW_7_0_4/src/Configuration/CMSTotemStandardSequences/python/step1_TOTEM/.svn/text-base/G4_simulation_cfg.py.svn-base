from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

process.g4SimHits.Physics.DefaultCutValue = cms.double(100.0)
process.g4SimHits.Physics.type = cms.string('SimG4Core/Physics/TotemRPPhysicsList')
process.g4SimHits.Physics.BeamProtTransportSetup = cms.PSet(
    Model_IP_150_L_Name = cms.string('ip5_to_beg_150_station_lhcb1'),
    Model_IP_150_R_Zmin = cms.double(0.0),
    Verbosity = cms.bool(False),
    ModelRootFile = cms.string('Geometry/TotemRPOptics/data/parametrization_6500GeV_19p2_transp.root'),
    Model_IP_150_L_Zmax = cms.double(-202.769),
    Model_IP_150_R_Name = cms.string('ip5_to_beg_150_station_lhcb1'),
    Model_IP_150_R_Zmax = cms.double(202.769),
    Model_IP_150_L_Zmin = cms.double(0.0)
)
process.g4SimHits.StackingAction.SaveFirstLevelSecondary = cms.untracked.bool(True)
process.g4SimHits.Totem_RP_SD = cms.PSet(
    Verbosity = cms.int32(0)
)
process.g4SimHits.UseMeasuredGeometryRecord = cms.untracked.bool(True)
process.g4SimHits.OverrideUserStackingAction = cms.bool(True)
process.g4SimHits.Generator.LeaveScatteredProtons = cms.untracked.bool(True)
process.g4SimHits.Generator.ApplyPCuts = cms.bool(False)
process.g4SimHits.Generator.MinEtaCut = cms.double(-5.5)
process.g4SimHits.Generator.ApplyEtaCuts = cms.bool(False)
process.g4SimHits.Generator.LeaveOnlyScatteredProtons = cms.untracked.bool(False)
process.HectorEtaCut = cms.PSet(
    EtaCutForHector = cms.double(8.2)
)
process.common_UseHF = cms.PSet(
    FibreR = cms.untracked.double(0.3),
    CheckSurvive = cms.bool(False),
    Lambda1 = cms.double(280.0),
    Lambda2 = cms.double(700.0),
    Gain = cms.double(0.33)
)
process.common_UseLuminosity = cms.PSet(
    InstLuminosity = cms.double(0.0),
    DelivLuminosity = cms.double(5000.0)
)
process.common_UsePMT = cms.PSet(
    UseR7600UPMT = cms.bool(False)
)
process.common_heavy_suppression = cms.PSet(
    NeutronThreshold = cms.double(30.0),
    ProtonThreshold = cms.double(30.0),
    IonThreshold = cms.double(30.0)
)
process.common_maximum_time = cms.PSet(
    MaxTrackTime = cms.double(500.0),
    MaxTrackTimes = cms.vdouble(2000.0, 0.0, 0.0),
    MaxTimeNames = cms.vstring('ZDCRegion', 
        'QuadRegion', 
        'InterimRegion'
    )
)
