// -*- C++ -*-
//
// Original Author:  Mirko Berretti
//         Created:  Wed Dec 12 18:19:44 CET 2007
// $Id: T2TrkBasedInternalAlignment.h 6778 2012-09-18 22:04:03Z berretti $
//

#ifndef _TotemAlignmentT2T2TrkBasedInternalAlignment_H_
#define _TotemAlignmentT2T2TrkBasedInternalAlignment_H_

// system include files
#include <memory>
#include <math.h>
#include <TMath.h>
// user include files
#include "TF1.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include "TCanvas.h"
#include "TStyle.h"
#include "TProfile.h"
#include "TPad.h"
#include "TView.h"
#include "TAxis3D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TPolyLine3D.h"
#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/TrackInfo.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/T1RecHit/interface/T1RecHit2D.h"
#include "DataFormats/T1RecHit/interface/T1RecHit2DCollection.h"
#include "DataFormats/T2Cluster/interface/T2Cluster.h"
#include "DataFormats/T2Hit/interface/T2Hit.h"
#include "DataFormats/T2Hit/interface/T2HitCollection.h"
#include "DataFormats/T2Cluster/interface/T2PadClusterCollection.h"
#include "DataFormats/T2Cluster/interface/T2StripClusterCollection.h"
#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/T2Road/interface/T2Road.h"
#include "DataFormats/T2Road/interface/T2RoadCollection.h"
#include "DataFormats/T1T2Track/interface/T1T2Track.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/CrossingFrame/interface/MixCollection.h"
#include "SimDataFormats/CrossingFrame/interface/CrossingFrame.h"
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"

#include "Geometry/TotemGeometry/interface/T2Geometry.h"
#include "Geometry/TotemGeometry/interface/T2GeometryUtil.h"
#include <boost/shared_ptr.hpp>

#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/QuarterTilt.h"
#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/MillePede.h"
#include "TotemAlignment/T2TrkBasedInternalAlignment/interface/MillePedeGlobal.h"
#include "TotemAnalysis/T2Cuts/interface/T2SelectionCutUtils.h"
 

// class decleration
//

class T2TrkBasedInternalAlignment : public edm::EDAnalyzer {
public:
  explicit T2TrkBasedInternalAlignment(const edm::ParameterSet&);
  ~T2TrkBasedInternalAlignment();


  QuarterTilt* qtiltobj;
  MillePede* millepedeobj;
  MillePedeGlobal* millepedeGlobobj;

  virtual void beginJob();
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  

  
  void MakeQuarterQuarterMisalHisto(std::vector<std::vector<T2Hit> > *roadfitOverlapARM,unsigned int halftoalign);
  void MakeHitResolSimuHisto(std::map<int, edm::PSimHitContainer> hitMap,std::vector<T2Hit> t2hitcoll, char XorY);
  std::vector<std::vector<double> > MakeErrorHistograms(std::vector<std::vector<T2Hit> > *roadsX,std::vector<std::vector<T2Hit> > *roadsY,unsigned int thehalf);

private:

  //void HipReferenceLine(unsigned int quarter, double Z, double &Xret,double &Yret );

  std::vector<double> chi2R(std::vector<T2Hit> hitvec,unsigned int UseJointProb);
  std::vector<double> RPhiFit(std::vector<T2Hit> hitvec);

  double HitError(T2Hit* hit, const char * comp);
  bool MettiTracciaBuona(std::vector<TrackInfo>* matricetracce,T1T2TrackCollection::const_iterator  trk, unsigned int numevento);

  bool MettiTracciaBuonaInOverlap(std::vector<TrackInfo>* matricetracce,T1T2TrackCollection::const_iterator  trk, unsigned int numevento);
  int TrackIsInTwoQuarter(T1T2TrackCollection::const_iterator  trk, unsigned int howmanyhit);  
  int TrackIsInOneQuarter(T1T2TrackCollection::const_iterator  trk, unsigned int howmanyhit);

