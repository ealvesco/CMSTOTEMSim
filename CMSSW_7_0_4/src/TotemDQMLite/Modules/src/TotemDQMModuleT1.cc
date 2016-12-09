#include "TotemDQMLite/Modules/interface/TotemDQMModuleT1.h"

#include "TotemDQMLite/Core/interface/PlotManager.h"

#include "DataFormats/T1DigiWire/interface/T1DigiWireCollection.h"
#include "DataFormats/T1DigiVfat/interface/T1DigiVfatCollection.h"
#include "DataFormats/T1RecHit/interface/T1RecHit2DCollection.h"

using namespace std;
using namespace edm;

TotemDQMModuleT1::CSCPlots::CSCPlots(unsigned int id_059)
{
  unsigned int braccio = int(id_059/30);
  unsigned int piano = int((id_059%30)/6);
  unsigned int camera = (id_059%30)%6;
 
  std::string CSCName;
 
  CSCName=PathHistoName(braccio,piano,camera);
  
// digi

  PlotManager::Register(CSCName + "StripA number cumulative", CSCName + "StripA number (cumulative)", StripA_digi_number_cumulative = new TH1D("", "title", 250, -0.5, 249.5));
  PlotManager::Register(CSCName + "StripB number cumulative", CSCName + "StripB number (cumulative)", StripB_digi_number_cumulative = new TH1D("", "title", 250, -0.5, 249.5));
  PlotManager::Register(CSCName + "Wire number cumulative", CSCName + "Wire number (cumulative)", Wire_digi_number_cumulative = new TH1D("", "title", 250, -0.5, 249.5));

  PlotManager::Register(CSCName + "StripA profile cumulative", CSCName + "StripA : digi profile (cumulative)", StripA_digi_profile_cumulative = new TH1D("", "title", 250, 0.5, 250.5));
  PlotManager::Register(CSCName + "StripB profile cumulative", CSCName + "StripB : digi profile (cumulative)", StripB_digi_profile_cumulative = new TH1D("", "title", 250, 0.5, 250.5));
  PlotManager::Register(CSCName + "Wire profile cumulative", CSCName + "Wire : digi profile (cumulative)", Wire_digi_profile_cumulative = new TH1D("", "title", 250, 0.5, 250.5));

 PlotManager::Register(CSCName + "StripA profile one-event", CSCName + "StripA : digi profile (one-event)", StripA_digi_profile_one_event = new TH1D("", "title", 250, 0.5, 250.5));

 PlotManager::Register(CSCName + "StripB profile one-event", CSCName + "StripB : digi profile (one-event)", StripB_digi_profile_one_event = new TH1D("", "title", 250, 0.5, 250.5));

 PlotManager::Register(CSCName + "Wire profile one-event", CSCName + "Wire : digi profile (one-event)", Wire_digi_profile_one_event = new TH1D("", "title", 250, 0.5, 250.5));

// reco
 PlotManager::Register(CSCName + "Reco hits cumulative", CSCName + "Reco hits (cumulative)", Reco_hits_cumulative = new TH2D("", "title", 300, -600, 600,300, -600,600) );

 PlotManager::Register(CSCName + "Reco hits number cumulative", CSCName + "Reco hits number (cumulative)", Reco_hits_number_cumulative = new TH1D("", "title", 300, -0.5, 299.5) );
}



TotemDQMModuleT1::ARMPlots::ARMPlots(unsigned int braccio)
{
  std::string ARMName;
  ARMName=PathHistoName(braccio);
  PlotManager::Register(ARMName + "Reco hits one-event", ARMName + "Reco hits (one-event)", Reco_hits_one_event = new TH2D("", "title", 250, -1000, 1000,250,-1000,1000));
}



TotemDQMModuleT1::TotemDQMModuleT1(const edm::ParameterSet &ps) : DQMModule(ps),
  tagDigiColl(ps.getParameter<edm::InputTag>("tagDigiColl")),
  tagDigiCollStrip(ps.getParameter<edm::InputTag>("tagDigiCollStrip")),
  tagRecoColl(ps.getParameter<edm::InputTag>("tagRecoColl"))
{
  std::string thegeometryfile = "Geometry/TotemGeometry/data/T1_data_geometry.dat";
  theT1Geometry = new T1Geometry(thegeometryfile);


}
TotemDQMModuleT1::~TotemDQMModuleT1()
{
  delete theT1Geometry;
}


void TotemDQMModuleT1::endJob()
{
}


