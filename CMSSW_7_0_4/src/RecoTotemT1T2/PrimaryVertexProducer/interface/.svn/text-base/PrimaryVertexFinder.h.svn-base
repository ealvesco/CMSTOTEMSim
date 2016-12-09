#include <memory>
/*
Created by Fabrizio Ferro - INFN Genova for TOTEM
*/

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
//#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//#include "DataFormats/T1Road/interface/T1Road.h"
#include "DataFormats/T1Road/interface/T1RecHitGlobal.h"

#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "DataFormats/Provenance/interface/Provenance.h"
#include "DataFormats/Provenance/interface/BranchDescription.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"

#include "Geometry/TotemGeometry/interface/T1Geometry.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
//
// class decleration
//


#include "TROOT.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include "TMatrixD.h"


class PrimaryVertexFinder : public edm::EDProducer 
{


 public:

  PrimaryVertexFinder(const edm::ParameterSet&);

  virtual void produce(edm::Event& event, const edm::EventSetup& setup);
  
  ~PrimaryVertexFinder();

  void TwoTracksMinD(T1T2Track, T1T2Track, pair<GlobalPoint, float> & );

 private:

  double _SeeTracks;
  double _SeeHits;
  double _ChiOverNCut;
  double _ZRange;
  double _Rmin;
  int _Verbosity;
  int _Dets;
  int _NumberOfTracks;
  double _ZCenter;
  bool _FromOutside;

  T1T2TrackCollection *trackCollection;


};
