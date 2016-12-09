/**
 * Class AlignParamtype.
 *
 * Author: Mirko Berretti / University of Siena 
 * Email:  mirko.berretti@gmail.com
 * Date:   2007-12-08
 */ //TrackInfo.h

#ifndef _TrackInfo_h
#define _TrackInfo_h
#include <vector>
#include <map>
#include <utility>
//#include "FWCore/Framework/interface/ESHandle.h"
//#include "FWCore/Framework/interface/EDProducer.h"
//#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/T2Hit/interface/T2Hit.h"
//#include "DataFormats/T2Road/interface/T2Road.h"
#include "DataFormats/T2Cluster/interface/T2PadClusterCollection.h"
#include "DataFormats/T2Cluster/interface/T2StripClusterCollection.h"
#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "DataFormats/T2Road/interface/T2Road.h"
#include "DataFormats/T2Road/interface/T2RoadCollection.h"
/*
#include "DataFormats/T1T2Track/interface/T1T2Track.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"
#include "DataFormats/T1DetId/interface/T1DetId.h"
#include "DataFormats/T1DigiWire/interface/T1DigiWireCollection.h"
#include "DataFormats/T1DigiVfat/interface/T1DigiVfatCollection.h"
#include "Geometry/TotemGeometry/interface/T1Geometry.h"
#include "DataFormats/T1Road/interface/T1RecHitGlobal.h"
#include "DataFormats/T1T2Track/interface/T1T2TrackCollection.h"
#include "DataFormats/T1RecHit/interface/T1RecHit2D.h"
#include "DataFormats/T1RecHit/interface/T1RecHit2DCollection.h"
#include "DataFormats/T1Cluster/interface/T1Cluster.h"
#include "DataFormats/T1Cluster/interface/T1ClusterCollection.h"
*/


class TrackInfo {
public:
  /// Constructor
  TrackInfo();
  /// Destructor
  virtual ~TrackInfo();
  

  struct IdandHit
  {
    T2Hit thehit;
    unsigned int iddet;
    double dr;
    double dphi;
//R-phi fit
    double OLDdr;
    double OLDdphi;
  };
 

  unsigned int eventnumber;
  unsigned int goodhitnumber;
  std::vector<IdandHit> idactive;
  //T1T2Track thetrack;
  double ar;
  double br;
  double bphi;
  double aphi;
  double chiR;
  //R-phi fit
  double OLDar;
  double OLDbr;
  double OLDbphi;
  double OLDaphi;
  

};
#endif
