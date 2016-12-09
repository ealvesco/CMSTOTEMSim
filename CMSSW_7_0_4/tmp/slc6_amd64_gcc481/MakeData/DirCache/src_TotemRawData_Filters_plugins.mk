ifeq ($(strip $(TotemRawDataLibraryFiltresPlugins)),)
TotemRawDataLibraryFiltresPlugins_files := $(patsubst src/TotemRawData/Filters/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/Filters/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/Filters/plugins/$(file). Please fix src/TotemRawData/Filters/plugins/BuildFile.))))
TotemRawDataLibraryFiltresPlugins := self/src/TotemRawData/Filters/plugins
TotemRawDataLibraryFiltresPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/Filters/plugins/BuildFile
TotemRawDataLibraryFiltresPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet TotemRawDataLibrary/DataFormats
TotemRawDataLibraryFiltresPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataLibraryFiltresPlugins,TotemRawDataLibraryFiltresPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/Filters/plugins))
TotemRawDataLibraryFiltresPlugins_PACKAGE := self/src/TotemRawData/Filters/plugins
ALL_PRODS += TotemRawDataLibraryFiltresPlugins
TotemRawDataLibraryFiltresPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryFiltresPlugins,src/TotemRawData/Filters/plugins,src_TotemRawData_Filters_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataLibraryFiltresPlugins,src/TotemRawData/Filters/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_Filters_plugins
src_TotemRawData_Filters_plugins_parent := TotemRawData/Filters
src_TotemRawData_Filters_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Filters_plugins,src/TotemRawData/Filters/plugins,PLUGINS))
