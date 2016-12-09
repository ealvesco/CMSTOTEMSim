ifeq ($(strip $(IOMCElegentPlugins)),)
IOMCElegentPlugins_files := $(patsubst src/IOMC/Elegent/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/plugins/$(file). Please fix src/IOMC/Elegent/plugins/BuildFile.))))
IOMCElegentPlugins := self/src/IOMC/Elegent/plugins
IOMCElegentPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/plugins/BuildFile
IOMCElegentPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3
IOMCElegentPlugins_LOC_USE := self  FWCore/Framework SimDataFormats/GeneratorProducts IOMC/Elegent hepmc root
IOMCElegentPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCElegentPlugins,IOMCElegentPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/Elegent/plugins))
IOMCElegentPlugins_PACKAGE := self/src/IOMC/Elegent/plugins
ALL_PRODS += IOMCElegentPlugins
IOMCElegentPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCElegentPlugins,src/IOMC/Elegent/plugins,src_IOMC_Elegent_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCElegentPlugins,src/IOMC/Elegent/plugins))
endif
ALL_COMMONRULES += src_IOMC_Elegent_plugins
src_IOMC_Elegent_plugins_parent := IOMC/Elegent
src_IOMC_Elegent_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_plugins,src/IOMC/Elegent/plugins,PLUGINS))
