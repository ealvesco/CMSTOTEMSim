/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*     
*   Mirko Berretti (mirko.berretti@gmail.com) 
*   The code have been developed for T2 purposes stared from the RP code
*   Jan Kašpar (jan.kaspar@gmail.com) Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "TotemDQMLite/Modules/interface/TotemDQMModuleT2.h"

#include "TotemDQMLite/Core/interface/PlotManager.h"

#include "DataFormats/T2Cluster/interface/T2ROGeometry.h"
#include "Geometry/TotemGeometry/interface/T2GeometryUtil.h"
#include "DataFormats/T2DigiVfat/interface/T2DigiVfatCollection.h"
#include "DataFormats/T2Digi/interface/T2PadDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2PadDigi.h"
#include "DataFormats/T2Digi/interface/T2StripDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2StripDigi.h"
#include "DataFormats/T2Cluster/interface/T2StripClusterCollection.h"
#include "DataFormats/T2Cluster/interface/T2PadClusterCollection.h"
#include "DataFormats/T2Hit/interface/T2HitCollection.h"
#include "DataFormats/T2Road/interface/T2RoadCollection.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"

#include "DataFormats/Common/interface/Handle.h"

#include "TH1D.h"
#include "TH2F.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TProfile.h"

using namespace edm;


//planes from 0 to 19 in the same arm
void TotemDQMModuleT2::OneArmPlots::Add(std::set<unsigned int> planes, int limit/*, bool BuildCorrelationPlots*/) {
  int correlationPlotsCounter = 0;
  bool limited;
  if (limit == -1)
    limited = false;
  else
    limited = true;

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinformation1,planeinformation2;

  
  //-------------------------------------------------------------------------------------------
  // Correlation Plots ------------------------------------------------------------------------
  //if(BuildCorrelationPlots==true)
    for (std::set<unsigned int>::iterator i = planes.begin(); i != planes.end(); i++)
    for (std::set<unsigned int>::iterator j = i; j != planes.end(); j++) {
      if (hist[*i][*j] == 0 && hist[*j][*i] == 0 && *i != *j && i != j) {

        unsigned int plane1_019 = *i;//std::min(*i, *j);
	unsigned int plane2_019 =*j; //std::max(*i, *j);

	if(plane2_019>plane1_019)
	  {

	    //   std::cout<<"Looking at "<<plane1_019<<" "<<plane2_019<<" correlation initialization"<<std::endl;
	    //if(correlationPlotsSelectorT2->IfCorrelate(plane1_019, plane2_019,id) && (!limited || correlationPlotsCounter < limit))
	      // std::cout<<"Plane "<<plane1_019<<" Plane "<<plane2_019<<" in arm "<<id<<" are correlated"<<std::endl;
	    //else
	    //std::cout<<"Plane "<<plane1_019<<" Plane "<<plane2_019<<" in arm "<<id<<" are NOT correlated"<<std::endl;
	
	    if (correlationPlotsSelectorT2->IfCorrelate(plane1_019, plane2_019,id) && (!limited || correlationPlotsCounter < limit)) {
	  
	      char buf1[200];
	      char buf2[200];

	      // Get standard Id	    
	      unsigned int Ht1 = plane1_019/10; 
	      unsigned int Ht2 = plane2_019/10; 
	      unsigned int pl1_0_39=plane1_019+id*20;
	      unsigned int pl2_0_39=plane2_019+id*20;
	      planeinformation1=conv.GetT2Info(pl1_0_39);
	      planeinformation2=conv.GetT2Info(pl2_0_39);	      
	      std::string ArmName=PathHistoName(planeinformation1.arm);
	      
	      //-----------------------------------------------------
	      // String for the plots TITLE
	      std::string T2Plane1 = "";
	      std::string T2Plane2 = "";

	      if(Ht1==0)
		T2Plane1=T2Plane1+"_HT0_Pl";
	      if(Ht1==1)
		T2Plane1=T2Plane1+"_HT1_Pl";
	    
	      if(Ht2==0)
		T2Plane2=T2Plane2+"_HT0_Pl";
	      if(Ht2==1)
		T2Plane2=T2Plane2+"_HT1_Pl";

	      sprintf(buf1, "%d", planeinformation1.pl_0to9);
	      sprintf(buf2, "%d", planeinformation2.pl_0to9);
	             
	      T2Plane1 += buf1;	  	    
	      T2Plane2 += buf2;

	      //Arm=1 Means Negative
	     
	      std::string arm="";
	      if(id==0)
		{
		  
		  arm="Arm[+] ";
		}
	      if(id==1)
		{
		  arm="Arm[-] ";
		}
	      //
	      //--------------------------------------------------------

	      Int_t bins[2] = {512, 512};
	      Double_t xmin[2] = {-0.5, -0.5};
	      Double_t xmax[2] = {511.5, 511.5};
	    	    

	      // hist[plane1_019][plane2_019] = hist[plane2_019][plane1_019] = new THnSparseD("", "title", 2, bins, xmin, xmax);
          
	      // PlotManager::Register(ArmName,"Correlation profile  " +  T2Plane1_019 + " vs " + T2Plane2/* , ArmName+ " : correlation profile " + T2Plane1 + " vs " + T2Plane2 + ";Strip Numb. in " + T2Plane1 + ";Strip Numb. in " + T2Plane2*/ , hist[plane1_019][plane2_019]);

	      PlotManager::Register(ArmName+"Correlation profile "+arm+T2Plane1+" vs "+T2Plane2,"Correlation profile "+T2Plane1+" vs "+T2Plane2+";Strip Numb. in "+T2Plane1+";Strip Numb. in "+T2Plane2, hist[plane1_019+(id*20)][plane2_019+(id*20)]= new THnSparseD("", "title", 2, bins, xmin, xmax));

	      //Important to use [plane1_019+(id*20)][plane2_019+(id*20)] otherwise you'll have the same pairs for both arms
	      
	      //std::cout<<"Registering: "<<ArmName+"Correlation profile "+arm+T2Plane1+" vs "+T2Plane2<<std::endl;
	      
	      
	      correlationPlotsCounter++;
	    }

	  }

      }
    }
  
  if (limited && correlationPlotsCounter >= limit) 
    {printf("!!! Number of Correlation Plots has been limited to: %d\n", limit);}
}



TotemDQMModuleT2::OneArmPlotsGlobal::OneArmPlotsGlobal() : XHitsSel(NULL), YHitsSel(NULL)/*, XHitsSelFirst(NULL), YHitsSelFirst(NULL)*/,
							   XTrack(NULL),YTrack(NULL), mROX(NULL), mROY(NULL)
{
}

TotemDQMModuleT2::OneArmPlotsGlobal::OneArmPlotsGlobal(unsigned int j)
{
  id=j;
  //-------------------------------------------------------------------------------------------
  // NON-Correlation Plots --------------------------------------------------------------------
  std::string TheArm=PathHistoName(id);
  XHitsSel = new TGraphErrors(); XHitsSel->SetMarkerColor(2); XHitsSel->SetMarkerStyle(2); XHitsSel->SetMarkerSize(1.);
  YHitsSel = new TGraphErrors(); YHitsSel->SetMarkerColor(2); YHitsSel->SetMarkerStyle(2); YHitsSel->SetMarkerSize(1.);
  XTrack = new TF1("XTrack", "[0]*x+[1]", 0, 1); XTrack->SetLineColor(4);
  YTrack = new TF1("YTrack", "[0]*x+[1]", 0, 1); YTrack->SetLineColor(4);

  //char z0_str[30];
  //sprintf(z0_str, "%.0f", z0);
  mROY = new MultiRootPlot();
  mROX = new MultiRootPlot();
  mROX->Add(XHitsSel, "AP");
  mROX->Add(XTrack, "SAME");

  mROY->Add(YHitsSel, "AP");
  mROY->Add(YTrack, "SAME");
  PlotManager::Register(TheArm+ "Actual track - Y projection",  "Actual track - Y projection;z (mm);Y (mm)",  mROY);
  PlotManager::Register(TheArm+ "Actual track - X projection",  "Actual track - X projection;z (mm);X (mm)",  mROX);

   /*
  mRO = new MultiRootPlot();
  mRO->Add(YHitsSel, "AP");
  mRO->Add(YTrack, "SAME");




  // PlotManager::Register(TheArm+ "Actual track - Y projection",  "Actual track - Y projection;z (mm);Y (mm)",  mRO);
 
  
  mRO = new MultiRootPlot();
  mRO->Add(XHitsSel, "AP");
  mRO->Add(XTrack, "SAME");
  //PlotManager::Register(TheArm+ "Actual track - X projection",  "Actual track - X projection;z (mm);X (mm)",  mRO);
  PlotManager::Register(TheArm+ "Actual track - X projection",  "Actual track - X projection;z (mm);X (mm)",  mROX);
  



  XHitsSelFirst = new TGraphErrors(); XHitsSelFirst->SetMarkerColor(2); XHitsSelFirst->SetMarkerStyle(2); XHitsSelFirst->SetMarkerSize(1.);
  YHitsSelFirst = new TGraphErrors(); YHitsSelFirst->SetMarkerColor(2); YHitsSelFirst->SetMarkerStyle(2); YHitsSelFirst->SetMarkerSize(1.);
  XTrackFirst = new TF1("XTrackFirst", "[0]*x+[1]", 0, 1); XTrackFirst->SetLineColor(4);
  YTrackFirst = new TF1("YTrackFirst", "[0]*x+[1]", 0, 1); YTrackFirst->SetLineColor(4);
  
  MultiRootPlot *mROFirst = new MultiRootPlot();
  mROFirst->Add(YHitsSelFirst, "AP");
  mROFirst->Add(YTrackFirst, "SAME");


  PlotManager::Register(TheArm+ "First Reco track - Y projection",  "First track - Y projection;z (mm);Y (mm)",  mROFirst);

  mROFirst = new MultiRootPlot();
  mROFirst->Add(XHitsSelFirst, "AP");
  mROFirst->Add(XTrackFirst, "SAME");
  PlotManager::Register(TheArm+ "First Reco track - X projection", "First track - X projection;z (mm);X (mm)",  mROFirst);
  */
  
}





