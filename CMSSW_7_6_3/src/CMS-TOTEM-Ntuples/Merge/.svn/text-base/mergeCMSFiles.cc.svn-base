
#include <TFile.h>
#include <TTree.h>

#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"

#include "utilities.h"

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

#include <stdio.h>

using namespace std;

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
  if (!branch) {
    tree->Print();
    error(" No data branch " + branchName + " found in input file!");
  }
  return branch;
}

/**
 * This function merges the CMS ntuples event id information. The result is saved in outputFileName.
 */
void mergeCMSFiles(vector<string> const& cmsFileNames, string const& outputFileName, int cmsFirstLumi, int cmsLastLumi) {

  bool debug = false;

  bool selectHLT  = false;
  bool selectLumi = true;

  vector<string> hltPathNames;
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part1_v1");

  MyEvtId  * evtId   = 0;
  MyHLTrig * hltTrig = 0;

  TFile* output = TFile::Open(outputFileName.c_str(), "RECREATE"); //output ntuple
  TTree* outputTree = new TTree("cms", "cms-metadata");
  outputTree->Branch("evtId", &evtId);
  outputTree->Branch("HLTrig", &hltTrig);

  unsigned int n_events_all = 0;

  vector<string>::const_iterator it_file     = cmsFileNames.begin();
  vector<string>::const_iterator it_file_end = cmsFileNames.end();
  for(; it_file != it_file_end; ++it_file){ 

     string const& cmsFileName = *it_file;

     cout << "Opening CMS File: " << cmsFileName << endl;
     TFile* cmsFile = TFile::Open(cmsFileName.c_str(), "READ");
     if (!cmsFile || cmsFile->IsZombie())
	error("Error opening file");

     TTree * cmsTree = (TTree*) cmsFile->Get("evt");
     unsigned int cmsSize = cmsTree->GetEntries();
     cout << "CMS entries: " << cmsTree->GetEntries() << endl;

     TBranch *b_evtId = checkAndGetBranch(cmsTree, "evtId");
     b_evtId->SetAddress( &evtId );

     TBranch *b_hltTrig = checkAndGetBranch(cmsTree, "HLTrig");
     b_hltTrig->SetAddress( &hltTrig );

     // Loop over events in TTree
     for (unsigned int cms_i = 0; cms_i < cmsSize; cms_i++){

	b_evtId->GetEntry(cms_i);
	b_hltTrig->GetEntry(cms_i);
	//cmsTree->GetEntry(cms_i);

	if( selectHLT ){
	   bool acceptHLT = false; 
	   map<string,bool>::iterator it_hlt = (*hltTrig).HLTmap.begin();
	   map<string,bool>::iterator it_hlt_end = (*hltTrig).HLTmap.end();
	   for(; it_hlt != it_hlt_end; ++it_hlt){
	      string const& hltName = it_hlt->first;
	      vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
	      if(it_pos != hltPathNames.end()){
		 if( it_hlt->second ) {
		    cout << "Event accepted by passing trigger: " << hltName << endl; 
		    acceptHLT = true;
		    break; }
	      }
	   }
	   if( !acceptHLT ) { cout << "Event did not pass any of selected triggers." << endl; continue; }
	}

	if( selectLumi ){
	   if( cmsFirstLumi > 0 && evtId->LumiSect < (unsigned int) cmsFirstLumi ) continue;
	   if( cmsLastLumi > 0 && evtId->LumiSect > (unsigned int) cmsLastLumi ) continue;
	}

	if(debug) cout << cms_i << "\t\t" << evtId->LumiSect << "\t\t" << evtId->Orbit << "\t\t" << evtId->Bunch << endl;

	if (cleanBX && !collidingBunch(evtId->Bunch))
	{ //if bunch is not colliding
	   cout << "Non colliding bunch.. skipping." << endl;
	   continue;
	}

	outputTree->Fill(); //fill the output ntuple
	++n_events_all;
     } // end loop cms events
  }

  output->cd();
  outputTree->Write();
  output->Close();

  if (n_events_all == 0) { //we don't need to store empty ntuples
    if (remove(outputFileName.c_str()) != 0)
      error("Error deleting file");
  }
  cout << "Total number of saved events = " << n_events_all << endl;

}

int main(int argc, char** argv) {

  if (argc < 3)
  {
    error("mergeCMSFiles <Output file name> <CMS data file 1> [<CMS data file 2>,...]");
  }

  string outputFileName(argv[1]);

  //string prefix = "root://eoscms/";
  string prefix = "";
  vector<string> cmsFileNames;
  cmsFileNames.push_back( prefix + string(argv[2]) );
  if( argc > 3)
     for(int iarg = 3; iarg < argc; ++iarg) { cmsFileNames.push_back( prefix + string(argv[iarg]) ); }

  int cmsFirstLumi = -1;
  int cmsLastLumi  = -1;

  ostringstream oss;
  oss << "List of input files: " << endl;
  vector<string>::const_iterator it_file     = cmsFileNames.begin();
  vector<string>::const_iterator it_file_end = cmsFileNames.end();
  for(; it_file != it_file_end; ++it_file) oss << "\t" << *it_file << endl; 

  cout << "CMS first lumi section: " << cmsFirstLumi << endl
       << "CMS last lumi section: " << cmsLastLumi << endl
       << oss.str(); 

  mergeCMSFiles(cmsFileNames, outputFileName, cmsFirstLumi, cmsLastLumi);
  return 0;
}
