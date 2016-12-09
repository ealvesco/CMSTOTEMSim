#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ROOT
import sys
from DataFormats.FWLite import Events, Handle
from PhysicsTools.PythonAnalysis.cmstools import loop

if len(sys.argv) != 2:
    print "Usage: %s filename" % sys.argv[0]
    sys.exit(1)

events = Events (sys.argv[1])


def meanValue( functionPtr, moduleLabel, productInstanceLabel, processLabel, handleLabel):
    runningSum = 0
    n = 0
    handle = Handle(handleLabel)
    events.toBegin()
    for event in events:
        event.getByLabel (moduleLabel, productInstanceLabel, processLabel, handle)
        if not handle.isValid():
            return -1
        runningSum += sum( [functionPtr(prod) for prod in handle.product()] )
        n += len(handle.product())

    if n > 0:
        runningSum /= n
    else:
        runningSum = 0
    return runningSum

# print sum of x,y and z component of all particles momentum
def momentumValue( moduleLabel, productInstanceLabel, processLabel, handleLabel):
    handle = Handle(handleLabel)
    events.toBegin()
    runningSum = 0
    for event in events:
        event.getByLabel (moduleLabel, productInstanceLabel, processLabel, handle)
        if not handle.isValid():
            return -1
        runningSum = handle.product().GetEvent().particles_size() 
        begin = handle.product().GetEvent().particles_begin()
        end = handle.product().GetEvent().particles_end()
        for p in loop(begin,end):
            runningSum += p.momentum().x()+p.momentum().y()+p.momentum().z()
        break 
    return runningSum

def pSimMeanEnergy(name):
    return meanValue( lambda hit : hit.energyLoss(), "g4SimHits" , name, "SIM" , "vector<PSimHit>")

def pCaloMeanEnergy(name):
    return meanValue( lambda hit: hit.energy(), "g4SimHits" , name, "SIM" , "vector<PCaloHit>")

def hepMCTest(name):
    return momentumValue( "generator" , name, "GEN" , "edm::HepMCProduct")

print "Sum of momentum"
print hepMCTest(""),"HepMCProduct"

print "Sum of energy"
pCaloNames = ["CastorFI","EcalHitsEB","EcalHitsEE"]
for name in pCaloNames:
    print pCaloMeanEnergy(name),name

print "Sum of energy loss"
pSimNames = ["TotemHitsT2Gem","TrackerHitsPixelBarrelLowTof"]
for name in pSimNames:
    print pSimMeanEnergy(name),name

# Cuts in TOTEM T1/T2 might affect: CASTOR, Forward Calo, Muon Chambers (MuonCSCHits, MuonRPCHits), Ecal (EcalHitsEE)
# much less chance that in will affect: EcalHitsEB