//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
TotemDQMModuleT2::FullDetectorPlots::FullDetectorPlots()
{


}



TotemDQMModuleT2::FullDetectorPlots::FullDetectorPlots(unsigned int id)
{

  //char OnlyHtNumberch[10];
  //sprintf(OnlyHtNumberch, "%d", id);
  PlotManager::Register("DAQ/T2_ Current TriggerandTracks","   Track vs Trigger (one-event);Half Quarter Tracks;Trigger Flag", TriggerandTracks = new TH2F("", "title", 12, -0.5, 11.5, 12,-0.5,11.5));

  PlotManager::Register("DAQ/T2_ All TriggerandTracksG","   Track vs Trigger (cumulative);Half Quarter Tracks;Trigger Flag", TriggerandTracksG = new TH2F("", "title", 12, -0.5, 11.5, 12,-0.5,11.5));

  PlotManager::Register("DAQ/T2_ Current TriggerandTracks in BX","   Track vs Trigger (one-event) in BX;Half Quarter Tracks;Trigger Flag", OnBX_TriggerandTracks = new TH2F("", "title", 12, -0.5, 11.5, 12,-0.5,11.5));

  PlotManager::Register("DAQ/T2_ All TriggerandTracksG  in BX","   Track vs Trigger (cumulative)  in BX;Half Quarter Tracks;Trigger Flag", OnBX_TriggerandTracksG = new TH2F("", "title", 12, -0.5, 11.5, 12,-0.5,11.5));

  PlotManager::Register("DAQ/T2_ All Tracks Phi-R","  All Tracks Phi-R (cumulative);#Phi;R; ", ALLTRKS_RPHIG  = new TH2F("", "title", 120, -0.5, 359.5,55, 40.,150.));


}

TotemDQMModuleT2::HalfTelescopePlots::HalfTelescopePlots() : currentTrackInHT(NULL), allTracksInHT(NULL), CorrelPad24(NULL)// HitsAll(NULL), HitsSel(NULL), Track(NULL)
{
}

TotemDQMModuleT2::HalfTelescopePlots::HalfTelescopePlots(unsigned int ht0_3)
{

  unsigned int arm=ht0_3/2;
  unsigned int ht=ht0_3%2;
  char OnlyHtNumberch[10];
  sprintf(OnlyHtNumberch, "%d", ht);
  std::string OnlyHtNumber="";
  OnlyHtNumber+=OnlyHtNumberch;
  std::string HalfName =PathHistoName(arm,ht);


  PlotManager::Register(HalfName + "Current Tracks Eta-Phi", OnlyHtNumber + " : Track #eta #phi (one-event);#eta;#phi", currentTrackInHT = new TH2F("", "title", 360, -0.5, 359.5,21,-10.5,10.5));

  PlotManager::Register(HalfName + "All Tracks Eta-Phi", OnlyHtNumber + " : Track #eta #phi (cumulative);#eta;#phi", allTracksInHT = new TH2F("", "title", 360, -0.5, 359.5,21,-10.5,10.5));

  PlotManager::Register(HalfName + "Pad-Pad correlation plane 2-4", OnlyHtNumber + " : Pad_C ;Pad_ind;Pad_ind", CorrelPad24 = new TH2F("", "title", 1560, -0.5, 1559.5,1560,-0.5,1559.5));
  

  PlotManager::Register(HalfName + "Track Multiplicity(cumulative)", OnlyHtNumber + " : Track Multiplicity (cumulative) ;Number of tracks", allTracksInHT1D = new TH1D("", "title", 360, -0.5, 359.5));
  
  PlotManager::Register(HalfName + "Track Multiplicity(one-event)", OnlyHtNumber + " : Track Multiplicity (one-event) ;Number of tracks", currentTrackInHT1D = new TH1D("", "title", 360, -0.5, 359.5));

  PlotManager::Register(HalfName + "All Tracks R-Phi", OnlyHtNumber + " : Track r-Phi (cumulative) ;R;#phi", TrkRPhiG = new TH2F("", "title", 120, -0.5, 359.5,55, 40.,150.));
  PlotManager::Register(HalfName + "Current Tracks R-Phi", OnlyHtNumber + " : Track r-Phi (one-event) ;R;#phi", TrkRPhi = new TH2F("", "title", 120, -0.5, 359.5,55,40.,150.));
  
  PlotManager::Register(HalfName + "StripCluMultPerPlaneG", OnlyHtNumber + " : Strip-Clu Avg Mult (cumulative) ;Plane", StripCluMultPerPlaneG = new TProfile("", "title", 10, -0.5, 9.5));
  PlotManager::Register(HalfName + "PadCluMultPerPlaneG", OnlyHtNumber + " : Pad-Clu Avg Mult (cumulative) ;Plane", PadCluMultPerPlaneG = new TProfile("", "title", 10, -0.5, 9.5));
  
  PlotManager::Register(HalfName + "StripCluMultPerPlane", OnlyHtNumber + " : Strip-Clu Avg Mult (one-event) ;Plane", StripCluMultPerPlane = new TProfile("", "title", 10, -0.5, 9.5));
  PlotManager::Register(HalfName + "PadCluMultPerPlane", OnlyHtNumber + " : Pad-Clu Avg Mult (one-event) ;Plane", PadCluMultPerPlane = new TProfile("", "title", 10, -0.5, 9.5));


  PlotManager::Register(HalfName + "VfatMultiplicityMap", OnlyHtNumber + " : Vfat Multiplicity Map (one-event) ;PLANE;ID", VfatMultiplicityMap = new TProfile2D("", "title", 10, -0.5, 9.5, 17, -0.5, 16.5));
  PlotManager::Register(HalfName + "VfatMultiplicityMapG", OnlyHtNumber + " : Vfat Multiplicity Map (cumulative) ;PLANE;ID", VfatMultiplicityMapG = new TProfile2D("", "title", 10, -0.5, 9.5, 17, -0.5, 16.5));

}

//----------------------------------------------------------------------------------------------------

