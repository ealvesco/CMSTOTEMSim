/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*  Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "TotemAnalysis/TestBeam/interface/Efficiency.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"

#include "DataFormats/TotemRPDataTypes/interface/RPStripDigi.h"
#include "DataFormats/TotemRPDataTypes/interface/RPRecoHit.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "Geometry/TotemRPGeometryBuilder/interface/TotemRPGeometry.h"
#include "Geometry/TotemRecords/interface/RealGeometryRecord.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPFittedTrackCollection.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPTrackCandidateCollection.h"

#include <TH1D.h>
#include <TH2D.h>


using namespace edm;
using namespace std;

//----------------------------------------------------------------------------------------------------

Efficiency::PotPlots::PotPlots()
{
  char name[512], name2[512], name3[512];
  int bins = 50;
  for (int i=0; i<10; i++)
   {
	sprintf(name, "hits_det_%d",i);
	sprintf(name2, "fit_det_%d",i);
	sprintf(name3, "eff_det_%d",i);
	hit_pos_det[i] = new TH1D(name, ";position", bins, -20, 20);	//detected
	hit_fit_det[i] = new TH1D(name2, ";position", bins, -20, 20);	//expected
	h_array_eff[i] = new TH1D(name3, name3, bins, -20, 20);		//efficiency
   }
}

//----------------------------------------------------------------------------------------------------

void Efficiency::beginJob()
{
}

//----------------------------------------------------------------------------------------------------

void Efficiency::Analyze(const RPTrackCandidateCollection *selHits, const RPFittedTrackCollection *tracks, const TotemRPGeometry *geometry)
{
  for(RPTrackCandidateCollection::const_iterator dit = selHits->begin() ; dit!=selHits->end(); ++dit)
  {
    if(!dit->second.Fittable())
      continue;
    unsigned int RPId = dit->first;
    const vector<RPRecoHit> &rhs = dit->second.TrackRecoHits();

    for (vector<RPRecoHit>::const_iterator hit = rhs.begin(); hit != rhs.end(); ++hit) 
    {
      unsigned int detId = TotRPDetId::RawToDecId(hit->DetId());
      unsigned int plane = detId % 10;
 
	RPFittedTrackCollection::const_iterator ftit = tracks->find(RPId);
	if (ftit == tracks->end()) {
		// problem
		return;
	}
      if (hit == rhs.begin()) {
	for (int i=0; i<10; i++) {
	   unsigned int rawDetId = TotRPDetId::DecToRawId(RPId * 10 + i);
	   double zp = geometry->GetDetTranslation(rawDetId).z();
	   TVector2 v = ftit->second.GetTrackPoint(zp);
	  if(i%2 ==0) {
	   plots[RPId].hit_fit_det[i]->Fill(v.X());
	  }
	  else {
	   plots[RPId].hit_fit_det[i]->Fill(v.Y());
	  }
	}
      }
      
      double zp = geometry->GetDetTranslation(hit->DetId()).z();
      TVector2 v = ftit->second.GetTrackPoint(zp);
      for (unsigned int k=0; k<10; k++) {
	if(k%2 == 0) {
	  if(plane==k) plots[RPId].hit_pos_det[k]->Fill(v.X());
	}
	else {
	  if(plane==k) plots[RPId].hit_pos_det[k]->Fill(v.Y());
	}	
      }	
    }
  }
}

//----------------------------------------------------------------------------------------------------

void Efficiency::endJob()
{
  for (map<unsigned int, PotPlots>::iterator it = plots.begin(); it != plots.end(); ++it)
  {
    for(int i=0; i<10; i++)
      it->second.h_array_eff[i]->Divide(it->second.hit_pos_det[i], it->second.hit_fit_det[i]);
  }
}
