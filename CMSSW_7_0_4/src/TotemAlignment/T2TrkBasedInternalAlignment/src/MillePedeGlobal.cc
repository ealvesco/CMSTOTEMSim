/*
Author: Mirko Berretti 
University of Siena and Pisa INFN
*/

#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/MillePedeGlobal.h"
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


MillePedeGlobal::MillePedeGlobal(double T2_TrkEtamin_,double T2_TrkEtaMAX_,int T2_trkMultimin_,int T2_trkMultiMAX_,double T2_DZMultiplicator_,double T2_PhiChiProbCut_,double T2_RChiProbCut_,std::vector<unsigned int> T2_QuarterUsed_, bool XYFitUsed_,double AXTollerance_,double X0Tollerance_,double AYTollerance_,double Y0Tollerance_,std::vector<unsigned int>  refplane_,std::vector<unsigned int> IdreferencedetMille_,std::vector<double> XreferencedetMille_,std::vector<double> YreferencedetMille_)
{
  std::cout<<"MillePedeGlobal Init0:"<<std::endl;
  T2_TrkEtamin = T2_TrkEtamin_;
  T2_TrkEtaMAX = T2_TrkEtaMAX_;
  T2_trkMultimin = T2_trkMultimin_;
  T2_trkMultiMAX = T2_trkMultiMAX_ ; 
  T2_DZMultiplicator = T2_DZMultiplicator_ ; 
  T2_PhiChiProbCut =  T2_PhiChiProbCut_;
  T2_RChiProbCut = T2_RChiProbCut_;
  // T2_QuarterUsed = T2_QuarterUsed_;
  std::vector<int> T2_QuarterUsedCopy;

  for(unsigned int j=0;j<T2_QuarterUsed_.size();j++)
    {
      T2_QuarterUsed.push_back(T2_QuarterUsed_.at(j));
      T2_QuarterUsedCopy.push_back(T2_QuarterUsed_.at(j));
    }
  for(unsigned int j=0;j<refplane_.size();j++)
    refplane.push_back(refplane_.at(j));


  for(unsigned int j=0;j<IdreferencedetMille_.size();j++)
    {
      IdreferencedetMille.push_back(IdreferencedetMille_.at(j));
      XreferencedetMille.push_back(XreferencedetMille_.at(j));
      YreferencedetMille.push_back(YreferencedetMille_.at(j));
    }


  _T2_usesXYtracking= XYFitUsed_;
  AXTollerance=AXTollerance_;
  X0Tollerance=X0Tollerance_;
  AYTollerance=AYTollerance_;
  Y0Tollerance=Y0Tollerance_;
  std::cout<<"MillePedeGlobal Init1:"<<std::endl;
  std::cout<<"|"<< T2_TrkEtamin <<"|"<<T2_TrkEtaMAX <<"|"<<T2_trkMultimin<<"|"<<T2_trkMultiMAX<<"|"<<T2_DZMultiplicator<<"|"<<T2_PhiChiProbCut<<"|"<<T2_RChiProbCut<<"|";

  for(unsigned int i=0;i<T2_QuarterUsed.size();i++)
    std::cout<<T2_QuarterUsed.at(i)<<"&";

  std::cout<<"|"<<_T2_usesXYtracking<<std::endl;
  
  /*T2CutsUtil*/
  T2CutsUtilMilleGlob.SetCuts(T2_TrkEtamin,T2_TrkEtaMAX,T2_trkMultimin,T2_trkMultiMAX,T2_DZMultiplicator,T2_PhiChiProbCut,T2_RChiProbCut,T2_QuarterUsedCopy,_T2_usesXYtracking);

}






MillePedeGlobal::~MillePedeGlobal()
{
}





double MillePedeGlobal::Nj(double axj, double bxj, double AX0, double X0)
{
  double calc=bxj+X0;
  return calc;
}

double MillePedeGlobal::Dj(double axj, double bxj, double AX0, double X0)
{
  double calc=axj+AX0;
  return calc;
}

