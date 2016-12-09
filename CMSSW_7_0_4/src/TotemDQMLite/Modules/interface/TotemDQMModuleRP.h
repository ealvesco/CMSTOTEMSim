/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _TotemDQMLite_TotemDQMModuleRP_h_
#define _TotemDQMLite_TotemDQMModuleRP_h_


#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Common/interface/EventBase.h"

#include "TotemDQMLite/Core/interface/DQMModule.h"
#include "TotemDQMLite/Core/interface/MultiRootPlot.h"
#include "TotemDQMLite/Modules/interface/TrackInRPFigure.h"
#include "TotemDQMLite/Modules/interface/CorrelationPlotsSelector.h"
#include "TotemDQMLite/Geometry/interface/TotemRPGeometryLite.h"

#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "THnSparse.h"

/**
 * \ingroup TotemDQM
 * \brief A TotemDQM module producing plots related to RP.
 **/
class TotemDQMModuleRP : public DQMModule
{
  protected:
	/// input tags
    edm::InputTag tagRawEvent;
    edm::InputTag tagStripDigi;
    edm::InputTag tagDigiCluster;
    edm::InputTag tagRecoHit;
    edm::InputTag tagPatternColl;
    edm::InputTag tagTrackColl, tagTrackCandColl;
    edm::InputTag tagMultiTrackColl;

    bool buildCorrelationPlots;                           ///< decides wheather the correlation plots are created
    std::string correlationPlotsFilter;                   ///< decides which correlation plots are created
    unsigned int correlationPlotsLimit;                   ///< maximum number of created correlation plots
    CorrelationPlotsSelector correlationPlotsSelector;

    /// whether the results of pattern recognition shall be drawn
    bool drawRecognizedPatterns;

    /// plots related to one (anti)diagonal
    struct DiagonalPlots
    {
      int id;

      TGraph *g_lrc_x_d, *g_lrc_x_n, *g_lrc_x_f;
      TGraph *g_lrc_y_d, *g_lrc_y_n, *g_lrc_y_f;

      TH2D *h_lrc_x_d, *h_lrc_x_n, *h_lrc_x_f;
      TH2D *h_lrc_y_d, *h_lrc_y_n, *h_lrc_y_f;

      DiagonalPlots() {}

      DiagonalPlots(int _id);
    };

    std::map<unsigned int, DiagonalPlots> diagonalPlots;

    /// plots related to one arm
    struct ArmPlots
    {
      int id;

      TH1D *h_numRPWithTrack_top, *h_numRPWithTrack_hor, *h_numRPWithTrack_bot;
      TH2D *h_trackCorr, *h_trackCorr_overlap;

      ArmPlots() : id(0), h_numRPWithTrack_top(NULL), h_numRPWithTrack_hor(NULL), h_numRPWithTrack_bot(NULL) {}

      ArmPlots(int _id);
    };

    std::map<unsigned int, ArmPlots> armPlots;

    /// plots related to one station
    struct StationPlots
    {
      std::map<int, std::map<int, THnSparseD*> > hist;
      int id;
      CorrelationPlotsSelector *correlationPlotsSelector;

      TGraph *rpHits;

      StationPlots() : correlationPlotsSelector(NULL), rpHits(NULL) {}
      StationPlots(int _id, std::set<unsigned int> planes, bool allocateCorrelationPlots, 
        CorrelationPlotsSelector *correlationPlotsSelector, int limit = -1);
      void Add(std::set<unsigned int> planes, int limit = -1);
    };

	std::map<unsigned int, StationPlots> stationPlots;

    /// plots related to one RP
    struct PotPlots
    {
      TH1D *activity, *activity_u, *activity_v;
      TH2D *hit_plane_hist;
      TH1D *patterns_u, *patterns_v;
      TH1D *h_planes_fit_u, *h_planes_fit_v;
      TH1D *event_category;
      TrackInRPFigure *currentTrackInRP, *allTracksInRP;
      TGraph *detectorShape;
      TGraph *currentTrackXY, *currentMultiTracksXY;
      TGraph *trackHitsCumulative;
      TH2D *trackHitsCumulativeHist;
      TH1D *track_u_profile, *track_v_profile;
      TGraphErrors *uHitsAll, *vHitsAll;
      TGraphErrors *uHitsSel, *vHitsSel;
      TF1 *uTrack, *vTrack;
      MultiRootPlot *uView, *vView;
      MultiRootPlot *uvGlobalView;

      /// to fix scale of u, v projection plots
      TH2F *scaleFixer;

      PotPlots();
      PotPlots(unsigned int id, const TotemRPGeometryLite *geometry);
    };

	std::map<unsigned int, PotPlots> potPlots;

    /// plots related to one RP plane
    struct PlanePlots
    {
      TH1D *digi_profile_cumulative;
      TH1D *digi_profile_one_event;
      TH1D *cluster_profile_cumulative;
      TH1D *cluster_profile_one_event;
      TH1D *hit_multiplicity;
      TH1D *cluster_size;

      PlanePlots() : digi_profile_cumulative(NULL), digi_profile_one_event(NULL) {}
      PlanePlots(unsigned int id);
    };

	std::map<unsigned int, PlanePlots> planePlots;

    // TODO
    //Efficiency efficiency;

	TotemRPGeometryLite *geometry;

  public:
    TotemDQMModuleRP(const edm::ParameterSet&);
    ~TotemDQMModuleRP();

    virtual void beginJob();
    virtual void analyze(const edm::EventBase &);
    virtual void endJob() {};
};

#endif
