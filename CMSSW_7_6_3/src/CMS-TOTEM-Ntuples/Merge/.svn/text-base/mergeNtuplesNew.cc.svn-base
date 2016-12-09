#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"
#include "UATree/UADataFormat/interface/MyTracks.h"
#include "UATree/UADataFormat/interface/MyVertex.h"
#include "UATree/UADataFormat/interface/MyPFJet.h"
#include "UATree/UADataFormat/interface/MyCaloJet.h"
#include "UATree/UADataFormat/interface/MyMuon.h"
#include "UATree/UADataFormat/interface/MyElectron.h"
#include "UATree/UADataFormat/interface/MyPFCand.h"
#include "UATree/UADataFormat/interface/MyCaloTower.h"
#include "UATree/UADataFormat/interface/MyMet.h"
#include "UATree/UADataFormat/interface/MyFSCInfo.h"
#include "UATree/UADataFormat/interface/MyFSCHit.h"
#include "UATree/UADataFormat/interface/MyFSCDigi.h"
#include "UATree/UADataFormat/interface/MyBeamSpot.h"
#include "UATree/UADataFormat/interface/MyKshorts.h"
#include "UATree/UADataFormat/interface/MyLambdas.h"

#include "utilities.h"

#include <map>
#include <algorithm>
#include <sstream>
#include <limits>

#include <time.h>
#include <stdio.h>

using namespace std;

void errorBranch(string const& branchName) { error(" No data branch " + branchName + " found in input file!"); }

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

void setChainBranch(TChain* chain, string const& branchName, void* data_ptr) {
  Int_t err = 0;
  err = chain->SetBranchAddress( branchName.c_str(),data_ptr );
  if( err == TTree::kMissingBranch ) errorBranch( branchName );
}

/**
 * This function compares two TOTEM events. First, it compares orbit numbers and then (if equal)
 * bunch numbers.
 */
bool sortEvtTOTEM(info const& event1, info const& event2) {
	if (event1.orbit != event2.orbit) {
		return (event1.orbit < event2.orbit);
	} else {
		return (event1.bcn < event2.bcn);
	}
	return true; //this is just to avoid compilator warnings
}

class findEvtByIndex{
   public:
      findEvtByIndex(int idx): idx_(idx) {}
      bool operator()(info const& info_) const { return ( info_.i == idx_ ); }
   private:
      int idx_; 
};

class totemChainRPSetBranchAddress{
   public:
      totemChainRPSetBranchAddress(TChain* chain): chain_(chain) {}

      void operator()(unsigned int rp_id, TTree* outputTree = 0) const {
	 char br_name[200];

	 if (includeDigi) {
	    sprintf(br_name, "digi_rp_%u.", rp_id);
	    setChainBranch(chain_, br_name, &digi_info_[rp_id]);
	    cout << "Set input branch " << br_name << endl; 

	    if(outputTree) {
	       outputTree->Branch(br_name, &digi_info_[rp_id]);
	       cout << "Set output branch " << br_name << endl; 
	    } 
	 }

	 if (includePatterns) {
	    sprintf(br_name, "par_patterns_rp_%u.", rp_id);
	    setChainBranch(chain_, br_name, &par_patterns_info_[rp_id]);
	    cout << "Set input branch " << br_name << endl; 

	    if(outputTree) {
	       outputTree->Branch(br_name, &par_patterns_info_[rp_id]);
	       cout << "Set output branch " << br_name << endl; 
	    }

	    sprintf(br_name, "nonpar_patterns_rp_%u.", rp_id);
	    setChainBranch(chain_, br_name, &nonpar_patterns_info_[rp_id]);
	    cout << "Set input branch " << br_name << endl; 

	    if(outputTree) {
	       outputTree->Branch(br_name, &nonpar_patterns_info_[rp_id]);
	       cout << "Set output branch " << br_name << endl; 
	    }
	 }

	 sprintf(br_name, "track_rp_%u.", rp_id);
	 setChainBranch(chain_, br_name, &track_info_[rp_id]);
	 cout << "Set input branch " << br_name << endl; 

	 if(outputTree) {
	    outputTree->Branch(br_name, &track_info_[rp_id]);
	    cout << "Set output branch " << br_name << endl; 
	 } 

	 if (includeMultiTracks) {
	    sprintf(br_name, "multi_track_rp_%u", rp_id);
	    setChainBranch(chain_, br_name, &multi_track_info_[rp_id]);
	    cout << "Set input branch " << br_name << endl; 

	    if(outputTree) {
	       outputTree->Branch(br_name, &multi_track_info_[rp_id]);
	       cout << "Set output branch " << br_name << endl; 
	    } 
	 }
      }

