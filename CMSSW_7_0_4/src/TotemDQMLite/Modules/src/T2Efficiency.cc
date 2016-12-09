/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*  Rafał Leszko (rafal.leszko@gmail.com)
*  Mirko Berretti (mirko.berretti@gmail.com) 
*
****************************************************************************/

#include "TotemDQMLite/Modules/interface/T2Efficiency.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"

#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/T2Digi/interface/T2StripDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2StripDigi.h"
#include "DataFormats/T2Digi/interface/T2PadDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2PadDigi.h"
#include "DataFormats/T2Cluster/interface/T2Cluster.h"
#include "DataFormats/T2Hit/interface/T2Hit.h"
#include "DataFormats/T2Hit/interface/T2HitCollection.h"
#include "DataFormats/T2Cluster/interface/T2PadClusterCollection.h"
#include "DataFormats/T2Cluster/interface/T2StripClusterCollection.h"
#include "DataFormats/T2Road/interface/T2Road.h"
#include "DataFormats/T2Road/interface/T2RoadCollection.h"
#include "DataFormats/T1T2Track/interface/T1T2Track.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"
#include "DataFormats/Common/interface/DetSetVector.h"

#include "RecoTotemT1T2/T2MakeCluster/interface/T2DetClustReconst.h"
#include "RecoTotemT1T2/T2MakeCluster/interface/T2MakeCluster.h"
#include "RecoTotemT1T2/T2RecHit/interface/T2DetHitReconst.h" 
#include "RecoTotemT1T2/T2RecHit/interface/T2RecHit.h"


//#include "TotemT1T2Validation/T2ValidRawData/interface/TrackInfo.h"
#include <TH1D.h>
#include <TH2D.h>
#include <vector>

using namespace edm;
using namespace std;


T2Efficiency::HalfTelePlots::HalfTelePlots()
{
  char name[512], name2[512], name3[512];
  int bins = 256;
  for (int i=0; i<10; i++)
   {
    // TODO: this causes lots of ROOT warnings
	//sprintf(name, "hits_det_%d",i);
	//sprintf(name2, "fit_det_%d",i);
	//sprintf(name3, "eff_det_%d",i);
	strcpy(name, "");
	strcpy(name2, "");
	strcpy(name3, "");

	hit_pos_det[i] = new TH1D(name, ";position", bins, -0.5, 255.5);	//detected
	hit_fit_det[i] = new TH1D(name2, ";position", bins,-0.5, 255.5);	//expected
	h_array_eff[i] = new TH1D(name3, name3, bins, -0.5, 255.5);		//efficiency
   }
}