  void CorrectRoadHitsInOverlap( std::vector<std::vector<T2Hit> > *roadfitOverlapARM, std::vector<double> TotDXDisphalf0, std::vector<double>  TotDYDisphalf0,std::vector<double> TotDXDisphalf1,std::vector<double> TotDYDisphalf1);

  void CalculateRelativeHalfAlign(double* TotDXDispARM,double* TotDYDispARM,double* TotDXDispARMErr,double* TotDYDispARMErr, std::vector<std::vector<T2Hit> > *roadfitOverlapARM,unsigned int halftoalign);
  
  
  void RecomputeHalfDispl(double TotDXDispARM, double TotDYDispARM, double TotDXDispARMErr,double TotDYDispARMErr, std::vector<double> *TotDXDisphalf, std::vector<double> *TotDYDisphalf,  std::vector<double> *TotDXDisphalfErr, std::vector<double> *TotDYDisphalfErr);

  std::vector<double>  CalculateAlignError2(std::vector<double> Disp , std::vector<std::vector<T2Hit> > roads,unsigned int xory, bool CalculateErrorForWholeHalf, std::vector<double> DispError);

  double CalculateAlignHIP(std::vector<std::vector<T2Hit> > roads,unsigned int xory, unsigned int thehalf,unsigned int plane0_9);


  std::vector<T2Hit> GiveMeTheHitForResidual(unsigned int planeIdToExclude, std::vector<T2Hit>  hitv);
  
  T1T2Track GiveMeTrkHalfPart(T1T2TrackCollection::const_iterator  TrkCit, unsigned int half);

  bool IsOverlappingTrkInAccept(std::vector<T2Hit>   PartofTrackinH0,std::vector<T2Hit>   PartofTrackinH1,unsigned int halftoalign);

  bool IsTrkInFULLAccept(std::vector<T2Hit> trkhit, unsigned int wantedhalf);

 
 

 T2SelectionCutUtils T2CutsUtilForAl;

  // Begin of Common plots
  std::auto_ptr<TH1F>  Taglio1_TrkSel; std::auto_ptr<TH1F>  Taglio2_TrkSel; std::auto_ptr<TH1F>  Taglio3_TrkSel;
  std::auto_ptr<TH1F> Taglio5_TrkSel;std::auto_ptr<TH1F>  Taglio4_TrkSel;std::auto_ptr<TH1F>  CumulativeRawTrkNumHit;
  std::auto_ptr<TH1F>  SeparEvent;std::auto_ptr<TH1F> AllDetIdRAW;
  std::auto_ptr<TH1F> NumActivePlH0;
  std::auto_ptr<TH1F> NumActivePlH1;
  std::auto_ptr<TH1F> NumActivePlH2;
  std::auto_ptr<TH1F> NumActivePlH3;

  std::auto_ptr<TProfile> H0AvgStripCLSHis;  std::auto_ptr<TProfile> H0AvgPadCLSHis;
  std::auto_ptr<TH1F> SimuErrDX;
  std::auto_ptr<TH1F> SimuErrDY;

  std::auto_ptr<TH1F> NumhitinTrack;
  std::auto_ptr<TH1F> NumhitinTrackGood;
  std::auto_ptr<TH1F> HitZ;
  std::auto_ptr<TH1F> clusterstripentries;
  std::auto_ptr<TH1F> clusterpadentries;
  std::auto_ptr<TH1F> diffphiCluGun;
  std::auto_ptr<TH1F> RLocHRecoH;
  std::auto_ptr<TH1F> Trketa;
  std::auto_ptr<TH1F> Trkphi;
  std::auto_ptr<TH1F> DPhiGoodTrk;
  std::auto_ptr<TH1F> DEtaGoodTrk;
  std::auto_ptr<TH1F> diffphiGUNHIT;
  std::auto_ptr<TH1F> diffphiCluHit;
  std::auto_ptr<TH1F> Trkphigood;
  std::auto_ptr<TH1F> Trketagood;
  std::auto_ptr<TH1F> diffRCluHit;
  std::auto_ptr<TH1F> Chi2RProb;
  std::auto_ptr<TH1F> Chi2PhiProb;
  std::auto_ptr<TH1F> chiRredREF;
  std::auto_ptr<TH1F> HitXErr;
  std::auto_ptr<TH1F> HitYErr;
  std::auto_ptr<TH1F> HitX;
  std::auto_ptr<TH1F> HitY;
  std::auto_ptr<TH1F> AllHitR;

