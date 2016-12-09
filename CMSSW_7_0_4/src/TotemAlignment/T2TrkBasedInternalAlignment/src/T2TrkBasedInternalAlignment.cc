// -*- C++ -*-
//
// Original Author:  Mirko Berretti


#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/T2TrkBasedInternalAlignment.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "CLHEP/Random/RandGaussQ.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/T2Digi/interface/T2StripDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2StripDigi.h"
#include "DataFormats/T2Digi/interface/T2PadDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2PadDigi.h"
#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/T2Cluster/interface/cluster_entry.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TAxis.h"
#include "FWCore/Framework/interface/MakerMacros.h"



T2TrkBasedInternalAlignment::T2TrkBasedInternalAlignment(const edm::ParameterSet& iConfig){

  simufile=iConfig.getParameter<bool>("simufile");

  Chicut = iConfig.getParameter<double>("Chicut");
  PhiChiProbCut = iConfig.getParameter<double>("PhiChiProbCut");
  RChiProbCut = iConfig.getParameter<double>("RChiProbCut");  
  chiRredCut = iConfig.getParameter<double>("chiRredCut");
  chiPhiredCut = iConfig.getParameter<double>("chiPhiredCut");
  AllowedDRTrackDistance=iConfig.getParameter<double>("AllowedDRTrackDistance");
  
  FitdzEnergy=iConfig.getParameter<double>("FitdzEnergy");
  DZScale=iConfig.getParameter<double>("DZScale");
  tracketamin=iConfig.getParameter<double>("TrkEtamin");
  tracketamax=iConfig.getParameter<double>("TrkEtaMAX");


  //DetEffRWind=iConfig.getParameter<double>("DetEffRWind");
  //DetEffPhiWind=iConfig.getParameter<double>("DetEffPhiWind");
  //Numhittrkeff=iConfig.getParameter<int>("Numhittrkeff");
  //Testedcamera=iConfig.getParameter<std::vector<unsigned int> >("Testedcamera"); 

  SelectedHalfs=iConfig.getParameter<std::vector<unsigned int> >("SelectedHalfs");
  HalfSelectedForPlot=iConfig.getParameter<unsigned int>("HalfSelectedForPlot");
  RefHalfsWholeQuarterAlign=iConfig.getParameter<std::vector<unsigned int> >("RefHalfsWholeQuarterAlign");

  MaxPad=iConfig.getParameter<unsigned int>("MaxPad");
  MaxStrip=iConfig.getParameter<unsigned int>("MaxStrip");
  MaxDphi=iConfig.getParameter<double>("MaxDphi");
  NumHitGood=iConfig.getParameter<unsigned int>("NumHitGood");
  maxdrhit=iConfig.getParameter<double>("maxdrhit");
  maxdphihit=iConfig.getParameter<double>("maxdphihit");
  Effgoodhitnumber=iConfig.getParameter<unsigned int>("Effgoodhitnumber");
  
 

  Effmaxdphihit=iConfig.getParameter<double>("Effmaxdphihit");
  Effmaxdrhit=iConfig.getParameter<double>("Effmaxdrhit");
  EffMaxPad=iConfig.getParameter<unsigned int>("EffMaxPad");
  EffMaxStrip=iConfig.getParameter<unsigned int>("EffMaxStrip");
 
  SHIFTprescale=iConfig.getParameter<double>("SHIFTprescale");
  MaxStepalignstep=iConfig.getParameter<unsigned int>("MaxStepalignstep");
  Idreferencedet=iConfig.getParameter<std::vector<unsigned int> >("Idreferencedet");
  AlignmentHitRMax=iConfig.getParameter<double>("AlignmentHitRMax");
  AlignmentHitRMin=iConfig.getParameter<double>("AlignmentHitRMin");
 
  DoInternalAlign=iConfig.getParameter<bool>("DoInternalAlign");
  UseMillePede=iConfig.getParameter<bool>("UseMillePede");
  UseMillePedeGlobal=iConfig.getParameter<bool>("UseMillePedeGlobal");
  HitNumb4Align=iConfig.getParameter<unsigned int>("HitNumb4Align");
  //MeasuredXYResol=iConfig.getParameter<double>("MeasuredXYResol");
  MeasuredResol_X=iConfig.getParameter<double>("MeasuredResol_X");;
  MeasuredResol_Y=iConfig.getParameter<double>("MeasuredResol_Y");
  UseHistogramsForInternalError=iConfig.getParameter<bool>("UseHistogramsForInternalError");
  CalculateErrorAsHIP=iConfig.getParameter<bool>("CalculateErrorAsHIP");
  HitXYResolError=iConfig.getParameter<double>("HitXYResolError");

  MillePedeExcludedPlaneH0=iConfig.getParameter<std::vector<unsigned int> >("MillePedeExcludedPlaneH0");
  MillePedeExcludedPlaneH1=iConfig.getParameter<std::vector<unsigned int> >("MillePedeExcludedPlaneH1");
  MillePedeExcludedPlaneH2=iConfig.getParameter<std::vector<unsigned int> >("MillePedeExcludedPlaneH2");
  MillePedeExcludedPlaneH3=iConfig.getParameter<std::vector<unsigned int> >("MillePedeExcludedPlaneH3");


  IdreferencedetMille=iConfig.getParameter<std::vector<unsigned int> >("IdreferencedetMille");
  XreferencedetMille=iConfig.getParameter<std::vector<double> >("XreferencedetMille");
  YreferencedetMille=iConfig.getParameter<std::vector<double> >("YreferencedetMille");  
  
  IdreferencedetHIP=iConfig.getParameter<std::vector<unsigned int> >("IdreferencedetHIP");
  XreferencedetHIP=iConfig.getParameter<std::vector<double> >("XreferencedetHIP");
  YreferencedetHIP=iConfig.getParameter<std::vector<double> >("YreferencedetHIP");  
  
  //NumHitInTrk=iConfig.getParameter<int>("NumHitInTrk");
  ratioXYAlignTrkcut=iConfig.getParameter<double>("ratioXYAlignTrkcut");
  AllCorrectionAtSameTime=iConfig.getParameter<bool>("AllCorrectionAtSameTime");

  DoAlignHalfHalf=iConfig.getParameter<bool>("DoAlignHalfHalf");
  HalfHalfMaxDispTolerance=iConfig.getParameter<double>("HalfHalfMaxDispTolerance");
  HalfHalfMaxDispToleranceX=iConfig.getParameter<double>("HalfHalfMaxDispToleranceX");
  HalfHalfMaxDispToleranceY=iConfig.getParameter<double>("HalfHalfMaxDispToleranceY");
  EffgoodhitnumberOverl=iConfig.getParameter<unsigned int>("EffgoodhitnumberOverl");	
  OverlapTrkHitRMax=iConfig.getParameter<double>("OverlapTrkHitRMax");
  RMaxOverlapXalign=iConfig.getParameter<double>("RMaxOverlapXalign");
  RMaxOverlapYalign=iConfig.getParameter<double>("RMaxOverlapYalign");
  RMaxOverlapYalignHisto=iConfig.getParameter<double>("RMaxOverlapYalignHisto");
  RMaxOverlapXalignHisto=iConfig.getParameter<double>("RMaxOverlapXalignHisto");
  RMaxOverlapXalignHisto=iConfig.getParameter<double>("RMaxOverlapXalignHisto");
  RMaxOverlapYalignHisto=iConfig.getParameter<double>("RMaxOverlapYalignHisto");  
  HighEtaForOverlapAlign=iConfig.getParameter<double>("HighEtaForOverlapAlign");
  


  UseJointProb=iConfig.getParameter<unsigned int>("UseJointProb");
  FitgravcenterZ=iConfig.getParameter<double>("FitgravcenterZ");
  useRZforResol=iConfig.getParameter<unsigned int>("useRZforResol");
  UseHitErrorFromResol=iConfig.getParameter<bool>("UseHitErrorFromResol"); 
  DR_Resol_mm=iConfig.getParameter<double>("DR_Resol_mm"); 
  DPhiResol_Deg=iConfig.getParameter<double>("DPhiResol_Deg");
  


  IncludeQuarterTiltAlign=iConfig.getParameter<bool>("IncludeQuarterTiltAlign");
  SelectedHalfsForTiltAlign=iConfig.getParameter<std::vector<unsigned int> >("SelectedHalfsForTiltAlign");
  UseGlobVertexForTiltCalulation=iConfig.getParameter<bool>("UseGlobVertexForTiltCalulation");
  AXToll=iConfig.getParameter<double>("AXToll");
  AYToll=iConfig.getParameter<double>("AYToll");
  X0Toll=iConfig.getParameter<double>("X0Toll");
  Y0Toll=iConfig.getParameter<double>("Y0Toll");
  XYFitUsedinReco=iConfig.getParameter<bool>("XYFitUsedinReco");


  outputFileName = iConfig.getUntrackedParameter<std::string>("OutputFile");
  CluLabel = iConfig.getParameter<std::string>("CluLabel");
  HitLabel = iConfig.getParameter<std::string>("HitLabel");
  RoadLabel = iConfig.getParameter<std::string>("RoadLabel");
  TrackLabel= iConfig.getParameter<std::string>("TrackLabel");
  MaxEvents= iConfig.getParameter<unsigned int>("MaxEvents");

  T2StripDigiCollectionLabel = iConfig.getParameter<edm::InputTag>("T2StripDigiCollectionLabel");
  T2PadDigiCollectionLabel = iConfig.getParameter<edm::InputTag>("T2PadDigiCollectionLabel");
 
//  std::cout<<"Constructor called"<<std::endl;
}


T2TrkBasedInternalAlignment::~T2TrkBasedInternalAlignment()
{
//  std::cout<<"Destructor called"<<std::endl;
}


unsigned int RawtoSymb(uint32_t thedet)
{
  T2DetId converter;
  unsigned int pl=converter.plane(thedet);
  unsigned int pls=converter.planeSide(thedet);
  unsigned int ht=converter.halfTelescope(thedet);
  unsigned int arm=converter.arm(thedet);
  unsigned int symbolic=pl*2+pls+ht*10+20*arm;	  
 
  return symbolic;
}

/*
void HipReferenceLine(unsigned int quarter, double Z, double &Xret,double &Yret )
{
  //Two reference points have been assumed for each quarter. First two are for H0, then H1, ...H2.
  //If the planes are out of range, so no reference condition is applied, this method should not be called.
  int Startposinvector=quarter*2;
  
  if(Startposinvector<7){
    unsigned int id1=IdreferencedetHIP.at(Startposinvector);
    unsigned int id2=IdreferencedetHIP.at(Startposinvector+1);

    double X1=XreferencedetHIP.at(Startposinvector);
    double Y1=YreferencedetHIP.at(Startposinvector);
    double X2=XreferencedetHIP.at(Startposinvector+1);
    double Y2=YreferencedetHIP.at(Startposinvector+1);
    T2GeometryUtil conv1;
    T2GeometryUtil::T2DetInfo planeinfo1;
    planeinfo1=conv.GetT2Info(id1);
    double Z1=planeinfo1.Zdet;
    T2GeometryUtil conv2;
    T2GeometryUtil::T2DetInfo planeinfo2;
    planeinfo2=conv.GetT2Info(id2);
    double Z2=planeinfo2.Zdet;    
    
    Yret=Y1+((Y2-Y1)/(Z2-Z1))*(Z-Z1);
    Xret=X1+((X2-X1)/(Z2-Z1))*(Z-Z1);
  }else{
    std::cout<<"HipReferenceLine "<<std::endl;
  }
  
  
}
*/
//--------------------------------------------------------------------------------------------------------------------------------------
// BEGIN ALIGNMENT PART FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------------


