#include <memory>
#include <vector>
#include <iostream>
#include <set>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/TotemRPGeometryBuilder/interface/TotemRPGeometry.h"
#include "Geometry/TotemRecords/interface/RealGeometryRecord.h"
#include "CLHEP/Vector/ThreeVector.h"
#include "CLHEP/Vector/Rotation.h"
#include "DataFormats/TotemRPDataTypes/interface/RPTimingDetectorHit.h"
#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "TH1.h"
#include "TH2.h"
#include "TLine.h"

using namespace edm;
using namespace std;

class RPTimingDetectorsAnalysis : public edm::EDAnalyzer {
public:
    explicit RPTimingDetectorsAnalysis(const edm::ParameterSet&);
    ~RPTimingDetectorsAnalysis();

private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    std::map< unsigned int, TH2F *> xy_histogram;
    std::map< unsigned int, TH1F *> y_histogram;
    std::map< unsigned int, TH1F *> x_histogram;
    std::map< unsigned int, TH1F *> detectors_histogram;
    set<unsigned int> rp_ids = {
            1200, 1201, 1202, 1203,
            1210, 1211, 1212, 1213,
             200,  201,  202,  203,
             210,  211,  212,  213
    };

    std::map< unsigned int, CLHEP::Hep3Vector> rp_translations;
    std::map< unsigned int, CLHEP::HepRotation> rp_rotations;
};

RPTimingDetectorsAnalysis::RPTimingDetectorsAnalysis(const edm::ParameterSet& iConfig)
{
    edm::Service<TFileService> fs;
    for (auto &det_id: rp_ids) {
        char name[25];
        sprintf(name, "xy_%04d", det_id);
        xy_histogram[det_id] = fs->make<TH2F>(name, ";x   (mm);y   (mm)",
                                          100 , -21.5 , 21.5, 100 , -21.5 , 21.5);
        xy_histogram[det_id]->SetMarkerStyle(7);
        sprintf(name, "detector_%04d", det_id);
        detectors_histogram[det_id] = fs->make<TH1F>(name, ";electrode id;hits", 12 , 0.5 , 12.5);

        sprintf(name, "x_%04d", det_id);
        x_histogram[det_id] = fs->make<TH1F>(name, ";x   (mm)", 100 , -21.5 , 21.5);

        sprintf(name, "y_%04d", det_id);
        y_histogram[det_id] = fs->make<TH1F>(name, ";y   (mm)", 100 , -21.5 , 21.5);
    }
}


RPTimingDetectorsAnalysis::~RPTimingDetectorsAnalysis()
{
}

void
RPTimingDetectorsAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    // get translation and rotation

    edm::ESHandle<TotemRPGeometry> totem_rp_geometry;
    iSetup.get<RealGeometryRecord>().get(totem_rp_geometry);

    for (auto &rp_id_raw: rp_ids) {
        TotRPDetId rp_id_obj(TotRPDetId::DecToRawId(rp_id_raw));

        // add translation of detector to list
        if (rp_translations.find(rp_id_raw) == rp_translations.end()){
            CLHEP::Hep3Vector trans = totem_rp_geometry->GetDetTranslation(rp_id_obj);
            rp_translations[rp_id_raw] = trans;
        }

        // add rotation of detector to list
        if (rp_rotations.find(rp_id_raw) == rp_rotations.end()){
            double xx, xy, xz, yx, yy, yz, zx, zy, zz;
            (totem_rp_geometry->GetDetector(rp_id_obj)->rotation()).GetComponents(xx, xy, xz, yx, yy, yz, zx, zy, zz);
            CLHEP::HepRep3x3 rot_mat( xx, xy, xz, yx, yy, yz, zx, zy, zz);
            CLHEP::HepRotation rot(rot_mat);
            rp_rotations[rp_id_raw] = rot;
        }
    }

    // get hits
    edm::Handle<vector<PSimHit> > cf;
    iEvent.getByLabel("g4SimHits", "TotemHitsRP", cf);

    for (auto const &particle : *cf.product()) {
        if (particle.particleType() != 2212) continue;

        if (rp_ids.find(TotRPDetId::RawToDecId(particle.detUnitId())) == rp_ids.end()) {
            continue;
        }

        CLHEP::Hep3Vector point;
        point.setX(particle.entryPoint().x());
        point.setY(particle.entryPoint().y());

        unsigned int rp_id = TotRPDetId::RawToDecId(particle.detUnitId());

        CLHEP::Hep3Vector aligned_point = rp_rotations[rp_id] * point + rp_translations[rp_id];

        xy_histogram[rp_id]->Fill(aligned_point.x(), aligned_point.y());
        x_histogram[rp_id]->Fill(aligned_point.x());
        y_histogram[rp_id]->Fill(aligned_point.y());
    }

    //get detector data
    edm::Handle<vector<RPTimingDetectorHit> > td_hits;
    iEvent.getByLabel("RPTimingDetectorsDigiProducer", td_hits);
    for(auto &hit: *td_hits.product()) {
        detectors_histogram[TotRPDetId::RawToDecId(hit.GetDetId())]->Fill(hit.GetElectrodeId());
    }

}

void
RPTimingDetectorsAnalysis::beginJob()
{
}

void
RPTimingDetectorsAnalysis::endJob()
{
}

DEFINE_FWK_MODULE(RPTimingDetectorsAnalysis);
