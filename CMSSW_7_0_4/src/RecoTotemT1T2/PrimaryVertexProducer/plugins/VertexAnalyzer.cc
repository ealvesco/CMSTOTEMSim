/*
  Created by Fabrizio Ferro - INFN Genova for TOTEM
*/
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "RecoTotemT1T2/PrimaryVertexProducer/interface/VertexAnalyzer.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"


#include <vector>
#include "TFile.h"
#include "TH1.h"

//#define _DEBUG_

VertexAnalyzer::VertexAnalyzer(const edm::ParameterSet& iConfig)
//:_SeeTracks(0),_SeeHits(0),_ChiOverNCut(10000),_ZRange(1000),eeevvv(0)
{
/*
  _SeeTracks = iConfig.getParameter<double>("SeeTrack");
  _SeeHits = iConfig.getParameter<double>("SeeHits");
  _ChiOverNCut = iConfig.getParameter<double>("ChiOverNCut");
  _ZRange =  iConfig.getParameter<double>("ZRange");
*/

  simVertexContainerLabel = iConfig.getParameter<edm::InputTag>("SimVertexContainerLabel");
 
}


VertexAnalyzer::~VertexAnalyzer()
{
 
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
VertexAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup )
{

 
  using namespace edm;



// get G4 Vertexes
  std::vector<SimVertex> theSimVertexes;
  std::vector<math::XYZPointD> theRecVertexes;

  Handle<SimVertexContainer> SimVtx;
  iEvent.getByLabel(simVertexContainerLabel, SimVtx);
  theSimVertexes.insert(theSimVertexes.end(),SimVtx->begin(),SimVtx->end());

  edm::Handle<vector<math::XYZPointD> > vertexCollection;
  iEvent.getByLabel("PrimaryVertexFinder", vertexCollection);
  theRecVertexes.insert(theRecVertexes.end(),vertexCollection->begin(),vertexCollection->end());

  double SimPriVert[3];
  double RecPriVert[3];

  if(!theSimVertexes.empty() && !theRecVertexes.empty()) {
    SimPriVert[0] = theSimVertexes.begin()->position().x();
    SimPriVert[1] = theSimVertexes.begin()->position().y();
    SimPriVert[2] = theSimVertexes.begin()->position().z();

    RecPriVert[0] = theRecVertexes.begin()->x();
    RecPriVert[1] = theRecVertexes.begin()->y();
    RecPriVert[2] = theRecVertexes.begin()->z();

    for(std::vector<math::XYZPointD>::iterator irecvtx = theRecVertexes.begin(); irecvtx != theRecVertexes.end(); ++irecvtx){
      V2D->SetPoint(jojo,irecvtx->x(),irecvtx->y(),irecvtx->z() );
      jojo++;
    }

    hxVrec->Fill( RecPriVert[0] );
    hyVrec->Fill( RecPriVert[1] );
    hzVrec->Fill( RecPriVert[2] );
    hxVresidual->Fill( SimPriVert[0] - RecPriVert[0]);
    hyVresidual->Fill( SimPriVert[1] - RecPriVert[1]);
    hzVresidual->Fill( SimPriVert[2] - RecPriVert[2]);

    hxVsim->Fill( SimPriVert[0] );
    hyVsim->Fill( SimPriVert[1] );
    hzVsim->Fill( SimPriVert[2] );

    hxVrec->GetXaxis()->SetTitle("cm") ; // RecPriVert[0] ;
    hyVrec->GetXaxis()->SetTitle("cm") ; // RecPriVert[1] ;
    hzVrec->GetXaxis()->SetTitle("cm") ; // RecPriVert[2] ;
    hxVresidual->GetXaxis()->SetTitle("cm") ; // SimPriVert[0] - RecPriVert[0] ;
    hyVresidual->GetXaxis()->SetTitle("cm") ; // SimPriVert[1] - RecPriVert[1];
    hzVresidual->GetXaxis()->SetTitle("cm") ; // SimPriVert[2] - RecPriVert[2];
    hxVsim->GetXaxis()->SetTitle("cm") ; // SimPriVert[0] ;
    hyVsim->GetXaxis()->SetTitle("cm") ; // SimPriVert[1] ;
    hzVsim->GetXaxis()->SetTitle("cm") ; // SimPriVert[2] ;

  }
  else {
    edm::LogError("VertexAnalyzer") << "SimPriVert or RecPriVert is empty";
  }
}


// ------------ method called once each job just before starting event loop  ------------
void 
VertexAnalyzer::beginJob()
{
  

  theFile = new TFile("vertexFile.root","RECREATE");
  hxVrec = new TH1D("xVrec","xVrec",500,-100,100);
  hyVrec = new TH1D("yVrec","yVrec",500,-100,100);
  hzVrec = new TH1D("zVrec","zVrec",500,-1000,1000);
  hxVsim = new TH1D("xVsim","xVsim",500,-100,100);
  hyVsim = new TH1D("yVsim","yVsim",500,-100,100);
  hzVsim = new TH1D("zVsim","zVsim",500,-1000,1000);

  hxVresidual = new TH1D("xVresidual","xVresidual",500,-100,100);
  hyVresidual = new TH1D("yVresidual","yVresidual",500,-100,100);
  hzVresidual = new TH1D("zVresidual","zVresidual",500,-1000,1000);

  V2D = new TGraph2D("V");
  jojo=0;

}

// ------------ method called once each job just after ending the event loop  ------------
void 
VertexAnalyzer::endJob() {
  V2D->Write();

  hxVrec->Write();
  hyVrec->Write();
  hzVrec->Write();
  hxVsim->Write();
  hyVsim->Write();
  hzVsim->Write();
  hxVresidual->Write();
  hyVresidual->Write();
  hzVresidual->Write();




//  theFile->Write();
  theFile->Close();

  std::cout << " END OF VERTEX ANALYZER " << std::endl;
}
