
#include "TotemAnalysis/TotemNtuplizer/interface/RPTrackInfo.h"

#include "DataFormats/Common/interface/Wrapper.h"
#include <vector>
#include <map>
namespace {
   struct dictionary {
      TotemEvent totemEvent;

      RPDumpTrackInfo               rpTrackInfo;
      RPDumpDigiInfo                rpDigiInfo;
      RPDumpReconstructedProton     rpReconstructedProton;
      RPDumpReconstructedProtonPair rpReconstructedProtonPair;
      RPDumpPattern                 rpPattern;
      RPDumpPatternInfo             rpPatternInfo;

      std::vector<RPRootDumpTrackInfo>           vec_rpTrackInfo;
      std::vector<RPRootDumpDigiInfo>            vec_rpDigiInfo;
      std::vector<RPRootDumpPatternInfo>         vec_rpPatternInfo;
      std::vector<RPRootDumpReconstructedProton> vec_rpReconstructedProton;
  
      std::map<unsigned int, RPRootDumpTrackInfo>    track_info_;
      std::map<unsigned int, RPRootDumpDigiInfo>     digi_info_;
      std::map<unsigned int, RPRootDumpPatternInfo> patterns_info_;

      std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > multi_track_info_;
      std::map<unsigned int, RPRootDumpReconstructedProton>     rec_pr_info_;

      edm::Wrapper<RPDumpTrackInfo>               rpTrackInfo_wr;
      edm::Wrapper<RPDumpDigiInfo>                rpDigiInfo_wr;
      edm::Wrapper<RPDumpReconstructedProton>     rpReconstructedProton_wr;
      edm::Wrapper<RPDumpReconstructedProtonPair> rpReconstructedProtonPair_wr;
      edm::Wrapper<RPDumpPattern>                 rpPattern_wr;
      edm::Wrapper<RPDumpPatternInfo>             rpPatternInfo_wr;

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