//Return AX ErrAx BX ErrBx if XorY='X'
std::vector<double> MillePedeGlobal::MilleFindGlobal(char XorY, unsigned int quarterNumb)
{
  
  //double ExtVtxX=0.001;
  //double ExtVtxY=0.001;
  //double ExtVtxZ=0.001;
  T2GeometryUtil convMilleGlob;
  T2GeometryUtil::T2DetInfo planeinfoMilleGlob;
  std::vector<double> returnedParam_and_Error;

  //pag 7 Software alignment for Tracking Detector, V. Blobel      
  TMatrixD Cprime(2,2);
  Cprime.Zero();
  //TVectorD bprime(10);
  TMatrixD bprime(2,1);
  bprime.Zero();
  
 
 

  planeinfoMilleGlob=convMilleGlob.GetT2Info(quarterNumb*10);  
  //  double firstplanez=planeinfo.Zdet;
 
  //  unsigned int planesymbid;
 
  double measb,sigmab;//b,a

  TRandom *R = new TRandom(time(0));  // create a pointer to a new instance of TRanom in the heap
 
  
  TMatrixD Gamma_k(1,1); //Gammak-1 is the covariance matrix of the k-track.  
  TMatrixD beta_k(1,1);
  TMatrixD beta_k_T(1,1);
  TMatrixD Gk(2,1);
  TMatrixD Gk_T(1,2);
  TMatrixD b_k(2,1);


  std::cout<<" Start MilleGlobal alignment of  "<<XorY<<std::endl;
  
  //Evt_with_Vtxtrackcollection ?? un vettore di std::vector<std::vector<T2Hit> > *theTracks;std::vector<std::vector<T2Hit> > ;
  for(unsigned int j=0; j<Evt_with_Vtxtrackcollection.size();j++)
    {
      std::vector<std::vector<T2Hit> > theTracksfromSameVtx=Evt_with_Vtxtrackcollection.at(j);               	      
      //std::vector<T2Hit> hitv =  theTracks->at(j);
      //2=NUM of alignment parameter, 1= number of Vtx parameter (z) 
       
       Gk.Zero();
       Gamma_k.Zero();
       beta_k.Zero();
       //std::vector<TMatrixD> dGlobal_i;
       //std::vector<TMatrixD> dGlobal_i_T;
       // std::cout<<" !2 "<<std::endl;
       TMatrixD dGlobal(2,1);
       TMatrixD dGlobal_T(1,2);
       

       
       //Calculate Vz for this event.
       std::vector<T1T2Track> Vtxtracks;
       for(unsigned int k=0;k<theTracksfromSameVtx.size();k++)
	 {
	   Vtxtracks.push_back(T2CutsUtilMilleGlob.TrackFromHits(true,theTracksfromSameVtx.at(k)));
	 }

       double ZVtxposForThisEvt=0.;
       if(theTracksfromSameVtx.size()>1){
	 std::vector<T2SelectionCutUtils::point3d> TheEvtVtx=T2CutsUtilMilleGlob.GivePrimaryVtx(Vtxtracks, true);
	  ZVtxposForThisEvt=TheEvtVtx.at(1).z;//0XY 1RZ
       }

       //convert to detector frame
       //Commented on 24 Lug.
       // ZVtxposForThisEvt=((-1.0)*(T2CutsUtilMilleGlob.FirstPlaneForThishit(theTracksfromSameVtx.at(0).at(0))-ZVtxposForThisEvt));
       //Vz calculated  
       
       bool goahead=false;
       //std::cout<<" A  "<<std::endl;
       for(unsigned int k=0;k<theTracksfromSameVtx.size();k++)
	 if(theTracksfromSameVtx.at(k).size()>0){

	   if(XorY=='Y'){
	     if((fabs(theTracksfromSameVtx.at(k).at(0).GetHitY()/theTracksfromSameVtx.at(k).at(0).GetHitR())>0.6)&&(theTracksfromSameVtx.at(k).at(0).GetHitY()>0))
	       goahead=true;
	     else
	       goahead=false;
	   }

	   if(XorY=='X'){
	     if(fabs(theTracksfromSameVtx.at(k).at(0).GetHitX()/theTracksfromSameVtx.at(k).at(0).GetHitR())>0.6)	     
	       goahead=true;
	     else
	       goahead=false;
	   }
		 
	 }
       // std::cout<<" A1  "<<std::endl;
       if(goahead){

	 for(unsigned int k=0;k<theTracksfromSameVtx.size();k++)
	   {	
	  	    
	     //dGlobal(0,0)=1;
	     //dGlobal(1,0)=ZVtxposForThisEvt;
	     int indexMax=theTracksfromSameVtx.at(k).size()-1; 
	     //	     double rnd01= R->Rndm();
	     int index=(int)((R->Rndm()*indexMax));
	     if(index>indexMax)
	       index=indexMax;
	     ZVtxposForThisEvt=theTracksfromSameVtx.at(k).at(index).GetHitZ();
	     // std::cout<<ZVtxposForThisEvt<<std::endl;
	     
	     dGlobal(0,0)=-1;
	     dGlobal(1,0)=-(1.0)*ZVtxposForThisEvt;
	     dGlobal_T.Transpose(dGlobal);
	     
	     std::vector<T2Hit> hitv =  T2CutsUtilMilleGlob.GetHitsInQuarterFrame(theTracksfromSameVtx.at(k)); 
	     T1T2Track thexytrk=T2CutsUtilMilleGlob.TrackFromHits(true, hitv);
	     
	     double measCoord=0.;
	     planeinfoMilleGlob=convMilleGlob.GetT2Info(hitv.at(k).GetHitDetRawId());
	     //	     unsigned int theplane=planeinfoMilleGlob.pl_0to9;
	     

	     if(XorY=='X')
	       {
		 sigmab=thexytrk.X0Sigma();
		 //a=thexytrk.GetTx();
		 // measb=thexytrk.X0()-ExtVtxX;
		 measb=thexytrk.X0();
		 measCoord=theTracksfromSameVtx.at(k).at(index).GetHitX();
		 //sigmab=theTracksfromSameVtx.at(k).at(index).GetHitDX();
	       }
	     else
	       {
		 sigmab=thexytrk.Y0Sigma();
		 //a=thexytrk.GetTy();
		 //measb=thexytrk.Y0()-ExtVtxY;	      
		 measb=thexytrk.Y0();
		 measCoord=theTracksfromSameVtx.at(k).at(index).GetHitY();
		 //sigmab=theTracksfromSameVtx.at(k).at(index).GetHitDY();
	       }
	     //   std::cout<<" A2  "<<std::endl;
	     double w_k=(1.0/(sigmab*sigmab));
	     // std::cout<<" !2A "<<std::endl;      
	     
	     //TVectorD delta_k_local(2);
	     TMatrixD delta_k_local(1,1);
	     //delta_k_local(0,0)=hitv.at(k).GetHitZ();
	     //Comm on Lug 2012
	     //delta_k_local(0,0)=a*(-1.0);
	     delta_k_local(0,0)=-(1.0)*ZVtxposForThisEvt;
	     TMatrixD delta_k_local_T(1,1);
	     delta_k_local_T.Transpose(delta_k_local);
	     //std::cout<<" !2B "<<std::endl;   
	     //std::cout<<"plane  "<<theplane<<"   Vectsize  "<<dGlobal_i.size()<<std::endl;
	     Gk=Gk+w_k*dGlobal*delta_k_local_T;
	     //std::cout<<" !2C "<<std::endl;   

	     
	     
	     Gamma_k(0,0)+= w_k*delta_k_local(0,0)*delta_k_local(0,0); 
	     
	     //for(unsigned int j=0;j<2;j++)
	     
	     beta_k(0,0)+= w_k*(measb-(1.0)*measCoord)*delta_k_local(0,0);
	     //std::cout<<" !2D "<<std::endl;   	  
	     b_k += w_k*(measb-(1.0)*measCoord)*dGlobal; //eq. 9 Kaspar paper
	     Cprime += w_k*dGlobal*dGlobal_T;	
	   }
      	 
	 
	 // std::cout<<" A3  "<<std::endl;
	 //  std::cout<<" !3 "<<std::endl;   
	 //you should use the gamma_k matrix previously found for get residuals.
	 //	 std::cout<<"  Loop all tr"<<std::endl;   
	 Double_t deti;
	 TMatrixD Gamma_kInvert=Gamma_k;
	 Gamma_kInvert.Invert(&deti);
	 //  std::cout<<" !3A "<<std::endl;   
	 beta_k_T.Transpose(beta_k);
	 Gk_T.Transpose(Gk);
	 //  std::cout<<" !3B "<<std::endl;   
	 //b_k.Print();
	 //Gk.Print();
	 //Gamma_kInvert.Print();	
	 //beta_k_T.Print();	
	 //b_k = b_k - Gk*(Gamma_kInvert*beta_k_T);
	 TMatrixD localpar(1,1);
	 localpar=(Gamma_kInvert*beta_k_T); 
	 /*
	   std::cout<<"--------------------"<<std::endl;
	   for(unsigned int k=0;k<hitv.size();k++)
	   std::cout<<"X Z: "<<hitv.at(k).GetHitX()<<" "<<hitv.at(k).GetHitZ();
	   std::cout<<"aj= ";
	   localpar.Print();
	   std::cout<<"--------------------"<<std::endl;
	   std::cout<<std::endl;
	 */
	 b_k = b_k - Gk*(Gamma_kInvert*beta_k);
	 // std::cout<<" !3C "<<std::endl;   
	 Cprime = Cprime - Gk*Gamma_kInvert*Gk_T;
	 //  std::cout<<" !4 "<<std::endl;   
       } //if goahead     
     
    }//All tracks have been considered                      : 
  
  //Now invert the C matrix and get the alignment parameter.
  //Now I will insert the constraint: Warning it is assumed that the millepede is called for only a quarter 
  //so the vector has size 1.
  // std::cout<<"Cprime:"<<std::endl;
  //Cprime.Print();
  
  TMatrixD CprimeConstr(2,2);
  CprimeConstr=Cprime;
  TMatrixD bprimeConstr(2,1);
  bprimeConstr=b_k;

 std::cout<<"Cprime Bef Inv:"<<std::endl;
 Cprime.Print();

/*
  TMatrixD g1(10,1);
  g1.Zero();
  TMatrixD g2(10,1);
  g2.Zero();


  unsigned int refpos=0;
  unsigned int posinvect=0;
  //std::cout<<" !5 "<<std::endl;   
 if(std::find(T2_QuarterUsed.begin(), T2_QuarterUsed.end(), quarterNumb) !=  T2_QuarterUsed.end())
   {
     posinvect=std::find(T2_QuarterUsed.begin(), T2_QuarterUsed.end(), quarterNumb)- T2_QuarterUsed.begin(); //indeed find give an iterator. I want to know the half pos. in the vector
     refpos=refplane.at(posinvect);
     refpos=refpos%10;
   }
 else
   {
     refpos=0;
     std::cout<<"MillePedeGlobal took the detector 0 of quarter "<<quarterNumb<<" as a reference plane"<<std::endl;
   }

   

  
  //The constraint is: Shift_ref_plane=0.
  // double lamda=1.;
  double constraint_value=0.;
  for(unsigned int i=0;i<10;i++)
    {
    for(unsigned int j=0;j<10;j++)
      {
	CprimeConstr(i,j)=Cprime(i,j);
      }
     bprimeConstr(i,0)=b_k(i,0);
    }
  double toputinmatrix;
  double toputinvectb;
  for(unsigned int i=0;i<12;i++)
     {    
       CprimeConstr(10,i)=0.;
       CprimeConstr(11,i)=0.;
       CprimeConstr(i,10)=0.;
       CprimeConstr(i,11)=0.;	   
     }

  
 
  double constraintValue1=0.;
  double constraintValue2=0.;
  unsigned int refdet1=1;
  unsigned int refdet2=9;
  unsigned int quarterindexinvector=quarterNumb*2;
  if(XreferencedetMille.size()!=8)
    std::cout<<"Incorrect Size = "<<XreferencedetMille.size()<<" of reference vector"<<std::endl;
  else
    {
      refdet1=IdreferencedetMille.at(quarterindexinvector);
      refdet2=IdreferencedetMille.at(quarterindexinvector+1);
      refdet1=refdet1%10;
      refdet2=refdet2%10;
      if(XorY=='X')
	{
	  constraintValue1=XreferencedetMille.at(quarterindexinvector);
	  constraintValue2=XreferencedetMille.at(quarterindexinvector+1);
	}
      else
	{
	  constraintValue1=YreferencedetMille.at(quarterindexinvector);
	  constraintValue2=YreferencedetMille.at(quarterindexinvector+1);
	}
    }
   
   
  bprimeConstr(10,0)=constraintValue1;//0.;
  bprimeConstr(11,0)=constraintValue2;//0.;

  CprimeConstr(refdet1,10)=1.;//ex: (10,0)=det1
  CprimeConstr(refdet2,11)=1.;

  CprimeConstr(10,refdet1)=1.;
  CprimeConstr(11,refdet2)=1.;  
  ///////////////////////
  */
   TMatrixD AlignParam(2,1);
   TMatrixD CprimeConstr_Invert=CprimeConstr;
   CprimeConstr.Print();
   Double_t deter;
   CprimeConstr_Invert.Invert(&deter);
   AlignParam=CprimeConstr_Invert*bprimeConstr;

   std::vector<double> retvecAlignPar;
   std::vector<double> retvecAlignParErr;
   std::cout<<"Millepede "<<XorY<< "Tilt-Shift alignment results:"<<std::endl;
   std::string kindofpar;
   for(unsigned int h=0;h<2;h++)
     {
       if(h==0)
	 kindofpar="A-intercept";
       else
	 kindofpar="B-slope";
      retvecAlignPar.push_back(AlignParam(h,0));
      returnedParam_and_Error.push_back(AlignParam(h,0));
      retvecAlignParErr.push_back(sqrt(CprimeConstr_Invert(h,h)));
      returnedParam_and_Error.push_back(sqrt(CprimeConstr_Invert(h,h)));
      std::cout<<"Parameter "<<h<<": ("<<kindofpar<<XorY<<"): "<<AlignParam(h,0)<<"    Err_D"<<kindofpar<<XorY<<": "<<sqrt(CprimeConstr_Invert(h,h))<<std::endl;
     }
 

   
   
   return returnedParam_and_Error;
}



