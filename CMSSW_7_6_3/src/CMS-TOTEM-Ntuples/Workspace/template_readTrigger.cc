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
#include "UATree/UADataFormat/interface/MassParticles.h"
#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"

/*#include "MyBaseJet.h"
#include "MyBeamSpot.h"
#include "MyCaloJet.h"
#include "MyCastorDigi.h"
#include "MyCastorJet.h"
#include "MyCastorRecHit.h"
#include "MyDiJet.h"
#include "MyElectron.h"
#include "MyFwdGap.h"
#include "MyGenJet.h"
#include "MyGenKin.h"
#include "MyGenMet.h"
#include "MyGenPart.h"
#include "MyJet.h"
//#include "MyMITEvtSel.h"
#include "MyMet.h"
#include "MyMuon.h"
#include "MyPFCand.h"
#include "MyPFJet.h"
#include "MyPUSumInfo.h"
#include "MyPart.h"
#include "MySimVertex.h"
#include "MyTracks.h"
#include "MyVertex.h"*/

//STANDARD C++ INCLUDES
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool isMC  = false;
bool debug = false;

void template_readTrigger(string const& fileName, const Int_t nevt_max = 100, bool accessL1 = true){
  
  bool verbose = false;
  //string treeName = "cms_totem";
  string treeName = "evt";

  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

  vector<string> hltPathNames;
  /*hltPathNames.push_back("HLT_L1DoubleEG3_FwdVeto_v1");
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
  hltPathNames.push_back("HLT_ZeroBias_v7");*/
  /*hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_part1_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_part2_v1");
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part1_v1");
  hltPathNames.push_back("HLT_L1TOTEM2_ZeroBias_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM2_ZeroBias_part1_v1");*/
  hltPathNames.push_back("HLT_L1DoubleJet20_v1");
  hltPathNames.push_back("HLT_L1DoubleJet28_v1");
  hltPathNames.push_back("HLT_L1DoubleJet32_v1");
  hltPathNames.push_back("HLT_L1DoubleMuOpen_v1");
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_v1");
  hltPathNames.push_back("HLT_L1TOTEM2_ZeroBias_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part1_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part2_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part3_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part4_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part5_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part6_v1");
  hltPathNames.push_back("HLT_L1TOTEM0_RomanPotsAND_PixelClusters5_part7_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part1_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part2_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part3_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part4_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part5_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part6_v1");
  hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part7_v1");
  hltPathNames.push_back("HLT_ZeroBias_v1");
  hltPathNames.push_back("HLT_Physics_v1");
  hltPathNames.push_back("HLT_Random_v1");

  //Declaration of my th1s
  map<string,TH1F*> histosTH1F;
  //unsigned int const NORBITMAX = 5e+07;
  unsigned int const NORBITMAX = 4e+08;
  int nBinsOrbit = NORBITMAX/10000;
  histosTH1F["cmsOrbit"] = new TH1F("cmsOrbit", "cmsOrbit", nBinsOrbit,      0, NORBITMAX);
  histosTH1F["cmsBunch"] = new TH1F("cmsBunch", "cmsBunch",   (2808+1),      0,  (2808+1));
  histosTH1F["cmsRun"]   = new TH1F("cmsRun"  , "cmsRun"  ,       5000, 255000,    260000);
  histosTH1F["cmsLumi"]  = new TH1F("cmsLumi" , "cmsLumi" ,       1500,      0,      1500);

  histosTH1F["decisionPhysTrig"] = new TH1F("decisionPhysTrig", "decisionPhysTrig", 128, 0, 128);
  histosTH1F["decisionTechTrig"] = new TH1F("decisionTechTrig", "decisionTechTrig",  64, 0,  64);

  int nBinsHLT = hltPathNames.size(); 
  histosTH1F["hltTrigFired"] = new TH1F("hltTrigFired", "hltTrigFired", nBinsHLT, 0, nBinsHLT);
  for(size_t k = 0; k < nBinsHLT; ++k) 
     histosTH1F["hltTrigFired"]->GetXaxis()->SetBinLabel( (k + 1) , hltPathNames[k].c_str() );

  //vector<TString>* vfiles = new vector<TString>(1,"merged_reduced_8372_198903_LP_Jets1_1_test_v1.root"); 
  vector<TString>* vfiles = new vector<TString>; 
  vfiles->push_back( fileName ); 
  
  //Declaration of tree and its branches variables
  TTree* tree = new TTree(treeName.c_str(),"");
  MyEvtId*           evtId        = NULL;
  MyHLTrig*          hltTrig      = NULL;
  MyL1TrigOld*       l1Trig       = NULL;  
  
  int i_tot = 0 , nevt_tot = 0;
  // Loop over files, stops at end of list of files or when reached nevt_max
  for(vector<TString>::iterator itfiles = vfiles->begin() ; itfiles != vfiles->end() && i_tot < nevt_max_corr ; ++itfiles){
  
    TFile* file = TFile::Open(*itfiles,"READ");
    
    //getting the tree form the current file
    tree = (TTree*) file->Get( treeName.c_str() );

    //Getting number of events
    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout << "The current file has " << nev << " entries : "<< endl << *itfiles << endl;

    // Adding branches to the tree ----------------------------------------------------------------------
    /*tree->SetBranchAddress("cmsEvtUA",&evtId);
    tree->SetBranchAddress("cmsTrigUA",&l1Trig);
    tree->SetBranchAddress("cmsHLTTrigUA",&hltTrig);*/
    tree->SetBranchAddress("evtId",&evtId);
    tree->SetBranchAddress("HLTrig",&hltTrig);
    if( accessL1 ) tree->SetBranchAddress("L1TrigOld",&l1Trig);
    
    // Loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0 ; i_evt < nev && i_tot < nevt_max_corr ; ++i_evt, ++i_tot){
    
      //printing the % of events done every 10k evts
      if( ((i_tot+1) % 10000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
    
      //Filling the variables defined setting branches
      tree->GetEntry(i_evt);

      //AT THIS POINT ON, CAN START USING THE VARIABLES LIKE TRACKS, VERTEX ETC !

      histosTH1F["cmsOrbit"]->Fill( evtId->Orbit );
      histosTH1F["cmsBunch"]->Fill( evtId->Bunch );
      histosTH1F["cmsRun"]->Fill( evtId->Run );
      histosTH1F["cmsLumi"]->Fill( evtId->LumiSect );

      if( accessL1 ){
	 for (int itrig = 0 ; itrig < 128 ; ++itrig){
	    if( l1Trig->PhysTrigWord[itrig] == 1) 
	       histosTH1F["decisionPhysTrig"]->Fill( itrig );
	 }

	 for (int itrig = 0 ; itrig < 64 ; ++itrig){
	    if( l1Trig->TechTrigWord[itrig] == 1 )
	       histosTH1F["decisionTechTrig"]->Fill( itrig );
	 }
      }

      map<string,bool>::iterator it_hlt = (*hltTrig).HLTmap.begin();
      map<string,bool>::iterator it_hlt_end = (*hltTrig).HLTmap.end();
      for(; it_hlt != it_hlt_end; ++it_hlt){
         string const& hltName = it_hlt->first;
         vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
         if(it_pos != hltPathNames.end()){
            size_t idx = it_pos - hltPathNames.begin();
            if( it_hlt->second ) histosTH1F["hltTrigFired"]->Fill(idx);
         }
         /*for(int ibin = 1; ibin <= histosTH1F["hltTrigFired"]->GetNbinsX(); ++ibin){
            if( hltName.c_str() != histosTH1F["hltTrigFired"]->GetXaxis()->GetBinLabel(ibin) ) continue;
            
            if( it_hlt->second ) 
               histosTH1F["hltTrigFired"]->Fill( histosTH1F["hltTrigFired"]->GetBinCenter( ibin ) );
         }*/ 
      }

    } // end of loop over events
    
    // Closing current files
    file->Close();
    
  } // end of loop over files
  
  
  //output file
  TFile* output = new TFile("output.root","RECREATE");
  output->cd();
  
  for(map<string,TH1F*>::iterator it_histo = histosTH1F.begin();
                                  it_histo != histosTH1F.end(); ++it_histo)
     (*it_histo).second->Write();

  output->Close();
}