   private:
      TChain* chain_;
};

template <class Impl>
void doTOTEMRPBranches(Impl const& impl_, TTree* outputTree = 0) {

  char br_name[200];
  // Digis, patterns and tracks 
  for (unsigned int a = 0; a < 2; ++a) { 
    // Iterate over RP ids
    for(unsigned int s = 0; s<=2; s+=2) {
      for (unsigned int r = 0; r < 6; r++) {
        unsigned int id = 100 * a + 10 * s + r;
        impl_( id , outputTree );
      }
    }
  }
}

/**
 * This function merges the totem and cms ntuples. The result is saved in outputFileName.
 **/
pair<int,int> mergeNtuples(const int dOrbit, TTree* cmsTree,
                                             TChain* totemChain,
                                             const string &outputFileName,
                           ULong_t cmsRunNo, int cmsFirstLumi, int cmsLastLumi) {

  bool debug = false;

  bool selectHLT  = false;
  bool selectLumi = true;
  bool mergeFull  = true; 

  // For debugging (selectHLT = true) 
  vector<string> hltPathNames;

  // TOTEM Trigger info
  // 
  totemChain->SetBranchStatus("*",0);
  totemChain->SetBranchStatus("trigger_data*",1);

  setChainBranch(totemChain, "trigger_data.", &trigData);
  
  cout << "Filling TOTEM trigger/event info." << endl; 

  auto totem = new vector<info>;

  // This map helps in searching for totem event with given orbit number
  // key - orbit number, value - vector of totem event info that have this orbit number
  auto totemOrbits = new map<unsigned int, vector<info> >; 
  map<unsigned int, vector<info> >::iterator it;
  const int totemSize = totemChain->GetEntries();
  for (int i = 0; i < totemSize; ++i)
  {
    totemChain->GetEntry(i);

    //-----> Note TOTEM orbit divided by two
    const info totemInfo(i, trigData->event_num, ( trigData->orbit_num )/2, trigData->bunch_num);
    totem->push_back(totemInfo);

    //unsigned int orbitNumber = trigData->orbit_num;
    unsigned int orbitNumber = totem->back().orbit;
    it = totemOrbits->find(orbitNumber);
    if (it != totemOrbits->end())
    { //if keys exist add to the existing vector
      it->second.push_back(totemInfo);
    }
    else
    { //if not create a vector for given orbit number
      vector<info> vect;
      vect.push_back(totemInfo);
      totemOrbits->insert( pair<int, vector<info> >(orbitNumber, vect) );
    }
  }
  cout << "Sorting TOTEM events.."; 
  sort(totem->begin(), totem->end(), sortEvtTOTEM);
  cout << " done." << endl;

  unsigned int firstCMSorbit = ( totem->at(0) ).orbit + dOrbit;
  unsigned int lastCMSorbit  = ( totem->at(totemSize - 1) ).orbit + dOrbit;
  cout << "First, last CMS orbit: " << firstCMSorbit << ", " << lastCMSorbit << endl;
  
  delete totem;

  cout << "Building input definition and output Tree." << endl; 

  // CMS branches
  MyEvtId *evtcmsUA = nullptr;
  TBranch *b_cms_evtId = checkAndGetBranch(cmsTree, "evtId");
  b_cms_evtId->SetAddress(&evtcmsUA);

  MyHLTrig *hltTrig_cmsUA = nullptr;
  TBranch *b_cms_hltTrig = checkAndGetBranch(cmsTree, "HLTrig");
  b_cms_hltTrig->SetAddress(&hltTrig_cmsUA);

  MyL1TrigOld*         trigcmsUA = 0;
  vector<MyTracks>*    tracks_cmsUA = 0;
  vector<MyVertex>*    vertices_cmsUA = 0;
  vector<MyPFJet>*     ak4PFJets_cmsUA = 0;
  vector<MyMuon>*      muons_cmsUA = 0;
  vector<MyElectron>*  electrons_cmsUA = 0;
  vector<MyPFCand>*    pFlow_cmsUA = 0;
  vector<MyCaloTower>* caloTowers_cmsUA = 0;
  vector<MyMet>*       pfMet_cmsUA = 0;
  MyBeamSpot*          offlinebeamspot_cmsUA = 0;
  vector<MyKshorts>*   kshort_cmsUA = 0;
  vector<MyLambdas>*   lambda_cmsUA = 0;

  if(mergeFull){
     checkAndGetBranch(cmsTree, "L1TrigOld")->SetAddress(&trigcmsUA);

     checkAndGetBranch(cmsTree, "generalTracks")->SetAddress(&tracks_cmsUA);
     checkAndGetBranch(cmsTree, "offlinePrimaryVertices")->SetAddress(&vertices_cmsUA);

     checkAndGetBranch(cmsTree, "ak4PFJets")->SetAddress(&ak4PFJets_cmsUA);

     checkAndGetBranch(cmsTree, "muons")->SetAddress(&muons_cmsUA);
     checkAndGetBranch(cmsTree, "gedGsfElectrons")->SetAddress(&electrons_cmsUA);

     checkAndGetBranch(cmsTree, "particleFlow")->SetAddress(&pFlow_cmsUA);
     checkAndGetBranch(cmsTree, "caloTowers")->SetAddress(&caloTowers_cmsUA);
     checkAndGetBranch(cmsTree, "pfMet")->SetAddress(&pfMet_cmsUA);
     checkAndGetBranch(cmsTree, "offlineBeamSpot")->SetAddress(&offlinebeamspot_cmsUA);

     checkAndGetBranch(cmsTree, "Kshort")->SetAddress(&kshort_cmsUA);
     checkAndGetBranch(cmsTree, "Lambda")->SetAddress(&lambda_cmsUA);
  }

  TFile* output = TFile::Open(outputFileName.c_str(), "RECREATE");
  TTree* outputTree = new TTree("cms_totem", "merged");

  outputTree->Branch("cmsEvtUA"    , &evtcmsUA);
  outputTree->Branch("cmsHLTTrigUA", &hltTrig_cmsUA);
  if(mergeFull){  
     outputTree->Branch("cmsTrigUA", &trigcmsUA);

     outputTree->Branch("cmsTracksUA", &tracks_cmsUA);
     outputTree->Branch("cmsVerticesUA", &vertices_cmsUA);

     outputTree->Branch("cmsak4PFJetsUA", &ak4PFJets_cmsUA);

     outputTree->Branch("cmsMuonsUA", &muons_cmsUA);
     outputTree->Branch("cmsElectronsUA", &electrons_cmsUA);

     outputTree->Branch("cmsParticleFlowUA", &pFlow_cmsUA);
     outputTree->Branch("cmsCaloTowersUA", &caloTowers_cmsUA);
     outputTree->Branch("cmsPFMETUA", &pfMet_cmsUA);
     outputTree->Branch("offlineBeamSpot", &offlinebeamspot_cmsUA);

     outputTree->Branch("Kshort", &kshort_cmsUA);
     outputTree->Branch("Lambda", &lambda_cmsUA);
  }
  
  // TOTEM
  totemChain->SetBranchStatus("*",0);
  totemChain->SetBranchStatus("trigger_data*",1);
  totemChain->SetBranchStatus("event_info*",1);
  totemChain->SetBranchStatus("rec_prot_left*",1);
  totemChain->SetBranchStatus("rec_prot_right*",1);
  if (includeDigi) totemChain->SetBranchStatus("digi_rp_*",1);
  if (includePatterns) {
     totemChain->SetBranchStatus("par_patterns_rp_*",1);
     totemChain->SetBranchStatus("nonpar_patterns_rp_*",1);
  }
  totemChain->SetBranchStatus("track_rp_*",1);
  if (includeMultiTracks) totemChain->SetBranchStatus("multi_track_rp_*",1);

  string branchName = "trigger_data.";
  setChainBranch(totemChain, branchName, &trigData);
  cout << "Set input branch " << branchName << endl;
  outputTree->Branch(branchName.c_str(), &trigData);
  cout << "Set output branch " << branchName << endl;

  branchName = "event_info.";
  setChainBranch(totemChain, branchName, &totemEventData);
  cout << "Set input branch " << branchName << endl;
  outputTree->Branch(branchName.c_str(), &totemEventData);
  cout << "Set output branch " << branchName << endl;

  branchName = "rec_prot_left.";
  setChainBranch(totemChain, branchName, &recProtLeft);
  cout << "Set input branch " << branchName << endl;
  outputTree->Branch(branchName.c_str(), &recProtLeft);
  cout << "Set output branch " << branchName << endl;

  branchName = "rec_prot_right.";
  setChainBranch(totemChain, branchName, &recProtRight);
  cout << "Set input branch " << branchName << endl;
  outputTree->Branch(branchName.c_str(), &recProtRight);
  cout << "Set output branch " << branchName << endl;

  doTOTEMRPBranches( totemChainRPSetBranchAddress(totemChain) , outputTree );

  if(debug) totemChain->Print();

  int matchingEventsCounter = 0;
  unsigned int countCms = 0;
  unsigned int countCmsLumi = 0;
  unsigned int countCmsNoMatch = 0;

  cout << "Start running over CMS events." << endl; 
  unsigned int cmsSize = cmsTree->GetEntries();
  for (unsigned int cms_i = 0; cms_i < cmsSize; cms_i++)
  { 
    b_cms_evtId->GetEntry(cms_i);
    b_cms_hltTrig->GetEntry(cms_i);

    if(evtcmsUA->Run != cmsRunNo)
    {
      cout << "[WARNING] CMS Run " << evtcmsUA->Run << " != " << cmsRunNo << endl;
      continue;
    }

    if( selectHLT ){
       bool acceptHLT = false; 
       map<string,bool>::iterator it_hlt = (*hltTrig_cmsUA).HLTmap.begin();
       map<string,bool>::iterator it_hlt_end = (*hltTrig_cmsUA).HLTmap.end();
       for(; it_hlt != it_hlt_end; ++it_hlt){
	  string const& hltName = it_hlt->first;
	  vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
	  if(it_pos != hltPathNames.end()){
	     //size_t idx = it_pos - hltPathNames.begin();
	     if( it_hlt->second ) {
                if(debug) cout << "Event accepted by passing trigger: " << hltName << endl; 
                acceptHLT = true;
                break; }
	  }
       }
       if( !acceptHLT ) { cout << "Event did not pass any of selected triggers." << endl; continue; }
    }

    if( selectLumi ){
       if( cmsFirstLumi > 0 && evtcmsUA->LumiSect < (unsigned int) cmsFirstLumi ) {
          if(debug) cout << "Event lumi section is below selected range. LS = " << evtcmsUA->LumiSect << endl;
          continue; }
       if( cmsLastLumi > 0 && evtcmsUA->LumiSect > (unsigned int) cmsLastLumi ) {
          if(debug) cout << "Event lumi section is above selected range. LS = " << evtcmsUA->LumiSect << endl;
          continue; }
    }

    ++countCmsLumi;

    if(debug) cout << cms_i << "\t\t" << evtcmsUA->LumiSect << "\t\t" << evtcmsUA->Orbit << "\t\t" << evtcmsUA->Bunch << endl;

    if (cleanBX && !collidingBunch(evtcmsUA->Bunch))
    {
      cout << "Non colliding bunch.. skipping." << endl;
      continue;
    }
    if (((unsigned int) evtcmsUA->Orbit >= firstCMSorbit)
        && ((unsigned int) evtcmsUA->Orbit <= lastCMSorbit)) {
       ++countCms;
    } else {
      continue;
    }

    unsigned int totemOrbitCorrected = evtcmsUA->Orbit - dOrbit;
    bool match = false;
    it = totemOrbits->find(totemOrbitCorrected);
    if (it != totemOrbits->end())
    {
      vector<info> totemEvents = it->second;
      // Iterate over totem events with given orbit number and find one that has a proper bunch crossing number
      for (unsigned int i = 0; (i < totemEvents.size()) && !match; i++)
      {
        info const& totemInfo = totemEvents.at(i);
        int index = totemInfo.i;
        int bunch = totemInfo.bcn;
        if ( (evtcmsUA->Bunch - bunch) == 1 )
        {
          totemChain->GetEntry(index);
          cmsTree->GetEntry(cms_i);

          // Fill the output ntuple
          outputTree->Fill();

          match = true;
          ++matchingEventsCounter;
    
          cout << "Matched event (LS, TOTEM orbit, CMS orbit, Orbit difference, TOTEM Bunch, CMS Bunch, Bunch difference): "
               << evtcmsUA->LumiSect << "\t" << totemInfo.orbit << "\t" << evtcmsUA->Orbit << "\t"
               << evtcmsUA->Orbit - totemInfo.orbit << "\t" << bunch << "\t"
               << evtcmsUA->Bunch << "\t" << evtcmsUA->Bunch - bunch << endl;
        }
      }
    }
    if (!match && ((unsigned int) evtcmsUA->Orbit >= firstCMSorbit)
        && ((unsigned int) evtcmsUA->Orbit <= lastCMSorbit))
    {
      ++countCmsNoMatch;
    }

  } // end loop cms events

  if(debug) outputTree->Print();
  output->cd();
  outputTree->Write();
  output->Close();

  if (matchingEventsCounter == 0) { 
    if ( remove( outputFileName.c_str() ) != 0 )
      error("Error deleting file");
  }

  cout << "Use only colliding BXs (0/1) = " << cleanBX << endl;
  cout << "Number of matching events                                  = " << matchingEventsCounter << endl;
  cout << "Number of CMS events in LS range                           = " << countCmsLumi << endl;
  cout << "Number of CMS events in LS and Orbit range                 = " << countCms << endl;
  cout << "Number of CMS events in LS and Orbit range without a match = " << countCmsNoMatch << endl;

  return pair<int,int>(matchingEventsCounter,countCmsLumi);

}

