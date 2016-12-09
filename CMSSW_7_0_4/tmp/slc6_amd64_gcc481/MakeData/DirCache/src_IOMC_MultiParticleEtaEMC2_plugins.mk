ifeq ($(strip $(IOMCMultiParticleEtaEMC2Plugins)),)
IOMCMultiParticleEtaEMC2Plugins_files := $(patsubst src/IOMC/MultiParticleEtaEMC2/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/MultiParticleEtaEMC2/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/MultiParticleEtaEMC2/plugins/$(file). Please fix src/IOMC/MultiParticleEtaEMC2/plugins/BuildFile.))))
IOMCMultiParticleEtaEMC2Plugins := self/src/IOMC/MultiParticleEtaEMC2/plugins
IOMCMultiParticleEtaEMC2Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/MultiParticleEtaEMC2/plugins/BuildFile
IOMCMultiParticleEtaEMC2Plugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCMultiParticleEtaEMC2Plugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord clhep hepmc heppdt
IOMCMultiParticleEtaEMC2Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCMultiParticleEtaEMC2Plugins,IOMCMultiParticleEtaEMC2Plugins,$(SCRAMSTORENAME_LIB),src/IOMC/MultiParticleEtaEMC2/plugins))
IOMCMultiParticleEtaEMC2Plugins_PACKAGE := self/src/IOMC/MultiParticleEtaEMC2/plugins
ALL_PRODS += IOMCMultiParticleEtaEMC2Plugins
IOMCMultiParticleEtaEMC2Plugins_INIT_FUNC        += $$(eval $$(call Library,IOMCMultiParticleEtaEMC2Plugins,src/IOMC/MultiParticleEtaEMC2/plugins,src_IOMC_MultiParticleEtaEMC2_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCMultiParticleEtaEMC2Plugins,src/IOMC/MultiParticleEtaEMC2/plugins))
endif
ALL_COMMONRULES += src_IOMC_MultiParticleEtaEMC2_plugins
src_IOMC_MultiParticleEtaEMC2_plugins_parent := IOMC/MultiParticleEtaEMC2
src_IOMC_MultiParticleEtaEMC2_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleEtaEMC2_plugins,src/IOMC/MultiParticleEtaEMC2/plugins,PLUGINS))