TotemDQMModuleT2::PlanePlots::PlanePlots(unsigned int pl0_39)
{


  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinformation;
  std::string PlName;
  planeinformation=conv.GetT2Info(pl0_39);
  PlName=PathHistoName(planeinformation.arm,planeinformation.ht,planeinformation.pl_0to9);  
  char OnlyPlaneNumberch[200];
  sprintf(OnlyPlaneNumberch, "%d", planeinformation.pl_0to9);
  std::string OnlyPlaneNumber="";
  OnlyPlaneNumber+=OnlyPlaneNumberch;

  
  PlotManager::Register(PlName + "Pad Digi profile cumulative", OnlyPlaneNumber + " : digi profile (cumulative);pad number", Pad_digi_profile_cumulative = new TH1D("", "title", 512, -0.5, 511.5));

  PlotManager::Register(PlName + "Pad Digi profile one-event", OnlyPlaneNumber + " : digi profile (one-event);pad number", Pad_digi_profile_one_event = new TH1D("", "title", 512, -0.5, 511.5));

  // PlotManager::Register(PlName + "Cluster profile cumulative", OnlyPlaneNumber + " : cluster profile (cumulative);cluster R-center", cluster_profile_cumulative = new TH1D("", "title", 1000, 40, 140));

  //PlotManager::Register(PlName + "Cluster profile one-event", OnlyPlaneNumber + " : cluster profile (one-event);cluster R-center", cluster_profile_one_event = new TH1D("", "title", 1000, 40, 140));

  PlotManager::Register(PlName + "Hit R Profile one-event", OnlyPlaneNumber + " : ;hit R (mm)", hit_R_one_event = new TH1D("", "title", 150, -0.5, 149.5));

  PlotManager::Register(PlName + "Hit Phi Profile one-event", OnlyPlaneNumber + " : ;hit Phi (deg)", hit_Phi_one_event = new TH1D("", "title", 360, -0.5, 359.5));


  PlotManager::Register(PlName + "Strip Cluster size one-event", OnlyPlaneNumber + " : strip cluster size (one-event)", Strip_ClusterSize_one_event = new TH1D("", "title", 21, 0.5, 20.5));

  PlotManager::Register(PlName + "Pad Cluster size one-event", OnlyPlaneNumber + " : pad cluster size (one-event)", Pad_ClusterSize_one_event = new TH1D("", "title", 21, 0.5, 20.5));


  PlotManager::Register(PlName + "Strip Cluster size cumulative", OnlyPlaneNumber + " : strip cluster size (cumulative)", Strip_ClusterSize_cumulative = new TH1D("", "title", 21, 0.5, 20.5));

  PlotManager::Register(PlName + "Pad Cluster size cumulative", OnlyPlaneNumber + " : pad cluster size (cumulative)", Pad_ClusterSize_cumulative = new TH1D("", "title", 21, 0.5, 20.5));


}
//----------------------------------------------------------------------------------------------------



TotemDQMModuleT2::VFatPlots::VFatPlots() : ActiveChOneEvt(NULL), ActiveChCumulative(NULL)
{}

TotemDQMModuleT2::VFatPlots::VFatPlots(unsigned int plane,unsigned int vfatid)
{
  //plane is supposed to be from 0 to 39!!
  //std::cout<<"Here with arm aft"<<planeinformation.arm<<std::endl;
  //std::cout<<"Here with arm bef with plane "<< plane<<std::endl;
  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinformation;
  std::string vfatstr;
 
  if(vfatid<=16) //Is a data VFAT
    {
      planeinformation=conv.GetT2Info(plane);
      vfatstr=PathHistoName(planeinformation.arm,planeinformation.ht,planeinformation.pl_0to9,vfatid);  
    }
  if(vfatid==18) //Is a trigger VFAT - should stay under the Half-Tele window
    {
      planeinformation=conv.GetT2Info(plane);
      vfatstr=PathHistoName(planeinformation.arm,planeinformation.ht); 
      vfatstr=vfatstr+ "Trigger VFAT 0";
    }
  if(vfatid==19) //Is a trigger VFAT - should stay under the Half-Tele window
    {
      planeinformation=conv.GetT2Info(plane);
      vfatstr=PathHistoName(planeinformation.arm,planeinformation.ht); 
      vfatstr=vfatstr+ "Trigger VFAT 1";
    }


    PlotManager::Register(vfatstr + "ACTIVE CHANNELS - One Event"," Channel Activated;Channel number", ActiveChOneEvt = new TH1D("", "title", 129, -0.5, 128.5));
    
    PlotManager::Register(vfatstr + "ACTIVE CHANNELS - Cumulative"," Channel Activated;Channel number", ActiveChCumulative  = new TH1D("", "title", 129, -0.5, 128.5));

 

}

unsigned int TotemDQMModuleT2::VFatPlots::uniqueVfatID(unsigned int pl_039,unsigned int Idv)
{
  unsigned int thefid = 0;

  //Id for  data VFAT
  if(Idv<=16)               
    thefid=pl_039*100+Idv;
  
  //Id for trigger VFAT
  //Note: here plane *could* mean halfTelescope if there exist one plane trigger vfat per Half!
  
  if((Idv==18)&&(pl_039==0))   //pl0= arm 0 ht 0
    thefid=18;
  if((Idv==19)&&(pl_039==0))   
    thefid=19;

  if((Idv==18)&&(pl_039==1))   //pl1= arm 1 ht 0
    thefid=28;
  if((Idv==19)&&(pl_039==1))   
    thefid=29;


  if((Idv==18)&&(pl_039==2))   //pl2= arm 1 ht 0
    thefid=38;
  if((Idv==19)&&(pl_039==2))   
    thefid=39;
  
  
  if((Idv==18)&&(pl_039==3)) //pl2= arm 1 ht 1
    thefid=48;
  if((Idv==19)&&(pl_039==3))   
    thefid=49;
    
  /*
  if((Idv==18)&&(pl_039==1))   //pl1= arm 1 ht 0
    thefid=19;

  if((Idv==18)&&(pl_039==2))   //pl2= arm 1 ht 0
    thefid=20;

  if((Idv==18)&&(pl_039==3))    //pl2= arm 1 ht 1
    thefid=21;
  */
  return thefid;
}



//-------------------------------END CLASS MEMBER DEFINITION---------------------------------------





//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

TotemDQMModuleT2::TotemDQMModuleT2(const edm::ParameterSet &ps) : DQMModule(ps),
  tagDigiVfatColl(ps.getParameter<edm::InputTag>("tagDigiVfatColl")),
  tagPadDigiColl(ps.getParameter<edm::InputTag>("tagPadDigiColl")),
  tagStripDigiColl(ps.getParameter<edm::InputTag>("tagStripDigiColl")),
  tagStripClusterColl(ps.getParameter<edm::InputTag>("tagStripClusterColl")),
  tagPadClusterColl(ps.getParameter<edm::InputTag>("tagPadClusterColl")),
  tagHitColl(ps.getParameter<edm::InputTag>("tagHitColl")),
  tagRoadColl(ps.getParameter<edm::InputTag>("tagRoadColl")),
  tagT1T2TrackColl(ps.getParameter<edm::InputTag>("tagT1T2TrackColl")),
  tagRawEvent(ps.getParameter<edm::InputTag>("tagRawEvent")),								  
								  
  buildCorrelationPlots(ps.getUntrackedParameter<bool>("buildCorrelationPlots", false)),
  correlationPlotsFilter(ps.getUntrackedParameter<std::string>("correlationPlotsFilter", "")),
  correlationPlotsLimit(ps.getUntrackedParameter<unsigned int>("correlationPlotsLimit", 50)),
  correlationPlotsSelectorT2(correlationPlotsFilter)
{
}

//----------------------------------------------------------------------------------------------------

