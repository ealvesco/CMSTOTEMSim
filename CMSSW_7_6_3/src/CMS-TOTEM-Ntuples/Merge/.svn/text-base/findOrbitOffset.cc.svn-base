#include <TFile.h>
#include <TH1I.h>

#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"

#include "utilities.h"

#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

const int maxDeltaBX = 10;
const int maxDeltaOrbit = 500;
unsigned int countTOTwrongBX = 0;
const bool lostEvtChck = false; // print-outs

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
 * This function compares two cms events. First, it compares orbit numbers and then (if equal)
 * bunch numbers.
 */
bool sortEvtCMS(MyEvtId const& event1, MyEvtId const& event2) {
	if (event1.Orbit != event2.Orbit) {
		return (event1.Orbit < event2.Orbit);
	} else {
		return (event1.Bunch < event2.Bunch);
	}
	return true; //this is just to avoid compilator warnings
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

/**
 * This function returns sorted vector of cms events. The vector includes just these cms events that
 * correspond to totem events (according to orbit number + some margin).
 * The sorting is necessary before finding the orbit offset.
 *
 * totemOrbitMin - orbit number of the first totem event that will be used for offset searching
 * totemOrbitMax - orbit number of the last totem event that will be used for offset searching
 */
vector<MyEvtId> getSortedCmsInfo( TTree *tree_cms, unsigned int totemOrbitMin,
		                                   unsigned int totemOrbitMax,
                                                   int cmsFirstLumi, int cmsLastLumi ) {

	const unsigned int orbitMargin = 2000; //just for safety we take some more events

        bool selectHLT = false;

        vector<string> hltPathNames;
        //hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part0_v1");
        //hltPathNames.push_back("HLT_L1TOTEM1_MinBias_part1_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part0_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part1_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part2_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part3_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part4_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part5_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part6_v1");
        hltPathNames.push_back("HLT_L1TOTEM3_RomanPotsTTBB_part7_v1");
        
        bool selectLumi = true;
        //unsigned int firstLumi =  88;
        //unsigned int lastLumi  = 141;
        //unsigned int firstLumi =  78;
        //unsigned int lastLumi  = 103;

	unsigned int cmsSize = tree_cms->GetEntries();
	MyEvtId  *cmsEventEvtId = 0;
	MyHLTrig *cmsEventHLT   = 0;
	TBranch *cmsEventBranchEvtId = checkAndGetBranch(tree_cms, "evtId");
	TBranch *cmsEventBranchHLT   = checkAndGetBranch(tree_cms, "HLTrig");
	cmsEventBranchEvtId->SetAddress(&cmsEventEvtId);
	cmsEventBranchHLT->SetAddress(&cmsEventHLT);

	vector<MyEvtId> vectorCmsEvents;
	int min = totemOrbitMin - orbitMargin;
	int max = totemOrbitMax + orbitMargin;

	for (unsigned int i = 0; i < cmsSize; i++) { //choose cms events within given orbit range
	   //cmsEventBranch->GetEntry(i);
	   tree_cms->GetEntry(i); 

	   if( selectHLT ){
	      bool accept = false; 
	      map<string,bool>::iterator it_hlt = (*cmsEventHLT).HLTmap.begin();
	      map<string,bool>::iterator it_hlt_end = (*cmsEventHLT).HLTmap.end();
	      for(; it_hlt != it_hlt_end; ++it_hlt){
		 string const& hltName = it_hlt->first;
		 vector<string>::const_iterator it_pos = find(hltPathNames.begin(),hltPathNames.end(),hltName);
		 if(it_pos != hltPathNames.end()){
		    //size_t idx = it_pos - hltPathNames.begin();
		    if( it_hlt->second ) { accept = true; break; }
		 }
	      }

	      if( !accept ) continue;
	   }

	   /*if( selectLumi ){
             if( cmsEventEvtId->LumiSect < firstLumi || cmsEventEvtId->LumiSect > lastLumi ) continue;
           }*/

	   if( selectLumi ){
	      if( cmsFirstLumi > 0 && cmsEventEvtId->LumiSect < (unsigned int) cmsFirstLumi ) continue;
	      if( cmsLastLumi > 0 && cmsEventEvtId->LumiSect > (unsigned int) cmsLastLumi ) continue;
	   }

	   if (cmsEventEvtId->Orbit > min && cmsEventEvtId->Orbit < max) {
	      vectorCmsEvents.push_back(*(cmsEventEvtId));
	   }
	}
	sort(vectorCmsEvents.begin(), vectorCmsEvents.end(), sortEvtCMS);
	return vectorCmsEvents;
}

/**
 * The aim of this function is to find and return orbit offset. (cms.orbit - totem.orbit).
 * The cmsInfo vector must be sorted.
 * cmsInfo - vector of sorted cms events (these events correspond to totem events (orbit range)
 * totem - vector of totem events (not all events just a sample of a given number (you can set variable in the code "const int n_totem")
 */
void calculateOrbitOffset( vector<MyEvtId> const& cmsEvents, vector<info> const& totem,
                           int *nmatchorb, int *nmatchall, TH1I *hScanOffset, TH1I *hScanOffset_match, TH1I *hBcnDelta ) {

	unsigned int cmsSize = cmsEvents.size();
	unsigned int totemSize = totem.size();
	cout << "Scanning totem...\n";
	for (unsigned int iScanTotem = 0; iScanTotem < totemSize; ++iScanTotem) { //for every totem event from sample
		cout << "\t" << iScanTotem << endl;
		// checking totem BX :
		if ((totem[iScanTotem]).bcn < dTOTEMoRxBX)
			countTOTwrongBX++;
		unsigned int i = 0;
		MyEvtId const& cmsEvent = cmsEvents[i];
		unsigned int minOrbit = (totem[iScanTotem]).orbit;
                unsigned int cmsOrbit = cmsEvent.Orbit;    
		cout << "\tTOTEM orbit: " << (totem[iScanTotem]).orbit << endl;
		if (cmsOrbit < minOrbit) { //this if is to evade the situation that after "while" statement we have i == -1
			// cms < totem - can't be => just pass
			while ((cmsOrbit < minOrbit) && (i < cmsSize)) { //find first cms event such
				MyEvtId const& cmsEvent = cmsEvents[i++]; //that cms.Orbit >= minOrbit
                                cmsOrbit = cmsEvent.Orbit;
			}
			i--;
		}
		if (cmsOrbit < minOrbit) //if we haven't found cms event that cms.Orbit >= minOrbit go to next totem event
			continue;

		cout << "\tFirst CMS orbit: " << cmsOrbit << endl;
		int deltaOrbit = cmsOrbit - (totem[iScanTotem]).orbit;
		if(deltaOrbit < 0) { cout << "\tWarning: delta(orbit) negative...Skipping." << endl; continue; }
		while ((deltaOrbit < maxDeltaOrbit) && (i < cmsSize)) { //iterate over all cms events such that cms.orbit belongs to range (totem.orbit; totem.orbit + maxOffset)
			MyEvtId const& cmsEvent = cmsEvents[i++];
                        unsigned int cmsLumi = cmsEvent.LumiSect;
                        cmsOrbit = cmsEvent.Orbit;
			deltaOrbit = cmsOrbit - (totem[iScanTotem]).orbit;
		        cout << "\t   CMS orbit, delta(orbit), LS= " << cmsOrbit << ", " << deltaOrbit << ", " << cmsLumi << endl;
			// cms is supposed to be in increasing order
			if (deltaOrbit < maxDeltaOrbit) {
				nmatchorb[deltaOrbit]++; //increase the number of possibly matched events for orbit offset == deltaOrbit
				hScanOffset->Fill(deltaOrbit);
				if (cmsEvent.Bunch - (totem[iScanTotem]).bcn == 1) {
					// cms start bcn with 1, totem with 0
		                        cout << "\t   -->matched" << endl;
					nmatchall[deltaOrbit]++; //assumes that bunch crossing offset is always 1
					hScanOffset_match->Fill(deltaOrbit);
				}
				hBcnDelta->Fill(cmsEvent.Bunch - (totem[iScanTotem]).bcn);
			}
		}
	} // end loop totem events
	cout << "Scan finished." << endl;
	float maxNmatchall = 0;
	int dOrbit = -1;
	for (int i = 0; i < maxDeltaOrbit; i++) { //find the orbit offset that has the biggest number of possibly matched events
		if (nmatchall[i] > maxNmatchall) {
			maxNmatchall = nmatchall[i];
			dOrbit = i;
		}
	}
	if (dOrbit == -1){
	   //error("can't find any matched events; exiting...\n");
	   cout << "Warning: Cannot find any matched events." << endl;
        }

        // Print some info on STDOUT:
	cout << "\n\ndOrbit (cms - totem) = " << dOrbit << "; \"eff\" wrt TOTEM/CMS = "
			<< float(maxNmatchall) / float(totemSize) << "/" << float(maxNmatchall) / float(cmsSize) 
                        <<  " (" << maxNmatchall << " matched events; "
                        << ( (dOrbit != -1) ? nmatchorb[dOrbit] : 0 ) << " matched with any bcn)" << endl;

	MyEvtId const& firstCmsEvent = cmsEvents[0];
	cout << "start : (totem : cms)\n";
	cout << (totem[0]).orbit << "\t:\t" << firstCmsEvent.Orbit << endl;
	MyEvtId const& lastCmsEvent = cmsEvents[cmsSize - 1];
	cout << "stop  : (totem : cms)\n";
	cout << (totem[totemSize - 1]).orbit << "\t:\t" << lastCmsEvent.Orbit << endl;
	cout << "totem = " << totemSize << endl;
}

/**
 * This function searches the orbit offset, creates some histograms presenting possible orbit
 * and bunch offsets and then merges the events that were used for searching.
 *
 * totemFileName - root file containing totem ntuple
 * cmsFileName - root file containing cms ntuple
 * outputFileName - root file where the histograms and sample of merged data will be stored
 */
void findOrbitOffset( const string& totemFileName, const string& cmsFileName, const string &outputFileName,
                      const string& totemTreeName, const string& cmsTreeName, int cmsFirstLumi, int cmsLastLumi ) {

	const int verbose = 0; // 0: normal, 1: little,  3: extended
	cout << "Opening Totem File: " << totemFileName << endl;
	TFile* totemFile = TFile::Open(totemFileName.c_str()); //opening input files
	if (!totemFile || totemFile->IsZombie())
		error("Error opening file");
	TTree* totemTree = (TTree*) totemFile->Get( totemTreeName.c_str() );
	if (!totemTree)
		error("No data tree found");
	cout << "Entries: " << totemTree->GetEntries() << endl;
	cout << "Opening CMS File: " << cmsFileName << endl;
	TFile* cmsFile = TFile::Open(cmsFileName.c_str());
	if (!cmsFile || cmsFile->IsZombie())
		error("Error opening file");
	//TTree *cmsTree = (TTree*) cmsFile->Get("evt");
	TTree *cmsTree = (TTree*) cmsFile->Get( cmsTreeName.c_str() );
	cout << "Entries: " << cmsTree->GetEntries() << endl;

	TFile* output = TFile::Open(outputFileName.c_str(), "RECREATE");
	if (verbose > 2) {
		cout << " cms raw sequence: nEv=" << cmsTree->GetEntries() << endl;
		cout << " totem raw sequence: nEv=" << totemTree->GetEntries() << endl;
	}
	TBranch *totemTriggerData = checkAndGetBranch(totemTree, "trigger_data");
	totemTriggerData->SetAddress(&trigData);

	vector<info> totem; //the basic totem data (trigger + bunch, orbit etc) will be stored in this vector
	const int totemSize = totemTree->GetEntries(); //number of totem events that will be used during orbit offset searching (these events are the first n_totem events chosen from the beggining of the ntuple)
	cout << "Filling totem vector... Reduced statistics \n";
	for (int i = 0; i < totemSize; ++i) { //prepare the vector of totem events
		cout << "->" << i << endl;
		totemTriggerData->GetEntry(i);
                //-----> Note TOTEM orbit divided by two
		const info info_totem(i, trigData->event_num, ( trigData->orbit_num )/2, trigData->bunch_num);
		totem.push_back(info_totem);
		if (verbose > 2)
			cout << trigData->event_num << trigData->orbit_num << " !!\n";
	}
        sort(totem.begin(), totem.end(), sortEvtTOTEM);
        cout << "First, last orbit number (TOTEM): " << totem[0].orbit << " : " << totem[totemSize - 1].orbit << endl;

	int nmatchorb[maxDeltaOrbit]; //prepare arrays and histograms with obrbit, bunch offsets
	memset(nmatchorb, 0, sizeof(nmatchorb));
	int nmatchall[maxDeltaOrbit];
	memset(nmatchall, 0, sizeof(nmatchall));
	TH1I *hScanOffset = new TH1I("hScanOffset", "hScanOffset",
			maxDeltaOrbit + 10, -10, maxDeltaOrbit);
	hScanOffset->SetXTitle("orbit_{cms}-orbit_{totem}");
	TH1I *hScanOffset_match = new TH1I("hScanOffset_match", "hScanOffset_match",
			maxDeltaOrbit + 10, -10, maxDeltaOrbit);
	hScanOffset_match->SetXTitle("orbit_{cms}-orbit_{totem}");
	hScanOffset_match->SetLineColor(2);
	TH1I *hBcnDelta = new TH1I("hBcnDelta", "hBcnDelta", maxDeltaBX * 2,
			-maxDeltaBX, maxDeltaBX);
	hBcnDelta->SetXTitle("bx_{cms}-bx_{totem}");

	vector<MyEvtId> cmsEvents = getSortedCmsInfo(cmsTree, totem[0].orbit, totem[totemSize - 1].orbit, cmsFirstLumi, cmsLastLumi);

        cout << "CMS n-tuple has " << cmsEvents.size() << " events in orbit range." << endl; 
        if( cmsEvents.size() == 0) { cout << "Warning: zero events (CMS) found in range" << endl; return; }
        cout << "First, last orbit number (CMS): " << cmsEvents[0].Orbit << " : " << cmsEvents[cmsEvents.size() - 1].Orbit << endl;

	calculateOrbitOffset(cmsEvents, totem, nmatchorb, nmatchall, hScanOffset, hScanOffset_match, hBcnDelta); // Find orbit offset

	output->Write();
	output->Flush();
}

/**
 * You can run program by typing:
 * ./findOrbitOffset totemNtuplePath cmsNtuplePath outputNtupleName
 */
int main(int argc, char** argv) {

   if (argc < 4){
      error("findOrbitOffset <TOTEM data file> <CMS data file> <output file> [<first CMS lumi>] [<last CMS lumi>] [<TOTEM Tree name>] [<CMS Tree name>]");
   }

   const string totem(argv[1]);
   const string cms(argv[2]);
   const string output(argv[3]);

   int cmsFirstLumi = -1;
   int cmsLastLumi  = -1;
   stringstream cmsFirstLumiStream;
   stringstream cmsLastLumiStream;
   if(argc > 4) { cmsFirstLumiStream << argv[4]; cmsFirstLumiStream >> cmsFirstLumi; }
   if(argc > 5) { cmsLastLumiStream << argv[5]; cmsLastLumiStream >> cmsLastLumi; }

   /*const string totemTreeName = "totem";
   const string cmsTreeName   = "cms";*/
   string totemTreeName = "TotemNtuple";
   string cmsTreeName   = "evt";
   if(argc > 6) totemTreeName = string( argv[6] );
   if(argc > 7) cmsTreeName = string( argv[7] );

   cout << "TOTEM file name: " << totem << endl
        << "CMS file name: " << cms << endl
        << "TOTEM Tree name: " << totemTreeName << endl
        << "CMS Tree name: " << cmsTreeName << endl
        << "CMS first lumi section: " << cmsFirstLumi << endl
        << "CMS last lumi section: " << cmsLastLumi << endl;

   findOrbitOffset(totem, cms, output, totemTreeName, cmsTreeName, cmsFirstLumi, cmsLastLumi);
   return 0;
}
