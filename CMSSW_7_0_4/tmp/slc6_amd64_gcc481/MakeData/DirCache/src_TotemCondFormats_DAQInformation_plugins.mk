ifeq ($(strip $(TotemCondFormatsDAQInformationPlugins)),)
TotemCondFormatsDAQInformationPlugins_files := $(patsubst src/TotemCondFormats/DAQInformation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemCondFormats/DAQInformation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemCondFormats/DAQInformation/plugins/$(file). Please fix src/TotemCondFormats/DAQInformation/plugins/BuildFile.))))
TotemCondFormatsDAQInformationPlugins := self/src/TotemCondFormats/DAQInformation/plugins
TotemCondFormatsDAQInformationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DAQInformation/plugins/BuildFile
TotemCondFormatsDAQInformationPlugins_LOC_USE := self  FWCore/Framework TotemCondFormats/DataRecord TotemCondFormats/DAQInformation xerces-c
TotemCondFormatsDAQInformationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemCondFormatsDAQInformationPlugins,TotemCondFormatsDAQInformationPlugins,$(SCRAMSTORENAME_LIB),src/TotemCondFormats/DAQInformation/plugins))
TotemCondFormatsDAQInformationPlugins_PACKAGE := self/src/TotemCondFormats/DAQInformation/plugins
ALL_PRODS += TotemCondFormatsDAQInformationPlugins
TotemCondFormatsDAQInformationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDAQInformationPlugins,src/TotemCondFormats/DAQInformation/plugins,src_TotemCondFormats_DAQInformation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCondFormatsDAQInformationPlugins,src/TotemCondFormats/DAQInformation/plugins))
endif
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_plugins
src_TotemCondFormats_DAQInformation_plugins_parent := TotemCondFormats/DAQInformation
src_TotemCondFormats_DAQInformation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_plugins,src/TotemCondFormats/DAQInformation/plugins,PLUGINS))
