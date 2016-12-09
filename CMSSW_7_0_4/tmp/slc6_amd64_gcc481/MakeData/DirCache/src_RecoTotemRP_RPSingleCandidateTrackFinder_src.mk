ifeq ($(strip $(RecoTotemRP/RPSingleCandidateTrackFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPSingleCandidateTrackFinder_src
src_RecoTotemRP_RPSingleCandidateTrackFinder_src_parent := RecoTotemRP/RPSingleCandidateTrackFinder
src_RecoTotemRP_RPSingleCandidateTrackFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPSingleCandidateTrackFinder_src,src/RecoTotemRP/RPSingleCandidateTrackFinder/src,LIBRARY))
RecoTotemRPRPSingleCandidateTrackFinder := self/RecoTotemRP/RPSingleCandidateTrackFinder
RecoTotemRP/RPSingleCandidateTrackFinder := RecoTotemRPRPSingleCandidateTrackFinder
RecoTotemRPRPSingleCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPSingleCandidateTrackFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPSingleCandidateTrackFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPSingleCandidateTrackFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPSingleCandidateTrackFinder/BuildFile
RecoTotemRPRPSingleCandidateTrackFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId
RecoTotemRPRPSingleCandidateTrackFinder_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPSingleCandidateTrackFinder,RecoTotemRPRPSingleCandidateTrackFinder,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPSingleCandidateTrackFinder/src))
RecoTotemRPRPSingleCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/src
ALL_PRODS += RecoTotemRPRPSingleCandidateTrackFinder
RecoTotemRPRPSingleCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/src,src_RecoTotemRP_RPSingleCandidateTrackFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
