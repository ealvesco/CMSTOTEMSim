ifeq ($(strip $(IOMCMultiParticleGunsPlugins)),)
IOMCMultiParticleGunsPlugins_files := $(patsubst src/IOMC/MultiParticleGuns/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/MultiParticleGuns/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/MultiParticleGuns/plugins/$(file). Please fix src/IOMC/MultiParticleGuns/plugins/BuildFile.))))
IOMCMultiParticleGunsPlugins := self/src/IOMC/MultiParticleGuns/plugins
IOMCMultiParticleGunsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/MultiParticleGuns/plugins/BuildFile
IOMCMultiParticleGunsPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCMultiParticleGunsPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord clhep hepmc heppdt
IOMCMultiParticleGunsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCMultiParticleGunsPlugins,IOMCMultiParticleGunsPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/MultiParticleGuns/plugins))
IOMCMultiParticleGunsPlugins_PACKAGE := self/src/IOMC/MultiParticleGuns/plugins
ALL_PRODS += IOMCMultiParticleGunsPlugins
IOMCMultiParticleGunsPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCMultiParticleGunsPlugins,src/IOMC/MultiParticleGuns/plugins,src_IOMC_MultiParticleGuns_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCMultiParticleGunsPlugins,src/IOMC/MultiParticleGuns/plugins))
endif
ALL_COMMONRULES += src_IOMC_MultiParticleGuns_plugins
src_IOMC_MultiParticleGuns_plugins_parent := IOMC/MultiParticleGuns
src_IOMC_MultiParticleGuns_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleGuns_plugins,src/IOMC/MultiParticleGuns/plugins,PLUGINS))
