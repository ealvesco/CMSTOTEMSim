ifeq ($(strip $(RecoTotemRPRPClusterSigmaServicePlugins)),)
RecoTotemRPRPClusterSigmaServicePlugins_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPClusterSigmaService/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPClusterSigmaService/plugins/$(file). Please fix src/RecoTotemRP/RPClusterSigmaService/plugins/BuildFile.))))
RecoTotemRPRPClusterSigmaServicePlugins := self/src/RecoTotemRP/RPClusterSigmaService/plugins
RecoTotemRPRPClusterSigmaServicePlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterSigmaService/plugins/BuildFile
RecoTotemRPRPClusterSigmaServicePlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core RecoTotemRP/RPClusterSigmaService
RecoTotemRPRPClusterSigmaServicePlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPClusterSigmaServicePlugins,RecoTotemRPRPClusterSigmaServicePlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPClusterSigmaService/plugins))
RecoTotemRPRPClusterSigmaServicePlugins_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/plugins
ALL_PRODS += RecoTotemRPRPClusterSigmaServicePlugins
RecoTotemRPRPClusterSigmaServicePlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterSigmaServicePlugins,src/RecoTotemRP/RPClusterSigmaService/plugins,src_RecoTotemRP_RPClusterSigmaService_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPClusterSigmaServicePlugins,src/RecoTotemRP/RPClusterSigmaService/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_plugins
src_RecoTotemRP_RPClusterSigmaService_plugins_parent := RecoTotemRP/RPClusterSigmaService
src_RecoTotemRP_RPClusterSigmaService_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_plugins,src/RecoTotemRP/RPClusterSigmaService/plugins,PLUGINS))
