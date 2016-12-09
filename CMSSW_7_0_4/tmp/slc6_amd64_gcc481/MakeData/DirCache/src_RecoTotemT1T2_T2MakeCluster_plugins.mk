ifeq ($(strip $(RecoTotemT1T2T2MakeClusterPlugins)),)
RecoTotemT1T2T2MakeClusterPlugins_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2MakeCluster/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2MakeCluster/plugins/$(file). Please fix src/RecoTotemT1T2/T2MakeCluster/plugins/BuildFile.))))
RecoTotemT1T2T2MakeClusterPlugins := self/src/RecoTotemT1T2/T2MakeCluster/plugins
RecoTotemT1T2T2MakeClusterPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2MakeCluster/plugins/BuildFile
RecoTotemT1T2T2MakeClusterPlugins_LOC_USE := self  RecoTotemT1T2/T2MakeCluster FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId boost root clhep DataFormats/T2Cluster
RecoTotemT1T2T2MakeClusterPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2MakeClusterPlugins,RecoTotemT1T2T2MakeClusterPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2MakeCluster/plugins))
RecoTotemT1T2T2MakeClusterPlugins_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/plugins
ALL_PRODS += RecoTotemT1T2T2MakeClusterPlugins
RecoTotemT1T2T2MakeClusterPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2MakeClusterPlugins,src/RecoTotemT1T2/T2MakeCluster/plugins,src_RecoTotemT1T2_T2MakeCluster_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2MakeClusterPlugins,src/RecoTotemT1T2/T2MakeCluster/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_plugins
src_RecoTotemT1T2_T2MakeCluster_plugins_parent := RecoTotemT1T2/T2MakeCluster
src_RecoTotemT1T2_T2MakeCluster_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_plugins,src/RecoTotemT1T2/T2MakeCluster/plugins,PLUGINS))
