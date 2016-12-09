ifeq ($(strip $(RecoTotemRP/RPTrackCandidateCollectionFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateCollectionFitter_src
src_RecoTotemRP_RPTrackCandidateCollectionFitter_src_parent := RecoTotemRP/RPTrackCandidateCollectionFitter
src_RecoTotemRP_RPTrackCandidateCollectionFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateCollectionFitter_src,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src,LIBRARY))
RecoTotemRPRPTrackCandidateCollectionFitter := self/RecoTotemRP/RPTrackCandidateCollectionFitter
RecoTotemRP/RPTrackCandidateCollectionFitter := RecoTotemRPRPTrackCandidateCollectionFitter
RecoTotemRPRPTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateCollectionFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTrackCandidateCollectionFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTrackCandidateCollectionFitter/BuildFile
RecoTotemRPRPTrackCandidateCollectionFitter_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter
RecoTotemRPRPTrackCandidateCollectionFitter_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPTrackCandidateCollectionFitter,RecoTotemRPRPTrackCandidateCollectionFitter,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPTrackCandidateCollectionFitter/src))
RecoTotemRPRPTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/src
ALL_PRODS += RecoTotemRPRPTrackCandidateCollectionFitter
RecoTotemRPRPTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src,src_RecoTotemRP_RPTrackCandidateCollectionFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