//return (a,b,e_a,e_b)
std::vector<double> MyLinearfitX(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{  

double Sx=0.;
double Sxz=0.;
double Szz_x=0.;
double Sz_x=0.; 
double S0_x=0.; 



unsigned int  sizeHitv=hitvec.size();
std::vector<double> x;
std::vector<double> z;

std::vector<double> ex;
 std::vector<double> ez;

 double a_xz, b_xz;

  for(unsigned int jj =0; jj<sizeHitv; jj++)
    {
      //   std::cout<<hitvec[jj].GetHitR()<<" "<<hitvec[jj].GetHitPhi()<<" "<<hitvec[jj].GetHitZ()<<std::endl;
      x.push_back(hitvec[jj].GetHitX());
      

      z.push_back(hitvec[jj].GetHitZ());    
 

      //ex.push_back(0.09*fabs(hitvec[jj].GetHitX()));
      double phirad=hitvec[jj].GetHitPhi()*3.14159/180.0;
      double sigmax=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*hitvec[jj].GetHitR()*hitvec[jj].GetHitR();
      
      //if(UseJointProb==1)
      //sigmax=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);
      
      ex.push_back(sqrt(sigmax));
 
            
      Sxz += x[jj]*z[jj]/ex[jj]/ex[jj];
      Szz_x += z[jj]*z[jj]/ex[jj]/ex[jj];
      Sz_x += z[jj]/ex[jj]/ex[jj];
      Sx += x[jj]/ex[jj]/ex[jj];
      S0_x += 1.0/ex[jj]/ex[jj];

  }


a_xz = (Sxz*S0_x - Sz_x*Sx) / (Szz_x*S0_x - Sz_x*Sz_x);   // angular coefficient
b_xz = (Sx*Szz_x - Sz_x*Sxz) / (Szz_x*S0_x - Sz_x*Sz_x);  // intercept   R=(a_rz)Z + b_rz

 double e_a_xz = sqrt( S0_x / (S0_x*Szz_x - Sz_x*Sz_x) );
 double e_b_xz = sqrt( Szz_x / (S0_x*Szz_x - Sz_x*Sz_x) );

 std::vector<double> vect;
 for (unsigned int i=0;i<5;i++)
   vect.push_back(0.0);

 vect[0]=a_xz;
 vect[1]=b_xz;
 vect[2]=e_a_xz;
 vect[3]=e_b_xz;

 double correl=(-1.0)*Sz_x*(1.0/(S0_x*Szz_x-(Sz_x*Sz_x)));
 vect[4]=correl;

 return vect;


}


//return (a,b,e_a,e_b,a_b_correl)
std::vector<double> MyLinearfitY(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{  

double Sy=0.;
double Syz=0.;
double Szz_y=0.;
double Sz_y=0.; 
double S0_y=0.; 



unsigned int  sizeHitv=hitvec.size();
std::vector<double> y;
std::vector<double> z;

std::vector<double> ey;
 std::vector<double> ez;

 double a_yz, b_yz;

  for(unsigned int jj =0; jj<sizeHitv; jj++)
    {
      //   std::cout<<hitvec[jj].GetHitR()<<" "<<hitvec[jj].GetHitPhi()<<" "<<hitvec[jj].GetHitZ()<<std::endl;
      y.push_back(hitvec[jj].GetHitY());
      

      z.push_back(hitvec[jj].GetHitZ());    
 
      double phirad=hitvec[jj].GetHitPhi()*3.14159/180.0;
      double sigmay=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitvec[jj].GetHitR()*hitvec[jj].GetHitR();
      
      //     if(UseJointProb==1)
      //sigmay=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);
	
      ey.push_back(sqrt(sigmay));
      
      // er.push_back(0.1);
      
      //ez.push_back(hitvec[jj].GetHitDZ());
            
      Syz += y[jj]*z[jj]/ey[jj]/ey[jj];
      Szz_y += z[jj]*z[jj]/ey[jj]/ey[jj];
      Sz_y += z[jj]/ey[jj]/ey[jj];
      Sy += y[jj]/ey[jj]/ey[jj];
      S0_y += 1.0/ey[jj]/ey[jj];

  }


  a_yz = (Syz*S0_y - Sz_y*Sy) / (Szz_y*S0_y - Sz_y*Sz_y);   // angulay coefficient
  b_yz = (Sy*Szz_y - Sz_y*Syz) / (Szz_y*S0_y - Sz_y*Sz_y);  // intercept   R=(a_rz)Z + b_rz
 double e_a_yz = sqrt( S0_y / (S0_y*Szz_y - Sz_y*Sz_y) );
 double e_b_yz = sqrt( Szz_y / (S0_y*Szz_y - Sz_y*Sz_y) );

  

 std::vector<double> vect;
 for (unsigned int i=0;i<5;i++)
   vect.push_back(0.0);

 vect[0]=a_yz;
 vect[1]=b_yz;
 vect[2]=e_a_yz;
 vect[3]=e_b_yz;

 double correl=(-1.0)*Sz_y*(1.0/(S0_y*Szz_y-(Sz_y*Sz_y)));
 vect[4]=correl;


 return vect;


}


//Return chi2Rprob,chi2R

std::vector<double> T2TrkBasedInternalAlignment::chi2R(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{

  unsigned int  sizeHitv=hitvec.size();
  std::vector<double> vpar=RPhiFit(hitvec);

  double chi2r_=0.;
  for(unsigned int m =0; m<sizeHitv; m++)
    {
      //Warning R should Be updatated!!
      double RR=hitvec[m].GetHitX()*hitvec[m].GetHitX()+hitvec[m].GetHitY()*hitvec[m].GetHitY();
      hitvec[m].SetHitR(sqrt(RR));
      //
      double sigmaR=0.12; 
      if(simufile==false)
	sigmaR=sigmaR*1.5;

      chi2r_=chi2r_+((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitR())/sigmaR)*((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitR())/sigmaR);
    }

  //double chiR_=thetrk.ChiSquaredR();
  double chiR_red=chi2r_/(sizeHitv-2);
  double chi2rprob=TMath::Prob(chi2r_,(sizeHitv-2));


  std::vector<double> retV;
  retV.push_back(chi2rprob);
  retV.push_back(chi2r_);
  retV.push_back(chiR_red);

  return retV;
  
}







//Return chi2xprob,chi2x
std::vector<double> chi2X(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{

  std::vector<double> vpar=MyLinearfitX(hitvec,UseJointProb);
  unsigned int  sizeHitv=hitvec.size();
  double chi2x_=0.;
  for(unsigned int m =0; m<sizeHitv; m++)
    {
      double phirad=hitvec[m].GetHitPhi()*3.14159/180.0;
      double sigmax=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*hitvec[m].GetHitR()*hitvec[m].GetHitR();  
      //if(UseJointProb==1)
      //	sigmax=(0.12*hitvec[m].GetHitR())*(0.12/**hitvec[m].GetHitR()*/);
      
      chi2x_=chi2x_+((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitX())/sigmax)*((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitX())/sigmax);
    }
  //  return chi2x_;
  double chi2prob;
  chi2prob=TMath::Prob(chi2x_,(sizeHitv-2));
  
  std::vector<double> retV;
  retV.push_back(chi2prob);
  retV.push_back(chi2x_);

  double ndeg=1.0*sizeHitv -2;
  retV.push_back((chi2x_/ndeg));
   return retV;
 
}


//Return chi2yprob,chi2y
std::vector<double> chi2Y(std::vector<T2Hit> hitvec,unsigned int UseJointProb)
{

  std::vector<double> vpar=MyLinearfitY(hitvec,UseJointProb);
  unsigned int  sizeHitv=hitvec.size();
  double chi2y_=0.;

  for(unsigned int m =0; m<sizeHitv; m++)
    {
      double phirad=hitvec[m].GetHitPhi()*3.14159/180.0;
      double sigmay=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitvec[m].GetHitR()*hitvec[m].GetHitR();
      // if(UseJointProb==1)
      //sigmay=(0.12*hitvec[m].GetHitR())*(0.12/**hitvec[m].GetHitR()*/);
      chi2y_=chi2y_+((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitY())/sigmay)*((vpar[0]*hitvec[m].GetHitZ()+vpar[1]-hitvec[m].GetHitY())/sigmay);
    }
  
  double chi2prob;
  chi2prob=TMath::Prob(chi2y_,(sizeHitv-2));
  
  std::vector<double> retV;
  retV.push_back(chi2prob);
  retV.push_back(chi2y_);
  double ndeg=1.0*sizeHitv -2;
  retV.push_back((chi2y_/ndeg));

   return retV;
  //return chi2y_;

}

//--------------------------------------------------------------------------------------------------------------------------------------
// END ALIGNMENT PART FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------------

/* 
Return:
vect[0]=a_xz;
vect[1]=b_xz;
vect[2]=a_yz;
vect[3]=b_yz;
vect[4]=e_a_xz;
vect[5]=e_b_xz;
vect[6]=e_a_yz;
vect[7]=e_b_yz;
vect[8]=correl_axbx;
vect[9]=correl_ayby;
*/

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
      //   if(UseJointProb==1)
      //sigmax=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);

      er.push_back(sqrt(sigmax));
      

      double sigmay=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitvec[jj].GetHitR()*hitvec[jj].GetHitR();
      //if(UseJointProb==1)
      //sigmay=(0.12*hitvec[jj].GetHitR())*(0.12/**hitvec[jj].GetHitR()*/);

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

//declMyLinearfitCorr
std::vector<double> MyLinearfitCorr(std::vector<T2Hit> hitvec,TMatrixD &par_covariance_matrix,double &chi2_)
{
  //   std::cout<<"  fun0  ";
  //std::cout<<"Inside MyLinearfitCorr .. init"<<std::endl;

  double sigmaR=0.12;
  double sigmaPhi=0.015;
  unsigned int  sizeHitv=hitvec.size();

  TMatrixD ParCov_matr(4,4); //matrice di covarianza dei parametri trovati;
  unsigned int sizeArighe=sizeHitv*2;
  TMatrixD A(sizeArighe,4);
  TMatrixD At(4,sizeArighe);
  //A ?? la matrice per cui Mis=A(Param)
  TMatrixD Vy(sizeArighe,sizeArighe); //matrice di covarianza delle misure (una per ogni xy, quindi ?? diag a blocchi);
  TMatrixD Vym1(sizeArighe,sizeArighe); 

  TMatrixD Ls(4,4);//((A^T)(Vy^-1)A)
  // TMatrixD Cs(4,4);//(A^T)(Vy^-1)
  TMatrixD Cs(4,sizeArighe);//(A^T)(Vy^-1)

  TVectorD FittedParam(4);
 
  TVectorD Yvect(sizeArighe);

  std::vector<TVectorD> allXY; //vettore degli (xi,yi);
  // std::cout<<"  fun1  ";
  
  for(unsigned int k =0; k<sizeHitv; k++)
    {
      TVectorD insert(2);
      insert[0]=hitvec[k].GetHitX();
      insert[1]=hitvec[k].GetHitY();
      allXY.push_back(insert);
    }
  //std::cout<<"  fun2  ";
  Ls.Zero();
  TMatrixD Ls00(2,2);//un quarto della matrice LS.
  TMatrixD Ls01(2,2);
  TMatrixD Ls10(2,2);
  TMatrixD Ls11(2,2);
  //std::cout<<"  fun3  ";
  TMatrixD Mia(2,2);
  TMatrixD Mib(2,2);

  TMatrixD MiaT(2,2);
  TMatrixD MibT(2,2);

  Ls00.Zero();
  Ls01.Zero();
  Ls10.Zero();
  Ls11.Zero();

  Vy.Zero();
  Vym1.Zero();
  //std::cout<<"  fun4  ";
  //std::cout<<"MyLinearfitCorr Start computation  .. "<<std::endl;

for(unsigned int k =0; k<sizeHitv; k++)
 {
   TMatrixD OneVy(2,2); 
   OneVy.Zero();
   //std::cout<<"  fun4a  ";
   double phirad=hitvec[k].GetHitPhi()*3.14159/180.0;
   double r=hitvec[k].GetHitR();
   //std::cout<<"  fun4aa  ";
   OneVy(0,0)=sigmaR*sigmaR*cos(phirad)*cos(phirad)+r*r*sin(phirad)*sin(phirad)*sigmaPhi*sigmaPhi;

   //std::cout<<"  fun4b  ";
   OneVy(0,1)=cos(phirad)*sin(phirad)*(sigmaR*sigmaR-r*r*sigmaPhi*sigmaPhi);  
   OneVy(1,0)=OneVy(0,1);
   //std::cout<<"  fun4c  ";
   OneVy(1,1)=sigmaR*sigmaR*sin(phirad)*sin(phirad)+ r*r*cos(phirad)*cos(phirad)*sigmaPhi*sigmaPhi;
   //std::cout<<"  fun5  ";
   // std::cout<<OneVy.Determinant()<<"    ";
   if(fabs(OneVy.Determinant())<0.001)
     {
       std::cout<<"Warning!! Determinant < 0.001"<<std::endl;
       OneVy.Print();
     }
   //Invert Vy matrix
   TMatrixD OneVym1(2,2); 
   OneVym1=OneVy;
   Double_t deti;	
   OneVym1.Invert(&deti);
   
   //OneVy.Print();
   if(fabs(deti)<0.001)     
     std::cout<<"Possible Vy Zero Determinant!!!"<<std::endl;
    
   Vym1(2*k,2*k)=OneVym1(0,0);
   Vym1(2*k,2*k+1)= OneVym1(0,1); 
   Vym1(2*k+1,2*k)=OneVym1(1,0);
   Vym1(2*k+1,2*k+1)=OneVym1(1,1);
   

   Vy(2*k,2*k)=OneVy(0,0);
   Vy(2*k,2*k+1)= OneVy(0,1); 
   Vy(2*k+1,2*k)=OneVy(1,0);
   Vy(2*k+1,2*k+1)=OneVy(1,1);

   



   Yvect(2*k)=hitvec[k].GetHitX();
   Yvect(2*k+1)=hitvec[k].GetHitY();  

   A(2*k,0)=hitvec[k].GetHitZ();
   A(2*k,1)=1.0;
   A(2*k,2)=0.0;
   A(2*k,3)=0.0;
   A(2*k+1,0)=0.0;
   A(2*k+1,1)=0.0;
   A(2*k+1,2)=hitvec[k].GetHitZ();
   A(2*k+1,3)=1.0;

     
   //std::cout<<"  fun6  ";
   Mia.Zero();
   Mib.Zero();
   
   
   Mia(0,0)=hitvec[k].GetHitZ();
   Mia(0,1)=0.;
   Mia(1,0)=1.;
   Mia(1,1)=0.;
   Mib(0,0)=0.;
   Mib(0,1)=hitvec[k].GetHitZ();
   Mib(1,0)=0.;
   Mib(1,1)=1.;
   
   MiaT=Mia;
   MibT=Mib;
   MiaT.Transpose(MiaT);
   MibT.Transpose(MibT);  
      

   Ls00=Ls00+Mia*OneVym1*MiaT;
   
   Ls01=Ls01+Mia*OneVym1*MibT;
   
   Ls10=Ls10+Mib*OneVym1*MiaT;
   
   Ls11=Ls11+Mib*OneVym1*MibT;  


 }

//std::cout<<"MyLinearfitCorr Parameter calculation  .. "<<std::endl;

//Nota che qui Vy ?? in realt?? Vy^-1 

 Ls(0,0)=Ls00(0,0);  Ls(0,1)=Ls00(0,1);   Ls(0,2)=Ls01(0,0);   Ls(0,3)=Ls01(0,1);
 Ls(1,0)=Ls00(1,0);  Ls(1,1)=Ls00(1,1);   Ls(1,2)=Ls01(1,0);   Ls(1,3)=Ls01(1,1); 

 Ls(2,0)=Ls10(0,0);  Ls(2,1)=Ls10(0,1);   Ls(2,2)=Ls11(0,0);   Ls(2,3)=Ls11(0,1);
 Ls(3,0)=Ls10(1,0);  Ls(3,1)=Ls10(1,1);   Ls(3,2)=Ls11(1,0);   Ls(3,3)=Ls11(1,1);
 
 // std::cout<<Ls.Determinant()<<"    ";
 if(fabs(Ls.Determinant())<0.001)
     {
       std::cout<<"Warning!! Determinant < 0.001"<<std::endl;
       Ls.Print();
     }
 Double_t determ;	
 Ls.Invert(&determ);
 if(fabs(determ)<0.001)
     std::cout<<"Possible Zero LS  Determinant!!!"<<std::endl;

 At.Zero();
 At.Transpose(A);
 Cs.Zero();
 Cs=At*Vym1;

 //std::cout<<"  fun7  ";
 
 FittedParam= Ls*Cs*Yvect;
 
 //std::cout<<"MyLinearfitCorr FittedParam: "<<std::endl;
 //FittedParam.Print();

 ParCov_matr=At*Vym1*A;

 //std::cout<<ParCov_matr.Determinant()<<"    ";

if(fabs(ParCov_matr.Determinant())<0.001)
     {
       std::cout<<"Warning!! Determinant ParCov_matr< 0.001"<<std::endl;
       ParCov_matr.Print();
     }
 ParCov_matr.Invert(&determ);
 //std::cout<<"MyLinearfitCorr Error Matrix: "<<std::endl;
 //ParCov_matr.Print();

 if(fabs(determ)<0.001)
   std::cout<<"Possible Zero ParCov_matr  Determinant!!!"<<std::endl;  

 //Calcolo chi2
 double chi2=0.;
 TVectorD Residui(sizeArighe);
 Residui=(Yvect-A*FittedParam);
 
 //TVectorD ResiduiT;
 //ResiduiT.Transpose(Residui);
 TVectorD VdotRes(sizeArighe);
  VdotRes=(Vym1*Residui);
 chi2=Residui*VdotRes;
 //std::cout<<"  fun8  ";
 //----------------------
 // Save the output
 //----------------------
 chi2_=chi2;
 
 if(chi2<0)
   {
     std::cout<<"WARNING: MyLinearfitCorr Chi2: "<<chi2<<std::endl;
     std::cout<<"Residui"<<std::endl;
     Residui.Print();
     std::cout<<"Cov Matrix Vy"<<std::endl;
     Vy.Print();
     std::cout<<"Vym1*Residui"<<std::endl;
     VdotRes.Print();

   }
 par_covariance_matrix=ParCov_matr;
 
 //std::cout<<"MyLinearfitCorr Error Matrix: "<<std::endl;
 //par_covariance_matrix.Print();


std::vector<double> vect;

 for (unsigned int i=0;i<10;i++)
   vect.push_back(0.);

 vect[0]=FittedParam(0);
 vect[1]=FittedParam(1);
 vect[2]=FittedParam(2);
 vect[3]=FittedParam(3);
 vect[4]=ParCov_matr(0,0);
 vect[5]=ParCov_matr(1,1);
 vect[6]=ParCov_matr(2,2);
 vect[7]=ParCov_matr(3,3);

 double correlabX=ParCov_matr(0,1);
 vect[8]=correlabX;
 double correlabY=ParCov_matr(2,3);
 vect[9]=correlabY;



 return vect;

}  //should return ax,bx,ay,by,...



/*
bool IsinT2(double eta, double tracketamin, double tracketamax){
  bool flag;
  if ((fabs(eta)>tracketamin)&&(fabs(eta)<tracketamax))
    flag=true;
  else
    flag=false;
  return flag;
}
*/



bool lookforactivepad(edm::Handle<T2HitCollection> t2hitcoll,T1T2Track TrkCit,unsigned int m)
{
 bool flag=false;
 return flag;
}
bool lookforactivestrip(edm::Handle<T2HitCollection> t2hitcoll,T1T2Track TrkCit,unsigned int m)
{
  bool flag=false;
  return flag;
}



//R-PhiFit
std::vector<double> T2TrkBasedInternalAlignment::RPhiFit(std::vector<T2Hit> hitvec)
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
      r.push_back(hitvec[jj].GetHitR());
      
      phi.push_back(hitvec[jj].GetHitPhi());
      z.push_back(hitvec[jj].GetHitZ());    
 

      er.push_back(0.12);
      ephi.push_back(0.1);
      
      ez.push_back(hitvec[jj].GetHitDZ());
            
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

 std::vector<double> vect;
 for (unsigned int i=0;i<10;i++)
   vect.push_back(0.0);

 vect[0]=a_rz;
 vect[1]=b_rz;
 vect[2]=a_phiz;
 vect[3]=b_phiz;
 //std::cout<<vect[0]<<" "<<vect[1]<<" "<<vect[2]<<" "<<vect[3]<<" "<<std::endl;
 
 vect[4]=0.;
 vect[5]=0.;
 vect[6]=0.;
 vect[7]=0.;

 //double correl=(-1.0)*Sz_r*(1.0/(S0_r*Szz_r-(Sz_r*Sz_r)));
 vect[8]=0.;
 // correl=(-1.0)*Sz_phi*(1.0/(S0_phi*Szz_phi-(Sz_phi*Sz_phi)));
 vect[9]=0.;


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

std::vector<double>  OLDResiduiRPhi(std::vector<double> vpar,double r, double phi,double z) //vpar[4]
{
  //double retdrdphi[2];
   std::vector<double> retdrdphi;
 for (unsigned int i=0;i<2;i++)
   retdrdphi.push_back(0.0);

  retdrdphi[0]=(vpar[0]*z+vpar[1]-r);
  retdrdphi[1]=(vpar[2]*z+vpar[3]-phi);  
  return retdrdphi;
}





std::vector<double>  CalculateAlignError(std::vector<double> Disp , std::vector<std::vector<T2Hit> > roads,unsigned int xory)
{
  //if xory==1 ?? x se xory==2 ?? y se no errore! 

  if((xory!=1)&&(xory!=2))
    std::cout<<"Error in CalculateAlignError: x or y fitting not specified "<<std::endl;

  std::vector<double> DispErr;
  std::vector<double> param;
  std::vector<std::vector<double> > Tracksparam;

  for(unsigned int k=0; k<roads.size();k++)
    {
	      
      std::vector<T2Hit> hitv;
	      
      for (unsigned int g=0;g<roads[k].size();g++)
	hitv.push_back(roads[k].at(g));
	      
      TMatrixD covmat(4,4);
      covmat.Zero();
      double chi2corr;	      
      std::vector<double> corrFit=MyLinearfitCorr(hitv,covmat,chi2corr);
      std::vector<double> support;

      unsigned int shiftind=0;
      if(xory==1)
	shiftind=0;
      if(xory==2)
	shiftind=2;

      for(unsigned int c=0;c<2;c++)
	{
	  support.push_back(corrFit[shiftind+c]);
	}
      for (unsigned int c=0;c<2;c++)
	{
	  support.push_back(covmat(shiftind+c,shiftind+c));
	}
      support.push_back(covmat(shiftind,shiftind+1));//(0,1) e (2,3) sono le posizioni di correlaz per fit x-y

      param=support;
      Tracksparam.push_back(param);

    }

  for (unsigned int l=0;l<10;l++)
    DispErr.push_back(0.);
  
  //std::cout<<"Disp size "<<Disp.size()<<std::endl;
  for (unsigned int l=0;l<Disp.size();l++)
    {
      if(fabs(Disp.at(l))>0.01) //There is a saved displacement (you can also put >-1 to evaluate the error also on unprocessed disal.).
	{
	  
	  // double sum=0.;
	  for(unsigned int k=0; k<roads.size();k++)
	    {
	      for (unsigned int g=0;g<roads[k].size();g++)
		{
		  unsigned int symb=RawtoSymb(roads[k].at(g).GetHitDetRawId());
		  
		  if(symb==l)
		    {
		      double phirad=roads[k].at(g).GetHitPhi()*3.14159/180.0;
		      double sigmay2=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR();
		      double sigmax2=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR(); 
		      double sigma2=0.;
		      //double measured=0.;
		      if(xory==1)
			{
			  sigma2=sigmax2;
			  // measured=roads[k].at(g).GetHitX();
			}
		      if(xory==2)
			{
			  sigma2=sigmay2;
			  // measured=roads[k].at(g).GetHitY();
			}
		      DispErr.at(l)=  DispErr.at(l)+/*(measured-Tracksparam.at(k).at(0)*roads[k].at(g).GetHitZ()-Tracksparam.at(k).at(1))*/1.0/sigma2;
		    }
	     
		}
	    }

	  DispErr.at(l)=sqrt(1.0/DispErr.at(l));
	}
      
    }


  return DispErr;
}

double T2TrkBasedInternalAlignment::HitError(T2Hit* hit, const char * coord)
{
 
  double used=0.;
  double phirad=hit->GetHitPhi()*3.14159/180.0;

  double DRresol=DR_Resol_mm;
  double DPhiResol=DPhiResol_Deg*3.14159/180.0;
  double sigmay2FromResol=sin(phirad)*sin(phirad)*DRresol*DRresol+cos(phirad)*cos(phirad)*DPhiResol*DPhiResol*hit->GetHitR()*hit->GetHitR();
  double sigmax2FromResol=cos(phirad)*cos(phirad)*DRresol*DRresol+sin(phirad)*sin(phirad)*DPhiResol*DPhiResol*hit->GetHitR()*hit->GetHitR(); 

  if((strcmp(coord, "X") != 0)&&(strcmp(coord, "Y") != 0)&&(strcmp(coord, "R") != 0)&&(strcmp(coord, "Phi") != 0))
    std::cout<<"Error: HitError function not called properly"<<std::endl;
  else
    {
      if(strcmp(coord, "X") == 0)
	{
	  if((hit->GetHitDX()>0)&&(hit->GetHitDX()<10)&&(UseHitErrorFromResol==false))
	    used=hit->GetHitDX();
	  else
	    used=sqrt(sigmax2FromResol);
	}

      if(strcmp(coord, "Y") == 0)
	{
	  if((hit->GetHitDY()>0)&&(hit->GetHitDY()<10)&&(UseHitErrorFromResol==false))
	    used=hit->GetHitDY();
	  else
	    used=sqrt(sigmay2FromResol);
	}
	
      if(strcmp(coord, "R") == 0)
	{
	  if((hit->GetHitDR()>0)&&(hit->GetHitDR()<4)&&(UseHitErrorFromResol==false))
	    used=hit->GetHitDR();
	  else
	    used=DRresol;
	}

      if(strcmp(coord, "Phi") == 0)
	{
	  if((hit->GetHitDPhi()>0)&&(hit->GetHitDPhi()<15)&&(UseHitErrorFromResol==false))
	    used=hit->GetHitDPhi();
	  else
	    used=DPhiResol;	
	}
    }

  return used;

}



std::vector<double>  T2TrkBasedInternalAlignment::CalculateAlignError2(std::vector<double> Disp , std::vector<std::vector<T2Hit> > roads,unsigned int xory, bool CalculateErrorForWholeHalf,std::vector<double> ErrIterBefore)
{
  //if xory==1 ?? x se xory==2 ?? y se no errore! 

  // std::cout<<"CalculateAlignError2 procedure"<<std::endl;
  
  if((xory!=1)&&(xory!=2))
    std::cout<<"Error in CalculateAlignError: x or y fitting not specified "<<std::endl;

  std::vector<double> DispErr;
  std::vector<double> param;

  std::vector<double> denominator;
  std::vector<double> numerator;
  std::vector<double> sig2_xij;
  std::vector<double> zijsig_ajbj;
  std::vector<double> zijzijsig2_aj;
  std::vector<double> sig2_bj;
  std::vector<double> zijsig_bjaj;

  
  std::vector<std::vector<double> > Tracksparam;

  for(unsigned int k=0; k<roads.size();k++)
    {
	      
      std::vector<T2Hit> hitv;
	      
      for (unsigned int g=0;g<roads[k].size();g++)
	hitv.push_back(roads[k].at(g));
	      
      TMatrixD covmat(4,4);
      covmat.Zero();
      double chi2corr;	      
      std::vector<double> corrFit=MyLinearfitCorr(hitv,covmat,chi2corr);
      std::vector<double> support;

      unsigned int shiftind=0;
      if(xory==1)
	shiftind=0;
      if(xory==2)
	shiftind=2;

      for(unsigned int c=0;c<2;c++)
	{
	  support.push_back(corrFit[shiftind+c]);
	}
      for (unsigned int c=0;c<2;c++)
	{
	  support.push_back(covmat(shiftind+c,shiftind+c));
	}

      //  std::cout<<"aj-erraj= "<<support.at(0)<<"-"<<support.at(2)<<std::endl;
      support.push_back(covmat(shiftind,shiftind+1));

      param=support;
      Tracksparam.push_back(param);

    }

  double ARMdenominator=0.;
  double ARMnumerator=0.;    

  for (unsigned int l=0;l<10;l++)
    {
      DispErr.push_back(0.);
      denominator.push_back(0.);
      numerator.push_back(0.);
      sig2_xij.push_back(0.);
      zijsig_ajbj.push_back(0.);	
      sig2_bj.push_back(0.);
      zijzijsig2_aj.push_back(0.);
      zijsig_bjaj.push_back(0.);
    }

  std::cout<<"CalculateAlignError2: Vector of displacement has size "<<Disp.size()<<std::endl;
  for (unsigned int l=0;l<Disp.size();l++)
    {
      if(fabs(Disp.at(l))>0.001) //There is a saved displacement (you can also put >-1 to evaluate the error also on unprocessed disal.).
	{
	  
	  // double sum=0.;


	  //Di=(1/denominator)sum_j{xij-aj*zij-bj}
	  //simga^2(Di)=(1/denominator)^2*sum_j{simga^2(xij)+zij^{2}*simga^2(aj)+zij*sigma(ajbj)+simga^2(bj)+zij*simga(bjaj)}

	  for(unsigned int k=0; k<roads.size();k++)
	    {
	      for (unsigned int g=0;g<roads[k].size();g++)
		{
		  unsigned int symb=RawtoSymb(roads[k].at(g).GetHitDetRawId());
		  symb=symb%10;
		  if((symb==l)||(CalculateErrorForWholeHalf==true))
		    {
		      double phirad=roads[k].at(g).GetHitPhi()*3.14159/180.0;
		      double sigmay2=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR();
		      double sigmax2=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR(); 


		      SimuErrDX->Fill(sqrt(sigmax2));
		      SimuErrDY->Fill(sqrt(sigmay2));
		      
		      double sigma2=0.;
		      //  double measured=0.;
		      
		      double directsigmaX=roads[k].at(g).GetHitDX();
	              double directsigmaY=roads[k].at(g).GetHitDY();	    
    	
		    
		      if(xory==1)
			{
			  sigma2=sigmax2;
			  if((directsigmaX>0.)&&(directsigmaX<10.))
			    sigma2=directsigmaX*directsigmaX;
			  //	  measured=roads[k].at(g).GetHitX();
			}
		      if(xory==2)
			{
			  sigma2=sigmay2;
			  if((directsigmaY>0.)&&(directsigmaY<10.))
			    sigma2=directsigmaY*directsigmaY;
			  //	  measured=roads[k].at(g).GetHitY();
			}
		      //correct for Hit position uncertainties due to previous alignment
		      if(ErrIterBefore.size()==10)
			sigma2=sigma2+ErrIterBefore.at(symb)*ErrIterBefore.at(symb);
		      // else is for half-half align
		      //std::cout<<"ErrIterBefore.size != 10"<<std::endl;

		      double Th_Pos_Unc=(roads[k].at(g).GetHitZ()*roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(2)+2*roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(4)+Tracksparam.at(k).at(3));

		      denominator.at(l)=denominator.at(l)+(1.0)/sigma2;
		      numerator.at(l)=numerator.at(l)+((sigma2+Th_Pos_Unc)/(sigma2*sigma2));

		      sig2_xij.at(l)+=sigma2;
		      zijsig_ajbj.at(l)+=roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(4);
		      zijzijsig2_aj.at(l)+=roads[k].at(g).GetHitZ()*roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(2);
		      sig2_bj.at(l)+=Tracksparam.at(k).at(3);
		      zijsig_bjaj.at(l)+=roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(4);
		      

		      if(CalculateErrorForWholeHalf==true)
			{
			  if(ErrIterBefore.size()==1)
			    sigma2=sigma2+ErrIterBefore.at(0)*ErrIterBefore.at(0);
			  ARMdenominator=ARMdenominator+(1.0)/sigma2;
			  ARMnumerator=ARMnumerator+((sigma2+Th_Pos_Unc)/(sigma2*sigma2));
			}

		      //  std::cout<<"a "<<Tracksparam.at(k).at(0)<<"+-"<<sqrt(Tracksparam.at(k).at(2))<<std::endl;
		      //  std::cout<<"b "<<Tracksparam.at(k).at(1)<<"+-"<<(Tracksparam.at(k).at(3))<<std::endl;
		      //  std::cout<<"sigma2_a "<<Tracksparam.at(k).at(2)<<std::endl;
		      //  std::cout<<"sigma2_b "<<Tracksparam.at(k).at(3)<<std::endl;
		      // 
		      // std::cout<<"Th_Pos_Unc "<<sqrt(Th_Pos_Unc)<<std::endl;
		      // std::cout<<"Z2 "<<roads[k].at(g).GetHitZ()*roads[k].at(g).GetHitZ()<<std::endl;
		      //std::cout<<"sigma2Meas "<<sigma2<<std::endl;
		      //std::cout<<"sig_ajbj"<<Tracksparam.at(k).at(4)<<std::endl;
		      //std::cout<<"zij*sig_ajbj "<<roads[k].at(g).GetHitZ()*Tracksparam.at(k).at(4)<<std::endl;
		    }
	     
		}
	    }
	  
	  //std::cout<<"|denominator: "<<denominator.at(l)<<" |sig2_xij: "<<sig2_xij.at(l)<<"|zijzijsig2: "<<+zijzijsig2_aj.at(l)<<" |"<<std::endl;
	  DispErr.at(l)=sqrt(numerator.at(l)/(denominator.at(l)*denominator.at(l)));
	  double MeasuredXYResol;
	  if(xory==1)
	    MeasuredXYResol=MeasuredResol_X;
	  else
	    MeasuredXYResol=MeasuredResol_Y;
	 	  
	  if(DispErr.at(l)<MeasuredXYResol)
	    DispErr.at(l)=MeasuredXYResol;
	 
	  std::cout<<"Det "<<l<<": Align  Error= "<<DispErr.at(l)<<"     ";
	 
	}
      
    }

  
  std::cout<<" "<<std::endl;
  return DispErr;
}

 

//Error strategy seen in cms paper: Error at the last iteration as the inverse of the second derivative of the chi-square
//Note: the sigmaJ-i is now the the sigma on the xij-ajzij-bj addend.
double T2TrkBasedInternalAlignment::CalculateAlignHIP(std::vector<std::vector<T2Hit> > roads,unsigned int xory, unsigned int thehalf,unsigned int plane0_9)
{

  // std::cout<<" ********** Hip ErrorEstim plane "<<plane0_9 <<", Quarter "<<thehalf<<" **************************************************** "<<std::endl;
  //  std::cout<<"Hip ErrorEstim A"<<std::endl;
  
  if((xory!=1)&&(xory!=2))
    std::cout<<"Error in CalculateAlignError: x or y fitting not specified "<<std::endl;

  std::vector<double> DispErr;
  // std::vector<double> param;

  double SecondDerivative=0.;
  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;
  
  std::vector<std::vector<double> > Tracksparam;
  std::vector<std::vector<T2Hit> > roadsZgrav0;
  //std::cout<<"Hip ErrorEstim B"<<std::endl;

  for(unsigned int k=0; k<roads.size();k++)
    {
	      
      std::vector<T2Hit> hitv;
      //std::cout<<"Hip ErrorEstim B0"<<std::endl;
      // std::vector<T2Hit> hitvForResidual=GiveMeTheHitForResidual(absSymb,thisroad);	     	
      for (unsigned int g=0;g<roads[k].size();g++)
	{
	  planeinfo=conv.GetT2Info(roads[k].at(g).GetHitDetRawId());
	  //std::cout<<"Hip ErrorEstim B1_0"<<std::endl;
	  unsigned int thesymb=planeinfo.symb;
	  if(thesymb!=(plane0_9+thehalf*10))
	    hitv.push_back(roads[k].at(g));

	  //  std::cout<<"Hip ErrorEstim B1"<<std::endl;
	}   
      

      double ZGraV=0.;
      for(unsigned int ff=0;ff<hitv.size();ff++)
	{
	  ZGraV+=hitv.at(ff).GetHitZ();
	}
      // ZGraV=ZGraV/((double)hitv.size());
      ZGraV=ZGraV/(hitv.size());
      for(unsigned int ff=0;ff<hitv.size();ff++)
	{
	  hitv.at(ff).SetHitZ(hitv.at(ff).GetHitZ()-ZGraV);
	}
      
      //std::cout<<"Hip ErrorEstim B2"<<std::endl;
      //TMatrixD covmat(4,4);
      //covmat.Zero();
      //double chi2corr;	      
      std::vector<double> corrFit=MyLinearfit(hitv,UseJointProb);
	//MyLinearfitCorr(hitv,covmat,chi2corr);
      std::vector<double> support;
      //  std::cout<<"Hip ErrorEstim B1a"<<std::endl;
      unsigned int shiftind=0;
      if(xory==1)
	shiftind=0;
      if(xory==2)
	shiftind=2;
      /*
      vect[0]=a_xz;
      vect[1]=b_xz;
      vect[2]=a_yz;
      vect[3]=b_yz;
      vect[4]=e_a_xz;
      vect[5]=e_b_xz;
      vect[6]=e_a_yz;
      vect[7]=e_b_yz;
      */
      //std::cout<<"Hip ErrorEstim B2"<<std::endl;
      for(unsigned int c=0;c<2;c++)
	{
	  support.push_back(corrFit[shiftind+c]);
	}
      for(unsigned int c=0;c<2;c++)
	{
	  support.push_back(corrFit[4+shiftind+c]);
	}
      // for (unsigned int c=0;c<2;c++)
      //{
      //  support.push_back(covmat(shiftind+c,shiftind+c));
      //}
      //std::cout<<"Hip ErrorEstim B3"<<std::endl;
      //  std::cout<<"aj-erraj= "<<support.at(0)<<"-"<<support.at(2)<<std::endl;
      //support.push_back(covmat(shiftind,shiftind+1));
      //      std::cout<<"Hip ErrorEstim B4"<<std::endl;
      //  param=support;
      
      Tracksparam.push_back(support);
      roadsZgrav0.push_back(hitv);
    }

  //  std::cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<Tracksparam.size()<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<roads.size()<<std::endl;
  //std::cout<<"Hip ErrorEstim C"<<std::endl;


  for(unsigned int k=0; k<roads.size();k++)
    {

      double ZGraV=0.;
      int count=0;
      for(unsigned int ff=0;ff<roads[k].size();ff++)
	{
	  planeinfo=conv.GetT2Info(roads[k].at(ff).GetHitDetRawId());	 
	  unsigned int thesymb=planeinfo.symb;
	  if(thesymb!=(plane0_9+thehalf*10))
	    {
	      ZGraV+=roads[k].at(ff).GetHitZ();
	      count++;
	    }
	}    

      ZGraV=ZGraV/count;

      for (unsigned int g=0;g<roads[k].size();g++)
	{
	 
	  planeinfo=conv.GetT2Info(roads[k].at(g).GetHitDetRawId());	
	  if(planeinfo.symb==(plane0_9+thehalf*10))
	    {
	      double phirad=roads[k].at(g).GetHitPhi()*3.14159/180.0;
	      double sigmay2=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR();
	      double sigmax2=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*roads[k].at(g).GetHitR()*roads[k].at(g).GetHitR(); 
	      
	      double sigma2=0.;
	      // double measured=0.;
		      
	      double directsigmaX=roads[k].at(g).GetHitDX();
	      double directsigmaY=roads[k].at(g).GetHitDY();	    
    	  
	      if(xory==1)
		{
		  sigma2=sigmax2;
		  if((directsigmaX>0.)&&(directsigmaX<10.))
		    sigma2=directsigmaX*directsigmaX;
		  //  measured=roads[k].at(g).GetHitX();
		}

	      if(xory==2)
		{
		  sigma2=sigmay2;
		  if((directsigmaY>0.)&&(directsigmaY<10.))
		    sigma2=directsigmaY*directsigmaY;
		  //  measured=roads[k].at(g).GetHitY();
		}
		     
	      double Th_Pos_Unc=((roads[k].at(g).GetHitZ()-ZGraV)*(roads[k].at(g).GetHitZ()-ZGraV)*Tracksparam.at(k).at(2)*Tracksparam.at(k).at(2)+Tracksparam.at(k).at(3)*Tracksparam.at(k).at(3));
		      
	      //  std::cout<<" $$$  "<<Tracksparam.at(k).at(2)<<"  "<<Tracksparam.at(k).at(3)<<"  "<<sigma2;
	      
	      SecondDerivative=SecondDerivative+1.0/((sigma2+Th_Pos_Unc));
	      //std::cout<<SecondDerivative<<"  ^^  ";
	      
	    }
	}
    }

  double the_error=sqrt(1.0/(SecondDerivative));
  //std::cout<<"Hip ErrorEstim Exit"<<std::endl;
  return the_error;

  // std::cout<<" ************************************************************** "<<std::endl;
}





bool HitIndetector(std::vector<double> vpar, unsigned int symbdetid,std::map<unsigned int,double> mapsymbtoZ)
{
  bool flag=false;
  double z=0.;
  double expY;
  double expX;
  double expRaggio;
  if((mapsymbtoZ.find(symbdetid))!= mapsymbtoZ.end())
    {
      std::map<unsigned int,double>::iterator Itr;
      Itr=mapsymbtoZ.find(symbdetid);      
      z=Itr->second;
      expX = (vpar[0]*z+vpar[1]); 
      expY=(vpar[2]*z+vpar[3]);
      expRaggio=sqrt(expX*expX+expY*expY);
      
      if((expX<144.)&&(expX>(-144.))) //144, 42
	{
	  if((fabs(expY)<144.)&&(fabs(expY)>(-144.)))
	    {
	      if((expRaggio>42.)&&(expRaggio<144.))
		{
		  flag=true;
		}
	      else
		std::cout<<"Raggio Aspettato Fuori det: "<<expRaggio<<std::endl;
	    }
	  else
	    std::cout<<"Y Aspettato Fuori det: "<<expY<<std::endl;
	}
      else
	std::cout<<"X Aspettato Fuori det:"<<expX<<std::endl;
    }
  else
    {
      //L'associazione non c'e' ancora.Metto flag=false per ignorare l'evento
      std::cout<<"HitIndetector: DETECTOR not yet ASSIGNED "<<std::endl;
      flag=false;
    }


  //if(flag==false)
  //std::cout<<"Expected hit out of detector; X="<<expr<<"Y="<<expphi<<" R="<<expRaggio  <<" Z="<<z<<"  Symb="<<symbdetid<<std::endl;
 
  return flag;
}


std::vector<T2Hit> T2TrkBasedInternalAlignment::GiveMeTheHitForResidual(unsigned int planeIdToExclude, std::vector<T2Hit>  hitv)
{

  std::vector<T2Hit> returnedVect;
  for(unsigned int i=0;i<hitv.size();i++)
    {
      if(hitv.at(i).GetHitDetRawId()!=planeIdToExclude)
	returnedVect.push_back(hitv.at(i));
    }

  //std::cout<<"Sizebef: "<<hitv.size()<<"Sizeaft: "<<returnedVect.size()<<"  |   ";
  return returnedVect;
}


int T2TrkBasedInternalAlignment::TrackIsInTwoQuarter(T1T2TrackCollection::const_iterator  trk, unsigned int howmanyhit)
{
  int flag=-1;
   T2GeometryUtil conv;
   T2GeometryUtil::T2DetInfo planeinfo;
   unsigned int trkh0=0;
   unsigned int trkh1=0;
   int arm=-1;

   for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
    {
       planeinfo=conv.GetT2Info(((*trk).GetHitT2(a)).GetHitDetRawId());
       if(planeinfo.ht==0)
	 {
	   trkh0++;
	   arm=planeinfo.arm;
	 }
       if(planeinfo.ht==1)
	 {
	   trkh1++;
	   arm=planeinfo.arm;
	 }
    }

   
   if((trkh0>=howmanyhit)&&(trkh1>=howmanyhit))
     {
       std::cout<<"Track has "<<trkh0<<"/"<<trkh1<<" hits in half 0/1. Trk Phi="<<(trk->Phi()*180/3.14159)<<std::endl;
       flag=arm;
       std::cout<<"and can be usef used for arm "<<flag<<std::endl;
     }

  return flag;
}


int T2TrkBasedInternalAlignment::TrackIsInOneQuarter(T1T2TrackCollection::const_iterator  trk, unsigned int howmanyhit)
{
  int flag=-1;
   T2GeometryUtil conv;
   T2GeometryUtil::T2DetInfo planeinfo;
   unsigned int trkh0=0;
   unsigned int trkh1=0;
   unsigned int arm=0;
  
   for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
    {
       planeinfo=conv.GetT2Info(((*trk).GetHitT2(a)).GetHitDetRawId());
       if(planeinfo.ht==0)
	 {
	   trkh0++;
	   arm=planeinfo.arm;
	 }
       if(planeinfo.ht==1)
	 {
	   trkh1++;
	   arm=planeinfo.arm;
	 }
    }

   if((trkh0>=howmanyhit)&&(trkh1==0))
     flag=0+arm*2;

   if((trkh1>=howmanyhit)&&(trkh0==0))
     flag=1+arm*2;

    
  return flag;
}


void T2TrkBasedInternalAlignment::CorrectRoadHitsInOverlap( std::vector<std::vector<T2Hit> > *roadfitOverlapARM,   std::vector<double> TotDXDisphalf0,  std::vector<double> TotDYDisphalf0, std::vector<double> TotDXDisphalf1, std::vector<double> TotDYDisphalf1)
{

  std::cout<<"Begin T2TrkBasedInternalAlignment::CorrectRoadHitsInOverlap"<<std::endl;
  for(unsigned int rd=0;rd<TotDXDisphalf0.size();rd++)
    {      
      std::cout<<rd<<"||"<<TotDXDisphalf0.at(rd)<<"||"<<TotDYDisphalf0.at(rd)<<std::endl;
    }

  for(unsigned int rd=0;rd<TotDXDisphalf1.size();rd++)
    {
      std::cout<<rd<<"||"<<TotDXDisphalf1.at(rd)<<"||"<<TotDYDisphalf1.at(rd)<<std::endl;
    }

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;

  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
    {
      std::vector<T2Hit> thisroad=roadfitOverlapARM->at(rd);
      
      for(unsigned int hit=0;hit<thisroad.size();hit++)
	{
	  planeinfo=conv.GetT2Info(thisroad.at(hit).GetHitDetRawId());
	  if(planeinfo.ht==0)
	    {
	      thisroad.at(hit).SetHitX(thisroad.at(hit).GetHitX()-TotDXDisphalf0.at((planeinfo.symb%10)));
	      thisroad.at(hit).SetHitY(thisroad.at(hit).GetHitY()-TotDYDisphalf0.at((planeinfo.symb%10)));
	      thisroad.at(hit).SetHitR(sqrt(thisroad.at(hit).GetHitX()*thisroad.at(hit).GetHitX()+thisroad.at(hit).GetHitY()*thisroad.at(hit).GetHitY()));
	    }
	  if(planeinfo.ht==1)
	    {
	      thisroad.at(hit).SetHitX(thisroad.at(hit).GetHitX()-TotDXDisphalf1.at((planeinfo.symb%10)));
	      thisroad.at(hit).SetHitY(thisroad.at(hit).GetHitY()-TotDYDisphalf1.at((planeinfo.symb%10)));
	      thisroad.at(hit).SetHitR(sqrt(thisroad.at(hit).GetHitX()*thisroad.at(hit).GetHitX()+thisroad.at(hit).GetHitY()*thisroad.at(hit).GetHitY()));
	    }
	}      
      roadfitOverlapARM->at(rd)=thisroad;
    }

}


//ricominciadaqui

T1T2Track  T2TrkBasedInternalAlignment::GiveMeTrkHalfPart(T1T2TrackCollection::const_iterator  TrkCit, unsigned int wantedhalf)
{
 
 
  
  //(*trk).GetHitT2(a).GetHitPlane()>4
  std::vector<T2Hit> hitvec;
  for(unsigned int h=0;h<(*TrkCit).GetHitEntries();h++)
    {
      if((*TrkCit).GetHitT2(h).GetHitHalftele()==wantedhalf)
	hitvec.push_back((*TrkCit).GetHitT2(h));      	
    }

  T1T2Track Onetrk=T2CutsUtilForAl.TrackFromHits(true,hitvec);//(bool DoXYTrkFit, std::vector<T2Hit> hitvec)
    
  //std::cout<<"From GiveMeTrkHalfPart: trk builded with "<<Onetrk.GetHitEntries()<<"hit"<<std::endl;

  //trkColl_i->push_back(Onetrk);  

  //  T1T2TrackCollection::const_iterator trkiter = trkColl_i->begin(); 

 
  return Onetrk;
}

bool T2TrkBasedInternalAlignment::IsTrkInFULLAccept(std::vector<T2Hit> trkhit, unsigned int wantedhalf)
{
  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;
  //  unsigned int arm=wantedhalf/2;
  bool foundfirsth0=false;
  bool foundlasth0=false;
  for(unsigned int i=0;i<trkhit.size();i++)
    {
      planeinfo=conv.GetT2Info(trkhit.at(i).GetHitDetRawId());
      if((planeinfo.pl_0to9==0)&&(planeinfo.ht==(wantedhalf%2)))
	foundfirsth0=true;
      if((planeinfo.pl_0to9==9)&&(planeinfo.ht==(wantedhalf%2)))
	foundlasth0=true;
   }
  bool flag=false;
  if((foundfirsth0==true)&&(foundlasth0==true))
    flag=true;

  return flag;
}


bool T2TrkBasedInternalAlignment::IsOverlappingTrkInAccept(std::vector<T2Hit>   PartofTrackinH0,std::vector<T2Hit>   PartofTrackinH1, unsigned int halftoalign)
{
  
 T2GeometryUtil conv;
 T2GeometryUtil::T2DetInfo planeinfo;
 //unsigned int arm=halftoalign/2;
 bool foundfirsth0=false;
 bool foundlasth0=false;
 // double ther0h0=0;
 // double ther0h1=0;
 for(unsigned int i=0;i<PartofTrackinH0.size();i++)
   {
     planeinfo=conv.GetT2Info(PartofTrackinH0.at(i).GetHitDetRawId());
     if(planeinfo.pl_0to9==0)
       {
	 foundfirsth0=true;
	 //	 ther0h0=PartofTrackinH0.at(i).GetHitR();
       }
     if(planeinfo.pl_0to9==9)
       foundlasth0=true;
   }
 
 
 bool foundfirsth1=false;
 bool foundlasth1=false;
 for(unsigned int i=0;i<PartofTrackinH1.size();i++)
   {
     planeinfo=conv.GetT2Info(PartofTrackinH1.at(i).GetHitDetRawId());
     if(planeinfo.pl_0to9==0)
       {
	 foundfirsth1=true;
	 // ther0h1=PartofTrackinH1.at(i).GetHitR();
       }
     if(planeinfo.pl_0to9==9)
       foundlasth1=true;
   }

 //std::cout<<" || foundfirsth0 "<<foundfirsth0<<"  foundlasth0 "<<foundlasth0<<"  foundfirsth1 "<<foundfirsth1<<"  foundlasth1 "<<foundlasth1<<std::endl;

 bool flag=false;
 if((foundfirsth0==true)&&(foundlasth0==true)&&(foundfirsth1==true)&&(foundlasth1==true))
   flag=true;
   //  if((ther0h1>49.0)&&(ther0h0>49.0))
     

 return flag;
}



void T2TrkBasedInternalAlignment::MakeQuarterQuarterMisalHisto(std::vector<std::vector<T2Hit> > *roadfitOverlapARM,unsigned int halftoalign)
{
  unsigned int histoStartindex=0;
  //std::cout<<"MakeQuarterQuarterMisalHisto"<<std::endl;
  
  //If you want to align all the arm  at the same time and if you are looking now at the arm 1, the index start from 10
  //So: histo 0-10 -> one arm. histo 10-20-> arm 1 in case of two arms
  if(RefHalfsWholeQuarterAlign.size()==2)
    if(halftoalign>=2)
      {
	histoStartindex=10;
      }
  
  std::cout<<"Begin T2TrkBasedInternalAlignment::MakeQuarterQuarterMisalHisto  size: "<<roadfitOverlapARM->size()<<std::endl;
  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;

  std::vector<std::vector<T2Hit> > TracksinH0ForXal;
  std::vector<std::vector<T2Hit> > TracksinH1ForXal;  
  
  std::vector<std::vector<T2Hit> > TracksinH0ForYal;
  std::vector<std::vector<T2Hit> > TracksinH1ForYal; 
  
  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
    {
      std::vector<T2Hit> thisroad=roadfitOverlapARM->at(rd);
      std::vector<T2Hit>  PartofTrackinH0;
      std::vector<T2Hit>  PartofTrackinH1;

      //std::cout<<thisroad.size()<<"   ";

      for(unsigned int hit=0;hit<thisroad.size();hit++)
	{
	  planeinfo=conv.GetT2Info(thisroad.at(hit).GetHitDetRawId());
	  if(planeinfo.ht==0)
	    { 
	      PartofTrackinH0.push_back(thisroad.at(hit));
	    }
	  else
	    {
	      PartofTrackinH1.push_back(thisroad.at(hit));
	    }
	}
      
      bool BothInAcceptance=false;
      BothInAcceptance=IsOverlappingTrkInAccept(PartofTrackinH0,PartofTrackinH1,halftoalign);
      
      
      if((PartofTrackinH1.size()>=7)&&(PartofTrackinH0.size()>=7))
	if(BothInAcceptance)
	  {
	    if((PartofTrackinH0.at(0).GetHitR()<RMaxOverlapXalignHisto)&&(PartofTrackinH1.at(0).GetHitR()<RMaxOverlapXalignHisto))
	      {
		TracksinH0ForXal.push_back(PartofTrackinH0);
		TracksinH1ForXal.push_back(PartofTrackinH1);
	      }

	    if((PartofTrackinH0.at(0).GetHitR()<RMaxOverlapYalignHisto)&&(PartofTrackinH1.at(0).GetHitR()<RMaxOverlapYalignHisto))
	      if((PartofTrackinH0.at(0).GetHitY()/PartofTrackinH0.at(0).GetHitR()>0.7))
		{
		  TracksinH0ForYal.push_back(PartofTrackinH0);
		  TracksinH1ForYal.push_back(PartofTrackinH1);
		}
	  }
    }


  std::vector<std::vector<T2Hit> >* TracksofNonRefForXal;
  std::vector<std::vector<T2Hit> >* TracksofRefForXal;
  std::vector<std::vector<T2Hit> >* TracksofNonRefForYal;
  std::vector<std::vector<T2Hit> >* TracksofRefForYal;


  if((halftoalign%2)==0)
    {
      TracksofNonRefForXal=&TracksinH0ForXal;
      TracksofRefForXal=&TracksinH1ForXal;

      TracksofNonRefForYal=&TracksinH0ForYal;
      TracksofRefForYal=&TracksinH1ForYal;
      //TracksofNonRef=&TracksinH0;
      //TracksofRef=&TracksinH1;
    }
  else
    {
      TracksofNonRefForXal=&TracksinH1ForXal;
      TracksofRefForXal=&TracksinH0ForXal;

      TracksofNonRefForYal=&TracksinH1ForYal;
      TracksofRefForYal=&TracksinH0ForYal;
      //TracksofNonRef=&TracksinH1;
      //TracksofRef=&TracksinH0;
    }


  //Start the fitting
  double ax,ay,bx,by;
  double shiftx,shifty;
  double hitZ,hitX,hitY;
  unsigned int finalIndexforHisto;
  std::cout<<"HistoQuarterQuarter:   NonRef_X= "<<TracksofNonRefForXal->size()<<"  NonRef_Y= "<<TracksofNonRefForYal->size()<<std::endl;
  std::cout<<"HistoQuarterQuarter:   Ref_X= "<<TracksofRefForXal->size()<<"  Ref_Y= "<<TracksofRefForYal->size()<<std::endl;

  for(unsigned int j=0; j<TracksofNonRefForXal->size();j++)
    {
      std::vector<T2Hit> hitvRef =  TracksofRefForXal->at(j);   //NOTE THIS!!
      std::vector<double> corrFit=T2CutsUtilForAl.MyLinearfitXYSimple(hitvRef);      
      ax=corrFit[0];
      bx=corrFit[1];
      //ay=corrFit[2];
      //by=corrFit[3];
      std::vector<T2Hit> hitvNonRef =  TracksofNonRefForXal->at(j);   //NOTE THIS!!
      for(unsigned m=0;m<hitvNonRef.size();m++)
	{
	  hitZ=hitvNonRef.at(m).GetHitZ();
	  hitX=hitvNonRef.at(m).GetHitX();
	  //  hitY=hitvNonRef.at(m).GetHitY();  
	  shiftx=ax*hitZ+bx-hitX;
	  //shifty=ay*hitZ+by-hitY;

	  planeinfo=conv.GetT2Info(hitvNonRef.at(m).GetHitDetRawId());
	  finalIndexforHisto=histoStartindex+planeinfo.pl_0to9;
	  QuarterQuarterReltiveDX.at(finalIndexforHisto)->Fill(shiftx);
	  //  std::cout<<"Ind-shiftx="<<finalIndexforHisto<<"-"<<shiftx<<"       ";
	  //QuarterQuarterReltiveDY.at(finalIndexforHisto)->Fill(shifty);  

	}
    }

  for(unsigned int j=0; j<TracksofNonRefForYal->size();j++)
    {
      std::vector<T2Hit> hitvRef =  TracksofRefForYal->at(j);   //NOTE THIS!!
      std::vector<double> corrFit=T2CutsUtilForAl.MyLinearfitXYSimple(hitvRef);      
      //ax=corrFit[0];
      //bx=corrFit[1];
      ay=corrFit[2];
      by=corrFit[3];
      std::vector<T2Hit> hitvNonRef =  TracksofNonRefForYal->at(j);   //NOTE THIS!!
      for(unsigned m=0;m<hitvNonRef.size();m++)
	{
	  hitZ=hitvNonRef.at(m).GetHitZ();
	  //hitX=hitvNonRef.at(m).GetHitX();
	  hitY=hitvNonRef.at(m).GetHitY();  
	  //shiftx=ax*hitZ+bx-hitX;
	  shifty=ay*hitZ+by-hitY;

	  planeinfo=conv.GetT2Info(hitvNonRef.at(m).GetHitDetRawId());
	  finalIndexforHisto=histoStartindex+planeinfo.pl_0to9;
	  //QuarterQuarterReltiveDX.at(finalIndexforHisto)->Fill(shiftx);
	  QuarterQuarterReltiveDY.at(finalIndexforHisto)->Fill(shifty);  
	  //std::cout<<"Ind-shifty="<<finalIndexforHisto<<"-"<<shifty<<"       ";
	}
    }



  //              Make final Histograms
  
  TF1 *fx= new TF1("fx","gaus",-2.7,2.7);
  TF1 *fy= new TF1("fy","gaus",-2.7,2.7);


  const unsigned int n=10;//QuarterQuarterReltiveDX.size();
  // Double_t det[n];

  TF1* Fy[n];
  TF1* Fx[n];
  if(false)
    std::cout<<Fx[0]->GetRandom()<<std::endl;
  
  Double_t dy[n];
  Double_t dx[n];

  Double_t sigmay[n];
  Double_t sigmax[n];

  // Double_t Ey[n];
  // Double_t Ex[n];
  // Double_t allzero[n];

  //  Double_t ErrMeany[n];
    Double_t ErrMeanx[n];
    //Double_t Meany[n];
  Double_t Meanx[n];
 

  for(unsigned int i=0;i<n;i++)
    {
      // det[i]=i;
      // allzero[i]=0;
      QuarterQuarterReltiveDX[histoStartindex+i]->Fit("fx","R0Q");
      dx[i]=fx->GetParameter(1);
      sigmax[i]=fx->GetParameter(2);
      QuarterQuarterReltiveDY[histoStartindex+i]->Fit("fy","R0Q");
      dy[i]=fy->GetParameter(1);
      sigmay[i]=fy->GetParameter(2);
      // Ex[i]=fx->GetParError(1);
      // Ey[i]=fy->GetParError(1);

      Meanx[i]=QuarterQuarterReltiveDX[histoStartindex+i]->GetMean();
      //Meany[i]=QuarterQuarterReltiveDY[histoStartindex+i]->GetMean();
      ErrMeanx[i]=QuarterQuarterReltiveDX[histoStartindex+i]->GetRMS();//->GetMeanError();//->GetRMS();//GetMeanError();
      // ErrMeany[i]=QuarterQuarterReltiveDY[histoStartindex+i]->GetMeanError();//->GetRMS();//GetMeanError();
    } 

  char sZnameR[1024];
  for(unsigned int i=0;i<n;i++)
    {
      sprintf(sZnameR, "fx %d", i);  
      Fx[i]=new TF1(sZnameR,"gaus",dx[i]-3*sigmax[i],dx[i]+3*sigmax[i]);
      sprintf(sZnameR, "fy %d", i);  
      Fy[i]=new TF1(sZnameR,"gaus",dy[i]-3*sigmay[i],dy[i]+3*sigmay[i]);
    }
  /*
  std::cout<<"AFTER the FIRST FITTING"<<std::endl;
  for(unsigned int i=0;i<n;i++)
    {
      std::cout<<"Media X= "<<dx[i]<<std::endl;
      std::cout<<"Sigma X= "<<sigmax[i]<<std::endl;
    }
  for(unsigned int i=0;i<n;i++)
    {
      std::cout<<"Media Y= "<<dy[i]<<std::endl;
      std::cout<<"Sigma Y= "<<sigmay[i]<<std::endl;
    }
*/
  for(unsigned int i=0;i<n;i++)
    {
      sprintf(sZnameR, "fx %d", i); 
      QuarterQuarterReltiveDX[histoStartindex+i]->Fit(sZnameR,"R0Q");
      sprintf(sZnameR, "fy %d", i);  
      QuarterQuarterReltiveDY[histoStartindex+i]->Fit(sZnameR,"R0Q");
    }


  const unsigned int n2=10;
  // Double_t det2[n2];
  Double_t dy2[n2];
  // Double_t dx2[n2];
  Double_t Ey2[n2];
  //  Double_t Ex2[n2];
  //Double_t allzero2[n2];


  //det2[0]=-1.+0;////////
  dy2[0]=0.;
  //dx2[0]=0.;
  Ey2[0]=0.;
  // Ex2[0]=0.;
  //  allzero2[0]=0.;
  
  for(unsigned int i=0;i<n2;i++)
    {
      //det2[i]=det[i-1]+0;
      // std::cout<<i<<" "<<det2[i]<<std::endl;
      // dx2[i]=Fx[i]->GetParameter(1);
      // Ex2[i]=Fx[i]->GetParameter(2);//GetParError(1);
      //if((Fx[i-1]->GetChisquare()/Fx[i-1]->GetNDF())>6.)
      //Ex2[i]=Fx[i-1]->GetParameter(2);
      dy2[i]=Fy[i]->GetParameter(1);
      Ey2[i]=Fy[i]->GetParameter(2);//GetParError(1);
      // allzero2[i]=allzero[i-1];
    }
  /*
   std::cout<<"AFTER the Second FITTING"<<std::endl;
  for(unsigned int i=0;i<n;i++)
    {
      std::cout<<"Media X= "<<dx2[i]<<std::endl;
      std::cout<<"Error X= "<<Ex2[i]<<std::endl;
    }
 for(unsigned int i=0;i<n;i++)
    {
      std::cout<<"Media Y= "<<dy2[i]<<std::endl;
      std::cout<<"Error Y= "<<Ey2[i]<<std::endl;
    }
  */

  // I want always 20 point in the final histo (ref+non ref)
 /*
  double zdet[20];
  double finaldx[20];
  double finalEdx[20];
  double finaldy[20];
  double finalEdy[20];
  double EZ[20];
 */
  for(unsigned int j=0;j<20;j++)
    {
      finaldx[j]=0.;
      finalEdx[j]=0.;
      finaldy[j]=0.;
      finalEdy[j]=0.;
      EZ[j]=0.;
      if(((halftoalign%2)==0)&&(j<10))
	{
	  finaldx[j]=Meanx[j];
	  finalEdx[j]=ErrMeanx[j];
	  //finaldx[j]=dx2[j];
	  //finalEdx[j]=Ex2[j];
	  //finaldy[j]=Meany[j];
	  //finalEdy[j]=ErrMeany[j];	  
	  finaldy[j]=dy2[j];
	  finalEdy[j]=Ey2[j];	  	  
	}

      if(((halftoalign%2)==1)&&(j>=10))
	{
	  
	  finaldx[j]=Meanx[j-10];
	  finalEdx[j]=ErrMeanx[j-10];
	  //  finaldx[j]=dx2[j-10];
	  //finalEdx[j]=Ex2[j-10];
	    //finaldy[j]=Meany[j-10];
	    //finalEdy[j]=ErrMeany[j-10];
	    finaldy[j]=dy2[j-10];
	    finalEdy[j]=Ey2[j-10];
	}

      if(halftoalign>=2)
	{
	  planeinfo=conv.GetT2Info(j+20);
	  zdet[j]=planeinfo.Zdet;
	}
      else
	{
	  planeinfo=conv.GetT2Info(j);
	  zdet[j]=planeinfo.Zdet;
	}
    }

  for(unsigned int j=0;j<20;j++)
    {
      std::cout<<"Relative quarter det|xdisp: "<<j<<"|"<<finaldx[j]<<std::endl;
      std::cout<<"Relative quarter det|ydisp: "<<j<<"|"<<finaldy[j]<<std::endl;	
    }
  

}


//Return 2 Vector for DX DY error
std::vector<std::vector<double> > T2TrkBasedInternalAlignment::MakeErrorHistograms(std::vector<std::vector<T2Hit> > *roadsX,std::vector<std::vector<T2Hit> > *roadsY,unsigned int thehalf)
{

  //std::cout<<"T2TrkBasedInternalAlignment::MakeErrorHistograms"<<std::endl;

  TF1 *fx= new TF1("fx","gaus",-2.0,2.0);
  TF1 *fy= new TF1("fy","gaus",-2.0,2.0);
  //TF1* Fy[40];
  // TF1* Fx[40];


  double sigmax[40];
  double sigmay[40];
  double sigmar[40];
  double fittedsigmaResidualx[40];
  double fittedsigmaResidualy[40];
  double sigmaDeltaX[40];
  double sigmaDeltaY[40];

  if(false)
    std::cout<<sigmar[0]<<std::endl;
  double hitresol=HitXYResolError;
  //Note: cannot be determined from a file with misalignment (PSimHit not reaaly updated and non parallel condition)
  //Sigma Hit Evaluation
  for(unsigned int u=0;u<40;u++)
    {
      sigmax[u]=0.;
      sigmay[u]=0.;
      sigmar[u]=0.;
      fittedsigmaResidualx[u]=0.;
      fittedsigmaResidualy[u]=0.;
      sigmaDeltaX[u]=0.;
      sigmaDeltaY[u]=0.;
    }
  
  for(unsigned int u=0;u<40;u++)
    {
      if(simufile)
	{
	  if(HitResolSimuY[u]->GetEntries()>30)
	    {
	      //HitResolSimuY[u]->Fit("fy","R0Q");      
	      //HitResolSimuR[u]->Fit("fy","R0Q");
	      // sigmay[u]=fy->GetParameter(2);	  
	      sigmay[u]=hitresol;
	    }
	  if(HitResolSimuX[u]->GetEntries()>30)
	    {
	      //HitResolSimuX[u]->Fit("fx","R0Q");
	      //HitResolSimuR[u]->Fit("fx","R0Q");
	      //sigmax[u]=fx->GetParameter(2);	  
	      sigmax[u]=hitresol;
	    }
	}
      else
	{
	   sigmax[u]=hitresol;
	   sigmay[u]=hitresol;
	   sigmar[u]=hitresol;
	}

    }

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;
  double chi2corr;

  //Make Residuals and Extrapolation histograms (X)

   for(unsigned int rd=0;rd<roadsX->size();rd++)
    {
      std::vector<T2Hit> thisroad=roadsX->at(rd);
      double ZGraV=0.;
      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  ZGraV+=thisroad.at(g).GetHitZ();
	}
      ZGraV=ZGraV/(thisroad.size());
      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  thisroad.at(g).SetHitZ(thisroad.at(g).GetHitZ()-ZGraV);
	}

      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  unsigned int absSymb=thisroad.at(g).GetHitDetRawId();
	  planeinfo=conv.GetT2Info(absSymb);
  
	  std::vector<T2Hit> hitvForResidual=GiveMeTheHitForResidual(absSymb,thisroad);	  
	  TMatrixD covmat(4,4);
	  covmat.Zero();
	  std::vector<double> corrFit=MyLinearfitCorr(hitvForResidual,covmat,chi2corr);
	  std::vector<double> support;
	  
	  for(unsigned int c=0;c<2;c++)
	    {
	      support.push_back(corrFit[c]);
	    }

	  if(fabs(thisroad.at(g).GetHitX())/fabs(thisroad.at(g).GetHitR())>0.7)
	    {
	      SigmaResidualX[thehalf*10+planeinfo.pl_0to9]->Fill(thisroad.at(g).GetHitX()-support.at(0)*thisroad.at(g).GetHitZ()-support.at(1));
	      SigmaExtrapolX[thehalf*10+planeinfo.pl_0to9]->Fill(sigmax[thehalf*10+planeinfo.pl_0to9]/sqrt(hitvForResidual.size()));
	    }
	}
    }
   
    //Make Residuals and Extrapolation histograms (Y)
   for(unsigned int rd=0;rd<roadsY->size();rd++)
    {
      std::vector<T2Hit> thisroad=roadsY->at(rd);
      double ZGraV=0.;
      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  ZGraV+=thisroad.at(g).GetHitZ();
	}
     ZGraV=ZGraV/(thisroad.size());
      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  thisroad.at(g).SetHitZ(thisroad.at(g).GetHitZ()-ZGraV);
	}

      for(unsigned int g=0;g<thisroad.size();g++)
	{
	  unsigned int absSymb=thisroad.at(g).GetHitDetRawId();
	  planeinfo=conv.GetT2Info(absSymb);
	  
	  std::vector<T2Hit> hitvForResidual=GiveMeTheHitForResidual(absSymb,thisroad);	  
	  TMatrixD covmat(4,4);
	  covmat.Zero();
	  std::vector<double> corrFit=MyLinearfitCorr(hitvForResidual,covmat,chi2corr);
	  std::vector<double> support;
	  for(unsigned int c=0;c<2;c++)
	    {
	      support.push_back(corrFit[2+c]);
	    }
	  if(fabs(thisroad.at(g).GetHitY())/fabs(thisroad.at(g).GetHitR())>0.7)
	    {
	      SigmaResidualY[thehalf*10+planeinfo.pl_0to9]->Fill(thisroad.at(g).GetHitY()-support.at(0)*thisroad.at(g).GetHitZ()-support.at(1));
	      SigmaExtrapolY[thehalf*10+planeinfo.pl_0to9]->Fill(sigmay[thehalf*10+planeinfo.pl_0to9]/sqrt(hitvForResidual.size()));
	    }
	}
    }


  
 for(unsigned int u=0;u<40;u++)
    {
    
       if(SigmaResidualX[u]->GetEntries()>30)
	 {
	   SigmaResidualX[u]->Fit("fx","R0Q");      	  
	   fittedsigmaResidualx[u]=fx->GetParameter(2);	  
	 }

       if(SigmaResidualY[u]->GetEntries()>30)
	 {
	   SigmaResidualY[u]->Fit("fy","R0Q");      	  
	   fittedsigmaResidualy[u]=fy->GetParameter(2);	  
	 }
	 

	  sigmaDeltaX[u]=fittedsigmaResidualx[u]*fittedsigmaResidualx[u]-(sigmax[u]*sigmax[u]+SigmaExtrapolX[u]->GetMean()*SigmaExtrapolX[u]->GetMean());
	  sigmaDeltaY[u]=fittedsigmaResidualy[u]*fittedsigmaResidualy[u]-(sigmay[u]*sigmay[u]+SigmaExtrapolY[u]->GetMean()*SigmaExtrapolY[u]->GetMean());
	  //sigmaDeltaY[u]=fittedsigmaResidualy[u]*fittedsigmaResidualy[u]-(hitresol*hitresol+hitresol*hitresol/9.0);

	  if(fabs(u-(thehalf*10))<10)
	    {
	      if(sigmaDeltaX[u]>0.)
		{
		  std::cout<<"Errdx in "<<u<<" detector: "<<sqrt(sigmaDeltaX[u])<<" Residuals:"<<fittedsigmaResidualx[u]<<std::endl;
		}
	      else
		{
		  std::cout<<"Errdx in "<<u<<" detector: DOES NOT WORK. SigmaResidX"<<fittedsigmaResidualx[u]<<" sigmaX "<<sigmax[u]<<std::endl;
		}

	      if(sigmaDeltaY[u]>0.)
		{
		  std::cout<<"Errdy in "<<u<<" detector: "<<sqrt(sigmaDeltaY[u])<<" Residuals:"<<fittedsigmaResidualy[u]<<std::endl;;
		}
	      else
		{
		  std::cout<<"Errdy in "<<u<<" detector: DOES NOT WORK. SigmaResidX"<<fittedsigmaResidualy[u]<<" sigmaY "<<sigmay[u]<<std::endl;
		}
	    }
    }
 //std::cout<<"T2TrkBasedInternalAlignment::MakeErrorHistograms 3"<<std::endl;


 std::vector<std::vector<double> > DXAndDYErrorVect;
 
 std::vector<double> fnalDX;
 std::vector<double> fnalDY;
 for(unsigned int h=0;h<10;h++)
   {
     fnalDX.push_back(sqrt(sigmaDeltaX[thehalf*10+h]));
     fnalDY.push_back(sqrt(sigmaDeltaY[thehalf*10+h]));
   }
 
 DXAndDYErrorVect.push_back(fnalDX);
 DXAndDYErrorVect.push_back(fnalDY);

 std::cout<<"????@@@@@@@@"<<DXAndDYErrorVect.size()<<" -: "<<fnalDX.size()<<" "<<fnalDY.size()<<std::endl;
 return DXAndDYErrorVect;

}







