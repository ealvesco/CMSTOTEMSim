#include <TFile.h>

#include "utilities.h"

#include <vector>
#include <string>
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
 * This function prepares totem branches in output tree.
 */
void prepareTotemBranches(const string& totemFileName, TTree *outputTree,
    TTree *tree_totem) {
  //checkAndGetBranch(tree_totem, "trigger_data")->SetAddress(&trigData);
  outputTree->Branch("trigger_data.", &trigData);
  //checkAndGetBranch(tree_totem, "event_info")->SetAddress(&totemEventData);
  outputTree->Branch("event_info.", &totemEventData);
}

/**
 * This function saves the TOTEM ntuples event information for each file. The result is saved in outputDir.
 */
void writeTOTEMEventInfo(vector<string> const& totemFileNames, string const& outputDir){

  unsigned int n_events_all = 0;

  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file){ 

     string const& totemFileName = *it_file;
     cout << "Opening Totem File: " << totemFileName << endl; //opening input ntuples
     TFile* totemFile = TFile::Open(totemFileName.c_str());
     if (!totemFile || totemFile->IsZombie())
        error("Error opening file");

     TTree* totemTree = (TTree*) totemFile->Get("TotemNtuple");
     if (!totemTree)
        error("No data tree found");

     TBranch *b_trigger_data = checkAndGetBranch(totemTree, "trigger_data");
     b_trigger_data->SetAddress(&trigData);
     TBranch *b_event_info = checkAndGetBranch(totemTree, "event_info");
     b_event_info->SetAddress(&totemEventData);

     unsigned int totemSize = totemTree->GetEntries(); 
     cout << "File: " << totemFileName << " -- TOTEM entries: " << totemSize << endl;

     if( totemSize == 0) continue;
 
     string totemFileNameNoPath;
     size_t pos = totemFileName.rfind("/");
     if( pos != string::npos) totemFileNameNoPath = totemFileName.substr(pos+1);

     string outputFileName = outputDir + string("/") + totemFileNameNoPath;
     TFile* output = TFile::Open(outputFileName.c_str(), "RECREATE");
     TTree* outputTree = new TTree("totem", "totem-metadata");
     // TOTEM
     //prepareTotemBranches(totemFileName, outputTree, totemTree);
     outputTree->Branch("trigger_data.", &trigData);
     outputTree->Branch("event_info.", &totemEventData);

     // Loop over events in TTree
     for (unsigned int totem_i = 0; totem_i < totemSize; ++totem_i){

	b_trigger_data->GetEntry(totem_i);
	b_event_info->GetEntry(totem_i);
	//totemTree->GetEntry(totem_i);

	cout << totem_i << "\t\t" << trigData->event_num
                        << "\t\t" << ( trigData->orbit_num )/2
                        << "\t\t" << trigData->bunch_num << endl;

	outputTree->Fill(); //fill the output ntuple
	++n_events_all;
     } // end loop totem events
      
     totemFile->Close(); 
     output->cd();
     outputTree->Write();
     output->Close();

  } // end loop on files

  cout << "Total number of saved events = " << n_events_all << endl;
}

int main(int argc, char** argv) {

  if (argc < 3)
  {
    error("writeTOTEMEventInfo.cc <Output dir> <TOTEM data file 1> [<TOTEM data file 2>,...]");
  }

  string outputDir(argv[1]);

  //string prefix = "root://eostotem/";
  string prefix = "";
  vector<string> totemFileNames;
  totemFileNames.push_back( prefix + string(argv[2]) );
  if( argc > 3)
     for(int iarg = 3; iarg < argc; ++iarg) { totemFileNames.push_back( prefix + string(argv[iarg]) ); }

  ostringstream oss;
  oss << "List of input files: " << endl;
  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file) oss << "\t" << *it_file << endl; 

  cout << oss.str(); 

  writeTOTEMEventInfo(totemFileNames, outputDir);

  return 0;
}
