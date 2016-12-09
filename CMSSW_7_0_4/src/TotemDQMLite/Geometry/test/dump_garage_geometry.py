import FWCore.ParameterSet.Config as cms
process = cms.Process("DumpGeometry")

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# geometry
process.load("Configuration.TotemCommon.geometryRP_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append('Geometry/TotemRPData/data/RP_Garage/RP_Dist_Beam_Cent.xml')
process.TotemRPGeometryESModule.verbosity = 0

# include alignments, if any
process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
#process.TotemRPIncludeAlignments.RealFiles = cms.vstring('/afs/cern.ch/exp/totem/scratch/data/RP/2010_10_29-30/alignment/version3/tb_all_rot/56_220.xml')

# no events to process
process.source = cms.Source("EmptySource")
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.DumpGeom = cms.EDAnalyzer("DumpRPGeometryModule",
    geometryType = cms.untracked.string("real")
)

process.p = cms.Path(
    process.DumpGeom
)
