#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/QuarterTilt.h"

#include <memory>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <cmath>

#include "TFile.h"
#include "TNtuple.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TRandom.h"
#include "TF1.h"
#include "TProfile.h"
#include <fstream>

//Begin--------------------------------------Please_uncomment_this

//static void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
//double funcbteo(double xVecati,double zVecati, double ajVecati,Double_t *par);

std::vector<double>* QuarterTilt::xVecPtr= new vector<double>(); 
std::vector<double>* QuarterTilt::zVecPtr= new vector<double>(); 
std::vector<double>* QuarterTilt::bjVecPtr= new vector<double>();
std::vector<double>* QuarterTilt::ajVecPtr= new vector<double>();
std::vector<double>* QuarterTilt::ERRbjVecPtr= new vector<double>();
std::vector<double>* QuarterTilt::bjX_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::ajX_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::bjY_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::ajY_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::ErrbjX_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::ErrbjY_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::OurVzs_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::EntryX_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::EntryY_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::EntryZ_forVeloCalc= new vector<double>();
std::vector<double>* QuarterTilt::ajY_forVeloCalc_usedinX= new vector<double>();
std::vector<double>* QuarterTilt::ajX_forVeloCalc_usedinX= new vector<double>();
std::vector<double>* QuarterTilt::ajY_forVeloCalc_usedinY= new vector<double>();
std::vector<double>* QuarterTilt::ajX_forVeloCalc_usedinY= new vector<double>();

//fcn is a simple chisquare function//Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)


double QuarterTilt::funcbteo(double xVecati,double zVecati, double ajVecati,Double_t *par)
{
  double toret=xVecati-ajVecati*zVecati-par[0]*(zVecati-13872.8)-par[1]; 
  //bj_teo
  //std::cout<<" Scarto="<<toret<<":   "<<xVecati<<ajVecati<<zVecati<<std::endl;
  return toret;
}

void QuarterTilt::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  const Int_t datasize = xVecPtr->size();
   Int_t i;

   //calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   for (i=0;i<datasize; i++) {
     // std::cout<<"bjData: "<<bjVecPtr->at(i)<<" ERRbj= "<<ERRbjVecPtr->at(i);
     delta  = (funcbteo(xVecPtr->at(i),zVecPtr->at(i),ajVecPtr->at(i),par)/*-bjVecPtr->at(i)*/)/ERRbjVecPtr->at(i);
     chisq += delta*delta;     
   }
   f = chisq;
}

double QuarterTilt::fcnGrandZimpX(Double_t *par,double ExtVx_)
{
  const Int_t datasize = EntryZ_forVeloCalc->size();

  // std::cout<<"   ---------------------- "<< EntryZ_forVeloCalc->size()<<"     "<<ajY_forVeloCalc_usedinX->size()<<std::endl;

  Int_t i;
  double  GrandZimp= 0.; double C0=0.;double Z0impact=0.;
 
   for (i=0;i<datasize; i++) {  
     C0=(EntryX_forVeloCalc->at(i)*EntryX_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i))/((ajX_forVeloCalc_usedinX->at(i)-par[0])*EntryX_forVeloCalc->at(i)+ajY_forVeloCalc_usedinX->at(i)*EntryY_forVeloCalc->at(i));
     Z0impact=EntryZ_forVeloCalc->at(i)-C0;  
     //if(fillhisto) ZImpHisto_XInsidecorrector->Fill(Z0impact); 
     GrandZimp+=fabs(Z0impact);
   }
   
   return GrandZimp;
}

double QuarterTilt::fcnGrandZimpY(Double_t *par,double ExtVx_)
{
  const Int_t datasize = EntryZ_forVeloCalc->size();

  // std::cout<<"   ---------------------- "<< EntryZ_forVeloCalc->size()<<"     "<<ajY_forVeloCalc_usedinX->size()<<std::endl;

  Int_t i;
  double  GrandZimp= 0.; double C0=0.;double Z0impact=0.;
 
   for (i=0;i<datasize; i++) {  
     C0=(EntryX_forVeloCalc->at(i)*EntryX_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i))/(ajX_forVeloCalc_usedinY->at(i)*EntryX_forVeloCalc->at(i)+(ajY_forVeloCalc_usedinY->at(i)-par[0])*EntryY_forVeloCalc->at(i));
     Z0impact=EntryZ_forVeloCalc->at(i)-C0;  
     //if(fillhisto) ZImpHisto_XInsidecorrector->Fill(Z0impact); 
     GrandZimp+=fabs(Z0impact);
   }
   
   return GrandZimp;
}


double QuarterTilt::fcnVeloX(Double_t *par,double ExtVx_)
{
  const Int_t datasize = bjX_forVeloCalc->size();
  Int_t i;
  //double maxTilt=0.007;
  //double maxShift=3.0;
   //calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   Double_t bj_Teo = 0;
   for (i=0;i<datasize; i++) {  
     bj_Teo= ExtVx_ - OurVzs_forVeloCalc->at(i)*ajX_forVeloCalc->at(i)+ OurVzs_forVeloCalc->at(i)*par[0] - par[1];     
     delta  = (bjX_forVeloCalc->at(i)-bj_Teo)/ErrbjX_forVeloCalc->at(i);// You need to divide for errbj ErrbjX_forVeloCalc
     chisq += delta*delta;
     // chisq += (par[0]/maxTilt)*(par[0]/maxTilt)+(par[1]/maxShift)*(par[1]/maxShift);
   }
   
   return chisq;
}

double QuarterTilt::fcnVeloY(Double_t *par,double ExtVy_)
{
  const Int_t datasize = bjY_forVeloCalc->size();
  Int_t i;
  //double maxTilt=0.007;
  // double maxShift=3.0;
   //calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   Double_t bj_Teo = 0;
   for (i=0;i<datasize; i++) {  
     bj_Teo= ExtVy_ - OurVzs_forVeloCalc->at(i)*ajY_forVeloCalc->at(i)+ OurVzs_forVeloCalc->at(i)*par[0] - par[1];     
     delta  = (bjY_forVeloCalc->at(i)-bj_Teo)/ErrbjY_forVeloCalc->at(i);// You need to divide for errbj
     chisq += delta*delta;
     //chisq += (par[0]/maxTilt)*(par[0]/maxTilt)+(par[1]/maxShift)*(par[1]/maxShift);
   }
   
   return chisq;
}



double QuarterTilt::fcnombra(Double_t *par)
{
  const Int_t datasize = xVecPtr->size();
   Int_t i;

   //calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   for (i=0;i<datasize; i++) {
     // std::cout<<"bjData: "<<bjVecPtr->at(i)<<" ERRbj= "<<ERRbjVecPtr->at(i);
     delta  = (bjVecPtr->at(i)-(par[0]*zVecPtr->at(i) + par[1]))/ERRbjVecPtr->at(i);
       //(funcbteo(xVecPtr->at(i),zVecPtr->at(i),ajVecPtr->at(i),par)-bjVecPtr->at(i))/ERRbjVecPtr->at(i);
     chisq += delta*delta;
   }
return chisq;
  
}



//End--------------------------------------Please_uncomment_this






QuarterTilt::QuarterTilt(double T2_TrkEtamin_,double T2_TrkEtaMAX_,int T2_trkMultimin_,int T2_trkMultiMAX_,double T2_DZMultiplicator_,double T2_PhiChiProbCut_,double T2_RChiProbCut_,std::vector<unsigned int> T2_QuarterUsed_,bool XYFitUsed_,double AXTollerance_,double X0Tollerance_,double AYTollerance_,double Y0Tollerance_)
{
  T2_TrkEtamin = T2_TrkEtamin_;
  T2_TrkEtaMAX = T2_TrkEtaMAX_;
  T2_trkMultimin = T2_trkMultimin_;
  T2_trkMultiMAX = T2_trkMultiMAX_ ; 
  T2_DZMultiplicator = T2_DZMultiplicator_ ; 
  T2_PhiChiProbCut =  T2_PhiChiProbCut_;
  T2_RChiProbCut = T2_RChiProbCut_;
  // T2_QuarterUsed = T2_QuarterUsed_;

  for(unsigned int j=0;j<T2_QuarterUsed_.size();j++)
    T2_QuarterUsed.push_back(T2_QuarterUsed_.at(j));

  _T2_usesXYtracking= XYFitUsed_;
  AXTollerance=AXTollerance_;
  X0Tollerance=X0Tollerance_;
  AYTollerance=AYTollerance_;
  Y0Tollerance=Y0Tollerance_;
  std::cout<<"QuarterTilt Init:"<<std::endl;
  std::cout<<"|"<< T2_TrkEtamin <<"|"<<T2_TrkEtaMAX <<"|"<<T2_trkMultimin<<"|"<<T2_trkMultiMAX<<"|"<<T2_DZMultiplicator<<"|"<<T2_PhiChiProbCut<<"|"<<T2_RChiProbCut<<"|";

  for(unsigned int i=0;i<T2_QuarterUsed.size();i++)
    std::cout<<T2_QuarterUsed.at(i)<<"&";

  std::cout<<"|"<<_T2_usesXYtracking<<std::endl;
  
  T2CutsUtil.SetCuts(T2_TrkEtamin,T2_TrkEtaMAX,T2_trkMultimin,T2_trkMultiMAX,T2_DZMultiplicator,T2_PhiChiProbCut,T2_RChiProbCut,T2_QuarterUsed,_T2_usesXYtracking);
  /*
  xVecPtr= new vector<double>();
  zVecPtr= new vector<double>();
  bjVecPtr= new vector<double>();
  ajVecPtr= new vector<double>();
  ERRbjVecPtr= new vector<double>();
  */
  
  ZImpHisto_X= std::auto_ptr<TH1F>(new TH1F("ZImpHisto_X","ZImpHisto_X",200,-18000,18000));
  ZImpHisto_XAfterAlign= std::auto_ptr<TH1F>(new TH1F("ZImpHisto_XAfterAlign","ZImpHisto_XAfterAlign",200,-18000,18000));

  ZImpHisto= std::auto_ptr<TH1F>(new TH1F("ZImpHisto","ZImpHisto",200,-18000,18000));


  ZImpHisto_XInsidecorrector= std::auto_ptr<TH1F>(new TH1F("ZImpHisto_XInsidecorrector","ZImpHisto_XInsidecorrector",200,-18000,18000));

  ZImpHisto_Y= std::auto_ptr<TH1F>(new TH1F("ZImpHisto_Y","ZImpHisto_Y",200,-18000,18000));
  ZImpHisto_YAfterAlign= std::auto_ptr<TH1F>(new TH1F("ZImpHisto_YAfterAlign","ZImpHisto_YAfterAlign",200,-18000,18000));

  
  SelTrackXY_X= std::auto_ptr<TH2F>(new TH2F("SelTrackXY_X","SelTrackXY_X",300,-150,-150,300,-150,-150));
  SelTrackXY_Y= std::auto_ptr<TH2F>(new TH2F("SelTrackXY_Y","SelTrackXY_Y",300,-150,-150,300,-150,-150));
  


  ShiftObsY= std::auto_ptr<TProfile>(new TProfile("ShiftObsY","ShiftObsY",1000,13500.,14500,"")); 
  ShiftObsX= std::auto_ptr<TProfile>(new TProfile("ShiftObsX","ShiftObsX",1000,13500.,14500,""));

  h2Xtiltshift = std::auto_ptr<TH3F>(new TH3F("AXBX","AXBX",100,-0.008,0.008,100,-2.,2.,100,0,5000.));
  h2Xtiltshift->SetXTitle("AX (cm)");
  h2Xtiltshift->SetYTitle("BX (cm)");

  h2Ytiltshift= std::auto_ptr<TH3F>(new TH3F("AYBY","AYBY",100,-0.008,0.008,100,-2.,2.,100,0,5000.));
  h2Ytiltshift->SetXTitle("AY (cm)");
  h2Ytiltshift->SetYTitle("BY (cm)");

  VXYhisto= std::auto_ptr<TH2F>(new TH2F("VXYhisto","",100,-100,100,100,-100,100));
  VZhisto= std::auto_ptr<TH1F>(new TH1F("VZhisto","",100,-5000,5000));

  ErrXvsAx= std::auto_ptr<TH2F>(new TH2F("ErrAXvsAx","",100,-0.01,0.01,100,-0.01,0.01));
  ErrBXvsBx= std::auto_ptr<TH2F>(new TH2F("ErrBXvsBx","",100,-50,50,100,-50,50));
  //ExtVz=2000;
  ExtVz=0.001;
  ExtVy=0.005;
  ExtVx=0.005;
}






QuarterTilt::~QuarterTilt()
{
   TFile *f = TFile::Open("testqtilt.root", "recreate");
  if( !f || !f->IsWritable() ){
    std::cout << "Output file not opened correctly !!" << std::endl;
  }
 
  ZImpHisto->Write();
  ZImpHisto_XInsidecorrector->Write();
  ZImpHisto_X->Write();
  ZImpHisto_XAfterAlign->Write();
  
  ZImpHisto_Y->Write();
  ZImpHisto_YAfterAlign->Write();

  h2Xtiltshift->Write();
  h2Ytiltshift->Write();
  VXYhisto->Write();
  VZhisto->Write();

  SelTrackXY_X->Write();
  SelTrackXY_Y->Write();
 
  ShiftObsY->Write();
  ShiftObsX->Write();
  ErrXvsAx->Write();
  ErrBXvsBx->Write();
  f->Close();


}




