/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "DataFormats/TotemRPDataTypes/interface/RPStripDigi.h"
#include "DataFormats/TotemRPDataTypes/interface/RPRecoHit.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPTrackCandidateCollection.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPTrackCandidate.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "Geometry/TotemRPGeometryBuilder/interface/TotemRPGeometry.h"
#include "Geometry/TotemRecords/interface/RealGeometryRecord.h"
#include "RecoTotemRP/RPRecoDataFormats/interface/RPFittedTrackCollection.h"

#include <TCanvas.h>
#include <TFile.h>

#include "TotemAnalysis/TestBeam/interface/Efficiency.h"

using namespace std;
using namespace edm;

//----------------------------------------------------------------------------------------------------

/**
 *\brief Various statistics (active plane counts etc) for data obtained in test beam.
**/
class TestbeamTrackStatistics : public edm::EDAnalyzer
{
  public:   
    struct PotInfo
    {
      std::set<unsigned char> u_planes, v_planes;
    };

    struct PotPlots
    {
      TH1D *all_ap_u, *all_ap_v, *all_ap_umv, *all_ap_min;
      TH2D *all_ap_uvv, *central_ap_uvv;
      TH1D *sel_ap_u, *sel_ap_v, *sel_ap_umv, *sel_ap_min;
      TH2D *sel_ap_uvv;
      TH1D *strip_distr;

      PotPlots();
    };

    std::map<unsigned int, PotPlots> plots;

    TestbeamTrackStatistics(const edm::ParameterSet &ps);
    ~TestbeamTrackStatistics() {}

  private:
    edm::InputTag tagStripDigi, tagRecoHit, tagTrackCandColl, tagTrackColl;

    unsigned int verbosity;
    std::string outputFile;

    Efficiency efficiency;

    virtual void beginJob();
    virtual void analyze(const edm::Event &e, const edm::EventSetup &es);
    virtual void endJob();
};

//----------------------------------------------------------------------------------------------------/

TestbeamTrackStatistics::PotPlots::PotPlots()
{
  all_ap_u = new TH1D("all_ap_u", ";active planes in u", 6, -0.5, 5.5);
  all_ap_v = new TH1D("all_ap_v", ";active planes in v", 6, -0.5, 5.5);
  all_ap_umv = new TH1D("all_ap_umv", ";active planes in u - a.p. in v", 11, -5.5, 5.5);
  all_ap_min = new TH1D("all_ap_min", ";minimum of active planes in u and v", 6, -0.5, 5.5);
  all_ap_uvv = new TH2D("all_app_uvv", ";active planes in u;active planes in v", 6, -0.5, 5.5, 6, -0.5, 5.5);
  central_ap_uvv = new TH2D("central_app_uvv", ";active planes in u;active planes in v", 6, -0.5, 5.5, 6, -0.5, 5.5);

  sel_ap_u = new TH1D("sel_ap_u", ";active planes in u", 6, -0.5, 5.5);
  sel_ap_v = new TH1D("sel_ap_v", ";active planes in v", 6, -0.5, 5.5);
  sel_ap_umv = new TH1D("sel_ap_umv", ";active planes in u - a.p. in v", 11, -5.5, 5.5);
  sel_ap_min = new TH1D("sel_ap_min", ";minimum of active planes in u and v", 6, -0.5, 5.5);
  sel_ap_uvv = new TH2D("sel_app_uvv", ";active planes in u;active planes in v", 6, -0.5, 5.5, 6, -0.5, 5.5);
  strip_distr = new TH1D("strip_distr", ";strip", 512, 0, 512);
}



//----------------------------------------------------------------------------------------------------

TestbeamTrackStatistics::TestbeamTrackStatistics(const edm::ParameterSet &ps) :
  tagStripDigi(ps.getParameter<edm::InputTag>("tagStripDigi")),
  tagRecoHit(ps.getParameter<edm::InputTag>("tagRecoHit")),
  tagTrackCandColl(ps.getParameter<edm::InputTag>("tagTrackCandColl")),
  tagTrackColl(ps.getParameter<edm::InputTag>("tagTrackColl"))
{
  verbosity = ps.getUntrackedParameter<unsigned int>("verbosity", 0);
  outputFile = ps.getParameter<std::string>("outputFile");
}

//----------------------------------------------------------------------------------------------------

