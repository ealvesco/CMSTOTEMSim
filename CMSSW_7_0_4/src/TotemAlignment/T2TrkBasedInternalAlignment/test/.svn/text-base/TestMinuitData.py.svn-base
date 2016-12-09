import FWCore.ParameterSet.Config as cms

process = cms.Process("valT1T2mu")

########################### COMMON PART ##########################################

process.maxEvents = cms.untracked.PSet(
    #input = cms.untracked.int32(-1) # -1 means to take all the events from the source as input
    input = cms.untracked.int32(34526) # -1 means to take all the events from the source as input
)

# Configure the input module (read the events from a file -- gunT1T2mu.root)
process.source = cms.Source("PoolSource",
   # fileNames = cms.untracked.vstring('file:/media/usbdisk/Simu_and_Reco/3_1_1/SimuMisalign/Generation50000IPMuonsT2DigisH06x6yDispl_H15x5yDispl_PhiFlat_Bis.root')
  fileNames = cms.untracked.vstring('file:/media/usbdisk1/DataAligned/RecoBeforeHit2_Merged_OptorRX1_4And6clk_IntAl_20Feb.root')                     
)
#Simu_and_Reco/Generate10000MBiasHalf0ShX2mm_confI.root
#Simu_and_Reco/Generate10000MBiasTiltX_SHX_confE.root
#Generate10000MBiasTiltX_confB.root
#/media/usbdisk1/DataAligned/RecoBeforeHit2_Merged_OptorRX1_4And6clk_IntAl_20Feb.root
# logging to txt files
#process.load("Configuration.TotemCommon.LoggerMax_cfi")
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# random number generators seeds
process.load("Configuration.TotemCommon.RandomNumbers_cfi")




process.load("TotemAlignment.T2TrkBasedInternalAlignment.T2TrkIntAlign_cfi")



process.T2TrkBasedIntAl.OutputFile=cms.untracked.string('TestMinuitData.root')
process.T2TrkBasedIntAl.simufile=cms.bool(False)
process.T2TrkBasedIntAl.DoALign=cms.bool(True)
process.T2TrkBasedIntAl.UseMillePede=cms.bool(False)

#Two reference detector per qurter is assumed in the Millepede algorithm
process.T2TrkBasedIntAl.IdreferencedetMille=cms.vuint32(1,9,11,19,21,29,31,39)
process.T2TrkBasedIntAl.XreferencedetMille=cms.vdouble(0.,0.,0.,0.,0.,0.,0.,0.)
process.T2TrkBasedIntAl.YreferencedetMille=cms.vdouble(0.,0.,0.,0.,0.,0.,0.,0.)
#process.T2TrkBasedIntAl.DetEffRWind =cms.double(20.0)
#process.T2TrkBasedIntAl.DetEffPhiWind =10.0
#process.T2TrkBasedIntAl.Numhittrkeff =4                # num cl1 hit in other detectors for efficiency calculation 
#process.T2TrkBasedIntAl.Testedcamera = cms.vuint32(0,2,4,6,8)

process.T2TrkBasedIntAl.HitNumb4Align=10
process.T2TrkBasedIntAl.MeasuredResol_X=0.5 #0.02  #Stop Condition internal alignment
process.T2TrkBasedIntAl.MeasuredResol_Y=0.5
process.T2TrkBasedIntAl.SHIFTprescale=1.0
process.T2TrkBasedIntAl.MaxStepalignstep=50	
process.T2TrkBasedIntAl.Idreferencedet=cms.vuint32(1,11)  #force fixed ref det for alignment
process.T2TrkBasedIntAl.MaxEvents=34526
process.T2TrkBasedIntAl.ratioXYAlignTrkcut=0.3
process.T2TrkBasedIntAl.AlignmentHitRMax=80.0