void T2TrkBasedInternalAlignment::CalculateRelativeHalfAlign(double* TotDXDispARM,double* TotDYDispARM,double* TotDXDispARMErr,double* TotDYDispARMErr, std::vector<std::vector<T2Hit> > *roadfitOverlapARM,unsigned int halftoalign)
{
  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;

  unsigned int Xalignstep=0,Yalignstep=0;
  bool XalignReached=false,YalignReached=false;

  double TotDXDisp=0., TotDXDispErr=0.;

  double TotDYDisp=0., TotDYDispErr=0.;

  if(false)
    std::cout<<TotDXDisp<<TotDYDisp<<TotDXDispErr<<TotDYDispErr<<std::endl;

  std::vector<std::vector<T2Hit> > SelectXroadfitOverlapARM;
  std::vector<std::vector<T2Hit> > SelectYroadfitOverlapARM;
  std::vector<std::vector<double> > startingtracksXParamArm;
  std::vector<std::vector<double> > startingtracksYParamArm;
  std::vector<double> geterror;
  geterror.push_back(0.);
  
  // -----------------------------------------------------------
  // ----------------------- X ALIGNMENT -----------------------
  // -----------------------------------------------------------
  //  SelectXroadfitOverlapARM=roadfitOverlapARM;
  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
    {
      std::vector<T2Hit> hitall=roadfitOverlapARM->at(rd);
      if(hitall.size()>0)
	if(hitall.at(0).GetHitR()<RMaxOverlapXalign)
	  {
	    SelectXroadfitOverlapARM.push_back(hitall);
	  }
    }


  while((Xalignstep<MaxStepalignstep)&&(XalignReached==false))
    {
      std::cout << "Quarter-Quarter relative DX Alignment Step "<< Xalignstep<<" ..." <<  std::endl;

      //vettore dei parametri di traccia
      startingtracksXParamArm.clear();
      std::vector<double> parmx;
      //unsigned int countdetstat=0;
      double DX=0.,DXDen=0.;

      std::cout<<"Road size for this align: "<<SelectXroadfitOverlapARM.size()<<std::endl;

      for(unsigned int rd=0;rd<SelectXroadfitOverlapARM.size();rd++)
	{
	  std::vector<T2Hit> hitall=SelectXroadfitOverlapARM.at(rd);

		std::vector<T2Hit> hitref;
		//std::vector<T2Hit> hitToalign;
		for(unsigned int j=0;j<hitall.size();j++)
		  {
		    planeinfo=conv.GetT2Info(hitall.at(j).GetHitDetRawId());
		    //  std::cout<<planeinfo.ht<<"   ????  ";
		    if(planeinfo.ht!=halftoalign)
		      hitref.push_back(hitall.at(j));	      		
		  }
		//	std::cout<<" "<<std::endl;

		    TMatrixD covmat(4,4);
		    covmat.Zero();
		    double chi2corr;	      
		    std::vector<double> corrFit=MyLinearfitCorr(hitref,covmat,chi2corr);
		    std::vector<double> support;
		    for(unsigned int c=0;c<2;c++)
		      {
			support.push_back(corrFit[c]);
		      }
		    for (unsigned int c=0;c<2;c++)
		      {
			support.push_back(covmat(c,c));
		      }
		    support.push_back(covmat(0,1));
		  
		    parmx=support;
		    startingtracksXParamArm.push_back(parmx);

		    for(unsigned int h=0;h<hitall.size();h++)
		      {
			planeinfo=conv.GetT2Info(hitall.at(h).GetHitDetRawId());
			if(planeinfo.ht==halftoalign)
			  {
			    double phirad=hitall.at(h).GetHitPhi()*3.14159/180.0;
			    double sigmax2=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*hitall.at(h).GetHitR()*hitall.at(h).GetHitR(); 		  
			    DX=DX+(hitall.at(h).GetHitX()-(startingtracksXParamArm.at(rd)).at(0)*hitall.at(h).GetHitZ()-(startingtracksXParamArm.at(rd)).at(1))/sigmax2; 
			    DXDen=DXDen+1.0/sigmax2;
			    //std::cout<<"sigmax2: "<<sigmax2<<std::endl;
			  }
		    
		      }
		    //  }
		//}
	}

      DX=DX/DXDen;
      std::cout<<"Temp DX= "<<DX<<std::endl;
      std::cout<<"Temp DXDen= "<<DXDen<<std::endl;

      std::vector<double> Dummyconv1;
      Dummyconv1.push_back(TotDXDisp+DX);
      //geterror=CalculateAlignError2(Dummyconv1,(SelectXroadfitOverlapARM),1,true,geterror);

      //update roadMatrix now!
      if(fabs(DX)>HalfHalfMaxDispToleranceX)
	{
	  std::cout<<"Found a Common X displ. of half "<<halftoalign<<"of "<<DX<<std::endl;
	  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
	    {
	      std::vector<T2Hit> hitv=roadfitOverlapARM->at(rd);
	      for(unsigned int h=0;h<hitv.size();h++)
		{
		  planeinfo=conv.GetT2Info(hitv.at(h).GetHitDetRawId());
		  if(planeinfo.ht==halftoalign)
		    {
		      hitv.at(h).SetHitX(hitv.at(h).GetHitX()-DX);
		    }
		}
	      roadfitOverlapARM->at(rd)=hitv;
	    }
		  
	  for(unsigned int rd=0;rd<SelectXroadfitOverlapARM.size();rd++)
	    {
	      std::vector<T2Hit> hitv=SelectXroadfitOverlapARM.at(rd);
	      for(unsigned int h=0;h<hitv.size();h++)
		{
		  planeinfo=conv.GetT2Info(hitv.at(h).GetHitDetRawId());
		  if(planeinfo.ht==halftoalign)
		    {
		      hitv.at(h).SetHitX(hitv.at(h).GetHitX()-DX);
		    }
		}
	      SelectXroadfitOverlapARM.at(rd)=hitv;
	    }	

  
	  TotDXDisp=TotDXDisp+DX;
	} 

		
      if(fabs(DX)<HalfHalfMaxDispToleranceX)
	{
	  XalignReached=true;
	  std::vector<double> finalerror;
	  std::vector<double> Dummyconv;
	  Dummyconv.push_back(TotDXDisp);
	  // finalerror=CalculateAlignError2(Dummyconv,(SelectXroadfitOverlapARM),1,true,geterror);
	  (*TotDXDispARM)=TotDXDisp;
	  (*TotDXDispARMErr)=finalerror.at(0);
	  if((*TotDXDispARMErr)<HalfHalfMaxDispTolerance)
	    (*TotDXDispARMErr)=HalfHalfMaxDispTolerance;

	  std::cout<<"Final common half DX= "<<(*TotDXDispARM)<<" +- "<<(*TotDXDispARMErr)<<std::endl;
	  // oppure guarda differenza di due iterazioni successive.
	}
      
      Xalignstep++;

    }


  // -----------------------------------------------------------
  // ----------------------- Y ALIGNMENT -----------------------
  // -----------------------------------------------------------

  // SelectYroadfitOverlapARM=roadfitOverlapARM;
  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
    {
      std::vector<T2Hit> hitall=roadfitOverlapARM->at(rd);
      if(hitall.size()>0)
	if(hitall.at(0).GetHitR()<RMaxOverlapYalign)
	  {
	    SelectYroadfitOverlapARM.push_back(hitall);
	  }
    }



  while((Yalignstep<MaxStepalignstep)&&(YalignReached==false))
    {
      std::cout << "Quarter-Quarter relative DY Alignment Step "<< Yalignstep<<" ..." <<  std::endl;

      //vettore dei parametri di traccia
      startingtracksYParamArm.clear();
      std::vector<double> parmy;
      //unsigned int countdetstat=0;
      double DY=0.,DYDen=0.;

     std::cout<<"Road size for this align: "<<SelectYroadfitOverlapARM.size()<<std::endl;

      for(unsigned int rd=0;rd<SelectYroadfitOverlapARM.size();rd++)
	{
	  std::vector<T2Hit> hitall=SelectYroadfitOverlapARM.at(rd);
	 

		std::vector<T2Hit> hitref;
		for(unsigned int j=0;j<hitall.size();j++)
		  {
		    planeinfo=conv.GetT2Info(hitall.at(j).GetHitDetRawId());
		    if(planeinfo.ht!=halftoalign)
		      hitref.push_back(hitall.at(j));	      		
		  }

	      
		    TMatrixD covmat(4,4);
		    covmat.Zero();
		    double chi2corr;	      
		    std::vector<double> corrFit=MyLinearfitCorr(hitref,covmat,chi2corr);
		    std::vector<double> support;
		    for(unsigned int c=0;c<2;c++)
		      {
			support.push_back(corrFit[2+c]);
		      }
		    for (unsigned int c=0;c<2;c++)
		      {
			support.push_back(covmat(2+c,2+c));
		      }
		    support.push_back(covmat(2,3));

		    parmy=support;
	  
		    startingtracksYParamArm.push_back(parmy);

		    for(unsigned int h=0;h<hitall.size();h++)
		      {
			planeinfo=conv.GetT2Info(hitall.at(h).GetHitDetRawId());
			//if((hitall.at(h).GetHitY())>0.)
			if(planeinfo.ht==halftoalign)
			  {
			    double phirad=hitall.at(h).GetHitPhi()*3.14159/180.0;		  
			    double sigmay2=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitall.at(h).GetHitR()*hitall.at(h).GetHitR();
			    DY=DY+((hitall.at(h).GetHitY()-(startingtracksYParamArm.at(rd)).at(0)*hitall.at(h).GetHitZ()-(startingtracksYParamArm.at(rd)).at(1))/sigmay2); 
		  // std::cout<<"Residuo: "<<((hitall.at(h).GetHitY()-(startingtracksYParamArm.at(rd)).at(0)*hitall.at(h).GetHitZ()-(startingtracksYParamArm.at(rd)).at(1))/sigmay2)<<std::endl;
		  //NOTE: multiply also for the sign of displacement in evt from vertex because the residual change sign 
		  // for the coordinate convention!!
		  
			    DYDen=DYDen+1.0/sigmay2;		  
			  }
	 
		      }
		    //  }
		    //}
	}
      // (hitv.at(h).GetHitY()/fabs(hitv.at(h).GetHitY()))
      
      DY=DY/DYDen;
      std::cout<<"Temp DY= "<<DY<<std::endl;
      std::vector<double> Dummyconv1;
      Dummyconv1.push_back(TotDYDisp+DY);
      //  geterror=CalculateAlignError2(Dummyconv1,(SelectYroadfitOverlapARM),2,true,geterror);

      //update roadMatrix now!
      if(fabs(DY)>HalfHalfMaxDispToleranceY)
	{
	  std::cout<<"Found a Common Y displ. of half "<<halftoalign<<"of "<<DY<<std::endl;
	  for(unsigned int rd=0;rd<roadfitOverlapARM->size();rd++)
	    {
	      std::vector<T2Hit> hitv=roadfitOverlapARM->at(rd);
	      for(unsigned int h=0;h<hitv.size();h++)
		{
		  planeinfo=conv.GetT2Info(hitv.at(h).GetHitDetRawId());
		  if(planeinfo.ht==halftoalign)
		    {
		      hitv.at(h).SetHitY(hitv.at(h).GetHitY()-DY);
		    }
		}
	      roadfitOverlapARM->at(rd)=hitv;
	    }

	  for(unsigned int rd=0;rd<SelectYroadfitOverlapARM.size();rd++)
	    {
	      std::vector<T2Hit> hitv=SelectYroadfitOverlapARM.at(rd);
	      for(unsigned int h=0;h<hitv.size();h++)
		{
		  planeinfo=conv.GetT2Info(hitv.at(h).GetHitDetRawId());
		  if(planeinfo.ht==halftoalign)
		    {
		      hitv.at(h).SetHitY(hitv.at(h).GetHitY()-DY);
		    }
		}
	      SelectYroadfitOverlapARM.at(rd)=hitv;
	    }	 

   
	  TotDYDisp=TotDYDisp+DY;
	 
	} 

		
      if(fabs(DY)<HalfHalfMaxDispToleranceY)
	{
	  YalignReached=true;
	  std::vector<double> finalerror;
	  std::vector<double> Dummyconv;
	  Dummyconv.push_back(TotDYDisp);
	  //finalerror=CalculateAlignError2(Dummyconv,(SelectYroadfitOverlapARM),2,true,geterror);
	  (*TotDYDispARM)=TotDYDisp;
	  (*TotDYDispARMErr)=finalerror.at(0);

	  if((*TotDYDispARMErr)<HalfHalfMaxDispTolerance)
	    (*TotDYDispARMErr)=HalfHalfMaxDispTolerance;

	  std::cout<<"Final common half DY= "<<(*TotDYDispARM)<<" +- "<<(*TotDYDispARMErr)<<std::endl;
	  // oppure guarda differenza di due iterazioni successive.
	}
      
      Yalignstep++;

    }

}



  
void T2TrkBasedInternalAlignment::RecomputeHalfDispl(double TotDXDispARM, double TotDYDispARM, double TotDXDispARMErr,double TotDYDispARMErr,std::vector<double> *TotDXDisphalf, std::vector<double> *TotDYDisphalf,  std::vector<double> *TotDXDisphalfErr,  std::vector<double> *TotDYDisphalfErr)
{
std::cout<<"Begin T2TrkBasedInternalAlignment::RecomputeHalfDispl"<<std::endl;
  for(unsigned int j=0;j<TotDXDisphalf->size();j++)
    {
      (*TotDXDisphalf).at(j)=(*TotDXDisphalf).at(j)+TotDXDispARM;      
    }

  for(unsigned int j=0;j<TotDYDisphalf->size();j++)
    {
      (*TotDYDisphalf).at(j)=(*TotDYDisphalf).at(j)+TotDYDispARM;      
    }

  for(unsigned int j=0;j<TotDXDisphalfErr->size();j++)
    {
      (*TotDXDisphalfErr).at(j)=sqrt(((*TotDXDisphalfErr).at(j))*((*TotDXDisphalfErr).at(j))+(TotDXDispARMErr*TotDXDispARMErr));      
    }

  for(unsigned int j=0;j<TotDYDisphalfErr->size();j++)
    {
      (*TotDYDisphalfErr).at(j)=sqrt(((*TotDYDisphalfErr).at(j))*((*TotDYDisphalfErr).at(j))+(TotDYDispARMErr*TotDYDispARMErr));      
    }

}