void TestbeamTrackStatistics::beginJob()
{
  efficiency.beginJob();
}

//----------------------------------------------------------------------------------------------------

void TestbeamTrackStatistics::analyze(const edm::Event &event, const edm::EventSetup &evSet)
{
  Handle< edm::DetSetVector<RPStripDigi> > stripHits;
  event.getByLabel(tagStripDigi, stripHits);

  Handle< edm::DetSetVector<RPRecoHit> > allHits;
  event.getByLabel(tagRecoHit, allHits); 

  Handle<RPTrackCandidateCollection> selHits;
  event.getByLabel(tagTrackCandColl, selHits);

  Handle<RPFittedTrackCollection> tracks;
  event.getByLabel(tagTrackColl, tracks);
  
  ESHandle<TotemRPGeometry> geometry;
  evSet.get<RealGeometryRecord>().get(geometry);
  
  efficiency.Analyze(selHits.product(), tracks.product(), geometry.product());

  if (verbosity > 5)
    printf("\nEVENT %i\n", event.id().event());

  map<unsigned int, PotInfo> allHitsMap, selHitsMap;

  // for some statistics we need to select only events in the central part of detectors,
  // where we know that the beam was there
  // this is a rather temporary test
  bool centralEvent = true;

  for (DetSetVector<RPStripDigi>::const_iterator it = stripHits->begin(); it != stripHits->end(); ++it) {
    	unsigned int detId = TotRPDetId::RawToDecId(it->detId());
    	unsigned int RPId = TotRPDetId::RPOfDet(detId);
    	unsigned int plane = detId % 10;
	if(plane==0){
 	   for (DetSet<RPStripDigi>::const_iterator dit = it->begin(); dit != it->end(); ++dit){
		dit->GetStripNo();
		plots[RPId].strip_distr->Fill(dit->GetStripNo());
		}
	   }
	}

  // process all hits collection
  for (DetSetVector<RPRecoHit>::const_iterator dit = allHits->begin(); dit != allHits->end(); ++dit) {
    unsigned int detId = TotRPDetId::RawToDecId(dit->detId());
    unsigned int RPId = TotRPDetId::RPOfDet(detId);
    unsigned int plane = detId % 10;
    bool uDir = TotRPDetId::IsStripsCoordinateUDirection(detId);

    if (! dit->empty()) {
      if (uDir) allHitsMap[RPId].u_planes.insert(plane);
      else allHitsMap[RPId].v_planes.insert(plane);
    }

    // check for centrality
    for (DetSet<RPRecoHit>::const_iterator hit = dit->begin(); hit != dit->end(); ++hit) {

     if (fabs(hit->Position()) > 10) {
        centralEvent = false;
        break;
      }
    }
  }


  // process selected hits collection
  for (RPTrackCandidateCollection::const_iterator dit = selHits->begin(); dit != selHits->end(); ++dit) {
	if (!dit->second.Fittable())
      continue;
    unsigned int RPId = dit->first;
    const vector<RPRecoHit> &rhs = dit->second.TrackRecoHits();

    for (vector<RPRecoHit>::const_iterator hit = rhs.begin(); hit != rhs.end(); ++hit) {
      unsigned int detId = TotRPDetId::RawToDecId(hit->DetId());
      unsigned int plane = detId % 10;
      bool uDir = TotRPDetId::IsStripsCoordinateUDirection(detId);

      if (uDir) selHitsMap[RPId].u_planes.insert(plane);
      else selHitsMap[RPId].v_planes.insert(plane);
    }
  }

  for (map<unsigned int, PotInfo>::iterator it = allHitsMap.begin(); it != allHitsMap.end(); ++it) {
    const PotPlots &pp = plots[it->first];
    pp.all_ap_u->Fill(it->second.u_planes.size());
    pp.all_ap_v->Fill(it->second.v_planes.size());
    pp.all_ap_umv->Fill(double(it->second.u_planes.size()) - it->second.v_planes.size());
    pp.all_ap_min->Fill(min(it->second.u_planes.size(), it->second.v_planes.size()));
    pp.all_ap_uvv->Fill(it->second.u_planes.size(), it->second.v_planes.size());


    if (centralEvent) pp.central_ap_uvv->Fill(it->second.u_planes.size(), it->second.v_planes.size());
  }

  for (map<unsigned int, PotInfo>::iterator it = selHitsMap.begin(); it != selHitsMap.end(); ++it) {
    const PotPlots &pp = plots[it->first];
    pp.sel_ap_u->Fill(it->second.u_planes.size());
    pp.sel_ap_v->Fill(it->second.v_planes.size());
    pp.sel_ap_umv->Fill(double(it->second.u_planes.size()) - it->second.v_planes.size());
    pp.sel_ap_min->Fill(min(it->second.u_planes.size(), it->second.v_planes.size()));
    pp.sel_ap_uvv->Fill(it->second.u_planes.size(), it->second.v_planes.size());
  }


}