std::vector<double> MyLinearfit(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{  

  double Sr=0.;
  double Srz=0.;
  double Szz_r=0.;
  double Sz_r=0.; 
  double S0_r=0.; 

  double Sphi=0.;
  double Sphiz=0.;
  double Szz_phi=0.;
  double Sz_phi=0.; 
  double S0_phi=0.; 

  unsigned int  sizeHitv=hitvec.size();
  std::vector<double> r;   
  std::vector<double> z;
  std::vector<double> phi;
  std::vector<double> er;
  std::vector<double> ez;
  std::vector<double> ephi;
  double a_rz, b_rz, a_phiz, b_phiz;

  for(unsigned int jj =0; jj<sizeHitv; jj++)
    {
      //   std::cout<<hitvec[jj].GetHitX()<<" "<<hitvec[jj].GetHitPhi()<<" "<<hitvec[jj].GetHitZ()<<std::endl;
      //r->x   phi->y
      r.push_back(hitvec[jj].GetHitX());
      
      phi.push_back(hitvec[jj].GetHitY());
      z.push_back(hitvec[jj].GetHitZ());    
 
      double phirad=hitvec[jj].GetHitPhi()*3.14159/180.0;
      
      //er.push_back(0.1);
      double sigmax=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*hitvec[jj].GetHitR()*hitvec[jj].GetHitR();
      //dalla Formula di JointProb viene sigma2x=r*sigma2R
      if(UseJointProb==1)
      	sigmax=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);

      er.push_back(sqrt(sigmax));
      

      double sigmay=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitvec[jj].GetHitR()*hitvec[jj].GetHitR();
      if(UseJointProb==1)
	sigmay=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);

      ephi.push_back(sqrt(sigmay));
      
     
      //ez.push_back(hitvec[jj].GetHitDZ());
            
      Srz += r[jj]*z[jj]/er[jj]/er[jj];
      Szz_r += z[jj]*z[jj]/er[jj]/er[jj];
      Sz_r += z[jj]/er[jj]/er[jj];
      Sr += r[jj]/er[jj]/er[jj];
      S0_r += 1.0/er[jj]/er[jj];

      Sphiz += phi[jj]*z[jj]/ephi[jj]/ephi[jj];
      Szz_phi += z[jj]*z[jj]/ephi[jj]/ephi[jj];
      Sz_phi += z[jj]/ephi[jj]/ephi[jj];
      Sphi += phi[jj]/ephi[jj]/ephi[jj];
      S0_phi += 1.0/ephi[jj]/ephi[jj];

  }


  a_rz = (Srz*S0_r - Sz_r*Sr) / (Szz_r*S0_r - Sz_r*Sz_r);   // angular coefficient
  b_rz = (Sr*Szz_r - Sz_r*Srz) / (Szz_r*S0_r - Sz_r*Sz_r);  // intercept   X=(a_rz)Z + b_rz

  a_phiz = (Sphiz*S0_phi - Sz_phi*Sphi) / (Szz_phi*S0_phi - Sz_phi*Sz_phi);   // angular coefficient
  b_phiz = (Sphi*Szz_phi - Sz_phi*Sphiz) / (Szz_phi*S0_phi - Sz_phi*Sz_phi);  // intercept   


  double e_a_rz = sqrt( S0_r / (S0_r*Szz_r - Sz_r*Sz_r) );
  double e_b_rz = sqrt( Szz_r / (S0_r*Szz_r - Sz_r*Sz_r) );

  double e_a_phiz = sqrt( S0_phi / (S0_phi*Szz_phi - Sz_phi*Sz_phi) );
  double e_b_phiz = sqrt( Szz_phi / (S0_phi*Szz_phi - Sz_phi*Sz_phi) );

  std::vector<double> vect;
  for (unsigned int i=0;i<10;i++)
    vect.push_back(0.0);

  vect[0]=a_rz;
  vect[1]=b_rz;
  vect[2]=a_phiz;
  vect[3]=b_phiz;

  vect[4]=e_a_rz;
  vect[5]=e_b_rz;
  vect[6]=e_a_phiz;
  vect[7]=e_b_phiz;

  double correl=(-1.0)*Sz_r*(1.0/(S0_r*Szz_r-(Sz_r*Sz_r)));
  vect[8]=correl;
  correl=(-1.0)*Sz_phi*(1.0/(S0_phi*Szz_phi-(Sz_phi*Sz_phi)));
  vect[9]=correl;

  //std::cout<<vect[0]<<" "<<vect[1]<<" "<<vect[2]<<" "<<vect[3]<<" "<<std::endl;
  return vect;

}







std::vector<double>  ResiduiRPhi(std::vector<double> vpar,double x, double y,double z) //vpar[4]
{
  //double retdrdphi[2];
   std::vector<double> retdrdphi;
 for (unsigned int i=0;i<2;i++)
   retdrdphi.push_back(0.0);

  retdrdphi[0]=(vpar[0]*z+vpar[1]-x);
  retdrdphi[1]=(vpar[2]*z+vpar[3]-y);  
  return retdrdphi;
}





