ifeq ($(strip $(TotemRawDataReadersPlugins)),)
TotemRawDataReadersPlugins_files := $(patsubst src/TotemRawData/Readers/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/Readers/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/Readers/plugins/$(file). Please fix src/TotemRawData/Readers/plugins/BuildFile.))))
TotemRawDataReadersPlugins := self/src/TotemRawData/Readers/plugins
TotemRawDataReadersPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/Readers/plugins/BuildFile
TotemRawDataReadersPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataReadersPlugins_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/Readers TotemRawData/DataFormats
TotemRawDataReadersPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataReadersPlugins,TotemRawDataReadersPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/Readers/plugins))
TotemRawDataReadersPlugins_PACKAGE := self/src/TotemRawData/Readers/plugins
ALL_PRODS += TotemRawDataReadersPlugins
TotemRawDataReadersPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataReadersPlugins,src/TotemRawData/Readers/plugins,src_TotemRawData_Readers_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataReadersPlugins,src/TotemRawData/Readers/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_Readers_plugins
src_TotemRawData_Readers_plugins_parent := TotemRawData/Readers
src_TotemRawData_Readers_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_plugins,src/TotemRawData/Readers/plugins,PLUGINS))
