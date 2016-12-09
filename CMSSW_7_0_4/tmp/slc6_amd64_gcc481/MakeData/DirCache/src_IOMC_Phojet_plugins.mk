ifeq ($(strip $(IOMCPhojetPlugins)),)
IOMCPhojetPlugins_files := $(patsubst src/IOMC/Phojet/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/Phojet/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Phojet/plugins/$(file). Please fix src/IOMC/Phojet/plugins/BuildFile.))))
IOMCPhojetPlugins := self/src/IOMC/Phojet/plugins
IOMCPhojetPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Phojet/plugins/BuildFile
IOMCPhojetPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCPhojetPlugins_LOC_USE := self  IOMC/Phojet boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCPhojetPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCPhojetPlugins,IOMCPhojetPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/Phojet/plugins))
IOMCPhojetPlugins_PACKAGE := self/src/IOMC/Phojet/plugins
ALL_PRODS += IOMCPhojetPlugins
IOMCPhojetPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCPhojetPlugins,src/IOMC/Phojet/plugins,src_IOMC_Phojet_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCPhojetPlugins,src/IOMC/Phojet/plugins))
endif
ALL_COMMONRULES += src_IOMC_Phojet_plugins
src_IOMC_Phojet_plugins_parent := IOMC/Phojet
src_IOMC_Phojet_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_plugins,src/IOMC/Phojet/plugins,PLUGINS))