//----------------------------------------------------------------------------------------------------

void TestbeamTrackStatistics::endJob()
{
  efficiency.endJob();

  TFile *f = new TFile(outputFile.c_str(), "recreate");
  TCanvas *cx = new TCanvas("v_hits", "v_hits", 600, 848);
  //gStyle->SetOptFit(1011);
  //gStyle->SetOptStat(1111);
  //gStyle->SetStatX(0.5);
  cx->Divide(2,5);
  //cx->cd(1);
  for (map<unsigned int, Efficiency::PotPlots>::iterator it = efficiency.plots.begin(); it != efficiency.plots.end(); ++it) {
    for (int i=0; i<5; i++) {
	cx->cd(1+2*i);
        it->second.h_array_eff[2*i+1]->Draw();
	it->second.h_array_eff[2*i+1]->Fit("pol0","Q");
	cx->cd(2+2*i);
	it->second.hit_fit_det[2*i+1]->SetLineColor(4);
	it->second.hit_fit_det[2*i+1]->SetLineStyle(2);
	it->second.hit_fit_det[2*i+1]->SetLineWidth(2);
	it->second.hit_fit_det[2*i+1]->Draw();
	it->second.hit_pos_det[2*i+1]->SetLineWidth(2);
	it->second.hit_pos_det[2*i+1]->Draw("same");
    }
  }  
  cx->Write(); 
 
  TCanvas *cy = new TCanvas("u_hits", "u_hits", 600, 848);
  cy->Divide(2,5);
  //cx->cd(1);
  for (map<unsigned int, Efficiency::PotPlots>::iterator it = efficiency.plots.begin(); it != efficiency.plots.end(); ++it) {
    for (int i=0; i<5; i++) {
	cy->cd(1+2*i);
        it->second.h_array_eff[2*i]->Draw();
	it->second.h_array_eff[2*i]->Fit("pol0","Q");
	cy->cd(2+2*i);
	it->second.hit_fit_det[2*i]->SetLineColor(4);
	it->second.hit_fit_det[2*i]->SetLineStyle(2);
	it->second.hit_fit_det[2*i]->SetLineWidth(2);
	it->second.hit_fit_det[2*i]->Draw();
	it->second.hit_pos_det[2*i]->SetLineWidth(2);
	it->second.hit_pos_det[2*i]->Draw("same");
    }
  }  
  cy->Write();  

  for (map<unsigned int, PotPlots>::iterator it = plots.begin(); it != plots.end(); ++it) {
    char buf[20];
    sprintf(buf, "%i", it->first);
    gDirectory = gDirectory->mkdir(buf);

    it->second.all_ap_u->Write();
    it->second.all_ap_v->Write();
    it->second.all_ap_umv->Write();
    it->second.all_ap_min->Write();
    it->second.all_ap_uvv->Write();
    it->second.central_ap_uvv->Write();

    it->second.sel_ap_u->Write();
    it->second.sel_ap_v->Write();
    it->second.sel_ap_umv->Write();
    it->second.sel_ap_min->Write();
    it->second.sel_ap_uvv->Write();

    /*
  for (int i=0; i<10; i++) {
    it->second.hit_pos_det[i]->Write();
    it->second.hit_fit_det[i]->Write();
  }
  */
    for (int i = 0; i < 10; i++) {
      efficiency.plots[it->first].hit_pos_det[i]->Write();
      efficiency.plots[it->first].hit_fit_det[i]->Write();
    }
    it->second.strip_distr->Write();

    gDirectory->cd("..");
  }

  delete f;
}

DEFINE_FWK_MODULE(TestbeamTrackStatistics);