void TotemDQMModuleT1::beginJob()
{
  //----------------------------------------
  // initialize ALL csc plots 
  //----------------------------------------
  for(unsigned int Id =0;Id<60;Id++)
    {
      cscPlots[Id] = CSCPlots(Id);
    }
  //----------------------------------------

    
	armPlots[0]=ARMPlots(0);
	armPlots[1]=ARMPlots(1);
}



std::string TotemDQMModuleT1::PathHistoName(unsigned int arm)
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

std::string TotemDQMModuleT1::PathHistoName(unsigned int arm, unsigned int plane)
{
 std::string outpstr=PathHistoName(arm);

 if(plane==0)
   outpstr=outpstr+"1stPlane_/";
 if(plane==1)
   outpstr=outpstr+"2ndPlane_/";
 if(plane==2)
   outpstr=outpstr+"3rdPlane_/";
 if(plane==3)
   outpstr=outpstr+"4thPlane_/";
 if(plane==4)
   outpstr=outpstr+"5thPlane_/";


 return outpstr;
}


std::string TotemDQMModuleT1::PathHistoName(unsigned int arm, unsigned int plane, unsigned int csc)
{
  std::string outpstr=PathHistoName(arm,plane);
  char buf[200];
  /*int i = */sprintf(buf, "%d", csc);
  outpstr+="CSC_";
  outpstr+=buf;
  outpstr+="/";

  return outpstr;
}
std::string TotemDQMModuleT1::PathHistoName(unsigned int arm, unsigned int plane, unsigned int csc, unsigned int Vfatid)
{
  std::string outpstr=PathHistoName(arm,plane,csc);
  char buf[200];
  /*int i =*/ sprintf(buf, "%d", Vfatid);
  outpstr+="VFAT_";
  outpstr+=buf;
  outpstr+="/";
  return outpstr;
}