double QuarterTilt::Nj(double axj, double bxj, double AX0, double X0)
{
  double calc=bxj+X0;
  return calc;
}

double QuarterTilt::Dj(double axj, double bxj, double AX0, double X0)
{
  double calc=axj+AX0;
  return calc;
}






//Begin --------------------------------------Please_uncomment_this
std::vector<long double> QuarterTilt::FindShiftTiltFrombj(std::vector<std::vector<T2Hit> >*theTracks, char XorY)
{

  //  double a0=0.;
  //double denj=0.;
  //double numj=0.;

  std::cout<<"Begin of  Data Loading Velo"<<std::endl;
  xVecPtr->clear(); 
  zVecPtr->clear(); 
  bjVecPtr->clear(); 
  ajVecPtr->clear(); 
  ERRbjVecPtr->clear();
  ajX_forVeloCalc->clear();
  bjX_forVeloCalc->clear();  
  ajY_forVeloCalc->clear();
  bjY_forVeloCalc->clear();
  ErrbjX_forVeloCalc->clear();
  ErrbjY_forVeloCalc->clear();

  EntryX_forVeloCalc->clear();
  EntryY_forVeloCalc->clear();  
  EntryZ_forVeloCalc->clear();
  ajY_forVeloCalc_usedinX->clear();
  ajX_forVeloCalc_usedinX->clear();
  ajY_forVeloCalc_usedinY->clear();
  ajX_forVeloCalc_usedinY->clear();


  OurVzs_forVeloCalc->clear();
  double aj=0.;
  double errbj=0.;
  double bj=0.;

  double ceckx=0.;
  double ceckz=0.;
  double ceckphi=0.;
 
  for(unsigned int j=0; j<theTracks->size();j++)
    {

      std::vector<T2Hit> hitv1 =  theTracks->at(j);
      T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitv1);

      //define the track in quarter frame   |||||||||| !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      std::vector<T2Hit> hitv =  T2CutsUtil.GetHitsInQuarterFrame(hitv1/*theTracks->at(j)*/);
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);

      EntryX_forVeloCalc->push_back((hitv1.at(0).GetHitX()));
      EntryY_forVeloCalc->push_back((hitv1.at(0).GetHitY()));
      EntryZ_forVeloCalc->push_back((hitv1.at(0).GetHitZ()));

      if(XorY=='X')
	{ 
	  
	  aj=corrFit[0];
	  bj=corrFit[1];
	  errbj=corrFit[5];//8.0;////2.0;//corrFit[5];
	  bjX_forVeloCalc->push_back(bj);
	  ajX_forVeloCalc->push_back(aj);  
	  ErrbjX_forVeloCalc->push_back(errbj);
	  ajY_forVeloCalc_usedinX->push_back(thexytrk.GetTy()/*corrFit[2]*/);
	  ajX_forVeloCalc_usedinX->push_back(thexytrk.GetTx()/*corrFit[2]*/);
 
	  OurVzs_forVeloCalc->push_back((-1.0)*T2CutsUtil.FirstPlaneForThishit(hitv.at(0))-ExtVz);//ExtVz is 0
	  // std::cout<<"+++"<<((-1.0)*T2CutsUtil.FirstPlaneForThishit(hitv.at(0)))<<((-1.0)*T2CutsUtil.FirstPlaneForThishit(hitv.at(0))-ExtVz)<<"+++"<<std::endl;
	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      ajVecPtr->push_back(aj);
	      bjVecPtr->push_back(bj);
	      ERRbjVecPtr->push_back(errbj);
	      xVecPtr->push_back(hitv.at(i).GetHitX());
	      ceckx+=(hitv.at(i).GetHitX());
	      zVecPtr->push_back(hitv.at(i).GetHitZ());
	      ceckz+=(hitv.at(i).GetHitZ());
	      ceckphi+=(hitv.at(i).GetHitPhi());
	    }	  
	}
      else
	{
	  
	  aj=corrFit[2];
	  bj=corrFit[3];
	  errbj=corrFit[7];//2.0;//corrFit[7];
	  bjY_forVeloCalc->push_back(bj);
	  ajY_forVeloCalc->push_back(aj);
	  ErrbjY_forVeloCalc->push_back(errbj);
	  ajY_forVeloCalc_usedinY->push_back(thexytrk.GetTy()/*corrFit[2]*/);
	  ajX_forVeloCalc_usedinY->push_back(thexytrk.GetTx()/*corrFit[2]*/);
	  OurVzs_forVeloCalc->push_back((-1.0)*T2CutsUtil.FirstPlaneForThishit(hitv.at(0))-ExtVz);
	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      ajVecPtr->push_back(aj);
	      bjVecPtr->push_back(bj);
	      ERRbjVecPtr->push_back(errbj);
	      xVecPtr->push_back(hitv.at(i).GetHitY());
	      zVecPtr->push_back(hitv.at(i).GetHitZ());	
	    }	 	  	  
	}
    }

  //Fai qui un plot dello Zimp delle tracce per vede che ha selezionato.
  // std::cout<<"FindShiftTiltFrombj  Data Loaded. Data Size:"<<ajVecPtr->size()<<std::endl;
  std::cout<<"FindShiftTiltFrombj  Data Loaded. Data Size:"<<OurVzs_forVeloCalc->size()<<" ZImp per trk:"<<std::endl;
  // std::cout<<"Checks on hit counters: "<<ceckx<<" "<<ceckz<<" "<<ceckphi<<std::endl;



  double amin=-0.0065;//-0.0065 for h1
  double amax=0.0065;
  double bmin=-1.5;//0.5 needed hor h1
  double bmax=1.5;
  double minx=0.;
  double miny=0.;
  //CONDITION TO CHANGE ACCORDING TO CONVERGENCE	
  double sigmaZImp=3000.;double dump=5.;

  if(XorY=='X')
    {
     
      unsigned int steps=400.0;
      double stepinx=(amax-amin)/steps;
      double stepiny=(bmax-bmin)/steps;
      double xval,yval;
      double param[2];
      double w=0.;
      double wZimp=0.;
      double Combw=0.;
      // std::cout<<"here.. "<<std::endl;
      
      param[0]=minx;
      param[1]=miny;
      // double fmin=sqrt(fcnombra(param));
    
      ///////////
      bool fillhisto=false;
      if(ZImpHisto_XInsidecorrector->GetEntries()==0)
	fillhisto=true;
      unsigned int i=0;
      if(fillhisto)
      for (i=0;i<EntryX_forVeloCalc->size(); i++) {  
	double C0=(EntryX_forVeloCalc->at(i)*EntryX_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i)+EntryY_forVeloCalc->at(i))/(ajX_forVeloCalc->at(i)*EntryX_forVeloCalc->at(i)+ajY_forVeloCalc_usedinX->at(i)*EntryY_forVeloCalc->at(i));
	double Z0impact=EntryZ_forVeloCalc->at(i)-C0;  
	//if(EntryZ_forVeloCalc->at(i)>0)
	//std::cout<<"errorrrrrr"<<std::endl;
	ZImpHisto_XInsidecorrector->Fill(Z0impact); 	
      }
      /////////////////



      double fmin=sqrt(fcnVeloX(param,ExtVx))/dump+(fcnGrandZimpX(param,ExtVx))*(1/sigmaZImp);
      //bj_Teo= ExtVx_ - OurVzs_forVeloCalc->at(i)*ajX_forVeloCalc->at(i)+ OurVzs_forVeloCalc->at(i)*par[0] - par[1];   
      for(unsigned int x=0;x<steps;x++)
	{
	  //  std::cout<<"["<<x<<"] step"<<std::endl;
	  for(unsigned int y=0;y<steps;y++)
	    {
	      xval=amin+x*stepinx;
	      yval=bmin+y*stepiny;
	      param[0]=xval;
	      param[1]=yval;

	      w=sqrt(fcnVeloX(param,ExtVx))/dump;
	      wZimp=(fcnGrandZimpX(param,ExtVx))*(1/sigmaZImp);

	      Combw=w+wZimp;
	      h2Xtiltshift->Fill(xval, yval, Combw);
	      // std::cout<<xval<<" "<<yval<<" ..............: "<< w<< " "<<wZimp<<std::endl;
	      if(Combw<fmin)
		{
		  minx=xval;
		  miny=yval; 
		  fmin=Combw;
		}
	      
	    }
	}
      std::cout<<"MinimumX = "<<fmin<<" found  at AX="<<minx<<" BX="<<miny<<" Weight contributions: "<<w<<" "<<wZimp<<std::endl;
    }
  else
    {

      // sigmaZImp=30000.;double dump=1.;
      unsigned int steps=400.0;
      double stepinx=(amax-amin)/steps;
      double stepiny=(bmax-bmin)/steps;
      double xval,yval;
      double param[2];
      double w=0.;
      double wZimp=0.;
      double Combw=0.;
      // std::cout<<"here.. "<<std::endl;
      
      param[0]=minx;
      param[1]=miny;
      // double fmin=sqrt(fcnombra(param));
      // double fmin=sqrt(fcnVeloY(param,ExtVy));
      double fmin=sqrt(fcnVeloY(param,ExtVx))/dump+(fcnGrandZimpY(param,ExtVx))*(1/sigmaZImp);
      for(unsigned int x=0;x<steps;x++)
	{
	  //  std::cout<<"["<<x<<"] step"<<std::endl;
	  for(unsigned int y=0;y<steps;y++)
	    {
	      xval=amin+x*stepinx;
	      yval=bmin+y*stepiny;
	      param[0]=xval;
	      param[1]=yval;


	      //w=sqrt(fcnombra(param));
	      w=sqrt(fcnVeloY(param,ExtVy))/dump;
	      wZimp=(fcnGrandZimpY(param,ExtVx))*(1/sigmaZImp);
	      Combw=w+wZimp;
	      // std::cout<<xval<<" "<<yval<<"   -->  "<<w<<" "<<wZimp<<std::endl;
	      h2Ytiltshift->Fill(xval, yval, Combw);	     
	      if(Combw<fmin)
		{
		  minx=xval;
		  miny=yval; 
		  fmin=Combw;
		}
	      
	    }
	}
      std::cout<<"MinimumY = "<<fmin<<" found  at AY="<<minx<<" BY="<<miny<<" Weight contributions: "<<w<<" "<<wZimp<<std::endl;
    }

  std::vector<long double> toret;
  
  //Calling function expect B-A
  toret.push_back(miny);
  toret.push_back(minx);

  return toret;

}
//End FindShiftTiltFrombj











