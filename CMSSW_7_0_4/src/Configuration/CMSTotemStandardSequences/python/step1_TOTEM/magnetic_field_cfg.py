from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

process.VolumeBasedMagneticFieldESProducer.scalingVolumes = cms.vint32(
    14100, 14200, 17600, 17800, 17900, 
    18100, 18300, 18400, 18600, 23100, 
    23300, 23400, 23600, 23800, 23900, 
    24100, 28600, 28800, 28900, 29100, 
    29300, 29400, 29600, 28609, 28809, 
    28909, 29109, 29309, 29409, 29609, 
    28610, 28810, 28910, 29110, 29310, 
    29410, 29610, 28611, 28811, 28911, 
    29111, 29311, 29411, 29611
)
process.VolumeBasedMagneticFieldESProducer.scalingFactors = cms.vdouble(
    1, 1, 0.994, 1.004, 1.004, 
    1.005, 1.004, 1.004, 0.994, 0.965, 
    0.958, 0.958, 0.953, 0.958, 0.958, 
    0.965, 0.918, 0.924, 0.924, 0.906, 
    0.924, 0.924, 0.918, 0.991, 0.998, 
    0.998, 0.978, 0.998, 0.998, 0.991, 
    0.991, 0.998, 0.998, 0.978, 0.998, 
    0.998, 0.991, 0.991, 0.998, 0.998, 
    0.978, 0.998, 0.998, 0.991
)
process.VolumeBasedMagneticFieldESProducer.version = cms.string('grid_1103l_090322_3_8t')
process.VolumeBasedMagneticFieldESProducer.geometryVersion = cms.int32(90322)
process.VolumeBasedMagneticFieldESProducer.gridFiles = cms.VPSet(
    cms.PSet(
        path = cms.string('grid.[v].bin'),
        master = cms.int32(1),
        volumes = cms.string('1-312'),
        sectors = cms.string('0')
    ), 
    cms.PSet(
        path = cms.string('S3/grid.[v].bin'),
        master = cms.int32(3),
        volumes = cms.string('176-186,231-241,286-296'),
        sectors = cms.string('3')
    ), 
    cms.PSet(
        path = cms.string('S4/grid.[v].bin'),
        master = cms.int32(4),
        volumes = cms.string('176-186,231-241,286-296'),
        sectors = cms.string('4')
    ), 
    cms.PSet(
        path = cms.string('S9/grid.[v].bin'),
        master = cms.int32(9),
        volumes = cms.string('14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296'),
        sectors = cms.string('9')
    ), 
    cms.PSet(
        path = cms.string('S10/grid.[v].bin'),
        master = cms.int32(10),
        volumes = cms.string('14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296'),
        sectors = cms.string('10')
    ), 
    cms.PSet(
        path = cms.string('S11/grid.[v].bin'),
        master = cms.int32(11),
        volumes = cms.string('14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296'),
        sectors = cms.string('11')
    )
)
process.fieldScaling = cms.PSet(
    scalingVolumes = cms.vint32(
        14100, 14200, 17600, 17800, 17900, 
        18100, 18300, 18400, 18600, 23100, 
        23300, 23400, 23600, 23800, 23900, 
        24100, 28600, 28800, 28900, 29100, 
        29300, 29400, 29600, 28609, 28809, 
        28909, 29109, 29309, 29409, 29609, 
        28610, 28810, 28910, 29110, 29310, 
        29410, 29610, 28611, 28811, 28911, 
        29111, 29311, 29411, 29611
    ),
    scalingFactors = cms.vdouble(
        1, 1, 0.994, 1.004, 1.004, 
        1.005, 1.004, 1.004, 0.994, 0.965, 
        0.958, 0.958, 0.953, 0.958, 0.958, 
        0.965, 0.918, 0.924, 0.924, 0.906, 
        0.924, 0.924, 0.918, 0.991, 0.998, 
        0.998, 0.978, 0.998, 0.998, 0.991, 
        0.991, 0.998, 0.998, 0.978, 0.998, 
        0.998, 0.991, 0.991, 0.998, 0.998, 
        0.978, 0.998, 0.998, 0.991
    )
)
process.magfield.geomXMLFiles.remove('MagneticField/GeomBuilder/data/MagneticFieldVolumes_1_v7_large.xml')
process.magfield.geomXMLFiles.remove('MagneticField/GeomBuilder/data/MagneticFieldVolumes_2_v7_large.xml')
process.magfield.geomXMLFiles.append('MagneticField/GeomBuilder/data/MagneticFieldVolumes_1103l.xml')
