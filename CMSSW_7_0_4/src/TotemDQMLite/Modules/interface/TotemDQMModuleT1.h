#ifndef _TotemDQMLite_TotemDQMModuleT1_h_
#define _TotemDQMLite_TotemDQMModuleT1_h_

#include "TH1D.h"
#include "TH2F.h"
#include "THnSparse.h"
#include "TGraphErrors.h"
#include "TF1.h"

#include "FWCore/Common/interface/EventBase.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TotemDQMLite/Core/interface/DQMModule.h"
#include "Geometry/TotemGeometry/interface/T1Geometry.h"

class TotemDQMModuleT1 : public DQMModule
{
  

private:
T1Geometry * theT1Geometry;
    edm::InputTag tagDigiColl;
    edm::InputTag tagDigiCollStrip;
    edm::InputTag tagRecoColl;
  

protected:

 struct CSCPlots{
    TH1D *StripA_digi_profile_cumulative;
    TH1D *StripA_digi_profile_one_event;
    TH1D *StripB_digi_profile_cumulative;
    TH1D *StripB_digi_profile_one_event;
    TH1D *Wire_digi_profile_cumulative;
    TH1D *Wire_digi_profile_one_event;
   TH1D *Wire_digi_number_cumulative;
   TH1D *StripA_digi_number_cumulative;
   TH1D *StripB_digi_number_cumulative;

   TH2D *Reco_hits_cumulative;
   TH1D *Reco_hits_number_cumulative;

    CSCPlots() {}
    CSCPlots(unsigned int id);
  };


  struct ARMPlots{
    TH2D *Reco_hits_one_event;
    ARMPlots(){}
    ARMPlots(unsigned int id);
  };

  ////////////////////////////////////////////////////////////////

  std::map<unsigned int, CSCPlots> cscPlots;                     // csc Plots;
  std::map<unsigned int, ARMPlots> armPlots;                     // csc Plots;
//  std::map<unsigned int, VFatPlots> vFatPlots;                 // VfatPlots;

  bool buildCorrelationPlots;                         
  std::string correlationPlotsFilter;                 
  unsigned int correlationPlotsLimit;
  
    
  std::string CluLabel;
  std::string HitLabel;
  std::string RoadLabel;
  std::string TrackLabel;
  std::string MaxEvents;

  bool FirstTrkAlreadyFilled;

  public:
    TotemDQMModuleT1(const edm::ParameterSet &ps);
    ~TotemDQMModuleT1();

//    unsigned int RawtoSymb(uint32_t thedet);
    static std::string PathHistoName(unsigned int arm);
    static std::string PathHistoName(unsigned int arm, unsigned int plane);
    static std::string PathHistoName(unsigned int arm, unsigned int plane, unsigned int csc);
    static std::string PathHistoName(unsigned int arm, unsigned int plane, unsigned int csc, unsigned int Vfatid);

    virtual void beginJob();
    virtual void endJob();
    virtual void analyze(const edm::EventBase &);
};

#endif