std::vector<long double> QuarterTilt::FindQuarterShiftTilt(unsigned int quarterNumb)
{  
  //   NewtonMethodTest();
  unsigned int MaxStepalignstep=40;
  unsigned int alignstep=0;
  bool alignReached=false;
    
  std::vector<long double> DisalignVectX, DisalignVectY;
  //std::vector<long double> OldDisalignVectX,OldDisalignVectY;
  
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALF;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALALL;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY;
  //unsigned int quarterid;
  unsigned int hh;
  for(unsigned int j=0;j<trackutilizedforalignment.size();j++)
    {
      planeinfo=conv.GetT2Info(trackutilizedforalignment.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;

      if(hh==quarterNumb)
	{
	  bool Xtrckcomp=false;bool Ytrckcomp=false;
	  

	  std::vector<T2Hit> hitsintrk=trackutilizedforalignment.at(j);
	  T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitsintrk);

	  double dthetaX=fabs(thexytrk.GetTxSigma()-(trackutilizedforalignment.at(j).at(0).GetHitX()/fabs(trackutilizedforalignment.at(j).at(0).GetHitZ())));	    	    
	  if(dthetaX<0.015) 
	    Xtrckcomp=true;

	  double dthetaY=fabs(thexytrk.GetTySigma()-(trackutilizedforalignment.at(j).at(0).GetHitY()/fabs(trackutilizedforalignment.at(j).at(0).GetHitZ())));	    	    
	  if(dthetaY<0.015) 
	    Ytrckcomp=true;
	 

	  //std::cout<<thexytrk.GetTxSigma()<<" "<<thexytrk.GetTySigma()<<" || "<<std::endl;
	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitX()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.7)	
	    if(trackutilizedforalignment.at(j).at(0).GetHitR()<140)
	      if((thexytrk.GetTxSigma()<0.002)&&(thexytrk.X0Sigma()<40))
		if(Xtrckcomp){
		
		  double C0=(thexytrk.GetHitT2(0).GetHitX()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetHitT2(0).GetHitY()*thexytrk.GetHitT2(0).GetHitY())/(thexytrk.GetTx()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetTy()*thexytrk.GetHitT2(0).GetHitY());
		  double Z0impact=thexytrk.GetHitT2(0).GetHitZ()-C0;
		  // if((((quarterNumb)==3)&&(fabs(thexytrk.GetHitT2(0).GetHitY())<20.))||((quarterNumb)!=3))//Used for 1	
		  if(fabs(Z0impact)<7000.)
		  {
			  ZImpHisto_X->Fill(Z0impact);
			  trackutilizedforalignmentONEHALFX.push_back(trackutilizedforalignment.at(j));	
			  SelTrackXY_X->Fill(thexytrk.GetHitT2(0).GetHitX(),thexytrk.GetHitT2(0).GetHitY());
		  }
		}

	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitY()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.7)
	    if(trackutilizedforalignment.at(j).at(0).GetHitR()<140)//	    if(trackutilizedforalignment.at(j).at(0).GetHitR()>80)  
	      if((thexytrk.GetTySigma()<0.002)&&(thexytrk.Y0Sigma()<40))
		if(Ytrckcomp)
		  {		
		    
		    double C0=(thexytrk.GetHitT2(0).GetHitX()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetHitT2(0).GetHitY()*thexytrk.GetHitT2(0).GetHitY())/(thexytrk.GetTx()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetTy()*thexytrk.GetHitT2(0).GetHitY());
		    double Z0impact=thexytrk.GetHitT2(0).GetHitZ()-C0;
		    std::cout<<Z0impact<<" "<<thexytrk.GetHitT2(0).GetHitY()<<" "<<thexytrk.GetTySigma()<<" "<<thexytrk.Y0Sigma()<<" "<<thexytrk.GetTy()<<" "<<thexytrk.Y0()<<std::endl;
		    
		    //CONDITION TO CHANGE ACCORDING TO CONVERGENCE		   
		    
		    // if((((quarterNumb)==3)&&(thexytrk.GetHitT2(0).GetHitX()>-10.))||((quarterNumb)!=3))
		    if(fabs(Z0impact)<7000.)
		      {
			ZImpHisto_Y->Fill(Z0impact);
			trackutilizedforalignmentONEHALFY.push_back(trackutilizedforalignment.at(j));
			SelTrackXY_Y->Fill(thexytrk.GetHitT2(0).GetHitX(),thexytrk.GetHitT2(0).GetHitY());
		      }
 
		  }
	  trackutilizedforalignmentONEHALALL.push_back(trackutilizedforalignment.at(j));
	  //if(trackutilizedforalignment.at(j).at(0).GetHitY()>0)
	}
    }

  //QuarterId:  0  TiltX:  0.0033  TiltY:  -0.002  ShiftX0: -2.0   ShiftY0:  -2.0

  std::cout << "Alignment for Tilt will work with tracks extrated from the full event sample of"<<trackutilizedforalignment.size()<<" tracks."<<" [Trk in X proj="<<trackutilizedforalignmentONEHALFX.size()<<" Trk in Y proj="<<trackutilizedforalignmentONEHALFY.size()<<"]"<<std::endl;

 


  //long double Shifty;
  //long double Shiftx;

  DisalignVectX.push_back(0.0);//Ax
  DisalignVectX.push_back(0.0);//X0
  
  DisalignVectY.push_back(0.0);
  DisalignVectY.push_back(0.0);

  std::vector<long double> ToReturnX, ToReturnY;

  ToReturnX.push_back(0.0);
  ToReturnX.push_back(0.0);

  ToReturnY.push_back(0.0);
  ToReturnY.push_back(0.0);
  
 
  //-------------------------------------------------------------
  // Start to iterate over the each-time-updated track parameters
  //-------------------------------------------------------------

  char XorY;
  double axj,bxj;
  double CorrectionToaxj,CorrectionTobxj;

  
  for(unsigned int fromxtoy=0;fromxtoy<2;fromxtoy++)
    {
    
    
      alignReached=false;
      // bool stopnext=false;
      if(fromxtoy==0)
	{
	  XorY='X';
	  trackutilizedforalignmentONEHALF.clear();
	  trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFX;	  
	}
      else
	{
	  XorY='Y';
	  trackutilizedforalignmentONEHALF.clear();
	  trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFY;
	}
      alignstep=0;
      MaxStepalignstep=40;

      //TestNewton(&trackutilizedforalignmentONEHALF);

      while((alignstep<MaxStepalignstep)&&(alignReached==false))
	{
	  
	  std::cout <<" *********" <<std::endl;
	  std::cout <<" *********" <<std::endl;
	  //Align Tilts/Shifts
	  std::vector<long double> DisalignVector;
	  std::vector<long double> DisalignVectorOtherChecks;
	  DisalignVector.push_back(0.);DisalignVector.push_back(0.);	  
	  DisalignVectorOtherChecks.push_back(0.);DisalignVectorOtherChecks.push_back(0.);

	  std::cout <<"Working the "<< XorY << " projetion in Main Loop: Alignment Step "<< alignstep<<" size: "<<trackutilizedforalignmentONEHALF.size()<<std::endl;
	  
	  //ExtVz=ExtVz/VtxTrkInEvt.size();
	  //std::cout <<"VZ position: "<<ExtVz<<std::endl;
	  double ExtVzlast;
	  if(alignstep==0)
	    ExtVzlast=10000;
	  else
	    ExtVzlast=ExtVz;
	  
	  ExtVz=T2CutsUtil.FindAverageTrackZ(&trackutilizedforalignmentONEHALF,  XorY);
	  //ExtVz=ExtVz/2;
	  ExtVz=0.1;//300.;//Funzionava bene a 400-600!
	  std::cout <<"VZ position: "<<ExtVz<<" Last position:"<<ExtVzlast<<std::endl;

	  DisalignVector=FindShiftTiltFrombj(&trackutilizedforalignmentONEHALF,  XorY);
	  //Here I want the detector shift and Tilt while the function return the track correction in order to have b=0.
	  //So if returned BX<0=>SHiftXdet=-BX While SignAX_Correction=Sign_DetRotation
	  
	  
	  DisalignVector.at(0)=DisalignVector.at(0);
	  DisalignVector.at(1)=DisalignVector.at(1);

	  //Note: in the simulation Instead Tilt_X put=-Tilt_X_det while ShiftX_put=Shift_det maybe not true anymore
	  //While the Reco-Hit correction procedure wants the  the Detector shift and Tilt
	  std::cout <<"Hit Parameter Correction used: Detector A"<<XorY<<"  B"<<XorY<<" = "<<DisalignVector.at(1)<<"  "<<DisalignVector.at(0)<<std::endl;

	  bool correctslope=true;
	  bool correctintercept=true;
	
	  
	  std::cout << XorY <<" In Main Loop iterations has been returned a-B=  " <<DisalignVector.at(1)<<" | "<<DisalignVector.at(0)<<  std::endl;
	  double stopvalue=0.0003;//=0.0003;
	  
	  if(DisalignVector.size()==2)
	    {
	      if(XorY=='X')
		{
		  
		  DisalignVectX= DisalignVector;
		  if((fabs(DisalignVectX.at(1))>stopvalue))
		    {		      
		      ToReturnX.at(1)+=DisalignVectX.at(1);
		      ToReturnX.at(0)+=DisalignVectX.at(0);
		      std::cout<<"Total misal value updated"<<std::endl;
		    }
		  else
		    {
		      correctslope=false;
		      std::cout<<"Total misal value SMALL... FINISH!!!"<<std::endl;
		    }
	
		  
		  std::cout<<".. Now  Total A"<<XorY<<"= "<<ToReturnX.at(1);
		  std::cout<<"..  Total B"<<XorY<<"= "<<ToReturnX.at(0)<<std::endl;
		  		 
		  if((fabs(DisalignVectX.at(1))<stopvalue)&&(fabs(DisalignVectX.at(0))<3.)) //was <0.5 
		    {
		      alignReached=true;	
		      std::cout<<" Global "<<XorY<<" align reached! "<<DisalignVectX.at(1)<<" "<<(DisalignVectX.at(0))<<std::endl;
		    
		    }
		  else
		    alignReached=false;
		}

	      if(XorY=='Y')
		{
		  DisalignVectY= DisalignVector;

		  if((fabs(DisalignVectY.at(1))>stopvalue))
		    {		      
		      ToReturnY.at(1)+=DisalignVectY.at(1); 
		      ToReturnY.at(0)+=DisalignVectY.at(0);
		      std::cout<<"Total misal value updated"<<std::endl;
		    }
		  else
		    {
		      correctslope=false;
		      std::cout<<"Total misal value SMALL... FINISH!!!"<<std::endl;
		    }

		  std::cout<<".. Now  Total A"<<XorY<<"= "<<ToReturnY.at(1);
		  std::cout<<"..  Total B"<<XorY<<"= "<<ToReturnY.at(0)<<std::endl;

		  if((fabs(DisalignVectY.at(1))<stopvalue)&&(fabs(DisalignVectY.at(0))<2.))//0.00036
		    {		      		      
		      //ToReturnX.at(0)+=DisalignVectX.at(0);
		      //correctintercept=false;
		      alignReached=true;	
		      std::cout<<" Global "<<XorY<<" align reached! "<<DisalignVectY.at(1)<<" "<<(DisalignVectY.at(0))<<std::endl;
		    
		    }
		  else
		    alignReached=false;
		  /*
		  std::cout<<"..    Updating Total A"<<XorY<<"= "<<ToReturnY.at(1);
		  std::cout<<"..    Total B"<<XorY<<"= "<<ToReturnY.at(0)<<std::endl;
		  		  
		  //if((fabs(DisalignVectY.at(0))<Y0Tollerance)&&(fabs(DisalignVectY.at(1))<AYTollerance))
		  //if(fabs(ExtVzlast-ExtVz)<200)	
		  if((fabs(DisalignVectY.at(1))<stopvalue)&&(fabs(DisalignVectY.at(0))<0.5)) 		  	   
                    {
		      alignReached=true;		     
		      std::cout<<" Global "<<XorY<<" align reached! "<<DisalignVectY.at(1)<<" "<<(DisalignVectY.at(0))<<std::endl;
		      // ToReturn.push_back(DisalignVectY.at(0));
		      // ToReturn.push_back(DisalignVectY.at(1));
		    }
		  else
		    alignReached=false;
		  */
		}

	      

	      std::cout<<"Correction because alignReached= "<<alignReached<<". Now I will correct the track"<<std::endl;
	      CorrectionToaxj=0.;
	      CorrectionTobxj=0.;
	      
		for(unsigned int k=0; k<trackutilizedforalignmentONEHALF.size();k++)
		  {
	
		    std::vector<T2Hit> hitv=trackutilizedforalignmentONEHALF.at(k);		    
		    std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
		    std::vector<double> Trkparameter;

		    if(XorY=='X')
		      {
		
			axj= corrFit.at(0); 
			bxj= corrFit.at(1);
		
			if(correctslope)
			  {
			    //CorrectionToaxj= DisalignVectX.at(1);
			    CorrectionToaxj= DisalignVectX.at(1)*(-1.0);			    
			    //   std::cout<<"going to correct for ax= "<<CorrectionToaxj<<std::endl;
			  }
			
			if(correctintercept)
			  {
			    
			    //CorrectionTobxj= DisalignVectX.at(0); 
			    CorrectionTobxj= DisalignVectX.at(0)*(-1.0);
			    //   std::cout<<"going to correct for bx= "<<CorrectionTobxj<<std::endl;
			  }
			//DisalignVectX.at(0) +=bxj;   
			//DisalignVectX.at(1) +=axj;    
		      }
		    
		    if(XorY=='Y')
		      {
		
			axj= corrFit.at(2); 
			bxj= corrFit.at(3);
			if(correctslope)
			  CorrectionToaxj= DisalignVectY.at(1)*(-1.0);
			if(correctintercept)
			  CorrectionTobxj= DisalignVectY.at(0)*(-1.0);
			//DisalignVectY.at(0)+=bxj;
			//DisalignVectY.at(1)+=axj;
		      }
		  
		    //if(fabs(CorrectionTobxj)>4.6)
		    //CorrectionTobxj=0.;
		    //std::cout<<"Tacks";
		    std::vector<T2Hit> theTrkUpdated;
		    // CorrectionToaxj=-0.002;
		    theTrkUpdated=UpdateThisTrk(hitv,axj,bxj,CorrectionToaxj,CorrectionTobxj,XorY);
		    T1T2Track thenewTrk=T2CutsUtil.TrackFromHits(true, theTrkUpdated);
		   
		    trackutilizedforalignmentONEHALF.at(k).clear();
		    trackutilizedforalignmentONEHALF.at(k)=theTrkUpdated;
		    //std::cout<<" ... updated";
		  }
	
	    }
	  else
	    std::cout<<"WARNING: newton method does not work"<<std::endl;
	 
	  alignstep++;	  
	}//While end
      

      //std::cout<<"Exit from align finding...Now  look at Shift1DSimpleDifference"<<std::endl;
      

 
      
      //Recopy the updated track
      if(fromxtoy==0)
	{
	  //XorY='X';
	  trackutilizedforalignmentONEHALFX=trackutilizedforalignmentONEHALF;
	  //Shiftx=Shift1DSimpleDifference(&trackutilizedforalignmentONEHALFX,XorY);//1D
	  //std::cout<<XorY<<" shift= "<<Shiftx<<std::endl;
	}
      else
	{
	  // XorY='Y';
	  trackutilizedforalignmentONEHALFY=trackutilizedforalignmentONEHALF;
	  //Shifty=Shift1DSimpleDifference(&trackutilizedforalignmentONEHALFY,XorY);//1D
	  //std::cout<<XorY<<" shift= "<<Shifty<<std::endl;
	}
      std::cout<<"Projected Trk updated..."<<std::endl;
   

    }//loop from x to y end

  


 std::cout<<"Zimp X plots..."<<std::endl;
   

  for(unsigned int j=0;j<trackutilizedforalignmentONEHALFX.size();j++)
    {
      planeinfo=conv.GetT2Info(trackutilizedforalignmentONEHALFX.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;
      
      if(hh==quarterNumb)
	{
	 
	  std::vector<T2Hit> hitsintrk=trackutilizedforalignmentONEHALFX.at(j);
	  T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitsintrk);
	  
	  
	  double C0=(thexytrk.GetHitT2(0).GetHitX()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetHitT2(0).GetHitY()*thexytrk.GetHitT2(0).GetHitY())/(thexytrk.GetTx()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetTy()*thexytrk.GetHitT2(0).GetHitY());
	  double Z0impact=thexytrk.GetHitT2(0).GetHitZ()-C0;
	 
	  ZImpHisto_XAfterAlign->Fill(Z0impact);
	  
	  //if(trackutilizedforalignment.at(j).at(0).GetHitY()>0)
	}
    }
 

 std::cout<<"Zimp Y plots..."<<std::endl;
   
 for(unsigned int j=0;j<trackutilizedforalignmentONEHALFY.size();j++)
    {
      planeinfo=conv.GetT2Info(trackutilizedforalignmentONEHALFY.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;
      
      if(hh==quarterNumb)
	{
	 
	  std::vector<T2Hit> hitsintrk=trackutilizedforalignmentONEHALFY.at(j);
	  T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitsintrk);
	  
	  
	  double C0=(thexytrk.GetHitT2(0).GetHitX()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetHitT2(0).GetHitY()*thexytrk.GetHitT2(0).GetHitY())/(thexytrk.GetTx()*thexytrk.GetHitT2(0).GetHitX()+thexytrk.GetTy()*thexytrk.GetHitT2(0).GetHitY());
	  double Z0impact=thexytrk.GetHitT2(0).GetHitZ()-C0;
	 
	  ZImpHisto_YAfterAlign->Fill(Z0impact);
	  
	  //if(trackutilizedforalignment.at(j).at(0).GetHitY()>0)
	}
    }
 

 std::cout<<ToReturnX.size()<<" "<<ToReturnY.size()<<std::endl;


   std::vector<long double> ToReturn;
  //ToReturn= (AX,X0,AY,Y0)
   ToReturn.push_back(ToReturnX.at(1));
   ToReturn.push_back(ToReturnX.at(0));
   //ToReturn.push_back(Shiftx);
   ToReturn.push_back(ToReturnY.at(1));
   ToReturn.push_back(ToReturnY.at(0));
   //ToReturn.push_back(Shifty);

  if(ToReturn.size()==4)
    std::cout<<"RETURNED Detector Misalignments Found: AX | X0 | AY | Y0 ="<<ToReturn.at(0)<<" | "<<ToReturn.at(1)<<" | "<<ToReturn.at(2)<<" | "<<ToReturn.at(3)<<std::endl;
  else
    std::cout<<"ERROR Size of vector returned from Tilt-alignment procedure not correct!"<<std::endl;

  
  return ToReturn;
  
}





