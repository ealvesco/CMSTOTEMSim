ifeq ($(strip $(RecoTotemRP/RPTrackCandidateFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateFitter_src
src_RecoTotemRP_RPTrackCandidateFitter_src_parent := RecoTotemRP/RPTrackCandidateFitter
src_RecoTotemRP_RPTrackCandidateFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateFitter_src,src/RecoTotemRP/RPTrackCandidateFitter/src,LIBRARY))
RecoTotemRPRPTrackCandidateFitter := self/RecoTotemRP/RPTrackCandidateFitter
RecoTotemRP/RPTrackCandidateFitter := RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTrackCandidateFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTrackCandidateFitter/BuildFile
RecoTotemRPRPTrackCandidateFitter_LOC_USE := self  FWCore/Framework boost DataFormats/Common DataFormats/TotemRPDataTypes root clhep Geometry/TotemRPGeometryBuilder RecoTotemRP/RPDetectorMaskingService RecoTotemRP/RPRecoDataFormats Geometry/TotemRPDetTopology FWCore/ParameterSet
RecoTotemRPRPTrackCandidateFitter_EX_LIB   := RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_EX_USE   := $(foreach d,$(RecoTotemRPRPTrackCandidateFitter_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPTrackCandidateFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateFitter/src
ALL_PRODS += RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTrackCandidateFitter,src/RecoTotemRP/RPTrackCandidateFitter/src,src_RecoTotemRP_RPTrackCandidateFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