void TotemDQMModuleT2::beginJob()
{
  //printf(">> beginJob\n");
  
  //----------------------------------------
  // initialize ALL  VFAT plots // DATA
  //----------------------------------------
  unsigned int absid;
  //(unsigned int plane,unsigned int vfatid)
  
  // std::cout<<"Vfat plot vector have the following index:"<<std::endl;
  
  for(unsigned int pl =0;pl<40;pl++)
    {
      
      for(unsigned int Idv =0;Idv<17;Idv++)
	{
	  absid=VFatPlots::uniqueVfatID(pl,Idv);
	  //std::cout<<" "<<absid;
	  vFatPlots[absid]=VFatPlots(pl,Idv);
	}
    }
  //Trigger VFAT
  //
  
  vFatPlots[18]=VFatPlots(0,18); //The choice of the plane is not important just to assign 2 Trig-VFAT per ht.
  vFatPlots[19]=VFatPlots(0,19);

  vFatPlots[28]=VFatPlots(10,18); //The choice of the plane is not important just to assign 2 Trig-VFAT per ht.
  vFatPlots[29]=VFatPlots(10,19);

  vFatPlots[38]=VFatPlots(20,18);  
  vFatPlots[39]=VFatPlots(20,19);

  vFatPlots[48]=VFatPlots(30,18);  
  vFatPlots[49]=VFatPlots(30,19);
  
  


  //----------------------------------------
  // initialize ALL  plane plots 
  //----------------------------------------
  for(unsigned int Id =0;Id<40;Id++)
    {
      planePlots[Id] = PlanePlots(Id);
    }
  //----------------------------------------


 
  //----------------------------------------
  // initialize ALL half telescopes plots 
  //----------------------------------------
   for(unsigned int Id =0;Id<4;Id++)
    {
      halfTelescopePlots[Id] = HalfTelescopePlots(Id);
    }
  //----------------------------------------

   fullDetectorPlots[0]=FullDetectorPlots(0);
   /*
5                       T2_Plus_Far
6                       T2
7                       T2_Minus_Near
8                       T2_Plus_Near
9                       BX
10                      T2_Minus_Far

*/
   //----------------------------------------
   //initialize ALL ARM plots 
   //----------------------------------------
  
   FirstTrkAlreadyFilled=false;
   //if (!buildCorrelationPlots) return;
  
       std::map<unsigned int, std::set<unsigned int> > armPlanes;
       for (unsigned int Id =0;Id<40;Id++) {
	 unsigned int DetId = Id;
	 unsigned int HalfId = (DetId/10)%2;    //10*ht+20*arm
	 unsigned int ArmId = (DetId/20);
	 unsigned int PlaneId = (DetId%10); //from 0 to 10
	 armPlanes[ArmId].insert(PlaneId+10*HalfId);//Should be inserted 20 Planes per Arm
       }

       for(unsigned int j=0;j<2;j++)
	 oneArmPlotsGlobal[j]= OneArmPlotsGlobal(j);
	 
       //bool makecorrelationplots;
       if (buildCorrelationPlots==true) 
       for (std::map<unsigned int, std::set<unsigned int> >::iterator iter = armPlanes.begin(); iter != armPlanes.end(); iter++) {
	 // Look if you have all detectors----------------------------------------------
	 std::cout<<"Reading detector on Arm "<<(iter->first)<<" - "<<" Plane "<<std::endl;
	 for (std::set<unsigned int>::iterator itt = (iter->second).begin(); itt != (iter->second).end(); itt++)
	   std::cout<<(*itt)<<std::endl;

	 
	 oneArmPlots[iter->first] = OneArmPlots(iter->first, iter->second, &correlationPlotsSelectorT2, correlationPlotsLimit);	 
       }

  //----------------------------------------
  // Initilize the efficiency plots
  //----------------------------------------
  
  efficiency.beginJob();
  for (unsigned int i=0;i<4; i++) 
    {
      efficiency.plots[i] = T2Efficiency::HalfTelePlots();  //For each halfTele, one eff. plots for detector.
      //  efficiency.halfplots[i]= Efficiency:HalfTelePlots();         //For  each helfTele, one eff. plots.
    }

  
  for (std::map<unsigned int, T2Efficiency::HalfTelePlots>::iterator it = efficiency.plots.begin(); it != efficiency.plots.end(); it++){
    unsigned int htid= it->first;
    std::string HalfName = "";
    if(htid==0)
      HalfName="ArmPlus_/HalfInner_/";
    if(htid==1)
      HalfName="ArmPlus_/HalfOuter_/";
    if(htid==2)
      HalfName="ArmMinus_/HalfInner_/";
    if(htid==3)
      HalfName="ArmMinus_/HalfOuter_/";
    
    //std::cout<<"InizializatooooooooooooooooooooooooooooEto'o"<<htid<<std::endl;

    PlotManager::Register(HalfName+"Plane Measured Rate", "Half Telescope Measured Rate; # Detector", it->second.halfMeasRate= /*std::auto_ptr<TH1D>*/(new TH1D("","title",10,-0.5,9.5)));
													  
    PlotManager::Register(HalfName+"Plane Expected Rate", "Half Telescope Expected Rate; # Detector", it->second.halfExpRate= /*std::auto_ptr<TH1D>*/(new TH1D("","title",10,-0.5,9.5)));
    PlotManager::Register(HalfName+"Plane Efficiency", "Half Telescope Measured Efficiency; # Detector", it->second.halfEffi= /*std::auto_ptr<TH1D>*/(new TH1D("","title",10,-0.5,9.5)));
  
    halfTelescopePlots[0].allTracksInHT1D->GetYaxis()->SetRangeUser(0,111.1);//allTracksInHT1D[0].GetMaximum()
    halfTelescopePlots[1].allTracksInHT1D->GetYaxis()->SetRangeUser(0,111.1);
    halfTelescopePlots[2].allTracksInHT1D->GetYaxis()->SetRangeUser(0,111.1);
    halfTelescopePlots[3].allTracksInHT1D->GetYaxis()->SetRangeUser(0,111.1);
  }
    


}

//----------------------------------------------------------------------------------------------------

TotemDQMModuleT2::~TotemDQMModuleT2()
{


  //printf(">> TotemDQMModuleT2 destructor\n");
  //printf("\tdone\n");
}



//-------------------------------BEGIN------------UTILITIES-------------------------------------------
unsigned int TotemDQMModuleT2::RawtoSymb(uint32_t thedet)
{
  T2DetId converter;
  unsigned int pl=converter.plane(thedet);
  unsigned int pls=converter.planeSide(thedet);
  unsigned int ht=converter.halfTelescope(thedet);
  unsigned int arm=converter.arm(thedet);
  //hitv2.at(a).GetHitPlane()*2+hitv2.at(a).GetHitPlaneSide() -------------WAY OF THE RAWDATA
  unsigned int symbolic=pl*2+pls+ht*10+20*arm;	  
  //unsigned int symbolic=pl*4+ht*2+pls+20*arm;               -------------WAY OF THE ALIGMENT SW (OLD) 

  return symbolic;
}


std::string TotemDQMModuleT2::PathHistoName(unsigned int arm)
{
  //Arm=1 Means Negative
  std::string ArmName = "";
  if(arm==0)
    {
      ArmName="ArmPlus_/";
    }
  if(arm==1)
    {
      ArmName="ArmMinus_/";
    }
  
  return ArmName;
}

std::string TotemDQMModuleT2::PathHistoName(unsigned int arm, unsigned int ht)
{
 std::string outpstr=PathHistoName(arm);

 if(ht==0)
   outpstr=outpstr+"HalfInner_/";
 if(ht==1)
   outpstr=outpstr+"HalfOuter_/";

 return outpstr;
}


std::string TotemDQMModuleT2::PathHistoName(unsigned int arm, unsigned int ht, unsigned int plane)
{
  std::string outpstr=PathHistoName(arm,ht);
  char buf[200];
  /*int i = */sprintf(buf, "%d", plane);
  outpstr+="Plane_";
  outpstr+=buf;
  outpstr+="/";

  return outpstr;
}
std::string TotemDQMModuleT2::PathHistoName(unsigned int arm, unsigned int ht, unsigned int plane, unsigned int Vfatid)
{
  std::string outpstr=PathHistoName(arm,ht,plane);
  char buf[200];
  /*int i =*/ sprintf(buf, "%d", Vfatid);
  outpstr+="VFAT_";
  outpstr+=buf;
  outpstr+="/";
  return outpstr;
}
//-------------------------------END---------------UTILITIES----------------------------------------






//---------------------------------------------------------------------------------------------------
//---------------------    ANALYZER -----------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

