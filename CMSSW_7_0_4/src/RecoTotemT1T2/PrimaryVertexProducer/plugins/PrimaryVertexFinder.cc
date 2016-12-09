/*
  Created by Fabrizio Ferro - INFN Genova for TOTEM
*/
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
/*
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"
*/
#include "RecoVertex/VertexTools/interface/FsmwModeFinder3d.h"
#include "RecoTotemT1T2/PrimaryVertexProducer/interface/PrimaryVertexFinder.h"

#include <vector>
#include "assert.h"
#include "TFile.h"
#include "TH1.h"


using namespace edm;
using namespace reco;

//#define _T2_TOO_
//#define _DEBUG_

#define _90DEG 1.570796327
#define _270DEG 4.71238898

PrimaryVertexFinder::PrimaryVertexFinder(const edm::ParameterSet& iConfig):_SeeTracks(0),_SeeHits(0),_ChiOverNCut(10000),_ZRange(1000),_Rmin(100),_Verbosity(0),_Dets(12),_NumberOfTracks(100),_ZCenter(0),_FromOutside(false)
{
  _SeeTracks = iConfig.getParameter<double>("SeeTrack");
  _SeeHits = iConfig.getParameter<double>("SeeHits");
  _ChiOverNCut = iConfig.getParameter<double>("ChiOverNCut");
  _ZRange =  iConfig.getParameter<double>("ZRange");
  _Verbosity = iConfig.getParameter<int>("Verbosity");
  _Rmin = iConfig.getParameter<double>("TrackRmin");
  _Dets = iConfig.getParameter<int>("Telescopes");
  _ZCenter = iConfig.getParameter<double>("ZCenter");
  _NumberOfTracks = iConfig.getParameter<int>("NumberOfTracks");
  _FromOutside = iConfig.getParameter<bool>("FromOutside");

  produces< vector<math::XYZPointD> >();

  trackCollection = new T1T2TrackCollection();

}

PrimaryVertexFinder::~PrimaryVertexFinder()
{
  delete trackCollection;
}

//
// member functions
//

