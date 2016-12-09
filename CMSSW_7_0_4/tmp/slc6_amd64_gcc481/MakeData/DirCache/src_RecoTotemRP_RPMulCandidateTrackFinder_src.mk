ifeq ($(strip $(RecoTotemRP/RPMulCandidateTrackFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPMulCandidateTrackFinder_src
src_RecoTotemRP_RPMulCandidateTrackFinder_src_parent := RecoTotemRP/RPMulCandidateTrackFinder
src_RecoTotemRP_RPMulCandidateTrackFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulCandidateTrackFinder_src,src/RecoTotemRP/RPMulCandidateTrackFinder/src,LIBRARY))
RecoTotemRPRPMulCandidateTrackFinder := self/RecoTotemRP/RPMulCandidateTrackFinder
RecoTotemRP/RPMulCandidateTrackFinder := RecoTotemRPRPMulCandidateTrackFinder
RecoTotemRPRPMulCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPMulCandidateTrackFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulCandidateTrackFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPMulCandidateTrackFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPMulCandidateTrackFinder/BuildFile
RecoTotemRPRPMulCandidateTrackFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost root rootgraphics DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId
RecoTotemRPRPMulCandidateTrackFinder_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPMulCandidateTrackFinder,RecoTotemRPRPMulCandidateTrackFinder,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPMulCandidateTrackFinder/src))
RecoTotemRPRPMulCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPMulCandidateTrackFinder/src
ALL_PRODS += RecoTotemRPRPMulCandidateTrackFinder
RecoTotemRPRPMulCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/src,src_RecoTotemRP_RPMulCandidateTrackFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
