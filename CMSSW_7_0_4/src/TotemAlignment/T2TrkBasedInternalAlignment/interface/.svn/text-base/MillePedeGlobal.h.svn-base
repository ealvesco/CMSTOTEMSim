// -*- C++ -*-
//
// Original Author:  Mirko Berretti
//         Created:  Wed Dec 12 18:19:44 CET 2007
// $Id: QuarterTilt ,v 1.4 2008/11/17 14:50:08 berretti Exp $
//

#ifndef _MILLEPEDEGLOBAL_H_
#define _MILLEPEDEGLOBAL_H_

// system include files
#include <memory>
#include <math.h>
#include <vector>
#include <algorithm>
#include "stdio.h"
#include <TMath.h>
// user include files
#include "TGraph.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include "TCanvas.h"
#include "TStyle.h"

#include <TMinuit.h>

#include "TROOT.h"


#include "DataFormats/T2Cluster/interface/T2Cluster.h"
#include "DataFormats/T2Hit/interface/T2Hit.h"
#include "DataFormats/T2Hit/interface/T2HitCollection.h"
#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/T2Road/interface/T2Road.h"
#include "DataFormats/T2Road/interface/T2RoadCollection.h"
#include "DataFormats/T1T2Track/interface/T1T2Track.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"
#include "DataFormats/T1Road/interface/T1RecHitGlobal.h"

#include "Geometry/TotemGeometry/interface/T2Geometry.h"
#include "TotemAnalysis/T2Cuts/interface/T2SelectionCutUtils.h"
#include <boost/shared_ptr.hpp>
//
// class decleration
//

class MillePedeGlobal{

public:

  explicit MillePedeGlobal(double T2_TrkEtamin_,double T2_TrkEtaMAX_,int T2_trkMultimin_,int T2_trkMultiMAX_,double T2_DZMultiplicator_,double T2_PhiChiProbCut_,double T2_RChiProbCut_,std::vector<unsigned int> T2_QuarterUsed_, bool XYFitUsed_,double AXTollerance_,double X0Tollerance_,double AYTollerance_,double Y0Tollerance_,std::vector<unsigned int> refplane_,std::vector<unsigned int> IdreferencedetMille_,std::vector<double> XreferencedetMille_,std::vector<double> YreferencedetMille_);


  ~MillePedeGlobal();
  

  
  //std::vector<double>  MilleFindGlobal(std::vector<std::vector<T2Hit> >* tt,char XorY,unsigned int quarterNumb);
  std::vector<double>  MilleFindGlobal(char XorY,unsigned int quarterNumb);
  void StoreEventtTrks(const T1T2TrackCollection* t2_trackCollection, bool separateTrkInH0, bool separateTrkInH1, bool separateTrkInH2, bool separateTrkInH3); 
  std::vector<double> CallMilleTiltShift(unsigned int quarterNumb/*,std::vector<std::vector<T2Hit> > *roadsX,std::vector<std::vector<T2Hit> > *roadsY*/);
  void SaveMisalinFile(unsigned int quarter,std::vector<double>  AX_ErrAX_X0_ErrX0_AY_ErrAY_Y0_ErrY0, fstream* f);
 
  //function to make code clear
  double Nj(double axj, double bxj, double AX0, double X0);
  double Dj(double axj, double bxj, double AX0, double X0);
  void CorrectForIntAlign(unsigned int half,std::vector<double> DX, std::vector<double> DY);



  //class data member
  T2SelectionCutUtils T2CutsUtilMilleGlob;
      
  std::vector<unsigned int> T2_QuarterUsed;
  std::vector<unsigned int> refplane;//One vect pos concern a quarter
  //These are all the ref plane for millepede of the 4 quarters.
  std::vector<unsigned int> IdreferencedetMille;
  std::vector<double> XreferencedetMille;
  std::vector<double> YreferencedetMille;
  double T2_FitdzEnergy;      //  # choose 10. or 50. GeV
  double T2_TrkEtamin;        //   # 4.8 for 10 GeV but now you have to consider MIS
  double T2_TrkEtaMAX;        //   # 7.0 for 10 GeV but now you have to consider MIS   
  int T2_trkMultimin, T2_trkMultiMAX;
  double T2_DZMultiplicator;
  double T2_PhiChiProbCut;
  double T2_RChiProbCut;
  unsigned int EventToPlot;
  bool UseSimu;
  bool _T2_usesXYtracking;
  
  double AXTollerance;
  double X0Tollerance;
  double AYTollerance;
  double Y0Tollerance;

  

  std::vector<long double> DisalignVectorAX,DisalignVectorAY;
  std::vector<long double> DisalignVectorX0,DisalignVectorY0;

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;

  std::vector<std::vector<std::vector<T2Hit> > > Evt_with_Vtxtrackcollection;
  std::vector<std::vector<T2Hit> > VtxtrackcollectionallEvt;
  
private:
  
  long double FinalX0, FinalThetaX, FinalY0, FinalThetaY;


};


 


#endif // _MILLEPEDEGLOBAL_H_