// ------------ method called to for each event  ------------
void PrimaryVertexFinder::produce(edm::Event& iEvent, const edm::EventSetup& iSetup )
{

 
  trackCollection->clear();

  vector< pair< GlobalPoint, float > > V_PaD;

  vector< pair<double,double> >::iterator pair_it;

// get G4 Vertexe
/*s
  std::vector<SimVertex> theSimVertexes;

  Handle<SimVertexContainer> SimVtx;
  iEvent.getByType(SimVtx);
  theSimVertexes.insert(theSimVertexes.end(),SimVtx->begin(),SimVtx->end());
*/


  edm::Handle<T1T2TrackCollection> t1trackCollection;
  iEvent.getByLabel("t1tracks2","T1TrackColl",t1trackCollection);
  
#ifdef _T2_TOO_

  edm::Handle<T1T2TrackCollection> t2trackCollection;
  iEvent.getByLabel("T2TrackColl","T2TrackColl",t2trackCollection);
  
#else
  T1T2TrackCollection * t2trackCollection = 0;
#endif




  auto_ptr< vector<math::XYZPointD> > vertexCollection(new vector<math::XYZPointD> );
/*
  double SimPriVert[3];

  int hjk=0;
  for(std::vector<SimVertex>::iterator isimvtx = theSimVertexes.begin(); isimvtx != theSimVertexes.end(); ++isimvtx){
    if(_Verbosity>1)
      cout << "                                                 SIM Z Vertice["<<hjk<<"] = "<<isimvtx->position().x() <<" "<<isimvtx->position().y() <<" "<<isimvtx->position().z() <<"  cm"<< endl;

    if(hjk==0){
      SimPriVert[0] = isimvtx->position().x();
      SimPriVert[1] = isimvtx->position().y();
      SimPriVert[2] = isimvtx->position().z();
    }
    hjk++;
  }
*/


  if(_Verbosity>0){

    switch(_Dets){
    case 1:
      std::cout << "Using only T1 for Vertex finding" << std::endl;
      break;
    case 2:
      std::cout << "Using only T2 for Vertex finding" << std::endl;
      break;
    case 12:
      std::cout << "Using both T1 and T2 for Vertex finding" << std::endl;
      break;
    case -12:
      std::cout << "Using negative T1 and T2 for Vertex finding" << std::endl;
      break;
    case 11:
      std::cout << "Using only T1 PLUS for Vertex finding" << std::endl;
      break;
     case -11:
      std::cout << "Using only T1 MINUS for Vertex finding" << std::endl;
      break;
 
    }

    if(_Dets == 1 || _Dets == 12 || _Dets == -12 || _Dets == 11 || _Dets == -11)
    std::cout << " Taglia della T1 track collection: " << t1trackCollection->size() <<std::endl;
   if(_Dets == 2 || _Dets == 12 || _Dets == -12)
    std::cout << " Taglia della T2 track collection: " << t2trackCollection->size() <<std::endl;
  
  }
  if (t1trackCollection->size() == 0) std::cout << "             WARNING: No tracks in T1 in the event !      ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]] " <<std::endl;

  T1T2TrackCollection::const_iterator TC_it1;
  T1T2TrackCollection::const_iterator TC_it2;
  T1T2TrackCollection::const_iterator TC_it;
  T1T2TrackCollection::const_iterator TC_it_;
  int numero=0;
  vector<int> *indiceTracce = new vector<int>;
  vector<int>::iterator indiceTracce_it;


// fill a new track collection with all the tracks of T1 and T2
// cuts should be put here

// 11 = T1 only arm plus; -11 = T1 only arm minus

  assert(_Dets == 1 || _Dets ==2 || _Dets ==12 || _Dets == -12 || _Dets == 11 || _Dets == -11 || _Dets == 110 || _Dets == 111 || _Dets == -110 || _Dets == -111);

  if(_Dets == 110){  // PLUS NEAR only
        for(TC_it1=t1trackCollection->begin(); TC_it1!=t1trackCollection->end(); TC_it1++){
	  if((*TC_it1).Eta() > 0 && ((*TC_it1).Phi() < _90DEG || (*TC_it1).Phi() > _270DEG) ){
	    trackCollection->push_back(*TC_it1);
	  }
	}
  }else if(_Dets == 111){ // PLUS FAR only
    for(TC_it1=t1trackCollection->begin(); TC_it1!=t1trackCollection->end(); TC_it1++){
      if((*TC_it1).Eta() > 0 && ((*TC_it1).Phi() > _90DEG && (*TC_it1).Phi() < _270DEG) ){
	trackCollection->push_back(*TC_it1);
      }
    } 
  }
  else if(_Dets == -111){  // MINUS NEAR only
        for(TC_it1=t1trackCollection->begin(); TC_it1!=t1trackCollection->end(); TC_it1++){
	  if((*TC_it1).Eta() < 0 && ((*TC_it1).Phi() < _90DEG || (*TC_it1).Phi() > _270DEG) ){
	    trackCollection->push_back(*TC_it1);
	  }
	}
  }else if(_Dets == -110){ // MINUS FAR only
    for(TC_it1=t1trackCollection->begin(); TC_it1!=t1trackCollection->end(); TC_it1++){
      if((*TC_it1).Eta() < 0 && ((*TC_it1).Phi() > _90DEG && (*TC_it1).Phi() < _270DEG) ){
	trackCollection->push_back(*TC_it1);
      }
    } 
  }
  
  else if(_Dets == 1 || _Dets ==12 || _Dets == -12 || _Dets == 11 || _Dets == -11)
    for(TC_it1=t1trackCollection->begin(); TC_it1!=t1trackCollection->end(); TC_it1++){
      
      if((*TC_it1).Eta() < 0 && _Dets != 11){
	trackCollection->push_back(*TC_it1);
      }else{
//	if( (*TC_it1).Z_at_Rmin()> 0 && (*TC_it1).Z_at_Rmin()<7000)
	if(_Dets == 1 || _Dets ==12 || (_Dets == 11 && (*TC_it1).Eta() > 0 ))trackCollection->push_back(*TC_it1);
      }
    }
  else if(_Dets == 2 || _Dets ==12 || _Dets == -12)
    for(TC_it2=t2trackCollection->begin(); TC_it2!=t2trackCollection->end(); TC_it2++){
      
      trackCollection->push_back(*TC_it2);
    }

  else{  assert(0==1);}




// first loop over tracks
  for(TC_it=trackCollection->begin(); TC_it!=trackCollection->end(); TC_it++){
    if(0==0){


      if(_SeeTracks > 0){
	std::cout << "Track #"<<++numero << " in detector " << (*TC_it).GetDet();
	std::cout << "  Track Size: " << (*TC_it).GetHitEntries() << std::endl;
	std::cout << std::endl;
	std::cout << "         XZ: x = ( "<<(*TC_it).GetTx()<<" +/- " << (*TC_it).GetTxSigma()<< " ) * z + ( "<< (*TC_it).X0()<<" +/- " << (*TC_it).X0Sigma()<< " )"<<std::endl;
	std::cout << "         YZ: y = ( "<<(*TC_it).GetTy()<<" +/- " << (*TC_it).GetTySigma()<< " ) * z + ( "<< (*TC_it).Y0()<<" +/- " << (*TC_it).Y0Sigma()<< " )"<<std::endl; 
	std::cout << "         Eta = "<< (*TC_it).Eta() << " Phi = " << (*TC_it).Phi() << " Rmin = " << (*TC_it).Rmin() << " Z_at_Rmin = " << (*TC_it).Z_at_Rmin() <<
	  " Chi2 = "<<(*TC_it).ChiSquared()<<	" Chi2/N = "<<(*TC_it).ChiSquaredOverN()<<std::endl;  
      }


      bool fromOut1 = false;
	for(unsigned int iy = 0; iy < (*TC_it).GetHitEntries(); iy++){
	  if(_SeeHits > 0)
	    std::cout << (*TC_it).GetHitT1(iy) <<std::endl;
	  if(iy == ((*TC_it).GetHitEntries()-1) ){
	    float RRR1 = sqrt(    (*TC_it).GetHitT1(0).GlobalPosition().x()*(*TC_it).GetHitT1(0).GlobalPosition().x()+(*TC_it).GetHitT1(0).GlobalPosition().y()*(*TC_it).GetHitT1(0).GlobalPosition().y()         );
	    float RRR2 = sqrt(    (*TC_it).GetHitT1(iy).GlobalPosition().x()*(*TC_it).GetHitT1(iy).GlobalPosition().x()+(*TC_it).GetHitT1(iy).GlobalPosition().y()*(*TC_it).GetHitT1(iy).GlobalPosition().y()         );
	    
	    if((( ((*TC_it).GetHitT1(0).GlobalPosition().x()*(*TC_it).GetHitT1(0).GlobalPosition().x()+(*TC_it).GetHitT1(0).GlobalPosition().y()*(*TC_it).GetHitT1(0).GlobalPosition().y()) - ((*TC_it).GetHitT1(iy).GlobalPosition().x()*(*TC_it).GetHitT1(iy).GlobalPosition().x()+(*TC_it).GetHitT1(iy).GlobalPosition().y()*(*TC_it).GetHitT1(iy).GlobalPosition().y()) )*(    fabs((*TC_it).GetHitT1(0).GlobalPosition().z()) - fabs((*TC_it).GetHitT1(iy).GlobalPosition().z())  ))<0)
	      {
		fromOut1 = true;

		std::cout << " Track from Outside. Z1=" << (*TC_it).GetHitT1(0).GlobalPosition().z() <<"  R1="<<RRR1 <<"  Z2=" << (*TC_it).GetHitT1(iy).GlobalPosition().z() <<"  R2="<<RRR2 <<"  Z_at_Rmin=" << (*TC_it).Z_at_Rmin() << "  Rmin=" <<  (*TC_it).Rmin() << std::endl;
	      }
	    
	  }

 
	}

// second loop over tracks
      for(TC_it_=TC_it+1; TC_it_ != trackCollection->end(); TC_it_++){
	bool fromOut2 = false;
	for(unsigned int iy = 0; iy < (*TC_it_).GetHitEntries(); iy++){

	  if(iy == ((*TC_it_).GetHitEntries()-1) ){
 
	    if((( ((*TC_it_).GetHitT1(0).GlobalPosition().x()*(*TC_it_).GetHitT1(0).GlobalPosition().x()+(*TC_it_).GetHitT1(0).GlobalPosition().y()*(*TC_it_).GetHitT1(0).GlobalPosition().y()) - ((*TC_it_).GetHitT1(iy).GlobalPosition().x()*(*TC_it_).GetHitT1(iy).GlobalPosition().x()+(*TC_it_).GetHitT1(iy).GlobalPosition().y()*(*TC_it_).GetHitT1(iy).GlobalPosition().y()) )*(    fabs((*TC_it_).GetHitT1(0).GlobalPosition().z()) - fabs((*TC_it_).GetHitT1(iy).GlobalPosition().z())  ))<0)
	      {
		fromOut2 = true;
	      }
	  }
	}

	

	if(trackCollection->size() > 1 &&  (int)trackCollection->size() < _NumberOfTracks)
	  if( ((*TC_it).Z_at_Rmin() < (_ZCenter + _ZRange)) &&  ((*TC_it).Z_at_Rmin() > (_ZCenter - _ZRange)) && ((*TC_it_).Z_at_Rmin() < (_ZCenter + _ZRange)) &&  ((*TC_it_).Z_at_Rmin() > (_ZCenter - _ZRange)) )
	    if( (*TC_it).Rmin() < _Rmin &&  (*TC_it_).Rmin() < _Rmin)
	      if((_FromOutside && fromOut1 && fromOut2) || !_FromOutside)
	      if( (*TC_it).ChiSquaredOverN() < _ChiOverNCut && (*TC_it_).ChiSquaredOverN() < _ChiOverNCut ){
		pair< GlobalPoint, float >  coppia ;
		TwoTracksMinD((*TC_it),(*TC_it_),coppia);

		if(_Verbosity>0){
		  std::cout <<"Zetas " << (*TC_it).Z_at_Rmin() << " "<< (*TC_it_).Z_at_Rmin()<<std::endl;
		  std::cout <<"Rmin " << (*TC_it).Rmin() << " "<< (*TC_it_).Rmin()<<std::endl;
		  std::cout << coppia.first << " " << coppia.second << std::endl;
		}
		V_PaD.push_back(coppia);
	      }
      } 
    }
  //    std::cout << " DETECTOR: " << (*TC_it).GetDet()<< std::endl;
  }


  if(V_PaD.size() > 0){
    const vector< pair< GlobalPoint, float > > V_PaD_c = V_PaD;

    FsmwModeFinder3d Finder;
    GlobalPoint Vert = Finder(V_PaD_c);
    math::XYZPointD Vert_(Vert.x(),Vert.y(),Vert.z() );

    std::cout << "                                                          RECO Vert "<<Vert << "  cm" <<std::endl;


    vertexCollection->push_back(Vert_);


  }
 
  delete indiceTracce;
  

  iEvent.put(vertexCollection);
}



