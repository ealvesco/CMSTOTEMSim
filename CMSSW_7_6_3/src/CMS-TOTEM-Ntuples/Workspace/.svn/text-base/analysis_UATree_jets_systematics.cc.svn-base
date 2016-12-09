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

//OUR OWN CLASSES TO READ THE TREE
#include "MassParticles.h"
#include "MyBaseJet.h"
#include "MyBeamSpot.h"
#include "MyCaloJet.h"
#include "MyCastorDigi.h"
#include "MyCastorJet.h"
#include "MyCastorRecHit.h"
#include "MyDiJet.h"
#include "MyElectron.h"
#include "MyEvtId.h"
#include "MyFwdGap.h"
#include "MyGenJet.h"
#include "MyGenKin.h"
#include "MyGenMet.h"
#include "MyGenPart.h"
#include "MyHLTrig.h"
#include "MyJet.h"
#include "MyL1Trig.h"
#include "MyL1TrigOld.h"
//#include "MyMITEvtSel.h"
#include "MyMet.h"
#include "MyMuon.h"
#include "MyPFCand.h"
#include "MyPFJet.h"
#include "MyPUSumInfo.h"
#include "MyPart.h"
#include "MySimVertex.h"
#include "MyTracks.h"
#include "MyVertex.h"
#include "MyFSCHit.h"
#include "MyFSCDigi.h"

// TOTEM data formats
#include "T1Event.h"
#include "T2Event.h"
#include "RPRootDumpReconstructedProton.h"
#include "RPRootDumpReconstructedProtonPair.h"
#include "RPRootDumpTrackInfo.h"
#include "RPRootDumpDigiInfo.h"
#include "RPRootDumpPatternInfo.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

#include "analysis_tools.h"
//#include "rp_aperture_config.h"

//STANDARD C++ INCLUDES
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

