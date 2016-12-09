/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*     
*   Mirko Berretti (mirko.berretti@gmail.com) 
*   The code have been developed for T2 purposes stared from the RP code
*   Jan Kašpar (jan.kaspar@gmail.com) Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _TotemDQMLite_TotemDQMModuleT2_h_
#define _TotemDQMLite_TotemDQMModuleT2_h_

#include "FWCore/Common/interface/EventBase.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TotemDQMLite/Core/interface/DQMModule.h"
#include "TotemDQMLite/Core/interface/MultiRootPlot.h"
#include "TotemDQMLite/Modules/interface/CorrelationPlotsSelectorT2.h"
#include "TotemDQMLite/Modules/interface/T2Efficiency.h"
#include "TotemRawDataLibrary/DataFormats/interface/RawEvent.h"
#include <set>

#include "THnSparse.h"
#include "TProfile2D.h"

class T2ROGeometry;
class TProfile2D;
class TH1D;
class TH2F;
class TGraphErrors;
class TF1;

/**
 *\brief A test DQM module.
 **/
class TotemDQMModuleT2 : public DQMModule
{
private:
     T2Efficiency efficiency;

  edm::InputTag tagDigiVfatColl;
  edm::InputTag tagPadDigiColl;
  edm::InputTag tagStripDigiColl;
  edm::InputTag tagStripClusterColl;
  edm::InputTag tagPadClusterColl;
  edm::InputTag tagHitColl;
  edm::InputTag tagRoadColl;
  edm::InputTag tagT1T2TrackColl;
  edm::InputTag tagRawEvent;

protected:
  ////////////////////////////////////////////////////////////////
 
  struct VFatPlots{
    TH1D *ActiveChOneEvt;
    TH1D *ActiveChCumulative;
    VFatPlots();
    VFatPlots(unsigned int plane,unsigned int vfatid);
    static unsigned int uniqueVfatID(unsigned int pl,unsigned int Idv);
  };



  struct PlanePlots{
    TH1D *Pad_digi_profile_cumulative;
    TH1D *Pad_digi_profile_one_event;
    TH1D *cluster_profile_cumulative;
    TH1D *cluster_profile_one_event;
    TH1D *hit_R_one_event;
    TH1D *hit_Phi_one_event;
    TH1D *Strip_ClusterSize_cumulative;
    TH1D *Strip_ClusterSize_one_event;
    TH1D *Pad_ClusterSize_cumulative;
    TH1D *Pad_ClusterSize_one_event;

    PlanePlots() : Pad_digi_profile_cumulative(NULL), Pad_digi_profile_one_event(NULL) {}
    PlanePlots(unsigned int id);
  };



  struct HalfTelescopePlots{  
    
    TH2F *currentTrackInHT;
    TH2F *allTracksInHT;
    TH2F *CorrelPad24;

    TProfile *PadCluMultPerPlane;
    TProfile *StripCluMultPerPlane;
    TH2F *TrkRPhi;
    
    TProfile *PadCluMultPerPlaneG;
    TProfile *StripCluMultPerPlaneG;
    TH2F *TrkRPhiG;

    TH1D *currentTrackInHT1D;
    TH1D *allTracksInHT1D;

    TProfile2D *VfatMultiplicityMap;
    TProfile2D *VfatMultiplicityMapG;
    HalfTelescopePlots();
    HalfTelescopePlots(unsigned int id);
    HalfTelescopePlots(unsigned int id, const T2ROGeometry*);                    ///< instantiate and register plots
  };





  struct OneArmPlotsGlobal{
    int id;
    // Graphs for hits in track with the fitted function superimposed
    // I put this graph here in order to monitor also possible disalignment between the halfs. 
    TGraphErrors *XHitsSel, *YHitsSel;
    TF1 *XTrack, *YTrack;
    // TGraphErrors *XHitsSelFirst, *YHitsSelFirst;
    // TF1 *XTrackFirst, *YTrackFirst;
    // MultiRootPlot *mRO;
    MultiRootPlot *mROX;// = new MultiRootPlot();
    MultiRootPlot *mROY;// = new MultiRootPlot();
    OneArmPlotsGlobal();
    OneArmPlotsGlobal(unsigned int _id);
  };

  struct OneArmPlots{
    int id;

    std::map<int, std::map<int, THnSparseD*> > hist;
    CorrelationPlotsSelectorT2 *correlationPlotsSelectorT2;
    
    OneArmPlots() : id(-1), correlationPlotsSelectorT2(NULL) {}
    OneArmPlots(int id, CorrelationPlotsSelectorT2 *correlationPlotsSelectorT2) : id(id), correlationPlotsSelectorT2(correlationPlotsSelectorT2) {}

    OneArmPlots(int _id, std::set<unsigned int> planes, CorrelationPlotsSelectorT2 *correlationPlotsSelectorT2, int limit = -1) : correlationPlotsSelectorT2(correlationPlotsSelectorT2) 
    { 
      id = _id;  
      Add(planes, limit);
    }

    void Add(std::set<unsigned int> planes, int limit = -1);

    };

 struct FullDetectorPlots{
   
   TH2F *TriggerandTracks;   
   TH2F *TriggerandTracksG;
   TH2F *OnBX_TriggerandTracks;   
   TH2F *OnBX_TriggerandTracksG; 
   TH2F *ALLTRKS_RPHIG;
   FullDetectorPlots();
   FullDetectorPlots(unsigned int _id);
 };

 
  ////////////////////////////////////////////////////////////////

  std::map<unsigned int, OneArmPlots> oneArmPlots;                   // Arm Correlation Plots;      //< registry of one-station plots
  std::map<unsigned int, OneArmPlotsGlobal>  oneArmPlotsGlobal;       // Global Arm Plots
  
  std::map<unsigned int, HalfTelescopePlots> halfTelescopePlots;     // HalfTele Plots; //< registry of one-pot plots
  std::map<unsigned int, PlanePlots> planePlots;                     // Plane Plots;
  std::map<unsigned int, VFatPlots> vFatPlots;                       // VfatPlots;

  // std::map<unsigned int, HalfTelescopePlotsGlobal> halfTelescopePlotsGlobal;                      
 std::map<unsigned int, FullDetectorPlots> fullDetectorPlots;                      

 //FullDetectorGlobal
 //HalfTelescopePlotsGlobal


  bool buildCorrelationPlots;                         
  std::string correlationPlotsFilter;                 
  unsigned int correlationPlotsLimit;
  CorrelationPlotsSelectorT2 correlationPlotsSelectorT2;

  bool FirstTrkAlreadyFilled;

  public:
    TotemDQMModuleT2(const edm::ParameterSet&);
    ~TotemDQMModuleT2();

    unsigned int RawtoSymb(uint32_t thedet);
    static std::string PathHistoName(unsigned int arm);
    static std::string PathHistoName(unsigned int arm, unsigned int ht);
    static std::string PathHistoName(unsigned int arm, unsigned int ht, unsigned int plane);
    static std::string PathHistoName(unsigned int arm, unsigned int ht, unsigned int plane, unsigned int Vfatid);

    virtual void beginJob();
    virtual void analyze(const edm::EventBase &);
    virtual void endJob();
};

#endif
