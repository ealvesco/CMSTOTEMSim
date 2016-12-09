/*
Author: Mirko Berretti 
University of Siena and Pisa INFN
*/

#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/MillePede.h"
#include <memory>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <cmath>
#include <fstream>
#include "TFile.h"
#include "TNtuple.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TRandom.h"
#include "TF1.h"
#include "TProfile.h"

MillePede::MillePede(double T2_TrkEtamin_,double T2_TrkEtaMAX_,int T2_trkMultimin_,int T2_trkMultiMAX_,double T2_DZMultiplicator_,double T2_PhiChiProbCut_,double T2_RChiProbCut_,std::vector<unsigned int> T2_QuarterUsed_, bool XYFitUsed_,double AXTollerance_,double X0Tollerance_,double AYTollerance_,double Y0Tollerance_,std::vector<unsigned int>  refplane_,std::vector<unsigned int> IdreferencedetMille_,std::vector<double> XreferencedetMille_,std::vector<double> YreferencedetMille_,std::vector<unsigned int> MillePedeExcludedPlaneH0_,std::vector<unsigned int> MillePedeExcludedPlaneH1_,std::vector<unsigned int> MillePedeExcludedPlaneH2_,std::vector<unsigned int> MillePedeExcludedPlaneH3_)
{
  std::cout<<"MillePede Init0:"<<std::endl;
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
  //for(unsigned int j=0;j<refplane_.size();j++)
  //  refplane.push_back(refplane_.at(j));
  if(false)
    std::cout<<"var not used"<<refplane_.size()<<std::endl;


  TheMillePedeExcludedPlaneH0=MillePedeExcludedPlaneH0_;
  TheMillePedeExcludedPlaneH1=MillePedeExcludedPlaneH1_;
  TheMillePedeExcludedPlaneH2=MillePedeExcludedPlaneH2_;
  TheMillePedeExcludedPlaneH3=MillePedeExcludedPlaneH3_;


  for(unsigned int j=0;j<IdreferencedetMille_.size();j++)
    {
      IdreferencedetMille.push_back(IdreferencedetMille_.at(j));
      XreferencedetMille.push_back(XreferencedetMille_.at(j));
      YreferencedetMille.push_back(YreferencedetMille_.at(j));
      std::cout<<" --->>> "<<XreferencedetMille_.at(j)<< " "<<std::endl;
    }


  _T2_usesXYtracking= XYFitUsed_;
  AXTollerance=AXTollerance_;
  X0Tollerance=X0Tollerance_;
  AYTollerance=AYTollerance_;
  Y0Tollerance=Y0Tollerance_;
  std::cout<<"MillePede Init1:"<<std::endl;
  std::cout<<"|"<< T2_TrkEtamin <<"|"<<T2_TrkEtaMAX <<"|"<<T2_trkMultimin<<"|"<<T2_trkMultiMAX<<"|"<<T2_DZMultiplicator<<"|"<<T2_PhiChiProbCut<<"|"<<T2_RChiProbCut<<"|";

  for(unsigned int i=0;i<T2_QuarterUsed.size();i++)
    std::cout<<T2_QuarterUsed.at(i)<<"&";

  std::cout<<"|"<<_T2_usesXYtracking<<std::endl;
  
  T2CutsUtil.SetCuts(T2_TrkEtamin,T2_TrkEtaMAX,T2_trkMultimin,T2_trkMultiMAX,T2_DZMultiplicator,T2_PhiChiProbCut,T2_RChiProbCut,T2_QuarterUsedCopy,_T2_usesXYtracking);


  
}






MillePede::~MillePede()
{
}





double MillePede::Nj(double axj, double bxj, double AX0, double X0)
{
  double calc=bxj+X0;
  return calc;
}

double MillePede::Dj(double axj, double bxj, double AX0, double X0)
{
  double calc=axj+AX0;
  return calc;
}