bool ExtrapolatedHitIndetector(std::vector<double> vpar, unsigned int symbdetid,unsigned int wantedhalf,unsigned int wantedarm)
{
  bool flag=false;
  double z=0.;
  double expphi;
  double expr;
  double expRaggio;

  double z1=13828.3;          //14035.605; //first Gem first drift gas zone (mm)
  double planedist= 86.0;
  double btbdist=24.6;   //25.0;
  double ovdist=43.0;
  double zinsidedet= 1.5;  
  int myhalftele= wantedhalf;
  int myplaneside= symbdetid%2;
  int myplane= symbdetid/2;
  double zdetshift=myplane*planedist+myplaneside*btbdist;

 if((myhalftele==0)&&(wantedarm==0))
   zdetshift=zdetshift+ovdist;
 
 if((myhalftele==1)&&(wantedarm==1))
   zdetshift=zdetshift+ovdist;


 z=zdetshift+z1+zinsidedet;

 if(wantedarm==1)
   z=z*(-1.0);


  expr = (vpar[0]*z+vpar[1]);
  expphi=(vpar[2]*z+vpar[3]);
  expRaggio=sqrt(expr*expr+expphi*expphi);
  
  // if((expr<144.)&&(expr>0.)) //144, 42
  if((expr<144.)&&(expr>-144.))
    {
      if((fabs(expphi)<144.)&&(fabs(expphi)>0.))
	{
	  if((expRaggio>42.)&&(expRaggio<144.))
	    {
	      flag=true;
	    }
	  else
	    std::cout<<"Raggio Aspettato Fuori det: "<<expRaggio<<std::endl;
	}
      else
	std::cout<<"Y Aspettato Fuori det: "<<expphi<<std::endl;
    }
  else
    std::cout<<"X Aspettato Fuori det:"<<expr<<std::endl;
  
  

  //if(flag==false)
  //std::cout<<"Expected hit out of detector; X="<<expr<<"Y="<<expphi<<" R="<<expRaggio  <<" Z="<<z<<"  Symb="<<symbdetid<<std::endl;
 
  return flag;
}

