
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

//#include "TriggerData.h"
//#include "EventMetaData.h"
#include "RPRootDumpReconstructedProton.h"
#include "RPRootDumpTrackInfo.h"
//#include "RPRootDumpReconstructedProton.h"
////#include "RPRootDumpReconstructedProtonPair.h"
////#include "RPRootDumpTrackInfo.h"

//#include "analysis_tools.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "Math/PxPyPzE4D.h"
#include "Math/LorentzVector.h"
#include "TLorentzVector.h"
#define PI 3.141592653589793
#include "deltaPhi.h"

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

void analysis_readTOTEM_MC(vector<string> fileNames, string const& outputFileName = "output.root", const Int_t nevt_max = -1){
  
  bool verbose = false;
  string treeName = "TotemNtuple";
  //string treeName = "evt"; 
  bool selectSingleArmRecProton = true; 
  //bool accessGen = true;
  //double CMEnergy_ = 13000.;
  //string mc = "pythia8_diff";

  const Int_t nevt_max_corr = (nevt_max >= 0) ? nevt_max : 99999999;

  map<string,TH1F*> histosTH1F;
  map<string,TH2F*> histosTH2F;
  vector<string> selections;
  selections.push_back("All");
  //selections.push_back("AllDiff");
  //if(accessGen) selections.push_back("GEN");
  selections.push_back("SingleArmRP");
  selections.push_back("good_proton_right");
  selections.push_back("bad_proton_right");
  selections.push_back("good_proton_right_rp");
  selections.push_back("good_proton_left");
  selections.push_back("good_proton_left_rp");
  selections.push_back("bad_proton_left");

  //unsigned int const ORBITMAX = 5e+07;
  
  int nBinsEventSelection = selections.size();
  histosTH1F["EventSelection"] = new TH1F("EventSelection","EventSelection",nBinsEventSelection,0,nBinsEventSelection);
  for(size_t k = 0; k < selections.size(); ++k)
     histosTH1F["EventSelection"]->GetXaxis()->SetBinLabel( (k + 1), selections[k].c_str() );
  
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
  
  //RECO
  histosTH1F["proton_right_xi"] = new TH1F("proton_right_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_right_t"] = new TH1F("proton_right_t", "-t" , 200 , 0. , 5.);
  histosTH1F["proton_right_strange_t"] = new TH1F("proton_right_strange_t", "-t" , 200 , 0. , 500000.);
  histosTH1F["proton_right_strange_xi"] = new TH1F("proton_right_strange_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["sxi_proton_right_strange_t"] = new TH1F("sxi_proton_right_strange_t", "-t" , 200 , 0. , 500000.);
  histosTH1F["sxi_proton_right_strange_xi"] = new TH1F("sxi_proton_right_strange_xi", "#xi" , 200 , -1. , 1.);

  histosTH1F["proton_left_xi"] = new TH1F("proton_left_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_left_t"] = new TH1F("proton_left_t", "-t" , 200 , 0. , 5.);
  histosTH1F["proton_left_strange_t"] = new TH1F("proton_left_strange_t", "-t" , 200 , 0. , 500000.);
  histosTH1F["proton_left_strange_xi"] = new TH1F("proton_left_strange_xi", "#xi" , 200 , -1. , 1.);
  histosTH1F["sxi_proton_left_strange_t"] = new TH1F("sxi_proton_left_strange_t", "-t" , 200 , 0. , 500000.);
  histosTH1F["sxi_proton_left_strange_xi"] = new TH1F("sxi_proton_left_strange_xi", "#xi" , 200 , -1. , 1.);

  histosTH1F["proton_right_xi_protontag"] = new TH1F("proton_right_xi_protontag", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_right_t_protontag"] = new TH1F("proton_right_t_protontag", "-t" , 200 , 0. , 5.);

  histosTH1F["proton_left_xi_protontag"] = new TH1F("proton_left_xi_protontag", "#xi" , 200 , -1. , 1.);
  histosTH1F["proton_left_t_protontag"] = new TH1F("proton_left_t_protontag", "-t" , 200 , 0. , 5.);
  //all proton
  histosTH2F["rp_track_pos_y_vs_x_000"] = new TH2F("rp_track_pos_y_vs_x_000", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_004"] = new TH2F("rp_track_pos_y_vs_x_004", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_001"] = new TH2F("rp_track_pos_y_vs_x_001", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_005"] = new TH2F("rp_track_pos_y_vs_x_005", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_002"] = new TH2F("rp_track_pos_y_vs_x_002", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_003"] = new TH2F("rp_track_pos_y_vs_x_003", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["rp_track_pos_y_vs_x_100"] = new TH2F("rp_track_pos_y_vs_x_100", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_104"] = new TH2F("rp_track_pos_y_vs_x_104", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_101"] = new TH2F("rp_track_pos_y_vs_x_101", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_105"] = new TH2F("rp_track_pos_y_vs_x_105", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_102"] = new TH2F("rp_track_pos_y_vs_x_102", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_103"] = new TH2F("rp_track_pos_y_vs_x_103", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["rp_track_pos_y_vs_x_020"] = new TH2F("rp_track_pos_y_vs_x_020", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_024"] = new TH2F("rp_track_pos_y_vs_x_024", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_021"] = new TH2F("rp_track_pos_y_vs_x_021", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_025"] = new TH2F("rp_track_pos_y_vs_x_025", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_022"] = new TH2F("rp_track_pos_y_vs_x_022", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_023"] = new TH2F("rp_track_pos_y_vs_x_023", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["rp_track_pos_y_vs_x_120"] = new TH2F("rp_track_pos_y_vs_x_120", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_124"] = new TH2F("rp_track_pos_y_vs_x_124", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_121"] = new TH2F("rp_track_pos_y_vs_x_121", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_125"] = new TH2F("rp_track_pos_y_vs_x_125", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_122"] = new TH2F("rp_track_pos_y_vs_x_122", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["rp_track_pos_y_vs_x_123"] = new TH2F("rp_track_pos_y_vs_x_123", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);


  histosTH2F["rp_track_ang_thx_vs_pos_x_000"] = new TH2F("rp_track_ang_thx_vs_pos_x_000", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_004"] = new TH2F("rp_track_ang_thx_vs_pos_x_004", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_001"] = new TH2F("rp_track_ang_thx_vs_pos_x_001", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_005"] = new TH2F("rp_track_ang_thx_vs_pos_x_005", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_002"] = new TH2F("rp_track_ang_thx_vs_pos_x_002", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_003"] = new TH2F("rp_track_ang_thx_vs_pos_x_003", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  
  histosTH2F["rp_track_ang_thx_vs_pos_x_100"] = new TH2F("rp_track_ang_thx_vs_pos_x_100", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_104"] = new TH2F("rp_track_ang_thx_vs_pos_x_104", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_101"] = new TH2F("rp_track_ang_thx_vs_pos_x_101", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_105"] = new TH2F("rp_track_ang_thx_vs_pos_x_105", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_102"] = new TH2F("rp_track_ang_thx_vs_pos_x_102", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_103"] = new TH2F("rp_track_ang_thx_vs_pos_x_103", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thx_vs_pos_x_020"] = new TH2F("rp_track_ang_thx_vs_pos_x_020", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_024"] = new TH2F("rp_track_ang_thx_vs_pos_x_024", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_021"] = new TH2F("rp_track_ang_thx_vs_pos_x_021", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_025"] = new TH2F("rp_track_ang_thx_vs_pos_x_025", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_022"] = new TH2F("rp_track_ang_thx_vs_pos_x_022", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_023"] = new TH2F("rp_track_ang_thx_vs_pos_x_023", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thx_vs_pos_x_120"] = new TH2F("rp_track_ang_thx_vs_pos_x_120", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_124"] = new TH2F("rp_track_ang_thx_vs_pos_x_124", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_121"] = new TH2F("rp_track_ang_thx_vs_pos_x_121", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_125"] = new TH2F("rp_track_ang_thx_vs_pos_x_125", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_122"] = new TH2F("rp_track_ang_thx_vs_pos_x_122", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thx_vs_pos_x_123"] = new TH2F("rp_track_ang_thx_vs_pos_x_123", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thy_vs_pos_y_000"] = new TH2F("rp_track_ang_thy_vs_pos_y_000", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_004"] = new TH2F("rp_track_ang_thy_vs_pos_y_004", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_001"] = new TH2F("rp_track_ang_thy_vs_pos_y_001", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_005"] = new TH2F("rp_track_ang_thy_vs_pos_y_005", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_002"] = new TH2F("rp_track_ang_thy_vs_pos_y_002", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_003"] = new TH2F("rp_track_ang_thy_vs_pos_y_003", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thy_vs_pos_y_100"] = new TH2F("rp_track_ang_thy_vs_pos_y_100", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_104"] = new TH2F("rp_track_ang_thy_vs_pos_y_104", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_101"] = new TH2F("rp_track_ang_thy_vs_pos_y_101", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_105"] = new TH2F("rp_track_ang_thy_vs_pos_y_105", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_102"] = new TH2F("rp_track_ang_thy_vs_pos_y_102", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_103"] = new TH2F("rp_track_ang_thy_vs_pos_y_103", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thy_vs_pos_y_020"] = new TH2F("rp_track_ang_thy_vs_pos_y_020", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_024"] = new TH2F("rp_track_ang_thy_vs_pos_y_024", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_021"] = new TH2F("rp_track_ang_thy_vs_pos_y_021", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_025"] = new TH2F("rp_track_ang_thy_vs_pos_y_025", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_022"] = new TH2F("rp_track_ang_thy_vs_pos_y_022", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_023"] = new TH2F("rp_track_ang_thy_vs_pos_y_023", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  histosTH2F["rp_track_ang_thy_vs_pos_y_120"] = new TH2F("rp_track_ang_thy_vs_pos_y_120", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_124"] = new TH2F("rp_track_ang_thy_vs_pos_y_124", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_121"] = new TH2F("rp_track_ang_thy_vs_pos_y_121", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_125"] = new TH2F("rp_track_ang_thy_vs_pos_y_125", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_122"] = new TH2F("rp_track_ang_thy_vs_pos_y_122", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
  histosTH2F["rp_track_ang_thy_vs_pos_y_123"] = new TH2F("rp_track_ang_thy_vs_pos_y_123", "thy(RP track) vs y(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 
 //good proton
  histosTH2F["proton_left_rp_track_pos_y_vs_x_000"] = new TH2F("proton_left_rp_track_pos_y_vs_x_000", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_004"] = new TH2F("proton_left_rp_track_pos_y_vs_x_004", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_001"] = new TH2F("proton_left_rp_track_pos_y_vs_x_001", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_005"] = new TH2F("proton_left_rp_track_pos_y_vs_x_005", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_002"] = new TH2F("proton_left_rp_track_pos_y_vs_x_002", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_003"] = new TH2F("proton_left_rp_track_pos_y_vs_x_003", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["proton_right_rp_track_pos_y_vs_x_100"] = new TH2F("proton_right_rp_track_pos_y_vs_x_100", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_104"] = new TH2F("proton_right_rp_track_pos_y_vs_x_104", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_101"] = new TH2F("proton_right_rp_track_pos_y_vs_x_101", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_105"] = new TH2F("proton_right_rp_track_pos_y_vs_x_105", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_102"] = new TH2F("proton_right_rp_track_pos_y_vs_x_102", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_103"] = new TH2F("proton_right_rp_track_pos_y_vs_x_103", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["proton_left_rp_track_pos_y_vs_x_020"] = new TH2F("proton_left_rp_track_pos_y_vs_x_020", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_024"] = new TH2F("proton_left_rp_track_pos_y_vs_x_024", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_021"] = new TH2F("proton_left_rp_track_pos_y_vs_x_021", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_025"] = new TH2F("proton_left_rp_track_pos_y_vs_x_025", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_022"] = new TH2F("proton_left_rp_track_pos_y_vs_x_022", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_left_rp_track_pos_y_vs_x_023"] = new TH2F("proton_left_rp_track_pos_y_vs_x_023", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["proton_right_rp_track_pos_y_vs_x_120"] = new TH2F("proton_right_rp_track_pos_y_vs_x_120", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_124"] = new TH2F("proton_right_rp_track_pos_y_vs_x_124", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_121"] = new TH2F("proton_right_rp_track_pos_y_vs_x_121", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_125"] = new TH2F("proton_right_rp_track_pos_y_vs_x_125", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_122"] = new TH2F("proton_right_rp_track_pos_y_vs_x_122", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["proton_right_rp_track_pos_y_vs_x_123"] = new TH2F("proton_right_rp_track_pos_y_vs_x_123", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_000"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_000", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_001"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_001", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_004"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_004", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_005"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_005", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_002"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_002", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_003"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_003", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_020"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_020", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_021"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_021", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_024"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_024", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_025"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_025", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_022"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_022", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_023"] = new TH2F("proton_left_rp_track_ang_thx_vs_pos_x_023", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_100"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_100", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_101"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_101", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_104"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_104", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_105"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_105", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_102"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_102", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_103"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_103", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_120"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_120", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_121"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_121", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_124"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_124", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_125"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_125", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_122"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_122", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_123"] = new TH2F("proton_right_rp_track_ang_thx_vs_pos_x_123", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 
 //y
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_000"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_000", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_001"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_001", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_004"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_004", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_005"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_005", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_002"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_002", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_003"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_003", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_020"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_020", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_021"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_021", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_024"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_024", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_025"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_025", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_022"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_022", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_023"] = new TH2F("proton_left_rp_track_ang_thy_vs_pos_y_023", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_100"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_100", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_101"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_101", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_104"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_104", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_105"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_105", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_102"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_102", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_103"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_103", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_120"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_120", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_121"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_121", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_124"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_124", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_125"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_125", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_122"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_122", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_123"] = new TH2F("proton_right_rp_track_ang_thy_vs_pos_y_123", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 //bad proton
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_000"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_000", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_001"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_001", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_004"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_004", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_005"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_005", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_002"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_002", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_003"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_003", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_020"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_020", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_021"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_021", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_024"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_024", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_025"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_025", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_022"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_022", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_023"] = new TH2F("s_proton_left_rp_track_ang_thx_vs_pos_x_023", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_100"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_100", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_101"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_101", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_104"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_104", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_105"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_105", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_102"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_102", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_103"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_103", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_120"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_120", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_121"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_121", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_124"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_124", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_125"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_125", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_122"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_122", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);
 histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_123"] = new TH2F("s_proton_right_rp_track_ang_thx_vs_pos_x_123", "thx(RP track) vs x(RP track)" , 200, -20., 20., 1000, -5.0e-3, 5.0e-3);

  //x vs y
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_000"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_000", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_004"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_004", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_001"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_001", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_005"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_005", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_002"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_002", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_003"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_003", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_100"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_100", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_104"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_104", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_101"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_101", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_105"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_105", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_102"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_102", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_103"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_103", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_020"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_020", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_024"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_024", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_021"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_021", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_025"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_025", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_022"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_022", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_left_rp_track_pos_y_vs_x_023"] = new TH2F("s_proton_left_rp_track_pos_y_vs_x_023", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_120"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_120", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_124"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_124", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_121"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_121", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_125"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_125", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_122"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_122", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["s_proton_right_rp_track_pos_y_vs_x_123"] = new TH2F("s_proton_right_rp_track_pos_y_vs_x_123", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_000"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_000", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_004"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_004", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_001"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_001", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_005"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_005", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_002"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_002", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_003"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_003", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_100"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_100", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_104"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_104", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_101"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_101", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_105"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_105", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_102"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_102", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_103"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_103", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);

  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_020"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_020", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_024"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_024", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_021"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_021", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_025"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_025", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_022"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_022", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_023"] = new TH2F("sxi_proton_left_rp_track_pos_y_vs_x_023", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_120"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_120", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_124"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_124", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_121"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_121", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_125"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_125", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_122"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_122", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);
  histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_123"] = new TH2F("sxi_proton_right_rp_track_pos_y_vs_x_123", "y(RP track) vs x(RP track)" , 200, -20., 20., 500, -50., 50.);


  vector<TString>* vfiles = new vector<TString>; 
  for(size_t idx_file = 0; idx_file < fileNames.size(); ++idx_file) vfiles->push_back( fileNames[idx_file] );
  
  TTree* tree = new TTree(treeName.c_str(),"");
  //TriggerData   *trigData       = nullptr;
  //EventMetaData *totemEventData = nullptr;
  RPRootDumpReconstructedProton* rec_proton_left  = NULL;
  RPRootDumpReconstructedProton* rec_proton_right = NULL;
  //RPRootDumpReconstructedProtonPair* rec_proton_pair  = NULL;
  map<unsigned int, RPRootDumpTrackInfo*> rp_track_info;
  //map<unsigned int, std::vector<RPRootDumpTrackInfo>*> rp_multi_track_info; 
  
  int n_evt_total = 0; 
  int n_evt_trigger = 0; 
  int n_evt_vtx = 0; 
  int n_evt_PF = 0; 
  int n_evt_etapf = 0; 
  //int n_evt_pass_threshold = 0; 
  int n_evt_proton_right = 0; 
  int n_evt_proton_right_cut = 0; 
  int n_evt_proton_left = 0; 
  int n_evt_proton_left_cut = 0; 
    if(verbose)cout<<"Oi 4"<<endl;                                                                                                                               

  int i_tot = 0 , nevt_tot = 0;
  // Loop over files, stops at end of list of files or when reached nevt_max
  for(vector<TString>::iterator itfiles = vfiles->begin() ; itfiles != vfiles->end() && i_tot < nevt_max_corr ; ++itfiles){
  
    TFile* file = TFile::Open(*itfiles,"READ");
    
    tree = (TTree*) file->Get( treeName.c_str() );

    int nev = int(tree->GetEntriesFast());
    nevt_tot += nev;
    cout << "The current file has " << nev << " entries : "<< endl << *itfiles << endl;
    double event_weight = 1.; 
    // Adding branches to the tree ----------------------------------------------------------------------
    /*TBranch *b_trigger_data = checkAndGetBranch(tree,"trigger_data");   
    b_trigger_data->SetAddress(&trigData);
    TBranch *b_event_info = checkAndGetBranch(tree,"event_info");
    b_event_info->SetAddress(&totemEventData);*/
    tree->SetBranchAddress("rec_prot_left.",&rec_proton_left);
    tree->SetBranchAddress("rec_prot_right.",&rec_proton_right);

    /*std::vector<unsigned int> rp_list;
    rp_list.push_back(20); rp_list.push_back(21); rp_list.push_back(22); rp_list.push_back(23); rp_list.push_back(24); rp_list.push_back(25);
    rp_list.push_back(120); rp_list.push_back(121); rp_list.push_back(122); rp_list.push_back(123); rp_list.push_back(124); rp_list.push_back(125);
    char br_name[500];
    for (unsigned int a = 0; a < 2; ++a) {
       int s = 2;
       for (unsigned int r = 0; r < 6; r++) {
          unsigned int id = 100 * a + 10 * s + r;
          if( std::find(rp_list.begin(), rp_list.end(), id) == rp_list.end() ) continue;

          sprintf(br_name, "track_rp_%u.", id);
          std::cout << br_name << std::endl;
          tree->SetBranchAddress(br_name, &rp_track_info[id]);
       }
    }*/
    std::vector<unsigned int> rp_list;
    rp_list.push_back(0); rp_list.push_back(1); rp_list.push_back(2); rp_list.push_back(3); rp_list.push_back(4); rp_list.push_back(5);
    rp_list.push_back(20); rp_list.push_back(21); rp_list.push_back(22); rp_list.push_back(23); rp_list.push_back(24); rp_list.push_back(25);
    rp_list.push_back(100); rp_list.push_back(101); rp_list.push_back(102); rp_list.push_back(103); rp_list.push_back(104); rp_list.push_back(105);
    rp_list.push_back(120); rp_list.push_back(121); rp_list.push_back(122); rp_list.push_back(123); rp_list.push_back(124); rp_list.push_back(125);
    char br_name[500];
    for (unsigned int a = 0; a < 2; ++a) {
       for (unsigned int s = 0; s < 3; ++s) {
          if ( s == 1 ) continue;
          for (unsigned int r = 0; r < 6; r++) {
             unsigned int id = 100 * a + 10 * s + r;
             if( std::find(rp_list.begin(), rp_list.end(), id) == rp_list.end() ) continue;

             sprintf(br_name, "track_rp_%u.", id);
             std::cout << br_name << std::endl;
             tree->SetBranchAddress(br_name, &rp_track_info[id]);
          }
       }
    } 
    
    // Loop over events, stops when reached end of file or nevt_max
    for(int i_evt = 0 ; i_evt < nev && i_tot < nevt_max_corr ; ++i_evt, ++i_tot){
    
      if( ((i_tot+1) % 10000) == 0) cout <<int(double(i_tot+1)/1000)<<"k done"<<endl;
    
      tree->GetEntry(i_evt);
      
      histosTH1F["EventSelection"]->Fill( "All", event_weight );

      //int event_number          = trigData->event_num;
      //unsigned int orbit_number = ( trigData->orbit_num )/2;
      //int bunch_number          = trigData->bunch_num;

      //ULong64_t timestamp       = totemEventData->timestamp;
      //histosTH1F["totemOrbit"]->Fill( orbit_number );
      //histosTH1F["totemTime"]->Fill( timestamp );
      //histosTH2F["totemOrbitvsTime"]->Fill( timestamp,orbit_number );
      //bool sd_minus_pythia = false;
      //bool sd_plus_pythia = false;
      //bool dd_pythia = false;
//if (mc == "pythia8_diff"){
//   int process_id = genKin->MCProcId;
//   if (process_id == 103) sd_minus_pythia = true;
//   if (process_id == 104) sd_plus_pythia = true; 
//   if (process_id == 105) dd_pythia = true;
//}
      
//if (dd_pythia) continue;    
//   histosTH1F["EventSelection"]->Fill( "AllDiff", event_weight );   
      //TOTEM
      bool proton_right_valid = rec_proton_right->valid;
      bool proton_left_valid = rec_proton_left->valid;
      //if( selectSingleArmRecProton && (proton_right_valid && proton_left_valid) ) continue;
      if((proton_right_valid || proton_left_valid)){
      histosTH1F["EventSelection"]->Fill( "SingleArmRP", event_weight );

      //right arm : sector 56
      bool rp_track_valid_120 = rp_track_info[120]->valid;  //top
      bool rp_track_valid_121 = rp_track_info[121]->valid;
      bool rp_track_valid_124 = rp_track_info[124]->valid;  //top
      bool rp_track_valid_125 = rp_track_info[125]->valid;
      bool rp_track_valid_100 = rp_track_info[100]->valid;  //top
      bool rp_track_valid_101 = rp_track_info[101]->valid;
      bool rp_track_valid_104 = rp_track_info[104]->valid;  //top
      bool rp_track_valid_105 = rp_track_info[105]->valid;
      bool rp_track_valid_102 = rp_track_info[102]->valid;  //Horizontal
      bool rp_track_valid_103 = rp_track_info[103]->valid;  //Horizontal
      bool rp_track_valid_122 = rp_track_info[122]->valid;  //Horizontal
      bool rp_track_valid_123 = rp_track_info[123]->valid;  //Horizontal

      //left arm : sector 45
      bool rp_track_valid_020 = rp_track_info[20]->valid;   //top
      bool rp_track_valid_021 = rp_track_info[21]->valid;
      bool rp_track_valid_024 = rp_track_info[24]->valid;   //top
      bool rp_track_valid_025 = rp_track_info[25]->valid;
      bool rp_track_valid_000 = rp_track_info[00]->valid;   //top
      bool rp_track_valid_001 = rp_track_info[01]->valid;
      bool rp_track_valid_004 = rp_track_info[04]->valid;   //top
      bool rp_track_valid_005 = rp_track_info[05]->valid;
      bool rp_track_valid_002 = rp_track_info[02]->valid;  //Horizontal
      bool rp_track_valid_003 = rp_track_info[03]->valid;  //Horizontal
      bool rp_track_valid_022 = rp_track_info[22]->valid;  //Horizontal
      bool rp_track_valid_023 = rp_track_info[23]->valid;  //Horizontal


      double rp_x_000 = rp_track_info[00]->x;
      double rp_y_000 = rp_track_info[00]->y;
      double rp_x_001 = rp_track_info[01]->x;
      double rp_y_001 = rp_track_info[01]->y;
      double rp_x_002 = rp_track_info[02]->x;
      double rp_y_002 = rp_track_info[02]->y;
      double rp_x_003 = rp_track_info[03]->x;
      double rp_y_003 = rp_track_info[03]->y;
      double rp_x_004 = rp_track_info[04]->x;
      double rp_y_004 = rp_track_info[04]->y;
      double rp_x_005 = rp_track_info[05]->x;
      double rp_y_005 = rp_track_info[05]->y;
      double rp_x_100 = rp_track_info[100]->x;
      double rp_y_100 = rp_track_info[100]->y;
      double rp_x_101 = rp_track_info[101]->x;
      double rp_y_101 = rp_track_info[101]->y;
      double rp_x_102 = rp_track_info[102]->x;
      double rp_y_102 = rp_track_info[102]->y;
      double rp_x_103 = rp_track_info[103]->x;
      double rp_y_103 = rp_track_info[103]->y;
      double rp_x_104 = rp_track_info[104]->x;
      double rp_y_104 = rp_track_info[104]->y;
      double rp_x_105 = rp_track_info[105]->x;
      double rp_y_105 = rp_track_info[105]->y;

      
      double rp_x_020 = rp_track_info[20]->x;
      double rp_y_020 = rp_track_info[20]->y;
      double rp_x_021 = rp_track_info[21]->x;
      double rp_y_021 = rp_track_info[21]->y;
      double rp_x_022 = rp_track_info[22]->x;
      double rp_y_022 = rp_track_info[22]->y;
      double rp_x_023 = rp_track_info[23]->x;
      double rp_y_023 = rp_track_info[23]->y;
      double rp_x_024 = rp_track_info[24]->x;
      double rp_y_024 = rp_track_info[24]->y;
      double rp_x_025 = rp_track_info[25]->x;
      double rp_y_025 = rp_track_info[25]->y;
      double rp_x_120 = rp_track_info[120]->x;
      double rp_y_120 = rp_track_info[120]->y;
      double rp_x_121 = rp_track_info[121]->x;
      double rp_y_121 = rp_track_info[121]->y;
      double rp_x_122 = rp_track_info[122]->x;
      double rp_y_122 = rp_track_info[122]->y;
      double rp_x_123 = rp_track_info[123]->x;
      double rp_y_123 = rp_track_info[123]->y;
      double rp_x_124 = rp_track_info[124]->x;
      double rp_y_124 = rp_track_info[124]->y;
      double rp_x_125 = rp_track_info[125]->x;
      double rp_y_125 = rp_track_info[125]->y;
      
      double rp_thx_000 = rp_track_info[00]->thx;
      double rp_thy_000 = rp_track_info[00]->thy;
      double rp_thx_001 = rp_track_info[01]->thx;
      double rp_thy_001 = rp_track_info[01]->thy;
      double rp_thx_002 = rp_track_info[02]->thx;
      double rp_thy_002 = rp_track_info[02]->thy;
      double rp_thx_003 = rp_track_info[03]->thx;
      double rp_thy_003 = rp_track_info[03]->thy;
      double rp_thx_004 = rp_track_info[04]->thx;
      double rp_thy_004 = rp_track_info[04]->thy;
      double rp_thx_005 = rp_track_info[05]->thx;
      double rp_thy_005 = rp_track_info[05]->thy;
      double rp_thx_100 = rp_track_info[100]->thx;
      double rp_thy_100 = rp_track_info[100]->thy;
      double rp_thx_101 = rp_track_info[101]->thx;
      double rp_thy_101 = rp_track_info[101]->thy;
      double rp_thx_102 = rp_track_info[102]->thx;
      double rp_thy_102 = rp_track_info[102]->thy;
      double rp_thx_103 = rp_track_info[103]->thx;
      double rp_thy_103 = rp_track_info[103]->thy;
      double rp_thx_104 = rp_track_info[104]->thx;
      double rp_thy_104 = rp_track_info[104]->thy;
      double rp_thx_105 = rp_track_info[105]->thx;
      double rp_thy_105 = rp_track_info[105]->thy;

      double rp_thx_020 = rp_track_info[20]->thx;
      double rp_thy_020 = rp_track_info[20]->thy;
      double rp_thx_021 = rp_track_info[21]->thx;
      double rp_thy_021 = rp_track_info[21]->thy;
      double rp_thx_022 = rp_track_info[22]->thx;
      double rp_thy_022 = rp_track_info[22]->thy;
      double rp_thx_023 = rp_track_info[23]->thx;
      double rp_thy_023 = rp_track_info[23]->thy;
      double rp_thx_024 = rp_track_info[24]->thx;
      double rp_thy_024 = rp_track_info[24]->thy;
      double rp_thx_025 = rp_track_info[25]->thx;
      double rp_thy_025 = rp_track_info[25]->thy;
      double rp_thx_120 = rp_track_info[120]->thx;
      double rp_thy_120 = rp_track_info[120]->thy;
      double rp_thx_121 = rp_track_info[121]->thx;
      double rp_thy_121 = rp_track_info[121]->thy;
      double rp_thx_122 = rp_track_info[122]->thx;
      double rp_thy_122 = rp_track_info[122]->thy;
      double rp_thx_123 = rp_track_info[123]->thx;
      double rp_thy_123 = rp_track_info[123]->thy;
      double rp_thx_124 = rp_track_info[124]->thx;
      double rp_thy_124 = rp_track_info[124]->thy;
      double rp_thx_125 = rp_track_info[125]->thx;
      double rp_thy_125 = rp_track_info[125]->thy;
 
      if(rp_track_valid_000){
         histosTH2F["rp_track_pos_y_vs_x_000"]->Fill( rp_x_000, rp_y_000, event_weight );
         histosTH2F["rp_track_ang_thx_vs_pos_x_000"]->Fill( rp_x_000, rp_thx_000, event_weight );
         histosTH2F["rp_track_ang_thy_vs_pos_y_000"]->Fill( rp_y_000, rp_thy_000, event_weight );

      }
      if(rp_track_valid_001){
        histosTH2F["rp_track_pos_y_vs_x_001"]->Fill( rp_x_001, rp_y_001, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_001"]->Fill( rp_x_001, rp_thx_001, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_001"]->Fill( rp_y_001, rp_thy_001, event_weight );
      }
     if(rp_track_valid_002){
        histosTH2F["rp_track_pos_y_vs_x_002"]->Fill( rp_x_002, rp_y_002, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_002"]->Fill( rp_x_002, rp_thx_002, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_002"]->Fill( rp_y_002, rp_thy_002, event_weight );
      }
     if(rp_track_valid_003){
        histosTH2F["rp_track_pos_y_vs_x_003"]->Fill( rp_x_003, rp_y_003, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_003"]->Fill( rp_x_003, rp_thx_003, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_003"]->Fill( rp_y_003, rp_thy_003, event_weight );
      }
      
      if(rp_track_valid_004){
        histosTH2F["rp_track_pos_y_vs_x_004"]->Fill( rp_x_004, rp_y_004, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_004"]->Fill( rp_x_004, rp_thx_004, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_004"]->Fill( rp_y_004, rp_thy_004, event_weight );

      }
      if(rp_track_valid_005){
        histosTH2F["rp_track_pos_y_vs_x_005"]->Fill( rp_x_005, rp_y_005, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_005"]->Fill( rp_x_005, rp_thx_005, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_005"]->Fill( rp_y_005, rp_thy_005, event_weight );

      }
      if(rp_track_valid_100){
        histosTH2F["rp_track_pos_y_vs_x_100"]->Fill( rp_x_100, rp_y_100, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_100"]->Fill( rp_x_100, rp_thx_100, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_100"]->Fill( rp_y_100, rp_thy_100, event_weight );

      }
      if(rp_track_valid_101){
        histosTH2F["rp_track_pos_y_vs_x_101"]->Fill( rp_x_101, rp_y_101, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_101"]->Fill( rp_x_101, rp_thx_101, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_101"]->Fill( rp_y_101, rp_thy_101, event_weight );
      }
    if(rp_track_valid_102){
        histosTH2F["rp_track_pos_y_vs_x_102"]->Fill( rp_x_102, rp_y_102, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_102"]->Fill( rp_x_102, rp_thx_102, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_102"]->Fill( rp_y_102, rp_thy_102, event_weight );
      }
     if(rp_track_valid_103){
        histosTH2F["rp_track_pos_y_vs_x_103"]->Fill( rp_x_103, rp_y_103, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_103"]->Fill( rp_x_103, rp_thx_103, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_103"]->Fill( rp_y_103, rp_thy_103, event_weight );
      }
      if(rp_track_valid_104){
        histosTH2F["rp_track_pos_y_vs_x_104"]->Fill( rp_x_104, rp_y_104, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_104"]->Fill( rp_x_104, rp_thx_104, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_104"]->Fill( rp_y_104, rp_thy_104, event_weight );

      }
      if(rp_track_valid_105){
        histosTH2F["rp_track_pos_y_vs_x_105"]->Fill( rp_x_105, rp_y_105, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_105"]->Fill( rp_x_105, rp_thx_105, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_105"]->Fill( rp_y_105, rp_thy_105, event_weight );
      }
 
      if(rp_track_valid_020){
        histosTH2F["rp_track_pos_y_vs_x_020"]->Fill( rp_x_020, rp_y_020, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_020"]->Fill( rp_x_020, rp_thx_020, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_020"]->Fill( rp_y_020, rp_thy_020, event_weight );
      }
      if(rp_track_valid_021){
        histosTH2F["rp_track_pos_y_vs_x_021"]->Fill( rp_x_021, rp_y_021, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_021"]->Fill( rp_x_021, rp_thx_021, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_021"]->Fill( rp_y_021, rp_thy_021, event_weight );
      }
    if(rp_track_valid_022){
        histosTH2F["rp_track_pos_y_vs_x_022"]->Fill( rp_x_022, rp_y_022, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_022"]->Fill( rp_x_022, rp_thx_022, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_022"]->Fill( rp_y_022, rp_thy_022, event_weight );
      }
    if(rp_track_valid_023){
        histosTH2F["rp_track_pos_y_vs_x_023"]->Fill( rp_x_023, rp_y_023, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_023"]->Fill( rp_x_023, rp_thx_023, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_023"]->Fill( rp_y_023, rp_thy_023, event_weight );
      }
      if(rp_track_valid_024){
        histosTH2F["rp_track_pos_y_vs_x_024"]->Fill( rp_x_024, rp_y_024, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_024"]->Fill( rp_x_024, rp_thx_024, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_024"]->Fill( rp_y_024, rp_thy_024, event_weight );
      }
      if(rp_track_valid_025){
        histosTH2F["rp_track_pos_y_vs_x_025"]->Fill( rp_x_025, rp_y_025, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_025"]->Fill( rp_x_025, rp_thx_025, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_025"]->Fill( rp_y_025, rp_thy_025, event_weight );
      }
      if(rp_track_valid_120){
        histosTH2F["rp_track_pos_y_vs_x_120"]->Fill( rp_x_120, rp_y_120, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_120"]->Fill( rp_x_120, rp_thx_120, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_120"]->Fill( rp_y_120, rp_thy_120, event_weight );
        
      }
      if(rp_track_valid_121){
        histosTH2F["rp_track_pos_y_vs_x_121"]->Fill( rp_x_121, rp_y_121, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_121"]->Fill( rp_x_121, rp_thx_121, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_121"]->Fill( rp_y_121, rp_thy_121, event_weight );
      }
     if(rp_track_valid_122){
        histosTH2F["rp_track_pos_y_vs_x_122"]->Fill( rp_x_122, rp_y_122, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_122"]->Fill( rp_x_122, rp_thx_122, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_122"]->Fill( rp_y_122, rp_thy_122, event_weight );
      }
    if(rp_track_valid_123){
        histosTH2F["rp_track_pos_y_vs_x_123"]->Fill( rp_x_123, rp_y_123, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_123"]->Fill( rp_x_123, rp_thx_123, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_123"]->Fill( rp_y_123, rp_thy_123, event_weight );
      }
      if(rp_track_valid_124){
        histosTH2F["rp_track_pos_y_vs_x_124"]->Fill( rp_x_124, rp_y_124, event_weight );
        histosTH2F["rp_track_ang_thx_vs_pos_x_124"]->Fill( rp_x_124, rp_thx_124, event_weight );
        histosTH2F["rp_track_ang_thy_vs_pos_y_124"]->Fill( rp_y_124, rp_thy_124, event_weight );
      }
      if(rp_track_valid_125){
         histosTH2F["rp_track_pos_y_vs_x_125"]->Fill( rp_x_125, rp_y_125, event_weight );
         histosTH2F["rp_track_ang_thx_vs_pos_x_125"]->Fill( rp_x_125, rp_thx_125, event_weight );
         histosTH2F["rp_track_ang_thy_vs_pos_y_125"]->Fill( rp_y_125, rp_thy_125, event_weight );
      }

      //Fiducial Cuts
      bool cut_rp_024 =  rp_x_024>0 && rp_x_024<6 && rp_y_024>8.4 && rp_y_024<29 ;
      bool cut_rp_025 =  rp_x_025>0 && rp_x_025<6 && rp_y_025<-8.4 && rp_y_024>-29 ;
      bool cut_rp_124 =  rp_x_124>0 && rp_x_124<6 && rp_y_124>8.4 && rp_y_124<27 ;
      bool cut_rp_125 =  rp_x_125>0 && rp_x_125<6 && rp_y_125<-8.4 && rp_y_124>-27 ;
      
      bool rp_track_accept_top_right = ( rp_track_valid_120 && rp_track_valid_124 && rp_track_valid_100 && rp_track_valid_104);
      bool rp_track_accept_bot_right = ( rp_track_valid_121 && rp_track_valid_125 && rp_track_valid_101 && rp_track_valid_105 );
      bool rp_track_accept_top_left =  ( rp_track_valid_020 && rp_track_valid_024 && rp_track_valid_000 && rp_track_valid_004 );
      bool rp_track_accept_bot_left =  ( rp_track_valid_021 && rp_track_valid_025 && rp_track_valid_001 && rp_track_valid_005);

      bool rp_track_accept_right = ( rp_track_valid_120 && rp_track_valid_124 )  || ( rp_track_valid_121 && rp_track_valid_125 ) || ( rp_track_valid_101 && rp_track_valid_105 );
      bool rp_track_accept_left = ( rp_track_valid_020 && rp_track_valid_024 )  || ( rp_track_valid_021 && rp_track_valid_025 ) || ( rp_track_valid_001 && rp_track_valid_005 );


      //bool rp_track_accept_right = ( rp_track_valid_120 && rp_track_valid_124 && cut_rp_124 )  || ( rp_track_valid_121 && rp_track_valid_125 && cut_rp_125 );// || ( rp_track_valid_122 && rp_track_valid_123 );
      //bool rp_track_accept_left = ( rp_track_valid_020 && rp_track_valid_024 && cut_rp_024 )  || ( rp_track_valid_021 && rp_track_valid_025 && cut_rp_025 );// || ( rp_track_valid_022 && rp_track_valid_023 );

      //RP Protons
      //Regarding the reconstructed xi-value are xi’s = -0.05 (in your definition) protons where 
      //the xi & t reconstruction doesn’t converge. xi’s > 0.25 are unphysical 
      //and due to secondaries even in the MC. Those with xi’s between -0.04 and 0.2 are unfamiliar to me.
      // It would be nice to see what are the x vs y distribution in the RPs for these events and ok
      //also the x vs y distribution for all protons (just as a crosscheck). ok
      //double xi_totem;
      //double thetax_proton_right = rec_proton_right->thx;
      //double thetay_proton_right = rec_proton_right->thy;
      //double beta_proton_right = x_minus/-xi_proton_right; 
      //bool xi_region_right = -xi_proton_right>=0.03 && -xi_proton_right<=0.1;
      double chi2_proton_right = rec_proton_right->chi2;
      double chindf_proton_right = rec_proton_right->chindf;
      double xi_proton_right = rec_proton_right->xi; 
      double t_proton_right = rec_proton_right->t;
      bool s_xi_region_right = -xi_proton_right>=-0.04 && -xi_proton_right<=0.2;
      bool t_region_right = fabs(t_proton_right)>=0.03 && fabs(t_proton_right)<=1;
      bool good_proton_right = proton_right_valid && (xi_proton_right < 0.1);
      
      // double thetax_proton_left = rec_proton_left->thx;
      //double thetay_proton_left = rec_proton_left->thy;
      //double beta_proton_left = x_plus/-xi_proton_left; //cout<<beta_proton_left<<endl;
      //bool xi_region_left = -xi_proton_left>=0.03 && -xi_proton_left<=0.1;
      double chi2_proton_left = rec_proton_left->chi2;
      double chindf_proton_left = rec_proton_left->chindf;
      double xi_proton_left = rec_proton_left->xi;
      double t_proton_left = rec_proton_left->t;
      bool s_xi_region_left = -xi_proton_left>=-0.04 && -xi_proton_left<=0.2;
      bool t_region_left = -t_proton_left>=0.03 && -t_proton_left<=1;
      bool good_proton_left = proton_left_valid && (xi_proton_left < 0.1);
      //double mass_x = sqrt(xi_proton_right*13000);

    if(proton_right_valid && fabs(t_proton_right) > 8.0 ){
        histosTH1F["EventSelection"]->Fill( "bad_proton_right", event_weight );
       
        histosTH1F["proton_right_strange_t"]->Fill(-t_proton_right, event_weight );
        histosTH1F["proton_right_strange_xi"]->Fill(-xi_proton_right, event_weight );
        
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_100"]->Fill( rp_x_100, rp_thx_100, event_weight );
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_104"]->Fill( rp_x_104, rp_thx_104, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_101"]->Fill( rp_x_101, rp_thx_101, event_weight ); 
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_102"]->Fill( rp_x_102, rp_thx_102, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_103"]->Fill( rp_x_103, rp_thx_103, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_105"]->Fill( rp_x_105, rp_thx_105, event_weight ); 
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_120"]->Fill( rp_x_120, rp_thx_120, event_weight );
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_124"]->Fill( rp_x_124, rp_thx_124, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_121"]->Fill( rp_x_121, rp_thx_121, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_125"]->Fill( rp_x_125, rp_thx_125, event_weight ); 
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_122"]->Fill( rp_x_122, rp_thx_122, event_weight );                                               
        histosTH2F["s_proton_right_rp_track_ang_thx_vs_pos_x_123"]->Fill( rp_x_123, rp_thx_123, event_weight ); 

        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_100"]->Fill( rp_x_100, rp_y_100, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_104"]->Fill( rp_x_104, rp_y_104, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_102"]->Fill( rp_x_102, rp_y_102, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_103"]->Fill( rp_x_103, rp_y_103, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_101"]->Fill( rp_x_101, rp_y_101, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_105"]->Fill( rp_x_105, rp_y_105, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_120"]->Fill( rp_x_120, rp_y_120, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_124"]->Fill( rp_x_124, rp_y_124, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_121"]->Fill( rp_x_121, rp_y_121, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_125"]->Fill( rp_x_125, rp_y_125, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_122"]->Fill( rp_x_122, rp_y_122, event_weight );
        histosTH2F["s_proton_right_rp_track_pos_y_vs_x_123"]->Fill( rp_x_123, rp_y_123, event_weight );
        
        if(s_xi_region_right){
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_100"]->Fill( rp_x_100, rp_y_100, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_102"]->Fill( rp_x_102, rp_y_102, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_103"]->Fill( rp_x_103, rp_y_103, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_104"]->Fill( rp_x_104, rp_y_104, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_101"]->Fill( rp_x_101, rp_y_101, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_105"]->Fill( rp_x_105, rp_y_105, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_120"]->Fill( rp_x_120, rp_y_120, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_124"]->Fill( rp_x_124, rp_y_124, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_121"]->Fill( rp_x_121, rp_y_121, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_125"]->Fill( rp_x_125, rp_y_125, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_122"]->Fill( rp_x_122, rp_y_122, event_weight );
            histosTH2F["sxi_proton_right_rp_track_pos_y_vs_x_123"]->Fill( rp_x_123, rp_y_123, event_weight );

            
            histosTH1F["sxi_proton_right_strange_t"]->Fill(-t_proton_right, event_weight );
            histosTH1F["sxi_proton_right_strange_xi"]->Fill(-xi_proton_right, event_weight );
        
        }

        
    }
    
    if (good_proton_right){    

          histosTH1F["proton_right_xi"]->Fill(-xi_proton_right, event_weight );
          histosTH1F["proton_right_t"]->Fill(fabs(t_proton_right), event_weight );
          histosTH1F["EventSelection"]->Fill( "good_proton_right", event_weight );
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_102"]->Fill( rp_x_102, rp_thx_102, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_103"]->Fill( rp_x_103, rp_thx_103, event_weight );  
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_100"]->Fill( rp_x_100, rp_thx_100, event_weight );
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_104"]->Fill( rp_x_104, rp_thx_104, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_101"]->Fill( rp_x_101, rp_thx_101, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_105"]->Fill( rp_x_105, rp_thx_105, event_weight ); 
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_120"]->Fill( rp_x_120, rp_thx_120, event_weight );
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_124"]->Fill( rp_x_124, rp_thx_124, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_121"]->Fill( rp_x_121, rp_thx_121, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_125"]->Fill( rp_x_125, rp_thx_125, event_weight );  
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_122"]->Fill( rp_x_122, rp_thx_122, event_weight );                                               
          histosTH2F["proton_right_rp_track_ang_thx_vs_pos_x_123"]->Fill( rp_x_123, rp_thx_123, event_weight );    
                                                     
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_100"]->Fill( rp_y_100, rp_thy_100, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_102"]->Fill( rp_y_102, rp_thy_102, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_103"]->Fill( rp_y_103, rp_thy_103, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_104"]->Fill( rp_y_104, rp_thy_104, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_101"]->Fill( rp_y_101, rp_thy_101, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_105"]->Fill( rp_y_105, rp_thy_105, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_120"]->Fill( rp_y_120, rp_thy_120, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_124"]->Fill( rp_y_124, rp_thy_124, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_121"]->Fill( rp_y_121, rp_thy_121, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_125"]->Fill( rp_y_125, rp_thy_125, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_122"]->Fill( rp_y_122, rp_thy_122, event_weight );
          histosTH2F["proton_right_rp_track_ang_thy_vs_pos_y_123"]->Fill( rp_y_123, rp_thy_123, event_weight );
          
          
          histosTH2F["proton_right_rp_track_pos_y_vs_x_100"]->Fill( rp_x_100, rp_y_100, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_102"]->Fill( rp_x_102, rp_y_102, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_103"]->Fill( rp_x_103, rp_y_103, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_104"]->Fill( rp_x_104, rp_y_104, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_101"]->Fill( rp_x_101, rp_y_101, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_105"]->Fill( rp_x_105, rp_y_105, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_120"]->Fill( rp_x_120, rp_y_120, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_124"]->Fill( rp_x_124, rp_y_124, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_121"]->Fill( rp_x_121, rp_y_121, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_125"]->Fill( rp_x_125, rp_y_125, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_122"]->Fill( rp_x_122, rp_y_122, event_weight );
          histosTH2F["proton_right_rp_track_pos_y_vs_x_123"]->Fill( rp_x_123, rp_y_123, event_weight );
          
          
     }
     
    if(proton_left_valid && fabs(t_proton_left)> 8.0){
        histosTH1F["EventSelection"]->Fill( "bad_proton_left", event_weight );
        histosTH1F["proton_left_strange_t"]->Fill(-t_proton_left, event_weight );
        histosTH1F["proton_left_strange_xi"]->Fill(-xi_proton_left, event_weight );
        
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_002"]->Fill( rp_x_002, rp_thx_002, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_003"]->Fill( rp_x_003, rp_thx_003, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_000"]->Fill( rp_x_000, rp_thx_000, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_004"]->Fill( rp_x_004, rp_thx_004, event_weight );                                               
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_001"]->Fill( rp_x_001, rp_thx_001, event_weight );                                               
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_005"]->Fill( rp_x_005, rp_thx_005, event_weight ); 
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_020"]->Fill( rp_x_020, rp_thx_020, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_024"]->Fill( rp_x_024, rp_thx_024, event_weight );                                               
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_021"]->Fill( rp_x_021, rp_thx_021, event_weight );                                               
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_025"]->Fill( rp_x_025, rp_thx_025, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_022"]->Fill( rp_x_022, rp_thx_022, event_weight );
        histosTH2F["s_proton_left_rp_track_ang_thx_vs_pos_x_023"]->Fill( rp_x_023, rp_thx_023, event_weight );
        
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_002"]->Fill( rp_x_002, rp_y_002, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_003"]->Fill( rp_x_003, rp_y_003, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_000"]->Fill( rp_x_000, rp_y_000, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_004"]->Fill( rp_x_004, rp_y_004, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_001"]->Fill( rp_x_001, rp_y_001, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_005"]->Fill( rp_x_005, rp_y_005, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_020"]->Fill( rp_x_020, rp_y_020, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_024"]->Fill( rp_x_024, rp_y_024, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_021"]->Fill( rp_x_021, rp_y_021, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_025"]->Fill( rp_x_025, rp_y_025, event_weight ); 
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_022"]->Fill( rp_x_022, rp_y_022, event_weight );
        histosTH2F["s_proton_left_rp_track_pos_y_vs_x_023"]->Fill( rp_x_023, rp_y_023, event_weight );
        
       if(s_xi_region_left){
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_002"]->Fill( rp_x_002, rp_y_002, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_003"]->Fill( rp_x_003, rp_y_003, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_000"]->Fill( rp_x_000, rp_y_000, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_004"]->Fill( rp_x_004, rp_y_004, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_001"]->Fill( rp_x_001, rp_y_001, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_005"]->Fill( rp_x_005, rp_y_005, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_020"]->Fill( rp_x_020, rp_y_020, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_024"]->Fill( rp_x_024, rp_y_024, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_021"]->Fill( rp_x_021, rp_y_021, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_025"]->Fill( rp_x_025, rp_y_025, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_022"]->Fill( rp_x_022, rp_y_022, event_weight );
            histosTH2F["sxi_proton_left_rp_track_pos_y_vs_x_023"]->Fill( rp_x_023, rp_y_023, event_weight );
            
            histosTH1F["sxi_proton_left_strange_t"]->Fill(-t_proton_left, event_weight );
            histosTH1F["sxi_proton_left_strange_xi"]->Fill(-xi_proton_left, event_weight );
        
        }
    }
    
    
     if (good_proton_left ){

          histosTH1F["proton_left_xi"]->Fill(-xi_proton_left, event_weight );
          histosTH1F["proton_left_t"]->Fill(fabs(t_proton_left), event_weight );
          histosTH1F["EventSelection"]->Fill( "good_proton_left", event_weight );
          
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_002"]->Fill( rp_x_002, rp_thx_002, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_003"]->Fill( rp_x_003, rp_thx_003, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_000"]->Fill( rp_x_000, rp_thx_000, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_004"]->Fill( rp_x_004, rp_thx_004, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_001"]->Fill( rp_x_001, rp_thx_001, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_005"]->Fill( rp_x_005, rp_thx_005, event_weight ); 
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_020"]->Fill( rp_x_020, rp_thx_020, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_024"]->Fill( rp_x_024, rp_thx_024, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_021"]->Fill( rp_x_021, rp_thx_021, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_025"]->Fill( rp_x_025, rp_thx_025, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_022"]->Fill( rp_x_022, rp_thx_022, event_weight ); 
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_023"]->Fill( rp_x_023, rp_thx_023, event_weight ); 


          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_002"]->Fill( rp_y_002, rp_thy_002, event_weight );
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_003"]->Fill( rp_y_003, rp_thy_003, event_weight );
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_000"]->Fill( rp_y_000, rp_thy_000, event_weight );
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_004"]->Fill( rp_y_004, rp_thy_004, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_001"]->Fill( rp_y_001, rp_thy_001, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_005"]->Fill( rp_y_005, rp_thy_005, event_weight );           
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_020"]->Fill( rp_y_020, rp_thy_020, event_weight );
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_024"]->Fill( rp_y_024, rp_thy_024, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_021"]->Fill( rp_y_021, rp_thy_021, event_weight );                                               
          histosTH2F["proton_left_rp_track_ang_thy_vs_pos_y_025"]->Fill( rp_y_025, rp_thy_025, event_weight ); 
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_022"]->Fill( rp_x_022, rp_thx_022, event_weight );
          histosTH2F["proton_left_rp_track_ang_thx_vs_pos_x_023"]->Fill( rp_x_023, rp_thx_023, event_weight );

          histosTH2F["proton_left_rp_track_pos_y_vs_x_002"]->Fill( rp_x_002, rp_y_002, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_003"]->Fill( rp_x_003, rp_y_003, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_000"]->Fill( rp_x_000, rp_y_000, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_004"]->Fill( rp_x_004, rp_y_004, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_001"]->Fill( rp_x_001, rp_y_001, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_005"]->Fill( rp_x_005, rp_y_005, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_020"]->Fill( rp_x_020, rp_y_020, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_024"]->Fill( rp_x_024, rp_y_024, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_021"]->Fill( rp_x_021, rp_y_021, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_025"]->Fill( rp_x_025, rp_y_025, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_022"]->Fill( rp_x_022, rp_y_022, event_weight );
          histosTH2F["proton_left_rp_track_pos_y_vs_x_023"]->Fill( rp_x_023, rp_y_023, event_weight );


    }
    if (good_proton_right && rp_track_accept_right){
           ++n_evt_proton_right;
          histosTH1F["proton_right_xi_protontag"]->Fill(-xi_proton_right, event_weight );
          histosTH1F["proton_right_t_protontag"]->Fill(fabs(t_proton_right), event_weight );
          histosTH1F["EventSelection"]->Fill( "good_proton_right_rp", event_weight );

    }
    //proton left
       if (good_proton_left && rp_track_accept_left){
          ++n_evt_proton_left;
          histosTH1F["proton_left_xi_protontag"]->Fill(-xi_proton_left, event_weight );
          histosTH1F["proton_left_t_protontag"]->Fill(fabs(t_proton_left), event_weight );
          histosTH1F["EventSelection"]->Fill( "good_proton_left_rp", event_weight );

        }
    }//sinlgeArm
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
  analysis_readTOTEM_MC(totemFileNames, outputFileName, maxEvents);
  return 0;
}
