//STANDARD ROOT INCLUDES
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TChainElement.h>
#include <TDirectory.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>

//OUR OWN CLASSES TO READ THE TREE
/*#include "UATree/UADataFormat/interface/MassParticles.h"
#include "UATree/UADataFormat/interface/MyBaseJet.h"
#include "UATree/UADataFormat/interface/MyBeamSpot.h"
#include "UATree/UADataFormat/interface/MyCaloJet.h"
#include "UATree/UADataFormat/interface/MyCastorDigi.h"
#include "UATree/UADataFormat/interface/MyCastorJet.h"
#include "UATree/UADataFormat/interface/MyCastorRecHit.h"
#include "UATree/UADataFormat/interface/MyDiJet.h"
#include "UATree/UADataFormat/interface/MyElectron.h"
#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyFwdGap.h"
#include "UATree/UADataFormat/interface/MyGenJet.h"
#include "UATree/UADataFormat/interface/MyGenKin.h"
#include "UATree/UADataFormat/interface/MyGenMet.h"
#include "UATree/UADataFormat/interface/MyGenPart.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"
#include "UATree/UADataFormat/interface/MyJet.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
//#include "MyMITEvtSel.h"
#include "UATree/UADataFormat/interface/MyMet.h"
#include "UATree/UADataFormat/interface/MyMuon.h"
#include "UATree/UADataFormat/interface/MyPFCand.h"
#include "UATree/UADataFormat/interface/MyPFJet.h"
#include "UATree/UADataFormat/interface/MyPUSumInfo.h"
#include "UATree/UADataFormat/interface/MyPart.h"
#include "UATree/UADataFormat/interface/MySimVertex.h"
#include "UATree/UADataFormat/interface/MyTracks.h"
#include "UATree/UADataFormat/interface/MyVertex.h"
#include "UATree/UADataFormat/interface/MyFSCHit.h"
#include "UATree/UADataFormat/interface/MyFSCDigi.h"
*/
#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"

// TOTEM data formats
/*#include "T1Event.h"
#include "T2Event.h"
#include "RPRootDumpReconstructedProton.h"
#include "RPRootDumpReconstructedProtonPair.h"
#include "RPRootDumpTrackInfo.h"
#include "RPRootDumpDigiInfo.h"
#include "RPRootDumpPatternInfo.h"*/

//#include "analysis_tools.h"
//#include "rp_aperture_config.h"

//STANDARD C++ INCLUDES
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

void analysis_CMSTOTEM_MC(vector<string> const& fileNames, string const& outputFileName, const Int_t nevt_max);

void analysis_CMSTOTEM_MC(string const& fileListName="filenames.txt", string const& outputFileName = "output.root", const Int_t nevt_max = 100){
   
   string file;
    
   ifstream infile( fileListName.c_str() );

   vector<string> fileNames; 
   while( infile >> file ) {
      cout << "Adding " << file << endl;
      fileNames.push_back( file ); 
   }
   infile.close();
 
   analysis_CMSTOTEM_MC(fileNames,outputFileName,nevt_max);
}

