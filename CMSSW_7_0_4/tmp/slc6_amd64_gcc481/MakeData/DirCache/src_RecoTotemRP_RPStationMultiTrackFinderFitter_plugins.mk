ifeq ($(strip $(RecoTotemRPRPStationMultiTrackFinderFitterAuto)),)
RecoTotemRPRPStationMultiTrackFinderFitterAuto_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPStationMultiTrackFinderFitterAuto := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins
RecoTotemRPRPStationMultiTrackFinderFitterAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins/BuildFile
RecoTotemRPRPStationMultiTrackFinderFitterAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/Common DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords RecoTotemRP/RPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitterAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPStationMultiTrackFinderFitterAuto,RecoTotemRPRPStationMultiTrackFinderFitterAuto,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins))
RecoTotemRPRPStationMultiTrackFinderFitterAuto_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins
ALL_PRODS += RecoTotemRPRPStationMultiTrackFinderFitterAuto
RecoTotemRPRPStationMultiTrackFinderFitterAuto_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPStationMultiTrackFinderFitterAuto,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins,src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPStationMultiTrackFinderFitterAuto,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins
src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins_parent := RecoTotemRP/RPStationMultiTrackFinderFitter
src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins,PLUGINS))
