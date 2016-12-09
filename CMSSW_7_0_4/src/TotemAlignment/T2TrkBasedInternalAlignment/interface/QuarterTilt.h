// -*- C++ -*-
//
// Original Author:  Mirko Berretti
//         Created:  Wed Dec 12 18:19:44 CET 2007
// $Id: QuarterTilt.h 6778 2012-09-18 22:04:03Z berretti $
//

#ifndef _QuarterTilt_H_
#define _QuarterTilt_H_

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
#include <TH3F.h> 

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

class QuarterTilt/*: public ROOT::Minuit2::FCNBase*/{

public:

  explicit QuarterTilt(double T2_TrkEtamin_,double T2_TrkEtaMAX_,int T2_trkMultimin_,int T2_trkMultiMAX_,double T2_DZMultiplicator_,double T2_PhiChiProbCut_,double T2_RChiProbCut_,std::vector<unsigned int> T2_QuarterUsed_, bool XYFitUsed_,double AXTollerance_,double X0Tollerance_,double AYTollerance_,double Y0Tollerance_);
  ~QuarterTilt();
  

  //Retun  X0, ThetaX or Y0, ThetaY
  long double AxInoneshot(std::vector<std::vector<T2Hit> >* tt,char XorY);
  std::vector<long double> NewtonStep(std::vector<std::vector<T2Hit> >* tt,char XorY);
  std::vector<long double> NewtonStep1D(std::vector<std::vector<T2Hit> >* tt,char XorY);

  long double ShiftEstimation1D(std::vector<std::vector<T2Hit> > *theTracks, char XorY);
  long double TiltHistograms1D(std::vector<std::vector<T2Hit> > *theTracks, char XorY);
  std::vector<long double> FindShiftTiltFrombj(std::vector<std::vector<T2Hit> >*theTracks, char XorY);

  //function to make code clear
  double Nj(double axj, double bxj, double AX0, double X0);
  double Dj(double axj, double bxj, double AX0, double X0);

  //Return true when parameter nv are close to parameter at previous iteration (ov)
  bool CompareAlignVector(std::vector<long double> nv,std::vector<long double> ov);

  void StoreEventtTrks(const T1T2TrackCollection* t2_trackCollection, bool UseGlobVertexForTrkSelection, bool SepH0, bool SepH1, bool SepH2, bool SepH3);
  void CorrectForIntAlign(unsigned int half,std::vector<double> DX, std::vector<double> DY);

  //std::vector<T2Hit> UpdateThisTrk(std::vector<T2Hit> hitv,double axj,double bxj,char XorY);  
  std::vector<T2Hit> UpdateThisTrk(std::vector<T2Hit> hitv,double origaxj,double origbxj,double CorrectionToaxj,double CorrectionTobxj,char XorY);

  //return AX,X0,AY,Y0
  std::vector<long double> FindQuarterShiftTilt(unsigned int quarterNumb);
  void TestNewton(std::vector<std::vector<T2Hit> >*);
  double StartingPointTheta(std::vector<std::vector<T2Hit> > *theTracks, char XorY);

  void SaveTiltsinFile(std::map<unsigned int,std::vector<long double> >  half_VS_AX_X0_AY_Y0, fstream* f);

  long double Shift1DSimpleDifference(std::vector<std::vector<T2Hit> > *theTracks, char XorY);
  std::vector<long double> ShiftTiltHistograms1DTh(std::vector<std::vector<T2Hit> > *theTracks, char XorY);
  std::vector<long double> FindQuarterShiftTiltSimple(unsigned int quarterNumb);

  std::auto_ptr<TH3F>  h2Xtiltshift;
  std::auto_ptr<TH3F>  h2Ytiltshift;
  std::auto_ptr<TH1F>  ZImpHisto;
  std::auto_ptr<TH1F>  ZImpHisto_X;
  std::auto_ptr<TH1F> ZImpHisto_XAfterAlign;



    std::auto_ptr<TH1F> ZImpHisto_Y;
    std::auto_ptr<TH1F> ZImpHisto_YAfterAlign;
  std::auto_ptr<TH1F> ZImpHisto_XInsidecorrector;
  std::auto_ptr<TH2F>  SelTrackXY_X;
  std::auto_ptr<TH2F>  SelTrackXY_Y;
  std::auto_ptr<TH1F>  VZhisto;
  std::auto_ptr<TH2F>  VXYhisto;
  std::auto_ptr<TH2F>  ErrXvsAx;
  std::auto_ptr<TH2F>  ErrBXvsBx;
  std::auto_ptr<TProfile> ShiftObsY;
  std::auto_ptr<TProfile> ShiftObsX;
  ////Tminuit Related function
  
  //Begin --------------------------------------Please_uncomment_this
  std::vector<long double> FindShiftTiltMinuit(std::vector<std::vector<T2Hit> >*theTracks, char XorY);
  //End --------------------------------------Please_uncomment_this
  

  //class data member
  T2SelectionCutUtils T2CutsUtil;
      
  std::vector<int> T2_QuarterUsed;
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
  

  T2GeometryUtil conv;
  T2GeometryUtil::T2DetInfo planeinfo;
  double ExtVx,ExtVy,ExtVz;
 

  std::vector<std::vector<T2Hit> >  trackutilizedforalignment;
  std::vector<std::vector<T1T2Track> > VtxTrkInEvt; //Each event has a vector of trks from vtx.

static std::vector<double>* xVecPtr;
static std::vector<double>* zVecPtr; 
static std::vector<double>* bjVecPtr;
static std::vector<double>* ajVecPtr;
static std::vector<double>* ERRbjVecPtr;

static std::vector<double>* ajX_forVeloCalc;
static std::vector<double>* bjX_forVeloCalc;
static std::vector<double>* ajY_forVeloCalc;
static std::vector<double>* bjY_forVeloCalc;
static std::vector<double>* OurVzs_forVeloCalc;
static std::vector<double>* ErrbjX_forVeloCalc;
static std::vector<double>* ErrbjY_forVeloCalc;

static std::vector<double>* EntryX_forVeloCalc;
static std::vector<double>* EntryY_forVeloCalc;
static std::vector<double>* EntryZ_forVeloCalc;
static std::vector<double>* ajY_forVeloCalc_usedinX;
static std::vector<double>* ajX_forVeloCalc_usedinX;
static std::vector<double>* ajY_forVeloCalc_usedinY;
static std::vector<double>* ajX_forVeloCalc_usedinY;

static double fcnombra(Double_t *par);
static void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
static double funcbteo(double xVecati,double zVecati, double ajVecati,Double_t *par);
static double fcnVeloX(Double_t *par, double ExtVx_);
static double fcnVeloY(Double_t *par, double ExtVy_);
static double fcnGrandZimpX(Double_t *par, double ExtVy_);
static double fcnGrandZimpY(Double_t *par, double ExtVy_);

private:
  
  long double FinalX0, FinalThetaX, FinalY0, FinalThetaY;


};


 






#endif // _QuarterTilt_H_
