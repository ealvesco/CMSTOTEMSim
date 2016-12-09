ifeq ($(strip $(TotemRawDataRawToDigiPlugins)),)
TotemRawDataRawToDigiPlugins_files := $(patsubst src/TotemRawData/RawToDigi/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/RawToDigi/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/RawToDigi/plugins/$(file). Please fix src/TotemRawData/RawToDigi/plugins/BuildFile.))))
TotemRawDataRawToDigiPlugins := self/src/TotemRawData/RawToDigi/plugins
TotemRawDataRawToDigiPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/RawToDigi/plugins/BuildFile
TotemRawDataRawToDigiPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataRawToDigiPlugins_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats DataFormats/TotemRPDataTypes DataFormats/T2Digi DataFormats/T2DetId DataFormats/TotemL1Trigger DataFormats/Common DataFormats/DetId DataFormats/T1DigiVfat DataFormats/T1DetId DataFormats/T1DigiWire TotemCondFormats/DataRecord TotemCondFormats/DAQInformation
TotemRawDataRawToDigiPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataRawToDigiPlugins,TotemRawDataRawToDigiPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/RawToDigi/plugins))
TotemRawDataRawToDigiPlugins_PACKAGE := self/src/TotemRawData/RawToDigi/plugins
ALL_PRODS += TotemRawDataRawToDigiPlugins
TotemRawDataRawToDigiPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataRawToDigiPlugins,src/TotemRawData/RawToDigi/plugins,src_TotemRawData_RawToDigi_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataRawToDigiPlugins,src/TotemRawData/RawToDigi/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_RawToDigi_plugins
src_TotemRawData_RawToDigi_plugins_parent := TotemRawData/RawToDigi
src_TotemRawData_RawToDigi_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_plugins,src/TotemRawData/RawToDigi/plugins,PLUGINS))
