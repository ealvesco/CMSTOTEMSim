ifeq ($(strip $(IOMCDPEProtonsPlugins)),)
IOMCDPEProtonsPlugins_files := $(patsubst src/IOMC/DPEProtons/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/DPEProtons/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/DPEProtons/plugins/$(file). Please fix src/IOMC/DPEProtons/plugins/BuildFile.))))
IOMCDPEProtonsPlugins := self/src/IOMC/DPEProtons/plugins
IOMCDPEProtonsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/DPEProtons/plugins/BuildFile
IOMCDPEProtonsPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCDPEProtonsPlugins_LOC_USE := self  IOMC/DPEProtons boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCDPEProtonsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCDPEProtonsPlugins,IOMCDPEProtonsPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/DPEProtons/plugins))
IOMCDPEProtonsPlugins_PACKAGE := self/src/IOMC/DPEProtons/plugins
ALL_PRODS += IOMCDPEProtonsPlugins
IOMCDPEProtonsPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCDPEProtonsPlugins,src/IOMC/DPEProtons/plugins,src_IOMC_DPEProtons_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCDPEProtonsPlugins,src/IOMC/DPEProtons/plugins))
endif
ALL_COMMONRULES += src_IOMC_DPEProtons_plugins
src_IOMC_DPEProtons_plugins_parent := IOMC/DPEProtons
src_IOMC_DPEProtons_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_plugins,src/IOMC/DPEProtons/plugins,PLUGINS))
