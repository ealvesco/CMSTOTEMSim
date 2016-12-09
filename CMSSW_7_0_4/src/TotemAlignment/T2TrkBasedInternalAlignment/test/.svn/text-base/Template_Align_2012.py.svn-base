import FWCore.ParameterSet.Config as cms

process = cms.Process("validIntAlignT2")

########################### COMMON PART ##########################################
#
#Reference planes are found from macro and readme file in:
#/home/mirko/SL/WorkingArea/Analysis/Alignment/Ip5_010/README_ReferencePlaneUsefForAlign
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(35766) # -1 means to take all the events from the source as input
)




 # Configure the input module (read the events from a file -- gunT1T2mu.root)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring("file:/tmp/berretti/run_RECOSIMUStart0run_EVB-wn10_9250.010.vmeb","file:/tmp/berretti/run_RECOSIMUStart0run_EVB-wn10_9250.009.vmeb","file:/tmp/berretti/run_RECOSIMUStart0run_EVB-wn10_9250.011.vmeb","file:/tmp/berretti/run_RECOSIMUStart0run_EVB-wn10_9250.012.vmeb","file:/tmp/berretti/run_RECOSIMUStart0run_EVB-wn10_9250.019.vmeb"), 
    noEventSort = cms.untracked.bool(True),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')                         
)



#/media/usbdisk1/DataAligned
# logging to txt files
#process.load("Configuration.TotemCommon.LoggerMax_cfi")
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# random number generators seeds
process.load("Configuration.TotemCommon.RandomNumbers_cfi")


process.load("TotemAlignment.T2TrkBasedInternalAlignment.T2TrkIntAlign_cfi")


process.T2TrkBasedIntAl.MaxEvents=35000#NumEventWhenAlignIsCalculated

process.T2TrkBasedIntAl.OutputFile=cms.untracked.string('ExampleAl2015.root')
process.T2TrkBasedIntAl.simufile=cms.bool(False)#2012Comm:was False
process.T2TrkBasedIntAl.DoALign=cms.bool(True)
process.T2TrkBasedIntAl.UseMillePede=cms.bool(True)

#Two reference detector per quarter is assumed in the Millepede algorithm
#process.T2TrkBasedIntAl.Idreferencedet=cms.vuint32(51,512,523,531)
process.T2TrkBasedIntAl.Idreferencedet=cms.vuint32(51,512,523,531) # NOT USED


#QuarterToAnalyze=(0,1,3)(QuarterToAnalyze)
process.T2TrkBasedIntAl.SelectedHalfs=cms.vuint32(0,1,3)       #what are the halfs to Internally  align was (0,1,2,3)

process.T2TrkBasedIntAl.IdreferencedetMille=cms.vuint32(2,8,                  11,17,                       23,28,        31,39)
process.T2TrkBasedIntAl.XreferencedetMille=cms.vdouble(0.194631,0.0934048,    -0.0159239,0.0596779,        0.,0.,       -0.0408054,0.0257427)
process.T2TrkBasedIntAl.YreferencedetMille=cms.vdouble(-0.0999972,-0.039286,   0.242704,-0.0558685,        0.,0.,       -0.13773,0.022136)
#process.T2TrkBasedIntAl.XreferencedetMille=cms.vdouble(0.205876,0.07,  -0.04,0.075,    0.,0.095,     0.22,0.16)

process.T2TrkBasedIntAl.HalfSelectedForPlot=cms.uint32(3)  #what is the half for which you want also the plot
process.T2TrkBasedIntAl.MillePedeExcludedPlaneH0=cms.vuint32(0,1)       #wh
process.T2TrkBasedIntAl.MillePedeExcludedPlaneH1=cms.vuint32()       #wh
process.T2TrkBasedIntAl.MillePedeExcludedPlaneH2=cms.vuint32()
process.T2TrkBasedIntAl.MillePedeExcludedPlaneH3=cms.vuint32(5)



#process.T2TrkBasedIntAl.IdreferencedetHIP=cms.vuint32(0,6,12,18,23,28,32,37)
#process.T2TrkBasedIntAl.XreferencedetHIP=cms.vdouble(-0.0998,0.102, 0.050,-0.045, -0.0823,0.04, -0.1689,-0.0061)
#process.T2TrkBasedIntAl.YreferencedetHIP=cms.vdouble(-0.0005,-0.214,-0.095,0.066,-0.037,0.058,-0.0949,-0.2865)


process.T2TrkBasedIntAl.FitgravcenterZ=cms.double(0.)
process.T2TrkBasedIntAl.MeasuredResol_X=0.02          #Stop Condition internal alignment
process.T2TrkBasedIntAl.MeasuredResol_Y=0.02
process.T2TrkBasedIntAl.SHIFTprescale=1.0
process.T2TrkBasedIntAl.MaxStepalignstep=30#2012Comm:was50