std::vector<T2Hit> QuarterTilt::UpdateThisTrk(std::vector<T2Hit> hitv,double origaxj,double origbxj,double CorrectionToaxj,double CorrectionTobxj,char XorY)
{
  // Note
  // roadYfit[k].at(g).SetHitY(roadYfit[k].at(g).GetHitY()-(DYi.at(symbolic2)/SHIFTprescale));
  // The formula you used is as the following: f(trk par +corr) = minimum. So you have to add the correction
  // parameter and not to subctract as for the internal alignment.

  // std::cout<<"Trk update size: "<<hitv.size()<<std::endl;
  planeinfo=conv.GetT2Info(hitv.at(0).GetHitDetRawId());
  unsigned int quarterid=(planeinfo.symb/10);
  
  planeinfo=conv.GetT2Info(quarterid*10);  
  double firstplanez=planeinfo.Zdet;
  // std::cout<<"  "<<firstplanez<<std::endl;
  double toadd=0.;    
  for (unsigned int k=0;k<hitv.size();k++)
    {
      planeinfo=conv.GetT2Info(hitv.at(k).GetHitDetRawId());
      double planez=planeinfo.Zdet;
      //  double before=0.;
      //   double after=0.;
      /*
      if(XorY=='X')
	{
	  toadd=(planez-firstplanez)*axj+bxj;
	  hitv.at(k).SetHitX(toadd);
	}
      else
	{
	  toadd=(planez-firstplanez)*axj+bxj;
	  hitv.at(k).SetHitY(toadd);
	  }
      */
      
      //recalculate Hit vector from trk fitting
      if(XorY=='X')
	{
	  toadd=(planez-firstplanez)*CorrectionToaxj*(1.0)+CorrectionTobxj;
	  // toadd=planez*CorrectionToaxj+CorrectionTobxj;
	  // before=hitv.at(k).GetHitX();
	  hitv.at(k).SetHitX(toadd+hitv.at(k).GetHitX());
	  // after=hitv.at(k).GetHitX();
	  //std::cout<<"@Z= "<<planez<<" Hit "<<XorY<<" before: "<<before<<" after: "<<after<<std::endl;
	}
      else
	{
	  toadd=(planez-firstplanez)*CorrectionToaxj*(1.0)+CorrectionTobxj;
	  //toadd=planez*CorrectionToaxj+CorrectionTobxj;
	  //before=hitv.at(k).GetHitY();
	  //std::cout<<"    Global hit-y correction: "<<toadd;
	  hitv.at(k).SetHitY(toadd+hitv.at(k).GetHitY());
	  //after=hitv.at(k).GetHitY();
	}
      
      //std::cout<<"|  CorrAdded: "<<(before-after);

      double rr=sqrt(hitv.at(k).GetHitY()*hitv.at(k).GetHitY()+hitv.at(k).GetHitX()*hitv.at(k).GetHitX());
      
      
      hitv.at(k).SetHitR(rr);

      double yy=hitv.at(k).GetHitY();
      double xx=hitv.at(k).GetHitX();
      //      double phi=0.0;
      
      //In T2DetHitRec: x-y=Rcos-sin phi 
      //Not consistent with CMS but only with Hit X definition starting from phi

      double expY_2=yy;
      double expX_2=xx;

      double expPhi_2=atan(fabs(expY_2)/fabs(expX_2));
      expPhi_2=expPhi_2*180.0/3.14159;				    
      if((expY_2<0)&&(expX_2>0))
	expPhi_2=360.0-expPhi_2;
      
      if((expY_2>0)&&(expX_2<0))
	expPhi_2=180.0-expPhi_2;
	//expPhi_2=expPhi_2+90.;
      
      if((expY_2<0)&&(expX_2<0))
	expPhi_2=expPhi_2+180.;

      /*
      if(yy>=0)
	phi = acos (xx/rr) * 180.0 / 3.14159265;          //acos: Principal arc cosine of x, in the interval [0,pi] radians.
      else
	phi = 180.0 + acos (xx/rr) * 180.0 / 3.14159265;     
      */

      //std::cout<<" <"<<hitv.at(k).GetHitPhi();
      hitv.at(k).SetHitPhi(expPhi_2);
      //std::cout<<"  "<<hitv.at(k).GetHitPhi()<<"> ";
    }


  return hitv;
}



void QuarterTilt::StoreEventtTrks(const T1T2TrackCollection* t2_trackCollection, bool UseGlobVertexForTrkSelection, bool h0cond,bool h1cond,bool h2cond,bool h3cond)
{


  //bool _T2_usesXYtracking=true;

  //bool flag=false;
  std::vector<T1T2Track> t2trackVector;
  T1T2TrackCollection::const_iterator TC_it2;
  unsigned int trksize=0;

  for(TC_it2=t2_trackCollection->begin(); TC_it2!=t2_trackCollection->end(); TC_it2++){

    trksize++;
    std::vector<T2Hit> hitsintrk;
    int cl1hitMult=0;
    
    for (unsigned int j=0;j<(*TC_it2).GetHitEntries();j++){
      hitsintrk.push_back((*TC_it2).GetHitT2(j));
      if((*TC_it2).GetHitT2(j).GetHitClass()==1)
	cl1hitMult++;
    }

    int quarterAn=T2_QuarterUsed.at(0);
    std::vector<T2Hit> hitsintrk2=T2CutsUtil.HitsFromTrkInOneQuarter(hitsintrk,quarterAn);
    // std::cout<<" .. ->-> "<<hitsintrk.size()<<std::endl;
    T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitsintrk);
   
    //  std::cout<<(*TC_it2).GetHitEntries()<<" "<<thexytrk.GetHitEntries()<<" "<<thexytrk.GetTx()<<" "<<thexytrk.GetTy()<<" "<<thexytrk.Eta()<<" "<<thexytrk.Z_at_Rmin()<<std::endl;

    // if(T2CutsUtil.AcceptThisT2Track(thexytrk)) -> Mod on 7 May 010
    //if(T2CutsUtil.AcceptThisT2TrackWhatEverQuarter(thexytrk))

    bool proceed=false;
    if((h0cond && (quarterAn==0))||(h1cond && (quarterAn==1))||(h2cond && (quarterAn==2))||(h3cond && (quarterAn==3)))
      proceed=true;
    
    if(cl1hitMult>=7)
      if(proceed)//if(T2CutsUtil.AcceptThisT2Track(thexytrk))//modif on 06/19/2015
	{
	  t2trackVector.push_back(thexytrk);
	  trackutilizedforalignment.push_back(hitsintrk);
	}
  }

 
  //  else
  //std::cout<<"No Vertex found in the event"<<std::endl;

  //std::cout<<"Track stored in QuarterTilt::StoreEventtTrks"<<std::endl;
  
  // return flag;
}







void QuarterTilt::SaveTiltsinFile(std::map<unsigned int,std::vector<long double> >  half_VS_AX_X0_AY_Y0, fstream* fileop)
{
  std::cout<<"Saving Tilts in a file.."<<std::endl;
  // char str[] = "\n";
  //(*fileop).seekg(ios::end);
  //(*fileop) <<str;

  if(((*fileop).is_open())==false)
    {
      std::cout<<"ERROR: Problem in opening file"<<std::endl;
      (*fileop).clear();
    }
  (*fileop) << " \n";

  std::map<unsigned int,std::vector<long double> >::iterator it;
  for(it = half_VS_AX_X0_AY_Y0.begin(); it != half_VS_AX_X0_AY_Y0.end(); ++it)
    {
      (*fileop)<<" \n";
      int half=it->first;
      (*fileop)<<"QuarterId:  "<<half;
      if((it->second).size()==4)
	{
	  long double AX=(it->second).at(0);
	  long double AY=(it->second).at(2);
	  long double BX=(it->second).at(1);
	  long double BY=(it->second).at(3);
	  (*fileop)<<"  TiltX:  "<<AX;
	  (*fileop)<<"  TiltY:  "<<AY;
	  (*fileop)<<"  ShiftX0:  "<<BX;
	  (*fileop)<<"  ShiftY0:  "<<BY;
	}
      else
	std::cout<<"Error: vector Tilt/shift.size != 4D !!!"<<std::endl;
        //cout << "(key = first): " << it->first;
        //cout << "(value = second): " << it->second << '\n';
    }
  
}











































































































////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////











































































































std::vector<long double> QuarterTilt::NewtonStep1D(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  
  //Find Tilt displacement
  double a0=0.;
  double denj=0.;
  double numj=0.;
  for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);      
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
      double aj=0.;
      double errbj=0.;
     
      double x_av_j=0.;
      double y_av_j=0.;
      double z_av_j=0.;
      
      double Nj=hitv.size();
      Nj=1.0;

      if(XorY=='X')
	{ 
	  aj=corrFit[0];
	  errbj=corrFit[5];
	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      x_av_j+=hitv.at(i).GetHitX();
	      z_av_j+=hitv.at(i).GetHitZ();	
	    }
	  x_av_j=x_av_j/Nj;
	  z_av_j=z_av_j/Nj;
	  

	  numj+=(1.0/errbj)*(1.0/errbj)*(1.0/Nj)*(1.0/Nj)*(x_av_j*z_av_j - aj*z_av_j*z_av_j);
	  denj+= (1.0/errbj)*(1.0/errbj)*(1.0/Nj)*(1.0/Nj)* z_av_j*z_av_j;
	 
	  
	}
      else
	{
	  aj=corrFit[2];
	  errbj=corrFit[7];

	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      y_av_j+=hitv.at(i).GetHitY();
	      z_av_j+=hitv.at(i).GetHitZ();	
	    }
	  y_av_j=y_av_j/Nj;
	  z_av_j=z_av_j/Nj;
	  

	  numj+=(1.0/errbj)*(1.0/errbj)*(1.0/Nj)*(1.0/Nj)*(y_av_j*z_av_j - aj*z_av_j*z_av_j);
	  denj+= (1.0/errbj)*(1.0/errbj)*(1.0/Nj)*(1.0/Nj)* z_av_j*z_av_j;
	  
	}

      //double rnax=StartingPointTheta(theTracks,XorY);      
	
    }
  a0=(numj/denj);
  
  

  std::vector<long double>  retvecAlignPar;
  retvecAlignPar.push_back(0.);
  retvecAlignPar.push_back(a0);
  return retvecAlignPar;

}
//End NewtonStep1D