  std::auto_ptr<TH1F> PSimHitXD1;
  std::auto_ptr<TH1F> PSimHitYD1;
  std::auto_ptr<TH1F> Plside0PSimHitYD0; 
  std::auto_ptr<TH1F> Plside1PSimHitYD0;
  std::auto_ptr<TH1F> Plside0PSimHitXD0; 
  std::auto_ptr<TH1F> Plside1PSimHitXD0;
 std::auto_ptr<TH1F> H0NumHit;
 std::auto_ptr<TH1F> H1NumHit;
  std::auto_ptr<TH1F> CumulativeRawTrketa;std::auto_ptr<TH1F> CumulativeRawTrkphi;
  std::auto_ptr<TProfile> NumAllHitvsIdGoodevt;
  std::auto_ptr<TProfile> NumAllHitvsIdAllevt;

  std::auto_ptr<TCanvas> Chi2PhiProbLogy;
  std::auto_ptr<TCanvas> Chi2RProbLogy;

  std::auto_ptr<TH1F> RandomGauss;
  std::auto_ptr<TH1F> HitMatrixR;
  std::auto_ptr<TH1F> HitMatrixPhi;
  std::auto_ptr<TH1F> ActiveSymbDet;
  std::auto_ptr<TH1F> PolarAngles;
  std::auto_ptr<TH1F> Chi2red;
  std::auto_ptr<TH1F> Chi2phired;


  std::auto_ptr<TH1F> ProbYHisto;
  std::auto_ptr<TH1F> ProbXHisto;
  std::auto_ptr<TH1F> ProbYHistoAl;
  std::auto_ptr<TH1F> ProbXHistoAl;

  std::auto_ptr<TH1F>  AXError;
  std::auto_ptr<TH1F>  AYError;
  std::auto_ptr<TH1F>  BXError;
  std::auto_ptr<TH1F>  BYError;
  std::auto_ptr<TH1F>  AXHisto;
  std::auto_ptr<TH1F>  AYHisto;

 
  
  // End of Common plots


  // ALiGNMENT - Begin specific plots

  std::auto_ptr<TH1F> NumhitinTrackAligned;
  std::auto_ptr<TH1F> IstoDisp;
    
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet0;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet1;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet2;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet3;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet4;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet5;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet6;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet7;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet8;
  std::auto_ptr<TH1F> AL_DPhiHitNoCutdet9;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet0;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet1;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet2;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet3;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet4;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet5;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet6;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet7;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet8;
  std::auto_ptr<TH1F> AL_DRHitNoCutdet9;

  std::auto_ptr<TH1F>  DYAlignDet[10];
  std::auto_ptr<TH1F>  DXAlignDet[10];
  std::auto_ptr<TH1F>  DRResol[10];
  std::auto_ptr<TH1F>  DPhiResol[10];
  std::auto_ptr<TH1F>  DXResol[10];
  std::auto_ptr<TH1F>  DYResol[10];

  std::auto_ptr<TH1F>  DXResp0[10];
  std::auto_ptr<TH1F>  DYResp0[10];
  std::auto_ptr<TH1F>  DXResp9[10];
  std::auto_ptr<TH1F>  DYResp9[10];

  std::auto_ptr<TH1F> HitResolSimuX[40];
  std::auto_ptr<TH1F> HitResolSimuY[40];
  std::auto_ptr<TH1F> HitResolSimuR[40];
  std::auto_ptr<TH1F> SigmaResidualX[40];
  std::auto_ptr<TH1F> SigmaResidualY[40];
  std::auto_ptr<TH1F> SigmaExtrapolX[40];
  std::auto_ptr<TH1F> SigmaExtrapolY[40];