unsigned int  MillePede::NumExcludedPlanes(unsigned int quarterNumb)
{

  unsigned int toret=0;
 
  if(quarterNumb==0) toret=TheMillePedeExcludedPlaneH0.size();
  if(quarterNumb==1) toret=TheMillePedeExcludedPlaneH1.size();
  if(quarterNumb==2) toret=TheMillePedeExcludedPlaneH2.size();
  if(quarterNumb==3) toret=TheMillePedeExcludedPlaneH3.size();



  return toret;
}

unsigned int  MillePede::PlaneNumberForMillewithExclusion(unsigned int plane0to9, unsigned int quarterNumb)
{

  int tosubtract=0;
  std::vector<unsigned int> TheMillePedeExcludedPlaneHX;
  if(quarterNumb==0) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH0;
  if(quarterNumb==1) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH1;
  if(quarterNumb==2) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH2;
  if(quarterNumb==3) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH3;

  for(unsigned int jj=0;jj< TheMillePedeExcludedPlaneHX.size(); jj++)
    {
      if(plane0to9>TheMillePedeExcludedPlaneHX.at(jj))
	tosubtract++;
    }

  plane0to9=plane0to9-tosubtract;

  return plane0to9;
}


unsigned int  MillePede::PlaneNumberOriginalFromMilleFormat(unsigned int plane0to9Mille, unsigned int quarterNumb)
{

  
  std::vector<unsigned int> TheMillePedeExcludedPlaneHX;
  if(quarterNumb==0) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH0;
  if(quarterNumb==1) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH1;
  if(quarterNumb==2) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH2;
  if(quarterNumb==3) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH3;

  //std::vector<int> milletoStdmap;
  unsigned int converted=0;
  for(unsigned int jj=0;jj<10; jj++)
    {

      if(PlaneNumberForMillewithExclusion(jj,quarterNumb)==plane0to9Mille)
	{
	  converted=jj;
	}
      
    }
  
  //for(unsigned int jj=0;jj<milletoStdmap.size(); jj++)
  //std::cout<<jj<<" ->  "<<milletoStdmap.at(jj)<<std::endl;
    
  plane0to9Mille=converted;

  return plane0to9Mille;
}



bool  MillePede::PlaneInExclusionList(unsigned int theplane,unsigned int quarterNumb)
{
  bool toret=false;
   std::vector<unsigned int> TheMillePedeExcludedPlaneHX;
  if(quarterNumb==0) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH0;
  if(quarterNumb==1) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH1;
  if(quarterNumb==2) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH2;
  if(quarterNumb==3) TheMillePedeExcludedPlaneHX=TheMillePedeExcludedPlaneH3;

  std::vector<unsigned int>::iterator it;

  it = std::find (TheMillePedeExcludedPlaneHX.begin(), TheMillePedeExcludedPlaneHX.end(), theplane);
  if (it != TheMillePedeExcludedPlaneHX.end())
    toret=true;

  return toret;
}