bool T2TrkBasedInternalAlignment::MettiTracciaBuonaInOverlap(std::vector<TrackInfo>* matricetracce,T1T2TrackCollection::const_iterator  trk, unsigned int numevento)
{

std::cout<<"Begin T2TrkBasedInternalAlignment::MettiTracciaBuonaInOverlap "<<std::endl;

  bool flag=false;
  
  unsigned int counthitgood=0;
  std::vector<T2Hit> hitv;
  std::vector<double> vpar;

  //double centrodigravitaZ=FitgravcenterZ;//13500.;//14057.1;//14000.;
  //14057.1;
 

   for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
      {
	if((*trk).GetHitT2(a).GetHitPlane()>4)
	  std::cout<<"Warning RECO!! Plane: "<<(*trk).GetHitT2(a).GetHitPlane()<<std::endl;

	//if(PlaneInRightHalf((*trk).GetHitT2(a).GetHitDetRawId()))
	if((*trk).GetHitT2(a).GetHitClass()==1)
	  if((*trk).GetHitT2(a).GetHitNumStrip()<=MaxStrip)
	    if((*trk).GetHitT2(a).GetHitNumPad()<=MaxPad)
	      if((*trk).GetHitT2(a).GetHitDPhi()<=MaxDphi)
		{
		  
		  hitv.push_back((*trk).GetHitT2(a));
		  //hitv.at(counthitgood).SetHitZ((*trk).GetHitT2(a).GetHitZ()-centrodigravitaZ);
		  counthitgood++;
		}
      }
 
    if(counthitgood>=16)
      {
	TMatrixD covmat(4,4);
	covmat.Zero();
	//	double chi2corr;
	//	vpar=MyLinearfitCorr(hitv,covmat,chi2corr);
	
	//if(useRZforResol==2)
	  vpar=MyLinearfit(hitv,UseJointProb);
	
	    //double *drdphi;//drdphi[2];
	std::vector<double>  drdphi;
	unsigned int symb;
	unsigned int countgoodhitaligned=0;
    
	//	std::cout<<" -  "<<vpar[0]<<" -  "<<vpar[1]<<" -  "<<vpar[2]<<" -  "<<vpar[3]<<std::endl;
	TrackInfo onetrack;
	std::vector<TrackInfo::IdandHit> tempidactive;
    
	for(unsigned int u=0;u<20;u++)
	  {
	    TrackInfo::IdandHit dummy;
	    dummy.iddet=0;
	    tempidactive.push_back(dummy);	
	  }
    
	std::vector<T2Hit> hitv2;
	std::vector<double> vpar2; 
	std::vector<double> OLDvpar2;
	//double* vpar2; //4

	//	for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
	for(unsigned int a=0;a<hitv.size();a++)
	  {
	    // drdphi=ResiduiRPhi(vpar,(*trk).GetHitT2(a).GetHitX(),(*trk).GetHitT2(a).GetHitY(),(*trk).GetHitT2(a).GetHitZ());
	    //bug discovered on 22-05-09
	    drdphi=ResiduiRPhi(vpar,hitv.at(a).GetHitX(),hitv.at(a).GetHitY(),hitv.at(a).GetHitZ());
	    if(drdphi[0]<maxdrhit)
	      if(drdphi[1]<maxdphihit)
		{		
		  hitv2.push_back(hitv.at(a));
		  //hitv2.push_back((*trk).GetHitT2(a));	
		  countgoodhitaligned++;
		}
	  }
    
	//	std::cout<<"drdphi.size()="<<drdphi.size()<<std::endl;
    
	if(countgoodhitaligned>=16)
	  {	       
	    onetrack.eventnumber=numevento;		
	    onetrack.goodhitnumber=countgoodhitaligned;
	

	    covmat.Zero();
	    // double chi2corr;
	    //vpar2=MyLinearfitCorr(hitv2,covmat,chi2corr);
	    vpar2=MyLinearfit(hitv,UseJointProb);
	   
	    //std::cout<<" -  "<<vpar2[0]<<" -  "<<vpar2[1]<<" -  "<<vpar2[2]<<" -  "<<vpar2[3]<<std::endl;

	    for(unsigned int a=0;a<hitv2.size(); a++)
	      {	   
		symb=hitv2.at(a).GetHitPlane()*2+hitv2.at(a).GetHitPlaneSide()+10*hitv2.at(a).GetHitHalftele();
		if((symb>19)||(hitv2.at(a).GetHitPlane()>4))
		  std::cout<<"WARNING"<<hitv2.at(a).GetHitPlane()<<hitv2.at(a).GetHitPlaneSide()<<std::endl;
		
		tempidactive.at(symb).iddet=1;
		
		tempidactive.at(symb).thehit=hitv2.at(a);
		if(tempidactive.at(symb).iddet==1)
		  {
		    drdphi=ResiduiRPhi(vpar2,hitv2.at(a).GetHitX(),hitv2.at(a).GetHitY(),hitv2.at(a).GetHitZ());
		    tempidactive.at(symb).dr=drdphi[0];
		    tempidactive.at(symb).dphi=drdphi[1];
		  }
	
	      }
	
	    //std::cout<<"vpar2.size()="<<vpar2.size()<<std::endl;
	    onetrack.ar=vpar2[0];
	    onetrack.br= vpar2[1];
	    onetrack.aphi=vpar2[2];
	    onetrack.bphi= vpar2[3];

	    onetrack.idactive=tempidactive;
 
	    (*matricetracce).push_back(onetrack);
	    std::cout<<"Track inserted for Overl alignment as event:"<<onetrack.eventnumber<<std::endl;
	    flag=true;
	  }
      }
    return flag;
}





bool T2TrkBasedInternalAlignment::MettiTracciaBuona(std::vector<TrackInfo>* matricetracce,T1T2TrackCollection::const_iterator  trk, unsigned int numevento)
{
  bool flag=false;
  
  unsigned int counthitgood=0;
  std::vector<T2Hit> hitv;
  std::vector<double> vpar;

  double centrodigravitaZ=FitgravcenterZ;//13500.;//14057.1;//14000.;
  //14057.1;
 
  Taglio1_TrkSel->Fill((*trk).GetHitEntries());
   for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
      {
	if((*trk).GetHitT2(a).GetHitPlane()>4)
	  std::cout<<"Warning RECO!! Plane: "<<(*trk).GetHitT2(a).GetHitPlane()<<std::endl;
	//	else
	//std::cout<<"  RECO!! Plane: "<<(*trk).GetHitT2(a).GetHitPlane()<<std::endl;

	//if(PlaneInRightHalf((*trk).GetHitT2(a).GetHitDetRawId()))
	if((*trk).GetHitT2(a).GetHitClass()==1)
	  if((*trk).GetHitT2(a).GetHitNumStrip()<=MaxStrip)
	    if((*trk).GetHitT2(a).GetHitNumPad()<=MaxPad)
	      if((*trk).GetHitT2(a).GetHitDPhi()<=MaxDphi)
		{
		  
		  hitv.push_back((*trk).GetHitT2(a));
		  hitv.at(counthitgood).SetHitZ((*trk).GetHitT2(a).GetHitZ()-centrodigravitaZ);
		  counthitgood++;
		}
      }
 
    if(counthitgood>=NumHitGood)
      {


	double trketa= (*trk).Eta();
	Trketa->Fill(trketa);
	//   std::cout<<(*TrkCit).Phi()<<std::endl;
	double trkphi=(*trk).Phi()*180/3.14159265; 
	       //  std::cout<<trkphi<<std::endl;
	Trkphi->Fill(trkphi);
	NumClass1Hits->Fill(counthitgood);

	int whereistrk2=TrackIsInOneQuarter(trk,6); 
	if(whereistrk2==0) NumClass1HitsH0->Fill(counthitgood);
	if(whereistrk2==1) NumClass1HitsH1->Fill(counthitgood);
	if(whereistrk2==3) NumClass1HitsH3->Fill(counthitgood);

	Taglio2_TrkSel->Fill((*trk).GetHitEntries()+whereistrk2*10);
	
	TMatrixD covmat(4,4);
	covmat.Zero();
	double chi2corr;
	vpar=MyLinearfitCorr(hitv,covmat,chi2corr);
	
	if(useRZforResol==2)
	  vpar=MyLinearfit(hitv,UseJointProb);
	
	    //double *drdphi;//drdphi[2];
	std::vector<double>  drdphi;
	unsigned int symb;
	unsigned int countgoodhitaligned=0;
    
	//	std::cout<<" -  "<<vpar[0]<<" -  "<<vpar[1]<<" -  "<<vpar[2]<<" -  "<<vpar[3]<<std::endl;
	TrackInfo onetrack;
	std::vector<TrackInfo::IdandHit> tempidactive;
    
	for(unsigned int u=0;u<10;u++)
	  {
	    TrackInfo::IdandHit dummy;
	    dummy.iddet=0;
	    tempidactive.push_back(dummy);	
	  }
    
	std::vector<T2Hit> hitv2;
	std::vector<double> vpar2; 
	std::vector<double> OLDvpar2;
	//double* vpar2; //4

	//	for(unsigned int a=0;a<(*trk).GetHitEntries(); a++)
	for(unsigned int a=0;a<hitv.size();a++)
	  {
	    // drdphi=ResiduiRPhi(vpar,(*trk).GetHitT2(a).GetHitX(),(*trk).GetHitT2(a).GetHitY(),(*trk).GetHitT2(a).GetHitZ());
	    //bug discovered on 22-05-09
	    drdphi=ResiduiRPhi(vpar,hitv.at(a).GetHitX(),hitv.at(a).GetHitY(),hitv.at(a).GetHitZ());
	    if(drdphi[0]<maxdrhit)
	      if(drdphi[1]<maxdphihit)
		{		
		  hitv2.push_back(hitv.at(a));
		  //hitv2.push_back((*trk).GetHitT2(a));	
		  countgoodhitaligned++;
		}
	  }
    
	//	std::cout<<"drdphi.size()="<<drdphi.size()<<std::endl;
    
	if(countgoodhitaligned>=NumHitGood)
	  {	       
	    onetrack.eventnumber=numevento;		
	    onetrack.goodhitnumber=countgoodhitaligned;

	    Taglio3_TrkSel->Fill((*trk).GetHitEntries()+whereistrk2*10);

	    covmat.Zero();
	    double chi2corr;
	    vpar2=MyLinearfitCorr(hitv2,covmat,chi2corr);

	    if(useRZforResol==2)
	      vpar2=MyLinearfit(hitv,UseJointProb);
	   
	    //std::cout<<" -  "<<vpar2[0]<<" -  "<<vpar2[1]<<" -  "<<vpar2[2]<<" -  "<<vpar2[3]<<std::endl;

	    for(unsigned int a=0;a<hitv2.size(); a++)
	      {	   
		symb=hitv2.at(a).GetHitPlane()*2+hitv2.at(a).GetHitPlaneSide();
		if((symb>9)||(hitv2.at(a).GetHitPlane()>4))
		  std::cout<<"WARNING"<<hitv2.at(a).GetHitPlane()<<hitv2.at(a).GetHitPlaneSide()<<std::endl;
		
		tempidactive.at(symb).iddet=1; //It means hit is present
		
		tempidactive.at(symb).thehit=hitv2.at(a);
		if(tempidactive.at(symb).iddet==1)
		  {
		    drdphi=ResiduiRPhi(vpar2,hitv2.at(a).GetHitX(),hitv2.at(a).GetHitY(),hitv2.at(a).GetHitZ());
		    tempidactive.at(symb).dr=drdphi[0];
		    tempidactive.at(symb).dphi=drdphi[1];
		  }
	
	      }
	
	    //std::cout<<"vpar2.size()="<<vpar2.size()<<std::endl;
	    onetrack.ar=vpar2[0];
	    onetrack.br= vpar2[1];
	    onetrack.aphi=vpar2[2];
	    onetrack.bphi= vpar2[3];
	    /*
	    onetrack.OLDar=OLDvpar2[0];
	    onetrack.OLDbr= OLDvpar2[1];
	    onetrack.OLDaphi=OLDvpar2[2];
	    onetrack.OLDbphi= OLDvpar2[3];
	    */
	    onetrack.idactive=tempidactive;
 
	    /*
	    for(unsigned int m=0;m<tempidactive.size();m++)
	      {
		if(tempidactive.at(m).iddet==1)
		  if(tempidactive.at(m).thehit.GetHitPlane()>4)
		    std::cout<<"Warning Plane in mettit: "<<tempidactive.at(m).thehit.GetHitPlane()<<std::endl;
	      }
	    */
	    //  std::cout<<"H1"<<std::endl;
	    (*matricetracce).push_back(onetrack);
	    //std::cout<<"H2"<<std::endl;
	    flag=true;
	  }
      }

    // std::cout<<"here mettitraccia"<<std::endl;
    return flag;
}









void T2TrkBasedInternalAlignment::MakeHitResolSimuHisto(std::map<int, edm::PSimHitContainer> hitMap,std::vector<T2Hit> t2hitcoll, char XorY)
{

if(simufile)
    {

      // std::cout<<"MakeHitResolSimuHisto "<<hitMap.size();
       for(std::map<int, edm::PSimHitContainer>::const_iterator hitMapItr = hitMap.begin(); hitMapItr != hitMap.end(); ++hitMapItr){
	 // std::cout<<"--------------><-------------"<<std::endl;
          const edm::PSimHitContainer & planeSimHits = hitMapItr->second;
          T2DetId *theT2DetId =new T2DetId(hitMapItr->first);
	  

	  unsigned int symbol=RawtoSymb(theT2DetId->calculateRawId(theT2DetId->arm(),theT2DetId->halfTelescope(),theT2DetId->plane(),theT2DetId->planeSide()));
	  
	  //  std::cout<<"plsimhit.size(): "<<planeSimHits.size()<<"  ";
	  for (unsigned int l=0; l<planeSimHits.size(); l++){
		 PSimHit myplanehits= planeSimHits[l];
	  double lmyx= myplanehits.localPosition().x();
	  double lmyy= myplanehits.localPosition().y();
	  uint32_t absPSimHitPlaneID=theT2DetId->calculateRawId(theT2DetId->arm(),theT2DetId->halfTelescope(),theT2DetId->plane(),theT2DetId->planeSide());
      
	  double lmyr=sqrt(lmyx*lmyx+lmyy*lmyy);

	      for(std::vector<T2Hit>::const_iterator ithit = t2hitcoll.begin(); ithit != t2hitcoll.end(); ithit++){
		
		  uint32_t AbsRecHitID=ithit->GetHitDetRawId();

		  if(AbsRecHitID==absPSimHitPlaneID)
		    if((fabs(lmyx)-fabs(ithit->GetHitX()))<10)
		      if((fabs(lmyy)-fabs(ithit->GetHitY()))<10)
			{
			  // double XovY=fabs(ithit->GetHitX()/ithit->GetHitY());
			  // double YovX=fabs(ithit->GetHitY()/ithit->GetHitX());

			   if(XorY=='X')			 
			     HitResolSimuX[symbol]->Fill(fabs(ithit->GetHitX())-fabs(lmyx));

			  if(XorY=='Y')			 
			      HitResolSimuY[symbol]->Fill(fabs(ithit->GetHitY())-fabs(lmyy));

			  HitResolSimuR[symbol]->Fill(fabs(ithit->GetHitR())-fabs(lmyr));
			}
	      }

	  }

       }

    }

}





//--------------------------------------------------------------------------------------------------------------------------------------
// ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
// ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
// ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******  ANLYZER BEGIN ******
//--------------------------------------------------------------------------------------------------------------------------------------