  std::vector<boost::shared_ptr<TH1F> > QuarterQuarterReltiveDX;
  std::vector<boost::shared_ptr<TH1F> > QuarterQuarterReltiveDY;
  
  std::auto_ptr<TGraphErrors> DxDispA0;
  std::auto_ptr<TGraphErrors> DxDispA1; 
  std::auto_ptr<TGraphErrors> DyDispA0;
  std::auto_ptr<TGraphErrors> DyDispA1;
  
  std::auto_ptr<TCanvas> GraphDxDispA0;
  std::auto_ptr<TCanvas> GraphDyDispA0;
  std::auto_ptr<TCanvas> GraphDxDispA1;
  std::auto_ptr<TCanvas> GraphDyDispA1;
  

  std::auto_ptr<TH1F> CumulativePhiResol;
  std::auto_ptr<TH1F> CumulativeRResol;
  std::auto_ptr<TH1F> CumulativeExpXUncert;
  std::auto_ptr<TH1F> CumulativeExpYUncert;

  std::auto_ptr<TProfile> DetIdvsXShOnlyXfit;
  std::auto_ptr<TProfile> DetIdvsYShOnlyYfit;
  std::auto_ptr<TH1F> AllDetId;
  std::auto_ptr<TH1F> AllDetIdPlane;
  std::auto_ptr<TH1F> AllDetIdPlaneS;
  std::auto_ptr<TH1F> TrkChi2X;
  std::auto_ptr<TH1F> TrkChi2Y;
  std::auto_ptr<TH1F> TrkChi2XAl;
  std::auto_ptr<TH1F> TrkChi2YAl;
  std::auto_ptr<TH1F> TrkChi2XNdf;
  std::auto_ptr<TH1F> TrkChi2YNdf;
  std::auto_ptr<TH1F> TrkChi2XNdfAl;
  std::auto_ptr<TH1F> TrkChi2YNdfAl;
  
  std::auto_ptr<TH1F> TrkChi2RNdfAl;
  std::auto_ptr<TH1F> TrkChi2RNdf;
  std::auto_ptr<TH1F>  NumClass1Hits;
  std::auto_ptr<TH1F>  NumClass1HitsH3; 
  std::auto_ptr<TH1F>  NumClass1HitsH1;
  std::auto_ptr<TH1F>  NumClass1HitsH0;
  std::auto_ptr<TH1F> PlaneUsedInAl;
  // ALiGNMENT - End specific plots


  // ALiGNMENT - Begin store results data
  unsigned int trkcounter;
 
  std::map<unsigned int,double> mapsymbtoZ; 

  unsigned int matrixentries;
  unsigned int matrixentries0;
  unsigned int matrixentries1;
  unsigned int matrixentries2;
  unsigned int matrixentries3;
  unsigned int matrixentries_Overl_Arm0;
  unsigned int matrixentries_Overl_Arm1;
  
  std::vector<TrackInfo> *MatriceTracce;
  std::vector<TrackInfo> MatriceTracceh0a0;
  std::vector<TrackInfo> MatriceTracceh1a0;
  std::vector<TrackInfo> MatriceTracceh0a1;
  std::vector<TrackInfo> MatriceTracceh1a1;
  std::vector<TrackInfo> MatriceTracceRelativeHalfAlignArm0;
  std::vector<TrackInfo> MatriceTracceRelativeHalfAlignArm1;
  std::vector<TrackInfo> *MatriceTracceTwoHalfs;


  
  std::vector<std::vector<T2Hit> > roadXfit;
  std::vector<std::vector<T2Hit> > roadYfit;

  std::vector<std::vector<T2Hit> > roadXfith0;
  std::vector<std::vector<T2Hit> > roadYfith0;
  std::vector<std::vector<T2Hit> > roadXfith1;
  std::vector<std::vector<T2Hit> > roadYfith1; 
  std::vector<std::vector<T2Hit> > roadXfith2;
  std::vector<std::vector<T2Hit> > roadYfith2;
  std::vector<std::vector<T2Hit> > roadXfith3;
  std::vector<std::vector<T2Hit> > roadYfith3;