std::vector<std::vector<double> > MillePede::MilleFindInternal(std::vector<std::vector<T2Hit> > *theTracks, char XorY,unsigned int quarterNumb)
{
  T2GeometryUtil convMille;
  T2GeometryUtil::T2DetInfo planeinfoMille;
 
  // std::cout<<" !0 "<<std::endl;   
  //pag 7 Software alignment for Tracking Detector, V. Blobel      
  int numexcludedplane=NumExcludedPlanes(quarterNumb);
  unsigned int numworkingplane=10-numexcludedplane;
  std::cout<<"MillePede internal working with quarter "<<quarterNumb<<" Num Excluded planes : "<<numexcludedplane<<" Working : "<<numworkingplane<<std::endl;

  TMatrixD Cprime(numworkingplane,numworkingplane);
  Cprime.Zero();
  //TVectorD bprime(numworkingplane);
  TMatrixD bprime(numworkingplane,1);
  bprime.Zero();

  //std::vector<TVectorD> dGlobal_i;
  std::vector<TMatrixD> dGlobal_i;
  std::vector<TMatrixD> dGlobal_i_T;
  for(unsigned int y=0;y<numworkingplane;y++)
    {

      TMatrixD CartesianBase_y(numworkingplane,1);     
      CartesianBase_y.Zero();
      // if((y!=9)&&(y!=1))
      CartesianBase_y(y,0)=1.0;
      dGlobal_i.push_back(CartesianBase_y);

      TMatrixD CartesianBase_y_T(1,numworkingplane);
      CartesianBase_y_T.Transpose(CartesianBase_y);
      dGlobal_i_T.push_back(CartesianBase_y_T);
    }
      
  double sigmaHit=0.;
  double meas_k=0.;
  //  double z_k=0.;
  //std::cout<<" !1 "<<std::endl;   
  
  TMatrixD Gamma_k(2,2); //Gammak-1 is the covariance matrix of the k-track.  
  TMatrixD beta_k(2,1);
  TMatrixD beta_k_T(1,2);
  TMatrixD Gk(numworkingplane,2);
  TMatrixD Gk_T(2,numworkingplane);
  TMatrixD b_k(numworkingplane,1);

  for(unsigned int j=0; j<theTracks->size();j++)
    {
                         	      
      std::vector<T2Hit> hitv =  theTracks->at(j);
      //numworkingplane=NUM of alignment parameter, 2= number of track parameter 
       
       Gk.Zero();
       Gamma_k.Zero();
       beta_k.Zero();
       // std::cout<<" !2 "<<std::endl;   
      for(unsigned int k=0;k<hitv.size();k++)
	{

	  planeinfoMille=convMille.GetT2Info(hitv.at(k).GetHitDetRawId());
	  unsigned int theplane=planeinfoMille.pl_0to9;
	  unsigned int theplaneSAV=theplane;
	  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	  if(PlaneInExclusionList(theplane,quarterNumb))
	    continue;

	  theplane=PlaneNumberForMillewithExclusion(theplane,quarterNumb);
	  if(false)std::cout<<theplaneSAV<<"->"<<theplane<<std::endl;
	  /*
	  if(numexcludedplane>1)
	    {
	      if(theplane<=1)
		continue;

	      if(theplane>1)//0 and 1 exclusion
		theplane=theplane-numexcludedplane;
	     
	    }
	  */

	  if(XorY=='X')
	    {
	      sigmaHit=hitv.at(k).GetHitDX();
	      meas_k=hitv.at(k).GetHitX();
	    }
	  else
	    {
	      sigmaHit=hitv.at(k).GetHitDY();
	      meas_k=hitv.at(k).GetHitY();
	    }
	  
	  double w_k=(1.0/(sigmaHit*sigmaHit));
	  // std::cout<<" !2A "<<std::endl;      
	  
	  //TVectorD delta_k_local(2);
	  TMatrixD delta_k_local(2,1);
	  delta_k_local(0,0)=1.;
	  delta_k_local(1,0)=hitv.at(k).GetHitZ();

	  TMatrixD delta_k_local_T(1,2);
	  delta_k_local_T.Transpose(delta_k_local);
	  //std::cout<<" !2B "<<std::endl;   
	  //std::cout<<"plane  "<<theplane<<"   Vectsize  "<<dGlobal_i.size()<<std::endl;
	  Gk=Gk+w_k*(dGlobal_i.at(theplane))*delta_k_local_T;
	  //std::cout<<" !2C "<<std::endl;   

	  for(unsigned int i=0;i<2;i++)//2= numnb of track parameter
	    for(unsigned int j=0;j<2;j++)
	      Gamma_k(i,j)+= w_k*delta_k_local(i,0)*delta_k_local(j,0);
	 
	  for(unsigned int j=0;j<2;j++)
	    beta_k(j,0)+= w_k*meas_k*delta_k_local(j,0);
	  //std::cout<<" !2D "<<std::endl;   
	  
	  b_k += w_k*meas_k*(dGlobal_i.at(theplane)); //eq. 9 Kaspar paper

	  Cprime += w_k*(dGlobal_i.at((theplane))*dGlobal_i_T.at((theplane)));	      
	  //std::cout<<" !2E "<<std::endl;   

	}

      //  std::cout<<" !3 "<<std::endl;   
      //you should use the gamma_k matrix previously found for get residuals.

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
      b_k = b_k - Gk*(Gamma_kInvert*beta_k);
      // std::cout<<" !3C "<<std::endl;   
      Cprime = Cprime - Gk*Gamma_kInvert*Gk_T;
      //  std::cout<<" !4 "<<std::endl;   
                
     
    }//All tracks have been considered                      : 
  
  //Now invert the C matrix and get the alignment parameter.
  //Now I will insert the constraint: Warning it is assumed that the millepede is called for only a quarter 
  //so the vector has size 1.
  // std::cout<<"Cprime:"<<std::endl;
  //Cprime.Print();
  TMatrixD CprimeConstr((numworkingplane+2),(numworkingplane+2));
  CprimeConstr.Zero();
  TMatrixD bprimeConstr((numworkingplane+2),1);
  bprimeConstr.Zero();

  TMatrixD g1(numworkingplane,1);
  g1.Zero();
  TMatrixD g2(numworkingplane,1);
  g2.Zero();


  
  //The constraint is: Shift_ref_plane=0.
  // double lamda=1.;
  //double constraint_value=0.;
  for(unsigned int i=0;i<numworkingplane;i++)
    {
    for(unsigned int j=0;j<numworkingplane;j++)
      {
	CprimeConstr(i,j)=Cprime(i,j);
      }
     bprimeConstr(i,0)=b_k(i,0);
    }
  //  double toputinmatrix;
  //double toputinvectb;
  for(unsigned int i=0;i<(numworkingplane+2);i++)
     {    
       CprimeConstr(numworkingplane,i)=0.;
       CprimeConstr((numworkingplane+1),i)=0.;
       CprimeConstr(i,numworkingplane)=0.;
       CprimeConstr(i,(numworkingplane+1))=0.;	   
     }

  
  //To implement better. Now assumed 0,9 as reference detector.
  //////////////////
  double constraintValue1=0.;
  double constraintValue2=0.;
  unsigned int refdet1=0;
  unsigned int refdet2=0;
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

  std::cout<<refdet1<<"  ||||||||||||||||||  "<<refdet2<<std::endl;
  refdet1=PlaneNumberForMillewithExclusion(refdet1,quarterNumb);//refdet1-numexcludedplane;
  refdet2=PlaneNumberForMillewithExclusion(refdet2,quarterNumb);//refdet2-numexcludedplane;
  std::cout<<refdet1<<"  ||||||||||||||||||  "<<refdet2<<std::endl;

  bprimeConstr(numworkingplane,0)=constraintValue1;//0.;
  bprimeConstr((numworkingplane+1),0)=constraintValue2;//0.;

  CprimeConstr(refdet1,numworkingplane)=1.;//ex: (10,0)=det1
  CprimeConstr(refdet2,(numworkingplane+1))=1.;

  std::cout<<"("<<refdet1<<" and "<<refdet2<<" constrained):"<<std::endl;
  std::cout<<"   CONSTRAINT  "<<XorY<<" "<< constraintValue1<<" "<<constraintValue2<<std::endl;

  CprimeConstr(numworkingplane,refdet1)=1.;
  CprimeConstr((numworkingplane+1),refdet2)=1.;  
  ///////////////////////
     
   TMatrixD AlignParam((numworkingplane+2),1);
   TMatrixD CprimeConstr_Invert=CprimeConstr;
   CprimeConstr.Print();
   std::cout<<"Try to invert it"<<std::endl;
   Double_t deter;
   CprimeConstr_Invert.Invert(&deter);
   AlignParam=CprimeConstr_Invert*bprimeConstr;

   std::vector<double> retvecAlignPar;
   std::vector<double> retvecAlignParErr;
   std::cout<<"Millepede "<<XorY<< " alignment results ("<<refdet1<<" and "<<refdet2<<" constrained):"<<std::endl;
   for(unsigned int h=0;h<numworkingplane;h++)
     {
      retvecAlignPar.push_back(AlignParam(h,0));
      retvecAlignParErr.push_back(sqrt(CprimeConstr_Invert(h,h)));
      std::cout<<"Det "<<h<<" D"<<XorY<<": "<<AlignParam(h,0)<<"    Err_D"<<XorY<<": "<<sqrt(CprimeConstr_Invert(h,h))<<std::endl;
     }
 


   //std::cout<<" !8 "<<std::endl;
   std::vector<std::vector<double> > returnedParam_and_Error;
   returnedParam_and_Error.push_back(retvecAlignPar);
   returnedParam_and_Error.push_back(retvecAlignParErr);
   //std::cout<<" !9"<<std::endl;
   return returnedParam_and_Error;
}



