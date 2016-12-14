
#include <TROOT.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TChainElement.h>
#include <TDirectory.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>

#include "UATree/UADataFormat/interface/MassParticles.h"
#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

/**
 * This function writes error message to the standard output and then terminates the program.
 */
void error(string errorMessage) {
	cout << errorMessage << "\n";
	exit(-1);
}

/**
 * This function checks if branch of a given name exists.
 * if branch exists - the pointer is returned
 * if not - the program is terminated with error message
 */
TBranch* checkAndGetBranch(TTree* tree, string branchName) {
	TBranch *branch = tree->GetBranch(branchName.c_str());
	if (!branch) {
		string dotBranchName = branchName + ".";
		branch = tree->GetBranch(dotBranchName.c_str());
	}
	return branch;
}

void analysis_readCMS(vector<string> fileNames, string const& outputFileName = "output.root", const Int_t nevt_max = -1){
  
  bool accessL1 = false;

  string treeName = "evt";

  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

  vector<string> hltPathNames;
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

  map<string,TH1F*> histosTH1F;
  map<string,TH2F*> histosTH2F;
  //unsigned int const ORBITMAX = 5e+07;
  unsigned int const ORBITMAX = 4e+08;
  //unsigned int const TIMEMIN  = 1435705200; //Jul 1, 2015
  //unsigned int const TIMEMAX  = 1451602800; //Jan 1, 2016
  unsigned int const TIMEMIN  = 1444860000; // Thu Oct 15 00:00:00 2015
  unsigned int const TIMEMAX  = 1445205600; // Mon Oct 19 00:00:00 2015
  unsigned int nBinsOrbit = ORBITMAX/100000;
  unsigned int nBinsTime  = (TIMEMAX-TIMEMIN)/60;
  histosTH1F["cmsOrbit"] = new TH1F("cmsOrbit", "cmsOrbit", nBinsOrbit,       0, ORBITMAX);
  histosTH1F["cmsTime"]  = new TH1F("cmsTime" , "cmsTime" ,  nBinsTime, TIMEMIN,  TIMEMAX);
  histosTH1F["cmsBunch"] = new TH1F("cmsBunch", "cmsBunch",   (2808+1),       0,  (2808+1));
  histosTH1F["cmsRun"]   = new TH1F("cmsRun"  , "cmsRun"  ,       5000,  255000,    260000);
  histosTH1F["cmsLumi"]  = new TH1F("cmsLumi" , "cmsLumi" ,       1500,       0,      1500);

  histosTH1F["decisionPhysTrig"] = new TH1F("decisionPhysTrig", "decisionPhysTrig", 128, 0, 128);
  histosTH1F["decisionTechTrig"] = new TH1F("decisionTechTrig", "decisionTechTrig",  64, 0,  64);

  int nBinsHLT = hltPathNames.size(); 
  histosTH1F["hltTrigFired"] = new TH1F("hltTrigFired", "hltTrigFired", nBinsHLT, 0, nBinsHLT);
  for(size_t k = 0; k < (unsigned int)nBinsHLT; ++k) 
     histosTH1F["hltTrigFired"]->GetXaxis()->SetBinLabel( (k + 1) , hltPathNames[k].c_str() );

  histosTH2F["cmsOrbitvsTime"]  = new TH2F("cmsOrbitvsTime", "cmsOrbitvsTime", nBinsTime, TIMEMIN, TIMEMAX, nBinsOrbit, 0, ORBITMAX);

  vector<TString>* vfiles = new vector<TString>; 
  for(size_t idx_file = 0; idx_file < fileNames.size(); ++idx_file) vfiles->push_back( fileNames[idx_file] );
  
  //Declaration of tree and its branches variables
  TTree* tree = new TTree(treeName.c_str(),"");
  MyEvtId*           evtId        = nullptr;
  MyHLTrig*          hltTrig      = nullptr;
  MyL1TrigOld*       l1Trig       = nullptr;  

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
    tree->SetBranchAddress("evtId",&evtId);
    tree->SetBranchAddress("HLTrig",&hltTrig);
    if( accessL1 ) tree->SetBranchAddress("L1TrigOld",&l1Trig);
    
    // Loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0 ; i_evt < nev && i_tot < nevt_max_corr ; ++i_evt, ++i_tot){
    
      if( ((i_tot+1) % 10000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
    
      tree->GetEntry(i_evt);

      unsigned int unix_time_cms = static_cast<unsigned int>( evtId->Time >> 32);
      histosTH1F["cmsOrbit"]->Fill( evtId->Orbit );
      histosTH1F["cmsTime"]->Fill( unix_time_cms );
      histosTH1F["cmsBunch"]->Fill( evtId->Bunch );
      histosTH1F["cmsRun"]->Fill( evtId->Run );
      histosTH1F["cmsLumi"]->Fill( evtId->LumiSect );

      histosTH2F["cmsOrbitvsTime"]->Fill( unix_time_cms , evtId->Orbit );

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
      }

    } // end of loop over events
    
    // Closing current files
    file->Close();
    
  } // end of loop over files

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

int main(int argc, char** argv) {

  if (argc < 4)
  {
    error("analysis-readCMS <N events> <Output file name> <CMS data file 1> [<CMS data file 2>,...]");
  }

  int maxEvents = -1;
  stringstream maxEvents_ss;
  maxEvents_ss << argv[1];
  maxEvents_ss >> maxEvents;

  string outputFileName = argv[2];
  
  //string prefix = "root://eoscms/";
  string prefix = "";
  vector<string> cmsFileNames;
  cmsFileNames.push_back( prefix + string(argv[3]) );
  if( argc > 4)
     for(int iarg = 4; iarg < argc; ++iarg) { cmsFileNames.push_back( prefix + string(argv[iarg]) ); }

  ostringstream oss;
  oss << "List of CMS files: " << endl;
  vector<string>::const_iterator it_file     = cmsFileNames.begin();
  vector<string>::const_iterator it_file_end = cmsFileNames.end();
  for(; it_file != it_file_end; ++it_file) oss << "\t" << *it_file << endl; 

  cout << "Output file name: " << outputFileName << endl
       << "Number of events to be processed: " << maxEvents << endl;
  cout << oss.str(); 

  //const string cmsTreeName   = "cms";
  //const string cmsTreeName   = "evt";
  analysis_readCMS(cmsFileNames, outputFileName, maxEvents);
  return 0;
}
