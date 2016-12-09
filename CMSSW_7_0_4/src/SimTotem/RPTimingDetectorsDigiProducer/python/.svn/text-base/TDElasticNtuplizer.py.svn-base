import FWCore.ParameterSet.Config as cms
import xml.etree.ElementTree as ET, os

events_no = 10

fileNamePrefix = 'TDElastic' + str(events_no)

# beam x misalignment in mm
beam_x_misalignment_mm = 0.0
beam_y_misalignment_mm = 0.0

beam_misalignment_info = ""
if beam_x_misalignment_mm != 0 or beam_y_misalignment_mm != 0:
    beam_misalignment_info += "BeamMisalignment"
    if beam_x_misalignment_mm != 0:
        beam_misalignment_info += "X%.2fmm" % beam_x_misalignment_mm
    if beam_y_misalignment_mm != 0:
        beam_misalignment_info += "Y%.2fmm" % beam_y_misalignment_mm

process = cms.Process(fileNamePrefix)

# Specify the maximum events to simulate
process.maxEvents = cms.untracked.PSet(
    input=cms.untracked.int32(events_no)
)

# Configure the output module (save the result in a file)
process.o1 = cms.OutputModule("PoolOutputModule",
                              outputCommands=cms.untracked.vstring('keep *', 'drop *_*mix*_*_*',
                                                                   'drop *_*_*TrackerHits*_*', 'drop *_*_*Muon*_*',
                                                                   'drop *_*_*Ecal*_*', 'drop *_*_*Hcal*_*',
                                                                   'drop *_*_*Calo*_*', 'drop *_*_*Castor*_*',
                                                                   'drop *_*_*FP420SI_*', 'drop *_*_*ZDCHITS_*',
                                                                   'drop *_*_*BSCHits_*', 'drop *_*_*ChamberHits_*',
                                                                   'drop *_*_*FibreHits_*', 'drop *_*_*WedgeHits_*'),
                              fileName=cms.untracked.string('file:' + fileNamePrefix + beam_misalignment_info + '.root')
                              )
process.outpath = cms.EndPath(process.o1)

# Configure if you want to detail or simple log information.
# LoggerMax -- detail log info output including: errors.log, warnings.log, infos.log, debugs.log
# LoggerMin -- simple log info output to the standard output (e.g. screen)
process.load("Configuration.TotemCommon.LoggerMin_cfi")

################## STEP 1 - process.generator
process.source = cms.Source("EmptySource")

# Use random number generator service
process.load("Configuration.TotemCommon.RandomNumbers_cfi")

# Monte Carlo gun - elastic specific
energy = "6500"
import IOMC.Elegent.ElegentSource_cfi

process.generator = IOMC.Elegent.ElegentSource_cfi.generator
process.generator.fileName = IOMC.Elegent.ElegentSource_cfi.ElegentDefaultFileName(energy)

################## STEP 2 process.SmearingGenerator

# declare optics parameters
process.load("Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_90_cfi")

# Smearing
process.load("IOMC.SmearingGenerator.SmearingGenerator_cfi")

################## STEP 3 process.g4SimHits
RPDistBeamCentPath = 'Geometry/TotemRPData/data/RP_Beta_90/RP_Dist_Beam_Cent.xml'

# Geometry - beta* specific
process.load("Configuration.TotemCommon.geometryRP_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append(RPDistBeamCentPath)

# Magnetic Field, by default we have 3.8T
process.load("Configuration.StandardSequences.MagneticField_cff")

# G4 simulation & proton transport
process.load("Configuration.TotemCommon.g4SimHits_cfi")
process.g4SimHits.Physics.BeamProtTransportSetup = process.BeamProtTransportSetup
process.g4SimHits.Generator.HepMCProductLabel = 'generator'  # The input source for G4 module is connected to "process.source".

################## STEP 4 mix pdt_cfi

# process.load("Configuration.TotemStandardSequences/RP_Digi_and_TrackReconstruction_cfi")
process.load("Configuration.TotemCommon/mixNoPU_cfi")

# Use particle table
process.load("SimGeneral.HepPDTESSource.pdt_cfi")

####

process.g4SimHits.G4TrackingManagerVerbosity = cms.untracked.int32(3)

################## STEP 5 RPTimingDetectorsDigiProducer and RP_Dist_Beam_Cent Path

# parse xml detector description to get y_offsets
RPDistBeamCentDict = {}
for child in ET.parse(os.path.join(os.environ['CMSSW_BASE'], 'src', RPDistBeamCentPath)).getroot()[0]:
    # this assumes that all values are in mm
    RPDistBeamCentDict[child.attrib['name']] = child.attrib['value'].split('*')[0]

# 0 == Left, 1 == Right
process.RPTimingDetectorsDigiProducer = cms.EDProducer(
    'RPTimingDetectorsDigiProducer',
    detector_020_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_0']),
    detector_021_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_1']),
    detector_120_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_0']),
    detector_121_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_1']),
    beam_x_misalignment_mm=cms.untracked.double(beam_x_misalignment_mm),
    beam_y_misalignment_mm=cms.untracked.double(beam_y_misalignment_mm)
)


################## STEP 6 Analysis module

process.TFileService = cms.Service(
    "TFileService",
    fileName=cms.string(fileNamePrefix + beam_misalignment_info + 'RPTimingDetectorsAnalysis.root')
)

process.RPTimingDetectorsAnalysis = cms.EDAnalyzer('RPTimingDetectorsAnalysis'
                                                   )

################## STEP 7 Needed for tracks

process.load("Configuration.TotemStandardSequences.RP_Digi_and_TrackReconstruction_cfi")

################## STEP 8 RPTimingDetectorsRecoHitsProducer

# 0 == Left, 1 == Right
process.RPTimingDetectorsRecoHitsProducer = cms.EDProducer(
    'RPTimingDetectorsRecoHitsProducer',
    detector_020_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_0']),
    detector_021_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_1']),
    detector_120_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_0']),
    detector_121_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_1']),
    beam_x_misalignment_mm=cms.untracked.double(beam_x_misalignment_mm),
    beam_y_misalignment_mm=cms.untracked.double(beam_y_misalignment_mm)
)
################## STEP 9 NTuplizer

process.load("TotemAnalysis.TotemNtuplizer.TotemNtuplizer_cfi")
process.TotemNtuplizer.outputFileName = fileNamePrefix + beam_misalignment_info + "Ntuple.root"
process.TotemNtuplizer.EnableTimingDetectors = cms.untracked.bool(True)

###

process.p1 = cms.Path(
    process.generator
    * process.SmearingGenerator
    * process.g4SimHits
    * process.mix
    * process.RPTimingDetectorsDigiProducer
    * process.RPTimingDetectorsAnalysis

    * process.RPSiDetDigitizer
    * process.RPClustProd
    * process.RPHecoHitProd
    * process.RPSinglTrackCandFind
    * process.RPSingleTrackCandCollFit
    * process.RPTimingDetectorsRecoHitsProducer

    * process.TotemNtuplizer)
