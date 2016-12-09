/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*	Jan Kašpar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "TotemAnalysis/TotemNtuplizer/interface/Ntuplizer.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RawMetaDataNtuplizer.h"
#include "TotemAnalysis/TotemNtuplizer/interface/TriggerDataNtuplizer.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RPNtuplizer.h"
#include "TotemAnalysis/TotemNtuplizer/interface/T2Ntuplizer.h"
#include "TotemAnalysis/TotemNtuplizer/interface/T1Ntuplizer.h"
#include "TotemCondFormats/DataRecord/interface/BeamOpticsParamsRcd.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizer.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "TTree.h"
#include "TFile.h"

#include <vector>
#include <string>

/**
 * Common Ntuplizer for all TOTEM subdetectors.
 **/
class TotemNtuplizer : public edm::EDAnalyzer
{
  public:
    TotemNtuplizer(const edm::ParameterSet&);
    ~TotemNtuplizer() {}

    virtual void beginRun(edm::Run const&, edm::EventSetup const&);
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    
    virtual void beginJob();
    virtual void endJob();

  protected:
    unsigned int verbosity;

    /// the name of the ROOT file with the final ntuple
    std::string outputFileName;

    /// the file where to save the ntuple
    TFile *file;   

    /// the ntuple
    TTree *tree;

    /// list of ntuple-making objects
    std::vector<Ntuplizer *> workers;
    
    /// internal reference to RPNtuplizer
    RPNtuplizer *rp_ntupl_;
    
    // flag for branch creating
    bool branchCreated; 
};

using namespace std;
using namespace edm;

//----------------------------------------------------------------------------------------------------

TotemNtuplizer::TotemNtuplizer(const edm::ParameterSet &ps) :
  verbosity(ps.getUntrackedParameter<unsigned int>("verbosity", 0)),
  outputFileName(ps.getUntrackedParameter<string>("outputFileName")),
  rp_ntupl_(NULL)
{
  vector<string> modules = ps.getParameter< vector<string> >("modules");

  for (auto m : modules)
  {
    if (m.compare("raw") == 0)
      workers.push_back(new RawMetaDataNtuplizer(ps));
      
    if (m.compare("trigger") == 0)
      workers.push_back(new TriggerDataNtuplizer(ps));

    if (m.compare("rp") == 0)
      workers.push_back(rp_ntupl_ = new RPNtuplizer(ps));

    if (m.compare("rp-timing") == 0)
      workers.push_back(new RPTimingDetectorsNtuplizer(ps));

    if (m.compare("t1") == 0)
      workers.push_back(new T1Ntuplizer(ps));

    if (m.compare("t2") == 0)
      workers.push_back(new T2Ntuplizer(ps));
  }
  
  branchCreated = false;
}

//----------------------------------------------------------------------------------------------------

void TotemNtuplizer::beginRun(edm::Run const& r, edm::EventSetup const& es)
{
  if (rp_ntupl_)
  {
    edm::ESHandle<BeamOpticsParams> BOParH;
    es.get<BeamOpticsParamsRcd>().get(BOParH);
    if (!BOParH.isValid())
      throw cms::Exception("TotemNtuplizer::beginRun") << " edm::ESHandle<BeamOpticsParams> is invalid";

    rp_ntupl_->SetOpticsConfig(*BOParH);
  }

  // let all workes create their branches
  if (branchCreated == false)
  {
    for (vector<Ntuplizer *>::iterator it = workers.begin(); it != workers.end(); ++it)
      (*it)->CreateBranches(es, tree);
    branchCreated = true;
  }
}

//----------------------------------------------------------------------------------------------------

void TotemNtuplizer::beginJob()
{
  // open dump file and preapre dump tree branches
  file = new TFile(outputFileName.c_str(), "recreate");
  tree = new TTree("TotemNtuple", "TotemNtuple");
}

//----------------------------------------------------------------------------------------------------

void TotemNtuplizer::analyze(const edm::Event &ev, const edm::EventSetup &es)
{
  // let all workes fill their event data
  for (vector<Ntuplizer *>::iterator it = workers.begin(); it != workers.end(); ++it) {
    try {
      (*it)->FillEvent(ev, es);
    } catch (const std::exception& ex) {
      if(verbosity > 0) {
        std::cout << "TotemNtuplizer exception: " << "'" << ex.what() << "'" << std::endl;
      }
    } catch (...) {
      if(verbosity > 0) {
        std::cout << "Unknown TotemNtuplizer exception occurred!" << std::endl;
      }
    }
  }

  // commit the data
  tree->Fill();
}

//----------------------------------------------------------------------------------------------------

void TotemNtuplizer::endJob()
{
  file->cd();
  tree->Write();
  delete file;
}

//----------------------------------------------------------------------------------------------------

DEFINE_FWK_MODULE(TotemNtuplizer);
