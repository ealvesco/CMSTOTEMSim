ifeq ($(strip $(RecoTotemRP/RPStationMultiTrackFinderFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_src
src_RecoTotemRP_RPStationMultiTrackFinderFitter_src_parent := RecoTotemRP/RPStationMultiTrackFinderFitter
src_RecoTotemRP_RPStationMultiTrackFinderFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_src,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src,LIBRARY))
RecoTotemRPRPStationMultiTrackFinderFitter := self/RecoTotemRP/RPStationMultiTrackFinderFitter
RecoTotemRP/RPStationMultiTrackFinderFitter := RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPStationMultiTrackFinderFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPStationMultiTrackFinderFitter/BuildFile
RecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords Geometry/TotemRPDetTopology root
RecoTotemRPRPStationMultiTrackFinderFitter_EX_LIB   := RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_EX_USE   := $(foreach d,$(RecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPStationMultiTrackFinderFitter_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/src
ALL_PRODS += RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src,src_RecoTotemRP_RPStationMultiTrackFinderFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
