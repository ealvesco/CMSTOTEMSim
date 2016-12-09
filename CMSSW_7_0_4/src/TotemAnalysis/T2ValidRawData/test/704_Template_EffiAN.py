import FWCore.ParameterSet.Config as cms







process = cms.Process("valT1T2mu")







########################### COMMON PART ##########################################







process.maxEvents = cms.untracked.PSet(



    input = cms.untracked.int32(-1) # -1 means to take all the events from the source as input



)







process.source = cms.Source("PoolSource",

    fileNames = cms.untracked.vstring('file:/tmp/berretti/run_9510_EVB13_1.030.srs_reco.root')

)





process.load("Configuration.TotemCommon.LoggerMin_cfi")





process.load("Configuration.TotemCommon.RandomNumbers_cfi")



process.load("TotemAnalysis.T2ValidRawData.T2RecoValidation2_cfi")



theanmaxev=99



process.T2ValidRaw.MaxEvents=theanmaxev



process.T2ValidRaw.OutputFile=cms.untracked.string('file:RawANOutput.root')

#process.T2ValidRaw.OutputFile=cms.untracked.string('ANRawOut.root')



process.T2ValidRaw.t2PadDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2PadDigi")

process.T2ValidRaw.t2StripDigiCollectionLabel = cms.InputTag("Raw2DigiProducer", "T2StripDigi")

process.T2ValidRaw.t2DigiVfatCollectionLabel = cms.InputTag("Raw2DigiProducer","T2Digivfat")

process.T2ValidRaw.rawEventLabel = cms.InputTag("source","")

















#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@









process.T2ValidRaw.SelectedHalf= 3







#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@











process.T2ValidRaw.OnlycorruptionAnalysis=cms.bool(False)



process.T2ValidRaw.OnlyClusterAnalysis=cms.bool(False)#False



process.T2ValidRaw.VFATMonitoring=cms.bool(True)#True


if(1 == 1):



  print "Raw data Efficiency"



  process.T2ValidRaw.simufile=cms.bool(False)#era false



  process.T2ValidRaw.LookToRawEvent=cms.bool(False)#True for data



else:



  print "SIMULATION Efficiency"



  process.T2ValidRaw.simufile=cms.bool(True)



  process.T2ValidRaw.LookToRawEvent=cms.bool(False)



  process.T2ValidRaw.UseUncorrupetdEventMap=cms.bool(False)#True for data











#Used for hit error definition



process.T2ValidRaw.UseJointProb=0 







#Used only for alignment histograms



process.T2ValidRaw.HitNumb4Align=6



process.T2ValidRaw.MeasuredXYResol=0.05



process.T2ValidRaw.SHIFTprescale=1.0



process.T2ValidRaw.MaxStepalignstep=400	



process.T2ValidRaw.Idreferencedet=13



process.T2ValidRaw.AlignmentHitRMax=140.0







#Used only for efficiency calculation (reference track cuts)



process.T2ValidRaw.NumHitGood=5     #Default was 5	 



process.T2ValidRaw.useRZforResol=0



process.T2ValidRaw.MaxPad=7



process.T2ValidRaw.MaxStrip=7



process.T2ValidRaw.MaxDphi=7.0	



process.T2ValidRaw.maxdphihit=5.5#2.5



process.T2ValidRaw.maxdrhit=5.5



process.T2ValidRaw.NoiseDphiMAX=30.0



process.T2ValidRaw.NoiseDrMAX=30.0











process.T2ValidRaw.MaxPadAllowedInQuarter=40 #default tested with Visualizer was 40



	  



#Be careful: the following cut define the efficiency and the value Effmaxdphihit Effmaxdrhit depend on your fit choosing



#dr dphi could be taken as dx-dy



process.T2ValidRaw.Effgoodhitnumber=5 #era 5



process.T2ValidRaw.EffMaxPad=7      #era 9



process.T2ValidRaw.EffMaxStrip= 15     #era 9



process.T2ValidRaw.Effmaxdrhit=2.0   #final cut for efficiency calculation (this is really R) PUT 2 DEFAULT







process.T2ValidRaw.Effmaxdphihit=4.0	#final cut for efficiency calculation (this is really Phi)







process.T2ValidRaw.chiRredCut=100.0  



process.T2ValidRaw.chiPhiredCut=100.0



process.T2ValidRaw.AllowedDRTrackDistance=1.0







process.T2ValidRaw.verbosity=cms.bool(True)



process.T2ValidRaw.produceVfatEffiFile=cms.bool(True)



#/afs/cern.ch/exp/totem/scratch/berretti/tmp/testSplitMerge/CMSSW_3_1_1/src



#Include The map of all the vfats



process.T2ValidRaw.xmlfilenameFull=cms.string('TotemRawData/RawToDigi/python/T2GeoMapIP5_4quarter_vmea_Full.xml')



#



#Include The map of vfat considered alive.



process.T2ValidRaw.xmlfilenameUsed_NotDead=cms.string('TotemRawData/RawToDigi/python/T2GeoMapIP5_4quarter_vmea_VFATsAlive_noTMC-14apr10.xml')



#Include The map of Dead Sector if you want to normalize for the deadsector also.



process.T2ValidRaw.DeadSectFileName=cms.string('TotemRawData/RawToDigi/python/3706_DeadSector.txt')











process.T2ValidRaw.MinTrkInQuarter= 1



process.T2ValidRaw.MaxTrkInQuarter= 15







process.T2ValidRaw.TrackLabel=cms.string('T2TrackColl3')















process.T2ValidRaw.skipSelectedEvents=cms.bool(False)



process.T2ValidRaw.skipEventFileName=cms.string('TotemAnalysis/T2ValidRawData/test/CorruptedEv.txt')















process.p1 = cms.Path(process.T2ValidRaw)







#process.outpath = cms.EndPath(process.o1)