void T2TrkBasedInternalAlignment::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace std;
  using namespace edm;
  using namespace HepMC;
  // std::cout<<"Analyze method"<<std::endl;

  /* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
  /* LOADING OF ALL THE RECORDS FROM THE EVENT */
  /* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

    /* :::::::::::::TakeDigi::::::::::::*/
  /*
  edm::Handle<T2PadDigiCollection> t2paddigicoll;
  iEvent.getByType(t2paddigicoll);
  const T2PadDigiCollection* PadDigiptr;
  PadDigiptr= t2paddigicoll.product();
  edm::Handle<T2StripDigiCollection> t2stripdigicoll;
  iEvent.getByType(t2stripdigicoll);
  const T2StripDigiCollection* StripDigiptr;
  StripDigiptr= t2stripdigicoll.product(); 
  */
  
  edm::Handle<T2PadDigiCollection> t2paddigicoll;
  iEvent.getByLabel(T2PadDigiCollectionLabel, t2paddigicoll);
  //  const T2PadDigiCollection* PadDigiptr;
  //PadDigiptr= t2paddigicoll.product();
  edm::Handle<T2StripDigiCollection> t2stripdigicoll;
  iEvent.getByLabel(T2StripDigiCollectionLabel, t2stripdigicoll);
  // const T2StripDigiCollection* StripDigiptr;
  //StripDigiptr= t2stripdigicoll.product(); 






  DigiContainerIterator<T2DetId, T2PadDigi> itp;
  DigiContainerIterator<T2DetId, T2StripDigi> its;
  /* :::::::::::::Take The Clusters::::::::::::*/
  Handle<T2StripClusterCollection> t2strclcoll;
  iEvent.getByLabel(CluLabel,"T2StripClusters",t2strclcoll);
  Handle<T2PadClusterCollection> t2padclcoll;
  iEvent.getByLabel(CluLabel,"T2PadClusters",t2padclcoll);
  
  /*::::::Take  T2  Hits::::::*/
  Handle<T2HitCollection> t2hitcoll;
  iEvent.getByLabel(HitLabel,"T2Hits",t2hitcoll);
  /*::::::Take  T2  Roads::::::*/
  Handle<T2RoadCollection> t2roadcoll;
  iEvent.getByLabel(RoadLabel,"T2RoadColl",t2roadcoll);
  /*:::::: Take T2 tracks ::::::*/
  Handle<T1T2TrackCollection> trackCollection;
  iEvent.getByLabel(TrackLabel,"T2TrackColl",trackCollection);


  //bool acceptSimuTracks=false;
  //bool acceptSimuTracks_ForQuarterRelativeAlign=false;

  //unsigned int count0simu=0;
  //unsigned int count1simu=0;

  map<int, PSimHitContainer> hitMap;

  


  int ActivePlH0[10]= {0,0,0,0,0,0,0,0,0,0};
  double H0AvgPadCLS[10]= {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};double H0AvgStripCLS[10]= {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  int ActivePlH1[10]= {0,0,0,0,0,0,0,0,0,0};
  int ActivePlH2[10]= {0,0,0,0,0,0,0,0,0,0}; 
  int ActivePlH3[10]= {0,0,0,0,0,0,0,0,0,0};
  
  unsigned int intplane=0;
  unsigned int totHitAllH0=0;unsigned int totHitAllH1=0;unsigned int totHitAllH2=0;unsigned int totHitAllH3=0;
  
  for(T2StripClusterCollection::const_iterator itstrip= t2strclcoll->begin(); itstrip != t2strclcoll->end(); itstrip++){//Reft2stripclcoll
    vector<T2Cluster> stripClv = itstrip->second;
    T2DetId *detID =new T2DetId(itstrip->first);
    
    uint32_t cmsswdId= detID->calculateRawId(detID->arm(),detID->halfTelescope(),detID->plane(),detID->planeSide());
    unsigned int symb=RawtoSymb(cmsswdId);
    //unsigned int quarter=symbol/10;
    //unsigned int plane=symbol%10;
    
    if((symb/10)==0){
      
      intplane=(symb%10);
      //ActivePlH0[intplane]=ActivePlH0[intplane]+stripClv.size();
      double media=0.;
      //media cls piano
      for(unsigned int io=0;io<stripClv.size();io++)
	media=media+stripClv.at(io).GetNoOfEntries();
      
      H0AvgStripCLS[intplane]=media/stripClv.size();
    }
  }


  for(T2PadClusterCollection::const_iterator itpad= t2padclcoll->begin(); itpad != t2padclcoll->end(); itpad++){//Reft2padclcoll
    vector<T2Cluster> padClv = itpad->second;
    T2DetId *detID =new T2DetId(itpad->first);
    
    uint32_t cmsswdId= detID->calculateRawId(detID->arm(),detID->halfTelescope(),detID->plane(),detID->planeSide());
    unsigned int symb=RawtoSymb(cmsswdId);
    //unsigned int quarter=symbol/10;
    //unsigned int plane=symbol%10;
    
    if((symb/10)==0){
      totHitAllH0=totHitAllH0+padClv.size();
      intplane=(symb%10);
      ActivePlH0[intplane]=ActivePlH0[intplane]+padClv.size();
      double media=0.;
      //media cls piano
      for(unsigned int io=0;io<padClv.size();io++)
	media=media+padClv.at(io).GetNoOfEntries();
      
      H0AvgPadCLS[intplane]=media/padClv.size();
    }
    if((symb/10)==1){	
      totHitAllH1=totHitAllH1+padClv.size();
      intplane=(symb%10);
      ActivePlH1[intplane]=ActivePlH1[intplane]+padClv.size();
      
    }
    if((symb/10)==2){
      totHitAllH2=totHitAllH2+padClv.size();
      intplane=(symb%10);
      ActivePlH2[intplane]=ActivePlH2[intplane]+padClv.size();
    }
    if((symb/10)==3){
      totHitAllH3=totHitAllH3+padClv.size();     
      intplane=(symb%10);
      ActivePlH3[intplane]=ActivePlH3[intplane]+padClv.size();
    }
  }
	 
  
  NumActivePlH0->Fill(totHitAllH0);
  NumActivePlH1->Fill(totHitAllH1);
  NumActivePlH2->Fill(totHitAllH2);
  NumActivePlH3->Fill(totHitAllH3);
  for(unsigned int j=0;j<10;j++){
    H0AvgStripCLSHis->Fill(j,H0AvgStripCLS[j]);
    H0AvgPadCLSHis->Fill(j,H0AvgPadCLS[j]);
  }
  
  if(simufile)
    {
       //::::::Take Geant local hit on T2::::::

      Handle<CrossingFrame<PSimHit> > cFrame;
      iEvent.getByLabel("mix", "g4SimHitsTotemHitsT2Gem", cFrame);
      // get hits from G4Sim
      const string nameOfHits("TotemHitsT2Gem");
      auto_ptr<MixCollection<PSimHit> >  T2SimHits( new MixCollection<PSimHit>( cFrame.product() ) );
      // map hits to T2 plane
     
      for(MixCollection<PSimHit>::MixItr hitItr = T2SimHits->begin(); hitItr != T2SimHits->end(); ++hitItr) {
	hitMap[hitItr->detUnitId()].push_back(*hitItr);
      }
      
    }
  
  
  
  
  //--***************************************************        Reco TRACK        ************************************************************--/
  //--***************************************************        Reco TRACK        ************************************************************--/
  //--***************************************************        Reco TRACK        ************************************************************--/


  numevent++;  

  //std::cout<<"\n\n ------------------------------------------"<<std::endl;    
  //std::cout<<"Absolute Numevent"<<numevent<<std::endl;

  T1T2TrackCollection::const_iterator TrkCit;

  
  /*
  if((totHitAllH0/10.)>10)
    if(SelectedHalfsForTiltAlign.at(0)==0)
      return;
  if((totHitAllH1/10.)>10)
    if(SelectedHalfsForTiltAlign.at(0)==1)
      return;
    */      

  //I'm looking if the event is too schifoso (new controls)
  unsigned int count_t2trackVectorALL_H0=0; 
  unsigned int count_t2trackVectorALL_H1=0; 
  unsigned int count_t2trackVectorALL_H2=0; 
  unsigned int count_t2trackVectorALL_H3=0;
  unsigned int trkcounterallEVERYQUARTER=0;
  std::vector<int> dummy_0; dummy_0.push_back(0);	  
  std::vector<int> dummy_1; dummy_1.push_back(1);
  std::vector<int> dummy_2; dummy_2.push_back(2);
  std::vector<int> dummy_3; dummy_3.push_back(3);
  std::vector<T1T2Track> TrkInOvH0;
  std::vector<T1T2Track> TrkInOvH1;
  std::vector<T1T2Track> TrkInOvH2;
  std::vector<T1T2Track> TrkInOvH3;
 
  T1T2TrackCollection::const_iterator TrkCit2;
  bool separateTrkInH0=true;  bool separateTrkInH1=true;  bool separateTrkInH2=true;  bool separateTrkInH3=true;
  for(TrkCit=trackCollection->begin(); TrkCit!=trackCollection->end(); TrkCit++){     
     

    
      //std::cout<<"fnal-1"<<std::endl;
      double ttrketa= (*TrkCit).Eta();
      double ttrkphi= (*TrkCit).Phi()*180/3.14159265;  
      //double ttrkphi=(*TrkCit).Phi()*180/3.14159265;  
      //chiRred=(*TrkCit).ChiSquaredR()/((*TrkCit).GetHitEntries()-2);
      //chiPhiRed=(*TrkCit).ChiSquaredPhi()/((*TrkCit).GetHitEntries()-1);
      //chiRProb=TMath::Prob((*TrkCit).ChiSquaredR(),((*TrkCit).GetHitEntries()-2));
      //chiPhiProb=TMath::Prob((*TrkCit).ChiSquaredPhi(),((*TrkCit).GetHitEntries()-1));  
      CumulativeRawTrketa->Fill(ttrketa);
      CumulativeRawTrkphi->Fill(ttrkphi);
      CumulativeRawTrkNumHit->Fill((*TrkCit).GetHitEntries());
      //std::cout<<"fnal-2"<<std::endl;
      //Chi2phired->Fill(chiPhiRed);
      //Chi2RProb->Fill(chiRProb);
      //Chi2PhiProb->Fill(chiPhiProb);
    

    if((*TrkCit).Eta()>0){
      if(T2CutsUtilForAl.TrkAlsoInQuarter((*TrkCit),dummy_0)){
	count_t2trackVectorALL_H0++;
      }
      if(T2CutsUtilForAl.TrkAlsoInQuarter((*TrkCit),dummy_1)){
	count_t2trackVectorALL_H1++;	      
      }
    }
    else{
      if(T2CutsUtilForAl.TrkAlsoInQuarter((*TrkCit),dummy_2))
	count_t2trackVectorALL_H2++;
      if(T2CutsUtilForAl.TrkAlsoInQuarter((*TrkCit),dummy_3))  
	count_t2trackVectorALL_H3++;  
    }
    
    if(count_t2trackVectorALL_H0>5)
      separateTrkInH0=false;
    if(count_t2trackVectorALL_H1>5)
      separateTrkInH1=false;
    if(count_t2trackVectorALL_H2>5)
      separateTrkInH2=false;
    if(count_t2trackVectorALL_H3>5)
      separateTrkInH3=false;

    if(separateTrkInH0)//Continue the check of trk separation in H0
      for(TrkCit2=TrkCit; TrkCit2!=trackCollection->end(); TrkCit2++){
	
	if((RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId())/10)==0)
	  if((RawtoSymb((*TrkCit2).GetHitT2(0).GetHitDetRawId())/10)==0)
	    if(TrkCit2!=TrkCit)
	      if(fabs((*TrkCit).GetHitT2(0).GetHitR()-(*TrkCit2).GetHitT2(0).GetHitR())<30.)//Was 50  
		if(fabs((*TrkCit).GetHitT2(0).GetHitPhi()-(*TrkCit2).GetHitT2(0).GetHitPhi())<15.)
		  {
		    separateTrkInH0=false;		  
		  }
      }

     if(separateTrkInH1)//Continue the check of trk separation in H1
      for(TrkCit2=TrkCit; TrkCit2!=trackCollection->end(); TrkCit2++){
	
	if((RawtoSymb((*TrkCit2).GetHitT2(0).GetHitDetRawId())/10)==1)
	  if((RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId())/10)==1)
	  if(TrkCit2!=TrkCit)
	    if(fabs((*TrkCit).GetHitT2(0).GetHitR()-(*TrkCit2).GetHitT2(0).GetHitR())<30.)//Was 50  
	      if(fabs((*TrkCit).GetHitT2(0).GetHitPhi()-(*TrkCit2).GetHitT2(0).GetHitPhi())<15.)
		{
		  separateTrkInH1=false;
		}
      }

     if(separateTrkInH2)//Continue the check of trk separation in H2
      for(TrkCit2=TrkCit; TrkCit2!=trackCollection->end(); TrkCit2++){
	
	if((RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId())/10)==2)
	  if((RawtoSymb((*TrkCit2).GetHitT2(0).GetHitDetRawId())/10)==2)
	    if(TrkCit2!=TrkCit)
	      if(fabs((*TrkCit).GetHitT2(0).GetHitR()-(*TrkCit2).GetHitT2(0).GetHitR())<30.)//Was 50  
		if(fabs((*TrkCit).GetHitT2(0).GetHitPhi()-(*TrkCit2).GetHitT2(0).GetHitPhi())<15.)
		  {
		    separateTrkInH2=false;
		  }
      }

     if(separateTrkInH3)//Continue the check of trk separation in H3
      for(TrkCit2=TrkCit; TrkCit2!=trackCollection->end(); TrkCit2++){
	
	if((RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId())/10)==3)
	  if((RawtoSymb((*TrkCit2).GetHitT2(0).GetHitDetRawId())/10)==3)
	    if(TrkCit2!=TrkCit)
	      if(fabs((*TrkCit).GetHitT2(0).GetHitR()-(*TrkCit2).GetHitT2(0).GetHitR())<30.)//Was 50  
		if(fabs((*TrkCit).GetHitT2(0).GetHitPhi()-(*TrkCit2).GetHitT2(0).GetHitPhi())<15.)
		  {
		    separateTrkInH3=false;
		  }
      }
  
     trkcounterallEVERYQUARTER++;
  }
  

  //*****************Part for Load Trk in Quarter Tilt Alignment**********
  //*********************************************************************
  //  if((separateTrkInH0 && (SelectedHalfsForTiltAlign==0) ) || (separateTrkInH1 && (SelectedHalfsForTiltAlign==1)) || (separateTrkInH2 && (SelectedHalfsForTiltAlign==2)) || (separateTrkInH3 && (SelectedHalfsForTiltAlign==3) )){

  if(IncludeQuarterTiltAlign)
    {      
      const T1T2TrackCollection* trkcollt2 = trackCollection.product();
      //std::cout<<"Starting alignment of Quarter "<<thehalf<<" Tilt - Shift respect to the Vertex"<<std::endl;		 
      qtiltobj->StoreEventtTrks(trkcollt2,UseGlobVertexForTiltCalulation,separateTrkInH0,separateTrkInH1,separateTrkInH2,separateTrkInH3);         	  
    }

  if(UseMillePedeGlobal)
    {
      const T1T2TrackCollection* trkcollt2 = trackCollection.product();  
      //   std::cout<<"Millepede storing global Begin "<<std::endl;
      millepedeGlobobj->StoreEventtTrks(trkcollt2,separateTrkInH0,separateTrkInH1,separateTrkInH2,separateTrkInH3);
      //std::cout<<"Millepede storing global END "<<std::endl;
    }
  
  

  
  //I'm looking if the event is too schifoso (old controls)
  unsigned int trkcountergd=0;
  
  for(TrkCit=trackCollection->begin(); TrkCit!=trackCollection->end(); TrkCit++){

    if((RawtoSymb((*TrkCit).GetHitT2(0).GetHitDetRawId())/10)==0)
      {
	if(separateTrkInH0)
	  SeparEvent->Fill(0.5);
	else
	  SeparEvent->Fill(-0.5);
      }


    for(unsigned int h=0;h<(*TrkCit).GetHitEntries();h++)
      {
	uint32_t rawiddet=(*TrkCit).GetHitT2(h).GetHitDetRawId();   
	AllDetIdRAW->Fill(RawtoSymb(rawiddet));   	
      }
           

    if((*TrkCit).GetHitEntries()>=NumHitGood)
      trkcountergd++;

    
  }
  
 
  if((numevent<MaxEvents)&&(trkcountergd>=1)) // carica la matrice
    {
      
      for(TrkCit=trackCollection->begin(); TrkCit!=trackCollection->end(); TrkCit++){
	bool inserted=false;
	bool inserted_an_overl=false;
	int whereistrk=TrackIsInOneQuarter(TrkCit,6); //Second argument: require at least n hit in that arm otherw ret -1
	    unsigned int control=0;
	    if((whereistrk==0)&&(separateTrkInH0))
	      {
		//	std::cout<<"half0"<<std::endl;
		//std::cout<<"Before MatriceTracceh0a0.size()= "<<MatriceTracceh0a0.size()<<std::endl;
		H0NumHit->Fill((*TrkCit).GetHitEntries());
		inserted=MettiTracciaBuona(&MatriceTracceh0a0,TrkCit,numevent);
	
		//std::cout<<"After MatriceTracceh0a0.size()= "<<MatriceTracceh0a0.size()<<std::endl;
		control++;
	      }
	    if((whereistrk==1)&&(separateTrkInH1))
	      {
		//std::cout<<"half1"<<std::endl;
		H1NumHit->Fill((*TrkCit).GetHitEntries());
		inserted=MettiTracciaBuona(&MatriceTracceh1a0,TrkCit,numevent);
		control++;
	      }
	    if((whereistrk==2)&&(separateTrkInH2))
	      {
		//	std::cout<<"half2"<<std::endl;
		inserted=MettiTracciaBuona(&MatriceTracceh0a1,TrkCit,numevent);
		control++;
	      }
	    if((whereistrk==3)&&(separateTrkInH3))
	      {
		//std::cout<<"half3"<<std::endl;
		inserted=MettiTracciaBuona(&MatriceTracceh1a1,TrkCit,numevent);
		/*
		std::cout<<" - - - - - - a --------"<<std::endl;	    
		//if((*TrkCit).GetHitEntries()>9)
		  {
		    
		    for(unsigned int mm=0;mm<(*TrkCit).GetHitEntries();mm++)
		      std::cout<<mm<<" "<<RawtoSymb((*TrkCit).GetHitT2(mm).GetHitDetRawId())<<" "<<(*TrkCit).GetHitT2(mm).GetHitZ()<<" "<<(*TrkCit).GetHitT2(mm).GetHitClass()<<std::endl; 
		  }
		*/

		control++;
	      }

	    if(((whereistrk==3)&&(separateTrkInH3))||((whereistrk==2)&&(separateTrkInH2))||((whereistrk==1)&&(separateTrkInH1))||((whereistrk==0)&&(separateTrkInH0)))
	      Taglio4_TrkSel->Fill((*TrkCit).GetHitEntries()+whereistrk*10);
	    
	    //else
	    // std::cout<<"Inserted non-ov track"<<std::endl;
	      //cms::trow error

	    double chiRProbc=TMath::Prob((*TrkCit).ChiSquaredR(),((*TrkCit).GetHitEntries()-2));
	  
	    
	    if(chiRProbc>0.1)
	      if((*TrkCit).GetHitEntries()>=8)
		if(fabs((*TrkCit).GetTySigma()/(*TrkCit).GetTy())<0.05){


		  if(((fabs((*TrkCit).GetHitT2(0).GetHitPhi()<96))&&(fabs((*TrkCit).GetHitT2(0).GetHitPhi()>84)))||
		     ((fabs((*TrkCit).GetHitT2(0).GetHitPhi()<276))&&(fabs((*TrkCit).GetHitT2(0).GetHitPhi()>264)))){
		  
		    if((separateTrkInH0)&&(separateTrkInH1)&&(whereistrk==0)&&(count_t2trackVectorALL_H1>0)){		      
		      TrkInOvH0.push_back((*TrkCit));
		    }	     	      

		  }


		if(((fabs((*TrkCit).GetHitT2(0).GetHitPhi()<96))&&(fabs((*TrkCit).GetHitT2(0).GetHitPhi()>84)))||
		   ((fabs((*TrkCit).GetHitT2(0).GetHitPhi()<276))&&(fabs((*TrkCit).GetHitT2(0).GetHitPhi()>264)))){
		  if((separateTrkInH0)&&(separateTrkInH1)&&(count_t2trackVectorALL_H0>0)&&(whereistrk==1)){
		    TrkInOvH1.push_back((*TrkCit));
		  }
		}
	      }
	    


	    bool OverlaTrkUsedpforInternal=false;

	    int Arm_ofOverlapTrk=TrackIsInTwoQuarter(TrkCit,7); //return -1 if it is not in the ov. region or wit at least 7 hit/half
 	    if(Arm_ofOverlapTrk!=-1)
	      {
		

		if((Arm_ofOverlapTrk==0)&&((count_t2trackVectorALL_H1+count_t2trackVectorALL_H0)<8))
		  {
		    inserted=MettiTracciaBuonaInOverlap(&MatriceTracceRelativeHalfAlignArm0,TrkCit,numevent); 
		    inserted_an_overl=inserted;
		    //I want to use this overlap track also for internal align
		    if(whereistrk==-1)
		      {
			T1T2TrackCollection trkcollH0;
			T1T2TrackCollection trkcollH1;
			T1T2Track trkH0=GiveMeTrkHalfPart(TrkCit,0);
			T1T2Track trkH1=GiveMeTrkHalfPart(TrkCit,1);
			trkcollH0.push_back(trkH0);
			trkcollH1.push_back(trkH1);
			T1T2TrackCollection::const_iterator trkiterH0 = trkcollH0.begin(); 
			T1T2TrackCollection::const_iterator trkiterH1 = trkcollH1.begin(); 
			//std::cout<<"Here0 Overlap Internal"<<trkiterH0->GetHitEntries()<<"  "<<trkiterH1->GetHitEntries()<<std::endl;
			//trkColl_i->push_back(GiveMeTrkHalfPart(TrkCit,0));  
			//trkColl_i->push_back(GiveMeTrkHalfPart(TrkCit,1)); 
			//std::cout<<"Here0"<<trkColl_i->size()<<" "<<trkColl_i->begin()->GetHitEntries()<<" "<<trkColl_i->end()->GetHitEntries()<<std::endl;
			if((trkiterH0->GetHitEntries()>=trkiterH1->GetHitEntries())&&(separateTrkInH0))		
			  {
			    //T1T2TrackCollection::const_iterator trkiter = trkColl_i->begin(); 
			    inserted=MettiTracciaBuona(&MatriceTracceh0a0,trkiterH0,numevent);
			    whereistrk=0;
			    OverlaTrkUsedpforInternal=true;
			    //  std::cout<<"Here0"<<std::endl;
			  }
			if((trkiterH1->GetHitEntries()>trkiterH0->GetHitEntries())&&(separateTrkInH1))	
			  {
			    //T1T2TrackCollection::const_iterator trkiter = trkColl_i->end(); 
			    inserted=MettiTracciaBuona(&MatriceTracceh1a0,trkiterH1,numevent);
			    whereistrk=1;
			    OverlaTrkUsedpforInternal=true;
			    //std::cout<<"Here1"<<std::endl;
			  }
			
		      }
		  }

		if((Arm_ofOverlapTrk==1)&&((count_t2trackVectorALL_H2+count_t2trackVectorALL_H3)<8))
		 { 
		   inserted=MettiTracciaBuonaInOverlap(&MatriceTracceRelativeHalfAlignArm1,TrkCit,numevent);
		   inserted_an_overl=inserted;
		   //I want to use this overlap track also for internal align
		    if(whereistrk==-1)
		      {
			T1T2TrackCollection trkcollH2;
			T1T2TrackCollection trkcollH3;
			T1T2Track trkH2=GiveMeTrkHalfPart(TrkCit,2);
			T1T2Track trkH3=GiveMeTrkHalfPart(TrkCit,3);
			trkcollH2.push_back(trkH2);
			trkcollH3.push_back(trkH3);
			T1T2TrackCollection::const_iterator trkiterH2 = trkcollH2.begin(); 
			T1T2TrackCollection::const_iterator trkiterH3 = trkcollH3.begin(); 
		
			if((trkiterH2->GetHitEntries()>=trkiterH3->GetHitEntries())&&(separateTrkInH2))		
			  {
			    //T1T2TrackCollection::const_iterator trkiter = trkColl_i->begin(); 
			    inserted=MettiTracciaBuona(&MatriceTracceh0a1,trkiterH2,numevent);
			    whereistrk=2;
			    OverlaTrkUsedpforInternal=true;
			    //  std::cout<<"Here0"<<std::endl;
			  }
			if((trkiterH3->GetHitEntries()>trkiterH2->GetHitEntries())&&(separateTrkInH3))	
			  {
			    //T1T2TrackCollection::const_iterator trkiter = trkColl_i->end(); 
			    inserted=MettiTracciaBuona(&MatriceTracceh1a1,trkiterH3,numevent);
			    whereistrk=3;
			    OverlaTrkUsedpforInternal=true;
			    //std::cout<<"Here1"<<std::endl;
			  }
			
		      }

		 }
		std::cout<<"Matrix filled for arm"<<Arm_ofOverlapTrk<<std::endl;
	      }


	    if((control>1)&&(OverlaTrkUsedpforInternal==false))
	      std::cout<<"ERROR: Unexpected behaviour of T2TrkBasedAlign code"<<std::endl;

	
	if((inserted))// Make plots for one quarter ad fill alignment starting roads
	  {
	  
	    //std::cout<<"Inserted track in matrix for half: "<<whereistrk<<std::endl;
	    //  std::cout<<"matrixentries= "<<matrixentries;
	    //std::cout<<"MatriceTracce.size()= "<<MatriceTracce.size()<<std::endl;
	    TrackInfo TrackInMatricRaw;

	    //  std::vector<TrackInfo> *test=&MatriceTracceh0a0;
	    if(whereistrk==0)
	      {
		MatriceTracce=&(MatriceTracceh0a0);
		TrackInMatricRaw=MatriceTracce->at(matrixentries0);
		matrixentries0++;
		
		//	matrixentries=matrixentries0;
	      }
	    if(whereistrk==1)
	      {		
		MatriceTracce=&(MatriceTracceh1a0);
		TrackInMatricRaw=MatriceTracce->at(matrixentries1);
		matrixentries1++;
		//	matrixentries=matrixentries1;
	      }
	    if(whereistrk==2)
	      {
		MatriceTracce=&(MatriceTracceh0a1);
		TrackInMatricRaw=MatriceTracce->at(matrixentries2);
		matrixentries2++;
		//matrixentries=matrixentries2;
	      }
	    if(whereistrk==3)
	      {
		MatriceTracce=&(MatriceTracceh1a1);
		TrackInMatricRaw=MatriceTracce->at(matrixentries3);
		matrixentries3++;	 
		
	      }
	    Taglio5_TrkSel->Fill((*TrkCit).GetHitEntries()+whereistrk*10);
	    // std::cout<<"Here3"<<std::endl;
	    
	   std::vector<TrackInfo::IdandHit> theidactive=TrackInMatricRaw.idactive;
	   
	   //std::cout<<" - - - - - - b --------"<<std::endl;
	   /*
	    if(whereistrk==3)
	      {
		if((*TrkCit).GetHitEntries()>9)
		  {
		    for(unsigned int mm=0;mm<theidactive.size();mm++)
		      std::cout<<mm<<" "<<theidactive.at(mm).iddet<<" "<<theidactive.at(mm).thehit.GetHitZ()<<std::endl;  
		    std::cout<<"  --------"<<std::endl;
		    for(unsigned int mm=0;mm<(*TrkCit).GetHitEntries();mm++)
		      if(RawtoSymb((*TrkCit).GetHitT2(mm).GetHitDetRawId())==35)
			std::cout<<mm<<" "<<RawtoSymb((*TrkCit).GetHitT2(mm).GetHitDetRawId())<<" "<<(*TrkCit).GetHitT2(mm).GetHitZ()<<" "<<(*TrkCit).GetHitT2(mm).GetHitClass()<<std::endl; 
		  }
	      }
	   */
	   if(whereistrk==(int)HalfSelectedForPlot)
	     {
	       // double trkphi=0.;
	       // double trketa=0.;
	      
	       NumhitinTrackGood->Fill((*TrkCit).GetHitEntries());
	       
	       //std::cout<<TrackInMatricRaw.aphi<<" - "<<TrackInMatricRaw.bphi<<"  Tot="<<TrackInMatricRaw.bphi+TrackInMatricRaw.aphi*14000.0<<std::endl;
	       Trkphigood->Fill(TrackInMatricRaw.bphi+TrackInMatricRaw.aphi*14000.0/*180.0/3.14159*/);
	       PolarAngles->Fill(TrackInMatricRaw.ar);
	       //std::cout<<"Evento "<<TrackInMatricRaw.eventnumber<<":"<<std::endl;	    
	       //std::cout<<TrackInMatricRaw.aphi<<" - "<<TrackInMatricRaw.bphi<<std::endl;
	       //std::cout<<" TrackInMatricRaw.goodhitnumber-Effgoodhitnumber:  "<<TrackInMatricRaw.goodhitnumber<<"-"<<Effgoodhitnumber<<std::endl;
	     } 
	   
	   // std::cout<<"\n \n"<<std::endl;
	   //std::cout<<"------------------------ \n"<<std::endl;
	   //  if(whereistrk>=0)
	   //std::cout<<"Single half Matrix Event: "<<TrackInMatricRaw.eventnumber<<std::endl;

	    if(TrackInMatricRaw.goodhitnumber>=Effgoodhitnumber)
	      {
		
		//--------------------------------------------
		// Begin of Important alignment loading  
		//--------------------------------------------
		// ALIGNMENT PART ....carico il vettore delle roads
		std::vector<T2Hit> alignmvect;
		for(unsigned int m=0;m<theidactive.size();m++)
		  {
		    if(theidactive.at(m).iddet==1) //It means the matrix has the hit in the "m" detector
			{

			  alignmvect.push_back(theidactive.at(m).thehit);
			  uint32_t rawiddet=theidactive.at(m).thehit.GetHitDetRawId();
			  AllDetId->Fill(RawtoSymb(rawiddet));
			  if(whereistrk==0)
			    if(std::find(alldetidh0.begin(),alldetidh0.end(),rawiddet)==alldetidh0.end())
			      {
				alldetidh0.push_back(rawiddet);			  			  
			      }
			  if(whereistrk==1)
			    if(std::find(alldetidh1.begin(),alldetidh1.end(),rawiddet)==alldetidh1.end())
			      {
				alldetidh1.push_back(rawiddet);			  			  
			      }
			  if(whereistrk==2)
			    if(std::find(alldetidh2.begin(),alldetidh2.end(),rawiddet)==alldetidh2.end())
			      {
				alldetidh2.push_back(rawiddet);			  			  
			      }
			  if(whereistrk==3)
			    if(std::find(alldetidh3.begin(),alldetidh3.end(),rawiddet)==alldetidh3.end())
			      {
				alldetidh3.push_back(rawiddet);			  			  
			      }
			  
			}
		  }
		
		if(alignmvect.at(0).GetHitR()<AlignmentHitRMax)
                if(alignmvect.at(0).GetHitR()> AlignmentHitRMin)
		  if(alignmvect.size()>=HitNumb4Align)
		    {
		      //roadXfit.push_back(alignmvect);
		      //roadYfit.push_back(alignmvect);
		      double XovY=fabs(alignmvect.at(0).GetHitX()/alignmvect.at(0).GetHitY());
		      double YovX=fabs(alignmvect.at(0).GetHitY()/alignmvect.at(0).GetHitX());
		      bool taketrackForXalign=false;
		      bool taketrackForYalign=false;
		      

		      if((XovY>ratioXYAlignTrkcut)&&((fabs(alignmvect.at(0).GetHitX())/fabs(alignmvect.at(0).GetHitR()))>0.7))
			taketrackForXalign=true;
		      if((YovX>ratioXYAlignTrkcut)&&((fabs(alignmvect.at(0).GetHitY())/fabs(alignmvect.at(0).GetHitR()))>0.7))
			taketrackForYalign=true;
		      //
		      //std::cout<<"Geant det B:  "<<hitMap.size()<<std::endl;
		      if(taketrackForXalign)
			MakeHitResolSimuHisto(hitMap,alignmvect,'X');
		      if(taketrackForYalign)
			MakeHitResolSimuHisto(hitMap,alignmvect,'Y');


		      if(whereistrk==(int)HalfSelectedForPlot)
			{
			  if(IsTrkInFULLAccept(alignmvect,HalfSelectedForPlot))
			    CommonTrackforPlot.push_back(alignmvect);
			}
		      
		      if(whereistrk==0)
			{
			  if(taketrackForXalign)
			    roadXfith0.push_back(alignmvect);
			  if(taketrackForYalign)
			    roadYfith0.push_back(alignmvect);
			  //	  std::cout<<"Filling roadXfith0"<<std::endl;
			}
		      
		      if(whereistrk==1)
			{
			  if(taketrackForXalign)
			    roadXfith1.push_back(alignmvect);
			  if(taketrackForYalign)
			    roadYfith1.push_back(alignmvect);
			  //	  std::cout<<"Filling roadXfith1. size="<<roadYfith1.size()<<std::endl;
			}
		      
		      if(whereistrk==2)
			{
			  if(taketrackForXalign)
			    roadXfith2.push_back(alignmvect);
			  if(taketrackForYalign)
			    roadYfith2.push_back(alignmvect);
			}
		      
		      if(whereistrk==3)
			{
			  if(taketrackForXalign)
			    roadXfith3.push_back(alignmvect);
			  if(taketrackForYalign)
			    roadYfith3.push_back(alignmvect);
			}
		    }

		//--------------------------------------------
		// End of Important alignment loading  
		//--------------------------------------------

		//--------------------------------------------
		// Begin of Before-alignment-related  Histograms
		//--------------------------------------------		 


		if(whereistrk==(int)HalfSelectedForPlot)
		  {
		    
		    NumhitinTrackAligned->Fill(TrackInMatricRaw.goodhitnumber);
		    
		   //alignmvect.size()>Effgoodhitnumber ?? sempre soddisfatta
		    //ProbXHisto->Fill(chi2X(alignmvect,UseJointProb).at(0));
		    //ProbYHisto->Fill(chi2Y(alignmvect,UseJointProb).at(0));
		    //TrkChi2X->Fill(chi2X(alignmvect,UseJointProb).at(1));
		    //TrkChi2Y->Fill(chi2Y(alignmvect,UseJointProb).at(1));

		    TMatrixD covmat(4,4);
		    covmat.Zero();
		    double chi2corr;		
		    std::vector<double> trkparam=MyLinearfitCorr(alignmvect,covmat,chi2corr);


		    AXError->Fill(trkparam.at(4));
		    AXHisto->Fill(trkparam.at(0));
		    AYHisto->Fill(trkparam.at(2));
		    BXError->Fill(trkparam.at(5));
		    AYError->Fill(trkparam.at(6));
		    BYError->Fill(trkparam.at(7));

		    std::vector<double> drphi4Alignment;

		    //if(chi2X(refhitv)>0.05)paramvectForAlign=MyLinearfit(refhitv);
		    // if(chi2Y(refhitv)>0.05)


		    T2Hit hpl[10];

		    bool pres[10];
		    pres[0]=false; pres[1]=false;  pres[2]=false;  pres[3]=false;  pres[4]=false; 
		    pres[5]=false;  pres[6]=false;  pres[7]=false;  pres[8]=false;  pres[9]=false;

		    if(alignmvect.size()>=(HitNumb4Align-2))
		    for (unsigned int u=0;u<alignmvect.size();u++)
		      {
			unsigned int  symb=alignmvect.at(u).GetHitPlane()*2+alignmvect.at(u).GetHitPlaneSide();

			if(alignmvect.at(u).GetHitNumStrip()<=4)
			  if(alignmvect.at(u).GetHitNumPad()<=3)
			    {
			      if (symb==0)
				{
				  hpl[0]=alignmvect.at(u);
				  pres[0]=true;
				}
			      if (symb==1)
				{
				  hpl[1]=alignmvect.at(u);
				  pres[1]=true;
				}				    
			      if (symb==2)
				{
				  hpl[2]=alignmvect.at(u);
				  pres[2]=true;
				}	
			      if (symb==3)
				{
				  hpl[3]=alignmvect.at(u);
				  pres[3]=true;
				}
			      if (symb==4)
				{
				  hpl[4]=alignmvect.at(u);
				  pres[4]=true;
				}				    
			      if (symb==5)
				{
				  hpl[5]=alignmvect.at(u);
				  pres[5]=true;
					 }	
			      if (symb==6)
				{
				  hpl[6]=alignmvect.at(u);
				  pres[6]=true;	
				}
			      if (symb==7)
				{
				  hpl[7]=alignmvect.at(u);
				  pres[7]=true;
				}				    
			      if (symb==8)
				{
				  hpl[8]=alignmvect.at(u);
				  pres[8]=true;
				}	
			      if (symb==9)
				{
				  hpl[9]=alignmvect.at(u);
				  pres[9]=true;	
				}
			      
			      PlaneUsedInAl->Fill(whereistrk*10+symb);
			    }
		      }

		    if(alignmvect.size()>=(HitNumb4Align-2))
		      for (unsigned int u=0;u<alignmvect.size();u++)
			{
			  drphi4Alignment=ResiduiRPhi(trkparam,alignmvect.at(u).GetHitX(), alignmvect.at(u).GetHitY(),alignmvect.at(u).GetHitZ());
			  unsigned int  symb=alignmvect.at(u).GetHitPlane()*2+alignmvect.at(u).GetHitPlaneSide();
			  if(alignmvect.at(u).GetHitNumStrip()<=4)
			    if(alignmvect.at(u).GetHitNumPad()<=3)
			      {
				if(alignmvect.at(u).GetHitR()<AlignmentHitRMax)
				if(alignmvect.at(u).GetHitR()>AlignmentHitRMin)
				  if((fabs(trkparam[0]<0.03))&&(fabs(trkparam[2]<0.03)))
				    {
				      //DXAlignDet[symb]->Fill(drphi4Alignment.at(0));
				      //DYAlignDet[symb]->Fill(drphi4Alignment.at(1));
				      if(symb>0)
					if((pres[symb])&&(pres[symb-1]))
					  {
					    DXResp0[symb]->Fill(hpl[symb].GetHitX()-hpl[symb-1].GetHitX());
					    DYResp0[symb]->Fill(hpl[symb].GetHitY()-hpl[symb-1].GetHitY());
					  }
				      if(symb==0)
					{
					  DXResp0[symb]->Fill(0.);
					  DYResp0[symb]->Fill(0.);
					}
				      if(pres[9])
					{
					  DXResp9[symb]->Fill(hpl[9].GetHitX()-alignmvect.at(u).GetHitX());
					  DYResp9[symb]->Fill(hpl[9].GetHitY()-alignmvect.at(u).GetHitY());
					 }
				      double expX=(trkparam[0]*alignmvect.at(u).GetHitZ()+trkparam[1]);
				      double expY=(trkparam[2]*alignmvect.at(u).GetHitZ()+trkparam[3]);  
				      double expPhi=atan(fabs(expY)/fabs(expX));
				      expPhi=expPhi*180.0/3.14159;
				      if(expY<0)
					expPhi=360.0-expPhi;
				      // double expR= sqrt(expX*expX+expY*expY);

				      //double measuredphi=alignmvect.at(u).GetHitPhi();
				      // double mesuredR=alignmvect.at(u).GetHitR();  

				      double measuredphi2=atan(fabs(alignmvect.at(u).GetHitY())/fabs(alignmvect.at(u).GetHitX()));
				      measuredphi2=measuredphi2*180.0/3.14159;
				      if(alignmvect.at(u).GetHitY()<0)
					measuredphi2=360.0-measuredphi2;

				      //double mesuredR2=sqrt(alignmvect.at(u).GetHitX()*alignmvect.at(u).GetHitX()+alignmvect.at(u).GetHitY()*alignmvect.at(u).GetHitY());


				      //CumulativeRResol->Fill(expR-mesuredR);
				      ///CumulativePhiResol->Fill(expPhi-measuredphi);

				      //DRResol[symb]->Fill(expR-mesuredR);  
				      //DPhiResol[symb]->Fill(expPhi-measuredphi);

				    }
			      }
			}

		  }

		 //--------------------------------------------
		 // End of Before-alignment-related  Histograms
		 //--------------------------------------------


		//	std::cout<<"Here4-1"<<std::endl;

	      }//if(TrackInMatricRaw.goodhitnumber>=Effgoodhitnumber)
	  

	    ///////////////////////////////////////
	    //Loading of the overlap roads
	    ////////////////////////////////////////
	    //if(DoAlignHalfHalf)
	    
	    if((Arm_ofOverlapTrk!=(-1))&&(inserted_an_overl))
	      {
		//std::cout<<"Before Arm0 Overl matrix size: "<<MatriceTracceRelativeHalfAlignArm0.size()<<std::endl;
		 // std::cout<<"Looking in pos"<<matrixentries_Overl_Arm0;
		 //std::cout<<"Inserting track for overlapping Arm "<<Arm_ofOverlapTrk <<". Matrix size: ";
		TrackInfo TrackInMatrixRawOverlap;
		if(Arm_ofOverlapTrk==0)
		  {		   
		    MatriceTracceTwoHalfs=&(MatriceTracceRelativeHalfAlignArm0);
		    //std::cout<<MatriceTracceRelativeHalfAlignArm0.size();
		    TrackInMatrixRawOverlap=MatriceTracceRelativeHalfAlignArm0.at(matrixentries_Overl_Arm0);
		    matrixentries_Overl_Arm0++;	       
		    //std::cout<<"Now Arm0 Overl matrix size: "<<MatriceTracceRelativeHalfAlignArm0.size()<<std::endl;
		  }

		//std::cout<<"Here4A"<<std::endl;
		if(Arm_ofOverlapTrk==1)
		  {
		    MatriceTracceTwoHalfs=&(MatriceTracceRelativeHalfAlignArm1);
		    TrackInMatrixRawOverlap=MatriceTracceRelativeHalfAlignArm1.at(matrixentries_Overl_Arm1);
		    matrixentries_Overl_Arm1++;	 
		    // std::cout<<"Arm1 Overl matrix size: "<<MatriceTracceRelativeHalfAlignArm1.size()<<std::endl;
		  }

		//	std::cout<<"Here4B"<<std::endl;
		std::vector<TrackInfo::IdandHit> theidactiveOverlap=TrackInMatrixRawOverlap.idactive;
		
		if(TrackInMatrixRawOverlap.goodhitnumber>=EffgoodhitnumberOverl)
		  {
		    std::vector<T2Hit> alignmvectOverlap;
		    for(unsigned int m=0;m<theidactiveOverlap.size();m++)
		      {
			if(theidactiveOverlap.at(m).iddet==1)
			  alignmvectOverlap.push_back(theidactiveOverlap.at(m).thehit);
		      }   
		
		    if(alignmvectOverlap.at(0).GetHitR()<OverlapTrkHitRMax)
		      if(fabs((*TrkCit).Eta())> HighEtaForOverlapAlign)
			{
			  //  std::cout<<"Ov. Trk with "<<(*TrkCit).GetHitEntries()<<"|"<<alignmvectOverlap.size()<<" inserted for arm "<<Arm_ofOverlapTrk<<std::endl;
			  if(Arm_ofOverlapTrk==0)
			    roadfitOverlapARM0.push_back(alignmvectOverlap);
			  if(Arm_ofOverlapTrk==1)
			    roadfitOverlapARM1.push_back(alignmvectOverlap);
			}			 		  
		  }
	      }
	    //else
	    //  std::cout<<"Warning: problems in quarter alignment"<<std::endl;
	     /////////////////////////////////////
	     //End Loading of Ovelapping roads
	     /////////////////////////////////////
	    //   std::cout<<"Here5"<<std::endl;
	    
	  }//if inserted
      }//end Track::event loop

      
    }//if numevent<MaxEv -> carica matrice
  
      
 
      //Selection of matching Ov. Tracks.
      for(unsigned int i0=0;i0<TrkInOvH0.size();i0++) 
	for(unsigned int i1=0;i1<TrkInOvH1.size();i1++)
	  {
	    if(fabs(TrkInOvH0.at(i0).GetHitT2(0).GetHitY()-TrkInOvH1.at(i1).GetHitT2(0).GetHitY())<3.0)
	      if(fabs(TrkInOvH0.at(i0).GetHitT2(0).GetHitZ()-TrkInOvH1.at(i1).GetHitT2(0).GetHitZ())<50){
		std::pair<T1T2Track,T1T2Track> trkh0h1(TrkInOvH0.at(i0),TrkInOvH1.at(i1));
		//std::cout<<TrkInOvH0.at(i0).GetTy()-TrkInOvH1.at(i1).GetTy()<<" "<<TrkInOvH0.at(i0).GetTy()<<"-"<<TrkInOvH1.at(i1).GetTy()<<" "<<TrkInOvH0.at(i0).GetHitT2(0).GetHitY()<<" "<<TrkInOvH0.at(i0).GetHitT2(0).GetHitR()<<" TyErr:"<<TrkInOvH0.at(i0).GetTySigma()<<std::endl;
		PairsOfOvTrkArm0.push_back(trkh0h1);
	      }
	      	   	     
	  }

  //std::cout<<"Here6"<<std::endl;

 //*************************************************************************************************
 //-----------------------------                                               ---------------------   
 //-----------------------------  ANALYSIS and Internal ALIGNMENT CALCULATION  ---------------------
 //-----------------------------                                               ---------------------
 //*************************************************************************************************

 // std::cout<<"here"<<std::endl;
  if((numevent%100)==0)
    std::cout<<"Event: "<<numevent<<std::endl;

  //std::cout<<"here"<<std::endl;
  if(numevent==MaxEvents)  // Make analysis, start Internal alignment procedure
    {
      
      std::cout<<"Opening file for store internal alignment "<<std::endl;
      std::string namefiledis=outputFileName;
      std::string namefiledis_Simp=outputFileName;
      std::string sought = ".root";
      int pos=namefiledis.find(sought); 
      namefiledis.replace(pos, sought.size(), "HIP.dat"); 
      namefiledis_Simp.replace(pos, sought.size(), "QTiltSimp.dat");
      
      std::cout<<"Internal alignment file "<<namefiledis.c_str()<<std::endl;
      fstream file_op(namefiledis.c_str(), ios::out); 
      fstream file_opS(namefiledis_Simp.c_str(), ios::out); 
      //Warning!! Found very strange problem opening file with "in" flag,file is written only if it already exists in the path.
      //fstream file_op("test.dat",ios::in | ios::out);
      if(IncludeQuarterTiltAlign){
	if(((file_opS).is_open())==false)
	{
	  std::cout<<"ERROR: Problem in opening file used for simple tilt estimation IN T2TrkBased().cc"<<std::endl;
	  (file_opS).clear();
	}	
      }

      if(((file_op).is_open())==false)
	{
	  std::cout<<"ERROR: Problem in opening file IN T2TrkBased().cc"<<std::endl;
	  (file_op).clear();
	}
     
      std::string SaveMille=outputFileName;
      std::string sought2 = ".root";
      int pos2=SaveMille.find(sought2); 
      SaveMille.replace(pos2, sought2.size(), "Mille.dat"); 

       //std::string namefiledisMille= string(cmsswPath) + string("/src/TotemAlignment/T2TrkBasedInternalAlignment/test/") + SaveMille;
      std::string namefiledisMille=SaveMille;
      fstream file_opMille(namefiledisMille.c_str(), ios::out); 
      //Warning!! Found very strange problem opening file with "in" flag,file is written only if it already exists in the path.
      //fstream file_op("test.dat",ios::in | ios::out);
      if(((file_opMille).is_open())==false)
	{
	  std::cout<<"ERROR: Problem in opening file IN "<<namefiledisMille.c_str()<<std::endl;
	  (file_opMille).clear();
	}
      

      if(DoInternalAlign==true)
	{

      
	  for (unsigned int half=0;half<SelectedHalfs.size();half++)
	    {
	       unsigned int thehalf=SelectedHalfs.at(half);

	       std::cout<<"Internal alignment. SelectedHalfs.at("<<half<<")="<<thehalf<<std::endl;
	     if(thehalf==0)
	       {
		 alldetid=alldetidh0;
		 //MatriceTracce=&MatriceTracceh0a0;
		 roadXfit=roadXfith0;
		 roadYfit=roadYfith0;	      
	       }
	     if(thehalf==1)
	       {
		 alldetid=alldetidh1;
		 //	MatriceTracce=&MatriceTracceh1a0;
		 roadXfit=roadXfith1;
		 roadYfit=roadYfith1;	      
	       }
	     if(thehalf==2)
	       {
		 alldetid=alldetidh2;
		 //MatriceTracce=&MatriceTracceh0a1;
		 roadXfit=roadXfith2;
		 roadYfit=roadYfith2;	      
	       }
	     if(thehalf==3)
	       {
		 alldetid=alldetidh3;
		 //MatriceTracce=&MatriceTracceh1a1;
		 roadXfit=roadXfith3;
		 roadYfit=roadYfith3;	      
	       }


	     if(UseMillePede)
	       {     
		 std::vector<std::vector<double> > Results =  millepedeobj->CallMille(thehalf,&roadXfit,&roadYfit);
		 millepedeobj->SaveMisalinFile(thehalf,Results,&file_opMille);
		 
	       }
	     
	     //ITERATIVE ALGORITHM

	     std::cout<<"Computing parameters for half: "<<thehalf<<std::endl;
	     //std::cout<<"Eventi della matrice "<< (*MatriceTracce).size()<<std::endl;
	     std::cout << "Alignment will work with "<< MaxEvents <<" events and " <<roadXfit.size()<<"-"<<roadYfit.size()<<" X-Y Roads"<<" having hits in "<<alldetid.size() <<" different detectors."<<std::endl;

	   	     

	     for(unsigned int i=0;i<alldetid.size();i++)
	       {
		 std::cout<<"alldetid.at("<<i<<") = "<<RawtoSymb(alldetid.at(i))<<std::endl;
	       }

	     //unsigned int MaxStepalignstep=100;
	     double DXDYMaxDisp=MeasuredResol_X;
	     //align X first
	     //double  SHIFTprescale=1.0;
	     bool XalignReached=false;
	     bool YalignReached=false;
	     std::map<uint32_t,double> DXDisalignVect;
	     std::map<uint32_t,double> DXOldDisalignVect;
	     std::map<uint32_t,double> DYDisalignVect;
	     std::map<uint32_t,double> DYOldDisalignVect;
	     origroadXfit=roadXfit;
	     origroadYfit=roadYfit;

	     std::vector<double> TotDXDisp;
	     std::vector<double> TotDYDisp;

	     for(unsigned int m=0; m<10;m++)
	       {
		 TotDXDisp.push_back(0.);
		 TotDYDisp.push_back(0.);
	       }

	     std::vector<double> TotDXDispErr;
	     std::vector<double> TotDYDispErr;
	     std::vector<double> TotDXDispErr_Hip;
	     std::vector<double> TotDYDispErr_Hip;


	     for(unsigned int m=0; m<10;m++)
	       {
		 TotDXDispErr.push_back(0.);
		 TotDYDispErr.push_back(0.);
		 // TotDXDispErr_Hip.push_back(0.);
		 //TotDYDispErr_Hip.push_back(0.);
	       }

	     //------------------------------------------------
	     //Map DisalignVect,OldDisalignVect  initialization
	     //------------------------------------------------

	     std::pair<uint32_t,double> toput;
	     double toputAl=0.;


	     for(unsigned int m=0; m<alldetid.size();m++)
	       {
		 //  toputAl.rawt2detid=alldetid.at(m);
		 toput.first=alldetid.at(m);
		 toput.second=toputAl;
		 DXOldDisalignVect.insert(toput);
		 DYOldDisalignVect.insert(toput);
	       }


	     DXDisalignVect=DXOldDisalignVect;
	     DYDisalignVect=DYOldDisalignVect;


	     //------------------------------------------------
	     // Start to iterate over the each-time-updated track parameters
	     //------------------------------------------------

	     unsigned int Xalignstep=0;
	     unsigned int Yalignstep=0;
	     unsigned int refposx=30;


	     //--------------------------------------------------------------
	     //                         ALLINEAMENTO X
	     //--------------------------------------------------------------


	     //xi -DXi=xith . -DXi ?? shift detector
	     while((Xalignstep<MaxStepalignstep)&&(XalignReached==false))
	       {
		 std::cout << "DX Alignment Step "<< Xalignstep<<" ..." <<  std::endl;

		 //vettore dei parametri di traccia
		 startingtracksDX.clear();
		 std::vector<double> parmx;
		 std::vector<unsigned int> countdetstat;
		 for(unsigned int m=0; m<10;m++)
		   {
		     countdetstat.push_back(0);
		   }
		 std::vector<double> DXi;
		 std::vector<double> DXiDen;
		 for(unsigned int m=0; m<10;m++)
		   {
		     DXi.push_back(0.);
		     DXiDen.push_back(0.);
		   }

		 for(unsigned int k=0; k<roadXfit.size();k++)
		   {

		     std::vector<T2Hit> hitv;
		     std::vector<T2Hit> hitvForResidual;
		     // The Only Difference respect to the alignment code is that roadXfit is not a vect of road but a vect of vect of hit
		     for (unsigned int g=0;g<roadXfit[k].size();g++)
		       hitv.push_back(roadXfit[k].at(g));

		     TMatrixD covmat(4,4);
		     double chi2corr;
		     	

		     for(unsigned int i=0; i<alldetid.size();i++)
		       {
			 
			 uint32_t thedet=alldetid.at(i);

			 unsigned int symbolic1=RawtoSymb(thedet);
			 symbolic1=symbolic1%10;
			 unsigned int symbolic2;
			 for(unsigned int f=0; f<hitv.size();f++)
			   {
			     
			     symbolic2=RawtoSymb(hitv.at(f).GetHitDetRawId());
			     unsigned int absSymb=hitv.at(f).GetHitDetRawId();
			     symbolic2=symbolic2%10;
			     if(symbolic2==symbolic1)
			       {
				 std::vector<double> corrFit;				 
				 std::vector<double> support;
				 covmat.Zero();
				 hitvForResidual.clear();
				 hitvForResidual=GiveMeTheHitForResidual(absSymb,hitv);
				 corrFit=MyLinearfitCorr(hitvForResidual,covmat,chi2corr);
		     
				 for(unsigned int c=0;c<2;c++)
				   {
				     support.push_back(corrFit[c]);
				   }
				 for (unsigned int c=0;c<2;c++)
				   {
				     support.push_back(covmat(c,c));
				   }
				 support.push_back(covmat(0,1));

				 double phirad=hitv.at(f).GetHitPhi()*3.14159/180.0;
				 double sigmax2=cos(phirad)*cos(phirad)*0.12*0.12+sin(phirad)*sin(phirad)*0.015*0.015*hitv.at(f).GetHitR()*hitv.at(f).GetHitR(); 
				 //sigmax2=1.0;
				 //std::cout<<"X-Y-R-Z-phi-sigma: "<<hitv.at(f).GetHitX()<<"-"<<hitv.at(f).GetHitY()<<"-"<<hitv.at(f).GetHitR()<<"-"<<hitv.at(f).GetHitZ()<<"-"<<hitv.at(f).GetHitPhi()<<"-"<<sqrt(sigmax2)<<std::endl;
				 //std::cout<<"Exp X pos: "<<(startingtracksDX.at(k)).at(0)*hitv.at(f).GetHitZ()+(startingtracksDX.at(k)).at(1)<<std::endl;
				 DXi.at(symbolic1)=DXi.at(symbolic1)+(hitv.at(f).GetHitX()-support.at(0)*hitv.at(f).GetHitZ()-support.at(1))/sigmax2; 
				 DXiDen.at(symbolic1)=DXiDen.at(symbolic1)+1.0/sigmax2;
				 countdetstat.at(symbolic1)++;
				 //  std::cout<<DXi.at(symbolic1)<<std::endl;
			       }
			     
			   }		   

		       }	      	   	      

		   }
	

		 //		 double refPositDX=0.;
		 
		 for(unsigned int m=0; m<10;m++)
		   {

		     if(countdetstat.at(m)>0)
		       {
			 DXi.at(m)= DXi.at(m)/DXiDen.at(m);			   
		
			  if(std::find(IdreferencedetHIP.begin(),IdreferencedetHIP.end(),(m+thehalf*10))!=IdreferencedetHIP.end()) 
			   {
			     //refPositDX=DXi.at(m);
			     refposx=m;
			     double imposed=0.;
			      //if(Xalignstep==0) Change reference DX only first time then set it to 0
			     if(Xalignstep==0){
			       unsigned int posinV=std::find(IdreferencedetHIP.begin(),IdreferencedetHIP.end(),(m+thehalf*10))-IdreferencedetHIP.begin();
			       imposed=XreferencedetHIP.at(posinV);
			     }else
			       imposed=0.;
			     
			     std::cout<<"DXi.at("<<m<<") From "<<DXi.at(m)<<" forced to "<<imposed<<std::endl;
			     DXi.at(m)=imposed;
			     //DXi.at(m)=0.;
			   }
			 else
			   std::cout<<"DXi.at("<<m<<")= "<<DXi.at(m)<<std::endl;
		       }
		   }

		 // FIND max DXi
		 double maxDXi=0.;
		 unsigned int maxind=0;
		 for(unsigned int m=0; m<10;m++)
		   {		     
		     if(fabs(DXi.at(m))>maxDXi)
		       {
			 maxind=m;
			 maxDXi=fabs(DXi.at(m));
		       }
		   }

		 // Update hit in roadXfit
		 if(maxDXi>DXDYMaxDisp)
		   {
		     std::cout<<"Found X displ. of detector "<<maxind<<"of "<<DXi.at(maxind)<<std::endl;


		     if((AllCorrectionAtSameTime==false))
		       TotDXDisp.at(maxind)=TotDXDisp.at(maxind)+(DXi.at(maxind)/SHIFTprescale);
		     else
		       for(unsigned int m=0; m<10;m++)
			 TotDXDisp.at(m)=TotDXDisp.at(m)+(DXi.at(m)/SHIFTprescale);
		      		      		     
		     std::vector<double> TotDXDispErr_iter;
		     
		     for(unsigned int k=0; k<roadXfit.size();k++)
		       {
			 for (unsigned int g=0;g<roadXfit[k].size();g++)
			   {

			     unsigned int symbolic2=RawtoSymb(roadXfit[k].at(g).GetHitDetRawId());
			     symbolic2=symbolic2%10;
			     if((AllCorrectionAtSameTime==true)||((AllCorrectionAtSameTime==false)&&(symbolic2==maxind)))
			       {			  
				 roadXfit[k].at(g).SetHitX(roadXfit[k].at(g).GetHitX()-(DXi.at(symbolic2)/SHIFTprescale));
				 // std::cout<<"upda"<<std::endl;
			       }		  		  
			   }
		       }
		    
		    
		     
		   } 

		 // se max DXi<DXDYMaxDisp  alignreached=true

		
		 if(maxDXi<DXDYMaxDisp){
		    XalignReached=true;
		    if(CalculateErrorAsHIP)
		      for(unsigned int m=0; m<10;m++)
			{
			  TotDXDispErr.at(m)=CalculateAlignHIP(roadXfit,1,thehalf,m);
			}
		 }


		 Xalignstep++;
	       }

	    



	     //--------------------------------------------------------------
	     //                         ALLINEAMENTO Y
	     //--------------------------------------------------------------
	     
	     DXDYMaxDisp=MeasuredResol_Y;

	     while((Yalignstep<MaxStepalignstep)&&(YalignReached==false))
	       {
		 std::cout << "DY Alignment Step "<< Yalignstep<<" ..." <<  std::endl;

		 //vettore dei parametri di traccia
		 startingtracksDY.clear();
		 std::vector<double> parmy;
		 std::vector<unsigned int> countdetstat;
		 for(unsigned int m=0; m<10;m++)
		   {
		     countdetstat.push_back(0);
		   }

		 std::vector<double> DYi;
		 std::vector<double> DYiDen;
		 for(unsigned int m=0; m<10;m++)
		   {
		     DYi.push_back(0.);
		     DYiDen.push_back(0.);
		   }

		 for(unsigned int k=0; k<roadYfit.size();k++)
		   {

		     std::vector<T2Hit> hitv;
		     std::vector<T2Hit> hitvForResidual;

		     for (unsigned int g=0;g<roadYfit[k].size();g++)
		       hitv.push_back(roadYfit[k].at(g));

		     //parmy=MyLinearfitY(hitv,UseJointProb);

		     TMatrixD covmat(4,4);
		     double chi2corr;
		     covmat.Zero();
		    

		     for(unsigned int i=0; i<alldetid.size();i++)
		       {

			 uint32_t thedet=alldetid.at(i);
			 
			 unsigned int symbolic1=RawtoSymb(thedet);
			 symbolic1= symbolic1%10;
			 unsigned int symbolic2;
			 for(unsigned int f=0; f<hitv.size();f++)
			   {

			     symbolic2=RawtoSymb(hitv.at(f).GetHitDetRawId());
			     unsigned int absSymb=hitv.at(f).GetHitDetRawId();
			     symbolic2= symbolic2%10;
			     if(symbolic2==symbolic1)
			       {
				 std::vector<double> corrFit;				 
				 std::vector<double> support;
				 covmat.Zero();
				 hitvForResidual.clear();
				 hitvForResidual=GiveMeTheHitForResidual(absSymb,hitv);
				 corrFit=MyLinearfitCorr(hitvForResidual,covmat,chi2corr);
		     
				 
				 for(unsigned int c=0;c<2;c++)
				   {
				     support.push_back(corrFit[2+c]);
				   }
				 for (unsigned int c=0;c<2;c++)
				   {
				     support.push_back(covmat(2+c,2+c));
				   }
				 support.push_back(covmat(2,3));
				 			      
				 double phirad=hitv.at(f).GetHitPhi()*3.14159/180.0;
				 double sigmay2=sin(phirad)*sin(phirad)*0.12*0.12+cos(phirad)*cos(phirad)*0.015*0.015*hitv.at(f).GetHitR()*hitv.at(f).GetHitR();
				 //double resid=(hitv.at(f).GetHitY()-support.at(0)*hitv.at(f).GetHitZ()-support.at(1));

				 //sigmay2=1.0;
				 DYi.at(symbolic1)=DYi.at(symbolic1)+(hitv.at(f).GetHitY()-support.at(0)*hitv.at(f).GetHitZ()-support.at(1))/sigmay2;


				 //DYiDen.at(symbolic1)=DYiDen.at(symbolic1)+1.0/fabs(hitv.at(f).GetHitY());
				 DYiDen.at(symbolic1)=DYiDen.at(symbolic1)+1.0/sigmay2;

				 // if(symbolic1==0)
				 //   std::cout<<"Dy:"<<DYi.at(symbolic1)<<" Den:"<<DYiDen.at(symbolic1)<<"  Sigma:"<<sigmay2<<" Resid:"<<resid<<std::endl;

				 countdetstat.at(symbolic1)++;


			       }

			   }		   

		       }	      	   	      

		   }
		 // (std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),halftoAl)==RefHalfsWholeQuarterAlign.end())

		 double refPositDY=0.;
		 unsigned int refposy=0;
		 for(unsigned int m=0; m<10;m++)
		   {

		     if(countdetstat.at(m)>0)
		       {
			 //DYi.at(m)= DYi.at(m)/countdetstat.at(m);
			 DYi.at(m)= DYi.at(m)/DYiDen.at(m);
			 
		
			  if(std::find(IdreferencedetHIP.begin(),IdreferencedetHIP.end(),(m+thehalf*10))!=IdreferencedetHIP.end())
			   {
			     refPositDY=DYi.at(m);
			     refposy=m;
			     
			     double imposed=0.;
			      //if(Xalignstep==0) Change reference DX only first time then set it to 0
			     if(Yalignstep==0){
			       unsigned int posinV=std::find(IdreferencedetHIP.begin(),IdreferencedetHIP.end(),(m+thehalf*10))-IdreferencedetHIP.begin();
			       imposed=YreferencedetHIP.at(posinV);
			     }else
			       imposed=0.;
			     
			     std::cout<<"DYi.at("<<m<<") From "<<DYi.at(m)<<" forced to "<<imposed<<std::endl;
			     DYi.at(m)=imposed;


			     //std::cout<<"DYi.at("<<m<<") From "<<DYi.at(m)<<" to 0"<<std::endl;
			     //DYi.at(m)=0.;
			   }
			 else
			    std::cout<<"DYi.at("<<m<<")= "<<DYi.at(m)<<std::endl;
			 // std::cout<<DYi.at(m)<<std::endl;			
		       }
		   }
		 if(false)
		   std::cout<<refPositDY<<refposy<<std::endl;
		 // FIND max DYi  
		 double maxDYi=0.;
		 unsigned int maxind=0;
		 for(unsigned int m=0; m<10;m++)
		   {
		     if(fabs(DYi.at(m))>maxDYi)
		       {
			 maxind=m;
			 maxDYi=fabs(DYi.at(m));
		       }
		   }

		 // Update hit in roadYfit
		 if(maxDYi>DXDYMaxDisp)
		   {
		     std::cout<<"Found Y displ. of detector "<<maxind<<"of "<<DYi.at(maxind)<<std::endl;
		     
		     if((AllCorrectionAtSameTime==false))
		       TotDYDisp.at(maxind)=TotDYDisp.at(maxind)+(DYi.at(maxind)/SHIFTprescale);
		     else
		       for(unsigned int m=0; m<10;m++)
			 TotDYDisp.at(m)=TotDYDisp.at(m)+(DYi.at(m)/SHIFTprescale);
		     
		     //Before2 Feb
		     //TotDYDispErr=CalculateAlignError2(TotDYDisp,roadYfit,2,false,TotDYDispErr);
		     //Note: you need to add somehow the bias of the alignment. Indeed internal alignment
		     //can give you perfetc align track but a little bit tilted...
		     /*
		     std::vector<double> TotDYDispErr_iter;
		     TotDYDispErr_iter=CalculateAlignError2(TotDYDisp,roadYfit,2,false,TotDYDispErr);
		     for(unsigned int m=0; m<10;m++)
		       {
			 TotDYDispErr.at(m)=TotDYDispErr.at(m)+TotDYDispErr_iter.at(m);
		       }
		     */
		     for(unsigned int k=0; k<roadYfit.size();k++)
		       {
			 for (unsigned int g=0;g<roadYfit[k].size();g++)
			   {

			     unsigned int symbolic2=RawtoSymb(roadYfit[k].at(g).GetHitDetRawId());
			     symbolic2= symbolic2%10;
			     if((AllCorrectionAtSameTime==true)||((AllCorrectionAtSameTime==false)&&(symbolic2==maxind)))
			       {
				 roadYfit[k].at(g).SetHitY(roadYfit[k].at(g).GetHitY()-(DYi.at(symbolic2)/SHIFTprescale));
			       }

			   }
		       }
		     

		   }

		 // se max DXi<DXDYMaxDisp  alignreached=true
		  if(maxDYi<DXDYMaxDisp){
		    YalignReached=true;
		    if(CalculateErrorAsHIP)
		      for(unsigned int m=0; m<10;m++)
			{
			  TotDYDispErr.at(m)=CalculateAlignHIP(roadYfit,2,thehalf,m);
			}
		 }


		  /*
		     if(maxDYi<DXDYMaxDisp)
		       {
			 
			 
			 if(fabs(refPositDY)<DXDYMaxDisp)
			   {
			     YalignReached=true;
			     //Last Iteration... calculate the error on DYi.
			    
			     // oppure guarda differenza di due iterazioni successive.
			   }
			 else//if added on 3feb. To return as before: erase the if statement and all the associated else block
			   {
			     for(unsigned int k=0; k<TotDYDisp.size();k++)
			       {
				 if(k!=refposy)
				   TotDYDisp.at(k)=TotDYDisp.at(k)-refPositDY;
			       }
			     for(unsigned int k=0; k<roadYfit.size();k++)
			       for (unsigned int g=0;g<roadYfit[k].size();g++)
				 {
				   unsigned int symbolic2=RawtoSymb(roadYfit[k].at(g).GetHitDetRawId());
				   symbolic2= symbolic2%10;
				   if(symbolic2!=refposy)
				     roadYfit[k].at(g).SetHitY(roadYfit[k].at(g).GetHitY()+refPositDY);
				 }
			   }
			 
			 if(CalculateErrorAsHIP)
			   for(unsigned int m=0; m<10;m++)
			     {
			       TotDYDispErr.at(m)=CalculateAlignHIP(roadYfit,2,thehalf,m);
			     }

		       }
		     */
		 


		 Yalignstep++;
	       }

	     std::cout<<"Now I'm here"<<std::endl;
	     std::vector<std::vector<double> > Histo_DXAndDYErrorVect;
	     
	     if(UseHistogramsForInternalError)
	       {
		 Histo_DXAndDYErrorVect=MakeErrorHistograms(&roadXfit,&roadYfit,thehalf);
		 TotDXDispErr.clear();
		 TotDXDispErr=Histo_DXAndDYErrorVect.at(0);
		 TotDYDispErr.clear();
		 TotDYDispErr=Histo_DXAndDYErrorVect.at(1);
		for(unsigned int m=0; m<10;m++)
		  {
		    if(m==refposx)
		      {
			TotDXDispErr.at(m)=0.;
			TotDYDispErr.at(m)=0.;
		      }
		  }
	       }

	     std::cout<<"FINAL internal alignment results for Half "<<thehalf<<" :"<<std::endl;

	     for(unsigned int m=0; m<10;m++)
	       {
		 std::cout<<"Half "<<thehalf<<" TotDXDisp.at("<<m<<")= "<<TotDXDisp.at(m)<<" +- "<<TotDXDispErr.at(m) <<std::endl;
	       }
	     
	     std::cout<<"---"<<std::endl;
	     
	     for(unsigned int m=0; m<10;m++)
	       {
		 std::cout<<"Half "<<thehalf<<" TotDYDisp.at("<<m<<")= "<<TotDYDisp.at(m)<<" +- "<<TotDYDispErr.at(m) <<std::endl;
	       }

	     
	     
	     std::cout<<"Writing the internal Alignment Results in a file for half... "<<thehalf<<std::endl;
	     

	     for(unsigned int m=0; m<10;m++)
	       {
		 file_op<<"DetId: "<<m+(thehalf*10)<<"   DX: "<<TotDXDisp.at(m)<<"   DY: "<<TotDYDisp.at(m)<<"   EDX: "<<TotDXDispErr.at(m)<<"   EDY: "<<TotDYDispErr.at(m)<<" \n";	  
	       }

	     //file_op<<"SimuEDX: "<<SimuErrDX->GetMean()<<"     SimuEDY: "<<SimuErrDY->GetMean()<<" \n";
	     file_op<<"NumTrkX: "<<roadXfit.size()<<"     NumTrkY: "<<roadYfit.size()<<" \n";
	     // Saving internal half  disalignment
	     if((YalignReached)&&(XalignReached))
	       {
		 if(thehalf==0)
		   {
		     TotDXDispErrh0=TotDXDispErr;
		     TotDYDispErrh0=TotDYDispErr;

		     TotDXDisph0=TotDXDisp;
		     TotDYDisph0=TotDYDisp;

		   }

		 if(thehalf==1)
		   {
		     TotDXDispErrh1=TotDXDispErr;
		     TotDYDispErrh1=TotDYDispErr;

		     TotDXDisph1=TotDXDisp;
		     TotDYDisph1=TotDYDisp;
		   }

		 if(thehalf==2)
		   {
		     TotDXDispErrh2=TotDXDispErr;
		     TotDYDispErrh2=TotDYDispErr;

		     TotDXDisph2=TotDXDisp;
		     TotDYDisph2=TotDYDisp;
		   }

		 if(thehalf==3)
		   {
		     TotDXDispErrh3=TotDXDispErr;
		     TotDYDispErrh3=TotDYDispErr;

		     TotDXDisph3=TotDXDisp;
		     TotDYDisph3=TotDYDisp;
		   }
	       }
	     std::cout<<"Internal alignment results for half "<<thehalf<<" written"<<std::endl;
	     
	     //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	     // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	     //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	     //CONSTRUCTION OF HISTOGRAMS which show misalignment of a selected half

	     //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	     // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	     //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	     if(thehalf==HalfSelectedForPlot)	     
	       {

		 for(unsigned int k=0; k<roadXfit.size();k++)
		   {
		     if(roadXfit.size()==origroadXfit.size())
		       {
			 for(unsigned int j=0; j<roadXfit.at(k).size();j++)
			   {

			     if(roadXfit.at(k).at(j).GetHitDetRawId()==origroadXfit.at(k).at(j).GetHitDetRawId())
			       {
				 unsigned int symbolic=RawtoSymb(roadXfit.at(k).at(j).GetHitDetRawId());		      
				 double diffX=roadXfit.at(k).at(j).GetHitX()-origroadXfit.at(k).at(j).GetHitX();		      
				 DetIdvsXShOnlyXfit->Fill(symbolic,diffX);

			       }
			   }
		       }
		   }


		 for(unsigned int k=0; k<roadYfit.size();k++)
		   {
		     if(roadYfit.size()==origroadYfit.size())
		       {
			 for(unsigned int j=0; j<roadYfit.at(k).size();j++)
			   {

			     if(roadYfit.at(k).at(j).GetHitDetRawId()==origroadYfit.at(k).at(j).GetHitDetRawId())
			       {

				 unsigned int symbolic=RawtoSymb(roadYfit.at(k).at(j).GetHitDetRawId());
				 double diffY=roadYfit.at(k).at(j).GetHitY()-origroadYfit.at(k).at(j).GetHitY();		      
				 DetIdvsYShOnlyYfit->Fill(symbolic,diffY);
			       }
			   }
		       }
		   }


		 //START Quality Plot after alignment
		 for(unsigned int k=0; k<origroadXfit.size();k++)
		   {
		     ProbXHisto->Fill(chi2X(origroadXfit.at(k),UseJointProb).at(0));
		     TrkChi2X->Fill(chi2X(origroadXfit.at(k),UseJointProb).at(1));
		     TrkChi2XNdf->Fill(chi2X(origroadXfit.at(k),UseJointProb).at(2));
		     TrkChi2RNdf->Fill(chi2R(origroadXfit.at(k),UseJointProb).at(2));

		   }

		 for(unsigned int k=0; k<origroadYfit.size();k++)
		   {
		     ProbYHisto->Fill(chi2Y(origroadYfit.at(k),UseJointProb).at(0));
		     TrkChi2Y->Fill(chi2Y(origroadYfit.at(k),UseJointProb).at(1));
		     TrkChi2YNdf->Fill(chi2Y(origroadYfit.at(k),UseJointProb).at(2));
		     TrkChi2RNdf->Fill(chi2R(origroadYfit.at(k),UseJointProb).at(2));
		   }

		 for(unsigned int k=0; k<roadXfit.size();k++)
		   {
		     ProbXHistoAl->Fill(chi2X(roadXfit.at(k),UseJointProb).at(0));
		     TrkChi2XAl->Fill(chi2X(roadXfit.at(k),UseJointProb).at(1));
		     TrkChi2XNdfAl->Fill(chi2X(roadXfit.at(k),UseJointProb).at(2));
		     TrkChi2RNdfAl->Fill(chi2R(roadXfit.at(k),UseJointProb).at(2));
		   }
		   
		   for(unsigned int k=0; k<roadYfit.size();k++)
		   {
		     ProbYHistoAl->Fill(chi2Y(roadYfit.at(k),UseJointProb).at(0));
		     TrkChi2YAl->Fill(chi2Y(roadYfit.at(k),UseJointProb).at(1));
		     TrkChi2YNdfAl->Fill(chi2Y(roadYfit.at(k),UseJointProb).at(2));
		     TrkChi2RNdfAl->Fill(chi2R(roadYfit.at(k),UseJointProb).at(2));
		   }
		 
		 
		 //Fill R Resolution Plot (2)

		 //????????
		   /*
		 if(roadYfit.size()!=roadXfit.size())
		   {		     
		     std::cout<<"WHY THIS"<<roadYfit.size()<<" "<<roadXfit.size()<<std::endl;
		     //correct the hit with misalignment
		     T2GeometryUtil conv;
		     T2GeometryUtil::T2DetInfo planeinfo;
		     unsigned int symb;
		     for(unsigned int i=0;i<CommonTrackforPlot.size();i++)
		       {
			 std::vector<T2Hit> theroad=CommonTrackforPlot.at(i);
			 for(unsigned int j=0;j<theroad.size();j++) 
			   {
			     planeinfo=conv.GetT2Info(theroad.at(j).GetHitDetRawId());
			     symb=planeinfo.symb%10;
			     theroad.at(j).SetHitX(theroad.at(j).GetHitX()-TotDXDisp.at(symb));
			     theroad.at(j).SetHitY(theroad.at(j).GetHitY()-TotDYDisp.at(symb));	
			     theroad.at(j).SetHitR(sqrt(theroad.at(j).GetHitY()*theroad.at(j).GetHitY()+theroad.at(j).GetHitX()*theroad.at(j).GetHitX()));
			   }
			 CommonTrackforPlot.at(i)=theroad;
		       }
		     //roadXfit=CommonTrackforPlot;
		     //roadYfit=CommonTrackforPlot;		    
		   }
		   */
		 //????????  

		 //bef. 13 nov there was only this if (does not work for different cuts) and not ????????
		 //if(roadYfit.size()==roadXfit.size()) 
		   for(unsigned int k=0; k<CommonTrackforPlot.size();k++)
		     {

		       std::vector<T2Hit> refhitv;
		       //for(unsigned int j=0;j<CommonTrackforPlot.at(k).size();j++)
			 //	 {
			   //T2Hit thehit = CommonTrackforPlot.at(k).at(j);
			   //thehit.SetHitX(roadXfit.at(k).at(j).GetHitX());
			   // refhitv.push_back(thehit);
			   //}

		       //  std::vector<double> drphi4Alignment;

		       refhitv=CommonTrackforPlot.at(k);

		       TMatrixD covmatr(4,4);
		       covmatr.Zero();
		       double chi2corre;	      
		       std::vector<double> correFit=MyLinearfitCorr(refhitv,covmatr,chi2corre);
		       //std::vector<double> correFit=RPhiFit(std::vector<T2Hit> hitvec)
		       //
		       std::vector<double> support2;

		       for(unsigned int c=0;c<2;c++)
			 {
			   support2.push_back(correFit[c]);
			 }

		       for(unsigned int c=0;c<2;c++)
			 {
			   support2.push_back(correFit[2+c]);
			 }

		       for (unsigned int c=0;c<2;c++)
			 {
			   support2.push_back(covmatr(c,c));
			 }


		       for (unsigned int c=0;c<2;c++)
			 {
			   support2.push_back(covmatr(2+c,2+c));
			 }
		       support2.push_back(covmatr(0,1));
		       support2.push_back(covmatr(2,3));

		       std::vector<double> paramvectForAlign;
		       paramvectForAlign=support2;
		       
		       if(refhitv.size()>=(HitNumb4Align-1))
			 for (unsigned int u=0;u<refhitv.size();u++)
			   {
			     //     drphi4Alignment=ResiduiRPhi(paramvectForAlign,refhitv.at(u).GetHitX(), refhitv.at(u).GetHitY(),refhitv.at(u).GetHitZ());
			     unsigned int  symb=refhitv.at(u).GetHitPlane()*2+refhitv.at(u).GetHitPlaneSide();
			     // if(refhitv.at(u).GetHitNumStrip()<=4)
			     //  if(refhitv.at(u).GetHitNumPad()<=3)
			     //	 {
				   if(refhitv.at(u).GetHitR()<AlignmentHitRMax)
			            if(refhitv.at(u).GetHitR()>AlignmentHitRMin)
				     {
				       // DXAlignDet[symb]->Fill(drphi4Alignment.at(0));
				       //DYAlignDet[symb]->Fill(drphi4Alignment.at(1));
				       // HitXErr->Fill(sqrt(sigmax));
				       // HitYErr->Fill(sqrt(sigmay)); 
				       HitX->Fill(refhitv.at(u).GetHitX());
				       HitY->Fill(refhitv.at(u).GetHitY());  
				       //CumulativeRResol->Fill(expR-mesuredR2);
				       //CumulativePhiResol->Fill(expPhi-measuredphi2);
				       //CumulativeExpXUncert->Fill(errorx);
				       //CumulativeExpYUncert->Fill(errory);

				       //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				       //Part very important for the results...
				       //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

				       TMatrixD covmatr3(4,4);
				       std::vector<T2Hit> hitvForResidual=GiveMeTheHitForResidual(refhitv.at(u).GetHitDetRawId(),refhitv);
				       std::vector<double> correFit3=MyLinearfitCorr(hitvForResidual,covmatr3,chi2corre);
				       
				       std::vector<double> support3;
				       for(unsigned int c=0;c<2;c++)
					 {
					   support3.push_back(correFit3[c]);
					 }
				       for(unsigned int c=0;c<2;c++)
					 {
					   support3.push_back(correFit3[2+c]);
					 }
				       for (unsigned int c=0;c<2;c++)
					 {
					   support3.push_back(covmatr3(c,c));
					 }
				       for (unsigned int c=0;c<2;c++)
					 {
					   support3.push_back(covmatr3(2+c,2+c));
					 }
				       support3.push_back(covmatr3(0,1));
				       support3.push_back(covmatr3(2,3));
				       
				       double expY_2=(support3[2]*refhitv.at(u).GetHitZ()+support3[3]);  
				       double expX_2=(support3[0]*refhitv.at(u).GetHitZ()+support3[1]);
				       double expR_2= sqrt(expX_2*expX_2+expY_2*expY_2);
				       double expPhi_2=atan(fabs(expY_2)/fabs(expX_2));
				       expPhi_2=expPhi_2*180.0/3.14159;				    
				       if((expY_2<0)&&(expX_2>0))
					 expPhi_2=360.0-expPhi_2;

				       if((expY_2>0)&&(expX_2<0))
					 expPhi_2=expPhi_2+90.;

				       if((expY_2<0)&&(expX_2<0))
					 expPhi_2=expPhi_2+180.;

				       if((fabs(refhitv.at(u).GetHitX())/fabs(refhitv.at(u).GetHitR()))>0.7)
					 DXResol[symb]->Fill(expX_2-refhitv.at(u).GetHitX());
  
				       if((fabs(refhitv.at(u).GetHitY())/fabs(refhitv.at(u).GetHitR()))>0.7)
					 DYResol[symb]->Fill(expY_2-refhitv.at(u).GetHitY());
  

				       DRResol[symb]->Fill(expR_2-refhitv.at(u).GetHitR());  
				       DPhiResol[symb]->Fill(expPhi_2-refhitv.at(u).GetHitPhi());

				     }
				   //}
			   }//end for on refhitVect

		     }//end for on roadY size
		  std::cout<<"Histogrmas for selected half done"<<std::endl;
	       }//end if thehalf==SelectedHalf
	     
	      
	     std::cout<<"Internal Done"<<std::endl;


	    

	    } //end loop on 4 halfs

	  //save tilt alignment results in a file
	  //std::map<unsigned int,std::vector<long double> >::iterator it;
	  
	  //DA_CAMBIARE

	  
	} //if (DoAlign==true)

      //**********************************************************
      //*****************Part for Quarter Tilt Alignment**********
      //**********************************************************
      std::cout<<"Internal alignment end"<<std::endl;
      
      for (unsigned int half=0;half<SelectedHalfs.size();half++)
	{
	  unsigned int thehalf=SelectedHalfs.at(half);
	  std::vector<double> TotDXDispInternal;
	  std::vector<double> TotDYDispInternal;
	  for(unsigned int i=0;i<10;i++)
	    {
	      TotDXDispInternal.push_back(0.);
	      TotDYDispInternal.push_back(0.);
	    }

	  if(DoInternalAlign)
	    {
	      if(thehalf==0)
		{		  
		  TotDXDispInternal=TotDXDisph0;
		  TotDYDispInternal=TotDYDisph0;
		}

	       if(thehalf==1)
		{		  
		  TotDXDispInternal=TotDXDisph1;
		  TotDYDispInternal=TotDYDisph1;
		}

	       if(thehalf==2)
		{		  
		  TotDXDispInternal=TotDXDisph2;
		  TotDYDispInternal=TotDYDisph2;
		}

	       if(thehalf==3)
		{		  
		  TotDXDispInternal=TotDXDisph3;
		  TotDYDispInternal=TotDYDisph3;
		}
	    }




	  if(IncludeQuarterTiltAlign)
	    {
	      bool candoalign=false;
	      
	      for(unsigned int hh=0;hh<SelectedHalfsForTiltAlign.size();hh++)
		if(SelectedHalfsForTiltAlign.at(hh)==thehalf)
		  candoalign=true;
	      
	      if(candoalign)
		{
		  std::cout<<"Starting alignment of Quarter "<<thehalf<<" Tilt - Shift respect to the Vertex"<<std::endl;
	
		  if(DoInternalAlign)
		    qtiltobj->CorrectForIntAlign(thehalf,TotDXDispInternal, TotDYDispInternal);

		  std::vector<long double> qAlReslt=qtiltobj->FindQuarterShiftTilt(thehalf);
		  //(AX,X0,AY,Y0)
		  QuartvsGlobAlignParamMAP.insert(std::pair<unsigned int,std::vector<long double> >(thehalf,qAlReslt));
		  // bool issaved=qtiltobj->StoreEventtTrks(&roadYfit,&roadXfit);
		  //if(issaved)
		  // std::cout<<"Ev "<<numevent<<" saved for tilt align"<<std::endl;
		  std::vector<long double> qAlReslt2=qtiltobj->FindQuarterShiftTiltSimple(thehalf);
		  QuartvsGlobAlignParamMAPBIS.insert(std::pair<unsigned int,std::vector<long double> >(thehalf,qAlReslt2));	  
		}
	      qtiltobj->SaveTiltsinFile(QuartvsGlobAlignParamMAP,&file_op);
	      qtiltobj->SaveTiltsinFile(QuartvsGlobAlignParamMAPBIS,&file_opS);
	    }
	  
	  if(UseMillePedeGlobal)
	    {
	      std::cout<<"Starting alignment of Quarter "<<thehalf<<" Tilt - Shift respect to the Vertex with Millepede "<<std::endl;
	      if(DoInternalAlign)
		millepedeGlobobj->CorrectForIntAlign(thehalf,TotDXDispInternal, TotDYDispInternal);
	      std::vector<double> GlobResults=  millepedeGlobobj->CallMilleTiltShift(thehalf);
	      millepedeGlobobj->SaveMisalinFile(thehalf,GlobResults,&file_opMille);
	    }
	  
	}
      
      
      file_op.close(); 
      file_opMille.close(); 
      file_opS.close();
    }// if numevent==maxevent
  

 
  

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //Caluclate now the misalignment between halves
  //*****************************************************************************
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  if(numevent==MaxEvents){
  double zz=0.;double ypr0=0.; double ypr1=0.;double sl0=0.;double sl1=0.;
      double matchn=0.;
      double y0avg=0.;
      double sl0avg=0.;
         double matchn2=0.;
      double y0avg2=0.;
      double sl0avg2=0.;
      //      std::cout<<"Studies of the QQ align. Matching trk pairs:"<<PairsOfOvTrkArm0.size()<<std::endl;
      for(unsigned int u=0;u<PairsOfOvTrkArm0.size();u++){
	std::pair <T1T2Track,T1T2Track> h0h1=PairsOfOvTrkArm0.at(u); 
	zz=h0h1.first.GetHitT2(0).GetHitZ();
	//	double ysign=h0h1.first.GetHitT2(0).GetHitY()/fabs(h0h1.first.GetHitT2(0).GetHitY());
	
	  if(h0h1.first.GetHitT2(0).GetHitR()>80)
	    if(zz<13870){
	      ypr0=h0h1.first.GetTy()*zz+h0h1.first.Y0();
	      ypr1=h0h1.second.GetTy()*zz+h0h1.second.Y0();
	      sl0=h0h1.first.GetTy();
	      sl1=h0h1.second.GetTy();
	      //std::cout<<"T01"<<" "<<sl0<<" "<<sl1<<" "<<(sl1-sl0)<<std::endl;
	      
	      matchn=matchn+1.0;
	      y0avg=y0avg+(ypr1-ypr0);
	      sl0avg=sl0avg+(sl1-sl0);
	      
	      matchn2=matchn2+1.0;
	      y0avg2=y0avg2+(ypr1-ypr0);
	      sl0avg2=sl0avg2+(sl1-sl0);

	      
	    }


      }
      y0avg=y0avg/matchn;
      sl0avg=sl0avg/matchn;
     

      std::cout<<"Opening file for store Overlap misalignment results"<<std::endl;
      std::string namefiledisov=outputFileName;
      std::string sought = ".root";
      int pos=namefiledisov.find(sought); 
      namefiledisov.replace(pos, sought.size(), "_HHOverlapCorr.dat"); 
      
      std::string namefiledis2ov=namefiledisov;
      fstream file_opFNov(namefiledis2ov.c_str(),ios::out);
      
 
      file_opFNov<<"OverlapQQ: 0"<<"   TiltY: "<<sl0avg<<"   Y0: "<<y0avg<<" \n";	  
      file_opFNov.close();

  }



  if((numevent==MaxEvents)&&(DoAlignHalfHalf))
    {

      	std::cout<<"Begin Procedures for misalignment between halves"<<std::endl;
      //Define the reference halfs.
      if(RefHalfsWholeQuarterAlign.size()==0)
	{
	  std::cout<<"You need at least 1 reference quarter per arm for relative alignment. Cannot complete alignment operation!"<<std::endl;
	}
      else
	{
	  for(unsigned int halftoAl=0;halftoAl<4;halftoAl++)
	    {
	    if(std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),halftoAl)==RefHalfsWholeQuarterAlign.end())	 
	      {
		unsigned int refhalf =5;
		//you can align this quarter respect to the other (refhalf)
		//look if the other quarter in the same are in the list of the reference
		if(halftoAl==0)
		  {
		    if(std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),1)==RefHalfsWholeQuarterAlign.end())
		      {
			std::cout<<"There is no half reference for alignment of arm 0. Half 0 not aligned respect 1"<<std::endl;
			continue;
		      }
		    else
		      {
			refhalf=1;
			std::cout<<"Half 0 will be aligned respect to Half 1"<<std::endl;
		      }
		  }

		if(halftoAl==1)
		  {
		    if(std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),0)==RefHalfsWholeQuarterAlign.end())
		      {
			std::cout<<"There is no half reference for alignment of arm 0. Half 1 not aligned respect 0"<<std::endl;
			continue;
		      }
		    else
		      {
			refhalf=0;
			std::cout<<"Half 1 will be aligned respect to Half 0"<<std::endl;
		      }
		  }

		if(halftoAl==2)
		  {
		    if(std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),3)==RefHalfsWholeQuarterAlign.end())
		      {
			std::cout<<"There is no half reference for alignment of arm 1"<<std::endl;
			continue;
		      }
		    else
		      {
			refhalf=3;
			std::cout<<"Half 2 will be aligned respect to Half 3"<<std::endl;
		      }
		  }
		
		if(halftoAl==3)
		  {
		    if(std::find(RefHalfsWholeQuarterAlign.begin(),RefHalfsWholeQuarterAlign.end(),2)==RefHalfsWholeQuarterAlign.end())
		      {
			std::cout<<"There is no half reference for alignment of arm 1"<<std::endl;
			continue;
		      }
		    else
		      {
			refhalf=2;
			std::cout<<"Half 3 will be aligned respect to Half 2"<<std::endl;		    
		      }
		  }

		if(refhalf==(5))
		  {
		    std::cout<<"Error in the half number!!"<<std::endl;
		    //continue;
		  }

		//take common track from Roads already loaded
		if((halftoAl/2)==0)
		  {
		    //correct with the internal alignment previously found
		    //for(unsigned int ne=0;ne<roadfitOverlapARM0.size();ne++)
		    //	  std::cout<<(roadfitOverlapARM0.at(ne)).size()<<" !! ";
		    std::cout<<"Correction half-half in arm 0..."<<std::endl;
		    
		    CorrectRoadHitsInOverlap(&roadfitOverlapARM0,TotDXDisph0,TotDYDisph0,TotDXDisph1,TotDYDisph1);
		    		    
		    if(halftoAl==0)
		      {
			//implement iterative method for common alignment between half
			std::cout<<"... start computation for half  0"<<std::endl;
			//for(unsigned int ne=0;ne<roadfitOverlapARM0.size();ne++)
			//	  std::cout<<(roadfitOverlapARM0.at(ne)).size()<<" !! ";

			MakeQuarterQuarterMisalHisto(&roadfitOverlapARM0,halftoAl);
			CalculateRelativeHalfAlign(&TotDXDispARM0,&TotDYDispARM0,&TotDXDispARM0Err,&TotDYDispARM0Err,&roadfitOverlapARM0,halftoAl);

			
			//Recompute the halfs displacement vector
			RecomputeHalfDispl(TotDXDispARM0,TotDYDispARM0,TotDXDispARM0Err,TotDYDispARM0Err,&TotDXDisph0,&TotDYDisph0,&TotDXDispErrh0,&TotDYDispErrh0);
		      }

		    if(halftoAl==1)
		      {
			std::cout<<"... start computation for half  1"<<std::endl;
			//for(unsigned int ne=0;ne<roadfitOverlapARM0.size();ne++)
			//  std::cout<<(roadfitOverlapARM0.at(ne)).size()<<" !! ";
			MakeQuarterQuarterMisalHisto(&roadfitOverlapARM0,halftoAl);
			//implement iterative method for common alignment between half
			CalculateRelativeHalfAlign(&TotDXDispARM0,&TotDYDispARM0,&TotDXDispARM0Err,&TotDYDispARM0Err,&roadfitOverlapARM0,halftoAl);

			
			//Recompute the halfs displacement vector
			RecomputeHalfDispl(TotDXDispARM0,TotDYDispARM0,TotDXDispARM0Err,TotDYDispARM0Err,&TotDXDisph1,&TotDYDisph1,&TotDXDispErrh1,&TotDYDispErrh1);
		      }
		  }

  
		if((halftoAl/2)==1)
		  {
		    //correct with the internal alignment previously found
		    std::cout<<"Correction half-half in arm 1"<<std::endl;

		    CorrectRoadHitsInOverlap(&roadfitOverlapARM1,TotDXDisph2,TotDYDisph2,TotDXDisph3,TotDYDisph3);
		    
		     if(halftoAl==2)
		       {
			 std::cout<<"... start computation for half  2"<<std::endl;
			 //implement iterative method for common alignment between half
			 CalculateRelativeHalfAlign(&TotDXDispARM1,&TotDYDispARM1,&TotDXDispARM1Err,&TotDYDispARM1Err,&roadfitOverlapARM1,halftoAl);
			 MakeQuarterQuarterMisalHisto(&roadfitOverlapARM1,halftoAl);
			 //Recompute the halfs displacement vector
			 RecomputeHalfDispl(TotDXDispARM1,TotDYDispARM1,TotDXDispARM1Err,TotDYDispARM1Err,&TotDXDisph2,&TotDYDisph2,&TotDXDispErrh2,&TotDYDispErrh2);
		       }
		    if(halftoAl==3)
		      {
			std::cout<<"... start computation for half  3"<<std::endl;
			 //implement iterative method for common alignment between half
			 CalculateRelativeHalfAlign(&TotDXDispARM1,&TotDYDispARM1,&TotDXDispARM1Err,&TotDYDispARM1Err,&roadfitOverlapARM1,halftoAl);
			 MakeQuarterQuarterMisalHisto(&roadfitOverlapARM1,halftoAl);
			 //Recompute the halfs displacement vector
			 RecomputeHalfDispl(TotDXDispARM1,TotDYDispARM1,TotDXDispARM1Err,TotDYDispARM1Err,&TotDXDisph3,&TotDYDisph3,&TotDXDispErrh3,&TotDYDispErrh3);
		      }
		  }
		
	      }
	  }
	}

      std::cout<<"Here8"<<std::endl;
      
      




            
      //save the results of internal + half-half misal. in a unique file.
      std::cout<<"Opening file for store internal alignment with also half-half correction"<<std::endl;
      std::string namefiledis=outputFileName;
      std::string sought22 = ".root";
      int pos22=namefiledis.find(sought22); 
      namefiledis.replace(pos22, sought22.size(), "_HHCorr.dat"); 
     // std::string befores="MisalOut/InternalARMAlign_";
      //std::string namefiledis2=befores+namefiledis;	
      std::string namefiledis2=namefiledis;
      fstream file_opFN(namefiledis2.c_str(),ios::out);

      std::cout<<"Writing the internal Alignment Results in a file for half 0"<<std::endl;
      for(unsigned int m=0; m<TotDXDisph0.size(); m++)
	{
	  file_opFN<<"DetId: "<<m<<"   DX: "<<TotDXDisph0.at(m)<<"   DY: "<<TotDYDisph0.at(m)<<"   EDX: "<<TotDXDispErrh0.at(m)<<"   EDY: "<<TotDYDispErrh0.at(m)<<" \n";	  
	}

      std::cout<<"Writing the internal Alignment Results in a file for half 1"<<std::endl;
      for(unsigned int m=0; m<TotDXDisph1.size(); m++)
	{
	  file_opFN<<"DetId: "<<m+10<<"   DX: "<<TotDXDisph1.at(m)<<"   DY: "<<TotDYDisph1.at(m)<<"   EDX: "<<TotDXDispErrh1.at(m)<<"   EDY: "<<TotDYDispErrh1.at(m)<<" \n";	  
	}
      std::cout<<"Writing the internal Alignment Results in a file for half 2"<<std::endl;
      for(unsigned int m=0; m<TotDXDisph2.size(); m++)
	{
	  file_opFN<<"DetId: "<<m+20<<"   DX: "<<TotDXDisph2.at(m)<<"   DY: "<<TotDYDisph2.at(m)<<"   EDX: "<<TotDXDispErrh2.at(m)<<"   EDY: "<<TotDYDispErrh2.at(m)<<" \n";	  
	}

      std::cout<<"Writing the internal Alignment Results in a file for half 3"<<std::endl;
      for(unsigned int m=0; m<TotDXDisph3.size(); m++)
	{
	  file_opFN<<"DetId: "<<m+30<<"   DX: "<<TotDXDisph3.at(m)<<"   DY: "<<TotDYDisph3.at(m)<<"   EDX: "<<TotDXDispErrh3.at(m)<<"   EDY: "<<TotDYDispErrh3.at(m)<<" \n";	  
	}

      file_opFN.close();

    }







  //double chiRProb=0.;
  //double chiRred=0.;
  //double chiPhiProb=0.;
  //bool chi2condition;
  // double chiPhiRed=0.;

  // double trkphi=0.;
  // double trketa=0.;
	    


 
  //std::cout<<"fnal-3"<<std::endl;
   
  //}//if trkcountergood==1

  //std::cout<<"-------------------------analyze end--"<<std::endl;

} 

