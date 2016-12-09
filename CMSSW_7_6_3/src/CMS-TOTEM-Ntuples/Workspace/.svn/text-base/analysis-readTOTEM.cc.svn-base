
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

#include "TriggerData.h"
#include "EventMetaData.h"

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

void analysis_readTOTEM(vector<string> fileNames, string const& outputFileName = "output.root", const Int_t nevt_max = -1){
  
  //bool verbose = false;
  string treeName = "TotemNtuple";

  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

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
  histosTH1F["totemOrbit"] = new TH1F("totemOrbit", "totemOrbit", nBinsOrbit, 0, ORBITMAX);
  histosTH1F["totemTime"]  = new TH1F("totemTime", "totemTime", nBinsTime, TIMEMIN, TIMEMAX);
  histosTH2F["totemOrbitvsTime"]  = new TH2F("totemOrbitvsTime", "totemOrbitvsTime", nBinsTime, TIMEMIN, TIMEMAX, nBinsOrbit, 0, ORBITMAX);

  vector<TString>* vfiles = new vector<TString>; 
  for(size_t idx_file = 0; idx_file < fileNames.size(); ++idx_file) vfiles->push_back( fileNames[idx_file] );
  
  TTree* tree = new TTree(treeName.c_str(),"");
  TriggerData   *trigData       = nullptr;
  EventMetaData *totemEventData = nullptr;
  
  int i_tot = 0 , nevt_tot = 0;
  // Loop over files, stops at end of list of files or when reached nevt_max
  for(vector<TString>::iterator itfiles = vfiles->begin() ; itfiles != vfiles->end() && i_tot < nevt_max_corr ; ++itfiles){
  
    TFile* file = TFile::Open(*itfiles,"READ");
    
    tree = (TTree*) file->Get( treeName.c_str() );

    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout << "The current file has " << nev << " entries : "<< endl << *itfiles << endl;

    // Adding branches to the tree ----------------------------------------------------------------------
    TBranch *b_trigger_data = checkAndGetBranch(tree,"trigger_data");   
    b_trigger_data->SetAddress(&trigData);
    TBranch *b_event_info = checkAndGetBranch(tree,"event_info");
    b_event_info->SetAddress(&totemEventData);
    
    // Loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0 ; i_evt < nev && i_tot < nevt_max_corr ; ++i_evt, ++i_tot){
    
      if( ((i_tot+1) % 10000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
    
      tree->GetEntry(i_evt);

      //int event_number          = trigData->event_num;
      unsigned int orbit_number = ( trigData->orbit_num )/2;
      //int bunch_number          = trigData->bunch_num;

      ULong64_t timestamp       = totemEventData->timestamp;
      histosTH1F["totemOrbit"]->Fill( orbit_number );
      histosTH1F["totemTime"]->Fill( timestamp );
      histosTH2F["totemOrbitvsTime"]->Fill( timestamp,orbit_number );

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
    error("analysis-readTOTEM <N events> <Output file name> <TOTEM data file 1> [<TOTEM data file 2>,...]");
  }

  int maxEvents = -1;
  stringstream maxEvents_ss;
  maxEvents_ss << argv[1];
  maxEvents_ss >> maxEvents;

  string outputFileName = argv[2];
  
  //string prefix = "root://eostotem/";
  string prefix = "";
  vector<string> totemFileNames;
  totemFileNames.push_back( prefix + string(argv[3]) );
  if( argc > 4)
     for(int iarg = 4; iarg < argc; ++iarg) { totemFileNames.push_back( prefix + string(argv[iarg]) ); }

  ostringstream oss;
  oss << "List of TOTEM files: " << endl;
  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file) oss << "\t" << *it_file << endl; 

  cout << "Output file name: " << outputFileName << endl
       << "Number of events to be processed: " << maxEvents << endl;
  cout << oss.str(); 

  //const string totemTreeName = "totem";
  //const string totemTreeName = "TotemNtuple";
  //const string cmsTreeName   = "cms";
  //const string cmsTreeName   = "evt";
  analysis_readTOTEM(totemFileNames, outputFileName, maxEvents);
  return 0;
}