void PrimaryVertexFinder::TwoTracksMinD(T1T2Track t1, T1T2Track t2, pair<GlobalPoint, float> & coppia_){

//  std::cout << "Inside TwoTracksMinD " <<std::endl;
  long double a1x ;
  long double b1x ;
  long double a1y;
  long double b1y ;

  long double a2x ;
  long double b2x ;
  long double a2y ;
  long double b2y ;


  if(t1.GetDet()==1 && t2.GetDet()==1){
    a1x = t1.GetTx(); 
    b1x = t1.X0(); 
    a1y = t1.GetTy(); 
    b1y = t1.Y0();

    a2x = t2.GetTx(); 
    b2x = t2.X0(); 
    a2y = t2.GetTy(); 
    b2y = t2.Y0(); 
  }else if(t1.GetDet()==2 && t2.GetDet()==2){
    a1x = t1.GetTy() * cos( t1.Phi() ); 
    b1x = t1.GetTx() * cos( t1.Phi() ); 
    a1y = t1.GetTy() * sin( t1.Phi() ); 
    b1y = t1.GetTx() * sin( t1.Phi() ); 
       
    a2x = t2.GetTy() * cos( t2.Phi() ); 
    b2x = t2.GetTx() * cos( t2.Phi() ); 
    a2y = t2.GetTy() * sin( t2.Phi() ); 
    b2y = t2.GetTx() * sin( t2.Phi() ); 
       
  }else if(t1.GetDet()==1 && t2.GetDet()==2){
    a1x = t1.GetTx(); 
    b1x = t1.X0(); 
    a1y = t1.GetTy(); 
    b1y = t1.Y0();
       
    a2x = t2.GetTy() * cos( t2.Phi() ); 
    b2x = t2.GetTx() * cos( t2.Phi() ); 
    a2y = t2.GetTy() * sin( t2.Phi() ); 
    b2y = t2.GetTx() * sin( t2.Phi() ); 
       
  }else if(t1.GetDet()==2 && t2.GetDet()==1){
    a2x = t2.GetTx(); 
    b2x = t2.X0(); 
    a2y = t2.GetTy(); 
    b2y = t2.Y0();
       
    a1x = t1.GetTy() * cos( t1.Phi() ); 
    b1x = t1.GetTx() * cos( t1.Phi() ); 
    a1y = t1.GetTy() * sin( t1.Phi() ); 
    b1y = t1.GetTx() * sin( t1.Phi() ); 
  }
  else{
    std::cout << "ERROR: wrong detector number in track. " << std::endl;
    assert(0);
  }




  long double A = 1 + a1x * a2x + a1y * a2y;
  long double B1 = a1x*b2x + a1y*b2y - a1x*b1x - a1y*b1y;
  long double B2 =  a2x*b1x + a2y*b1y - a2x*b2x - a2y*b2y;
  long double C1 = 1 + a1x*a1x + a1y*a1y;
  long double C2 = 1 + a2x*a2x + a2y*a2y;
  long double S = (B2*C1 + A*B1)/(C1*C2-A*A);
  long double T = A/C1*S + B1/C1;

// long double dsquared = (S*S*(C2-(A*A/C1)))-2.*(S*(A*B1/C1+B2))+(D-(B1*B1/C1));
/* 
   std::cout << "a1x="<< a1x << " b1x="<< b1x <<" a1y="<< a1y <<" b1y="<< b1y <<std::endl;
   std::cout << "a2x="<< a2x << " b2x="<< b2x <<" a2y="<< a2y <<" b2y="<< b2y <<std::endl;

   std::cout << "A="<< A << " B1="<< B1 << " B2="<< B2 << " C1="<< C1 << " C2="<< C2 << " D="<< D<< " S="<< S << " T="<< T << std::endl;
   std::cout << S*S*C2-(S*S*A*A/C1) << " " << -2.*(S*(A*B1/C1+B2)) << " "<< (D-(B1*B1/C1))<<std::endl;
   std::cout << "dsquared="<<dsquared <<std::endl;

*/


//-----------------------------
// new algorithm
/*

  double dsquared_2 = 0;
  double d_min =0 ;
  double AAAA=0; double AAAAAA=0; double mod_v_ort_sq=0;
  if(a1x != a2x){

    AAAA = (a2y - a1y)/(a2x-a1x);
    AAAAAA = (a1x*a2y - a2x*a1y)/(a2x-a1x);

    mod_v_ort_sq = AAAA*AAAA + AAAAAA*AAAAAA + 1;

    d_min = ( (b1x-b2x)*(a2y-a1y)/(a1x-a2x)+(b1y-b2y))/sqrt(mod_v_ort_sq);

    dsquared_2 = d_min * d_min;

  }

  else{
    d_min = sqrt( (b1x-b2x)*(b1x-b2x) )/ (1 + (a1x+a2x)*(a1x+a2x)/4.) ;
    dsquared_2 = d_min*d_min;
  }
*/

// terzo algoritmo
  double d_min_3=0;
  {
    double bx12 = b1x-b2x;
    double ax12 = a1x-a2x;
    double by12 = b1y-b2y;
    double ay12 = a1y-a2y;
    double a12cross = a1x*a2y-a1y*a2x;
    double NNN = fabs(bx12*ay12 - by12*ax12);
    double DDD = sqrt(ay12*ay12 + ax12*ax12 + a12cross*a12cross);
    assert(DDD>0);
    d_min_3 = NNN/DDD;
  }


/*
  if(dsquared<0){
    cout << " WARNING : dsquared < 0 !!! dsquared = " << dsquared << "  CHECK IT OUT! Hardwired to 0." << endl;
 dsquared=0;
  }
*/
//  assert(dsquared >= 0);
//----------------------------


//  double d = sqrt(dsquared);

// cout << " +++++++++++++++    DISTANZA tra due rette " << d << " " << d_min<< " " << d_min_3<< endl; 





  double x1 = b1x+T*a1x;
  double y1 = b1y+T*a1y;
  double z1 = T;
  double x2 = b2x+S*a2x;
  double y2 = b2y+S*a2y;
  double z2 = S;

//  double d_check = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

//  cout << " +++++++++++++++    DISTANZA check : " << d_check << endl;

  if(_Verbosity>1){
 
    std::cout << A << " " << B1<< " " << C1 << std::endl;

    std::cout << T << " " << S << std::endl;

    std::cout << " Lines: " <<std::endl;
    std::cout << "1: x = "<< a1x << " z + " << b1x 
	      << "    y = "<< a1y << " z + " << b1y <<std::endl;
    std::cout << "2: x = "<< a2x << " z + " << b2x 
	      << "    y = "<< a2y << " z + " << b2y <<std::endl;
    std::cout << "Minimum distance " << d_min_3 << std::endl;
    std::cout << "between points:" << std::endl;
    std::cout << "1: "<< x1 << ", "<<  y1 << ", "<<  z1 << " "<< std::endl;
    std::cout << "2: "<< x2 << ", "<<  y2 << ", "<<  z2 << " "<< std::endl;
  }

  GlobalPoint InMezzo(x1/20.+x2/20.,y1/20.+y2/20.,z1/20.+z2/20.); //to cm

  coppia_.first = InMezzo;
  coppia_.second = d_min_3/10.;
//  std::cout << " End of TwoTracksMinD"<<std::endl;
  return;
}