//--------------------------------------------------------------------------------------------------------------------------------------
// ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******
//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
// ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******  ANLYZER END ******
//--------------------------------------------------------------------------------------------------------------------------------------







// ------------ method called once each job just before starting event loop  ------------
void T2TrkBasedInternalAlignment::beginJob()
{

  std::cout<<"+++++++++"<<std::endl;
  std::cout<<"Begin Job"<<std::endl;
  TH1::AddDirectory(kFALSE);
  //std::vector<double> alldetZ;
  meanz=0;
  numevent=0;
  matrixentries=0;
  trkcounter=0;
  matrixentries0=0;
  matrixentries1=0;
  matrixentries2=0;
  matrixentries3=0;
  matrixentries_Overl_Arm0=0;
  matrixentries_Overl_Arm1=0;
  PairsOfOvTrkArm0.clear();
  double et1=4.8,et2=7.0;
  int m1=6,m2=10;//m1 was 5
  double dzmul=2.0;
  double p1=0.05,p2=0.05;//was 0.01
  if(IncludeQuarterTiltAlign)
    {
      // std::cout<<"Try1"<<std::endl;
      // QuarterTilt qtiltobj2(et1,et2,m1,m2,dzmul,p1,p2,SelectedHalfsForTiltAlign,XYFitUsedinReco,AXToll,X0Toll,AYToll,Y0Toll);
      //std::cout<<"Try2"<<std::endl;
      //(*qtiltobj)=qtiltobj2;

      qtiltobj=new QuarterTilt(et1,et2,m1,m2,dzmul,p1,p2,SelectedHalfsForTiltAlign,XYFitUsedinReco,AXToll,X0Toll,AYToll,Y0Toll);
      std::cout<<"Try3"<<std::endl;
    }
  

  if(UseMillePede)
    {   
     
       
      millepedeobj=new MillePede(et1,et2,m1,m2,dzmul,p1,p2,SelectedHalfs,XYFitUsedinReco,AXToll,X0Toll,AYToll,Y0Toll,Idreferencedet,IdreferencedetMille,XreferencedetMille,YreferencedetMille,MillePedeExcludedPlaneH0,MillePedeExcludedPlaneH1,MillePedeExcludedPlaneH2,MillePedeExcludedPlaneH3);
      //std::cout<<"Try3"<<std::endl;
    }

  if(UseMillePedeGlobal)
    {  
      millepedeGlobobj=new MillePedeGlobal(et1,et2,m1,m2,dzmul,p1,p2,SelectedHalfs,XYFitUsedinReco,AXToll,X0Toll,AYToll,Y0Toll,Idreferencedet,IdreferencedetMille,XreferencedetMille,YreferencedetMille);
    }
  //bool StoreEventtTrks(T1T2TrackCollection t2_trackCollection);

SimuErrDX= std::auto_ptr<TH1F>(new TH1F("SimuErrDX","SimuErrDX",300, 0., 3.));
SimuErrDY= std::auto_ptr<TH1F>(new TH1F("SimuErrDY","SimuErrDY",300, 0., 3.));


AllHitR= std::auto_ptr<TH1F>(new TH1F("AllHitR","AllHitR",120, 30., 150.));
AllHitR->SetDirectory(0); 

chiRredREF = std::auto_ptr<TH1F>(new TH1F("chiRredREF","Chi2ridotto riferimento",100, 0., 50.));
chiRredREF->SetDirectory(0); 
H1NumHit= std::auto_ptr<TH1F>(new TH1F("H1NumHit","H1NumHit",11,-0.5,10.5));
H1NumHit->SetDirectory(0); 

H0NumHit= std::auto_ptr<TH1F>(new TH1F("H0NumHit","H0NumHit",11,-0.5,10.5));
H0NumHit->SetDirectory(0); 

Trketa= std::auto_ptr<TH1F>(new TH1F("Trketa","Reconstructed Track #eta (no cut used)",300,-8.,8.0));
Trketa->SetDirectory(0); 
Trkphi= std::auto_ptr<TH1F>(new TH1F("Trkphi","Reconstructed Track #phi (no cut used)",361,0,360));
Trkphi->SetDirectory(0); 

 NumClass1Hits= std::auto_ptr<TH1F>(new TH1F("NumClass1Hits","NumClass1Hits per track",11,-0.5,10.5));
NumClass1HitsH0= std::auto_ptr<TH1F>(new TH1F("NumClass1HitsH0","NumClass1Hits per track",11,-0.5,10.5));
NumClass1HitsH1= std::auto_ptr<TH1F>(new TH1F("NumClass1HitsH1","NumClass1Hits per track",11,-0.5,10.5));
NumClass1HitsH3= std::auto_ptr<TH1F>(new TH1F("NumClass1HitsH3","NumClass1Hits per track",11,-0.5,10.5));

CumulativeRawTrketa= std::auto_ptr<TH1F>(new TH1F("CumulativeRawTrketa","Reconstructed Track #eta (no cut used)",300,-8.0,8.0));
CumulativeRawTrketa->SetDirectory(0); 
CumulativeRawTrkphi= std::auto_ptr<TH1F>(new TH1F("CumulativeRawTrkphi","Reconstructed Track # (no cut used)",361,-0.5,359.5));
CumulativeRawTrkphi->SetDirectory(0); 

Trketagood= std::auto_ptr<TH1F>(new TH1F("Trketagood","Reconstructed Track #eta (#chi^{2}_{p} cut)",300,-8.0,8.0));
Trketagood->SetDirectory(0); 
//Trkphigood= std::auto_ptr<TH1F>(new TH1F("Trkphigood","Reconstructed Track #phi (#chi^{2}_{p} cut)",361,0,360));
Trkphigood= std::auto_ptr<TH1F>(new TH1F("Trkphigood","Reconstructed Track #phi",361,0,360));
Trkphigood->SetDirectory(0); 

Chi2RProb = std::auto_ptr<TH1F>(new TH1F("Chi2RProb","Radial #chi^{2} probability",15000,0.0,1.05));
Chi2RProb->SetDirectory(0); 
Chi2PhiProb = std::auto_ptr<TH1F>(new TH1F("Chi2PhiProb","Azimuthal #chi^{2} probability",15000,0.0,1.05));
Chi2PhiProb->SetDirectory(0);

IstoDisp= std::auto_ptr<TH1F>(new TH1F("IstoDisp","Displ.",100,0.0,10.0));
IstoDisp->SetDirectory(0);

AllDetId= std::auto_ptr<TH1F>(new TH1F("AllDetId","AllDetId",10,-0.5,9.5));
AllDetId->SetDirectory(0); 
AllDetIdRAW= std::auto_ptr<TH1F>(new TH1F("AllDetIdRAW","AllDetIdRAW extracted from TRK",41,-0.5,40.5));
 AllDetIdRAW->SetDirectory(0); 
RandomGauss=std::auto_ptr<TH1F>(new TH1F("RandomGauss","RandomGauss",1000,-5000,5000));
RandomGauss->SetDirectory(0);

HitZ=std::auto_ptr<TH1F>(new TH1F("HitZ","HitZ",1000,13500,14500));
HitZ->SetDirectory(0);

Taglio1_TrkSel= std::auto_ptr<TH1F>(new TH1F("Taglio1_TrkSel","Taglio1_TrkSel",11,-0.5,10.5));
Taglio1_TrkSel->SetDirectory(0);
Taglio2_TrkSel= std::auto_ptr<TH1F>(new TH1F("Taglio2_TrkSel","Taglio2_TrkSel",41,-0.5,40.5));
Taglio2_TrkSel->SetDirectory(0);
Taglio3_TrkSel= std::auto_ptr<TH1F>(new TH1F("Taglio3_TrkSel","Taglio3_TrkSel",41,-0.5,40.5));
Taglio3_TrkSel->SetDirectory(0);
Taglio4_TrkSel= std::auto_ptr<TH1F>(new TH1F("Taglio4_TrkSel","Taglio4_TrkSel",41,-0.5,40.5));
Taglio4_TrkSel->SetDirectory(0);
Taglio5_TrkSel= std::auto_ptr<TH1F>(new TH1F("Taglio5_TrkSel","Taglio5_TrkSel",41,-0.5,40.5));
Taglio5_TrkSel->SetDirectory(0);


Chi2phired=std::auto_ptr<TH1F>(new TH1F("Chi2phired","Reduced #chi^{2}-#Phi",200,0.,50.));
Chi2phired->SetDirectory(0);

Chi2red=std::auto_ptr<TH1F>(new TH1F("Chi2red","Reduced #chi^{2}-R",200,0.,50.));
Chi2red->SetDirectory(0);
PlaneUsedInAl=std::auto_ptr<TH1F>(new TH1F("PlaneUsedInAl","PlaneUsedInAl",41,-0.5,40.5));
PlaneUsedInAl->SetDirectory(0);
ActiveSymbDet=std::auto_ptr<TH1F>(new TH1F("ActiveSymbDet","Symb det inside tracks",20,-0.5,19.5));
ActiveSymbDet->SetDirectory(0);
PolarAngles=std::auto_ptr<TH1F>(new TH1F("PolarAngles","Track #theta_{x} angle (rad)",20,-0.25,0.25));
PolarAngles->SetDirectory(0);

NumhitinTrack=std::auto_ptr<TH1F>(new TH1F("NumhitinTrack","# hit in Track",18,-0.5,17.5));
NumhitinTrack->SetDirectory(0);
NumhitinTrackAligned=std::auto_ptr<TH1F>(new TH1F("NumhitinTrackAligned","# hit in Matrix-Track Aligned",18,-0.5,17.5));
NumhitinTrackAligned->SetDirectory(0);

NumhitinTrackGood=std::auto_ptr<TH1F>(new TH1F("NumhitinTrackGood","# hit in Track",12,-0.5,11.5));
NumhitinTrackGood->SetDirectory(0);

AL_DRHitNoCutdet0= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet0"," ",40,-4,4));
AL_DRHitNoCutdet0->SetDirectory(0);

AL_DPhiHitNoCutdet0= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet0"," ",40,-4,4));
AL_DPhiHitNoCutdet0->SetDirectory(0);


AL_DRHitNoCutdet1= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet1"," ",40,-4,4));
AL_DRHitNoCutdet1->SetDirectory(0);



AL_DRHitNoCutdet2= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet2"," ",40,-4,4));
AL_DRHitNoCutdet2->SetDirectory(0);



AL_DRHitNoCutdet3= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet3"," ",40,-4,4));
AL_DRHitNoCutdet3->SetDirectory(0);

AL_DRHitNoCutdet4= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet4"," ",40,-4,4));
AL_DRHitNoCutdet4->SetDirectory(0);

AL_DRHitNoCutdet5= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet5"," ",40,-4,4));
AL_DRHitNoCutdet5->SetDirectory(0);

AL_DRHitNoCutdet6= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet6"," ",40,-4,4));
AL_DRHitNoCutdet6->SetDirectory(0);

AL_DRHitNoCutdet7= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet7"," ",40,-4,4));
AL_DRHitNoCutdet7->SetDirectory(0);

AL_DRHitNoCutdet8= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet8"," ",40,-4,4));
AL_DRHitNoCutdet8->SetDirectory(0);

AL_DRHitNoCutdet9= std::auto_ptr<TH1F>(new TH1F("AL_DRHitNoCutdet9"," ",40,-4,4));
AL_DRHitNoCutdet9->SetDirectory(0);



AL_DPhiHitNoCutdet1= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet1"," ",40,-4,4));
AL_DPhiHitNoCutdet1->SetDirectory(0);

AL_DPhiHitNoCutdet2= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet2"," ",40,-4,4));
AL_DPhiHitNoCutdet2->SetDirectory(0);

AL_DPhiHitNoCutdet3= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet3"," ",40,-4,4));
AL_DPhiHitNoCutdet3->SetDirectory(0);

AL_DPhiHitNoCutdet4= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet4"," ",40,-4,4));
AL_DPhiHitNoCutdet4->SetDirectory(0);

AL_DPhiHitNoCutdet5= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet5"," ",40,-4,4));
AL_DPhiHitNoCutdet5->SetDirectory(0);

AL_DPhiHitNoCutdet6= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet6"," ",40,-4,4));
AL_DPhiHitNoCutdet6->SetDirectory(0);

AL_DPhiHitNoCutdet7= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet7"," ",40,-4,4));
AL_DPhiHitNoCutdet7->SetDirectory(0);

AL_DPhiHitNoCutdet8= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet8"," ",40,-4,4));
AL_DPhiHitNoCutdet8->SetDirectory(0);

AL_DPhiHitNoCutdet9= std::auto_ptr<TH1F>(new TH1F("AL_DPhiHitNoCutdet9"," ",40,-4,4));
AL_DPhiHitNoCutdet9->SetDirectory(0);


PSimHitYD1= std::auto_ptr<TH1F>(new TH1F("PSimHitXD1","PSimHitYD1",300,-150.,150.));
PSimHitYD1->SetDirectory(0);
PSimHitXD1= std::auto_ptr<TH1F>(new TH1F("PSimHitXD1","PSimHitXD1",300,-150.,150.));
PSimHitXD1->SetDirectory(0);
 
Plside0PSimHitXD0= std::auto_ptr<TH1F>(new TH1F(" Plside0PSimHitXD0"," Plside0PSimHitXD0",300,-150.,150.));
Plside0PSimHitXD0->SetDirectory(0);
Plside1PSimHitXD0= std::auto_ptr<TH1F>(new TH1F(" Plside1PSimHitXD0"," Plside1PSimHitXD0",300,-150.,150.));
Plside1PSimHitXD0->SetDirectory(0);
Plside0PSimHitYD0= std::auto_ptr<TH1F>(new TH1F(" Plside0PSimHitYD0"," Plsid00PSimHitYD0",300,-150.,150.));
Plside0PSimHitYD0->SetDirectory(0);
Plside1PSimHitYD0= std::auto_ptr<TH1F>(new TH1F(" Plside1PSimHitYD0"," Plside1PSimHitYD0",300,-150.,150.));
Plside1PSimHitYD0->SetDirectory(0);

DetIdvsXShOnlyXfit= std::auto_ptr<TProfile>(new TProfile("DetIdvsXShOnlyXfit","Det Id vs X Shift (OnlyXfit)",42,-1.5,40.5,""));
DetIdvsXShOnlyXfit->SetDirectory(0);
H0AvgPadCLSHis= std::auto_ptr<TProfile>(new TProfile("H0AvgPadCLSHis","H0AvgPadCLSHis",11,-0.5,10.5,""));
H0AvgStripCLSHis= std::auto_ptr<TProfile>(new TProfile("H0AvgStripCLSHis","H0AvgStripCLSHis",11,-0.5,10.5,""));
DetIdvsYShOnlyYfit= std::auto_ptr<TProfile>(new TProfile("DetIdvsYShOnlyYfit","Det Id vs Y Shift (OnlyYfit)",42,-1.5,40.5,""));
DetIdvsYShOnlyYfit->SetDirectory(0);

ProbYHisto= std::auto_ptr<TH1F>(new TH1F("ProbYHisto","ProbYHisto",200,0.,1.));
ProbYHisto->SetDirectory(0);
ProbXHisto= std::auto_ptr<TH1F>(new TH1F("ProbXHisto","ProbXHisto",200,0.,1.));
ProbXHisto->SetDirectory(0);
ProbXHistoAl= std::auto_ptr<TH1F>(new TH1F("ProbXHistoAl","ProbXHistoAl",200,0.,1.));
ProbXHistoAl->SetDirectory(0);
ProbYHistoAl= std::auto_ptr<TH1F>(new TH1F("ProbYHistoAl","ProbYHistoAl",200,0.,1.));
ProbYHistoAl->SetDirectory(0);

AXHisto= std::auto_ptr<TH1F>(new TH1F("AXHisto","AXHisto",100,-0.1,0.1));
AXHisto->SetDirectory(0);
AYHisto= std::auto_ptr<TH1F>(new TH1F("AYHisto","AYHisto",100,-0.1,0.1));
AYHisto->SetDirectory(0);

AXError= std::auto_ptr<TH1F>(new TH1F("AXError","AXError",100,-0.05,0.05));
AXError->SetDirectory(0);
AYError= std::auto_ptr<TH1F>(new TH1F("AYError","AYError",100,-0.05,0.05));
AYError->SetDirectory(0);
BXError= std::auto_ptr<TH1F>(new TH1F("BXError","BXError",100,-100.,100.));
BXError->SetDirectory(0);
BYError= std::auto_ptr<TH1F>(new TH1F("BYError","BYError",100,-1000.,1000.));
BYError->SetDirectory(0);
 HitYErr= std::auto_ptr<TH1F>(new TH1F("HitYErr","HitYErr",100,-1,1));
HitYErr->SetDirectory(0);
HitXErr= std::auto_ptr<TH1F>(new TH1F("HitXErr","HitXErr",100,-1,1));
HitXErr->SetDirectory(0);

HitX= std::auto_ptr<TH1F>(new TH1F("HitX","HitX",300,-150,150));
HitX->SetDirectory(0);
HitY= std::auto_ptr<TH1F>(new TH1F("HitY","HitY",300,-150,150));
HitY->SetDirectory(0);



TrkChi2RNdfAl= std::auto_ptr<TH1F>(new TH1F("TrkChi2RNdfAl","TrkChi2RNdfAl",60,0.,30.));
TrkChi2RNdfAl->SetDirectory(0);
TrkChi2RNdf= std::auto_ptr<TH1F>(new TH1F("TrkChi2RNdf","TrkChi2RNdf",60,0.,30.));
TrkChi2RNdf->SetDirectory(0);
NumActivePlH0= std::auto_ptr<TH1F>(new TH1F("NumActivePlH0","NumActivePlH0",50,-0.5,49.5));
NumActivePlH1= std::auto_ptr<TH1F>(new TH1F("NumActivePlH1","NumActivePlH1",50,-0.5,49.5));
NumActivePlH2= std::auto_ptr<TH1F>(new TH1F("NumActivePlH2","NumActivePlH2",50,-0.5,49.5));
NumActivePlH3= std::auto_ptr<TH1F>(new TH1F("NumActivePlH3","NumActivePlH3",50,-0.5,49.5));


TrkChi2X= std::auto_ptr<TH1F>(new TH1F("TrkChi2X","TrkChi2X",800,0.,800.));
TrkChi2X->SetDirectory(0);
TrkChi2Y= std::auto_ptr<TH1F>(new TH1F("TrkChi2Y","TrkChi2Y",800,0.,800.));
TrkChi2Y->SetDirectory(0);



TrkChi2XAl= std::auto_ptr<TH1F>(new TH1F("TrkChi2XAl","TrkChi2XAl",800,0.,800.));
TrkChi2XAl->SetDirectory(0);
TrkChi2YAl= std::auto_ptr<TH1F>(new TH1F("TrkChi2YAl","TrkChi2YAl",800,0.,800.));
TrkChi2YAl->SetDirectory(0);


TrkChi2YNdfAl= std::auto_ptr<TH1F>(new TH1F("TrkChi2YNdfAl","TrkChi2YNdfAl",90,0.,30.));
TrkChi2YNdfAl->SetDirectory(0);
TrkChi2XNdfAl= std::auto_ptr<TH1F>(new TH1F("TrkChi2XNdfAl","TrkChi2XNdfAl",90,0.,30.));
TrkChi2XNdfAl->SetDirectory(0);
TrkChi2YNdf= std::auto_ptr<TH1F>(new TH1F("TrkChi2YNdf","TrkChi2YNdf",90,0.,30.));
TrkChi2YNdf->SetDirectory(0);
TrkChi2XNdf= std::auto_ptr<TH1F>(new TH1F("TrkChi2XNdf","TrkChi2XNdf",90,0.,30.));
TrkChi2XNdf->SetDirectory(0);



HitMatrixR= std::auto_ptr<TH1F>(new TH1F("HitMatrixR","Class 1 Hit R",240,30.,150.)); 
HitMatrixR->SetDirectory(0);
HitMatrixR->SetXTitle("R (mm)");

HitMatrixPhi= std::auto_ptr<TH1F>(new TH1F("HitMatrixPhi","Class 1 Hit Phi",360,0.,360.)); 
HitMatrixPhi->SetDirectory(0);
HitMatrixPhi->SetXTitle("Deg");

char sZname2[1024];
char sZnamehist[1024];


 if(DoAlignHalfHalf)
 for(unsigned int m=0;m<RefHalfsWholeQuarterAlign.size();m++)
   {
     for(unsigned int t=0;t<10; t++)
       {
	 sprintf(sZname2, "ReltiveDX Respect reference Half %d Det %d ", m ,t); 
	 sprintf(sZnamehist,"ReltiveDX Respect reference Half %d Det %d ", m ,t); 
	 QuarterQuarterReltiveDX.push_back(boost::shared_ptr<TH1F>(new TH1F(sZname2,sZnamehist,70,-4,4)));
	 
	 QuarterQuarterReltiveDX.at(QuarterQuarterReltiveDX.size()-1)->SetDirectory(0);
	
       }
     for(unsigned int t=0;t<10; t++)
       {
	 sprintf(sZname2, "ReltiveDY Respect reference Half %d Det %d ", m ,t); 
	 sprintf(sZnamehist,"ReltiveDY Respect reference Half %d Det %d ", m ,t); 
	 QuarterQuarterReltiveDY.push_back(boost::shared_ptr<TH1F>(new TH1F(sZname2,sZnamehist,150,-4,4)));
	 QuarterQuarterReltiveDY.at(QuarterQuarterReltiveDY.size()-1)->SetDirectory(0);
       } 
   }

 
  for(unsigned int m=0;m<10; m++)
   {
       
       sprintf(sZname2, "DXAlignDet %d", m); 
       sprintf(sZnamehist, "DX shifts det %d", m);
       DXAlignDet[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,20,-3,3));
       DXAlignDet[m]->SetDirectory(0);
       
       sprintf(sZname2, "DYAlignDet %d", m); 
       sprintf(sZnamehist, "DY shifts det %d", m);
       DYAlignDet[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,20,-3,3));
       DYAlignDet[m]->SetDirectory(0);
   }

   for(unsigned int m=0;m<10; m++)
   {    
       sprintf(sZname2, "DRResol %d", m); 
       sprintf(sZnamehist, "R resolution det %d", m);
       DRResol[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,60,-2.5,2.5));
       DRResol[m]->SetDirectory(0);
       DRResol[m]->SetXTitle("#Delta R (mm)");
   }

    for(unsigned int m=0;m<10; m++)
      {
       sprintf(sZname2, "DPhiResol %d", m); 
       sprintf(sZnamehist, "Phi resolution det %d", m);
       // DPhiResol[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,30,-5,5));
       DPhiResol[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,60,-5,5));
       DPhiResol[m]->SetDirectory(0);
       DPhiResol[m]->SetXTitle("#Delta #Phi (deg)");
      }

    for(unsigned int m=0;m<10; m++)
      {
       sprintf(sZname2, "DXResol %d", m); 
       sprintf(sZnamehist, "X resolution det %d", m);
       DXResol[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,60,-3,3));
       DXResol[m]->SetDirectory(0);
       DXResol[m]->SetXTitle("#Delta X (mm)");
      }


    for(unsigned int m=0;m<10; m++)
      {
       sprintf(sZname2, "DYResol %d", m); 
       sprintf(sZnamehist, "Y resolution det %d", m);
       DYResol[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,60,-3,3));
       DYResol[m]->SetDirectory(0);
       DYResol[m]->SetXTitle("#Delta Y (mm)");
      }

    
    for(unsigned int m=0;m<10; m++)
      {
       sprintf(sZname2, "DXResp0 %d", m); 
       sprintf(sZnamehist,"X schift det %d respect det 0", m);
       DXResp0[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));
       DXResp0[m]->SetDirectory(0);
       sprintf(sZname2, "DYResp0 %d", m); 
       sprintf(sZnamehist,"Y schift det %d respect det 0", m);
       DYResp0[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));
       DYResp0[m]->SetDirectory(0);

       sprintf(sZname2, "DXResp9 %d", m); 
       sprintf(sZnamehist,"X schift det %d respect det 9", m);
       DXResp9[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));
       DXResp9[m]->SetDirectory(0);
       sprintf(sZname2, "DYResp9 %d", m); 
       sprintf(sZnamehist,"Y schift det %d respect det 9", m);
       DYResp9[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));
       DYResp9[m]->SetDirectory(0);
    
      
   } 
    
