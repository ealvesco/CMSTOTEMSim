ifeq ($(strip $(TotemRPValidationTransportValidationPlugins)),)
TotemRPValidationTransportValidationPlugins_files := $(patsubst src/TotemRPValidation/TransportValidation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/TransportValidation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/TransportValidation/plugins/$(file). Please fix src/TotemRPValidation/TransportValidation/plugins/BuildFile.))))
TotemRPValidationTransportValidationPlugins := self/src/TotemRPValidation/TransportValidation/plugins
TotemRPValidationTransportValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/TransportValidation/plugins/BuildFile
TotemRPValidationTransportValidationPlugins_LOC_USE := self  TotemRPValidation/TransportValidation FWCore/Framework TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord
TotemRPValidationTransportValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationTransportValidationPlugins,TotemRPValidationTransportValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/TransportValidation/plugins))
TotemRPValidationTransportValidationPlugins_PACKAGE := self/src/TotemRPValidation/TransportValidation/plugins
ALL_PRODS += TotemRPValidationTransportValidationPlugins
TotemRPValidationTransportValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationTransportValidationPlugins,src/TotemRPValidation/TransportValidation/plugins,src_TotemRPValidation_TransportValidation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationTransportValidationPlugins,src/TotemRPValidation/TransportValidation/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_plugins
src_TotemRPValidation_TransportValidation_plugins_parent := TotemRPValidation/TransportValidation
src_TotemRPValidation_TransportValidation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_plugins,src/TotemRPValidation/TransportValidation/plugins,PLUGINS))