void TotemDQMModuleT2::analyze(const edm::EventBase &event)
{

  edm::Handle<Totem::RawEvent> re;
  event.getByLabel(tagRawEvent, re);//(tagRawEvent, re);"source", re

  // std::cout<<re->triggerData.input_status_bits<<std::endl;
  

  /* :::::::::::::TAKE VFAT:::::::::::::::*/
  edm::Handle<T2DigiVfatCollection> t2digivfatcoll;
  event.getByLabel(tagDigiVfatColl , t2digivfatcoll);
  
  /* :::::::::::::TakeDigi::::::::::::*/
  edm::Handle<T2PadDigiCollection> t2paddigicoll;
  event.getByLabel(tagPadDigiColl, t2paddigicoll);
  
  edm::Handle<T2StripDigiCollection> t2stripdigicoll;
  event.getByLabel(tagStripDigiColl, t2stripdigicoll);
  
  DigiContainerIterator<T2DetId, T2PadDigi> itp;
  DigiContainerIterator<T2DetId, T2PadDigi> itp2;
  
  DigiContainerIterator<T2DetId, T2StripDigi> its;
  DigiContainerIterator<T2DetId, T2StripDigi> its2;
  
  /* :::::::::::::Take The Clusters::::::::::::*/

  Handle<T2StripClusterCollection> t2strclcoll;
  event.getByLabel(tagStripClusterColl, t2strclcoll);
  
  Handle<T2PadClusterCollection> t2padclcoll;
  event.getByLabel(tagPadClusterColl, t2padclcoll);
  
  /* ::::::Take  T2  Hits::::::*/
  Handle<T2HitCollection> t2hitcoll;
  event.getByLabel(tagHitColl, t2hitcoll);
  
  /* ::::::Take  T2  Roads::::::*/
  // TODO: remove if not needed
  //Handle<T2RoadCollection> t2roadcoll;
  //event.getByLabel(tagRoadColl, t2roadcoll);
  
  /* :::::: Take T2 tracks ::::::*/
  Handle<T1T2TrackCollection> trackCollection;
  event.getByLabel(tagT1T2TrackColl, trackCollection);

  // input valid?
  bool inputValid = true;
  inputValid &= t2digivfatcoll.isValid();
  inputValid &= t2paddigicoll.isValid();
  inputValid &= t2stripdigicoll.isValid();
  inputValid &= t2strclcoll.isValid();
  inputValid &= t2padclcoll.isValid();
  inputValid &= t2hitcoll.isValid();
  //inputValid &= t2roadcoll.isValid();
  inputValid &= trackCollection.isValid();

  if (!inputValid)
  {
    printf("ERROR in TotemDQMModuleT2::analyze > input handles not valid. Skipping this event.\n");

    printf("\tt2digivfatcoll.isValid = %i\n", t2digivfatcoll.isValid());
    printf("\tt2paddigicoll.isValid = %i\n", t2paddigicoll.isValid());
    printf("\tt2stripdigicoll.isValid = %i\n", t2stripdigicoll.isValid());
    printf("\tt2strclcoll.isValid = %i\n", t2strclcoll.isValid());
    printf("\tt2padclcoll.isValid = %i\n", t2padclcoll.isValid());
    printf("\tt2hitcoll.isValid = %i\n", t2hitcoll.isValid());
    //printf("\tt2roadcoll.isValid = %i\n", t2roadcoll.isValid());
    printf("\ttrackCollection.isValid = %i\n", trackCollection.isValid());

    return;
  }

  // dereferencing handles delayed after validity check
  const T2DigiVfatCollection* DigiVFatptr;
  DigiVFatptr= t2digivfatcoll.product();
  DigiContainerIterator<T2DetId, T2DigiVfat> itv;
  
  const T2PadDigiCollection* PadDigiptr;
  PadDigiptr= t2paddigicoll.product();
  
  const T2StripDigiCollection* StripDigiptr;
  StripDigiptr= t2stripdigicoll.product(); 
  

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinformation;
  
  //--------------------------------------------------------
  //  VFAT Plots
  //--------------------------------------------------------

 
  unsigned int absid;
  unsigned int pl;
  unsigned int vfpos;
  //Reset of oneEvent Data-Vfat Plot
  if (!CumulativeMode()) {
    for(itv= DigiVFatptr->begin();itv!=DigiVFatptr->end(); ++itv)
      {
	T2DetId mydet=(*itv).first;  
	pl= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
	for(unsigned int Idv=0;Idv<17;Idv++)
	  {
	    absid=VFatPlots::uniqueVfatID(pl,Idv);

	    //if(vFatPlots.find(absid)!=vFatPlots.end())
	    // {
		//std::cout<<"T2 dqm is going to reset plots for vfat "<<pl<<"-"<<Idv<<std::endl;
	    //}
	    //else
	    //std::cout<<"T2 dqm CANNOT FIND vfat in plane "<<pl<<" with id "<<Idv<<std::endl;

	    vFatPlots[absid].ActiveChOneEvt->Reset();           
	  }
      }
    //Reset of oneEvent trigger-Vfat Plot
    vFatPlots[18].ActiveChOneEvt->Reset();     
    vFatPlots[19].ActiveChOneEvt->Reset();     
    vFatPlots[28].ActiveChOneEvt->Reset();     
    vFatPlots[29].ActiveChOneEvt->Reset();   
    vFatPlots[38].ActiveChOneEvt->Reset();     
    vFatPlots[39].ActiveChOneEvt->Reset();     
    vFatPlots[48].ActiveChOneEvt->Reset();     
    vFatPlots[49].ActiveChOneEvt->Reset(); 
    

  
  }

  
  for(itv= DigiVFatptr->begin();itv!=DigiVFatptr->end(); ++itv)
      {
	T2DetId mydet=(*itv).first;  
	pl= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
	if(pl<40)
	  {
	    for(std::vector<T2DigiVfat>::const_iterator itvfat =(*itv).second.first; itvfat !=(*itv).second.second; itvfat++)
	      {
		vfpos=itvfat->GetVfatPos();
		//std::cout<<"Found event record with vfat position "<<vfpos<<" in plane "<<pl<<std::endl;
		absid=VFatPlots::uniqueVfatID(pl,vfpos);
		//	std::cout<<"I will try to fill vfat plot in position "<<absid<<std::endl;
		std::map<const unsigned int,unsigned int>::const_iterator itch;
		if (CumulativeMode())
		  {	
		    for(itch=(*itvfat).ChActMap.begin();itch != (*itvfat).ChActMap.end();itch++)
		      if(((*itch).second)==1)//Active Channel
			{
			  vFatPlots[absid].ActiveChCumulative->Fill((*itch).first); //Fill The Bin corresponding to the channel
			  //std::cout<<"vFatPlots["<<absid<<"].ActiveChCumulative->Fill("<<(*itch).first<<");"<<std::endl;
			}
		  }
		else
		  {
		    for(itch=(*itvfat).ChActMap.begin();itch != (*itvfat).ChActMap.end();itch++)
		      if(((*itch).second)==1)
			{
			  //std::cout<<"|||BEF vFatPlots["<<absid<<"].ActiveChOneEvt->Fill("<<(*itch).first<<");"<<std::endl;
			  vFatPlots[absid].ActiveChOneEvt->Fill((*itch).first); 	
			  //std::cout<<"|||AFT vFatPlots["<<absid<<"].ActiveChOneEvt->Fill("<<(*itch).first<<");"<<std::endl;
			}
		  }
	      }
	  }
	else
	  std::cout<<"Warning: totem T2-DQM has found a T2 plane with symb > 39"<<std::endl;
      }

 

     
  //------------------------------------------------------------------------------------------------------
  // Plane Plots
  //------------------------------------------------------------------------------------------------------
    
  //Questo if serve per azzerare il grafico one_event.
  unsigned int symb;
  T2DetId mydet;
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Begin Reset One-Event Histograms +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  if (!CumulativeMode()) {
    for(itp= PadDigiptr->begin(); itp!=PadDigiptr->end(); ++itp)
      {
    	mydet=(*itp).first;  
      	symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
	planePlots[symb].Pad_digi_profile_one_event->Reset();      
      }

    for(T2StripClusterCollection::const_iterator itstrip = t2strclcoll->begin(); itstrip != t2strclcoll->end(); itstrip++){
      //std::vector<T2Cluster> stripClv = itstrip->second;
      mydet=(*itstrip).first;  
      symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
      planePlots[symb].Strip_ClusterSize_one_event->Reset(); 
      for(unsigned int k=0;k<(itstrip->second).size();k++){
	 planePlots[symb].Strip_ClusterSize_one_event->Fill((itstrip->second).at(k).GetNoOfEntries());
      }
    }

   for(T2PadClusterCollection::const_iterator itpad = t2padclcoll->begin(); itpad != t2padclcoll->end(); itpad++){
      mydet=(*itpad).first;
      symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
      planePlots[symb].Pad_ClusterSize_one_event->Reset(); 
      for(unsigned int k=0;k<(itpad->second).size();k++){
	planePlots[symb].Pad_ClusterSize_one_event->Fill((itpad->second).at(k).GetNoOfEntries());
      }
   }
    

   for(T2HitCollection::const_iterator ithit = t2hitcoll->begin(); ithit != t2hitcoll->end(); ithit++){
      symb=RawtoSymb((*ithit).GetHitDetRawId());
      planePlots[symb].hit_R_one_event->Reset(); 
      planePlots[symb].hit_Phi_one_event->Reset(); 
    }
  
  }
  
  //---------------------------------------------------------------------------------------------
  // Half telescope  Plots RESET
  //---------------------------------------------------------------------------------------------
  // 3D plots cumulative and one-event & 3D graphs
  if (!CumulativeMode()) {
    for (std::map<unsigned int, HalfTelescopePlots>::iterator it = halfTelescopePlots.begin(); it != halfTelescopePlots.end(); it++) {
      it->second.currentTrackInHT->Reset(); 
      it->second.TrkRPhi->Reset(); 
      it->second.currentTrackInHT1D->Reset(); 
      it->second.PadCluMultPerPlane->Reset(); 
      it->second.StripCluMultPerPlane->Reset();    
      it->second.VfatMultiplicityMap->Reset();    
    }
  }
  // END Reset One-Event Histograms +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  int NumPadclu[40]; 
  int NumStripclu[40];
  for(unsigned int io=0;io<40;io++)
    {
      NumPadclu[io]=0;
      NumStripclu[io]=0;
    }


  for(T2PadClusterCollection::const_iterator itpad = t2padclcoll->begin(); itpad != t2padclcoll->end(); itpad++){
      mydet=(*itpad).first;
      symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));    
      
      NumPadclu[symb]=(itpad->second).size();

      for(unsigned int k=0;k<(itpad->second).size();k++){
	if (CumulativeMode())
	  planePlots[symb].Pad_ClusterSize_cumulative->Fill((itpad->second).at(k).GetNoOfEntries());
	else
	  planePlots[symb].Pad_ClusterSize_one_event->Fill((itpad->second).at(k).GetNoOfEntries());
      }
   }


  for(T2StripClusterCollection::const_iterator itstrip = t2strclcoll->begin(); itstrip != t2strclcoll->end(); itstrip++){
      //std::vector<T2Cluster> stripClv = itstrip->second;
      mydet=(*itstrip).first;  
      symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
      NumStripclu[symb]=(itstrip->second).size();
      for(unsigned int k=0;k<(itstrip->second).size();k++){
	if (CumulativeMode())
	  planePlots[symb].Strip_ClusterSize_cumulative->Fill((itstrip->second).at(k).GetNoOfEntries());
	else
	  planePlots[symb].Strip_ClusterSize_one_event->Fill((itstrip->second).at(k).GetNoOfEntries());
      }
    }



 

  //Half tele plot only if one trk is reco
  if(trackCollection->size()>0)
  for(unsigned int ie=0;ie<4;ie++)
    {
      const HalfTelescopePlots & pp = halfTelescopePlots[ie]; // do the search once for ever
      if (!CumulativeMode()) 
	{
	  for(unsigned int io=10*ie;io<10*(ie+1);io++)
	    {
	      pp.PadCluMultPerPlane->Fill(io%10,NumPadclu[io]);
	      pp.StripCluMultPerPlane->Fill(io%10,NumStripclu[io]);
	    }
	}
      else
	{

	   for(unsigned int io=10*ie;io<10*(ie+1);io++)
	    {
	      pp.PadCluMultPerPlaneG->Fill(io%10,NumPadclu[io]);
	      pp.StripCluMultPerPlaneG->Fill(io%10,NumStripclu[io]);
	    }
	  
	}
    }



  for(itp= PadDigiptr->begin(); itp!=PadDigiptr->end(); ++itp)
      {
    	T2DetId mydet=(*itp).first;  
      	unsigned int symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
	for(std::vector<T2PadDigi>::const_iterator itpad =(*itp).second.first; itpad !=(*itp).second.second; itpad++)
	  {
	    //std::cout<<((*itpad).getRow()+1)+24*((*itpad).getCol())<<"   ";
	    if (CumulativeMode())
	      planePlots[symb].Pad_digi_profile_cumulative->Fill(((*itpad).getRow()+1)+24*((*itpad).getCol()));
	    else
	      planePlots[symb].Pad_digi_profile_one_event->Fill(((*itpad).getRow()+1)+24*((*itpad).getCol()));
	  }
      }


  for(T2HitCollection::const_iterator ithit = t2hitcoll->begin(); ithit != t2hitcoll->end(); ithit++){
       symb=RawtoSymb((*ithit).GetHitDetRawId());
       if(!CumulativeMode())
	 {
	   planePlots[symb].hit_R_one_event->Fill((*ithit).GetHitR()); 
	   planePlots[symb].hit_Phi_one_event->Fill((*ithit).GetHitPhi());
	 }
     }


  





  const HalfTelescopePlots & h0pl = halfTelescopePlots[0];
  for(itp= PadDigiptr->begin(); itp!=PadDigiptr->end(); ++itp)
    {
      T2DetId mydet=(*itp).first; 
      unsigned int symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
      
      if(symb==7)
	for(std::vector<T2PadDigi>::const_iterator itpad =(*itp).second.first; itpad !=(*itp).second.second; itpad++)
	  {
	    
	    for(itp2= PadDigiptr->begin(); itp2!=PadDigiptr->end(); ++itp2)
	      {    
		      
		T2DetId mydet2=(*itp2).first;   
		
		unsigned int symb2= RawtoSymb(mydet2.calculateRawId(mydet2.arm(),mydet2.halfTelescope(),mydet2.plane(),mydet2.planeSide()));
		if(symb2==9)
		  for(std::vector<T2PadDigi>::const_iterator itpad2 =(*itp2).second.first; itpad2 !=(*itp2).second.second; itpad2++)
		    {
		      unsigned int Numitp= (((*itpad).getRow()+1)+24*((*itpad).getCol()));
			
			unsigned int Numitp2= (((*itpad2).getRow()+1)+24*((*itpad2).getCol()));
			     
			
			h0pl.CorrelPad24->Fill(Numitp,Numitp2);
		    }
	      }
	  }
    }
  


  if(trackCollection->size()>0)
  for(unsigned int ih=0;ih<4;ih++)
    for(unsigned int ip=0;ip<10;ip++)
      for(unsigned int iv=0;iv<17;iv++)
	{
	  const HalfTelescopePlots & pp = halfTelescopePlots[ih];
	  int absid=VFatPlots::uniqueVfatID(ih*10+ip,iv);
	  if (!CumulativeMode())
	    {
	      pp.VfatMultiplicityMap->Fill(ip,iv,vFatPlots[absid].ActiveChOneEvt->GetEntries());
	    }
	  else
	    {
	      pp.VfatMultiplicityMapG->Fill(ip,iv,vFatPlots[absid].ActiveChCumulative->GetEntries());
	    }
	}

 int NumTrkHx[4]; 
  for(unsigned int io=0;io<4;io++)
    {
      NumTrkHx[io]=0;
    }

  T1T2TrackCollection::const_iterator TrkCit;
