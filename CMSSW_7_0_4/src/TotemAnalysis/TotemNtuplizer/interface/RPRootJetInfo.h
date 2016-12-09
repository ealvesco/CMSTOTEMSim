#ifndef _TotemAnalysis_TotemNtuplizer_RPRootJetInfo_h_
#define _TotemAnalysis_TotemNtuplizer_RPRootJetInfo_h_

#include "TNamed.h"
#include <vector>
#include <map>
#include "fastjet/ClusterSequence.hh"
#include "RecoTotemRP/RPRecoDataFormats/interface/CentralMassInfo.h"


/*
struct RPRootDumpDigiInfo 
{
  std::vector<int> numberOfClusters;  ///< number of clusters in a given plane (indexed from 0 to 9)
  unsigned int numberOfPlanesOn;      ///< number of planes with at least one cluster
  unsigned int uPlanesOn;             ///< number of U planes with at least one cluster
  unsigned int vPlanesOn;             ///< number of V planes with at least one cluster
  std::vector<int> planeId;           ///< plane ID for a given cluster (array index)
  std::vector<int> clusterSize;       ///< cluster size of a given cluster
  std::vector<int> centralStrip;      ///< central strip of a given cluster
  RPRootDumpDigiInfo()
  {
  {
    numberOfPlanesOn = uPlanesOn = vPlanesOn = 0;
    numberOfClusters = std::vector<int>();
    numberOfClusters.reserve(10);
    numberOfClusters.assign(10,0);
    planeId = std::vector<int>();
    clusterSize = std::vector<int>();
    centralStrip = std::vector<int>();
  }

  virtual ~RPRootDumpDigiInfo() {}
  
  ClassDef(RPRootDumpDigiInfo,1)
};
*/



struct RPRootDumpJet
{
  double e;
  double px;
  double py;
  double pz;
  double phi;
  double phi_std;
  double rapidity;
  double pseudorapidity;
  double pt;
  
  RPRootDumpJet(const fastjet::PseudoJet &jet)
  {
    e = jet.e();
    px = jet.px();
    py = jet.py();
    pz = jet.pz();
    phi = jet.phi();
    phi_std = jet.phi_std();
    rapidity = jet.rapidity();
    pseudorapidity = jet.pseudorapidity();
    pt = sqrt(px*px + py*py);
  }
  RPRootDumpJet()
  {
   e = 0.;
   px = 0.;
   py = 0.;
   pz = 0.;
   phi = 0.;
   phi_std = 0.;
   rapidity = 0.;
   pseudorapidity = 0.;
   pt = 0.;
  }
  virtual ~RPRootDumpJet() {}
  
  ClassDef(RPRootDumpJet,1)
};


struct RPRootDumpJetInfo
{
  std::vector<RPRootDumpJet> jets;  ///< array of MC jets
  int jets_no;

  RPRootDumpJetInfo() : jets_no(0) {}
  virtual ~RPRootDumpJetInfo() {}
  
  void AddJets(const std::vector< fastjet::PseudoJet > &jets_vect)
  {
    jets.clear();
    for(unsigned int i=0; i<jets_vect.size(); ++i)
    {
      jets.push_back(jets_vect[i]);
    }
    jets_no = jets.size();
  }
  
  ClassDef(RPRootDumpJetInfo,1)
};


struct RPRootDiffMassInfo
{
  RPRootDiffMassInfo() {}
  double px, py, pz;
  double pt;
  double e;
  double m;
  double min_rap, max_rap;
  double rap;
  bool empty;
  
  virtual ~RPRootDiffMassInfo() {}

  void SetVariables(const CentralMassInfo & centr_mass_info)
  {
    px = centr_mass_info.px;
    py = centr_mass_info.py;
    pz = centr_mass_info.pz;
    pt = centr_mass_info.pt;
    e = centr_mass_info.e;
    m = centr_mass_info.m;
    min_rap = centr_mass_info.min_rap;
    max_rap = centr_mass_info.max_rap;
    rap = centr_mass_info.rap;
    empty = centr_mass_info.empty;
  }
  ClassDef(RPRootDiffMassInfo,1)
};


#endif