std::vector<long double> QuarterTilt::NewtonStep(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  std::vector<long double> retvecAlignPar;
  // std::cout<<"NewtonStep.."<<std::endl;
  std::vector<TMatrixD> Js;  // one 2x2 matrix for each detector (2=number of incognite X0, ThetaX)
  std::vector<TVectorD> Fs;
  unsigned int maxnewtoniter=280;
  TRandom *ran1 = new TRandom();

  //      double rnx0;
      double rnax;
      
      //rnx0=ran1->Uniform(-1,1);
      
      rnax=ran1->Uniform(-100,100);
      
      
      //  rnax=StartingPointTheta(theTracks,XorY);
      std::vector<long double>  AlignPar1d=NewtonStep1D(theTracks,XorY);
      rnax=AlignPar1d.at(1);
      std::cout<<"TanTheta"<<XorY<<"starting point: "<<rnax<<std::endl;
      	
      TVectorD Parbefore(2);
      Parbefore(0)=0.;//rnx0;//0.;//rnx;//Metti un random
      Parbefore(1)=rnax;//rnax;//0.;//rny;    
      TVectorD  Parafter(2); //X0,AX0
      
      Parafter=Parbefore;
      bool exitnewton=false;
      unsigned int counter=0;
      double X0=0.;
      double AX0=0.;
      double bxj=0.;
      double axj=0.;
      double sigmaZj=100.0; // a costant value, to be implemented better.

      std::vector<double> lastX0s;

      while((exitnewton==false)&&(counter<maxnewtoniter))
	{
	   
	  TMatrixD oneJ(2,2);
	  TVectorD oneF(2);
	  oneF.Zero();
	  oneJ.Zero();
	 
	  //double oneJ1Var=0.;
	  // double oneF1Var=0.;
	 
	  Parbefore(1)=Parafter(1);
	      

	  if(counter>0)
	    {
	      if(fabs(Parafter(0)-Parbefore(0))<0.01)
		{		    
		  Parbefore(0)=Parafter(0);
		  
		  std::cout<<"******************Taken regularly X0 as "<<Parbefore(0)<<std::endl;
		}
	      else
		{
	
		  unsigned int numiter=lastX0s.size();
		  if(numiter>2)
		    {
		      if(fabs(lastX0s.at(numiter-1)-lastX0s.at(numiter-2))>0.01)
			{
			  std::cout<<"Warning, SHIFT TOO  big, not considered, B resetted to 0"<<std::endl;
			  std::cout<<numiter<<"Difference (lastX0s.at(numiter-1)-lastX0s.at(numiter-2)) was "<<(lastX0s.at(numiter-1)-lastX0s.at(numiter-2))<<std::endl;
			  Parbefore(0)=0.;
			  //In the code X0 should be the same of parbefore0. X0 is used as alias to make code easier to understand
			}
		      else
			{
			  Parbefore(0)=Parafter(0);
			  std::cout<<"******************Taken X0 as "<<Parbefore(0)<<""<<std::endl;
			}
		    }
		  else
		    {
		      if((fabs(Parafter(0))>10)&&(fabs(Parafter(0)-Parbefore(0))>0.01))
			{
			  std::cout<<"Warning, SHIFT TOO  big, not considered, B resetted to 0"<<std::endl;
			  std::cout<<numiter<<"Difference (Parafter(0)-Parbefore(0)) was "<<(Parafter(0)-Parbefore(0))<<std::endl;
			  Parbefore(0)=0.;
			}
		      
		    }
		  
		}
	    }
	  
	  for(unsigned int j=0; j<theTracks->size();j++)
	    {
	      
	      
	      AX0=Parbefore(1);
	      X0=Parbefore(0);

	      TMatrixD covmat(4,4);
	      covmat.Zero();
	      //	      double chi2corr;	      
	      std::vector<T2Hit> hitv =  theTracks->at(j);

	      //std::vector<double> corrFit=T2CutsUtil.MyLinearfitCorr(hitv,covmat,chi2corr);
	      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
	      std::vector<double> Trkparameter;

	       if(XorY=='X')
		{
		  //Store X fit 
		  for(unsigned int c=0;c<2;c++)
		    {
		      Trkparameter.push_back(corrFit[c]);
		    }
		  
		  axj= Trkparameter.at(0); 
		  bxj= Trkparameter.at(1);
		}

	       if(XorY=='Y')
		{
		  //Store Y Fit
		  for(unsigned int c=0;c<2;c++)
		    {
		      Trkparameter.push_back(corrFit[2+c]);
		    }
		  	  
		  axj= Trkparameter.at(0); 
		  bxj= Trkparameter.at(1);
		}
	      
	      
	      sigmaZj=100.0; // a costant value, to be implemented better.
	      

	      //Update oneJ,oneF
	      //OneF is the gradient of the function to be minimized. OneJ is the hessian, to be inverted for the final formula
	      
	      oneJ(0,0)=oneJ(0,0)+(1.0/(sigmaZj*sigmaZj))*(2.0)*(1.0/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)));
	      oneJ(0,1)=oneJ(0,1)+(1.0/(sigmaZj*sigmaZj))*(-4.0)*( Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      
	      oneJ(1,0)=oneJ(1,0)+(1.0/(sigmaZj*sigmaZj))*(-4.0)*( Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      oneJ(1,1)=oneJ(1,1)+(1.0/(sigmaZj*sigmaZj))*(6.0)*( Nj(axj, bxj,AX0, X0)*Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      
	      
	      oneF(0)=oneF(0)+(1.0/(sigmaZj*sigmaZj))*(2.0)*(Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ));
	      oneF(1)=oneF(1)+(1.0/(sigmaZj*sigmaZj))*(-2.0)*( Nj(axj, bxj,AX0, X0)*Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
		      
		  		     
	    
	    }//All tracks are considered for a single detector: 
	     //the parameter for the system of equations and Jacobians are now computed

	  // std::cout<<"J:"<<std::endl;
	  //oneJ.Print();

	  Double_t deti;
	
	  oneJ.Invert(&deti);
	  //std::cout<<"determinante="<<deti<<std::endl;
	  //std::cout<<"DX,DY( "<<counter<<" ):"<<std::endl;
	  // Parbefore.Print();
	  //std::cout<<"J-1:"<<std::endl;
	  //oneJ.Print();
	  // std::cout<<"F:"<<std::endl;
	  // oneF.Print();
	  //std:: cout<<"Inside newton method; B|A Print:"<<endl;

	  std::cout<<"   >>>>  Newt Iteration "<<counter<<". BEGIN"<<std::endl;
	  std::cout<<"   >>>>Parbefore:"<<std::endl;
	  Parbefore.Print();
	  Parafter=Parbefore-oneJ*oneF;
	  std::cout<<"   >>>>Parafter:"<<std::endl;
	  Parafter.Print();
	  std::cout<<"   >>>>  Newt Iteration "<<counter<<". END"<<std::endl;
	  
	  /*TVectorD differ(2);
	  differ.Zero();
	  differ=Parbefore-Parafter;
	   //std::cout<<"DX,DY( "<<(counter+1)<<" ):"<<std::endl;	      
	   //Parafter.Print();
	   */
	  lastX0s.push_back(Parafter(0));

	  exitnewton=false;
	  /*
	  if((fabs(Parafter(1)-Parbefore(1))<0.001))
	    if((fabs(Parafter(1)/Parbefore(1))<1.5)&&(fabs(Parafter(1)/Parbefore(1))>0.7))
	      if((fabs(Parafter(0)-Parbefore(0))<1))
		if((fabs(Parafter(0)/Parbefore(0))<1.5)&&(fabs(Parafter(0)/Parbefore(0))>0.7))
		  exitnewton=true;
	  */
	  std::cout<<"Evaluating condition for another newt step.."<<std::endl;
	  std::cout<<"fabs((Parafter(1)-Parbefore(1))/Parafter(1))<0.05?  ="<<fabs((Parafter(1)-Parbefore(1))/Parafter(1))<<std::endl;
	  std::cout<<"OR (fabs(Parafter(1)-Parbefore(1))<0.0005)?  ="<<(fabs(Parafter(1)-Parbefore(1)))<<std::endl;
	  std::cout<<"AND ( fabs(Parafter(0)-Parbefore(0))<0.01)<0.5?  ="<<fabs(Parafter(0)-Parbefore(0))<<std::endl;


	  if( fabs(Parafter(0)-Parbefore(0))<0.5)
	  if((fabs((Parafter(1)-Parbefore(1))/Parafter(1)) <0.05)||(fabs(Parafter(1)-Parbefore(1))<0.0005))
	      exitnewton=true; 
	    

	  //std::cout<<"Difference:"<<std::endl;
	  //differ.Print();
	  
	     /*
	  if((differ.Norm2Sqr()<0.00004)&&(differ.NormInf()<0.00004))
	    exitnewton=true;
	  else
	    exitnewton=false;	
	     */
	 
	  // std::cout<<"   >>>>  Newt Iteration "<<counter<<". B|A = "<<Parafter(0)<<"|"<<Parafter(1)<<" newt step end" <<std::endl;
	  counter++;
	}// end of Newton method iteration for a detector
      
      if(exitnewton)
	{
	  std::cout<<"Newton method converges after "<<counter<<" iteration!"<<std::endl;
	  retvecAlignPar.push_back(Parafter(0));
	  retvecAlignPar.push_back(Parafter(1));
	}
      else
	{
	  std::cout<<"WARNING Newton method for does not work"<<std::endl;
	}
 
    

  return retvecAlignPar;
}
//End NewtonStep
 

long double QuarterTilt::TiltHistograms1D(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  
  long double toret;
  std::auto_ptr<TProfile> TiltsObs;
  TiltsObs= std::auto_ptr<TProfile>(new TProfile("TiltsObs","TiltsObs",10,-10,10,""));
  double ax,ay;//,bx,by;

 for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);      
      ax=corrFit[0];
      //   bx=corrFit[1];
        ay=corrFit[2];
     // by=corrFit[3];
      bool inRZplane=false;
      T1T2Track atrk=T2CutsUtil.RPhiFit(hitv);
      //      double thephi=atrk.Phi();
      // double tanphi=tan(thephi);
      
      if(fabs(hitv.at(0).GetHitPhi()-hitv.at(hitv.size()-1).GetHitPhi())<(3*3.14159/180.0))
	inRZplane=true;
      
      if((inRZplane)&&(hitv.at(0).GetHitR()<90.))
	{
	  for(unsigned m=0;m<hitv.size();m++)
	    {
	      double hitphi=hitv.at(m).GetHitPhi()*3.14159/180.0;
	      if(hitphi>3.14159)
		hitphi=hitphi-2*3.14159;

	      double they=tan(hitphi)*ax-ay;
	      double thex=tan(hitphi);
	      TiltsObs->Fill(thex,they);
	    }
	}
    }

  TF1 *f1 = new TF1("f1","[0]+[1]*x",-8,8);
  TiltsObs->Fit("f1","Q");
  TVectorD c_graph(2);
  c_graph(0) = f1->GetParameter(0);//intercept
  c_graph(1) = f1->GetParameter(1);//slope
  
  //OBS=AY-tanphi*AX
  if(XorY=='X')
    toret=c_graph(1)*(-1.0);
  else
    toret=c_graph(0);
  
  return toret;
}