//Return DX EDX DY EDY
std::vector<std::vector<double> >  MillePede::CallMille(unsigned int quarterNumb,std::vector<std::vector<T2Hit> > *roadsX,std::vector<std::vector<T2Hit> > *roadsY)
{  

  std::vector<std::vector<double> > DisalignVector;
  
  /*
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALF;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALALL;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX;
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY;
  unsigned int quarterid;
  unsigned int hh;
  for(unsigned int j=0;j<trackutilizedforalignment.size();j++)
    {
      planeinfo=conv.GetT2Info(trackutilizedforalignment.at(j).at(0).GetHitDetRawId());
      hh=planeinfo.symb/10;
      if(hh==quarterNumb)
	{
	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitX()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.8)	    
	    trackutilizedforalignmentONEHALFX.push_back(trackutilizedforalignment.at(j));

	  if(fabs(trackutilizedforalignment.at(j).at(0).GetHitY()/trackutilizedforalignment.at(j).at(0).GetHitR())>0.8)
	    trackutilizedforalignmentONEHALFY.push_back(trackutilizedforalignment.at(j));

	  trackutilizedforalignmentONEHALALL.push_back(trackutilizedforalignment.at(j));
	}
    }

  */
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFX=(*roadsX);
  std::vector<std::vector<T2Hit> >  trackutilizedforalignmentONEHALFY=(*roadsY);
  std::cout << "Millepede algorithm will work with tracks extrated from the full event sample of: [Trk in X proj="<<trackutilizedforalignmentONEHALFX.size()<<" Trk in Y proj="<<trackutilizedforalignmentONEHALFY.size()<<"]"<<std::endl;

  
  char XorY;
  std::vector<std::vector<double> > VectToReturn;

  for(unsigned int fromxtoy=0;fromxtoy<2;fromxtoy++)
    {
       
      if(fromxtoy==0)
	{
	  XorY='X';
	  //trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFX;	 
	  DisalignVector=MilleFindInternal(&trackutilizedforalignmentONEHALFX, XorY,quarterNumb);
	  for(unsigned int t=0;t<DisalignVector.size();t++)
	    VectToReturn.push_back(DisalignVector.at(t));
	}
      else
	{
	  XorY='Y';
	  DisalignVector=MilleFindInternal(&trackutilizedforalignmentONEHALFY, XorY,quarterNumb);
	  for(unsigned int t=0;t<DisalignVector.size();t++)
	    VectToReturn.push_back(DisalignVector.at(t));
	  // trackutilizedforalignmentONEHALF=trackutilizedforalignmentONEHALFY;
	}
     
      // DisalignVector=MilleFindInternal(&trackutilizedforalignmentONEHALF, XorY);
      /* 
      if(fromxtoy==0)
	{
	  VectToReturn.push_back(DisalignVector);
	}
      else
	{
	  VectToReturn.push_back(DisalignVector);
	  
	}
      */

    }//loop from x to y end

  

  // std::vector<long double> ToReturn;
  //ToReturn.insert( ToReturn.end(), DisalignVectorX.begin(), DisalignVectorX.end() );
  //ToReturn.insert( ToReturn.end(), DisalignVectorY.begin(), DisalignVectorY.end() );
   
  

  if(VectToReturn.size()!=4)
    {
      std::cout<<"MillePede is not working, incorrect size of returned parameted. Expected 4, returned "<<VectToReturn.size()<<std::endl ;
      if(VectToReturn.size()>=4)
	std::cout<<"DxiDYi ="<<VectToReturn.at(0).at(0)<<" | "<<VectToReturn.at(1).at(0)<<" | "<<VectToReturn.at(2).at(0)<<" | "<<VectToReturn.at(3).at(0)<<std::endl;
    }

  return VectToReturn;
  
}





