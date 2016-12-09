ifeq ($(strip $(RecoTotemRP/RPNonParallelTrackCandidateFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src_parent := RecoTotemRP/RPNonParallelTrackCandidateFinder
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src,LIBRARY))
RecoTotemRPRPNonParallelTrackCandidateFinder := self/RecoTotemRP/RPNonParallelTrackCandidateFinder
RecoTotemRP/RPNonParallelTrackCandidateFinder := RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPNonParallelTrackCandidateFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/BuildFile
RecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats Geometry/Records DataFormats/TotemRPDetId root rootgraphics
RecoTotemRPRPNonParallelTrackCandidateFinder_EX_LIB   := RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_EX_USE   := $(foreach d,$(RecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPNonParallelTrackCandidateFinder_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src
ALL_PRODS += RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