for(unsigned int m=0;m<40; m++)
  {
    sprintf(sZname2, "HitResolSimuY%d", m); 
    sprintf(sZnamehist,"HitResolSimuY%d", m);
    HitResolSimuY[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-5,5));
    // HitResolSimuY[m]->SetDirectory(0);
    sprintf(sZname2, "HitResolSimuX%d", m); 
    sprintf(sZnamehist,"HitResolSimuX%d", m);
    HitResolSimuX[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-5,5));
    // HitResolSimuX[m]->SetDirectory(0);


    sprintf(sZname2, "HitResolSimuR%d", m); 
    sprintf(sZnamehist,"HitResolSimuR%d", m); 
    HitResolSimuR[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-5,5));
    // SigmaResidualR[m]->SetDirectory(0);




    sprintf(sZname2, "SigmaResidualX %d", m); 
    sprintf(sZnamehist,"SigmaResidualX %d", m);
    SigmaResidualX[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));
    // SigmaResidualX[m]->SetDirectory(0);

   
    sprintf(sZname2, "SigmaResidualY %d", m); 
    sprintf(sZnamehist,"SigmaResidualY %d", m);
    SigmaResidualY[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-10,10));



    sprintf(sZname2, "SigmaExtrapolX %d", m); 
    sprintf(sZnamehist,"SigmaExtrapolX %d", m);
    SigmaExtrapolX[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-5,5));

    
    sprintf(sZname2, "SigmaExtrapolY %d", m); 
    sprintf(sZnamehist,"SigmaExtrapolY %d", m);
    SigmaExtrapolY[m]= std::auto_ptr<TH1F>(new TH1F(sZname2,sZnamehist,200,-5,5));


    
    //SigmaResidualY[m]->SetDirectory(0);
  }
 SeparEvent= std::auto_ptr<TH1F>(new TH1F("SeparEvent","-1NOTSEP 1SEP",2,-1,1));
 CumulativeRawTrkNumHit= std::auto_ptr<TH1F>(new TH1F("CumulativeRawTrkNumHit","CumulativeRawTrkNumHit",11,-0.5,10.5));