void MillePede::StoreEventtTrks(const T1T2TrackCollection* t2_trackCollection)
{

 
  bool _T2_usesXYtracking=true;

  //  bool flag=false;
  std::vector<T1T2Track> t2trackVector;
  T1T2TrackCollection::const_iterator TC_it2;
  //unsigned int trksize;

  for(TC_it2=t2_trackCollection->begin(); TC_it2!=t2_trackCollection->end(); TC_it2++){
    if(T2CutsUtil.AcceptThisT2Track(*TC_it2))
      t2trackVector.push_back((*TC_it2)); 
  }

  T2CutsUtil.FindPrimaryVtx(t2trackVector,_T2_usesXYtracking);

  if(T2CutsUtil.storeVtx.VtxTrks.size()>=2)
    {
      
      if(fabs(T2CutsUtil.storeVtx.VtxPos.x)<100)//10cm
	 if(fabs(T2CutsUtil.storeVtx.VtxPos.y)<100)
	    if(fabs(T2CutsUtil.storeVtx.VtxPos.z)<8000)
	      {
		for(unsigned int i=0;i<t2trackVector.size();i++)
		  {
		    if(T2CutsUtil.TrkInQuarter(t2trackVector.at(i)))
		      {
			T1T2Track Trk=t2trackVector.at(i);
			std::vector<T2Hit> hitv;
			for (unsigned int g=0;g<Trk.GetHitEntries();g++)
			  hitv.push_back(Trk.GetHitT2(g));
		      
			trackutilizedforalignment.push_back(hitv);		    		     
		      }
		    }
	      }      
    }

  // return flag;
}

void MillePede::SaveMisalinFile(unsigned int quarter,std::vector<std::vector<double> >  DX_EDX_DY_EDY, fstream* file_op)
{
  std::cout<<"Saving Millepede results in a file.."<<std::endl;

  if(((*file_op).is_open())==false)
    {
      std::cout<<"ERROR: Problem in opening file"<<std::endl;
      (*file_op).clear();
    }
  (*file_op) << " \n";

  std::vector<double> DX=DX_EDX_DY_EDY.at(0);
  std::vector<double> EDX=DX_EDX_DY_EDY.at(1);
  std::vector<double> DY=DX_EDX_DY_EDY.at(2);
  std::vector<double> EDY=DX_EDX_DY_EDY.at(3);

  for(unsigned int m=0; m<DX.size(); m++)
    {
      int originalplaneNumber=PlaneNumberOriginalFromMilleFormat(m,quarter);
      (*file_op)<<"DetId: "<<quarter*10+originalplaneNumber<<"   DX: "<<DX.at(m)<<"   DY: "<<DY.at(m)<<"   EDX: "<<EDX.at(m)<<"   EDY: "<<EDY.at(m)<<" \n";
      (*file_op)<<" \n";                  	
    }
  
}



