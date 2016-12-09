import FWCore.ParameterSet.Config as cms

T2TrkBasedIntAl = cms.EDAnalyzer("T2TrkBasedInternalAlignment",

         FitdzEnergy = cms.double (10.0),   # choose 10. or 50. GeV
         Chicut= cms.double (3.0),
         DZScale= cms.double (1.0),
         TrkEtamin= cms.double (5.1),  # 4.8 for 10 GeV
         TrkEtaMAX= cms.double (6.9),  # 7.0 for 10 GeV

#	 DetEffRWind =cms.double(10.0),
#	 DetEffPhiWind =cms.double(10.0),
#	 Numhittrkeff =cms.int32(4),	
#        Testedcamera = cms.vuint32(0,1,2,3,4),
                                 
	 chiRredCut=cms.double(5.0),
         chiPhiredCut=cms.double(5.0),
	 AllowedDRTrackDistance=cms.double(1.0),
         
         PhiChiProbCut=cms.double(0.01),
         RChiProbCut=cms.double(0.01),

	 EffMaxPad=cms.uint32(12),
         EffMaxStrip= cms.uint32(12),
 	 Effmaxdphihit=cms.double(3.0),
         Effmaxdrhit=cms.double(3.0),
         NoiseDphiMAX=cms.double(30.0),
         NoiseDrMAX=cms.double(20.0),
	 Effgoodhitnumber=cms.uint32(3),
                                 
	 useRZforResol=cms.uint32(0),  #0 use Fit correlation (Full matrix calculation); 2 use Simple XY YZ fit
	 simufile=cms.bool(False),


                                 
	 MaxPad=cms.uint32(10),
         MaxStrip=cms.uint32(10),
	 MaxEvents=cms.uint32(2400),
	 maxdphihit=cms.double(3.0), 
	 maxdrhit=cms.double(1.0), 
	 NumHitGood=cms.uint32(3), 
	 MaxDphi=cms.double(12.0),
	
                         
         SelectedHalfs=cms.vuint32(0,1,2,3),
         HalfSelectedForPlot=cms.uint32(0),                        

	 FitgravcenterZ=cms.double(0.),
	 UseJointProb=cms.uint32(1),
         UseHitErrorFromResol=cms.bool(True), 
         DR_Resol_mm=cms.double(0.12),
         DPhiResol_Deg=cms.double(0.015),                        
         HalfHalfMaxDispToleranceX=cms.double(0.05),
         HalfHalfMaxDispToleranceY=cms.double(0.05),         
	 DoInternalAlign=cms.bool(True),
         UseMillePede=cms.bool(False),
         UseMillePedeGlobal=cms.bool(False),                 
	 HitNumb4Align=cms.uint32(8),
         MeasuredResol_X=cms.double(0.3),
         MeasuredResol_Y=cms.double(0.3),
         RMaxOverlapXalign=cms.double(100.0),                
         RMaxOverlapYalign=cms.double(100.0),
         RMaxOverlapXalignHisto =cms.double(100.0),
         RMaxOverlapYalignHisto =cms.double(100.0),                        
	 SHIFTprescale=cms.double(1.0),
         Idreferencedet=cms.vuint32(23),
         IdreferencedetHIP=cms.vuint32(0),
         XreferencedetHIP=cms.vdouble(0),
         YreferencedetHIP=cms.vdouble(0),                                 
         IdreferencedetMille=cms.vuint32(0),
         XreferencedetMille=cms.vdouble(0),
         YreferencedetMille=cms.vdouble(0),                        
         MaxStepalignstep=cms.uint32(100),
         AlignmentHitRMax=cms.double(110.0),
         AlignmentHitRMin=cms.double(0.0),
         AllCorrectionAtSameTime=cms.bool(False),
         UseHistogramsForInternalError=cms.bool(False),
         CalculateErrorAsHIP=cms.bool(False),                        
         HitXYResolError=cms.double(0.15),                        
                                 
	 DetForNoiseStudies=cms.uint32(0), 
	 PhiMinForNoiseStudies=cms.double(270), 
	 PhiMaxForNoiseStudies=cms.double(359),

        MillePedeExcludedPlaneH0=cms.vuint32(),
        MillePedeExcludedPlaneH1=cms.vuint32(),
        MillePedeExcludedPlaneH2=cms.vuint32(),
        MillePedeExcludedPlaneH3=cms.vuint32(),

                          
                                 
        ratioXYAlignTrkcut=cms.double(0.0),
        DoAlignHalfHalf=cms.bool(False),
        HalfHalfMaxDispTolerance=cms.double(0.05),
        EffgoodhitnumberOverl=cms.uint32(16),	
        OverlapTrkHitRMax=cms.double(90.),
        HighEtaForOverlapAlign=cms.double(5.0),                        
        RefHalfsWholeQuarterAlign=cms.vuint32(0,2),
                         

        IncludeQuarterTiltAlign=cms.bool(False),
        SelectedHalfsForTiltAlign=cms.vuint32(0),
        AXToll=cms.double(0.003),
        AYToll=cms.double(0.003),
        X0Toll=cms.double(1.),
        Y0Toll=cms.double(1.),
        XYFitUsedinReco=cms.bool(True),
        UseGlobVertexForTiltCalulation=cms.bool(False),                         
                                  
        CluLabel = cms.string('T2MCl'),
        HitLabel = cms.string('T2Hits'),
        RoadLabel = cms.string('T2RoadColl2'),
        TrackLabel = cms.string('T2TrackColl2'),
        OutputFile = cms.untracked.string('valPythia90T2PlotsReco.root'),
        T2PadDigiCollectionLabel = cms.InputTag("T2Digis", "T2PadDigi"),
        T2StripDigiCollectionLabel = cms.InputTag("T2Digis", "T2StripDigi")                         
    )