//Return AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0
std::vector<double>   MillePedeGlobal::CallMilleTiltShift(unsigned int quarterNumb)
{  
  //VtxtrackcollectionallEvt
  std::cout<<"Size Global Millepede starting sample: "<<VtxtrackcollectionallEvt.size()<<std::endl;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALALL;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY;
  //  unsigned int quarterid;
  unsigned int hh;
  for(unsigned int j=0;j<VtxtrackcollectionallEvt.size();j++)
    {
      planeinfo=conv.GetT2Info(VtxtrackcollectionallEvt.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;
      if(hh==quarterNumb)
	{
	  if(fabs(VtxtrackcollectionallEvt.at(j).at(0).GetHitX()/VtxtrackcollectionallEvt.at(j).at(0).GetHitR())>0.7)	    
	    trackutilizedforalignmentONEHALFX.push_back(VtxtrackcollectionallEvt.at(j));

	  if(fabs(VtxtrackcollectionallEvt.at(j).at(0).GetHitY()/VtxtrackcollectionallEvt.at(j).at(0).GetHitR())>0.7)
	    if(VtxtrackcollectionallEvt.at(j).at(0).GetHitY()>0)
	       trackutilizedforalignmentONEHALFY.push_back(VtxtrackcollectionallEvt.at(j));
	  
	  trackutilizedforalignmentONEHALALL.push_back(VtxtrackcollectionallEvt.at(j));
	}
    }

 

  //std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX=(*roadsX);
  //std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY=(*roadsY);
  std::vector<double>  DisalignVector;
  std::cout << "Millepede algorithm will work with tracks extrated from the full event sample of: [Trk in X proj="<<trackutilizedforalignmentONEHALFX.size()<<" Trk in Y proj="<<trackutilizedforalignmentONEHALFY.size()<<"]"<<std::endl;

  
  char XorY;
  std::vector<double>  VectToReturn;

  for(unsigned int fromxtoy=0;fromxtoy<2;fromxtoy++)
    {
       
      if(fromxtoy==0)
	{
	  XorY='X';
	  //VtxtrackcollectionallEvt.clear();
	  //VtxtrackcollectionallEvt=trackutilizedforalignmentONEHALFX;
	  DisalignVector=MilleFindGlobal(XorY,quarterNumb);
	  for(unsigned int t=0;t<DisalignVector.size();t++)
	    VectToReturn.push_back(DisalignVector.at(t));
	}
      else
	{
	  XorY='Y';
	  //VtxtrackcollectionallEvt.clear();
	  //VtxtrackcollectionallEvt=trackutilizedforalignmentONEHALFY;
	  DisalignVector=MilleFindGlobal(XorY,quarterNumb);
	  for(unsigned int t=0;t<DisalignVector.size();t++)
	    VectToReturn.push_back(DisalignVector.at(t));
	}
     
     

    }//loop from x to y end

  

  // std::vector<long double> ToReturn;
  //ToReturn.insert( ToReturn.end(), DisalignVectorX.begin(), DisalignVectorX.end() );
  //ToReturn.insert( ToReturn.end(), DisalignVectorY.begin(), DisalignVectorY.end() );
   
  
  //VectToReturn=AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0
  if(VectToReturn.size()!=8)
    {
      std::cout<<"MillePedeGlobal is not working, incorrect size of returned parameted. Expected 8, returned "<<VectToReturn.size()<<std::endl ;
     
    }

  return VectToReturn;
  
}


void MillePedeGlobal::CorrectForIntAlign(unsigned int half,std::vector<double> DX, std::vector<double> DY)
{
  uint32_t rawiddet=0;
  double r=0.;
  unsigned int symb=0;
  //unsigned int countinhalf=0;
  for (unsigned int g=0;g<VtxtrackcollectionallEvt.size();g++)
    {
      std::vector<T2Hit> hitv=VtxtrackcollectionallEvt.at(g);
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
	VtxtrackcollectionallEvt.at(g)=hitv;
    }
}



void MillePedeGlobal::StoreEventtTrks(const T1T2TrackCollection* t2_trackCollection, bool H0cond,bool H1cond,bool H2cond,bool H3cond)
{

  //T1T2Track T2SelectionCutUtils::TrackFromHits(bool DoXYTrkFit, std::vector<T2Hit> hitvec)
 
  //if(trk.GetHitEntries()>=3)
  //planeinfo=conv.GetT2Info(trk.GetHitT2(0)
 
  //  bool _T2_usesXYtracking=true;

  //  bool flag=false;
  std::vector<T1T2Track> t2trackVector;
  T1T2TrackCollection::const_iterator TC_it2;
  //unsigned int trksize;

  for(TC_it2=t2_trackCollection->begin(); TC_it2!=t2_trackCollection->end(); TC_it2++){
    
    std::vector<T2Hit> hitsintrk;
    for (unsigned int j=0;j<(*TC_it2).GetHitEntries();j++)
      hitsintrk.push_back((*TC_it2).GetHitT2(j));
    T1T2Track thexytrk=T2CutsUtilMilleGlob.TrackFromHits(true, hitsintrk);
   

    if(T2CutsUtilMilleGlob.AcceptThisT2Track(thexytrk))/*(*TC_it2)*/
       t2trackVector.push_back(thexytrk);/*(*TC_it2)*/ 
  }
 
    
  // std::cout<<"No Vertex found in the event... 2012 work with single trk"<<std::endl;    
  std::vector<std::vector<T2Hit> > trackutilizedforalignment;
  for(unsigned int i=0;i<t2trackVector.size();i++){//Loop 1 or 0 tracks
      T1T2Track Trk=t2trackVector.at(i);
      std::vector<T2Hit> hitv;
      for (unsigned int g=0;g<Trk.GetHitEntries();g++)
	hitv.push_back(Trk.GetHitT2(g));      
      trackutilizedforalignment.push_back(hitv);
      VtxtrackcollectionallEvt.push_back(hitv);
      
      if(trackutilizedforalignment.size()>=1)
	Evt_with_Vtxtrackcollection.push_back(trackutilizedforalignment);
    }
    // return flag;
  }





///void MillePedeGlobal::SaveTiltsinFile(std::map<unsigned int,std::vector<long double> >  half_VS_AX_X0_AY_Y0, fstream* fileop)
void MillePedeGlobal::SaveMisalinFile(unsigned int quarter,std::vector<double> AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0, fstream* file_op)
{
  std::cout<<"Saving Millepede results in a file.."<<std::endl;
  
  if(((*file_op).is_open())==false)
    {
      std::cout<<"ERROR: Problem in opening file"<<std::endl;
      (*file_op).clear();
    }
  (*file_op) << " \n";


  if(AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.size()==8)
    {
      
      (*file_op)<<"QuarterId:  "<<quarter;
   
     
      (*file_op)<<"  TiltX:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(0);
      (*file_op)<<"  Err_TiltX:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(1);
      (*file_op)<<"  ShiftX0:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(2);
      (*file_op)<<"  Err_ShiftX0:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(3);
      (*file_op) << " \n";
      (*file_op)<<"  TiltY:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(4);
      (*file_op)<<"  Err_TiltY:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(5);
      (*file_op)<<"  ShiftY0:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(6);
      (*file_op)<<"  Err_ShiftY0:  "<<AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0.at(7);
  
    }
  else
    std::cout<<"Error: vector Tilt/shift.size != 8 !!!"<<std::endl;
  

    
}