void analysis_CMSTOTEM_MC(vector<string> const& fileNames, string const& outputFileName = "output.root", const Int_t nevt_max = 100){
  
  bool isMC  = true;
  //bool useRPParam = false; 
  bool verbose = false;
  string treeName = (!isMC) ? "cms_totem" : "evt";

  double CMEnergy_ = 13000.;
  string jetCollName = "ak4PFJets";
  string jetCorrName = "ak4PFL2L3Residual";
  if(isMC) jetCorrName = "ak4PFL2L3"; 
  double ptJetMin = 20.0;
  double etaJetMax = 4.0;
  double etaMaxThreshold = 2.0;

  bool accessL1  = false; 
  bool accessHLT = false; 
  bool accessGen = true;

  //bool selectBunchCrossing = false;
  bool selectVertex = true;
  bool selectJets = false;
  //bool selectEtaMax = false;
  //bool selectEtaMin = false;
  //bool selectZeroHitsT2Plus = false;
  //bool selectZeroHitsT2Minus = false;
  bool selectSingleArmRecProton = false;
  bool selectDoubleArmRecProton = false;
  //bool selectElastic = false;
  //bool selectNonElastic = false;

  bool selectHLT = false; 
  bool selectHLTORorAND = true; // OR=true - AND=false
  vector<string> selectHLTPathNames;
  selectHLTPathNames.push_back("");
 
  //vector<int> bunchCrossingList;

  /*ThresholdsPerRegion thresholdsPFlow;
  thresholdsPFlow[Barrel] = ThresholdsPerType(); 
  thresholdsPFlow[Endcap] = ThresholdsPerType(); 
  thresholdsPFlow[Transition] = ThresholdsPerType(); 
  thresholdsPFlow[Endcap] = ThresholdsPerType(); 
  resetPFThresholds(thresholdsPFlow[Barrel]);
  resetPFThresholds(thresholdsPFlow[Endcap]);
  resetPFThresholds(thresholdsPFlow[Transition]);
  resetPFThresholds(thresholdsPFlow[Forward]);

  thresholdsPFlow[Barrel][MyPFCand::h0]            = make_pair(-1.,1.4);
  thresholdsPFlow[Barrel][MyPFCand::gamma]         = make_pair(-1.,0.9);
  thresholdsPFlow[Endcap][MyPFCand::h0]            = make_pair(-1.,2.7);
  thresholdsPFlow[Endcap][MyPFCand::gamma]         = make_pair(-1.,2.5);
  thresholdsPFlow[Transition][MyPFCand::h0]        = make_pair(-1.,3.8);
  thresholdsPFlow[Transition][MyPFCand::gamma]     = make_pair(-1.,2.5);
  thresholdsPFlow[Transition][MyPFCand::h_HF]      = make_pair(-1.,4.0);
  thresholdsPFlow[Transition][MyPFCand::egamma_HF] = make_pair(-1.,3.5);
  thresholdsPFlow[Forward][MyPFCand::h_HF]         = make_pair(-1.,4.0);
  thresholdsPFlow[Forward][MyPFCand::egamma_HF]    = make_pair(-1.,3.5);

  ThresholdsPerType::const_iterator pfThreshold = thresholdsPFlow[Barrel].begin();
  ThresholdsPerType::const_iterator pfThresholds_end = thresholdsPFlow[Barrel].end(); 
  ostringstream oss;
  oss << "Using the following PF thresholds:\n";
  for(; pfThreshold != pfThresholds_end; ++pfThreshold){
     int key = pfThreshold->first;    
     oss << "  " << key << ": "
                 << "(" << thresholdsPFlow[Barrel][key].first
                 << "," << thresholdsPFlow[Barrel][key].second << ")  "
                 << "(" << thresholdsPFlow[Endcap][key].first
                 << "," << thresholdsPFlow[Endcap][key].second << ")  "
                 << "(" << thresholdsPFlow[Transition][key].first
                 << "," << thresholdsPFlow[Transition][key].second << ")  "
                 << "(" << thresholdsPFlow[Forward][key].first
                 << "," << thresholdsPFlow[Forward][key].second << ")\n";   
  }
  cout << oss.str();*/
  //==============================
  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

  vector<string> hltPathNames;
  hltPathNames.push_back("");

  // Declaration of histograms
  map<string,TH1F*> histosTH1F;
  
  vector<string> selections;
  selections.push_back("All");
  /*selections.push_back("BunchCrossing");
  selections.push_back("HLT");
  selections.push_back("Vertex");
  selections.push_back("Jet");*/
  selections.push_back("SingleArmRPRight");
  selections.push_back("SingleArmRPLeft");
  selections.push_back("SingleArmRP");
  selections.push_back("DoubleArmRP");
  //selections.push_back("Elastic");
  //selections.push_back("NonElastic");
  int nBinsEventSelection = selections.size();
  histosTH1F["EventSelection"] = new TH1F("EventSelection","EventSelection",nBinsEventSelection,0,nBinsEventSelection);
  for(size_t k = 0; k < selections.size(); ++k)
     histosTH1F["EventSelection"]->GetXaxis()->SetBinLabel( (k + 1), selections[k].c_str() );

  histosTH1F["decisionPhysTrig"] = new TH1F("decisionPhysTrig", "decisionPhysTrig" , 128 , 0 , 128);
  histosTH1F["decisionTechTrig"] = new TH1F("decisionTechTrig", "decisionTechTrig" , 64 , 0 , 64);

  int nBinsHLT = hltPathNames.size(); 
  histosTH1F["hltTrigFired"] = new TH1F("hltTrigFired", "hltTrigFired" , nBinsHLT , 0 , nBinsHLT);
  for(size_t k = 0; k < (unsigned int) nBinsHLT; ++k) 
     histosTH1F["hltTrigFired"]->GetXaxis()->SetBinLabel( (k + 1), hltPathNames[k].c_str() );

  //histosTH1F["vtx_sumpt_max"] = new TH1F("vtx_sumpt_max", "vtx max sum(pT) index" , 30 , 0 , 30);

  histosTH1F["vtx_zpos"] = new TH1F("vtx_zpos", "z(vtx)" , 150 , -30. , 30.);
  histosTH1F["vtx_xpos"] = new TH1F("vtx_xpos", "x(vtx)" , 150 , -1.5 , 1.5);
  histosTH1F["vtx_ypos"] = new TH1F("vtx_ypos", "y(vtx)" , 150 , -1.5 , 1.5);
  histosTH1F["vtx_ndof"] = new TH1F("vtx_ndof", "ndof(vtx)" , 100 , 0. , 15.);
  histosTH1F["vtx_chi2"] = new TH1F("vtx_chi2", "chi2(vtx)" , 100 , 0. , 10.);

  histosTH1F["vertex_multiplicity"] = new TH1F("vertex_multiplicity", "n vertices" , 30 , 0 , 30);

  histosTH1F["prim_vtx_zpos"] = new TH1F("prim_vtx_zpos", "z(vtx)" , 150 , -30. , 30.);
  histosTH1F["prim_vtx_xpos"] = new TH1F("prim_vtx_xpos", "x(vtx)" , 150 , -1.5 , 1.5);
  histosTH1F["prim_vtx_ypos"] = new TH1F("prim_vtx_ypos", "y(vtx)" , 150 , -1.5 , 1.5);

  histosTH1F["prim_vtx_ndof"] = new TH1F("prim_vtx_ndof", "ndof(vtx)" , 100 , 0. , 15.);
  histosTH1F["prim_vtx_chi2"] = new TH1F("prim_vtx_chi2", "chi2(vtx)" , 100 , 0. , 10.);
  histosTH1F["prim_vtx_chi2n"] = new TH1F("prim_vtx_chi2n", "chi2n(vtx)" , 100 , 0. , 10.);
  histosTH1F["prim_vtx_ntracks"] = new TH1F("prim_vtx_ntracks", "n_{trk}(vtx)" , 30 , 0 , 30);
  histosTH1F["prim_vtx_sumpt"] = new TH1F("prim_vtx_sumpt", "sum(p_{T})(vtx)" , 100 , 0. , 100.);

  histosTH1F["track_pt"] = new TH1F("track_pt", "p_{T}(trk)" , 150 , 0. , 15.);
  histosTH1F["track_eta"] = new TH1F("track_eta", "#eta(trk)" , 200 , -5.2 , 5.2);
  histosTH1F["track_phi"] = new TH1F("track_phi", "#phi(trk)" , 200 , -M_PI , M_PI);
  histosTH1F["track_multiplicity"] = new TH1F("track_multiplicity", "n tracks" , 100 , 0 , 100);
  
  histosTH1F["jet_pt"] = new TH1F("jet_pt", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["jet_eta"] = new TH1F("jet_eta", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["jet_phi"] = new TH1F("jet_phi", "#phi(jet)" , 200 , -M_PI , M_PI);

  histosTH1F["leadingJet_pt"] = new TH1F("leadingJet_pt", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["leadingJet_eta"] = new TH1F("leadingJet_eta", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["leadingJet_phi"] = new TH1F("leadingJet_phi", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["leadingJet_jec"] = new TH1F("leadingJet_jec", "JEC" , 100 , 0. , 5.);
  histosTH1F["leadingJet_looseJetId"] = new TH1F("leadingJet_looseJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["leadingJet_tightJetId"] = new TH1F("leadingJet_tightJetId", "jet Id" , 2 , 0 , 2);

  histosTH1F["secondJet_pt"] = new TH1F("secondJet_pt", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["secondJet_eta"] = new TH1F("secondJet_eta", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["secondJet_phi"] = new TH1F("secondJet_phi", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["secondJet_jec"] = new TH1F("secondJet_jec", "JEC" , 100 , 0. , 5.);
  histosTH1F["secondJet_looseJetId"] = new TH1F("secondJet_looseJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["secondJet_tightJetId"] = new TH1F("secondJet_tightJetId", "jet Id" , 2 , 0 , 2);

  /*histosTH1F["pf_etaMax"] = new TH1F("pf_etaMax","#eta^{max}",82,etaBinsHCALBoundaries);
  histosTH1F["pf_etaMin"] = new TH1F("pf_etaMin","#eta^{min}",82,etaBinsHCALBoundaries);
  histosTH1F["pf_deltaEta"] = new TH1F("pf_deltaEta","#Delta#eta",100,0.,10.);
  histosTH1F["pf_EPlusPz"] = new TH1F("pf_EPlusPz","sum(E + pz)",24,binningEPlusPz);
  histosTH1F["pf_EMinusPz"] = new TH1F("pf_EMinusPz","sum(E - pz)",24,binningEPlusPz);
  histosTH1F["pf_xiPlus"] = new TH1F("pf_xiPlus","#xi^{+}",200,-1.,1.);
  histosTH1F["pf_xiMinus"] = new TH1F("pf_xiMinus","#xi^{-}",200,-1.,1.);
  histosTH1F["pf_logXiPlus"] = new TH1F("pf_logXiPlus","log(#xi^{+})",200,-5.,0.);
  histosTH1F["pf_logXiMinus"] = new TH1F("pf_logXiMinus","log(#xi^{-})",200,-5.,0.);*/

  histosTH1F["rp_track_posx_020"] = new TH1F("rp_track_posx_020", "x(RP track)" , 200, -10., 10.);
  histosTH1F["rp_track_posy_020"] = new TH1F("rp_track_posy_020", "y(RP track)" , 500, -50., 50.);

  histosTH1F["rp_track_posx_120"] = new TH1F("rp_track_posx_120", "x(RP track)" , 200, -10., 10.);
  histosTH1F["rp_track_posy_120"] = new TH1F("rp_track_posy_120", "y(RP track)" , 500, -50., 50.);

  histosTH1F["proton_right_xi"] = new TH1F("proton_right_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_right_logXi"] = new TH1F("proton_right_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_right_t"] = new TH1F("proton_right_t", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_left_xi"] = new TH1F("proton_left_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_left_logXi"] = new TH1F("proton_left_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_left_t"] = new TH1F("proton_left_t", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_pair_right_xi"] = new TH1F("proton_pair_right_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_pair_right_logXi"] = new TH1F("proton_pair_right_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_pair_right_t"] = new TH1F("proton_pair_right_t", "-t" , 200 , 0. , 5.);
  histosTH1F["proton_pair_left_xi"] = new TH1F("proton_pair_left_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_pair_left_logXi"] = new TH1F("proton_pair_left_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_pair_left_t"] = new TH1F("proton_pair_left_t", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_gen_plus_xi"] = new TH1F("proton_gen_plus_xi", "#xi" , 200 , 0. , 1.);
  histosTH1F["proton_gen_plus_logXi"] = new TH1F("proton_gen_plus_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_gen_plus_right_t"] = new TH1F("proton_gen_plus_t", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_gen_minus_xi"] = new TH1F("proton_gen_minus_xi", "#xi" , 200 , 0. , 1.);
  histosTH1F["proton_gen_minus_logXi"] = new TH1F("proton_gen_minus_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_gen_minus_right_t"] = new TH1F("proton_gen_minus_t", "-t" , 200 , 0. , 5.);

  histosTH1F["pf_xiPlus_minus_proton_left_xi"]   = new TH1F("pf_xiPlus_minus_proton_left_xi","",200,-1.,1.);
  histosTH1F["pf_xiMinus_minus_proton_right_xi"] = new TH1F("pf_xiMinus_minus_proton_right_xi","",200,-1.,1.);

  map<string,TH2F*> histosTH2F;

  histosTH2F["rp_track_pos_y_vs_x_020"] = new TH2F("rp_track_pos_y_vs_x_020", "y(RP track) vs x(RP track)" , 200, -10., 10., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_120"] = new TH2F("rp_track_pos_y_vs_x_120", "y(RP track) vs x(RP track)" , 200, -10., 10., 500, -50., 50.);

  double energyMin = -10.;
  double energyMax = 190.;
  int nBinsEnergy = 1000;
  /*histosTH2F["energyVsEtaAllTypes"]             = new TH2F("energyVsEtaAllTypes","energyVsEtaAllTypes",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaUndefined"]            = new TH2F("energyVsEtaUndefined","energyVsEtaUndefined",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaChargedHadron"]        = new TH2F("energyVsEtaChargedHadron","energyVsEtaChargedHadron",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaElectron"]             = new TH2F("energyVsEtaElectron","energyVsEtaElectron",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaMuon"]                 = new TH2F("energyVsEtaMuon","energyVsEtaMuon",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaGamma"]                = new TH2F("energyVsEtaGamma","energyVsEtaGamma",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaNeutralHadron"]        = new TH2F("energyVsEtaNeutralHadron","energyVsEtaNeutralHadron",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaHadronHF"]             = new TH2F("energyVsEtaHadronHF","energyVsEtaHadronHF",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaHadronHFEcalEnergy"]   = new TH2F("energyVsEtaHadronHFEcalEnergy","energyVsEtaHadronHFEcalEnergy",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaHadronHFNoEcalEnergy"] = new TH2F("energyVsEtaHadronHFNoEcalEnergy","energyVsEtaHadronHFNoEcalEnergy",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
  histosTH2F["energyVsEtaEGammaHF"]             = new TH2F("energyVsEtaEGammaHF","energyVsEtaEGammaHF",82,etaBinsHCALBoundaries,nBinsEnergy,energyMin,energyMax);
*/
  histosTH2F["proton_left_vs_gen_plus_logXi"]   = new TH2F("proton_left_vs_gen_plus_logXi", "" , 200, -5., 0., 200, -5., 0.);
  histosTH2F["proton_right_vs_gen_minus_logXi"] = new TH2F("proton_right_vs_gen_minus_logXi", "" , 200, -5., 0., 200, -5., 0.);

  histosTH2F["proton_rec_vs_sim_right_logXi"]   = new TH2F("proton_rec_vs_sim_right_logXi", "" , 200, -5., 0., 200, -5., 0.);
  histosTH2F["proton_rec_vs_sim_left_logXi"]    = new TH2F("proton_rec_vs_sim_left_logXi", "" , 200, -5., 0., 200, -5., 0.);

  histosTH2F["proton_sim_left_vs_gen_plus_logXi"]   = new TH2F("proton_sim_left_vs_gen_plus_logXi", "" , 200, -5., 0., 200, -5., 0.);
  histosTH2F["proton_sim_right_vs_gen_minus_logXi"] = new TH2F("proton_sim_right_vs_gen_minus_logXi", "" , 200, -5., 0., 200, -5., 0.);

  histosTH2F["proton_rec_vs_sim_right_t"]   = new TH2F("proton_rec_vs_sim_right_t", "" , 200, 0., 4., 200, 0., 4.);
  histosTH2F["proton_rec_vs_sim_left_t"]    = new TH2F("proton_rec_vs_sim_left_t", "" , 200, 0., 4., 200, 0., 4.);

  for(map<string,TH1F*>::const_iterator it = histosTH1F.begin(); it != histosTH1F.end(); ++it)
      it->second->Sumw2();
  for(map<string,TH2F*>::const_iterator it = histosTH2F.begin(); it != histosTH2F.end(); ++it)
      it->second->Sumw2();
  //===================

  //vector<TString>* vfiles = new vector<TString>(1,"merged_reduced_8372_198903_LP_Jets1_1_test_v1.root"); 
  vector<TString>* vfiles = new vector<TString>; 
  for(size_t idx_file = 0; idx_file < fileNames.size(); ++idx_file) vfiles->push_back( fileNames[idx_file] );
  
  // Declaration of tree and its branches variables
  TTree* tree = NULL;
/*  MyEvtId*           evtId         = NULL;
  MyL1TrigOld*       l1Trig        = NULL;  
  MyHLTrig*          hltTrig       = NULL;
  vector<MyTracks>*  track_coll    = NULL;
  vector<MyVertex>*  vertex_coll   = NULL;
  vector<MyPFJet>*   pfJet_coll    = NULL;
  vector<MyPFCand>*  pFlow_coll    = NULL;*/

  TotemRPEvent*      totemRP       = NULL; 
/*  vector<MyGenPart>* genPart       = NULL;
  MyGenKin*          genKin        = NULL;*/
  //===================
  
  //===================
  //===================
  //if(isMC && useRPParam) rp_aperture_config();
  //===================
  //===================

  int i_tot = 0 , nevt_tot = 0;
  //starting Loop over files, stops at end of list of files or when reached nevt_max
  for(vector<TString>::iterator itfiles = vfiles->begin() ; itfiles != vfiles->end() && i_tot < nevt_max_corr ; ++itfiles){
  
    cout << "Opening file " << *itfiles << endl;

    TFile* file = TFile::Open(*itfiles,"READ");
    
    // Access TTree from current file
    tree = (TTree*) file->Get( treeName.c_str() );

    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout <<"The current file has " << nev << " entries : "<< endl << *itfiles << endl;

    // Add branches to TTree ----------------------------------------------------------------------
 /*   tree->SetBranchAddress("evtId",&evtId);
    if(accessL1)  tree->SetBranchAddress("L1TrigOld",&l1Trig);
    if(accessHLT) tree->SetBranchAddress("HLTrig",&hltTrig);
    tree->SetBranchAddress("generalTracks",&track_coll); 
    tree->SetBranchAddress("offlinePrimaryVertices",&vertex_coll);
    tree->SetBranchAddress("ak4PFJets",&pfJet_coll);
    tree->SetBranchAddress("particleFlow",&pFlow_coll);

    if(accessGen) tree->SetBranchAddress("genKin",&genKin);
    if(accessGen) tree->SetBranchAddress("genPart",&genPart);*/
    //
    tree->SetBranchAddress("TotemRP",&totemRP);
    
    /*//Getting number of events
    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout <<"The current file has " << nev << " entries : "<< endl << *itfiles << endl;*/
  
    //starting loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0; i_evt < nev && i_tot < nevt_max_corr; ++i_evt , ++i_tot){
    
      //printing the % of events done every 10k evts
      if( ((i_tot+1) % 5000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
      //if( ((i_tot+1) % 100) == 0 ) cout << (i_tot+1) << " done" << endl;
    
      // Filling the variables defined setting branches
      tree->GetEntry(i_evt);

      //AT THIS POINT ON, CAN START USING THE VARIABLES LIKE TRACKS, VERTEX ETC !
      double event_weight = 1.;

      histosTH1F["EventSelection"]->Fill( "All", event_weight );

 /*     if(accessL1){
	 for (int itrig = 0 ; itrig < 128 ; ++itrig){
	    if( l1Trig->PhysTrigWord[itrig] == 1) 
	       histosTH1F["decisionPhysTrig"]->Fill( itrig, event_weight );
	 }

	 for (int itrig = 0 ; itrig < 64 ; ++itrig){
	    if( l1Trig->TechTrigWord[itrig] == 1 )
	       histosTH1F["decisionTechTrig"]->Fill( itrig, event_weight );
	 }
      }

      if(accessHLT){
	 map<string,bool>::iterator it_hlt = (*hltTrig).HLTmap.begin();
	 map<string,bool>::iterator it_hlt_end = (*hltTrig).HLTmap.end();
	 for(; it_hlt != it_hlt_end; ++it_hlt){
	    string const& hltName = it_hlt->first;
	    vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
	    if(it_pos != hltPathNames.end()){  */ //fim
	       /*size_t idx = it_pos - hltPathNames.begin();
		 if( it_hlt->second ) histosTH1F["hltTrigFired"]->Fill( idx, event_weight );*/
/*	       if( it_hlt->second ) histosTH1F["hltTrigFired"]->Fill( hltName.c_str(), event_weight );
	    }
	 }

	 if(selectHLT){
	    bool hlt_result = false;
	    for(vector<string>::const_iterator it_pathname_sel = selectHLTPathNames.begin();
		  it_pathname_sel != selectHLTPathNames.end(); ++it_pathname_sel){*/
	       /*bool accept = (*hltTrig).HLTmap[ *it_pathname_sel ];
		 if(accept) { select_HLT = true; break; }*/

/*	       if( it_pathname_sel == selectHLTPathNames.begin() ) hlt_result = selectHLTORorAND ? false : true;
	       bool accept = (*hltTrig).HLTmap[ *it_pathname_sel ];
	       if(selectHLTORorAND) hlt_result = hlt_result || accept;
	       else                 hlt_result = hlt_result && accept;
	    }
	    if(!hlt_result) continue;
	    histosTH1F["EventSelection"]->Fill( "HLT", event_weight );
	 }
      }*/
 
      //-------------------------------------------------------------------------------------------------
      //filling pt distribution for the generated particles
      //ie those from pythia generator, without reconstruction
      /*if(isMC){
        for(vector<MyGenPart>::iterator p=genPart->begin() ; p!=genPart->end() ; p++ )
          pt_gen->Fill(p->pt());
      }*/
      
     /* double xi_gen_plus = -1.;
      double xi_gen_minus = -1.;
      if(accessGen){
	 // Gen. Particles
	 double genEPlusPz = 0;
	 double genEMinusPz = 0;
	 double proton_pi = CMEnergy_/2;
	 double proton_pz_plus = -999.;
	 double proton_px_plus = -999.;
	 double proton_py_plus = -999.;
	 double proton_energy_plus = 0.;
	 double proton_pz_minus = -999.;
	 double proton_px_minus = -999.;
	 double proton_py_minus = -999.;
	 double proton_energy_minus = 0.;

         bool proton_plus_found = false; 
         bool proton_minus_found = false; 
	 for(vector<MyGenPart>::iterator it_genpart = genPart->begin();
	       it_genpart != genPart->end(); ++it_genpart){

	    double eta_gen = it_genpart->eta();
	    int status = it_genpart->status;
	    int id = it_genpart->pdgId;

	    if (status != 1) continue; // final state particles
	    double energy_gen = it_genpart->energy();
	    double px_gen = it_genpart->px();
	    double py_gen = it_genpart->py();
	    double pz_gen = it_genpart->pz();

	    genEPlusPz +=  (energy_gen + pz_gen);
	    genEMinusPz += (energy_gen - pz_gen);

	    if (id != 2212) continue; // select protons 

	    double proton_pf = sqrt(px_gen*px_gen+py_gen*py_gen+pz_gen*pz_gen);  
	    double pz_cut = 0.75*proton_pi;
	    if ( fabs(pz_gen) < pz_cut) continue;

	    if (pz_gen > proton_pz_plus)  { 
               proton_plus_found = true;
	       proton_pz_plus = pz_gen; proton_energy_plus = energy_gen; 
	       proton_px_plus = px_gen; proton_py_plus = py_gen;
	    } 
	    if (pz_gen < proton_pz_minus) { 
               proton_minus_found = true;
	       proton_pz_minus = pz_gen; proton_energy_minus = energy_gen; 
	       proton_px_minus = px_gen; proton_py_minus = py_gen;
	    } 
	 }
	 double xi_gen_plus_EPlusPz = genEPlusPz/CMEnergy_;
	 double xi_gen_minus_EPlusPz = genEMinusPz/CMEnergy_;

         xi_gen_plus  = (proton_plus_found) ? ( 1. - proton_pz_plus/proton_pi ) : -1.;
         xi_gen_minus = (proton_minus_found) ? ( 1. + proton_pz_minus/proton_pi ) : -1.;
         if(verbose) cout << "Xi+/- (gen.) = " << xi_gen_plus << " , " << xi_gen_minus << endl;
         histosTH1F["proton_gen_plus_xi"]->Fill( xi_gen_plus, event_weight );
         histosTH1F["proton_gen_minus_xi"]->Fill( xi_gen_minus, event_weight );
         histosTH1F["proton_gen_plus_logXi"]->Fill( log10(xi_gen_plus), event_weight );
         histosTH1F["proton_gen_minus_logXi"]->Fill( log10(xi_gen_minus), event_weight );
          
      }*/

      //-------------------------------------------------------------------------------------------------
      // Vertices
      //////int n_vertices_selected = 0;
      /*int idx_vtx_max_sumpt = -1;
      double sumpt_max = 0.;*/
     /* for(vector<MyVertex>::iterator it_vtx = vertex_coll->begin() ; it_vtx != vertex_coll->end() ; ++it_vtx){
         int idx_vtx = it_vtx - vertex_coll->begin();
         //if( it_vtx->SumPtTracks > sumpt_max ){ idx_vtx_max_sumpt = idx_vtx; sumpt_max = it_vtx->SumPtTracks; }

         if( it_vtx->fake ) continue;
         if( !it_vtx->validity ) continue;
         ++n_vertices_selected;

         histosTH1F["vtx_zpos"]->Fill( it_vtx->z, event_weight );
         histosTH1F["vtx_xpos"]->Fill( it_vtx->x, event_weight );
         histosTH1F["vtx_ypos"]->Fill( it_vtx->y, event_weight );
         histosTH1F["vtx_ndof"]->Fill( it_vtx->ndof, event_weight );
         histosTH1F["vtx_chi2"]->Fill( it_vtx->chi2, event_weight );
      }
      //histosTH1F["vtx_sumpt_max"]->Fill( idx_vtx_max_sumpt, event_weight );
      histosTH1F["vertex_multiplicity"]->Fill( n_vertices_selected, event_weight );

      //MyVertex const& primaryVertex = vertex_coll->at(0);
      MyVertex& primaryVertex = vertex_coll->at(0);
      histosTH1F["prim_vtx_zpos"]->Fill( primaryVertex.z, event_weight );
      histosTH1F["prim_vtx_xpos"]->Fill( primaryVertex.x, event_weight );
      histosTH1F["prim_vtx_ypos"]->Fill( primaryVertex.y, event_weight );
      
      histosTH1F["prim_vtx_ndof"]->Fill( primaryVertex.ndof, event_weight );
      histosTH1F["prim_vtx_chi2"]->Fill( primaryVertex.chi2, event_weight );
      histosTH1F["prim_vtx_chi2n"]->Fill( primaryVertex.chi2n(), event_weight );
      histosTH1F["prim_vtx_ntracks"]->Fill( primaryVertex.ntracks, event_weight );
      histosTH1F["prim_vtx_sumpt"]->Fill( primaryVertex.SumPtTracks, event_weight );

      double ndof_min = 0;
      double prim_vtx_r = sqrt( primaryVertex.x*primaryVertex.x + primaryVertex.y*primaryVertex.y );
      bool select_Vertex = ( !primaryVertex.fake && primaryVertex.validity &&
                              primaryVertex.ndof >= ndof_min && fabs( primaryVertex.z ) <= 24.0 && prim_vtx_r <= 2.0);
      if(selectVertex && !select_Vertex) continue;

      histosTH1F["EventSelection"]->Fill( "Vertex", event_weight );
*/
      // Tracks
  /*    int n_tracks_selected = 0;
      for(vector<MyTracks>::iterator it_trk = track_coll->begin() ; it_trk != track_coll->end() ; ++it_trk){
         histosTH1F["track_pt"]->Fill( it_trk->pt(), event_weight );
         histosTH1F["track_eta"]->Fill( it_trk->eta(), event_weight );
         histosTH1F["track_phi"]->Fill( it_trk->phi(), event_weight );

         if( it_trk->pt() < 0.5 ) continue;
         if( fabs( it_trk->eta() ) > 2.5 ) continue;
         if( ( it_trk->dz / it_trk->edz ) > 5. ) continue;
         if( ( it_trk->d0 / it_trk->ed0 ) > 5. ) continue;
 */   
         /*
         outtrack.quality[0] = intrack.quality(TrackBase::qualityByName("loose"));
         outtrack.quality[1] = intrack.quality(TrackBase::qualityByName("tight"));
         outtrack.quality[2] = intrack.quality(TrackBase::qualityByName("highPurity"));
         outtrack.quality[3] = intrack.quality(TrackBase::qualityByName("confirmed"));
         outtrack.quality[4] = intrack.quality(TrackBase::qualityByName("goodIterative"));
         */ 
   /*      if( !it_trk->quality[2] ) continue;

         ++n_tracks_selected;
      }
      histosTH1F["track_multiplicity"]->Fill( n_tracks_selected, event_weight );

      // Jets
      for(vector<MyPFJet>::iterator it_jet = pfJet_coll->begin() ; it_jet != pfJet_coll->end() ; ++it_jet){
         map<string,MyBaseJet>::iterator it_map = it_jet->mapjet.begin();
         for(; it_map != it_jet->mapjet.end(); ++it_map)
            if(verbose) cout << it_map->first << endl;

         MyBaseJet const& basejet = it_jet->mapjet[ jetCorrName ];
         histosTH1F["jet_pt"]->Fill( basejet.pt(), event_weight );
         if(basejet.pt() > 0.) histosTH1F["jet_eta"]->Fill( basejet.eta(), event_weight );
         histosTH1F["jet_phi"]->Fill( basejet.phi(), event_weight );
      }

      bool select_leadingJet = false;
      if( pfJet_coll->size() > 0 ){
	 MyBaseJet const& leadingJet = ( pfJet_coll->at(0) ).mapjet[ jetCorrName ];
	 histosTH1F["leadingJet_pt"]->Fill( leadingJet.pt(), event_weight );
	 if(leadingJet.pt() > 0.) histosTH1F["leadingJet_eta"]->Fill( leadingJet.eta(), event_weight );
	 histosTH1F["leadingJet_phi"]->Fill( leadingJet.phi(), event_weight );

         histosTH1F["leadingJet_jec"]->Fill( leadingJet.jec, event_weight );

         //bool looseJetId = ( pfJet_coll->at(0) ).LooseJetId;
         bool looseJetId = loosePFJetID(pfJet_coll->at(0),jetCollName);
         histosTH1F["leadingJet_looseJetId"]->Fill( looseJetId ? 1 : 0, event_weight );
         //bool tightJetId = ( pfJet_coll->at(0) ).TightJetId;
         bool tightJetId = tightPFJetID(pfJet_coll->at(0),jetCollName);
         histosTH1F["leadingJet_tightJetId"]->Fill( tightJetId ? 1 : 0, event_weight );

         select_leadingJet = (leadingJet.pt() >= ptJetMin && fabs(leadingJet.eta()) <= etaJetMax && looseJetId);
      }

      bool select_secondJet = false;
      if( pfJet_coll->size() > 1 ){
	 MyBaseJet const& secondJet = ( pfJet_coll->at(1) ).mapjet[ jetCorrName ];
	 histosTH1F["secondJet_pt"]->Fill( secondJet.pt(), event_weight );
	 if(secondJet.pt() > 0.) histosTH1F["secondJet_eta"]->Fill( secondJet.eta(), event_weight );
	 histosTH1F["secondJet_phi"]->Fill( secondJet.phi(), event_weight );

         histosTH1F["secondJet_jec"]->Fill( secondJet.jec, event_weight );

         //bool looseJetId = ( pfJet_coll->at(1) ).LooseJetId;
         bool looseJetId = loosePFJetID(pfJet_coll->at(1),jetCollName);
         histosTH1F["secondJet_looseJetId"]->Fill( looseJetId ? 1 : 0, event_weight );
         //bool tightJetId = ( pfJet_coll->at(1) ).TightJetId;
         bool tightJetId = tightPFJetID(pfJet_coll->at(1),jetCollName);
         histosTH1F["secondJet_tightJetId"]->Fill( tightJetId ? 1 : 0, event_weight );

         select_secondJet = (secondJet.pt() >= ptJetMin && fabs(secondJet.eta()) <= etaJetMax && looseJetId);
      }
      bool select_Jet = ( select_leadingJet && select_secondJet);
      if(selectJets && !select_Jet) continue;

      histosTH1F["EventSelection"]->Fill( "Jet", event_weight );

      // Particle-flow
      vector<MyPFCand> particles_sorted;
      double etaEdgeLow = -999.0;
      double etaEdgeHigh = 999.0;

      double pfEPlusPz = 0.;
      double pfEMinusPz = 0.;
      double xiCorrFactor = 1.0;
      for(vector<MyPFCand>::iterator it_pfcand = pFlow_coll->begin();
	                             it_pfcand != pFlow_coll->end(); ++it_pfcand){
	 int partType = it_pfcand->particleId;
	 double eta = it_pfcand->eta();
	 double energy = it_pfcand->energy();
	 double pz = it_pfcand->pz();

	 histosTH2F["energyVsEtaAllTypes"]->Fill( eta, energy, event_weight );

	 if(partType == MyPFCand::X)
	    histosTH2F["energyVsEtaUndefined"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::h)
	    histosTH2F["energyVsEtaChargedHadron"]->Fill( eta, energy, event_weight ); 
	 else if(partType == MyPFCand::e) 
	    histosTH2F["energyVsEtaElectron"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::mu) 
	    histosTH2F["energyVsEtaMuon"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::gamma) 
	    histosTH2F["energyVsEtaGamma"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::h0) 
	    histosTH2F["energyVsEtaNeutralHadron"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::h_HF)
	    histosTH2F["energyVsEtaHadronHF"]->Fill( eta, energy, event_weight );
	 else if(partType == MyPFCand::egamma_HF) 
	    histosTH2F["energyVsEtaEGammaHF"]->Fill( eta, energy, event_weight );

         // Apply thresholds
         if( !pflowThreshold(*it_pfcand,thresholdsPFlow) ) continue;

         if( eta >= etaEdgeLow && eta <= etaEdgeHigh ) particles_sorted.push_back(*it_pfcand);
         pfEPlusPz  += energy + pz;
         pfEMinusPz += energy - pz;
      }
      // Xi (CMS)
      double pfXiPlusReco = xiCorrFactor*pfEPlusPz/CMEnergy_;
      double pfXiMinusReco = xiCorrFactor*pfEMinusPz/CMEnergy_;

      // Find eta_min & eta_max
      double pfEtaMin = -999.;
      double pfEtaMax = 999.;
      if( particles_sorted.size() > 0 ){
	 std::stable_sort(particles_sorted.begin(), particles_sorted.end(), sortByEta);
	 pfEtaMin = particles_sorted.at(0).Eta();
	 pfEtaMax = particles_sorted.at(particles_sorted.size() - 1).Eta();
      }

      histosTH1F["pf_etaMax"]->Fill( pfEtaMax, event_weight ); 
      histosTH1F["pf_etaMin"]->Fill( pfEtaMin, event_weight );

      double pfDeltaEta = pfEtaMax - pfEtaMin;
      histosTH1F["pf_deltaEta"]->Fill( pfDeltaEta, event_weight ); 

      histosTH1F["pf_EPlusPz"]->Fill( pfEPlusPz, event_weight );
      histosTH1F["pf_EMinusPz"]->Fill( pfEMinusPz, event_weight );
      histosTH1F["pf_xiPlus"]->Fill( pfXiPlusReco, event_weight );
      histosTH1F["pf_xiMinus"]->Fill( pfXiMinusReco, event_weight );
      histosTH1F["pf_logXiPlus"]->Fill( log10(pfXiPlusReco), event_weight );
      histosTH1F["pf_logXiMinus"]->Fill( log10(pfXiMinusReco), event_weight );
*/
      /*if( selectEtaMax && (pfEtaMax > etaMaxThreshold) ) continue;
      histosTH1F["EventSelection"]->Fill( "EtaMax", event_weight );

      if( selectEtaMin && (pfEtaMin < -etaMaxThreshold) ) continue;
      histosTH1F["EventSelection"]->Fill( "EtaMin", event_weight );*/

      bool proton_right_valid = false;
      bool proton_left_valid = false;
      RPRootDumpReconstructedProton const& rec_proton_right = totemRP->rec_pr_info_.at(1);
      RPRootDumpReconstructedProton const& rec_proton_left = totemRP->rec_pr_info_.at(0);
      proton_right_valid = rec_proton_right.valid;
      proton_left_valid = rec_proton_left.valid;
      if(proton_right_valid){
          histosTH1F["EventSelection"]->Fill( "SingleArmRPRight", event_weight );
      }else if(proton_left_valid){
          histosTH1F["EventSelection"]->Fill( "SingleArmRPLeft", event_weight );
      }
      if( selectSingleArmRecProton ){
//         if( proton_right_valid && proton_left_valid) continue;
         if( proton_right_valid ||  proton_left_valid){
         histosTH1F["EventSelection"]->Fill( "SingleArmRP", event_weight );
      }
}

      if( selectDoubleArmRecProton ){
         if( !(proton_right_valid && proton_left_valid) ) continue;
         histosTH1F["EventSelection"]->Fill( "DoubleArmRP", event_weight );
      }

      //bool tag_elastic_top45_bot56 = elastic_top45_bot56(rp_track_info);      
      //bool tag_elastic_bot45_top56 = elastic_bot45_top56(rp_track_info);      
      //if( selectElastic && !(tag_elastic_top45_bot56 || tag_elastic_bot45_top56) ) continue;
      //histosTH1F["EventSelection"]->Fill( "Elastic", event_weight );
      //
      //if( selectNonElastic && (tag_elastic_top45_bot56 || tag_elastic_bot45_top56) ) continue;
      //histosTH1F["EventSelection"]->Fill( "NonElastic", event_weight );

      // RP protons
      std::map<unsigned int, RPRootDumpTrackInfo> const& rp_track_info = totemRP->track_info_; 
      RPRootDumpTrackInfo const& rp_track_info_020 = rp_track_info.at(20);
      RPRootDumpTrackInfo const& rp_track_info_120 = rp_track_info.at(120);

      bool rp_track_valid_020 = rp_track_info_020.valid;
      if( rp_track_valid_020 ){
	 double rp_track_posx_020 = rp_track_info_020.x;
	 double rp_track_posy_020 = rp_track_info_020.y;
	 histosTH1F["rp_track_posx_020"]->Fill( rp_track_posx_020, event_weight );
	 histosTH1F["rp_track_posy_020"]->Fill( rp_track_posy_020, event_weight );
	 histosTH2F["rp_track_pos_y_vs_x_020"]->Fill( rp_track_posx_020, rp_track_posy_020, event_weight );
      }

      bool rp_track_valid_120 = rp_track_info_120.valid;
      if( rp_track_valid_120 ){
	 double rp_track_posx_120 = rp_track_info_120.x;
	 double rp_track_posy_120 = rp_track_info_120.y;
	 histosTH1F["rp_track_posx_120"]->Fill( rp_track_posx_120, event_weight );
	 histosTH1F["rp_track_posy_120"]->Fill( rp_track_posy_120, event_weight );
	 histosTH2F["rp_track_pos_y_vs_x_120"]->Fill( rp_track_posx_120, rp_track_posy_120, event_weight );
      }

      RPRootDumpReconstructedProton const& sim_proton_right = totemRP->sim_pr_info_.at(1);
      RPRootDumpReconstructedProton const& sim_proton_left  = totemRP->sim_pr_info_.at(0);
      bool proton_sim_right_valid = sim_proton_right.valid;
      bool proton_sim_left_valid  = sim_proton_left.valid;
if( proton_right_valid ||  proton_left_valid){    
      double xi_proton_right = rec_proton_right.xi;
      double t_proton_right = rec_proton_right.t;
      bool good_proton_right = proton_right_valid && (xi_proton_right < 0.1);
      if( good_proton_right ){
	 histosTH1F["proton_right_xi"]->Fill( -xi_proton_right, event_weight );
	 histosTH1F["proton_right_t"]->Fill( -t_proton_right, event_weight );

	 if(-xi_proton_right > 0.1){
	    xi_proton_right = -xi_proton_right;
	    t_proton_right  = -t_proton_right;
	    histosTH1F["proton_right_logXi"]->Fill( log10(xi_proton_right), event_weight );

            //histosTH1F["pf_xiMinus_minus_proton_right_xi"]->Fill( pfXiMinusReco - xi_proton_right );

            double xi_proton_sim_right = -1.; 
            double t_proton_sim_right  = -999.; 
            if(proton_sim_right_valid){
               xi_proton_sim_right = -sim_proton_right.xi;
               t_proton_sim_right  = -sim_proton_right.t;
	       histosTH2F["proton_rec_vs_sim_right_logXi"]->Fill( log10(xi_proton_sim_right), log10(xi_proton_right), event_weight );
	       histosTH2F["proton_rec_vs_sim_right_t"]->Fill( t_proton_sim_right, t_proton_right, event_weight );
            }
            /*if( accessGen && xi_gen_minus > 0. ){
               histosTH2F["proton_right_vs_gen_minus_logXi"]->Fill( log10(xi_gen_minus), log10(xi_proton_right), event_weight );
               if(proton_sim_right_valid)
		  histosTH2F["proton_sim_right_vs_gen_minus_logXi"]->Fill( log10(xi_gen_minus), log10(xi_proton_sim_right), event_weight );
            }*/
	 }
      }

      double xi_proton_left = rec_proton_left.xi;
      double t_proton_left = rec_proton_left.t;
      bool good_proton_left = proton_left_valid && (xi_proton_left < 0.1);
      if( good_proton_left ){
	 histosTH1F["proton_left_xi"]->Fill( -xi_proton_left, event_weight );
	 histosTH1F["proton_left_t"]->Fill( -t_proton_left, event_weight );

	 if(-xi_proton_left > 0.1){
	    xi_proton_left = -xi_proton_left;
	    t_proton_left  = -t_proton_left;
	    histosTH1F["proton_left_logXi"]->Fill( log10(xi_proton_left), event_weight );

       //     histosTH1F["pf_xiPlus_minus_proton_left_xi"]->Fill( pfXiPlusReco - xi_proton_left );

            double xi_proton_sim_left = -1.; 
            double t_proton_sim_left  = -999.; 
            if(proton_sim_left_valid){
               xi_proton_sim_left = -sim_proton_left.xi;
               t_proton_sim_left  = -sim_proton_left.t;
	       histosTH2F["proton_rec_vs_sim_left_logXi"]->Fill( log10(xi_proton_sim_left), log10(xi_proton_left), event_weight );
	       histosTH2F["proton_rec_vs_sim_left_t"]->Fill( t_proton_sim_left, t_proton_left, event_weight );
            }
         /*   if( accessGen && xi_gen_plus > 0. ){
               histosTH2F["proton_left_vs_gen_plus_logXi"]->Fill( log10(xi_gen_plus), log10(xi_proton_left), event_weight );
               if(proton_sim_left_valid){
		  double xi_proton_sim_left = -sim_proton_left.xi;
		  histosTH2F["proton_sim_left_vs_gen_plus_logXi"]->Fill( log10(xi_gen_plus), log10(xi_proton_sim_left), event_weight );
               }
            }*/
	 }
      }
}
      //-------------------
      // After selection 
      //-------------------
      //...


    } // End of loop over events in a file
    
    // Close current file
    file->Close();
    
  } // End of loop over files
  
  
  // Output file
  TFile* output = new TFile(outputFileName.c_str(),"RECREATE");
  output->cd();
  
  for(map<string,TH1F*>::iterator it_histo = histosTH1F.begin();
                                  it_histo != histosTH1F.end(); ++it_histo)
     (*it_histo).second->Write();
  for(map<string,TH2F*>::iterator it_histo = histosTH2F.begin();
                                  it_histo != histosTH2F.end(); ++it_histo)
     (*it_histo).second->Write();

  output->Close();
}