CumulativePhiResol= std::auto_ptr<TH1F>(new TH1F("CumulativePhiResol","Azimuthal Hit Resolution",20,-5,5));
CumulativePhiResol->SetDirectory(0);
CumulativeRResol= std::auto_ptr<TH1F>(new TH1F("CumulativeRResol","Radial Hit Resolution",40,-2,2));
CumulativeRResol->SetDirectory(0);
CumulativeExpXUncert= std::auto_ptr<TH1F>(new TH1F("CumulativeExpXUncert","CumulativeExpXUncert",100,-10,10));
CumulativeExpYUncert= std::auto_ptr<TH1F>(new TH1F("CumulativeExpYUncert","CumulativeExpYUncert",100,-10,10));
CumulativeRResol->SetXTitle("#Delta R (mm)");
CumulativePhiResol->SetXTitle("#Delta #Phi (deg)");
Trketa->SetXTitle("Track #eta");
Trkphi->SetXTitle("Track #phi (deg)");
Trkphigood->SetXTitle("Track #phi (deg)");
Trketagood->SetXTitle("Track #eta");
Chi2RProb->SetXTitle("Probability");
Chi2PhiProb->SetXTitle("Probability");
PolarAngles->SetXTitle("(rad)"); 

}

// ------------ method called once each job just after ending the event loop  ------------

void T2TrkBasedInternalAlignment::endJob()
{
 
  


  std::cout<<"End Job"<<std::endl;
  if(IncludeQuarterTiltAlign)
    {
      delete qtiltobj;
    }
  if(UseMillePede)
    {     
      delete millepedeobj;
     
    }
  if(UseMillePedeGlobal)
    {
      delete millepedeGlobobj;
    }
  
  TFile *f = TFile::Open(outputFileName.c_str(), "recreate");
  if( !f || !f->IsWritable() ){
    std::cout << "Output file not opened correctly !!" << std::endl;
  }
 
  

  //NumhitinTrack->Write("");
 // std::cout<<"---1"<<std::endl;

if(DoAlignHalfHalf)
  {
    for(unsigned int m=0;m<QuarterQuarterReltiveDX.size(); m++)
      {
	QuarterQuarterReltiveDX.at(m)->Write("");     
      }
 
    for(unsigned int m=0;m<QuarterQuarterReltiveDY.size(); m++)
      {
	QuarterQuarterReltiveDY.at(m)->Write("");     
      }
    //   std::cout<<"---21"<<std::endl;
    GraphDxDispA0=std::auto_ptr<TCanvas>(new TCanvas("GraphDxDispA0", "GraphDxDispA0", 700, 500));
    GraphDxDispA0->cd();
    //   std::cout<<"---210"<<std::endl;
    TH2F* histoX=new TH2F("testX","testXProj",20,zdet[0]-50.,zdet[19]+50.,150,-2.5,2.5 ); 
    histoX->Draw("");
    std::cout<<"---211"<<std::endl;
    DxDispA0= std::auto_ptr<TGraphErrors>(new TGraphErrors(20,zdet,finaldx,EZ,finalEdx));
    DxDispA0->SetTitle("Half1 X residuals respect to Half0");
    std::cout<<"---212"<<std::endl;
    histoX->GetXaxis()->SetTitle("Z (mm)");
    histoX->GetYaxis()->SetTitle("X (mm)"); 
    std::cout<<"---213"<<std::endl;
    DxDispA0->Draw("AP");
    GraphDxDispA0->Write("");
    //std::cout<<"---22"<<std::endl;

    GraphDyDispA0=std::auto_ptr<TCanvas>(new TCanvas("GraphDyDispA0", "GraphDyDispA0", 700, 500));
    GraphDyDispA0->cd();
    TH2F* histoy=new TH2F("testy","testyProj",20,zdet[0]-50.,zdet[19]+50.,150,-2.5,2.5); 
    histoy->Draw("");
    DyDispA0= std::auto_ptr<TGraphErrors>(new TGraphErrors(20,zdet,finaldy,EZ,finalEdy));
    DyDispA0->SetTitle("Half1 Y residuals respect to Half0");
    DyDispA0->GetXaxis()->SetTitle("Z (mm)");
    DyDispA0->GetYaxis()->SetTitle("Y (mm)"); 
    //DyDispA0->Update();
    DyDispA0->Draw("AP");
    GraphDyDispA0->Update();
  
    GraphDyDispA0->Write("");
    
    /*
     TCanvas* PlotTracksXProj=new TCanvas("PlotTracksXProj","testCanvasXProj",900,900);
     PlotTracksXProj->cd();
     //TH2F* histo=new TH2F("test","test",100,13500,14500,100,40,150); 
     TH2F* histoX=new TH2F("testX","testXProj",20,zdet[0]-50.,zdet[19]+50.,150,finaldx[0]-1.,finaldx[19]+1.); 
     histoX->Draw("");
     TGraphErrors* histoXProj=new TGraphErrors(20,zdet,finaldx,EZ,finalEdx); 
     //std::cout<<"dupa 02"<<std::endl;
     histoXProj->Draw("AP");
     PlotTracksXProj->Write("");
    */
    // GraphDyDispA0->Write("");  
  }

//std::cout<<"---2"<<std::endl;

 for(unsigned int m=0;m<10; m++)
   {
     /*
       DYAlignDet[m]->Write("");
       DXAlignDet[m]->Write("");  
     */

     DRResol[m]->Write(""); 
   }
 for(unsigned int m=0;m<10; m++)
   {
     DXResol[m]->Write("");
   }
 for(unsigned int m=0;m<10; m++)
   {
     DYResol[m]->Write("");  
   }
 for(unsigned int m=0;m<10; m++)
   {
     DPhiResol[m]->Write("");  
     /* 
	DXResp0[m]->Write("");  
	DYResp0[m]->Write("");  
       DXResp9[m]->Write("");  
       DYResp9[m]->Write("");
       */
   } 

 SimuErrDX->Write("");
 SimuErrDY->Write("");

 HitMatrixR->Write(""); 

 //CluStripentriesGoodHit->Write("");
 //CluPadentriesGoodHit->Write("");
 // TrackPhi0R0->Write("");
 NumhitinTrackGood->Write("");
 chiRredREF->Write("");
 ActiveSymbDet->Write("");
 Chi2phired->Write("");
 PolarAngles->Write("");
 H0AvgPadCLSHis->Write("");H0AvgStripCLSHis->Write("");
   CumulativeRawTrkNumHit->Write("");
    SeparEvent->Write("");

 Chi2red->Write("");
 
 //Tr4EffDetAll->Write("");
 IstoDisp->Write("");
 AllHitR->Write("");
 //drvsIddet->Write(""); 
 //alldetdr->Write(""); 
 //dphivsIddet->Write(""); 
 //alldetdphi->Write("");

 DetIdvsYShOnlyYfit->Write("");
 DetIdvsXShOnlyXfit->Write("");
NumActivePlH0->Write("");
NumActivePlH1->Write("");
NumActivePlH2->Write("");
NumActivePlH3->Write("");

  

 AllDetId->Write("");
 
 H1NumHit->Write("");
 H0NumHit->Write("");
 Trketagood->Write("");
 
 CumulativeRawTrketa->Write("");
 CumulativeRawTrkphi->Write("");
 
 Trkphigood->Write("");
  Taglio1_TrkSel->Write("");
  Taglio2_TrkSel->Write("");
  Taglio3_TrkSel->Write(""); Taglio4_TrkSel->Write(""); Taglio5_TrkSel->Write("");

 Trketa->Write("");
 Trkphi->Write("");
 HitZ->Write("");

 Chi2PhiProb->Write("");
 Chi2RProb->Write(""); 

 NumhitinTrackAligned->Write("");

 CumulativeExpXUncert->Write("");
 CumulativeExpYUncert->Write("");
 CumulativePhiResol->Write("");
 CumulativeRResol->Write("");


 //DxDispA0->Write("");
 //DyDispA0->Write("");
 //DxDispA1->Write("");
 //DyDispA1->Write("");

 RandomGauss->Write("");
 //DRHit12->Write("");
 AllDetIdRAW->Write("");
 AL_DPhiHitNoCutdet0->Write("");
 AL_DRHitNoCutdet0->Write("");
 AL_DPhiHitNoCutdet1->Write("");
 AL_DRHitNoCutdet1->Write("");
 AL_DPhiHitNoCutdet2->Write("");
 AL_DRHitNoCutdet2->Write("");
 AL_DPhiHitNoCutdet3->Write("");
 AL_DRHitNoCutdet3->Write("");
 AL_DPhiHitNoCutdet4->Write("");
 AL_DRHitNoCutdet4->Write("");
 AL_DPhiHitNoCutdet5->Write("");
 AL_DRHitNoCutdet5->Write("");
 AL_DPhiHitNoCutdet6->Write("");
 AL_DRHitNoCutdet6->Write("");
 AL_DPhiHitNoCutdet7->Write("");
 AL_DRHitNoCutdet7->Write("");
 AL_DPhiHitNoCutdet8->Write("");
 AL_DRHitNoCutdet8->Write("");
 AL_DPhiHitNoCutdet9->Write("");
 AL_DRHitNoCutdet9->Write("");
 
 
 PlaneUsedInAl->Write("");
 TrkChi2X->Write("");
 TrkChi2Y->Write("");
 TrkChi2XAl->Write("");
 TrkChi2YAl->Write("");
 
 TrkChi2XNdfAl->Write("");
 TrkChi2YNdfAl->Write("");
 TrkChi2XNdf->Write("");
 TrkChi2YNdf->Write("");

 TrkChi2RNdfAl->Write("");
 TrkChi2RNdf->Write("");
 
 ProbXHisto->Write("");
 ProbYHisto->Write("");
 ProbXHistoAl->Write("");
 ProbYHistoAl->Write("");

 AXHisto->Write("");
 AYHisto->Write("");
 AXError->Write("");
 AYError->Write("");
 BXError->Write("");
 BYError->Write("");
 HitMatrixPhi->Write("");
 
 
 HitXErr->Write("");
 HitYErr->Write("");
 HitX->Write("");
 HitY->Write("");
 Plside0PSimHitXD0->Write("");
 Plside1PSimHitXD0->Write("");
 PSimHitXD1->Write("");
 Plside0PSimHitYD0->Write("");
 Plside1PSimHitYD0->Write("");

 PSimHitYD1->Write("");
 
 NumClass1Hits->Write("");
 NumClass1HitsH0->Write("");
 NumClass1HitsH1->Write("");
 NumClass1HitsH3->Write("");









 f->mkdir("ResolutionSimuHisto");
 f->cd("ResolutionSimuHisto"); 
 for(unsigned int m=0;m<40; m++)
   {
     HitResolSimuX[m]->Write("");     
   }
 for(unsigned int m=0;m<40; m++)
   {
     HitResolSimuY[m]->Write("");
   }
 
 for(unsigned int m=0;m<40; m++)
   {
     SigmaResidualX[m]->Write("");
   }
 for(unsigned int m=0;m<40; m++)
   {
     SigmaResidualY[m]->Write("");
   }

for(unsigned int m=0;m<40; m++)
   {
     HitResolSimuR[m]->Write("");
   }

 for(unsigned int m=0;m<40; m++)
   {
     SigmaExtrapolX[m]->Write(""); 
   }

for(unsigned int m=0;m<40; m++)
   {
     SigmaExtrapolY[m]->Write(""); 
   }

 f->Close();
}

//define this as a plug-in
DEFINE_FWK_MODULE(T2TrkBasedInternalAlignment);
