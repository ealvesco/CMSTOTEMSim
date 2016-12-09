#include <memory>
/*
Created by Fabrizio Ferro - INFN Genova for TOTEM
*/

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

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
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"


#include <fstream>
#include <iostream>
//
// class decleration
//

/*
#include "TROOT.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include "TGraph2D.h"
*/

class VertexDumper : public edm::EDAnalyzer 
{
 

   public:
      explicit VertexDumper(const edm::ParameterSet&);
      ~VertexDumper();
      float Eta(float x,float y,float z);
      float Phi(float, float);

   private:
      virtual void beginJob();
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      ofstream file;

      unsigned int ev;
};
