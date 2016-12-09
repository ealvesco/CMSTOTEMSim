ifeq ($(strip $(IOMCSmearingGeneratorPlugins)),)
IOMCSmearingGeneratorPlugins_files := $(patsubst src/IOMC/SmearingGenerator/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/SmearingGenerator/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/SmearingGenerator/plugins/$(file). Please fix src/IOMC/SmearingGenerator/plugins/BuildFile.))))
IOMCSmearingGeneratorPlugins := self/src/IOMC/SmearingGenerator/plugins
IOMCSmearingGeneratorPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/SmearingGenerator/plugins/BuildFile
IOMCSmearingGeneratorPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCSmearingGeneratorPlugins_LOC_USE := self  FWCore/Framework SimDataFormats/GeneratorProducts hepmc root TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord clhep
IOMCSmearingGeneratorPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCSmearingGeneratorPlugins,IOMCSmearingGeneratorPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/SmearingGenerator/plugins))
IOMCSmearingGeneratorPlugins_PACKAGE := self/src/IOMC/SmearingGenerator/plugins
ALL_PRODS += IOMCSmearingGeneratorPlugins
IOMCSmearingGeneratorPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCSmearingGeneratorPlugins,src/IOMC/SmearingGenerator/plugins,src_IOMC_SmearingGenerator_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCSmearingGeneratorPlugins,src/IOMC/SmearingGenerator/plugins))
endif
ALL_COMMONRULES += src_IOMC_SmearingGenerator_plugins
src_IOMC_SmearingGenerator_plugins_parent := IOMC/SmearingGenerator
src_IOMC_SmearingGenerator_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_plugins,src/IOMC/SmearingGenerator/plugins,PLUGINS))
