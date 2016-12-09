ifeq ($(strip $(TotemCondFormatsProtonTransportFunctionsPlugins)),)
TotemCondFormatsProtonTransportFunctionsPlugins_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemCondFormats/ProtonTransportFunctions/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemCondFormats/ProtonTransportFunctions/plugins/$(file). Please fix src/TotemCondFormats/ProtonTransportFunctions/plugins/BuildFile.))))
TotemCondFormatsProtonTransportFunctionsPlugins := self/src/TotemCondFormats/ProtonTransportFunctions/plugins
TotemCondFormatsProtonTransportFunctionsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/ProtonTransportFunctions/plugins/BuildFile
TotemCondFormatsProtonTransportFunctionsPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet root TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects SimG4CMS/TotemRPProtTranspPar clhep Geometry/TotemRecords Geometry/TotemRPGeometryBuilder TotemCondFormats/ProtonTransportFunctions
TotemCondFormatsProtonTransportFunctionsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemCondFormatsProtonTransportFunctionsPlugins,TotemCondFormatsProtonTransportFunctionsPlugins,$(SCRAMSTORENAME_LIB),src/TotemCondFormats/ProtonTransportFunctions/plugins))
TotemCondFormatsProtonTransportFunctionsPlugins_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/plugins
ALL_PRODS += TotemCondFormatsProtonTransportFunctionsPlugins
TotemCondFormatsProtonTransportFunctionsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsProtonTransportFunctionsPlugins,src/TotemCondFormats/ProtonTransportFunctions/plugins,src_TotemCondFormats_ProtonTransportFunctions_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCondFormatsProtonTransportFunctionsPlugins,src/TotemCondFormats/ProtonTransportFunctions/plugins))
endif
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_plugins
src_TotemCondFormats_ProtonTransportFunctions_plugins_parent := TotemCondFormats/ProtonTransportFunctions
src_TotemCondFormats_ProtonTransportFunctions_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_plugins,src/TotemCondFormats/ProtonTransportFunctions/plugins,PLUGINS))