void analysis_UATree_jets(vector<string> const& fileNames, string const& outputFileName = "output.root", const Int_t nevt_max = 100){
  
  bool isMC  = false;
  bool verbose = false;
  string treeName = (!isMC) ? "cms_totem" : "evt";
  string jetCollName = "ak5PFJets";
  string jetCorrName = "ak5PFL2L3Residual";
  if(isMC) jetCorrName = "ak5PFL2L3"; 
  double ptJetMin = 30.0;
  double etaJetMax = 4.0;
  double etaMaxThreshold = 2.0;

  bool selectBunchCrossing = false;
  bool selectVertex = true;
  bool selectJets = true;
  bool selectEtaMax = false;
  bool selectEtaMin = false;
  bool selectZeroHitsT2Plus = false;
  bool selectZeroHitsT2Minus = false;
  bool selectSingleArmRecProton = true;
  bool selectDoubleArmRecProton = false;
  bool selectElastic = false;
  bool selectNonElastic = false;
  bool selectRPProton = true;
  
  // MC
  bool selectRPPlusAccept = true;
  bool selectRPMinusAccept = false;

  bool selectHLTORorAND = true; // OR=true - AND=false
  vector<string> selectHLTPathNames;
  selectHLTPathNames.push_back("HLT_L1DoubleJet20part1_v1");
  selectHLTPathNames.push_back("HLT_L1DoubleJet20part2_v1");
  //selectHLTPathNames.push_back("HLT_L1Tech53_MB_1_v1");
  //selectHLTPathNames.push_back("HLT_L1Tech53_MB_2_v1");
  //selectHLTPathNames.push_back("HLT_L1Tech53_MB_3_v1");
  //selectHLTPathNames.push_back("HLT_ZeroBias_v7");
  //selectHLTPathNames.push_back("HLT_RomanPots_Tech52_v1");
 
  vector<int> bunchCrossingList;
  bunchCrossingList.push_back(27);
  bunchCrossingList.push_back(649);
  bunchCrossingList.push_back(2991);

  ThresholdsPerRegion thresholdsPFlow;
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
  cout << oss.str();
  //==============================
  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

  vector<string> hltPathNames;
  hltPathNames.push_back("HLT_L1DoubleEG3_FwdVeto_v1");
  hltPathNames.push_back("HLT_L1DoubleMu0_v1");
  hltPathNames.push_back("HLT_L1DoubleJet20_RomanPotsOR_v1");
  hltPathNames.push_back("HLT_L1DoubleJet20part1_v1");
  hltPathNames.push_back("HLT_L1DoubleJet24_v1");
  hltPathNames.push_back("HLT_L1DoubleJet20part2_v1");
  hltPathNames.push_back("HLT_L1Tech40_BPTXAND_v1");
  hltPathNames.push_back("HLT_L1Tech53_MB_1_v1");
  hltPathNames.push_back("HLT_L1Tech_HF9OR10_v1");
  hltPathNames.push_back("HLT_T1minbias_Tech55_v1");
  hltPathNames.push_back("HLT_L1Tech53_MB_2_v1");
  hltPathNames.push_back("HLT_L1Tech53_MB_3_v1");
  hltPathNames.push_back("HLT_RomanPots_Tech52_v1");
  hltPathNames.push_back("HLT_L1Tech54_ZeroBias_v1");
  hltPathNames.push_back("HLT_ZeroBias_v7");

  // Declaration of histograms
  map<string,TH1F*> histosTH1F;
  map<string,TH2F*> histosTH2F;
  
  vector<string> selections;
  selections.push_back("All");
  selections.push_back("BunchCrossing");
  selections.push_back("HLT");
  selections.push_back("Vertex");
  selections.push_back("Jet");
  selections.push_back("EtaMax");
  selections.push_back("EtaMin");
  selections.push_back("ZeroHitsT2Plus");
  selections.push_back("ZeroHitsT2Minus");
  selections.push_back("SingleArmRP");
  selections.push_back("DoubleArmRP");
  selections.push_back("Elastic");
  selections.push_back("NonElastic");
  selections.push_back("RPProton");
  selections.push_back("MCRPPlusAccept");
  selections.push_back("MCRPMinusAccept");
  int nBinsEventSelection = selections.size();
  histosTH1F["EventSelection"] = new TH1F("EventSelection","EventSelection",nBinsEventSelection,0,nBinsEventSelection);
  for(size_t k = 0; k < selections.size(); ++k)
     histosTH1F["EventSelection"]->GetXaxis()->SetBinLabel( (k + 1), selections[k].c_str() );

  //histosTH1F["bunchCrossingNumber"] = new TH1F("bunchCrossingNumber", "bunchCrossingNumber" , 3900 , 0 , 3900);

  histosTH1F["decisionPhysTrig"] = new TH1F("decisionPhysTrig", "decisionPhysTrig" , 128 , 0 , 128);
  histosTH1F["decisionTechTrig"] = new TH1F("decisionTechTrig", "decisionTechTrig" , 64 , 0 , 64);

  int nBinsHLT = hltPathNames.size(); 
  histosTH1F["hltTrigFired"] = new TH1F("hltTrigFired", "hltTrigFired" , nBinsHLT , 0 , nBinsHLT);
  for(int k = 0; k < nBinsHLT; ++k) 
     histosTH1F["hltTrigFired"]->GetXaxis()->SetBinLabel( (k + 1), hltPathNames[k].c_str() );

  histosTH1F["leadingJet_pt"] = new TH1F("leadingJet_pt", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["leadingJet_pt_unc_up"] = new TH1F("leadingJet_pt_unc_up", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["leadingJet_pt_unc_dw"] = new TH1F("leadingJet_pt_unc_dw", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["leadingJet_eta"] = new TH1F("leadingJet_eta", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["leadingJet_phi"] = new TH1F("leadingJet_phi", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["leadingJet_jec"] = new TH1F("leadingJet_jec", "JEC" , 100 , 0. , 5.);
  histosTH1F["leadingJet_looseJetId"] = new TH1F("leadingJet_looseJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["leadingJet_tightJetId"] = new TH1F("leadingJet_tightJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["leadingJet_pt_after_jet_sel"] = new TH1F("leadingJet_pt_after_jet_sel", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["leadingJet_eta_after_jet_sel"] = new TH1F("leadingJet_eta_after_jet_sel", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["leadingJet_phi_after_jet_sel"] = new TH1F("leadingJet_phi_after_jet_sel", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["leadingJet_jec_after_jet_sel"] = new TH1F("leadingJet_jec_after_jet_sel", "JEC" , 100 , 0. , 5.);

  histosTH1F["secondJet_pt"] = new TH1F("secondJet_pt", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["secondJet_eta"] = new TH1F("secondJet_eta", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["secondJet_phi"] = new TH1F("secondJet_phi", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["secondJet_jec"] = new TH1F("secondJet_jec", "JEC" , 100 , 0. , 5.);
  histosTH1F["secondJet_looseJetId"] = new TH1F("secondJet_looseJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["secondJet_tightJetId"] = new TH1F("secondJet_tightJetId", "jet Id" , 2 , 0 , 2);
  histosTH1F["secondJet_pt_after_jet_sel"] = new TH1F("secondJet_pt_after_jet_sel", "p_{T}(jet)" , 150 , 0. , 150.);
  histosTH1F["secondJet_eta_after_jet_sel"] = new TH1F("secondJet_eta_after_jet_sel", "#eta(jet)" , 200 , -5.2 , 5.2);
  histosTH1F["secondJet_phi_after_jet_sel"] = new TH1F("secondJet_phi_after_jet_sel", "#phi(jet)" , 200 , -M_PI , M_PI);
  histosTH1F["secondJet_jec_after_jet_sel"] = new TH1F("secondJet_jec_after_jet_sel", "JEC" , 100 , 0. , 5.);

  histosTH1F["proton_right_xi"] = new TH1F("proton_right_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_right_logXi"] = new TH1F("proton_right_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_right_t"] = new TH1F("proton_right_t", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_left_xi"] = new TH1F("proton_left_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_left_logXi"] = new TH1F("proton_left_logXi","log(#xi)",200,-5.,0.);
  histosTH1F["proton_left_t"] = new TH1F("proton_left_t", "-t" , 200 , 0. , 5.);

  float ximin = 0.03, ximax = 0.1;
  float tmin = 0.0, tmax = 1.0;
  float binning_t[] = {0.03, 0.1, 0.2, 0.4, 1.0};
  histosTH1F["proton_right_xi_selected"] = new TH1F("proton_right_xi_selected", "#xi" , 5 , ximin , ximax);
  //histosTH1F["proton_right_t_selected"] = new TH1F("proton_right_t_selected", "-t" , 5 , tmin , tmax);
  histosTH1F["proton_right_t_selected"] = new TH1F("proton_right_t_selected", "-t" , 4 , binning_t);

  histosTH1F["proton_left_xi_selected"] = new TH1F("proton_left_xi_selected", "#xi" , 5 , ximin , ximax);
  //histosTH1F["proton_left_t_selected"] = new TH1F("proton_left_t_selected", "-t" , 5 , tmin , tmax);
  histosTH1F["proton_left_t_selected"] = new TH1F("proton_left_t_selected", "-t" , 4 , binning_t);

  for(map<string,TH1F*>::const_iterator it = histosTH1F.begin(); it != histosTH1F.end(); ++it)
      it->second->Sumw2();
  for(map<string,TH2F*>::const_iterator it = histosTH2F.begin(); it != histosTH2F.end(); ++it)
      it->second->Sumw2();
  //===================

  //vector<TString>* vfiles = new vector<TString>(1,"merged_reduced_8372_198903_LP_Jets1_1_test_v1.root"); 
  vector<TString>* vfiles = new vector<TString>; 
  //vfiles->push_back( fileName ); 
  for(size_t idx_file = 0; idx_file < fileNames.size(); ++idx_file) vfiles->push_back( fileNames[idx_file] );
  
  //Declaration of tree and its branches variables
  //TTree* tree = new TTree(treeName.c_str(),"");
  TTree* tree = NULL;
  MyEvtId*           evtId         = NULL;
  MyL1TrigOld*       l1Trig        = NULL;  
  MyHLTrig*          hltTrig       = NULL;
  vector<MyTracks>*  track_coll    = NULL;
  vector<MyVertex>*  vertex_coll   = NULL;
  vector<MyPFJet>*   pfJet_coll    = NULL;
  vector<MyPFCand>*  pFlow_coll    = NULL;
  vector<MyFSCHit>*  fscHits_coll  = NULL;
  vector<MyFSCDigi>* fscDigis_coll = NULL;

  vector<MyGenPart>* genPart       = NULL;
  MyGenKin*          genKin        = NULL;
  //===================
  T2Event* t2_event = NULL; 
  RPRootDumpReconstructedProton* rec_proton_left  = NULL;
  RPRootDumpReconstructedProton* rec_proton_right = NULL;
  RPRootDumpReconstructedProtonPair* rec_proton_pair  = NULL;
  map<unsigned int, RPRootDumpTrackInfo*> rp_track_info;
  map<unsigned int, RPRootDumpDigiInfo*> rp_digi_info;
  map<unsigned int, RPRootDumpPatternInfo*> rp_par_patterns_info;
  map<unsigned int, RPRootDumpPatternInfo*> rp_nonpar_patterns_info;
  map<unsigned int, std::vector<RPRootDumpTrackInfo>*> rp_multi_track_info;
  //===================
  
  //===================
  //===================
  //if(isMC) rp_aperture_config();
  //===================
  //===================

  //===================
  //===================
  // Instantiate JES uncertainty sources
  //const int nsrc = 19;//16;
  //const char* srcnames[nsrc] =
  //{"Absolute", "HighPtExtra", /*"SinglePion",*/ "SinglePionECAL"/*new*/, "SinglePionHCAL"/*new*/,
  // "Flavor", "Time",
  // "RelativeJEREC1", "RelativeJEREC2", "RelativeJERHF",
  // "RelativePtEC1"/*new*/, "RelativePtEC2"/*new*/, "RelativePtHF"/*new*/,
  // "RelativeStatEC2", "RelativeStatHF", /*"RelativeFSR",*/ /*"RelativeSample",*/ /*new*/
  // "PileUpDataMC", /*"PileUpOOT",*/ "PileUpBias", /*"PileUpJetRate"*/
  // /*"PileUpPt",*/ "PileUpPtBB"/*new*/, "PileUpPtEC"/*new*/, "PileUpPtHF"/*new*/};
   
  const int n_jec_unc_src = 12;
  const char* jec_unc_srcnames[n_jec_unc_src] = {"Absolute", "HighPtExtra", "Flavor", "Time", 
                                         "RelativeJEREC1", "RelativeJEREC2", "RelativeJERHF",
                                         "RelativePtEC1"/*new*/, "RelativePtEC2"/*new*/, "RelativePtHF"/*new*/,
                                         "RelativeStatEC2", "RelativeStatHF"};
  std::vector<JetCorrectionUncertainty*> jec_unc_src(n_jec_unc_src);

  for (int isrc = 0; isrc < n_jec_unc_src; isrc++) {

     const char *name = jec_unc_srcnames[isrc];
     JetCorrectorParameters *p = new JetCorrectorParameters("jes_uncertainty/txt/Fall12_V7_DATA_UncertaintySources_AK5PF.txt", name);
     JetCorrectionUncertainty *unc = new JetCorrectionUncertainty(*p);
     jec_unc_src[isrc] = unc;
  } // for isrc

  // Total uncertainty for reference
  JetCorrectionUncertainty *jec_unc_total = new JetCorrectionUncertainty(*(new JetCorrectorParameters("jes_uncertainty/txt/Fall12_V7_DATA_UncertaintySources_AK5PF.txt", "Total")));
  //===================
  //===================

  int i_tot = 0 , nevt_tot = 0;
  //starting Loop over files, stops at end of list of files or when reached nevt_max
  for(vector<TString>::iterator itfiles = vfiles->begin() ; itfiles != vfiles->end() && i_tot < nevt_max_corr ; ++itfiles){
  
    TFile* file = TFile::Open(*itfiles,"READ");
    
    // Access TTree from current file
    tree = (TTree*) file->Get( treeName.c_str() );

    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout <<"The current file has " << nev << " entries : "<< endl << *itfiles << endl;

    // Add branches to TTree ----------------------------------------------------------------------
    if(isMC){
       tree->SetBranchAddress("evtId",&evtId);
       //tree->SetBranchAddress("L1TrigOld",&l1Trig);
       //tree->SetBranchAddress("HLTrig",&hltTrig);
       tree->SetBranchAddress("generalTracks",&track_coll); 
       tree->SetBranchAddress("offlinePrimaryVertices",&vertex_coll);
       tree->SetBranchAddress("ak5PFJets",&pfJet_coll);
       tree->SetBranchAddress("particleFlow",&pFlow_coll);

       tree->SetBranchAddress("genKin",&genKin);
       tree->SetBranchAddress("genPart",&genPart);
    } else{   
       tree->SetBranchAddress("cmsEvtUA",&evtId);
       tree->SetBranchAddress("cmsTrigUA",&l1Trig);
       tree->SetBranchAddress("cmsHLTTrigUA",&hltTrig);
       tree->SetBranchAddress("cmsTracksUA",&track_coll); 
       tree->SetBranchAddress("cmsVerticesUA",&vertex_coll);
       //tree->SetBranchAddress("cmsPFJetsUA",&pfJet_coll);
       tree->SetBranchAddress("cmsak5PFJetsUA",&pfJet_coll);
       tree->SetBranchAddress("cmsParticleFlowUA",&pFlow_coll);
       //tree->SetBranchAddress("cmsFSCHitsUA",&fscHits_coll);
       //tree->SetBranchAddress("cmsFSCDigisUA",&fscDigis_coll);
       tree->SetBranchAddress("branchT2EV.",&t2_event);
       tree->SetBranchAddress("rec_prot_left.",&rec_proton_left);
       tree->SetBranchAddress("rec_prot_right.",&rec_proton_right);
       tree->SetBranchAddress("rec_prot_pair.",&rec_proton_pair);
       /*//rp_track_info[20] = NULL;
	 tree->SetBranchAddress("track_rp_20.", &rp_track_info[20]);*/
       std::vector<unsigned int> rp_list;
       rp_list.push_back(20); rp_list.push_back(21); rp_list.push_back(24); rp_list.push_back(25);
       rp_list.push_back(22); rp_list.push_back(23);
       rp_list.push_back(120); rp_list.push_back(121); rp_list.push_back(124); rp_list.push_back(125);
       rp_list.push_back(122); rp_list.push_back(123);
       char br_name[200];
       for (unsigned int a = 0; a < 2; ++a) {
	  int s = 2;
	  for (unsigned int r = 0; r < 6; r++) {
	     unsigned int id = 100 * a + 10 * s + r;
	     if( std::find(rp_list.begin(), rp_list.end(), id) == rp_list.end() ) continue;

	     sprintf(br_name, "track_rp_%u.", id);
	     std::cout << br_name << std::endl;
	     tree->SetBranchAddress(br_name, &rp_track_info[id]);
	  }
       }
       /*readRPBranches(tree,
	 rec_proton_left,
	 rec_proton_right,
	 rec_proton_pair,
	 rp_track_info,
	 rp_digi_info,
	 rp_par_patterns_info,
	 rp_nonpar_patterns_info,
	 rp_multi_track_info);*/
    }
    
    /*//Getting number of events
    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout <<"The current file has " << nev << " entries : "<< endl << *itfiles << endl;*/
  
    //starting loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0; i_evt < nev && i_tot < nevt_max_corr; ++i_evt , ++i_tot){
    
      //printing the % of events done every 10k evts
      if( ((i_tot+1) % 5000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
      //if( ((i_tot+1) % 100) == 0 ) cout << (i_tot+1) << " done" << endl;
    
      //Filling the variables defined setting branches
      tree->GetEntry(i_evt);

      //AT THIS POINT ON, CAN START USING THE VARIABLES LIKE TRACKS, VERTEX ETC !
      double event_weight = 1.;

      histosTH1F["EventSelection"]->Fill( "All", event_weight );

      //-------------------------------------------------------------------------------------------------
      // MC 
      /*if(isMC){
        for(vector<MyGenPart>::iterator p=genPart->begin() ; p!=genPart->end() ; p++ )
          pt_gen->Fill(p->Pt());
      }*/
      
      bool proton_plus_rp_accept = false;
      bool proton_minus_rp_accept = false;

      bool proton_plus_xi_range = false;
      bool proton_plus_t_range = false;
      bool proton_minus_xi_range = false;
      bool proton_minus_t_range = false;

      double xi_proton_plus = -1.;
      double xi_proton_minus = -1.;
      double t_proton_plus = 0.;
      double t_proton_minus = 0.;
      if(isMC){
	 // Gen. Particles
	 double genEPlusPz = 0;
	 double genEMinusPz = 0;
	 double proton_pi = 4000.;
	 double proton_pz_plus = -999.;
	 double proton_px_plus = -999.;
	 double proton_py_plus = -999.;
	 double proton_energy_plus = 0.;
	 double proton_pz_minus = 999.;
	 double proton_px_minus = 999.;
	 double proton_py_minus = 999.;
	 double proton_energy_minus = 0.;

	 for(vector<MyGenPart>::iterator it_genpart = genPart->begin();
	       it_genpart != genPart->end(); ++it_genpart){

	    double eta_gen = it_genpart->Eta();
	    int status = it_genpart->status;
	    int id = it_genpart->pdgId;

	    if (status != 1) continue; // final state particles
	    double energy_gen = it_genpart->Energy();
	    double px_gen = it_genpart->Px();
	    double py_gen = it_genpart->Py();
	    double pz_gen = it_genpart->Pz();

	    genEPlusPz +=  (energy_gen + pz_gen);
	    genEMinusPz += (energy_gen - pz_gen);

	    if (id != 2212) continue; // select protons 

	    double proton_pf = sqrt(px_gen*px_gen+py_gen*py_gen+pz_gen*pz_gen);  
	    double pz_cut = 0.75*proton_pi;
	    if ( fabs(pz_gen) < pz_cut) continue;

	    if (pz_gen > proton_pz_plus)  { 
	       proton_pz_plus = pz_gen; proton_energy_plus = energy_gen; 
	       proton_px_plus = px_gen; proton_py_plus = py_gen;
	    } 
	    if (pz_gen < proton_pz_minus) { 
	       proton_pz_minus = pz_gen; proton_energy_minus = energy_gen; 
	       proton_px_minus = px_gen; proton_py_minus = py_gen;
	    } 
	 }
	 double xi_plus_gen = genEPlusPz/8000.;
	 double xi_minus_gen = genEMinusPz/8000.;
	 double thx_proton_plus = 0.; 
	 double thy_proton_plus = 0.; 
	 double thx_proton_minus = 0.; 
	 double thy_proton_minus = 0.; 

	 /*bool proton_minus_rp_accept_120 = false;
	 bool proton_minus_rp_accept_121 = false;
	 bool proton_minus_rp_accept_124 = false;
	 bool proton_minus_rp_accept_125 = false;
	 bool proton_minus_rp_accept_122 = false;
	 bool proton_minus_rp_accept_123 = false;
	 bool proton_minus_rp_accept_020 = false;

	 bool proton_plus_rp_accept_020 = false;
	 bool proton_plus_rp_accept_021 = false;
	 bool proton_plus_rp_accept_024 = false;
	 bool proton_plus_rp_accept_025 = false;
	 bool proton_plus_rp_accept_022 = false;
	 bool proton_plus_rp_accept_023 = false;
	 bool proton_plus_rp_accept_120 = false;

	 std::map<int,std::vector<double> > proton_plus_pars;
	 std::map<int,std::vector<double> > proton_minus_pars;

	 if(proton_pz_plus > 0.){
	    xi_proton_plus =  ( 1 - (proton_pz_plus/proton_pi) );
	    //t_proton_plus = -2*( (proton_pi*proton_energy_plus) - (proton_pi*proton_pz_plus) );
            TLorentzVector vec_pi(0.,0.,proton_pi,proton_pi);
            TLorentzVector vec_pf(proton_px_plus,proton_py_plus,proton_pz_plus,proton_energy_plus);
            TLorentzVector vec_t = (vec_pf - vec_pi);
            t_proton_plus = vec_t.Mag2();
 
	    thx_proton_plus = atan(-proton_px_plus/proton_pi);
	    thy_proton_plus = atan(proton_py_plus/proton_pi);

	    double out_x, out_thx, out_y, out_thy, out_xi;
	    proton_plus_rp_accept_020 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 20, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_021 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 21, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_022 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 22, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_023 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 23, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_024 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 24, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_025 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 25, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_plus_rp_accept_120 = protonRPDetected(0., thx_proton_plus, 0., thy_proton_plus, -xi_proton_plus, 120);

	    proton_plus_xi_range = ( xi_proton_plus >= 0.03 && xi_proton_plus < 0.1 );
	    proton_plus_t_range = ( fabs(t_proton_plus) < 1.0 );
	 }

	 if(proton_pz_minus < 0.){ 
	    xi_proton_minus = (proton_pz_minus < 0.) ? ( 1 + (proton_pz_minus/proton_pi) ) : -1.;
	    //t_proton_minus = -2*( (proton_pi*proton_energy_minus) + (proton_pi*proton_pz_minus) );
            TLorentzVector vec_pi(0.,0.,-proton_pi,proton_pi);
            TLorentzVector vec_pf(proton_px_minus,proton_py_minus,proton_pz_minus,proton_energy_minus);
            TLorentzVector vec_t = (vec_pf - vec_pi);
            t_proton_minus = vec_t.Mag2();

	    thx_proton_minus = atan(-proton_px_minus/proton_pi);
	    thy_proton_minus = atan(proton_py_minus/proton_pi);

	    double out_x, out_thx, out_y, out_thy, out_xi;
	    proton_minus_rp_accept_120 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 120, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_121 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 121, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_122 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 122, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_123 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 123, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_124 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 124, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_125 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 125, out_x, out_thx, out_y, out_thy, out_xi);

	    proton_minus_rp_accept_020 = protonRPDetected(0., thx_proton_minus, 0., thy_proton_minus, -xi_proton_minus, 20);

	    proton_minus_xi_range = ( xi_proton_minus >= 0.03 && xi_proton_minus < 0.1 );
	    proton_minus_t_range = ( fabs(t_proton_minus) < 1.0 );
	 }

         // Check RP combinations  
	 proton_plus_rp_accept = (proton_pz_plus > 0.) && 
                                 ( ( proton_plus_rp_accept_020 && proton_plus_rp_accept_024 ) || 
                                   ( proton_plus_rp_accept_021 && proton_plus_rp_accept_025 ) ||
                                   ( proton_plus_rp_accept_022 && proton_plus_rp_accept_023 ) );
	 proton_minus_rp_accept = (proton_pz_minus < 0.) && 
                                  ( ( proton_minus_rp_accept_120 && proton_minus_rp_accept_124 ) ||
                                    ( proton_minus_rp_accept_121 && proton_minus_rp_accept_125 ) ||
                                    ( proton_minus_rp_accept_122 && proton_minus_rp_accept_123 ) );*/
      }

      //-------------------------------------------------------------------------------------------------
      // Event selection
      //-------------------------------------------------------------------------------------------------
      // Bunch crossing & HLT
      if(!isMC){
	 //int orbitNumber = evtId->Orbit;
	 int bunchCrossingNumber = evtId->Bunch;

	 /*if( selectBunchCrossing &&
	       find(bunchCrossingList.begin(),bunchCrossingList.end(),bunchCrossingNumber) == bunchCrossingList.end() )
	    continue;*/

	 histosTH1F["EventSelection"]->Fill( "BunchCrossing", event_weight );

	 for (int itrig = 0 ; itrig < 128 ; ++itrig){
	    if( l1Trig->PhysTrigWord[itrig] == 1) 
	       histosTH1F["decisionPhysTrig"]->Fill( itrig, event_weight );
	 }

	 for (int itrig = 0 ; itrig < 64 ; ++itrig){
	    if( l1Trig->TechTrigWord[itrig] == 1 )
	       histosTH1F["decisionTechTrig"]->Fill( itrig, event_weight );
	 }

	 map<string,bool>::iterator it_hlt = (*hltTrig).HLTmap.begin();
	 map<string,bool>::iterator it_hlt_end = (*hltTrig).HLTmap.end();
	 for(; it_hlt != it_hlt_end; ++it_hlt){
	    string const& hltName = it_hlt->first;
	    vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
	    if(it_pos != hltPathNames.end()){
	       /*size_t idx = it_pos - hltPathNames.begin();
		 if( it_hlt->second ) histosTH1F["hltTrigFired"]->Fill( idx, event_weight );*/
	       if( it_hlt->second ) histosTH1F["hltTrigFired"]->Fill( hltName.c_str(), event_weight );
	    }
	 }

	 bool select_HLT = false;
	 bool hlt_result = false;
	 for(vector<string>::const_iterator it_pathname_sel = selectHLTPathNames.begin();
	       it_pathname_sel != selectHLTPathNames.end(); ++it_pathname_sel){
	    /*bool accept = (*hltTrig).HLTmap[ *it_pathname_sel ];
	      if(accept) { select_HLT = true; break; }*/

	    if( it_pathname_sel == selectHLTPathNames.begin() ) hlt_result = selectHLTORorAND ? false : true;
	    bool accept = (*hltTrig).HLTmap[ *it_pathname_sel ];
	    if(selectHLTORorAND) hlt_result = hlt_result || accept;
	    else                 hlt_result = hlt_result && accept;
	 }
	 select_HLT = hlt_result;
	 if(!select_HLT) continue;

	 histosTH1F["EventSelection"]->Fill( "HLT", event_weight );
      }
      //-------------------------------------------------------------------------------------------------
      // Vertices
      int n_vertices_selected = 0;
      /*int idx_vtx_max_sumpt = -1;
      double sumpt_max = 0.;*/
      for(vector<MyVertex>::iterator it_vtx = vertex_coll->begin() ; it_vtx != vertex_coll->end() ; ++it_vtx){
         int idx_vtx = it_vtx - vertex_coll->begin();
         //if( it_vtx->SumPtTracks > sumpt_max ){ idx_vtx_max_sumpt = idx_vtx; sumpt_max = it_vtx->SumPtTracks; }

         if( it_vtx->fake ) continue;
         if( !it_vtx->validity ) continue;
         ++n_vertices_selected;
      }

      MyVertex& primaryVertex = vertex_coll->at(0);
      double prim_vtx_r = sqrt( primaryVertex.x*primaryVertex.x + primaryVertex.y*primaryVertex.y );
      bool select_Vertex = ( !primaryVertex.fake && primaryVertex.validity &&
                              primaryVertex.ndof > 4 && fabs( primaryVertex.z ) < 15.0 && prim_vtx_r < 2.0);
      if(selectVertex && !select_Vertex) continue;

      histosTH1F["EventSelection"]->Fill( "Vertex", event_weight );

      // Tracks
      int n_tracks_selected = 0;
      for(vector<MyTracks>::iterator it_trk = track_coll->begin() ; it_trk != track_coll->end() ; ++it_trk){
         if( it_trk->Pt() < 0.5 ) continue;
         if( fabs( it_trk->Eta() ) > 2.5 ) continue;
         if( ( it_trk->dz / it_trk->edz ) > 5. ) continue;
         if( ( it_trk->d0 / it_trk->ed0 ) > 5. ) continue;
    
         /*
         outtrack.quality[0] = intrack.quality(TrackBase::qualityByName("loose"));
         outtrack.quality[1] = intrack.quality(TrackBase::qualityByName("tight"));
         outtrack.quality[2] = intrack.quality(TrackBase::qualityByName("highPurity"));
         outtrack.quality[3] = intrack.quality(TrackBase::qualityByName("confirmed"));
         outtrack.quality[4] = intrack.quality(TrackBase::qualityByName("goodIterative"));
         */ 
         if( !it_trk->quality[2] ) continue;

         ++n_tracks_selected;
      }

      // Jets
      for(vector<MyPFJet>::iterator it_jet = pfJet_coll->begin() ; it_jet != pfJet_coll->end() ; ++it_jet){
         map<string,MyBaseJet>::iterator it_map = it_jet->mapjet.begin();
         for(; it_map != it_jet->mapjet.end(); ++it_map)
            if(verbose) cout << it_map->first << endl;

         /*MyBaseJet const& basejet = it_jet->mapjet[ jetCorrName ];
         histosTH1F["jet_pt"]->Fill( basejet.Pt(), event_weight );
         if(basejet.Pt() > 0.) histosTH1F["jet_eta"]->Fill( basejet.Eta(), event_weight );
         histosTH1F["jet_phi"]->Fill( basejet.Phi(), event_weight );*/
      }

      bool select_leadingJet = false;
      if( pfJet_coll->size() > 0 ){
	 MyBaseJet const& leadingJet = ( pfJet_coll->at(0) ).mapjet[ jetCorrName ];
         double jetpt = leadingJet.Pt();
         double jeteta = (leadingJet.Pt() > 0.) ? leadingJet.Eta() : 0.;
         double sum2_up(0), sum2_dw(0);
         for (int isrc = 0; isrc < n_jec_unc_src; isrc++) {
            //cout << isrc << endl; 
            JetCorrectionUncertainty *unc = jec_unc_src[isrc];
            unc->setJetPt(jetpt);
            unc->setJetEta(jeteta);
            double sup = unc->getUncertainty(true); // up variation
            //cout << sup << endl;
            unc->setJetPt(jetpt);
            unc->setJetEta(jeteta);
            double sdw = unc->getUncertainty(false); // down variation
            //cout << sdw << endl;
           
            sum2_up += pow(max(sup,sdw),2);
            sum2_dw += pow(min(sup,sdw),2);
         } // for isrc
         //cout << sqrt(sum2_up) << endl;
         //cout << sqrt(sum2_dw) << endl;
         jec_unc_total->setJetPt(jetpt);
         jec_unc_total->setJetEta(jeteta);
         double uncert_total = jec_unc_total->getUncertainty(true);
         //cout << uncert_total << endl;
         if(verbose) std::cout << "Leading jet pT, uncertainties total, individual sources up/dw: " 
                               << jetpt << ", " << uncert_total
                               << ", " << sqrt(sum2_up) << ", " << sqrt(sum2_dw) << std::endl;
     

	 histosTH1F["leadingJet_pt"]->Fill( jetpt, event_weight );
	 histosTH1F["leadingJet_pt_unc_up"]->Fill( jetpt*(1. + sqrt(sum2_up)), event_weight );
	 histosTH1F["leadingJet_pt_unc_dw"]->Fill( jetpt*(1. - sqrt(sum2_dw)), event_weight );

	 if(leadingJet.Pt() > 0.) histosTH1F["leadingJet_eta"]->Fill( jeteta, event_weight );
	 histosTH1F["leadingJet_phi"]->Fill( leadingJet.Phi(), event_weight );

         histosTH1F["leadingJet_jec"]->Fill( leadingJet.jec, event_weight );

         //bool looseJetId = ( pfJet_coll->at(0) ).LooseJetId;
         bool looseJetId = loosePFJetID(pfJet_coll->at(0),jetCollName);
         histosTH1F["leadingJet_looseJetId"]->Fill( looseJetId ? 1 : 0, event_weight );
         //bool tightJetId = ( pfJet_coll->at(0) ).TightJetId;
         bool tightJetId = tightPFJetID(pfJet_coll->at(0),jetCollName);
         histosTH1F["leadingJet_tightJetId"]->Fill( tightJetId ? 1 : 0, event_weight );

         select_leadingJet = (leadingJet.Pt() >= ptJetMin && fabs(leadingJet.Eta()) <= etaJetMax && looseJetId);
      }

      bool select_secondJet = false;
      if( pfJet_coll->size() > 1 ){
	 MyBaseJet const& secondJet = ( pfJet_coll->at(1) ).mapjet[ jetCorrName ];
	 histosTH1F["secondJet_pt"]->Fill( secondJet.Pt(), event_weight );
	 if(secondJet.Pt() > 0.) histosTH1F["secondJet_eta"]->Fill( secondJet.Eta(), event_weight );
	 histosTH1F["secondJet_phi"]->Fill( secondJet.Phi(), event_weight );

         histosTH1F["secondJet_jec"]->Fill( secondJet.jec, event_weight );

         //bool looseJetId = ( pfJet_coll->at(1) ).LooseJetId;
         bool looseJetId = loosePFJetID(pfJet_coll->at(1),jetCollName);
         histosTH1F["secondJet_looseJetId"]->Fill( looseJetId ? 1 : 0, event_weight );
         //bool tightJetId = ( pfJet_coll->at(1) ).TightJetId;
         bool tightJetId = tightPFJetID(pfJet_coll->at(1),jetCollName);
         histosTH1F["secondJet_tightJetId"]->Fill( tightJetId ? 1 : 0, event_weight );

         select_secondJet = (secondJet.Pt() >= ptJetMin && fabs(secondJet.Eta()) <= etaJetMax && looseJetId);
      }
      bool select_Jet = ( select_leadingJet && select_secondJet);
      if(selectJets && !select_Jet) continue;

      histosTH1F["EventSelection"]->Fill( "Jet", event_weight );

      if( pfJet_coll->size() > 0 ){
	 MyBaseJet const& leadingJet = ( pfJet_coll->at(0) ).mapjet[ jetCorrName ];
	 histosTH1F["leadingJet_pt_after_jet_sel"]->Fill( leadingJet.Pt(), event_weight );
	 histosTH1F["leadingJet_eta_after_jet_sel"]->Fill( leadingJet.Eta(), event_weight );
	 histosTH1F["leadingJet_phi_after_jet_sel"]->Fill( leadingJet.Phi(), event_weight );
	 histosTH1F["leadingJet_jec_after_jet_sel"]->Fill( leadingJet.jec, event_weight );
      }
      if( pfJet_coll->size() > 1 ){
	 MyBaseJet const& secondJet = ( pfJet_coll->at(1) ).mapjet[ jetCorrName ];
	 histosTH1F["secondJet_pt_after_jet_sel"]->Fill( secondJet.Pt(), event_weight );
	 histosTH1F["secondJet_eta_after_jet_sel"]->Fill( secondJet.Eta(), event_weight );
	 histosTH1F["secondJet_phi_after_jet_sel"]->Fill( secondJet.Phi(), event_weight );
	 histosTH1F["secondJet_jec_after_jet_sel"]->Fill( secondJet.jec, event_weight );
      }

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
	 double eta = it_pfcand->Eta();
	 double energy = it_pfcand->Energy();
	 double pz = it_pfcand->Pz();

         // Apply thresholds
         if( !pflowThreshold(*it_pfcand,thresholdsPFlow) ) continue;

         if( eta >= etaEdgeLow && eta <= etaEdgeHigh ) particles_sorted.push_back(*it_pfcand);
         pfEPlusPz  += energy + pz;
         pfEMinusPz += energy - pz;
      }
      // Xi (CMS)
      double pfXiPlusReco = xiCorrFactor*pfEPlusPz/8000.;
      double pfXiMinusReco = xiCorrFactor*pfEMinusPz/8000.;

      // Find eta_min & eta_max
      double pfEtaMin = -999.;
      double pfEtaMax = 999.;
      if( particles_sorted.size() > 0 ){
	 std::stable_sort(particles_sorted.begin(), particles_sorted.end(), sortByEta);
	 pfEtaMin = particles_sorted.at(0).Eta();
	 pfEtaMax = particles_sorted.at(particles_sorted.size() - 1).Eta();
      }
      if( selectEtaMax && (pfEtaMax > etaMaxThreshold) ) continue;
      histosTH1F["EventSelection"]->Fill( "EtaMax", event_weight );

      if( selectEtaMin && (pfEtaMin < -etaMaxThreshold) ) continue;
      histosTH1F["EventSelection"]->Fill( "EtaMin", event_weight );

      // TOTEM T2
      int n_t2_tracks_selected = 0;
      int n_t2_tracks_selected_zplus = 0;
      int n_t2_tracks_selected_zminus = 0;
      if(!isMC){
	 vector<double> const& t2_trk_entryX = t2_event->TrkEntryX;
	 vector<double> const& t2_trk_entryY = t2_event->TrkEntryY;
	 vector<double> const& t2_trk_entryZ =  t2_event->TrkEntryZ;
	 vector<double> const& t2_trk_chiProb =  t2_event->TrkChiProb;

	 size_t n_t2_tracks = t2_trk_chiProb.size();
	 for(size_t i_t2_trk = 0; i_t2_trk < n_t2_tracks; ++i_t2_trk){
	    double trk_entryZ = t2_trk_entryZ[i_t2_trk];
	    int zside = ( trk_entryZ >= 0. ) ? 1 : -1;
	    // Select tracks
	    if( t2_trk_chiProb[i_t2_trk] < 0.2 ) continue;

	    ++n_t2_tracks_selected;
	    if( zside > 0 ) ++n_t2_tracks_selected_zplus;
	    else            ++n_t2_tracks_selected_zminus;
	 }

	 if( selectZeroHitsT2Plus && (n_t2_tracks_selected_zplus > 0) ) continue;
	 histosTH1F["EventSelection"]->Fill( "ZeroHitsT2Plus", event_weight );

	 if( selectZeroHitsT2Minus && (n_t2_tracks_selected_zminus > 0) ) continue;
	 histosTH1F["EventSelection"]->Fill( "ZeroHitsT2Minus", event_weight );
      }

      // RP topology 
      bool proton_right_valid = false;
      bool proton_left_valid = false;
      if(!isMC){
	 proton_right_valid = rec_proton_right->valid;
	 proton_left_valid = rec_proton_left->valid;
         bool double_arm_rec_proton = (proton_right_valid && proton_left_valid);
         //bool single_arm_rec_proton = (proton_right_valid || proton_left_valid) && !double_arm_rec_proton;
         bool single_arm_rec_proton = !double_arm_rec_proton;

	 if( selectSingleArmRecProton && !single_arm_rec_proton ) continue;
	 histosTH1F["EventSelection"]->Fill( "SingleArmRP", event_weight );

	 if( selectDoubleArmRecProton && !double_arm_rec_proton ) continue;
	 histosTH1F["EventSelection"]->Fill( "DoubleArmRP", event_weight );

	 bool tag_elastic_top45_bot56 = elastic_top45_bot56(rp_track_info);      
	 bool tag_elastic_bot45_top56 = elastic_bot45_top56(rp_track_info);      
	 if( selectElastic && !(tag_elastic_top45_bot56 || tag_elastic_bot45_top56) ) continue;
	 histosTH1F["EventSelection"]->Fill( "Elastic", event_weight );

	 if( selectNonElastic && (tag_elastic_top45_bot56 || tag_elastic_bot45_top56) ) continue;
	 histosTH1F["EventSelection"]->Fill( "NonElastic", event_weight );
      }

      // RP protons
      if(!isMC){
	 double chi2_proton_right = rec_proton_right->chi2;
	 double chindf_proton_right = rec_proton_right->chindf;
	 double xi_proton_right = -rec_proton_right->xi;
	 double t_proton_right = rec_proton_right->t;
	 bool good_proton_right = proton_right_valid;
         bool proton_right_xi_range = ( (xi_proton_right) >= 0.03 && (xi_proton_right < 0.1) );
         bool proton_right_t_range = ( (-t_proton_right) >= 0.0 && (-t_proton_right < 1.0) );

         bool select_proton_minus = false;
	 if( good_proton_right ){
	    histosTH1F["proton_right_xi"]->Fill( xi_proton_right, event_weight );
	    histosTH1F["proton_right_t"]->Fill( -t_proton_right, event_weight );
	    if(xi_proton_right > 0.){
	       histosTH1F["proton_right_logXi"]->Fill( log10(xi_proton_right), event_weight );
	    }

	    if( proton_right_xi_range && proton_right_t_range ){

	       /*if( pfXiMinusReco > 0.12 ){
		  histosTH1F["proton_right_xi_background"]->Fill( xi_proton_right, event_weight );
		  histosTH1F["proton_right_t_background"]->Fill( -t_proton_right, event_weight );
		  for(size_t ibin = 0; ibin < (vec_binning_t.size()-1); ++ibin){
                     if( ( -t_proton_right >= vec_binning_t[ibin] ) &&
			 ( -t_proton_right < vec_binning_t[ibin+1]) ){ 
			std::stringstream histoName_t_right;
			histoName_t_right << "proton_right_xi_background_" << ibin; 
			histosTH1F[histoName_t_right.str()]->Fill( xi_proton_right, event_weight ); 
		     }
		  }
	       }*/

	       if( (pfXiMinusReco - xi_proton_right) < 0. ){
                  select_proton_minus = true;
		  histosTH1F["proton_right_xi_selected"]->Fill( xi_proton_right, event_weight );
		  histosTH1F["proton_right_t_selected"]->Fill( -t_proton_right, event_weight );
	       }
	    }
	 }

	 double chi2_proton_left = rec_proton_left->chi2;
	 double chindf_proton_left = rec_proton_left->chindf;
	 double xi_proton_left = -rec_proton_left->xi;
	 double t_proton_left = rec_proton_left->t;
	 bool good_proton_left = proton_left_valid;
         bool proton_left_xi_range = ( (xi_proton_left) >= 0.03 && (xi_proton_left < 0.1) );
         bool proton_left_t_range = ( (-t_proton_left) >= 0.0 && (-t_proton_left < 1.0) );
       
         bool select_proton_plus = false;
	 if( good_proton_left ){
	    histosTH1F["proton_left_xi"]->Fill( xi_proton_left, event_weight );
	    histosTH1F["proton_left_t"]->Fill( -t_proton_left, event_weight );

	    if(xi_proton_left > 0.){
	       histosTH1F["proton_left_logXi"]->Fill( log10(xi_proton_left), event_weight );
	    }

	    if( proton_left_xi_range && proton_left_t_range ){

	       /*if( pfXiPlusReco > 0.12 ){
		  histosTH1F["proton_left_xi_background"]->Fill( xi_proton_left, event_weight );
		  histosTH1F["proton_left_t_background"]->Fill( -t_proton_left, event_weight );
		  for(size_t ibin = 0; ibin < (vec_binning_t.size()-1); ++ibin){
                     if( ( -t_proton_left >= vec_binning_t[ibin] ) &&
			 ( -t_proton_left < vec_binning_t[ibin+1]) ){ 
			std::stringstream histoName_t_left;
			histoName_t_left << "proton_left_xi_background_" << ibin; 
			histosTH1F[histoName_t_left.str()]->Fill( xi_proton_left, event_weight ); 
		     }
		  }
	       }*/

	       if( (pfXiPlusReco - xi_proton_left) < 0. ){
                  select_proton_plus = true;
		  histosTH1F["proton_left_xi_selected"]->Fill( xi_proton_left, event_weight );
		  histosTH1F["proton_left_t_selected"]->Fill( -t_proton_left, event_weight );
	       }
	    } 
	 }
         // Select proton track
	 if( selectRPProton && !(select_proton_minus || select_proton_plus) ) continue;
	 histosTH1F["EventSelection"]->Fill( "RPProton", event_weight );
      }

      /*if(isMC){
	 if( selectRPPlusAccept && !proton_plus_rp_accept ) continue;
	 histosTH1F["EventSelection"]->Fill( "MCRPPlusAccept", event_weight );

	 if( selectRPMinusAccept && !proton_minus_rp_accept ) continue;
	 histosTH1F["EventSelection"]->Fill( "MCRPMinusAccept", event_weight );
      }*/

      //-------------------
      // After selection 
      //-------------------

      //-------------------
      // Generator-level proton distributions
      //-------------------
      /*if(isMC){
	 if( proton_plus_rp_accept ){
	    histosTH1F["xi_proton_plus_selected"]->Fill( xi_proton_plus , event_weight );
	    histosTH1F["t_proton_plus_selected"]->Fill( fabs(t_proton_plus) , event_weight ); 
	    histosTH2F["proton_plus_xi_vs_t_selected"]->Fill( fabs(t_proton_plus) , xi_proton_plus , event_weight );
	    if(proton_plus_t_range)
	       histosTH1F["xi_proton_t_range_plus_selected"]->Fill( xi_proton_plus , event_weight );
	    if(proton_plus_xi_range)
	       histosTH1F["t_proton_xi_range_plus_selected"]->Fill( fabs(t_proton_plus) , event_weight );
	 }

	 if( proton_minus_rp_accept ){
	    histosTH1F["xi_proton_minus_selected"]->Fill( xi_proton_minus , event_weight );
	    histosTH1F["t_proton_minus_selected"]->Fill( fabs(t_proton_minus) , event_weight ); 
	    histosTH2F["proton_minus_xi_vs_t_selected"]->Fill( fabs(t_proton_minus) , xi_proton_minus , event_weight );

	    if(proton_minus_t_range)
	       histosTH1F["xi_proton_t_range_minus_selected"]->Fill( xi_proton_minus , event_weight );
	    if(proton_minus_xi_range)
	       histosTH1F["t_proton_xi_range_minus_selected"]->Fill( fabs(t_proton_minus) , event_weight );
	 }
      }*/

      //-------------------
      // Detector-level distributions
      //-------------------

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