for(TrkCit=trackCollection->begin(); TrkCit!=trackCollection->end(); TrkCit++){
  unsigned int symb=RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId());
  unsigned int halftele=(symb/10)%2; 
  unsigned int arm=(symb/20);
  unsigned int halfteleId=2*arm+halftele;  //perche sono 4 qui dentro
  const HalfTelescopePlots & pp = halfTelescopePlots[halfteleId]; // do the search once for ever
  NumTrkHx[halfteleId]++;

  if (!CumulativeMode()) 
    {
      pp.currentTrackInHT->Fill((*TrkCit).Phi()*180.0/3.14159, (*TrkCit).Eta());
      pp.TrkRPhi->Fill((*TrkCit).Phi()*180.0/3.14159, (*TrkCit).GetHitT2(0).GetHitR());
    
    } 
  else 
    {
      // std::cout<<"DDDDDDDDDDDDDDDDDDDDDDDDDD"<<std::endl;
      fullDetectorPlots[0].ALLTRKS_RPHIG->Fill((*TrkCit).Phi()*180.0/3.14159,  (*TrkCit).GetHitT2(0).GetHitR());
      pp.allTracksInHT->Fill((*TrkCit).Phi()*180.0/3.14159,(*TrkCit).Eta()); 
      pp.TrkRPhiG->Fill((*TrkCit).Phi()*180.0/3.14159,  (*TrkCit).GetHitT2(0).GetHitR());
    }
} 
   
 for(unsigned int io=0;io<4;io++)
   {
     const HalfTelescopePlots & pp = halfTelescopePlots[io]; 
     if (!CumulativeMode()) 
       {
	 pp.currentTrackInHT1D->Fill(NumTrkHx[io]);
       }
     else
       {
	 pp.allTracksInHT1D->Fill(NumTrkHx[io]);
	 
       }   
   }

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*
5                       T2_Plus_Far
6                       T2
7                       T2_Minus_Near
8                       T2_Plus_Near
9                       BX
10                      T2_Minus_Far

 triggerData.input_status_bits fullDetectorPlots[0]
 */


 {
 if(!CumulativeMode()) 
   {

     if(((re->triggerData.input_status_bits)&32)!=0)
       {
	 //5                       T2_Plus_Far
	 if(NumTrkHx[1]>0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(5,5);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(5,6);
       }     
     if(NumTrkHx[1]>0)
       {
	 //5                       T2_Plus_Far
	 if(((re->triggerData.input_status_bits)&32)!=0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(5,5);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(5,4);
       }
     
     if(((re->triggerData.input_status_bits)&64)!=0)
       {
	 //6                       T2
	 if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(6,6);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(6,7);
       }
     if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
       {
	 //6                       T2
	 if(((re->triggerData.input_status_bits)&64)!=0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(6,6);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(6,5);
       }
     
     if(((re->triggerData.input_status_bits)&128)!=0)
       {
	 if((NumTrkHx[2])>0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(7,7);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(7,8);
	 //7                        T2_Minus_Near
       }
     if((NumTrkHx[2])>0)
       {
	 if(((re->triggerData.input_status_bits)&128)!=0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(7,7);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(7,6);
	 //7                        T2_Minus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&256)!=0)
       {
	 if((NumTrkHx[0])>0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(8,8);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(8,9);
	 //8                       T2_Plus_Near
       }
     if((NumTrkHx[0])>0)
       {
	 if(((re->triggerData.input_status_bits)&256)!=0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(8,8);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(8,7);
	 //8                       T2_Plus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&1024)!=0)
       {
	 if((NumTrkHx[3])>0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(10,10);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(10,11);
	 //10                       T2_Minus_Far
       }
     if((NumTrkHx[3])>0)
       {
	 if(((re->triggerData.input_status_bits)&1024)!=0)
	   fullDetectorPlots[0].TriggerandTracks->Fill(10,10);
	 else
	   fullDetectorPlots[0].TriggerandTracks->Fill(10,9);
	 //10                       T2_Minus_Far
       }
   }
 else
   {
     if(((re->triggerData.input_status_bits)&32)!=0)
       {
	 //5                       T2_Plus_Far
	 if(NumTrkHx[1]>0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(5,5);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(5,6);
       }     
     if(NumTrkHx[1]>0)
       {
	 //5                       T2_Plus_Far
	 if(((re->triggerData.input_status_bits)&32)!=0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(5,5);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(5,4);
       }
     
     if(((re->triggerData.input_status_bits)&64)!=0)
       {
	 //6                       T2
	 if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(6,6);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(6,7);
       }
     if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
       {
	 //6                       T2
	 if(((re->triggerData.input_status_bits)&64)!=0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(6,6);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(6,5);
       }
     
     if(((re->triggerData.input_status_bits)&128)!=0)
       {
	 if((NumTrkHx[2])>0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(7,7);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(7,8);
	 //7                        T2_Minus_Near
       }
     if((NumTrkHx[2])>0)
       {
	 if(((re->triggerData.input_status_bits)&128)!=0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(7,7);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(7,6);
	 //7                        T2_Minus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&256)!=0)
       {
	 if((NumTrkHx[0])>0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(8,8);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(8,9);
	 //8                       T2_Plus_Near
       }
     if((NumTrkHx[0])>0)
       {
	 if(((re->triggerData.input_status_bits)&256)!=0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(8,8);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(8,7);
	 //8                       T2_Plus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&1024)!=0)
       {
	 if((NumTrkHx[3])>0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(10,10);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(10,11);
	 //10                       T2_Minus_Far
       }
     if((NumTrkHx[3])>0)
       {
	 if(((re->triggerData.input_status_bits)&1024)!=0)
	   fullDetectorPlots[0].TriggerandTracksG->Fill(10,10);
	 else
	   fullDetectorPlots[0].TriggerandTracksG->Fill(10,9);
	 //10                       T2_Minus_Far
       }
     
     
   }
 }

 

 ///////////////////////////////////////////////////////////////////////////////////////////
  ///   ///        ///         ///          ///          /// 
 ///////////////////////////////////////////////////////////////////////////////////////////


 if(((re->triggerData.input_status_bits)&512)!=0)
   {
 if(!CumulativeMode()) 
   {

     if(((re->triggerData.input_status_bits)&32)!=0)
       {
	 //5                       T2_Plus_Far
	 if(NumTrkHx[1]>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(5,5);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(5,6);
       }     
     if(NumTrkHx[1]>0)
       {
	 //5                       T2_Plus_Far
	 if(((re->triggerData.input_status_bits)&32)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(5,5);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(5,4);
       }
     
     if(((re->triggerData.input_status_bits)&64)!=0)
       {
	 //6                       T2
	 if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(6,6);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(6,7);
       }
     if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
       {
	 //6                       T2
	 if(((re->triggerData.input_status_bits)&64)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(6,6);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(6,5);
       }
     
     if(((re->triggerData.input_status_bits)&128)!=0)
       {
	 if((NumTrkHx[2])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(7,7);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(7,8);
	 //7                        T2_Minus_Near
       }
     if((NumTrkHx[2])>0)
       {
	 if(((re->triggerData.input_status_bits)&128)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(7,7);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(7,6);
	 //7                        T2_Minus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&256)!=0)
       {
	 if((NumTrkHx[0])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(8,8);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(8,9);
	 //8                       T2_Plus_Near
       }
     if((NumTrkHx[0])>0)
       {
	 if(((re->triggerData.input_status_bits)&256)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(8,8);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(8,7);
	 //8                       T2_Plus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&1024)!=0)
       {
	 if((NumTrkHx[3])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(10,10);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(10,11);
	 //10                       T2_Minus_Far
       }
     if((NumTrkHx[3])>0)
       {
	 if(((re->triggerData.input_status_bits)&1024)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(10,10);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracks->Fill(10,9);
	 //10                       T2_Minus_Far
       }
   }
 else
   {
     if(((re->triggerData.input_status_bits)&32)!=0)
       {
	 //5                       T2_Plus_Far
	 if(NumTrkHx[1]>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(5,5);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(5,6);
       }     
     if(NumTrkHx[1]>0)
       {
	 //5                       T2_Plus_Far
	 if(((re->triggerData.input_status_bits)&32)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(5,5);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(5,4);
       }
     
     if(((re->triggerData.input_status_bits)&64)!=0)
       {
	 //6                       T2
	 if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(6,6);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(6,7);
       }
     if((NumTrkHx[0]+NumTrkHx[1]+NumTrkHx[2]+NumTrkHx[3])>0)
       {
	 //6                       T2
	 if(((re->triggerData.input_status_bits)&64)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(6,6);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(6,5);
       }
     
     if(((re->triggerData.input_status_bits)&128)!=0)
       {
	 if((NumTrkHx[2])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(7,7);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(7,8);
	 //7                        T2_Minus_Near
       }
     if((NumTrkHx[2])>0)
       {
	 if(((re->triggerData.input_status_bits)&128)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(7,7);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(7,6);
	 //7                        T2_Minus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&256)!=0)
       {
	 if((NumTrkHx[0])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(8,8);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(8,9);
	 //8                       T2_Plus_Near
       }
     if((NumTrkHx[0])>0)
       {
	 if(((re->triggerData.input_status_bits)&256)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(8,8);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(8,7);
	 //8                       T2_Plus_Near
       }
     
     
     if(((re->triggerData.input_status_bits)&1024)!=0)
       {
	 if((NumTrkHx[3])>0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(10,10);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(10,11);
	 //10                       T2_Minus_Far
       }
     if((NumTrkHx[3])>0)
       {
	 if(((re->triggerData.input_status_bits)&1024)!=0)
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(10,10);
	 else
	   fullDetectorPlots[0].OnBX_TriggerandTracksG->Fill(10,9);
	 //10                       T2_Minus_Far
       }
     
     
   }
 }

 //if(((re->triggerData.input_status_bits)&512)!=0);
 //9                      BX







  //-----------------------------------------------------------------------------------
  // Arm Plots
  //-----------------------------------------------------------------------------------

  // Global plots
  if (!CumulativeMode()) 
    {
      for (std::map<unsigned int, OneArmPlotsGlobal>::iterator it = oneArmPlotsGlobal.begin(); it != oneArmPlotsGlobal.end(); it++) 
	{
	   it->second.XHitsSel->Set(0);
	   it->second.YHitsSel->Set(0);
	   it->second.YTrack->SetRange(0, 0);
	   it->second.XTrack->SetRange(0, 0);	 
	   it->second.mROX->Release(2);
	   it->second.mROY->Release(2);
	}      	  
    }
  /*
  else
    {
      for (std::map<unsigned int, OneArmPlotsGlobal>::iterator it = oneArmPlotsGlobal.begin(); it != oneArmPlotsGlobal.end(); it++) 
	{
	   it->second.XHitsSelFirst->Set(0);
	   it->second.YHitsSelFirst->Set(0);
	   it->second.YTrackFirst->SetRange(0, 0);
	   it->second.XTrackFirst->SetRange(0, 0);	 
	}
      
    }
  */

  // std::cout<<"It will be filled here"<<std::endl;
  // oneArmPlotsGlobal[Arm];
  
  
  unsigned int usdarm;
  double planez;
  double x_min_z = std::numeric_limits<double>::max(), x_max_z = std::numeric_limits<double>::min(), y_min_z = x_min_z, y_max_z = x_max_z;    // to set range for X,Y Track

 

  T1T2TrackCollection::const_iterator Trkit;
  // show the best track only?;
  
  for(Trkit=trackCollection->begin(); Trkit!=trackCollection->end(); Trkit++){
    
    planeinformation=conv.GetT2Info((*Trkit).GetHitT2(0).GetHitDetRawId());
    usdarm=planeinformation.arm;
    // Create a pointer to the arm
    const OneArmPlotsGlobal & ag = oneArmPlotsGlobal[usdarm];
    // double h0x=0.;
    //double h0y=0.;    
    if (!CumulativeMode()) 
      {
	for (unsigned int t=0;t<(*Trkit).GetHitEntries();t++)
	  {
	    planeinformation=conv.GetT2Info((*Trkit).GetHitT2(t).GetHitDetRawId());
	    planez=planeinformation.Zdet;
	    
	    Int_t pNX = oneArmPlotsGlobal[usdarm].XHitsSel->GetN();
	    ag.XHitsSel->SetPoint(pNX,planez , (*Trkit).GetHitT2(t).GetHitX());
            ag.XHitsSel->SetPointError(pNX,0 , (*Trkit).GetHitT2(t).GetHitDX());
	    x_min_z = std::min(x_min_z, planez);
            x_max_z = std::max(x_max_z, planez);

	    Int_t pNY = oneArmPlotsGlobal[usdarm].YHitsSel->GetN();
	    ag.YHitsSel->SetPoint(pNY,planez , (*Trkit).GetHitT2(t).GetHitY());
            ag.YHitsSel->SetPointError(pNY,0 , (*Trkit).GetHitT2(t).GetHitDY());

	    y_min_z = std::min(y_min_z, planez);
            y_max_z = std::max(y_max_z, planez);
	    
	  }
    
	//} 

	// if (!CumulativeMode()) {
     ag.XTrack->SetRange(x_min_z , x_max_z);
     ag.YTrack->SetRange(y_min_z , y_max_z);
     ag.XTrack->SetParameters((*Trkit).GetTx(), (*Trkit).X0() /*+ (ax*z0_sub)*/);
     ag.YTrack->SetParameters((*Trkit).GetTy(), (*Trkit).Y0() /*+ (ay*z0_sub)*/);

     TF1 *fx = new TF1("", "[0]*x+[1]", 0, 1);
     fx->SetParameters((*Trkit).GetTx(), (*Trkit).X0());
     fx->SetRange(x_min_z , x_max_z);
     fx->SetLineColor(4);
     fx->SetLineStyle(1);
     fx->SetLineWidth(1);
     
     
     ag.mROX->Add(fx, "same");

     TF1 *fy = new TF1("", "[0]*x+[1]", 0, 1);
     fy->SetParameters((*Trkit).GetTy(), (*Trkit).Y0());
     fy->SetRange(y_min_z , y_max_z);
     fy->SetLineColor(4);
     fy->SetLineStyle(1);
     fy->SetLineWidth(1);
     ag.mROY->Add(fy, "same");
     

     // std::cout<<"X A-B: "<<(*Trkit).GetTx()<<" "<<(*Trkit).X0()<<" z:"<<x_min_z<<" "<<x_max_z<<"RangeX: "<<((*Trkit).X0()+(*Trkit).GetTx()*x_min_z)<<" Hit0X: "<<(*Trkit).GetHitT2(0).GetHitX()<<std::endl;
     //std::cout<<"Y A-B: "<<(*Trkit).GetTy()<<" "<<(*Trkit).Y0()<<" z:"<<y_min_z<<" "<<y_max_z<<"RangeY: "<<std::endl;
    }
    else
      {
	/*
	//std::cout<<"Trk Entries"<<((*Trkit).GetHitEntries())<<std::endl;
	if((*Trkit).GetHitEntries()>=7)
	  {
	    //  std::cout<<"FirstTrkAlreadyFilled= "<<FirstTrkAlreadyFilled;
	  if(FirstTrkAlreadyFilled==false)
	    {
	      
	      for (unsigned int t=0;t<(*Trkit).GetHitEntries();t++)
		{
		  planeinformation=conv.GetT2Info((*Trkit).GetHitT2(t).GetHitDetRawId());
		  planez=planeinformation.Zdet;
	    
		  Int_t pNX = oneArmPlotsGlobal[usdarm].XHitsSelFirst->GetN();
		  ag.XHitsSelFirst->SetPoint(pNX,planez , (*Trkit).GetHitT2(t).GetHitX());
		  std::cout<<"point "<<pNX<<"-"<<planez<<"-"<<(*Trkit).GetHitT2(t).GetHitX()<<std::endl;
		  ag.XHitsSelFirst->SetPointError(pNX,0 , (*Trkit).GetHitT2(t).GetHitDX());
		  x_min_z = std::min(x_min_z, planez);
		  x_max_z = std::max(x_max_z, planez);

		  Int_t pNY = oneArmPlotsGlobal[usdarm].YHitsSelFirst->GetN();
		  ag.YHitsSelFirst->SetPoint(pNY,planez , (*Trkit).GetHitT2(t).GetHitY());
		  ag.YHitsSelFirst->SetPointError(pNY,0 , (*Trkit).GetHitT2(t).GetHitDY());

		  y_min_z = std::min(y_min_z, planez);
		  y_max_z = std::max(y_max_z, planez);

		}

	      ag.XTrackFirst->SetRange(x_min_z , x_max_z);
	      ag.YTrackFirst->SetRange(y_min_z , y_max_z);
	      ag.XTrackFirst->SetParameters((*Trkit).GetTx(), (*Trkit).X0() );
	      ag.YTrackFirst->SetParameters((*Trkit).GetTy(), (*Trkit).Y0() ); //(ay*z0_sub)
	      FirstTrkAlreadyFilled=true;
	    }
	  }
	*/
      }
  
  }

  

  // Correlation plots
 if (CumulativeMode()) 
   { 



     //Add here "Non-correlation" plots 

     if (buildCorrelationPlots) {
       for(its= StripDigiptr->begin(); its!=StripDigiptr->end(); ++its)
	 {
	   for(its2= StripDigiptr->begin(); its2!=StripDigiptr->end(); ++its2)
	     {    
	       T2DetId mydet=(*its).first;   
	       T2DetId mydet2=(*its2).first;   
	       unsigned int symb= RawtoSymb(mydet.calculateRawId(mydet.arm(),mydet.halfTelescope(),mydet.plane(),mydet.planeSide()));
	       unsigned int symb2= RawtoSymb(mydet2.calculateRawId(mydet2.arm(),mydet2.halfTelescope(),mydet2.plane(),mydet2.planeSide()));

	       if (symb != symb2) {
		 //unsigned int DetId1 = TotRPDetId::RawToDecId(i->detId());
		 //unsigned int DetId2 = TotRPDetId::RawToDecId(j->detId());
		 //unsigned int StationId1 = DetId1 / 100;
		 //unsigned int StationId2 = DetId2 / 100;
		 unsigned int Arm1= mydet.arm();
		 unsigned int Arm2= mydet2.arm();   
		 unsigned int Ht1= mydet.halfTelescope();
		 unsigned int Ht2= mydet2.halfTelescope();

		 unsigned int Plane1=mydet.plane()*2+mydet.planeSide()+Ht1*10;
		 unsigned int Plane2=mydet2.plane()*2+mydet2.planeSide()+Ht2*10;
	
		 //if (OneArmPlots.correlationPlotsSelectorT2->IfCorrelate(Plane1, Plane2,Arm1)) 
		 if (Arm1 == Arm2) 
		   {
		   //unsigned int RPPlaneId1 = DetId1 % 100;
		   //unsigned int RPPlaneId2 = DetId2 % 100;
		   if (oneArmPlots[Arm1].hist[Plane1+20*Arm1][Plane2+20*Arm1]) 
		     {
		       for(std::vector<T2StripDigi>::const_iterator itstrip =(*its).second.first; itstrip !=(*its).second.second; itstrip++)
			 for(std::vector<T2StripDigi>::const_iterator itstrip2 =(*its2).second.first; itstrip2 !=(*its2).second.second; itstrip2++){
			   //for (DetSet<RPStripDigi>::const_iterator di = i->begin(); di != i->end(); di++)
			   //for (DetSet<RPStripDigi>::const_iterator dj = j->begin(); dj != j->end(); dj++) {
			   Double_t temp[2];
			   temp[0] = itstrip->getStripNr();
			   temp[1] = itstrip2->getStripNr();
			   oneArmPlots[Arm1].hist[Plane1+20*Arm1][Plane2+20*Arm1]->Fill(temp);
			 }
		     }
		 }
	       }
	     }
	 }
     }   
  }

 // Add efficiency informaiton from this event
  efficiency.analyze(event, tagHitColl, tagT1T2TrackColl);

}

void TotemDQMModuleT2::endJob()
{
    efficiency.endJob();
}
