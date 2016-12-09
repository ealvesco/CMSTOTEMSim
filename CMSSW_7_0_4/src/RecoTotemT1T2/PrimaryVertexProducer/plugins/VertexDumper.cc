/*
  Created by Fabrizio Ferro - INFN Genova for TOTEM
*/
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "RecoTotemT1T2/PrimaryVertexProducer/interface/VertexDumper.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"




#include <vector>


  using namespace edm;
  using namespace std;
//#define _DEBUG_

VertexDumper::VertexDumper(const edm::ParameterSet& iConfig)

{
  ev = 0;
}


VertexDumper::~VertexDumper()
{
 
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
VertexDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup )
{

 
  using namespace edm;
  using namespace std;

  ev++;



  std::vector<math::XYZPointD> theRecVertexes;



  edm::Handle<vector<math::XYZPointD> > vertexCollection;
  iEvent.getByLabel("PrimaryVertexFinder", vertexCollection);
  theRecVertexes.insert(theRecVertexes.end(),vertexCollection->begin(),vertexCollection->end());



  if(theRecVertexes.size()>0){
    for(std::vector<math::XYZPointD>::iterator irecvtx = theRecVertexes.begin(); irecvtx != theRecVertexes.end(); ++irecvtx){


//    file << iEvent.id().event() << " "<< irecvtx->x()<< " "<< irecvtx->y()<< " "<< irecvtx->z()<<endl;
    file << ev << " "<< irecvtx->x()<< " "<< irecvtx->y()<< " "<< irecvtx->z()<<endl;

  }
   
  }


}


// ------------ method called once each job just before starting event loop  ------------
void 
VertexDumper::beginJob()
{
  

  file.open("v.dat",ios::out);

}

// ------------ method called once each job just after ending the event loop  ------------
void 
VertexDumper::endJob() {


  file.close();

  std::cout << " END OF VERTEX ANALYZER2 " << std::endl;
}
