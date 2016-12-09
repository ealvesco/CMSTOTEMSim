ifeq ($(strip $(RecoTotemT1T2T2RoadPadFinderPlugins)),)
RecoTotemT1T2T2RoadPadFinderPlugins_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2RoadPadFinder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2RoadPadFinder/plugins/$(file). Please fix src/RecoTotemT1T2/T2RoadPadFinder/plugins/BuildFile.))))
RecoTotemT1T2T2RoadPadFinderPlugins := self/src/RecoTotemT1T2/T2RoadPadFinder/plugins
RecoTotemT1T2T2RoadPadFinderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RoadPadFinder/plugins/BuildFile
RecoTotemT1T2T2RoadPadFinderPlugins_LOC_USE := self  RecoTotemT1T2/T2RoadPadFinder FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Road DataFormats/T2Cluster
RecoTotemT1T2T2RoadPadFinderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2RoadPadFinderPlugins,RecoTotemT1T2T2RoadPadFinderPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2RoadPadFinder/plugins))
RecoTotemT1T2T2RoadPadFinderPlugins_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/plugins
ALL_PRODS += RecoTotemT1T2T2RoadPadFinderPlugins
RecoTotemT1T2T2RoadPadFinderPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RoadPadFinderPlugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins,src_RecoTotemT1T2_T2RoadPadFinder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2RoadPadFinderPlugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_plugins
src_RecoTotemT1T2_T2RoadPadFinder_plugins_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_plugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins,PLUGINS))
