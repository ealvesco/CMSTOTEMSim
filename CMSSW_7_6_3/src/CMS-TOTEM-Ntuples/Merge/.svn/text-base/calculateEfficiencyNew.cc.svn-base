#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"

#include "utilities.h"

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <limits>

#include <time.h>
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

void errorBranch(string const& branchName) { error(" No data branch " + branchName + " found in input file!"); }

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
      bool operator()(info const& info_) { return ( info_.i == idx_ ); }
   private:
      int idx_; 
};

/**
 * This function counts the matching events between the totem and cms ntuples.
 * dOrbit is the previously found orbit offset 
 * cmsRunNo - cms Run number
 */
pair<int,int> calculateEfficiency(const int dOrbit, TTree* cmsTree, TChain& totemChain,
                                  ULong_t cmsRunNo, int cmsFirstLumi, int cmsLastLumi) {

  bool debug = false;

  bool selectHLT  = false;
  bool selectLumi = true;

  vector<string> hltPathNames;
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part0_v1");
  hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part1_v1");

  MyEvtId *evtcmsUA = nullptr;
  TBranch *b_cms_evtId = checkAndGetBranch(cmsTree, "evtId");
  b_cms_evtId->SetAddress(&evtcmsUA);

  MyHLTrig *hltTrig_cmsUA = nullptr;
  TBranch *b_cms_hltTrig = checkAndGetBranch(cmsTree, "HLTrig");
  b_cms_hltTrig->SetAddress(&hltTrig_cmsUA);

  totemChain.SetBranchStatus("*",0);
  totemChain.SetBranchStatus("trigger_data*",1);
  //totemChain.SetBranchStatus("event_info*",1);

  Int_t err = 0;
  err = totemChain.SetBranchAddress("trigger_data.",&trigData);
  if( err == TTree::kMissingBranch ) errorBranch( "trigger_data" );
  
  //err = totemChain.SetBranchAddress("event_info.",&totemEventData);
  //if( err == TTree::kMissingBranch ) errorBranch( "event_info" );

  cout << "Filling TOTEM event info." << endl; 

  vector<info> totem; // This vector contains only basic information about totem events
  // This map helps in searching for totem event with given orbit number
  // key - orbit number, value - vector of totem event info that have this orbit number
  map<unsigned int, vector<info> > totemOrbits; 
  map<unsigned int, vector<info> >::iterator it;
  const int totemSize = totemChain.GetEntries();
  for (int i = 0; i < totemSize; ++i)
  {
    totemChain.GetEntry(i);

    //-----> Note TOTEM orbit divided by two
    const info totemInfo(i, trigData->event_num, ( trigData->orbit_num )/2, trigData->bunch_num);
    totem.push_back(totemInfo);

    //unsigned int orbitNumber = trigData->orbit_num;
    unsigned int orbitNumber = totem.back().orbit;
    it = totemOrbits.find(orbitNumber);
    if (it != totemOrbits.end())
    { //if keys exist add to the existing vector
      it->second.push_back(totemInfo);
    }
    else
    { //if not create a vector for given orbit number
      vector<info> vect;
      vect.push_back(totemInfo);
      totemOrbits.insert( pair<int, vector<info> >(orbitNumber, vect) );
    }
  }
  cout << "Sorting TOTEM events.."; 
  sort(totem.begin(), totem.end(), sortEvtTOTEM);
  cout << " done." << endl;

  int matchingEventsCounter = 0;
  unsigned int firstCMSorbit = (totem[0]).orbit + dOrbit;
  unsigned int lastCMSorbit = (totem[totemSize - 1]).orbit + dOrbit;
  unsigned int countCms = 0;
  unsigned int countCmsLumi = 0;
  unsigned int countCmsNoMatch = 0;

  cout << "Start running over CMS events." << endl; 
  cout << "First, last CMS orbit: " << firstCMSorbit << ", " << lastCMSorbit << endl;
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
    { //if bunch is not colliding
      cout << "Non colliding bunch.. skipping." << endl;
      continue;
    }
    if (((unsigned int) evtcmsUA->Orbit >= firstCMSorbit)
        && ((unsigned int) evtcmsUA->Orbit <= lastCMSorbit))
    { //in this we should be able to find corresponding event in totem vector
      ++countCms;
    }
    else
    {
      continue;
    }
    unsigned int totemOrbitCorrected = evtcmsUA->Orbit - dOrbit;
    bool match = false;
    it = totemOrbits.find(totemOrbitCorrected);
    if (it != totemOrbits.end())
    {
      vector<info> totemEvents = it->second;
      for (unsigned int i = 0; (i < totemEvents.size()) && !match; i++)
      { // Iterate over totem events with given orbit number and find one that has a proper bunch crossing number
        info const& totemInfo = totemEvents.at(i);
        //int index = totemInfo.i;
        int bunch = totemInfo.bcn;
        if ( (evtcmsUA->Bunch - bunch) == 1 )
        {
          ++matchingEventsCounter;
          match = true;
    
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

  // Print some basic information to STDOUT
  //cout << "CMS File: " << cmsFileName << endl;
  //cout << "Totem File: " << totemFileName << endl;
  cout << "Use only colliding BXs (0/1) = " << cleanBX << endl;
  cout << "Number of matching events                                  = " << matchingEventsCounter << endl;
  cout << "Number of CMS events in LS range                           = " << countCmsLumi << endl;
  cout << "Number of CMS events in LS and Orbit range                 = " << countCms << endl;
  cout << "Number of CMS events in LS and Orbit range without a match = " << countCmsNoMatch << endl;

  return pair<int,int>(matchingEventsCounter,countCmsLumi);
}

void calculateEfficiency(const int dOrbit, const string& cmsFileName,
                         const vector<string>& totemFileNames,
                         ULong_t cmsRunNo, int cmsFirstLumi, int cmsLastLumi,
                         const string& cmsTreeName, const string& totemTreeName) {

  cout << "CMS File: " << cmsFileName << endl;

  TChain chain_totem( totemTreeName.c_str() );

  ostringstream oss; 
  vector<string>::const_iterator it_file     = totemFileNames.begin();
  vector<string>::const_iterator it_file_end = totemFileNames.end();
  for(; it_file != it_file_end; ++it_file){
      string const& totemFileName = *it_file; 
      chain_totem.Add( totemFileName.c_str() ); 
      oss << "Totem File: " << totemFileName << endl;
  }
  cout << oss.str();
  unsigned int totemSize = chain_totem.GetEntries();
  cout << "TOTEM entries: " << totemSize << endl;

  cout << "Opening CMS File: " << cmsFileName << endl;
  TFile* cmsFile = TFile::Open(cmsFileName.c_str());
  if (!cmsFile || cmsFile->IsZombie())
    error("Error opening file");
  TTree * cmsTree = (TTree*) cmsFile->GetObjectChecked( cmsTreeName.c_str(),"TTree" );
  unsigned int cmsSize = cmsTree->GetEntries();
  cout << "CMS entries: " << cmsSize << endl;

  auto count = calculateEfficiency(dOrbit, cmsTree, chain_totem, cmsRunNo, cmsFirstLumi, cmsLastLumi);

  cout << "Total number of events merged/CMS = " << count.first << " / " << count.second << endl;

}

/**
 * You can use this program by typing:
 * ./calculateEfficiency <CMS run number> <offset> <first CMS lumi> <last CMS lumi> <CMS data file> <TOTEM data file 1> [<TOTEM data file 2>,...]
 */
int main(int argc, char** argv) {
  if (argc < 9)
  {
    error("calculateEfficiency <CMS run number> <offset> <first CMS lumi> <last CMS lumi> <CMS Tree name> <TOTEM Tree name> <CMS data file> <TOTEM data file 1> [<TOTEM data file 2>,...]");
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

  //const string totemTreeName = "totem";
  //const string totemTreeName = "TotemNtuple";
  //const string cmsTreeName   = "cms";
  //const string cmsTreeName   = "evt";
  const string cmsTreeName(argv[5]);
  const string totemTreeName(argv[6]);
 
  const string cmsFileName(argv[7]);

  //string prefix = "root://eostotem/";
  string prefix = "";
  vector<string> totemFileNames;
  totemFileNames.push_back( prefix + string(argv[8]) );
  if( argc > 9)
     for(int iarg = 9; iarg < argc; ++iarg) { totemFileNames.push_back( prefix + string(argv[iarg]) ); }

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
  cout << oss.str(); 

  calculateEfficiency(offset, cmsFileName, totemFileNames, cmsRunNo, cmsFirstLumi, cmsLastLumi, cmsTreeName, totemTreeName);
  return 0;
}
