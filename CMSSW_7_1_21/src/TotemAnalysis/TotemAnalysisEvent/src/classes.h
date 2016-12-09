
#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"
//#include "TotemAnalysis/TotemAnalysisEvent/interface/RPTrackInfo.h"
#include "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h"

#include "DataFormats/Common/interface/Wrapper.h"
#include <vector>
#include <map>

namespace {
   struct dictionary {
      TotemRPEvent totemRPEvent;

      RPRootDumpTrackInfo               rpTrackInfo;
      RPRootDumpDigiInfo                rpDigiInfo;
      RPRootDumpReconstructedProton     rpReconstructedProton;
      RPRootDumpReconstructedProtonPair rpReconstructedProtonPair;
      RPRootDumpPattern                 rpPattern;
      RPRootDumpPatternInfo             rpPatternInfo;

      std::vector<RPRootDumpTrackInfo>           vec_rpTrackInfo;
      std::vector<RPRootDumpDigiInfo>            vec_rpDigiInfo;
      std::vector<RPRootDumpPatternInfo>         vec_rpPatternInfo;
      std::vector<RPRootDumpReconstructedProton> vec_rpReconstructedProton;
  
      std::map<unsigned int, RPRootDumpTrackInfo>    track_info_;
      std::map<unsigned int, RPRootDumpDigiInfo>     digi_info_;
      std::map<unsigned int, RPRootDumpPatternInfo>  patterns_info_;

      std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > multi_track_info_;
      std::map<unsigned int, RPRootDumpReconstructedProton>     rec_pr_info_;

      edm::Wrapper<TotemRPEvent>                  totemRPEvent_wr;

      edm::Wrapper<RPRootDumpTrackInfo>               rpTrackInfo_wr;
      edm::Wrapper<RPRootDumpDigiInfo>                rpDigiInfo_wr;
      edm::Wrapper<RPRootDumpReconstructedProton>     rpReconstructedProton_wr;
      edm::Wrapper<RPRootDumpReconstructedProtonPair> rpReconstructedProtonPair_wr;
      edm::Wrapper<RPRootDumpPattern>                 rpPattern_wr;
      edm::Wrapper<RPRootDumpPatternInfo>             rpPatternInfo_wr;

      edm::Wrapper<std::vector<RPRootDumpTrackInfo> >           vec_rpTrackInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpDigiInfo> >            vec_rpDigiInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpPatternInfo> >         vec_rpPatternInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpReconstructedProton> > vec_rpReconstructedProton_wr;

      edm::Wrapper<std::map<unsigned int, RPRootDumpTrackInfo> >               track_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpDigiInfo> >                digi_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpPatternInfo> >             patterns_info_wr;
      edm::Wrapper<std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > > multi_track_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpReconstructedProton> >     rec_pr_info_wr;

   };
} 
