ifeq ($(strip $(RecoTotemT1T2T1MakeClusterPlugins)),)
RecoTotemT1T2T1MakeClusterPlugins_files := $(patsubst src/RecoTotemT1T2/T1MakeCluster/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1MakeCluster/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1MakeCluster/plugins/$(file). Please fix src/RecoTotemT1T2/T1MakeCluster/plugins/BuildFile.))))
RecoTotemT1T2T1MakeClusterPlugins := self/src/RecoTotemT1T2/T1MakeCluster/plugins
RecoTotemT1T2T1MakeClusterPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1MakeCluster/plugins/BuildFile
RecoTotemT1T2T1MakeClusterPlugins_LOC_USE := self  DataFormats/Common FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger Geometry/TotemRecords DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1Cluster Geometry/TotemGeometry TotemRawDataLibrary/DataFormats SimTotem/T1Digitizer boost root
RecoTotemT1T2T1MakeClusterPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1MakeClusterPlugins,RecoTotemT1T2T1MakeClusterPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1MakeCluster/plugins))
RecoTotemT1T2T1MakeClusterPlugins_PACKAGE := self/src/RecoTotemT1T2/T1MakeCluster/plugins
ALL_PRODS += RecoTotemT1T2T1MakeClusterPlugins
RecoTotemT1T2T1MakeClusterPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1MakeClusterPlugins,src/RecoTotemT1T2/T1MakeCluster/plugins,src_RecoTotemT1T2_T1MakeCluster_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1MakeClusterPlugins,src/RecoTotemT1T2/T1MakeCluster/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1MakeCluster_plugins
src_RecoTotemT1T2_T1MakeCluster_plugins_parent := RecoTotemT1T2/T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1MakeCluster_plugins,src/RecoTotemT1T2/T1MakeCluster/plugins,PLUGINS))