long double QuarterTilt::ShiftEstimation1D(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  // long double toret;
  std::auto_ptr<TProfile> CommonShiftXObsCut;
  CommonShiftXObsCut= std::auto_ptr<TProfile>(new TProfile("CommonShiftXObsCut","DeltaXvsPlane",1000,13500.,14500,""));
 
  double aj,bj;//,idealHitpos

  std::cout<<"ShiftEstimation1D begin"<<std::endl;
  
  std::vector<long double>  returned_10_shifts;
  std::vector<long double>  statistic;
  
  for(unsigned int i=0;i<10;i++)
    {
      returned_10_shifts.push_back(0.0);
      statistic.push_back(0.0);
    }
  
  //std::cout<<"thetrk.size "<<theTracks->size()<<std::endl;
  for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);
      
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
      if(XorY=='X')
	{
	  aj=corrFit[0];
	  bj=corrFit[1];
	}
      else
	{
	  aj=corrFit[2];
	  bj=corrFit[3];
	}
      
      
      double theZ0=-bj/aj;
      // std::cout<<" A "<<std::endl;
      T1T2Track trkrebuilded=T2CutsUtil.TrackFromHits(true, hitv);
      //std::cout<<" !!! trkrebuilded.GetTx() "<<trkrebuilded.GetTx()<<" trkrebuilded.GetX0() "<<trkrebuilded.X0()<<std::endl;
      //std::cout<<"trk.Eta()"<<trkrebuilded.Eta()<<"   trk.Z_at_Rmin()"<<trkrebuilded.Z_at_Rmin()<<"  trk.ChiSquaredX()"<<trkrebuilded.ChiSquaredX()<<"  trk.ChiSquaredX() "<<trkrebuilded.ChiSquaredY();

      //trk.Eta()trk.Z_at_Rmin()
      //ThetaAsPrimary(T1T2Track trk, bool usexytrack)TrkInQuarter(T1T2Track trk)trk.ChiSquaredX()
      if(T2CutsUtil.AcceptThisT2Track(trkrebuilded))
	{
	  // std::cout<<"ACC$";
	  if((fabs(theZ0))<50000)
	    {

	      double hitZ;
	      double tanxHit;
	      double residualx;
	      unsigned int vectorpos;
	      //std::cout<<XorY<<"??"<<theZ0<<hitv.size();
	      for(unsigned int m=0;m<hitv.size();m++)
		{

		  planeinfo=conv.GetT2Info(hitv.at(m).GetHitDetRawId());
		  vectorpos=planeinfo.pl_0to9;
		  
		  //  std::cout<<" C: "<<vectorpos<<std::endl;
	      
		  hitZ=planeinfo.Zdet;
		 
	     
		  if(XorY=='X')
		    {
		      tanxHit=hitv.at(m).GetHitX()/hitZ;
		      // std::cout<<"^^"<<trkrebuilded.GetTx()<<"-"<<aj;
		      residualx=tanxHit-trkrebuilded.GetTx();
		      CommonShiftXObsCut->Fill(hitZ,residualx*hitZ);
		    }
		  else
		    {
		      tanxHit=hitv.at(m).GetHitY()/hitZ;
		      residualx=tanxHit-trkrebuilded.GetTy();
		      CommonShiftXObsCut->Fill(hitZ,residualx*hitZ);
		    }
	      
		  returned_10_shifts.at(vectorpos)+=residualx*hitZ;
		  statistic.at(vectorpos)+=1.0;
	       
		}
	      
	    
	    }
	  //else
	  //std::cout<<"WRN: fabsZ0>50000!";
	}
      //else
      //std::cout<<"NOT_ACC$";
    

    }
  
 long double thefinalaverage=0.;
 long double thefinalcounter=0.;
 
 for(unsigned int i=0;i<10;i++)
   {
     //calculate shift
     if(statistic.at(i)>=1)
       {
	 returned_10_shifts.at(i)=returned_10_shifts.at(i)/statistic.at(i);  
	 std::cout<<XorY<<" shift plane "<<i<<"=  "<<returned_10_shifts.at(i)<<std::endl;
	 thefinalaverage+=returned_10_shifts.at(i);
	 thefinalcounter=thefinalcounter+1.0;
       }
   }
   
 thefinalaverage=thefinalaverage/thefinalcounter;
 //thefinalaverage=CommonShiftXObsCut->GetMeany();
 
 TF1 *f1 = new TF1("f1","pol0",13500,14500);
 CommonShiftXObsCut->Fit("f1","Q");
 TVectorD c_graph(2);
 c_graph(0) = f1->GetParameter(0);
 //c_graph(1) = f1->GetParameter(1);
 thefinalaverage=c_graph(0);
 std::cout<<"ShiftEstimation1D end. Intercet= "<<c_graph(0)<</*"|"<<c_graph(1)<<*/std::endl;
 return thefinalaverage;

}
//End ShiftEstimation1D






long double QuarterTilt::Shift1DSimpleDifference(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  double hitZ;double tanxHit;double residualx;  double tanyHit;  double residualy;  double x0;  double y0;  double z0;  double x1;  double y1;  double z1;  double xn;  double yn;  double zn;  double tanXplane0_;  double tanXplane1_;   double tanYplane0_;  double tanYplane1_;   double x0_;  double y0_;  double z0_;  double x1_;  double y1_;  double z1_;  double xf_;  double yf_;  double zf_;  bool FirstplaneisPL0=false;  bool PL0saved=false;  bool PL1saved=false;

  if(false)
    std::cout<<hitZ<< tanxHit<< residualx<<   tanyHit<<   residualy<<   x0<<   y0<<   z0<<   x1<<   y1<<   z1<<   xn<<   yn<<   zn<<   tanXplane0_<<   tanXplane1_<<    tanYplane0_<<   tanYplane1_<<    x0_<<   y0_<<   z0_<<   x1_<<   y1_<<   z1_<<   xf_<<   yf_<<   zf_<<   FirstplaneisPL0<<   PL0saved<<   PL1saved<<std::endl;

  std::cout<<"Shift1DSimpleDifference begin"<<std::endl;


  ShiftObsX->Reset();
  ShiftObsY->Reset();  
  
  std::cout<<"a"<<std::endl;
  T2GeometryUtil conv_;
  T2GeometryUtil::T2DetInfo planeinfo_;
  T2GeometryUtil conv_2;
  T2GeometryUtil::T2DetInfo planeinfo_2;
  std::vector<double>  param;

  for (unsigned int ii=0;ii<theTracks->size();ii++)
    {
      param=T2CutsUtil.MyLinearfitXYSimple(theTracks->at(ii));
      T1T2Track theTrk=T2CutsUtil.TrackFromHits(true, theTracks->at(ii));   
      
      planeinfo_=conv_.GetT2Info(theTrk.GetHitT2(0).GetHitDetRawId());
      if(planeinfo_.pl_0to9==0)
	FirstplaneisPL0=true;	      	      
   
      xf_=theTrk.GetHitT2(theTrk.GetHitEntries()-1).GetHitX();
      yf_=theTrk.GetHitT2(theTrk.GetHitEntries()-1).GetHitY();
      zf_=theTrk.GetHitT2(theTrk.GetHitEntries()-1).GetHitZ();

      if(XorY=='X')
	{
	  ErrXvsAx->Fill(param[4],param[0]);
	  ErrBXvsBx->Fill(param[5],param[1]);
	}
      

      for(unsigned int m=0;m<theTrk.GetHitEntries();m++)
	{
  
	  planeinfo_=conv_.GetT2Info(theTrk.GetHitT2(m).GetHitDetRawId());
	  hitZ=planeinfo_.Zdet;		 
      
	  tanxHit=theTrk.GetHitT2(m).GetHitX()/hitZ;
	  residualx=tanxHit-theTrk.GetTx();
      
	  tanyHit=theTrk.GetHitT2(m).GetHitY()/hitZ;
	  residualy=tanyHit-theTrk.GetTy();
      
      
	  //  if(T2CutsUtil.AcceptThisT2Track(theTrk))
	  //    {
	  
	      planeinfo_2=conv_.GetT2Info(theTrk.GetHitT2(m).GetHitDetRawId());
	      if(planeinfo_2.pl_0to9==0)
		{
		  PL0saved=true;
		  tanXplane0_=theTrk.GetHitT2(m).GetHitX()/theTrk.GetHitT2(m).GetHitZ();
		  tanYplane0_=theTrk.GetHitT2(m).GetHitY()/theTrk.GetHitT2(m).GetHitZ();
		  x0_=theTrk.GetHitT2(m).GetHitX();   
		  y0_=theTrk.GetHitT2(m).GetHitY();   
		  z0_=theTrk.GetHitT2(m).GetHitZ();   
		}
	  
	      if(planeinfo_2.pl_0to9==1)
		{
		  PL1saved=true;
		  tanXplane1_=theTrk.GetHitT2(m).GetHitX()/theTrk.GetHitT2(m).GetHitZ();
		  tanYplane1_=theTrk.GetHitT2(m).GetHitY()/theTrk.GetHitT2(m).GetHitZ();
		  x1_=theTrk.GetHitT2(m).GetHitX();   
		  y1_=theTrk.GetHitT2(m).GetHitY();   
		  z1_=theTrk.GetHitT2(m).GetHitZ(); 
		}
	  
	  
	  
	      x0=theTrk.GetHitT2(0).GetHitX();   
	      y0=theTrk.GetHitT2(0).GetHitY();   
	      z0=theTrk.GetHitT2(0).GetHitZ();   
	      x1=theTrk.GetHitT2(1).GetHitX();   
	      y1=theTrk.GetHitT2(1).GetHitY();   
	      z1=theTrk.GetHitT2(1).GetHitZ(); 
	  		       	 	  
	  
	      if((FirstplaneisPL0)&&(planeinfo_.ht==0))
		{
		  xn=theTrk.GetHitT2(m).GetHitX();
		  yn=theTrk.GetHitT2(m).GetHitY();
		  zn=theTrk.GetHitT2(m).GetHitZ();
		  //double tanXplane0=theTrk.GetHitT2(0).GetHitX()/theTrk.GetHitT2(0).GetHitZ();
		  //double tanYplane0=theTrk.GetHitT2(0).GetHitY()/theTrk.GetHitT2(0).GetHitZ();
		  //double tanXplane1=theTrk.GetHitT2(1).GetHitX()/theTrk.GetHitT2(1).GetHitZ();
		  //double tanYplane1=theTrk.GetHitT2(1).GetHitY()/theTrk.GetHitT2(1).GetHitZ();
		  /*
		  if((fabs(theTrk.GetHitT2(0).GetHitX()/theTrk.GetHitT2(0).GetHitR())>0.8)&&(theTrk.Eta()<5.7))
		    {
		      T1T2Track theTrk2=T2CutsUtil.TrackXYFromHitsExcludingOneplane(theTrk.GetHitT2(m).GetHitDetRawId(),theTrk);
		      //Uncomment for Tilt-Histo evaluation
		      
		      if(zn!=z0)				
		      {
			TiltObsXBigAngleFromVtx->Fill(zn,((xn-x0)/(zn-z0))-tanXplane0);			
		      }
		      
		    }
		  */

		  // if((fabs(theTrk.GetHitT2(0).GetHitX()/theTrk.GetHitT2(0).GetHitR())>0.8)&&(theTrk.GetHitT2(0).GetHitR()<70))
		  // {
		  
		  
		  if(XorY=='X')
		    {
		      T1T2Track theTrk2=T2CutsUtil.TrackXYFromHitsExcludingOneplane(theTrk.GetHitT2(m).GetHitDetRawId(),theTrk);
		      //if(theTrk.Eta()<5.9)//(theTrk2.GetTx())
		      if((param[4]<0.0009)&&(param[5]<30))
			ShiftObsX->Fill(hitZ,(theTrk2.GetTx())*(hitZ+9)-theTrk.GetHitT2(m).GetHitX());
		    }
		  
		  //Uncomment for Tilt-Histo evaluation
		  /*
		  if(zn!=z0)
		    {
		      TiltObsX->Fill(zn,((xn-x0)/(zn-z0))-tanXplane0);
		    }
		  */
		  //  }
		  // if((fabs(theTrk.GetHitT2(0).GetHitY()/theTrk.GetHitT2(0).GetHitR())>0.8)&&(theTrk.GetHitT2(0).GetHitR()<80))
		  //{
		      //TanHitTanTrkDiffYFromVTX->Fill(hitZ,residualy);
		  
		  if(XorY=='Y')
		    {
		      T1T2Track theTrk2=T2CutsUtil.TrackXYFromHitsExcludingOneplane(theTrk.GetHitT2(m).GetHitDetRawId(),theTrk);
		      if((param[6]<0.0009)&&(param[7]<30))
			ShiftObsY->Fill(hitZ,(theTrk2.GetTy())*(hitZ+9)-theTrk.GetHitT2(m).GetHitY());
		      //std::cout<<param[6]<<std::endl;		      
		    }
		      //Uncomment for Tilt-Histo evaluation
		      /*
			if(zn!=z0)				
			{				  
			TiltObsY->Fill(zn,((yn-y0)/(zn-z0))-tanYplane0);
			//std::cout<<((yn-y0)/(zn-z0))<<"@@"<<tanYplane0<<std::endl;
			}
		      */
		  //}
		}
	      //}
	}

    }

  std::cout<<"b"<<std::endl;
  long double thefinalaverage;

  //CPlayer newPlayer = CPlayer(position, attacker);
  TF1 f1 = TF1("f1","pol0",13500,14500); 
  //TF1 *f1 = new TF1("f1","pol0",13500,14500); 
  std::cout<<"c"<<std::endl;
  TVectorD c_graph(2);
  
  if(XorY=='X')
    {       
      ShiftObsX->Fit("f1","Q");
     
      c_graph(0) = f1.GetParameter(0);
      //c_graph(1) = f1->GetParameter(1);
      thefinalaverage=c_graph(0);
    }
  else
    {
      ShiftObsY->Fit("f1","Q");
      
      c_graph(0) = f1.GetParameter(0);
      //c_graph(1) = f1->GetParameter(1);
      thefinalaverage=c_graph(0);
    }
  std::cout<<"ShiftEstimation1D end. Intercept "<<XorY<<"= "<<c_graph(0)<<"| slope="<<c_graph(1)<<std::endl;
  return thefinalaverage;
} //the intercept is the detector shift, with the correct sign.