  std::vector<std::vector<T2Hit> > CommonTrackforPlot;


  std::vector<std::vector<T2Hit> > origroadXfit;
  std::vector<std::vector<T2Hit> > origroadYfit;

  std::vector<std::vector<T2Hit> > origroadXfith0;
  std::vector<std::vector<T2Hit> > origroadYfith0; 
  std::vector<std::vector<T2Hit> > origroadXfith1;
  std::vector<std::vector<T2Hit> > origroadYfith1;
  std::vector<std::vector<T2Hit> > origroadXfith2;
  std::vector<std::vector<T2Hit> > origroadYfith2;
  std::vector<std::vector<T2Hit> > origroadXfith3;
  std::vector<std::vector<T2Hit> > origroadYfith3;

  std::vector<uint32_t> alldetid;
  std::vector<uint32_t> alldetidh0;
  std::vector<uint32_t> alldetidh1;
  std::vector<uint32_t> alldetidh2;
  std::vector<uint32_t> alldetidh3;

  std::vector<std::vector<double> > startingtracksDX;
  std::vector<std::vector<double> > originaltracksDX;
  std::vector<std::vector<double> > startingtracksDY;
  std::vector<std::vector<double> > originaltracksDY;

  std::vector<std::vector<double> > startingtracksDXh0;
  std::vector<std::vector<double> > originaltracksDXh0;
  std::vector<std::vector<double> > startingtracksDYh0;
  std::vector<std::vector<double> > originaltracksDYh0;

  std::vector<std::vector<double> > startingtracksDXh1;
  std::vector<std::vector<double> > originaltracksDXh1;
  std::vector<std::vector<double> > startingtracksDYh1;
  std::vector<std::vector<double> > originaltracksDYh1;

  std::vector<std::vector<double> > startingtracksDXh2;
  std::vector<std::vector<double> > originaltracksDXh2;
  std::vector<std::vector<double> > startingtracksDYh2;
  std::vector<std::vector<double> > originaltracksDYh2;

  std::vector<std::vector<double> > startingtracksDXh3;
  std::vector<std::vector<double> > originaltracksDXh3;
  std::vector<std::vector<double> > startingtracksDYh3;
  std::vector<std::vector<double> > originaltracksDYh3;

  std::map<unsigned int,std::vector<long double> > QuartvsGlobAlignParamMAP;
  std::map<unsigned int,std::vector<long double> > QuartvsGlobAlignParamMAPBIS;
  
  
  std::vector<double> TotDXDispErrh0;
  std::vector<double> TotDYDispErrh0;
  std::vector<double> TotDXDispErrh1;
  std::vector<double> TotDYDispErrh1;
  std::vector<double> TotDXDispErrh2;
  std::vector<double> TotDYDispErrh2;
  std::vector<double> TotDXDispErrh3;
  std::vector<double> TotDYDispErrh3;

  std::vector<double> TotDXDisph0;
  std::vector<double> TotDYDisph0;
  std::vector<double> TotDXDisph1;
  std::vector<double> TotDYDisph1;
  std::vector<double> TotDXDisph2;
  std::vector<double> TotDYDisph2;
  std::vector<double> TotDXDisph3;
  std::vector<double> TotDYDisph3;

  

  std::vector<std::vector<T2Hit> > roadfitOverlapARM0;
  std::vector<std::vector<T2Hit> > roadfitOverlapARM1;
  double TotDXDispARM0Err;
  double TotDXDispARM1Err;
  double TotDXDispARM0;
  double TotDXDispARM1;  
  
  double TotDYDispARM0Err;
  double TotDYDispARM1Err;
  double TotDYDispARM0;
  double TotDYDispARM1; 

  std::vector<double> alldetZ;


  /*
  double VectGraphAlzdet[20];
  double VectGraphAlfinaldx[20];
  double VectGraphAlfinalEdx[20];
  double VectGraphAlfinaldy[20];
  double VectGraphAlfinalEdy[20];
  double VectGraphAlEZ[20];
  */
  double zdet[20];
  double finaldx[20];
  double finalEdx[20];
  double finaldy[20];
  double finalEdy[20];
  double EZ[20];

  