bool HalfTeleEfficiency(T1T2TrackCollection::const_iterator trk, std::vector<unsigned int> *planesActivity10, unsigned int wantedhalf, unsigned int wantedarm)
{
  bool flag=false;
  
  unsigned int counthitgood=0;
  std::vector<T2Hit> hitv;
  std::vector<double> vpar;

  unsigned int maxstripsize=10;
  unsigned int maxpadsize=10;
  double dphipadclu=16.0;
  unsigned int minnumhitgood=7;
  unsigned int UseJointProb=2;  
  double maxdrhit=16.0;
  double maxdphihit=16.0;
  double centrodigravitaZ=0.;//FitgravcenterZ_;//13500.;//14057.1;//14000.;
  //14057.1;
 

   for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
      {
	if((*trk).GetHitT2(a).GetHitPlane()>4)
	  std::cout<<"Warning RECO!! Plane: "<<(*trk).GetHitT2(a).GetHitPlane()<<std::endl;

	if((*trk).GetHitT2(a).GetHitHalftele()==wantedhalf)
	  if((*trk).GetHitT2(a).GetHitClass()==1)
	    if((*trk).GetHitT2(a).GetHitNumStrip()<=maxstripsize)
	      if((*trk).GetHitT2(a).GetHitNumPad()<=maxpadsize)
		if((*trk).GetHitT2(a).GetHitDPhi()<=dphipadclu)
		  {
		  
		    hitv.push_back((*trk).GetHitT2(a));
		    hitv.at(counthitgood).SetHitZ((*trk).GetHitT2(a).GetHitZ()-centrodigravitaZ);
		    counthitgood++;
		  }
      }

 
    if(counthitgood>=minnumhitgood)
      {
	vpar=MyLinearfit(hitv,UseJointProb);       
	std::vector<double>  drdphi;
	unsigned int symb;
	unsigned int countgoodhitaligned=0;

    	for(unsigned int u=0;u<10;u++)
	  {
	    (*planesActivity10).push_back(0);//0=Hit not in acceptance; 1=Efficient; 2=Inefficient;	    
	  }
    
	std::vector<T2Hit> hitv2;
	std::vector<double> vpar2; 

	for(unsigned int a=0;a<hitv.size();a++)
	  {
	    
	    drdphi=ResiduiRPhi(vpar,hitv.at(a).GetHitX(),hitv.at(a).GetHitY(),hitv.at(a).GetHitZ());
	    if(drdphi[0]<maxdrhit)
	      if(drdphi[1]<maxdphihit)
		{		
		  hitv2.push_back(hitv.at(a));		  
		  countgoodhitaligned++;
		}
	  }
    

    
	if(countgoodhitaligned>=minnumhitgood)
	  {		
	    //   onetrack.eventnumber=numevento;	
	    //onetrack.goodhitnumber=countgoodhitaligned;
	    //double chi2corr;
	    vpar2=MyLinearfit(hitv,UseJointProb);

	   
	    //std::cout<<" -  "<<vpar2[0]<<" -  "<<vpar2[1]<<" -  "<<vpar2[2]<<" -  "<<vpar2[3]<<std::endl;
	    for(unsigned int a=0;a<hitv2.size(); a++)
	      {	   
		symb=hitv2.at(a).GetHitPlane()*2+hitv2.at(a).GetHitPlaneSide();
		if((symb>9)||(hitv2.at(a).GetHitPlane()>4))
		  std::cout<<"WARNING"<<hitv2.at(a).GetHitPlane()<<hitv2.at(a).GetHitPlaneSide()<<std::endl;
		
		(*planesActivity10).at(symb)=1;//Efficient;

	      }

	    //HERE YOU SHOULD LOOP ON THE T2HIT in order to evitate TrackReco Bias (Time-Consuming?)

	
	    for(unsigned int u=0;u<10;u++)
	      {
		if((*planesActivity10).at(u)==0)		 
		  {
		    if(ExtrapolatedHitIndetector(vpar2,u,wantedhalf,wantedarm)==true) 
		      (*planesActivity10).at(u)=2;
		    //The extrapolation is inside the acceptance so the det is not efficient
		  }
	      }	    	    
	    
	    flag=true;
	  }
      }
    return flag;
}






void T2Efficiency::beginJob() {
}

