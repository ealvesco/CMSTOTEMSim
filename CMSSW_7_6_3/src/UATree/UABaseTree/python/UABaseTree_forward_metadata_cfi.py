#   For all possibilities that are not here (like some of the input collections),
#   please look at all parameters retrieved in src/GetParameters.cc
#   All the parameters have anyway a default value !

import FWCore.ParameterSet.Config as cms

# General switches --------------------------------------------------------------------
from UABaseTree_forward_options_metadata import *

# Standard Parameters For UABaseTree Process   ----------------------------------------
from uabasetree_cfi import *

uabasetree.storeL1Trig    = False
uabasetree.storeL1TrigOld = False
#uabasetree.hlt_paths = []

uabasetree.beamspots = cms.untracked.VInputTag()

# Tracking --------------------------------------------------------------
uabasetree.tracks   = cms.untracked.VInputTag()
uabasetree.vertices = cms.untracked.VInputTag()
if doMBTracking:
    #uabasetree.tracks   = cms.untracked.VInputTag("generalTracks","selectTracks")
    uabasetree.tracks   = cms.untracked.VInputTag()
    uabasetree.vertices = cms.untracked.VInputTag()

# DA Vertex -------------------------------------------------------------------------
if doDAvertex:
    uabasetree.vertices.insert(0,'offlinePrimaryVerticesDA')

# Beam Scrapping filter -------------------------------------------------------------
if useMITFilter:
    uabasetree.storeMITEvtSel = cms.untracked.bool(True)

# Jet Collections -------------------------------------------------------------------

# each VPSet of vpfjets or vcalojets needs to contain PSets with:
# jetcoll : not corrected collection. Can specifiy tree branch name in label using seperator # : "label#branchname:instance:process". Example : "ak5PFJets#jets". NOT NECESSARY !
# corrections : name of corrections in vector. Need to provide essource for it in python/UABaseTree_jets_cfi.py . Can specifiy corr name/key stored in Jet.mapjet using seperator # :
#               "corr#mapkey". Example : "ak5PFL1Fastjet#fastjet", but of course "ak5PFL1Fastjet" works too, the mapkey will then be the correction name, here "ak5PFL1Fastjet"
# dijetcoll : if you want to have the Dijet class done for each jetcoll. Need to provide the exact same string as the correction, #mapkey included. Example : "ak5PFL1Fastjet#fastjet"

if storeJets:
    uabasetree.storeTracksInPFJets  = cms.untracked.bool(False)
    uabasetree.vpfjets   = cms.untracked.VPSet(
	    cms.PSet( jetcoll    = cms.untracked.InputTag("ak5PFJets"),
		      corrections = cms.untracked.vstring('ak5PFL2L3','ak5PFL2L3Residual') ),
	    cms.PSet( jetcoll    = cms.untracked.InputTag("ak7PFJets"),
		      corrections = cms.untracked.vstring('ak7PFL2L3','ak7PFL2L3Residual') ),
	    )
    uabasetree.vcalojets = cms.untracked.VPSet(
	    cms.PSet( jetcoll     = cms.untracked.InputTag("ak5CaloJets"),
	              calojetid   = cms.untracked.InputTag("ak5JetID"),
		      corrections = cms.untracked.vstring('ak5CaloL2L3','ak5CaloL2L3Residual') ),
	    cms.PSet( jetcoll     = cms.untracked.InputTag("ak7CaloJets"),
	              calojetid   = cms.untracked.InputTag("ak7JetID"),
		      corrections = cms.untracked.vstring('ak7CaloL2L3','ak7CaloL2L3Residual') ),
	    )
					      
# Basic jets:
#uabasetree.basicjets = cms.untracked.VInputTag("ueSisCone5TracksJet500","ueAk5TracksJet500")
uabasetree.basicjets = cms.untracked.VInputTag()

# Track jets
#uabasetree.trackjets = cms.untracked.VInputTag("ueSisCone5TracksJet500#TrackJetSisCone","ueAk5TracksJet500#TrackJetAntiKt")
uabasetree.trackjets = cms.untracked.VInputTag()
uabasetree.vtxcoll_for_trackjets = cms.untracked.string("offlinePrimaryVertices")

# MET Collections --------------------------------------------------------------------
if storeMET:					     
    uabasetree.mets = cms.untracked.VInputTag()

# CASTOR -----------------------------------------------------------------------------
if storeCastor:
    uabasetree.castorrechits = cms.untracked.InputTag('castorreco')
    uabasetree.basicjets     = cms.untracked.InputTag('ak7BasicJets')
    uabasetree.castorjetid   = cms.untracked.InputTag('ak7CastorJetID')
    #uabasetree.castordigis   = cms.untracked.InputTag('castorDigis')

# PF candidates
if storePFCands:					     
    uabasetree.pfcands = cms.untracked.VInputTag()

# Calo towers
if storeCaloObjects:
    uabasetree.storeCaloObjects = cms.untracked.bool(True)
    uabasetree.calotowercoll = cms.untracked.InputTag("towerMaker")

# Reco muons
if storeMuons:
    uabasetree.muons = cms.untracked.VInputTag()

# Reco electrons
if storeElectrons:
    uabasetree.electrons = cms.untracked.VInputTag()

if storeFSC:
    uabasetree.storeFSCInfo  = cms.untracked.bool(True)
    uabasetree.storeFSCHits  = cms.untracked.bool(True)
    uabasetree.storeFSCDigis = cms.untracked.bool(True)
    uabasetree.fscrechits    = cms.untracked.InputTag('zdcreco')
    uabasetree.fscdigis      = cms.untracked.InputTag('hcalDigis')