  // ALiGNMENT - End store results data










  // Begin of alignment  handles
  double HitXYResolError;
  unsigned int HitNumb4Align;
  double MeasuredResol_X;
  double MeasuredResol_Y;
  double RMaxOverlapYalign;
  double RMaxOverlapXalign;
  double RMaxOverlapXalignHisto;
  double RMaxOverlapYalignHisto;

  double HalfHalfMaxDispToleranceX;
  double HalfHalfMaxDispToleranceY;
  double HalfHalfMaxDispTolerance;
  double  SHIFTprescale;
  unsigned int MaxStepalignstep;
  std::vector<unsigned int>  Idreferencedet;
  std::vector<unsigned int>  IdreferencedetMille;
  std::vector<double> XreferencedetMille;
  std::vector<double> YreferencedetMille;
  std::vector<unsigned int>  IdreferencedetHIP;
  std::vector<double> XreferencedetHIP;
  std::vector<double> YreferencedetHIP;
 
  double centrograv;
  double  meanz;
  double AlignmentHitRMax;
  double AlignmentHitRMin;
  // int NumHitInTrk;
  bool DoInternalAlign;
  bool UseMillePede;
  bool UseMillePedeGlobal;
  bool DoAlignHalfHalf;
  double ratioXYAlignTrkcut;
  unsigned int UseJointProb;
  double FitgravcenterZ;
  unsigned int  useRZforResol;
  std::vector<unsigned int> SelectedHalfs;

  unsigned int HalfSelectedForPlot;
  unsigned int EffgoodhitnumberOverl; 
  double OverlapTrkHitRMax;
  double HighEtaForOverlapAlign;
  std::vector<unsigned int> RefHalfsWholeQuarterAlign;
  bool AllCorrectionAtSameTime;
  bool UseHistogramsForInternalError;
  bool CalculateErrorAsHIP;

  bool IncludeQuarterTiltAlign;
  bool UseGlobVertexForTiltCalulation;
  bool XYFitUsedinReco;
  std::vector<unsigned int> SelectedHalfsForTiltAlign;
  double AXToll, AYToll, X0Toll, Y0Toll;
  // End of alignment handles
  

  bool verbosity;

 // Begin of trk selection cut handles
  double MaxDphi;
  double maxdphihit;
  double maxdrhit; 
  double Effmaxdphihit; 
  double Effmaxdrhit; 


  unsigned int NumHitGood;
  unsigned int numevent;
  double Chicut;
  double FitdzEnergy;
  double DZScale;
  double tracketamin;
  double tracketamax;
  double PhiChiProbCut;
  double RChiProbCut;
  //  double Rwind;
  //double Phiwind;
  //int numhittrkeff;
  double chiRredCut,chiPhiredCut;

  bool UseHitErrorFromResol; 
  double DR_Resol_mm; 
  double DPhiResol_Deg;
  std::vector< std::pair <T1T2Track, T1T2Track> > PairsOfOvTrkArm0 ;
  unsigned int MaxPad, MaxStrip;
  unsigned int EffMaxPad, EffMaxStrip;
  double NoiseDphiMAX;
  double NoiseDrMAX;
  double AllowedDRTrackDistance;
  unsigned int  MaxEvents;
  unsigned int Effgoodhitnumber;
  std::string outputFileName, CluLabel, HitLabel, RoadLabel,TrackLabel;


 std::vector<unsigned int>  MillePedeExcludedPlaneH0;
 std::vector<unsigned int>  MillePedeExcludedPlaneH1;
 std::vector<unsigned int>  MillePedeExcludedPlaneH2;
 std::vector<unsigned int>  MillePedeExcludedPlaneH3;

 edm::InputTag T2PadDigiCollectionLabel;
  edm::InputTag T2StripDigiCollectionLabel;
  bool simufile;
  // End of trk selection cut handles

};

#endif // _TotemAlignmentT2T2TrkBasedInternalAlignment_H_
