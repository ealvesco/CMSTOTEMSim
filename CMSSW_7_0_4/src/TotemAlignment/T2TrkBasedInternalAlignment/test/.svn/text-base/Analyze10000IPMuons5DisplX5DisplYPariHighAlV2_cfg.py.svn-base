import FWCore.ParameterSet.Config as cms

process = cms.Process("valT1T2mu")

########################### COMMON PART ##########################################

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1) # -1 means to take all the events from the source as input
)

# Configure the input module (read the events from a file -- gunT1T2mu.root)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/media/usbdisk/Simu_and_Reco/3_1_1/SimuMisalign/10000IPMuons5DisplX5DisplYPari.root')
)

# logging to txt files
#process.load("Configuration.TotemCommon.LoggerMax_cfi")
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# random number generators seeds
process.load("Configuration.TotemCommon.RandomNumbers_cfi")




process.load("TotemAlignment.T2TrkBasedInternalAlignment.T2TrkIntAlign_cfi")



process.T2TrkBasedIntAl.OutputFile=cms.untracked.string('10000IPMuons5DisplX5DisplYPariHighAlV2.root')
process.T2TrkBasedIntAl.simufile=cms.bool(True)
process.T2TrkBasedIntAl.DoALign=cms.bool(True)

process.T2TrkBasedIntAl.DetEffRWind =cms.double(20.0)
process.T2TrkBasedIntAl.DetEffPhiWind =10.0
process.T2TrkBasedIntAl.Numhittrkeff =4                # num cl1 hit in other detectors for efficiency calculation 
process.T2TrkBasedIntAl.Testedcamera = cms.vuint32(0,2,4,6,8)

process.T2TrkBasedIntAl.HitNumb4Align=10
process.T2TrkBasedIntAl.MeasuredXYResol=0.05
process.T2TrkBasedIntAl.SHIFTprescale=1.0
process.T2TrkBasedIntAl.MaxStepalignstep=400	
process.T2TrkBasedIntAl.Idreferencedet=13

process.T2TrkBasedIntAl.MaxEvents=10000


process.T2TrkBasedIntAl.MaxPad=5
process.T2TrkBasedIntAl.MaxStrip=9
process.T2TrkBasedIntAl.MaxDphi=7.0	
process.T2TrkBasedIntAl.maxdphihit=2.5
process.T2TrkBasedIntAl.maxdrhit=2.5
process.T2TrkBasedIntAl.NoiseDphiMAX=30.0
process.T2TrkBasedIntAl.NoiseDrMAX=30.0
process.T2TrkBasedIntAl.NumHitGood=7	  
	  

process.T2TrkBasedIntAl.Effgoodhitnumber=7 #era 7
process.T2TrkBasedIntAl.EffMaxPad=4      #era 9
process.T2TrkBasedIntAl.EffMaxStrip= 9     #era 9
process.T2TrkBasedIntAl.Effmaxdphihit=2.5
process.T2TrkBasedIntAl.Effmaxdrhit=2.5
	

process.T2TrkBasedIntAl.chiRredCut=100.0  
process.T2TrkBasedIntAl.chiPhiredCut=100.0
process.T2TrkBasedIntAl.AllowedDRTrackDistance=1.0

process.T2TrkBasedIntAl.UseHitErrorFromResol=cms.bool(True); 
process.T2TrkBasedIntAl.DR_Resol_mm=0.12; 
process.T2TrkBasedIntAl.DPhiResol_Deg=0.015;


# NOTE:
# Remember to add process.generator (based on "pythia") to the path.
#process.p1 = cms.Path(process.generator*process.VtxSmeared*process.g4SimHits*process.mix*process.T2Digis*process.T2MCl*process.T2Hits*process.T2RoadColl*process.T2TrackColl2)
process.p1 = cms.Path(process.T2TrkBasedIntAl)

#process.outpath = cms.EndPath(process.o1)
