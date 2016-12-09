from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

import os
BASE_DIR = os.path.dirname(os.path.realpath('__file__'))

process.__dict__['_Process__name'] = 'step1TOTEM'
process.GlobalTag = GlobalTag(process.GlobalTag, '', '')

# Logging
from Configuration.CMSTotemStandardSequences.step1_TOTEM.logger_cfg import *

# Random numbers generator
from Configuration.CMSTotemStandardSequences.step1_TOTEM.random_numbers_cfg import *

# Optics
process.load('Configuration.TotemOpticsConfiguration.OpticsConfig_6500GeV_19p2_cfi')

# Geometry
from Configuration.CMSTotemStandardSequences.step1_TOTEM.geometry_cfg import *

# Magnetic field
from Configuration.CMSTotemStandardSequences.step1_TOTEM.magnetic_field_cfg import *

# Smearing
process.load('IOMC.SmearingGenerator.SmearingGenerator_cfi')

# G4 simulation and proton transport
from Configuration.CMSTotemStandardSequences.step1_TOTEM.G4_simulation_cfg import *

# Mix
from Configuration.CMSTotemStandardSequences.step1_TOTEM.mix_cfg import *

# Particle table
process.HepPDTESSource.pdtFileName = cms.FileInPath('SimGeneral/HepPDTESSource/data/particle.tbl')

# Removal of additional CMS modules and parameters
from Configuration.CMSTotemStandardSequences.step1_TOTEM.other_cfg import *

# Chain of modules
process.path = cms.Path(
    process.SmearingGenerator
    * process.g4SimHits
)

# Configure the output module (save the result in a file)
process.output = cms.OutputModule('PoolOutputModule',
    outputCommands = cms.untracked.vstring('keep *'),
    fileName = cms.untracked.string(os.path.join(BASE_DIR, 'data/step1_TOTEM.root'))
)

process.outpath = cms.EndPath(process.output)