void mergeNtuples(const int dOrbit, const string& cmsFileName,
                         const vector<string>& totemFileNames,
                         const string &outputFileName,
                         ULong_t cmsRunNo, int cmsFirstLumi, int cmsLastLumi,
                         const string& cmsTreeName, const string& totemTreeName) {

  cout << "CMS File: " << cmsFileName << endl;

  TChain* chain_totem = new TChain( totemTreeName.c_str() );

  ostringstream oss; 
  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file){
      string const& totemFileName = *it_file; 
      chain_totem->Add( totemFileName.c_str() ); 
      oss << "Totem File: " << totemFileName << endl;
  }
  cout << oss.str();
  unsigned int totemSize = chain_totem->GetEntries();
  cout << "TOTEM entries: " << totemSize << endl;

  cout << "Opening CMS File: " << cmsFileName << endl;
  TFile* cmsFile = TFile::Open(cmsFileName.c_str());
  if (!cmsFile || cmsFile->IsZombie())
    error("Error opening file");
  TTree * cmsTree = (TTree*) cmsFile->GetObjectChecked( cmsTreeName.c_str(),"TTree" );
  unsigned int cmsSize = cmsTree->GetEntries();
  cout << "CMS entries: " << cmsSize << endl;

  auto count = mergeNtuples(dOrbit, cmsTree, chain_totem, outputFileName, cmsRunNo, cmsFirstLumi, cmsLastLumi);

  cout << "Total number of events merged/CMS = " << count.first << " / " << count.second << endl;

}

