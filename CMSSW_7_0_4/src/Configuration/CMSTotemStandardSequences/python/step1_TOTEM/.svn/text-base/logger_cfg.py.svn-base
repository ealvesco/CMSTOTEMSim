from Configuration.CMSTotemStandardSequences.step1_CMS_cfg import *

attrs = [
    'FrameworkJobReport',
    'categories',
    'cerr_stats',
    'cout',
    'debugModules',
    'debugs',
    'default',
    'errors',
    'fwkJobReports',
    'infos',
    'suppressDebug',
    'suppressInfo',
    'suppressWarning',
    'warnings'
    ]

for attr in attrs:
    process.MessageLogger.__delattr__(attr)

process.MessageLogger.statistics = cms.untracked.vstring()
process.MessageLogger.cerr = cms.untracked.PSet(
    threshold = cms.untracked.string('WARNING')
)
process.MessageLogger.destinations = cms.untracked.vstring('cerr')