//DX, DY has size=10
//Correct All the tracks  with internal alignment results
void QuarterTilt::CorrectForIntAlign(unsigned int half,std::vector<double> DX, std::vector<double> DY)
{
  uint32_t rawiddet=0;
  double r=0.;
  unsigned int symb=0;
  //unsigned int countinhalf=0;
  for (unsigned int g=0;g<trackutilizedforalignment.size();g++)
    {
      std::vector<T2Hit> hitv=trackutilizedforalignment.at(g);
      //countinhalf=0;
      for(unsigned int l=0;l<hitv.size();l++)
	{
	  rawiddet=hitv.at(l).GetHitDetRawId();
	  planeinfo=conv.GetT2Info(rawiddet);
	  symb=(planeinfo.symb%10);
	  if((planeinfo.symb/10)==half)
	    {
	      //  countinhalf++;
	      //See line ~226 of T2RecHit.cc. There it is used the -SIGN for correct hit position
	      hitv.at(l).SetHitX(hitv.at(l).GetHitX()-DX.at(symb));
	      hitv.at(l).SetHitY(hitv.at(l).GetHitY()-DY.at(symb));	  
	      r=sqrt(hitv.at(l).GetHitX()*hitv.at(l).GetHitX()+hitv.at(l).GetHitY()*hitv.at(l).GetHitY());
	      hitv.at(l).SetHitR(r);
	    }
	}
      // if(countinhalf>=4)
	trackutilizedforalignment.at(g)=hitv;
    }
}





void QuarterTilt::TestNewton(std::vector<std::vector<T2Hit> > *theTracks)
{
  std::vector<long double> retvecAlignPar;

  // std::cout<<"NewtonStep.."<<std::endl;
  std::vector<TMatrixD> Js;  // one 2x2 matrix for each detector (2=number of incognite X0, ThetaX)
  std::vector<TVectorD> Fs;
  unsigned int maxnewtoniter=10;
  //  TRandom *ran1 = new TRandom();

  //double rnx0;
  //double rnax;
      
  // rnx0=ran1->Uniform(-1,1);
      
  // rnax=ran1->Uniform(-100,100);
    
      	
      TVectorD Parbefore(2);
      Parbefore(0)=0.;//rnx0;//0.;//rnx;//Metti un random
      Parbefore(1)=0.;//rnax;//0.;//rny;    
      TVectorD  Parafter(2); //X0,AX0
      
      Parafter=Parbefore;
      bool exitnewton=false;
      unsigned int counter=0;
      double X0,AX0,bxj,axj;
      double sigmaZj=100.0; // a costant value, to be implemented better.
      
      std::vector<double> theTracksAX;
      std::vector<double> theTracksBX;
      //vector<int> first (3,0);
      
      for(unsigned int j=0; j<theTracks->size();j++)
	{
	  std::vector<T2Hit> hitv =  theTracks->at(j);

	  //std::vector<double> corrFit=T2CutsUtil.MyLinearfitCorr(hitv,covmat,chi2corr);
	  std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
      
	  theTracksAX.push_back(corrFit[0]);
	  theTracksBX.push_back(corrFit[1]);
			  
      
	}

       while((exitnewton==false)&&(counter<maxnewtoniter))
	{
	   std::cout<<"   >>>>  Newt Iteration "<<counter<<". begin newton step"<<std::endl;
	  TMatrixD oneJ(2,2);
	  TVectorD oneF(2);
	  oneF.Zero();
	  oneJ.Zero();
	 
	  // double oneJ1Var=0.;
	  // double oneF1Var=0.;

	  for(unsigned int j=0; j<theTracksBX.size();j++)
	    {
	      
	      X0=Parbefore(0);
	      AX0=Parbefore(1);


	      TMatrixD covmat(4,4);
	      covmat.Zero();
	      // double chi2corr;	      
	

	      axj= theTracksAX.at(j);
	      bxj= theTracksBX.at(j);
	      
		
	      //long double toprint=-(bxj/axj);
	       //std::cout<<"  |"<<toprint<<"("<<-bxj<<"/"<<axj<<")";
	     
	      sigmaZj=100.0; // a costant value, to be implemented better.
	      

	      //Update oneJ,oneF
	      //OneF is the gradient of the function to be minimized. OneJ is the hessian, to be inverted for the final formula
	      
	      oneJ(0,0)=oneJ(0,0)+(1.0/(sigmaZj*sigmaZj))*(2.0)*(1.0/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)));
	      oneJ(0,1)=oneJ(0,1)+(1.0/(sigmaZj*sigmaZj))*(-4.0)*( Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      
	      oneJ(1,0)=oneJ(1,0)+(1.0/(sigmaZj*sigmaZj))*(-4.0)*( Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      oneJ(1,1)=oneJ(1,1)+(1.0/(sigmaZj*sigmaZj))*(6.0)*( Nj(axj, bxj,AX0, X0)*Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
	      
	      
	      oneF(0)=oneF(0)+(2.0)*(1.0/(sigmaZj*sigmaZj))*(Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ));
	      oneF(1)=oneF(1)+(-2.0)*(1.0/(sigmaZj*sigmaZj))*( Nj(axj, bxj,AX0, X0)*Nj(axj, bxj,AX0, X0)/( Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0)*Dj(axj, bxj,AX0, X0) ) );
		      
		  		     
	    
	    }//All tracks are considered for a single detector: 
	     //the parameter for the system of equations and Jacobians are now computed

	  // std::cout<<"J:"<<std::endl;
	  //oneJ.Print();

	  Double_t deti;
	
	  oneJ.Invert(&deti);
	  //std::cout<<"determinante="<<deti<<std::endl;
	  //std::cout<<"DX,DY( "<<counter<<" ):"<<std::endl;
	  // Parbefore.Print();
	  //std::cout<<"J-1:"<<std::endl;
	  //oneJ.Print();
	  // std::cout<<"F:"<<std::endl;
	  // oneF.Print();
	  std:: cout<<"Inside newton method; B|A Print:"<<endl;
	 
	  Parbefore.Print();
	  Parafter=Parbefore-oneJ*oneF;
	  Parafter.Print();
	  
	  TVectorD differ(2);
	  differ.Zero();
	  differ=Parbefore-Parafter;
	   //std::cout<<"DX,DY( "<<(counter+1)<<" ):"<<std::endl;	      
	   //Parafter.Print();
	  exitnewton=false;
	  
	  if((fabs(Parafter(1)-Parbefore(1))<0.001)/*&&((fabs(Parafter(0)-Parbefore(0))<0.5)*/)
	    if((fabs(Parafter(1)/Parbefore(1))<1.5)&&(fabs(Parafter(1)/Parbefore(1))>0.7))
	      if((fabs(Parafter(0)-Parbefore(0))<1)/*&&((fabs(Parafter(0)-Parbefore(0))<0.5)*/)
		if((fabs(Parafter(0)/Parbefore(0))<1.5)&&(fabs(Parafter(0)/Parbefore(0))>0.7))
		  exitnewton=true;
	  
	  //Put a constraint
	  if((fabs(Parafter(0))>4.6)&&(exitnewton==false))
	    {
	      Parafter(0)=Parbefore(0);
	      std::cout<<"Warning, SHIFT TOO  big, not considered"<<std::endl;		
	    }
	  
	  Parbefore=Parafter;
	  
	 
	  std::cout<<"   >>>>  Newt Iteration "<<counter<<". B|A = "<<Parafter(0)<<"|"<<Parafter(1)<<" newt step end" <<std::endl;
	  counter++;
	}// end of Newton method iteration for a detector
      
      if(exitnewton)
	{
	  std::cout<<"Newton method converges after "<<counter<<" iteration!"<<std::endl;
	  retvecAlignPar.push_back(Parafter(0));
	  retvecAlignPar.push_back(Parafter(1));
	}
      else
	{
	  std::cout<<"WARNING Newton method for does not work"<<std::endl;
	}
      
      std::cout<<"Newt Test results:"<<std::endl;


      std::cout<<"Aj= (";
      for (unsigned int y=0;y<theTracksAX.size();y++)
	{
	  std::cout<<theTracksAX.at(y)<<",";
	}
      std::cout<<")"<<std::endl;

       std::cout<<"Bj= (";
      for (unsigned int y=0;y<theTracksBX.size();y++)
	{
	  std::cout<<theTracksBX.at(y)<<",";
	}

      std::cout<<")"<<std::endl;

      std::cout<<"Zj= (";
      for (unsigned int y=0;y<theTracksBX.size();y++)
	{
	  std::cout<<-(theTracksBX.at(y)/theTracksAX.at(y))<<",";
	}
      std::cout<<")"<<std::endl;
      std::cout<<"Results: B | A:"<<std::endl;
      for (unsigned int y=0;y<retvecAlignPar.size();y++)
	std::cout<<retvecAlignPar.at(y)<<std::endl;
      //retvecAlignPar.Print();

}
//End TestNewton

double QuarterTilt::StartingPointTheta(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  std::vector<double> theTracksAX;
  std::vector<double> theTracksBX;
  std::vector<double> theTracksZX;
      //vector<int> first (3,0);
  double sumbx=0.;
  double sumzx=0.;
      for(unsigned int j=0; j<theTracks->size();j++)
	{
	  std::vector<T2Hit> hitv =  theTracks->at(j);

	  //std::vector<double> corrFit=T2CutsUtil.MyLinearfitCorr(hitv,covmat,chi2corr);
	  std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
	  if(XorY=='X')
	    {
	      theTracksAX.push_back(corrFit[0]);
	      theTracksBX.push_back(corrFit[1]);
	      theTracksZX.push_back(-(corrFit[1]/corrFit[0]));
	      sumbx+=corrFit[1];
	      sumzx+=(-(corrFit[1]/corrFit[0]));
	    }
	  else
	    {
	      theTracksAX.push_back(corrFit[2]);
	      theTracksBX.push_back(corrFit[3]);
	      theTracksZX.push_back(-(corrFit[3]/corrFit[2]));	      
	      sumbx+=corrFit[3];
	      sumzx+=-(corrFit[3]/corrFit[2]);
	    }
	}
      
      
      double  startingtheta=(sumbx/theTracksBX.size())/(sumzx/theTracksZX.size());//sign=tilt angle of det resp BP
      //   double startingb=(sumbx/theTracksBX.size());

      //startingtheta=startingtheta;
      std::cout<<"<B>="<<(sumbx/theTracksBX.size())<<"  <Z>="<<(sumzx/theTracksZX.size())<<"  <A>="<<startingtheta<<std::endl;
      return startingtheta;
}

//Da fare meglio!!!
long double QuarterTilt::AxInoneshot(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  long double S_aytanphi=0;
  long double S_axtanphitanphi=0;
  long double S_tanphi=0;
  long double S_axtanphi=0;
  long double S_ay=0;
  long double S_tanphitanphi=0;
  long double statistic=0;


 for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);
      double ax=corrFit[0];
      
      double ay=corrFit[2];
      bool inRZplane=false;
      T1T2Track atrk=T2CutsUtil.RPhiFit(hitv);
      double thephi=atrk.Phi();
      double tanphi=tan(thephi);

      if(fabs(hitv.at(0).GetHitPhi()-hitv.at(hitv.size()-1).GetHitPhi())<(3*3.15159/180.0))
	inRZplane=true;
      
      if(inRZplane)
	{
	  S_aytanphi+=ay*tanphi;
	  S_axtanphitanphi+=ax*tanphi*tanphi;
	  S_tanphi+=tanphi;
	  S_axtanphi+=ax*tanphi;
	  S_ay+=ay;
	  S_tanphitanphi+=tanphi*tanphi;
	  statistic+=1;
	}

    }

 long double num=S_aytanphi-S_axtanphitanphi+(1.0/statistic)*S_tanphi*S_axtanphi-(1.0/statistic)*S_tanphi*S_ay;
 long double den= S_tanphitanphi- (S_tanphi*S_tanphi/statistic);

 long double finalTiltX=num/den;
   
 std::cout<<"TiltX in one shot:"<<finalTiltX;
 
 return finalTiltX;
}
std::vector<long double> QuarterTilt::FindShiftTiltMinuit(std::vector<std::vector<T2Hit> >*theTracks, char XorY)
{
  //double a0=0.;
  //double denj=0.;
  //double numj=0.;

  std::cout<<"Begin of   Data Loading Minuit "<<std::endl;
  xVecPtr->clear(); 
  zVecPtr->clear(); 
  bjVecPtr->clear(); 
  ajVecPtr->clear(); 
  ERRbjVecPtr->clear();
  //ErrbjY_forVeloCalc->clear();
  // ErrbjX_forVeloCalc->clear();  
  double aj=0.;
  double errbj=0.;
  double bj=0.;
  
  for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);      
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);

      if(XorY=='X')
	{ 
	  aj=corrFit[0];
	  bj=corrFit[1];
	  errbj=corrFit[5];//8.0;////2.0;//corrFit[5];
	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      ajVecPtr->push_back(aj);
	      bjVecPtr->push_back(bj);
	      ERRbjVecPtr->push_back(errbj);
	      xVecPtr->push_back(hitv.at(i).GetHitX());
	      zVecPtr->push_back(hitv.at(i).GetHitZ());		      	      
	    }	  
	}
      else
	{
	  aj=corrFit[2];
	  bj=corrFit[3];
	  errbj=corrFit[7];//2.0;//corrFit[7];

	  for(unsigned int i=0;i<hitv.size();i++)
	    {
	      ajVecPtr->push_back(aj);
	      bjVecPtr->push_back(bj);
	      ERRbjVecPtr->push_back(errbj);
	      xVecPtr->push_back(hitv.at(i).GetHitY());
	      zVecPtr->push_back(hitv.at(i).GetHitZ());	
	    }	 	  	  
	}
    }


  std::cout<<"FindShiftTiltMinuit  Data Loaded. Calling TMinuit. Data Size:"<<ajVecPtr->size()<<std::endl;

