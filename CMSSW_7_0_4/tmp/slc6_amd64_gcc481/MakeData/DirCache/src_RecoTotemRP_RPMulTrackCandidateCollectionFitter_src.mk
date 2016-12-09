ifeq ($(strip $(RecoTotemRP/RPMulTrackCandidateCollectionFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src_parent := RecoTotemRP/RPMulTrackCandidateCollectionFitter
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src,LIBRARY))
RecoTotemRPRPMulTrackCandidateCollectionFitter := self/RecoTotemRP/RPMulTrackCandidateCollectionFitter
RecoTotemRP/RPMulTrackCandidateCollectionFitter := RecoTotemRPRPMulTrackCandidateCollectionFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPMulTrackCandidateCollectionFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/BuildFile
RecoTotemRPRPMulTrackCandidateCollectionFitter_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPMulTrackCandidateCollectionFitter,RecoTotemRPRPMulTrackCandidateCollectionFitter,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src))
RecoTotemRPRPMulTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src
ALL_PRODS += RecoTotemRPRPMulTrackCandidateCollectionFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