process.T2TrkBasedIntAl.SelectedHalfs=cms.vuint32(0,1)       #what are the halfs to Internally  align
process.T2TrkBasedIntAl.HalfSelectedForPlot=cms.uint32(0) #what is the half for which you want also the plot
process.T2TrkBasedIntAl.AllCorrectionAtSameTime=cms.bool(True)
process.T2TrkBasedIntAl.UseHistogramsForInternalError=cms.bool(False)
process.T2TrkBasedIntAl.CalculateErrorAsHIP=cms.bool(True)
process.T2TrkBasedIntAl.HitXYResolError=0.15

process.T2TrkBasedIntAl.DoAlignHalfHalf=cms.bool(False)#(True)
process.T2TrkBasedIntAl.RefHalfsWholeQuarterAlign=cms.vuint32(0)  
process.T2TrkBasedIntAl.HalfHalfMaxDispToleranceX=0.042
process.T2TrkBasedIntAl.HalfHalfMaxDispToleranceY=0.01
process.T2TrkBasedIntAl.EffgoodhitnumberOverl=17	
process.T2TrkBasedIntAl.OverlapTrkHitRMax=100.
process.T2TrkBasedIntAl.HighEtaForOverlapAlign=5.0
process.T2TrkBasedIntAl.RMaxOverlapXalign=cms.double(65.0)                
process.T2TrkBasedIntAl.RMaxOverlapYalign=cms.double(100.0)
process.T2TrkBasedIntAl.RMaxOverlapXalignHisto=cms.double(65.0)                
process.T2TrkBasedIntAl.RMaxOverlapYalignHisto=cms.double(100.0)

process.T2TrkBasedIntAl.MaxPad=50
process.T2TrkBasedIntAl.MaxStrip=90
process.T2TrkBasedIntAl.MaxDphi=17.00	
process.T2TrkBasedIntAl.maxdphihit=20.5
process.T2TrkBasedIntAl.maxdrhit=20.5
process.T2TrkBasedIntAl.NoiseDphiMAX=30.0
process.T2TrkBasedIntAl.NoiseDrMAX=30.0
process.T2TrkBasedIntAl.NumHitGood=7	  


process.T2TrkBasedIntAl.Effgoodhitnumber=7 #era 7
process.T2TrkBasedIntAl.EffMaxPad=40      #era 9
process.T2TrkBasedIntAl.EffMaxStrip= 90     #era 9
process.T2TrkBasedIntAl.Effmaxdphihit=30.5
process.T2TrkBasedIntAl.Effmaxdrhit=30.5
	

process.T2TrkBasedIntAl.chiRredCut=100.0  
process.T2TrkBasedIntAl.chiPhiredCut=100.0
process.T2TrkBasedIntAl.AllowedDRTrackDistance=10.0

process.T2TrkBasedIntAl.UseHitErrorFromResol=cms.bool(True)
process.T2TrkBasedIntAl.DR_Resol_mm=0.12
process.T2TrkBasedIntAl.DPhiResol_Deg=0.015



#Parameter for quarter Shift/Tilt alignment respect to the vtx.
process.T2TrkBasedIntAl.IncludeQuarterTiltAlign=cms.bool(True)
process.T2TrkBasedIntAl.SelectedHalfsForTiltAlign=cms.vuint32(0)
process.T2TrkBasedIntAl.AXToll=cms.double(0.003)
process.T2TrkBasedIntAl.AYToll=cms.double(0.003)
process.T2TrkBasedIntAl.X0Toll=cms.double(1.)
process.T2TrkBasedIntAl.Y0Toll=cms.double(1.)
process.T2TrkBasedIntAl.XYFitUsedinReco=cms.bool(True)




# NOTE:
# Remember to add process.generator (based on "pythia") to the path.
#process.p1 = cms.Path(process.generator*process.VtxSmeared*process.g4SimHits*process.mix*process.T2Digis*process.T2MCl*process.T2Hits*process.T2RoadColl*process.T2TrackColl2)
process.p1 = cms.Path(process.T2TrkBasedIntAl)

#process.outpath = cms.EndPath(process.o1)
