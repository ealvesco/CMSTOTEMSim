import FWCore.ParameterSet.Config as cms
import xml.etree.ElementTree as ET, os

# parse xml detector description to get y_offsets
RPDistBeamCentPath = 'Geometry/TotemRPData/data/RP_Beta_90/RP_Dist_Beam_Cent.xml'
RPDistBeamCentDict = {}
for child in ET.parse(os.path.join(os.environ['CMSSW_BASE'], 'src', RPDistBeamCentPath)).getroot()[0]:
    # this assumes that all values are in mm
    RPDistBeamCentDict[child.attrib['name']] = child.attrib['value'].split('*')[0]

# beam x misalignment in mm
beam_x_misalignment_mm = 0.0
beam_y_misalignment_mm = 0.0

# 0 == Left, 1 == Right
RPTimingDetectorsDigiProducer = cms.EDProducer(
    'RPTimingDetectorsDigiProducer',
    detector_020_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_0']),
    detector_021_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Left_Det_Dist_1']),
    detector_120_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_0']),
    detector_121_y_offset_mm=cms.untracked.double(RPDistBeamCentDict['RP_220_Right_Det_Dist_1']),
    beam_x_misalignment_mm=cms.untracked.double(beam_x_misalignment_mm),
    beam_y_misalignment_mm=cms.untracked.double(beam_y_misalignment_mm)
)
