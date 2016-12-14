
#include "UATree/UABaseTree/interface/UABaseTree.h"

bool TotemRPDebug = true;

void UABaseTree::GetTotemRP(const edm::Event& event, const edm::EventSetup& setup)
{
  edm::Handle<TotemRPEvent> totemRPEventH;
  event.getByLabel( totemRP_, totemRPEventH );
   if(TotemRPDebug){cout << "Totem RP starting " << endl; }

  track_info_ = map<unsigned int, RPRootDumpTrackInfo>();
  digi_info_ =  map<unsigned int, RPRootDumpDigiInfo>();
  par_patterns_info_ = map<unsigned int, RPRootDumpPatternInfo >();
  nonpar_patterns_info_ = map<unsigned int, RPRootDumpPatternInfo >();
  //if(TotemRPDebug){cout << "Totem RP maps " << endl; }

  multi_track_info_ = map<unsigned int, std::vector<RPRootDumpTrackInfo> >();
  rec_pr_info_ = map<unsigned int, RPRootDumpReconstructedProton>();
  sim_pr_info_ = map<unsigned int, RPRootDumpReconstructedProton>();
  rec_pr_pair_info_ = RPRootDumpReconstructedProtonPair();

  if( totemRPEventH.isValid() ){
    //  cout  << totemRPEventH.isValid() << endl;                                                                               

     const TotemRPEvent* totemRPEvent_ptr = totemRPEventH.product();
     totemRPEvent_ = *totemRPEvent_ptr;

     if(TotemRPDebug){
	cout << "RP Track size: " << totemRPEvent_.track_info_.size() << endl; 
	cout << "RP Digi size: " << totemRPEvent_.digi_info_.size() << endl; 
	cout << "RP Patterns size: " << totemRPEvent_.par_patterns_info_.size() << endl; 
	cout << "RP Patterns size: " << totemRPEvent_.nonpar_patterns_info_.size() << endl; 
	cout << "RP Multi Track size: " << totemRPEvent_.multi_track_info_.size() << endl; 
	cout << "RP Rec. Proton size: " << totemRPEvent_.rec_pr_info_.size() << endl; 
	cout << "RP Sim. Proton size: " << totemRPEvent_.sim_pr_info_.size() << endl; 
     }

     track_info_ = totemRPEvent_.track_info_;
     digi_info_ = totemRPEvent_.digi_info_;
     par_patterns_info_ = totemRPEvent_.par_patterns_info_;
     nonpar_patterns_info_ = totemRPEvent_.nonpar_patterns_info_;

     multi_track_info_ = totemRPEvent_.multi_track_info_;
     rec_pr_info_ = totemRPEvent_.rec_pr_info_;
     sim_pr_info_ = totemRPEvent_.sim_pr_info_;
     rec_pr_pair_info_ = totemRPEvent_.rec_pr_pair_info_;
 
     }

  //if(TotemRPDebug) {}

}