/**
 * You can use this program by typing:
 * ./mergeNtuples totemNtuplePath cmsNtuplePath outputNtuple
 */
int main(int argc, char** argv) {
  if (argc < 8)
  {
    //error("Please specify TOTEM and CMS data files, output file, totem run number, cms run number and offset difference.");
    //error("mergeNtuples <TOTEM data file> <CMS data file> <output file> <CMS run number> <offset> [<first CMS lumi>] [<last CMS lumi>]");
    error("mergeNtuplesNew <CMS run number> <offset> <first CMS lumi> <last CMS lumi> <Output file name> <CMS data file> <TOTEM data file 1> [<TOTEM data file 2>,...]");
  }

  ULong_t cmsRunNo;
  stringstream cmsRunNoStream;
  cmsRunNoStream << argv[1];
  cmsRunNoStream >> cmsRunNo;

  int offset;
  stringstream offsetStream;
  offsetStream << argv[2];
  offsetStream >> offset;

  int cmsFirstLumi = -1;
  int cmsLastLumi  = -1;
  stringstream cmsFirstLumiStream;
  stringstream cmsLastLumiStream;
  cmsFirstLumiStream << argv[3]; cmsFirstLumiStream >> cmsFirstLumi;
  cmsLastLumiStream << argv[4]; cmsLastLumiStream >> cmsLastLumi;

  const string cmsTreeName( "evt" );
  const string totemTreeName( "TotemNtuple" );
 
  const string outputFileName(argv[5]);
  const string cmsFileName(argv[6]);

  //string prefix = "root://eostotem/";
  string prefix = "";
  vector<string> totemFileNames;
  totemFileNames.push_back( prefix + string(argv[7]) );
  if( argc > 8)
     for(int iarg = 8; iarg < argc; ++iarg) { totemFileNames.push_back( prefix + string(argv[iarg]) ); }

  ostringstream oss;
  oss << "List of TOTEM files: " << endl;
  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file) oss << "\t" << *it_file << endl; 

  cout << "CMS Run number: " << cmsRunNo << endl
       << "CMS Tree name: " << cmsTreeName << endl
       << "TOTEM Tree name: " << totemTreeName << endl
       << "CMS-TOTEM orbit offset: " << offset << endl
       << "CMS first lumi section: " << cmsFirstLumi << endl
       << "CMS last lumi section: " << cmsLastLumi << endl;
  cout << "CMS file: " << cmsFileName << endl; 
  cout << "Output file: " << outputFileName << endl; 
  cout << oss.str(); 

  mergeNtuples(offset, cmsFileName, totemFileNames, outputFileName, cmsRunNo, cmsFirstLumi, cmsLastLumi, cmsTreeName, totemTreeName);
  return 0;
}