void TotemDQMModuleT1::analyze(const edm::EventBase &event)
{
  if( event.id().event()%100 == 0) std::cout << '\xd' <<"******** Events: "<< event.id().event() << "                                      ";

  edm::Handle<T1DigiWireCollection> myDigiColl;
  event.getByLabel(tagDigiColl, myDigiColl);

  edm::Handle<T1DigiVfatCollection> myDigiCollStrip;
  event.getByLabel(tagDigiCollStrip, myDigiCollStrip);

  edm::Handle<T1RecHit2DCollection> myRecoColl;
  event.getByLabel(tagRecoColl, myRecoColl);
  T1RecHit2DCollection::const_iterator T1Reco_it;

  // input valid?
  if (!myDigiColl.isValid() || !myDigiCollStrip.isValid() || !myRecoColl.isValid())
  {
    printf("ERROR in TotemDQMModuleT1::analyze > input handles not valid. Skipping this event.\n");

    printf("\tmyDigiColl.isValid = %i\n", myDigiColl.isValid());
    printf("\tmyDigiCollStrip.isValid = %i\n", myDigiCollStrip.isValid());
    printf("\tmyRecoColl.isValid = %i\n", myRecoColl.isValid());

    return;
  }

    int NumberOfWire[60];
    int NumberOfStripA[60];
    int NumberOfStripB[60];

    int NumberOfRecoHits[60];


//reset histograms for non cumulative mode
 
    for(int iii = 0; iii<60; iii++){
      if(!CumulativeMode()){
//	std::cout <<" non cumulative a ---------" << std::endl; 
	cscPlots[iii].Wire_digi_profile_one_event->Reset();
	cscPlots[iii].StripA_digi_profile_one_event->Reset();
	cscPlots[iii].StripB_digi_profile_one_event->Reset();
	if(iii<=1)
	  armPlots[iii].Reco_hits_one_event->Reset();
      }else{
	NumberOfWire[iii]=0;
	NumberOfStripA[iii]=0;
	NumberOfStripB[iii]=0;
	NumberOfRecoHits[iii]=0;
      }
      
    }


    

    T1DigiWireCollection::DigiRangeIterator T1Digi_it;
    for(T1Digi_it=myDigiColl->begin();T1Digi_it!=myDigiColl->end();T1Digi_it++){

      int braccio = (*T1Digi_it).first.Arm();
      int piano = (*T1Digi_it).first.Plane();
      int camera = (*T1Digi_it).first.CSC();

      unsigned int ID = braccio*30 + piano*6 + camera;
      if(ID> 59)throw("CSC ID >59");

      const T1DigiWireCollection::Range& range = (*T1Digi_it).second;
      for (T1DigiWireCollection::const_iterator digiIt = range.first;
           digiIt!=range.second;++digiIt){
	
	if(CumulativeMode()){
	  cscPlots[ID].Wire_digi_profile_cumulative->Fill(digiIt->wire());
	  NumberOfWire[ID] += 1;
	// std::cout <<" Cumulative b ---------" << std::endl; 
	}
	else{
//	  std::cout <<" non cumulative b ---------" << std::endl; 
	  cscPlots[ID].Wire_digi_profile_one_event->Fill(digiIt->wire());
	}
	cscPlots[ID].Wire_digi_profile_cumulative->GetXaxis()->SetTitle("N");
	cscPlots[ID].Wire_digi_profile_one_event->GetXaxis()->SetTitle("N");

      }
    }

    T1DigiVfatCollection::DigiRangeIterator T1DigiS_it;
    for(T1DigiS_it=myDigiCollStrip->begin();T1DigiS_it!=myDigiCollStrip->end();T1DigiS_it++){
      int piano = (*T1DigiS_it).first.Plane();
      int braccio = (*T1DigiS_it).first.Arm();
      int camera = (*T1DigiS_it).first.CSC();
      int strato = (*T1DigiS_it).first.Layer();

      unsigned int ID = braccio*30 + piano*6 + camera;
      if(ID> 59)throw("CSC ID >59");

      const T1DigiVfatCollection::Range& range = (*T1DigiS_it).second;
      for (T1DigiVfatCollection::const_iterator digiIt = range.first;
           digiIt!=range.second;++digiIt){
	

	if(strato==1){
	  if(CumulativeMode()){
	    cscPlots[ID].StripA_digi_profile_cumulative->Fill(digiIt->strip() );
	    NumberOfStripA[ID] += 1;
	  }
	    else{
	    cscPlots[ID].StripA_digi_profile_one_event->Fill(digiIt->strip() );
	    }
	  cscPlots[ID].StripA_digi_profile_cumulative->GetXaxis()->SetTitle("N");
	  cscPlots[ID].StripA_digi_profile_one_event->GetXaxis()->SetTitle("N");
										
	}
	if(strato==2){
	  if(CumulativeMode()){
	    cscPlots[ID].StripB_digi_profile_cumulative->Fill(digiIt->strip() );
	    NumberOfStripB[ID] += 1;
}
	  else{
	    cscPlots[ID].StripB_digi_profile_one_event->Fill(digiIt->strip() );
	  }
	  cscPlots[ID].StripB_digi_profile_cumulative->GetXaxis()->SetTitle("N");
	  cscPlots[ID].StripB_digi_profile_one_event->GetXaxis()->SetTitle("N");
	 
	    }
	
      }
    }



    // first use of myRecoColl

    for(T1Reco_it=myRecoColl->begin();T1Reco_it!=myRecoColl->end();T1Reco_it++){

      T1DetId t1Id((*T1Reco_it).t1DetId());
      int braccio = t1Id.Arm();
      int piano = t1Id.Plane();
      int camera = t1Id.CSC();

      unsigned int ID = braccio*30 + piano*6 + camera;
      
      float xxxR = theT1Geometry->xFromLocal2BeamSystem((*T1Reco_it).t1DetId().rawId(),(*T1Reco_it).localPosition().x() );
      float yyyR = theT1Geometry->yFromLocal2BeamSystem((*T1Reco_it).t1DetId().rawId(),(*T1Reco_it).localPosition().y() );


      float xxxxR=0;
      float yyyyR=0;
      theT1Geometry->RotationLocal2Global((*T1Reco_it).t1DetId().rawId(),xxxR,yyyR,xxxxR,yyyyR);


      if(CumulativeMode()){
	
	cscPlots[ID].Reco_hits_cumulative->Fill((*T1Reco_it).localPosition().x(),(*T1Reco_it).localPosition().y());
	NumberOfRecoHits[ID] += 1;
	  }
      else{
	armPlots[braccio].Reco_hits_one_event->Fill(xxxxR,yyyyR);



      }




      cscPlots[ID].Reco_hits_cumulative->GetXaxis()->SetTitle("X (mm)");
      cscPlots[ID].Reco_hits_cumulative->GetYaxis()->SetTitle("Y (mm)");
     armPlots[braccio].Reco_hits_one_event->GetXaxis()->SetTitle("X (mm)");
      armPlots[braccio].Reco_hits_one_event->GetYaxis()->SetTitle("Y (mm)");

    }
 

    for(int ii=0;ii<60;ii++){
      cscPlots[ii].Wire_digi_number_cumulative->Fill(NumberOfWire[ii]);
      cscPlots[ii].StripA_digi_number_cumulative->Fill(NumberOfStripA[ii]);
      cscPlots[ii].StripB_digi_number_cumulative->Fill(NumberOfStripB[ii]);
      cscPlots[ii].Reco_hits_number_cumulative->Fill(NumberOfRecoHits[ii]);
    }

}