void T2Efficiency::analyze(const edm::EventBase &event, const edm::InputTag &tagHitColl, const edm::InputTag &tagT1T2TrackColl)
{
  
  /*::::::Take  T2  Hits::::::*/
  Handle<T2HitCollection> t2hitcoll;
  event.getByLabel(tagHitColl, t2hitcoll);
 
  /*:::::: Take T2 tracks ::::::*/
  Handle<T1T2TrackCollection> trackCollection;
  event.getByLabel(tagT1T2TrackColl, trackCollection);

  // input valid?
  bool inputValid = true;
  inputValid &= t2hitcoll.isValid();
  inputValid &= trackCollection.isValid();

  if (!inputValid)
  {
    printf("ERROR in T2Efficiency::analyze > input handles not valid. Skipping this event.\n");

    printf("\tt2hitcoll.isValid = %i\n", t2hitcoll.isValid());
    printf("\ttrackCollection.isValid = %i\n", trackCollection.isValid());

    return;
  }

  
  ////////// E F F I C I E N C Y ///////////////
  
  
  /*
  unsigned int UseJointProb=1;
  unsigned int counthitgood=0;
  unsigned int maxstripsize=10;
  unsigned int maxpadsize=10;  
  unsigned int dphipadclu=10;
  unsigned int minnumhitgood=7;
  double centrodigravitaZ=0.0;
  */
 
  if(trackCollection->size()<4)   //High multiplicity events are not appropriate for eff. calculation
    {
      for(T1T2TrackCollection::const_iterator TrkCit=trackCollection->begin(); TrkCit!=trackCollection->end(); TrkCit++)
	{

	  //Now I look in which HalfTelescope the track is
	  bool half0=false;
	  bool half1=false;
	  bool arm0=false;
	  bool arm1=false;
	  unsigned int thehalf = 0;
	  for(unsigned int a=0;a<(*TrkCit).GetHitEntries(); a++)
	    {
	      if((*TrkCit).GetHitT2(a).GetHitHalftele()==0)
		{
		  half0=true;
		  thehalf=0;
		}
	      if((*TrkCit).GetHitT2(a).GetHitHalftele()==1)
		{
		  half1=true;
		  thehalf=1;
		}
	      if((*TrkCit).GetHitT2(a).GetHitArm()==0)
		arm0=true;
	      if((*TrkCit).GetHitT2(a).GetHitArm()==1)
		arm1=true;	    	     		  
	    }
	  //Note: one track could be in 2 halftele 
	  unsigned int Armexaminated=0;
	  if(arm0)
	    Armexaminated=0;
	  if(arm1)
	    Armexaminated=1;
	  
	  unsigned int key=Armexaminated*2+thehalf;	

	  if(half0)
	    {
	      std::vector<unsigned int> planesActivity10;
	      //Fill The plots using planesActivity10
	      if(HalfTeleEfficiency(TrkCit,&planesActivity10 ,0,Armexaminated)==true)
		{
		  if(planesActivity10.size()!=10)
		    {
		      printf("Error in the T2-Efficiency routines");
		      exit(1);
		    }
		
		  for(unsigned int pl=0;pl<planesActivity10.size();pl++)
		    {
		      if(planesActivity10.at(pl)==1)//Efficient
			{
			  plots[key].halfMeasRate->Fill(pl);		      
			  plots[key].halfExpRate->Fill(pl);
			}
		      if(planesActivity10.at(pl)==2)//Inefficient
			{
			  plots[key].halfExpRate->Fill(pl);
			}
		      //if(planesActivity10.at(pl)==0) means outside acceptance
		    }
		}
	    }

	  if(half1)
	    {
	      std::vector<unsigned int> planesActivity10;
	      if(HalfTeleEfficiency(TrkCit,&planesActivity10 ,1,Armexaminated)==true)
		{
		  if(planesActivity10.size()!=10)
		    {
		      printf ("Error in the T2-Efficiency routines");
		      exit(1);
		    }
		
		  for(unsigned int pl=0;pl<planesActivity10.size();pl++)
		    {
		      if(planesActivity10.at(pl)==1)//Efficient
			{
			  		  
			  plots[key].halfMeasRate->Fill(pl);		      
			  plots[key].halfExpRate->Fill(pl);
			}
		      if(planesActivity10.at(pl)==2)//Inefficient
			{
			 			  
			  plots[key].halfExpRate->Fill(pl);			   
			}
		      //if(planesActivity10.at(pl)==0) means outside acceptance
		    }
		}
	
	    }


	}
    }



  //////////////////////////////////////////////

}

void T2Efficiency::endJob() {
  //double x[10];
  // double y[10];
  // double ex[10];
  //double ey[10];
  for (map<unsigned int, HalfTelePlots>::iterator it = plots.begin(); it != plots.end(); ++it) {
    for(int i=0; i<10; i++) {
      //TH1D *halfMeasRate;
      //TH1D *halfExpRate;
      //TH1D *halfEffi
      //it->second.halfEffi->Divide(it->second.halfMeasRate, it->second.halfExpRate);
      // x[i]=i;
      //y[i]=halfMeasRate->GetBinContent(i+1)/halfExpRate->GetBinContent(i+1);
      //ex[i]=0;
      //ey[i]=0;
      //->GetBinContent(binx,biny)
      if((it->second.halfExpRate->GetBinContent(i+1))>0)
	{
      double ratio=(it->second.halfMeasRate->GetBinContent(i+1))/(it->second.halfExpRate->GetBinContent(i+1));
      it->second.halfEffi->SetBinContent(i+1, ratio);//bin 1 è il primo!
	}
    }
    
  }
}