process.T2TrkBasedIntAl.AllCorrectionAtSameTime=cms.bool(True)
process.T2TrkBasedIntAl.UseHistogramsForInternalError=cms.bool(False)
process.T2TrkBasedIntAl.HitXYResolError=0.3


#First cut criteria on track hits *$*
process.T2TrkBasedIntAl.MaxPad=4   #was 8
process.T2TrkBasedIntAl.MaxStrip=4 #was 8
process.T2TrkBasedIntAl.MaxDphi=4.0#was 3.0

#0 use Fit correlation (Full matrix calculation); 2 use Simple XY YZ fit
process.T2TrkBasedIntAl.useRZforResol=cms.uint32(0)#was 0

#*** IMPORTANT****
#Notice: The 2 parmaeter maxdrhit below are quite critical for the internal alignment, especially for the comparison with millepede.
# Max DX residuals accepted between hitX and expecteted trk position (trk in xz plane) *$*
process.T2TrkBasedIntAl.maxdrhit=2.5#=MaxdxdyValCut   #bef 2.5
# Max DY residuals accepted between hitY and expecteted trk position (trk in yz plane) *$*
process.T2TrkBasedIntAl.maxdphihit=2.5#=MaxdxdyValCut #bef 2.5

#Look if you have at least NumHitGood cl1 hit in trk having the properties *$*
process.T2TrkBasedIntAl.NumHitGood=8
#8 work for h0 h1

#second refinement for trk in matrix
process.T2TrkBasedIntAl.Effgoodhitnumber=8#8 work for h0 h1 #track in matrix numhit requirement (tracks has already passed *$*) -era 7

process.T2TrkBasedIntAl.AlignmentHitRMax=80.       # MAX R Value requested for Hit-0 in order to use trk for alignment. 100.0
process.T2TrkBasedIntAl.AlignmentHitRMin=40.       # MAX R Value requested for Hit-0 in order to use trk for alignment. 100.0


                                                      # *$* cuts already passed
process.T2TrkBasedIntAl.HitNumb4Align=cms.uint32(8) #8work hor h0 h1   # Number of required hit for each trk used for alignment *$*
                                                     # *$* cuts already passed
process.T2TrkBasedIntAl.ratioXYAlignTrkcut=ratioXovYAlignTrkcut=0.3       # applied after all above cut in order to improve resolution in X or Y fit usually 0.3


process.T2TrkBasedIntAl.UseHitErrorFromResol=cms.bool(False)
process.T2TrkBasedIntAl.DR_Resol_mm=0.15    #bef 0.12
process.T2TrkBasedIntAl.DPhiResol_Deg=0.018  #bef 0.015
process.T2TrkBasedIntAl.CalculateErrorAsHIP=cms.bool(True)

#Parameter for Half-Half relative alignment 
process.T2TrkBasedIntAl.DoAlignHalfHalf=cms.bool(False)
process.T2TrkBasedIntAl.RefHalfsWholeQuarterAlign=cms.vuint32(0)  
process.T2TrkBasedIntAl.HalfHalfMaxDispToleranceX=0.04
process.T2TrkBasedIntAl.HalfHalfMaxDispToleranceY=0.01
process.T2TrkBasedIntAl.EffgoodhitnumberOverl=17	
process.T2TrkBasedIntAl.OverlapTrkHitRMax=100.
process.T2TrkBasedIntAl.HighEtaForOverlapAlign=5.0
process.T2TrkBasedIntAl.RMaxOverlapXalign=cms.double(47.0)                
process.T2TrkBasedIntAl.RMaxOverlapYalign=cms.double(80.0)


#Parameter for quarter Shift/Tilt alignment respect to the vtx.
process.T2TrkBasedIntAl.IncludeQuarterTiltAlign=cms.bool(False)
process.T2TrkBasedIntAl.SelectedHalfsForTiltAlign=cms.vuint32(0)
process.T2TrkBasedIntAl.AXToll=cms.double(0.003)
process.T2TrkBasedIntAl.AYToll=cms.double(0.003)
process.T2TrkBasedIntAl.X0Toll=cms.double(1.)
process.T2TrkBasedIntAl.Y0Toll=cms.double(1.)
process.T2TrkBasedIntAl.XYFitUsedinReco=cms.bool(True)



#Parameters below Not used anymore
process.T2TrkBasedIntAl.chiRredCut=100.0  
process.T2TrkBasedIntAl.chiPhiredCut=100.0
process.T2TrkBasedIntAl.AllowedDRTrackDistance=1.0
process.T2TrkBasedIntAl.EffMaxPad=7      #era 9
process.T2TrkBasedIntAl.EffMaxStrip= 9     #era 9
process.T2TrkBasedIntAl.Effmaxdphihit=3.5
process.T2TrkBasedIntAl.Effmaxdrhit=3.5

process.T2TrkBasedIntAl.TrackLabel = cms.string('T2TrackColl3')

process.p1 = cms.Path(process.T2TrkBasedIntAl)