// Initialize minuit, set initial values etc. of parameters.

  const int npar = 2;              // the number of parameters
  //TMinuit minuit(npar);
  TMinuit *gmMinuit = new TMinuit(npar); 

  //double amin=-0.005;
  //double amax=0.005;
  //double bmin=-2.5;
  //double bmax=2.5;


  gmMinuit->SetFCN(fcn);

  std::cout<<"TMinuit set function OK. Start setting Tminuit"<<std::endl;

  double par[npar];               // the start values par[0]=a par[1]=Delta
  double stepSize[npar];          // step sizes 
  double minVal[npar];            // minimum bound on parameter 
  double maxVal[npar];            // maximum bound on parameter
  string parName[npar];

  par[0] = 0.000;            // a guess 0.5 mrad
  stepSize[0] = 0.0004;       // take e.g. 0.0002 of start value step size for numerical derivatives.
  
  minVal[0] = -0.005;   // if min and max values = 0, parameter is unbounded.
  maxVal[0] = 0.005;
  parName[0] = "AX";
  
  par[1] = 0.0;            // a guess 0. mm
  stepSize[1] = 0.2;       // 
  
  minVal[1] = -5.0;   // if min and max values = 0, parameter is unbounded.
  maxVal[1] = 5.0;
  parName[1] = "BX";
  
  for (int i=0; i<npar; i++){
    gmMinuit->DefineParameter(i, parName[i].c_str(), par[i], stepSize[i], minVal[i], maxVal[i]);
  }

// Do the minimization!

  gmMinuit->Migrad();       // Minuit's best minimization algorithm

  std::cout<<"TMinuit Minimization complete!"<<std::endl;
  
  double outpar[npar], err[npar];
  for (int i=0; i<npar; i++){
    gmMinuit->GetParameter(i,outpar[i],err[i]);
  }



  std::vector<long double>  retvecAlignPar;
  retvecAlignPar.push_back(outpar[1]);  //Inside "main" we use the shift parameter in position 0
  retvecAlignPar.push_back(outpar[0]);

  std::cout<<"FindShiftTiltMinuit END"<<std::endl;
  

  

  return retvecAlignPar;


}
//End FindShiftTiltMinuit




std::vector<long double> QuarterTilt::FindQuarterShiftTiltSimple(unsigned int quarterNumb)
{

  //unsigned int MaxStepalignstep=40;
  //unsigned int alignstep=0;
  // bool alignReached=false;
    
  std::vector<long double> DisalignVectX, DisalignVectY;
  //std::vector<long double> OldDisalignVectX,OldDisalignVectY;
  
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALF;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALALL;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY;
  // unsigned int quarterid;
  unsigned int hh;
  for(unsigned int j=0;j<trackutilizedforalignment.size();j++)
    {
      planeinfo=conv.GetT2Info(trackutilizedforalignment.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;
      if(hh==quarterNumb)
	{
	  
	  std::vector<T2Hit> hitsintrk=trackutilizedforalignment.at(j);
	  T1T2Track thexytrk=T2CutsUtil.TrackFromHits(true, hitsintrk);
	  //std::cout<<thexytrk.GetTxSigma()<<" "<<thexytrk.GetTySigma()<<" || "<<std::endl;
	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitX()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.7)	
	    if(trackutilizedforalignment.at(j).at(0).GetHitR()<140)
	      if((thexytrk.GetTxSigma()<0.001)&&(thexytrk.X0Sigma()<40))
		trackutilizedforalignmentONEHALFX.push_back(trackutilizedforalignment.at(j));

	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitY()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.7)
	    if(trackutilizedforalignment.at(j).at(0).GetHitR()<140)
	      if((thexytrk.GetTySigma()<0.001)&&(thexytrk.Y0Sigma()<40))		
		trackutilizedforalignmentONEHALFY.push_back(trackutilizedforalignment.at(j));

	  trackutilizedforalignmentONEHALALL.push_back(trackutilizedforalignment.at(j));
	  //if(trackutilizedforalignment.at(j).at(0).GetHitY()>0)
	}
    }


  std::cout << "SIMPLE-Alignment for Tilt will work with tracks extrated from the full event sample of"<<trackutilizedforalignment.size()<<" tracks."<<" [Trk in X proj="<<trackutilizedforalignmentONEHALFX.size()<<" Trk in Y proj="<<trackutilizedforalignmentONEHALFY.size()<<"]"<<std::endl;

 


  // long double Shifty;
  // long double Shiftx;

  DisalignVectX.push_back(0.0);//Ax
  DisalignVectX.push_back(0.0);//X0
  
  DisalignVectY.push_back(0.0);
  DisalignVectY.push_back(0.0);

  std::vector<long double> ToReturnX, ToReturnY;
 
  ToReturnX.push_back(0.0);
  ToReturnX.push_back(0.0);

  ToReturnY.push_back(0.0);
  ToReturnY.push_back(0.0);
  
 
  //-------------------------------------------------------------
  // Start to iterate over the each-time-updated track parameters
  //-------------------------------------------------------------

  char XorY;
  // double axj,bxj;
  //double CorrectionToaxj,CorrectionTobxj;

  //std::vector<long double>DisalignVectortest=FindShiftTiltMinuit(&trackutilizedforalignmentONEHALFX, 'X');

  for(unsigned int fromxtoy=0;fromxtoy<2;fromxtoy++)
    {
      // alignReached=false;
      // bool stopnext=false;
      if(fromxtoy==0)
	{
	  XorY='X';
	  trackutilizedforalignmentONEHALF.clear();
	  trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFX;	  
	}
      else
	{
	  XorY='Y';
	  trackutilizedforalignmentONEHALF.clear();
	  trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFY;
	}
      //alignstep=0;
      //  MaxStepalignstep=40;
      
      //long double tilt=TiltHistograms1DTh(&trackutilizedforalignmentONEHALALL, XorY);
      std::vector<long double> toret=ShiftTiltHistograms1DTh(&trackutilizedforalignmentONEHALALL, XorY);
      
      if(XorY=='X')
	ToReturnX= toret;
      else
	ToReturnY= toret;
    }

  std::vector<long double> ToReturn;
  //ToReturn= (AX,X0,AY,Y0)
  ToReturn.push_back(ToReturnX.at(0));
  ToReturn.push_back(ToReturnX.at(1));
  //ToReturn.push_back(Shiftx);
  ToReturn.push_back(ToReturnY.at(0));
  ToReturn.push_back(ToReturnY.at(1));  
  //ToReturn.push_back(Shifty);
  return ToReturn;
}





std::vector<long double> QuarterTilt::ShiftTiltHistograms1DTh(std::vector<std::vector<T2Hit> > *theTracks, char XorY)
{
  
  std::vector<long double> toret;
  std::auto_ptr<TProfile> TiltsObs;
  TiltsObs= std::auto_ptr<TProfile>(new TProfile("TiltsObs","TiltsObs",10,-10,10,""));
  double ax,bx,ay,by;
  double tiltAll=0.;double Nall=0.;
  double shiftAll=0.;double nsh=0.;
 for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);      
      ax=corrFit[0];
      bx=corrFit[1];
      ay=corrFit[2];
      by=corrFit[3];
      //      bool inRZplane=false;
      T1T2Track atrk=T2CutsUtil.RPhiFit(hitv);
      //double thephi=atrk.Phi();
      //double tanphi=tan(thephi);
      
      //if(fabs(hitv.at(0).GetHitPhi()-hitv.at(hitv.size()-1).GetHitPhi())<(3*3.14159/180.0))
	//	inRZplane=true;
      double h0=0.; //
      double z0=0.;
      // double dh0=0.;double slope=0.;
      z0=hitv.at(0).GetHitZ();
      if(XorY=='X'){
	//slope=ax;
		h0=hitv.at(0).GetHitX();	
	//	dh0=hitv.at(0).GetHitDX();
      }
      if(XorY=='Y'){
	//slope=ay;
		h0=hitv.at(0).GetHitY();
	//	dh0=hitv.at(0).GetHitDY();
      }
      double hi=0;
      // double dhi=0;
      double zi=0;
      double tilti=0.;
      double signZ=fabs(hitv.at(0).GetHitZ())/hitv.at(0).GetHitZ();

      if(fabs(h0/hitv.at(0).GetHitR())>0.8)
	if((hitv.at(0).GetHitR()<140.)&&(hitv.at(0).GetHitR()>50.))//(inRZplane)&&
	{
	  
	  for(unsigned m=(hitv.size()-1);m>=6;m--)
	    {
	      // double hitphi=hitv.at(m).GetHitPhi()*3.14159/180.0;
	      zi=hitv.at(m).GetHitZ();
	      


	      if(XorY=='X'){		
		hi=hitv.at(m).GetHitX();
		//dhi=hitv.at(m).GetHitDX();
	      }
	      if(XorY=='Y'){
		hi=hitv.at(m).GetHitY();
		//	dhi=hitv.at(m).GetHitDY();	
	      }

	      
	      
	      tilti=((hi-h0)/(zi-z0)-(h0/(z0+10*signZ)));
	      tiltAll+=tilti;
	      Nall=Nall+1.0;
	    }
	  
	}
    }

 double tilt=tiltAll/Nall;

  for(unsigned int j=0; j<theTracks->size();j++)
    {
      std::vector<T2Hit> hitv =  theTracks->at(j);
      std::vector<double> corrFit=T2CutsUtil.MyLinearfitXYSimple(hitv);      
      ax=corrFit[0];
      bx=corrFit[1];
      ay=corrFit[2];
      by=corrFit[3];
      bool inRZplane=false;
      T1T2Track atrk=T2CutsUtil.RPhiFit(hitv);
      //double thephi=atrk.Phi();
      //double tanphi=tan(thephi);
      
      if(fabs(hitv.at(0).GetHitPhi()-hitv.at(hitv.size()-1).GetHitPhi())<(3*3.14159/180.0))
	inRZplane=true;
      //   double h0=0.; double z0=0.;
      // double dh0=0.;
      // z0=hitv.at(0).GetHitZ();
      if(XorY=='X'){
	//	h0=hitv.at(0).GetHitX();	
	//	dh0=hitv.at(0).GetHitDX();
      }
      if(XorY=='Y'){
	//	h0=hitv.at(0).GetHitY();
	//	dh0=hitv.at(0).GetHitDY();
      }
      double hi=0;
     // double dhi=0;
      double zi=0;
      
      if((inRZplane)&&(hitv.at(0).GetHitR()<80.)&&(hitv.at(0).GetHitR()>40.))
	{
	  


	  for(unsigned m=0;m<hitv.size();m++)
	    {
	      // double hitphi=hitv.at(m).GetHitPhi()*3.14159/180.0;
	      zi=hitv.at(m).GetHitZ();
	      double shiftest=0.;
	      if(XorY=='X'){
		shiftest=bx+(ax-tilt)*zi;		
		hi=hitv.at(m).GetHitX();
		//	dhi=hitv.at(m).GetHitDX();
		if(m<=5)
		{
		  shiftAll=shiftAll+shiftest;//((h0/z0-hi/zi)/(1.0/zi-1.0/z0));
		  nsh=nsh+1.0;
		}

	      }
	      if(XorY=='Y'){
		shiftest=by+(ay-tilt)*zi;	
		hi=hitv.at(m).GetHitY();
		//	dhi=hitv.at(m).GetHitDY();
		if(m<=5)
		  if(hi>0)
		    {
		      shiftAll=shiftAll+shiftest;//((h0/z0-hi/zi)/(1.0/zi-1.0/z0));
		      nsh=nsh+1.0;
		    }
		
	      }

	      
	      	     
	    }


	}
    }

  double shift=shiftAll/nsh;


  toret.push_back(tilt);
  toret.push_back(shift);
  std::cout<<XorY<<"Tilt found by simple method: "<<tilt<<std::endl;
 /*
  TF1 *f1 = new TF1("f1","[0]+[1]*x",-8,8);
  TiltsObs->Fit("f1","Q");
  TVectorD c_graph(2);
  c_graph(0) = f1->GetParameter(0);//intercept
  c_graph(1) = f1->GetParameter(1);//slope
  
  //OBS=AY-tanphi*AX
  if(XorY=='X')
    toret=c_graph(1)*(-1.0);
  else
    toret=c_graph(0);
  */
  return toret;
}


