# TOTEM only simulation configuration that takes as an input 'data/step0_CMS.root' file.
# This configuration in used to compare output of original TOTEM simulation configuration
# located in TotemStandardSequences directory and modified CMS configuration.

import os
BASE_DIR = os.path.dirname(os.path.realpath('__file__'))

print BASE_DIR

import sys
sys.path.append(os.path.join(BASE_DIR, '../TotemStandardSequences/test/'))

from simRPT1T2 import *

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:' + os.path.join(BASE_DIR, 'data/step0_CMS.root'))
)

process.maxEvents.input = cms.untracked.int32(-1)

process.output.fileName = cms.untracked.string('file:' + os.path.join(BASE_DIR, 'data/orig_TOTEM.root'))

process.TotemNtuplizer.outputFileName = cms.untracked.string('file:' + os.path.join(BASE_DIR, 'data/orig_TOTEM.ntuple.root'))

process.path = cms.Path(
    process.SmearingGenerator
    * process.g4SimHits
    * process.mix

    * process.T1Digis
    * process.t1cluster
    * process.t1rechit
    * process.t1roads
    * process.t1tracks2
    
    * process.T2Digis
    * process.T2MCl
    * process.T2Hits
    * process.T2RoadPadFinder
    * process.T2TrackColl3
    
    * process.RPSiDetDigitizer
    * process.RPClustProd
    * process.RPHecoHitProd 
    * process.RPSinglTrackCandFind
    * process.NonParallelTrackFinder
    * process.RPSingleTrackCandCollFit
    * process.RPMulTrackNonParallelCandCollFit
    
    * process.RPCC
    * process.T2CC
    * process.RP220Reconst
    
    * process.TotemNtuplizer
    )
