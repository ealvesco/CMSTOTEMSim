ifeq ($(strip $(IOMCFlatProtonLogKsiLogTGunPlugins)),)
IOMCFlatProtonLogKsiLogTGunPlugins_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGun/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatProtonLogKsiLogTGun/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatProtonLogKsiLogTGun/plugins/$(file). Please fix src/IOMC/FlatProtonLogKsiLogTGun/plugins/BuildFile.))))
IOMCFlatProtonLogKsiLogTGunPlugins := self/src/IOMC/FlatProtonLogKsiLogTGun/plugins
IOMCFlatProtonLogKsiLogTGunPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatProtonLogKsiLogTGun/plugins/BuildFile
IOMCFlatProtonLogKsiLogTGunPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatProtonLogKsiLogTGunPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatProtonLogKsiLogTGunPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatProtonLogKsiLogTGunPlugins,IOMCFlatProtonLogKsiLogTGunPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatProtonLogKsiLogTGun/plugins))
IOMCFlatProtonLogKsiLogTGunPlugins_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGun/plugins
ALL_PRODS += IOMCFlatProtonLogKsiLogTGunPlugins
IOMCFlatProtonLogKsiLogTGunPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatProtonLogKsiLogTGunPlugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins,src_IOMC_FlatProtonLogKsiLogTGun_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatProtonLogKsiLogTGunPlugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_plugins
src_IOMC_FlatProtonLogKsiLogTGun_plugins_parent := IOMC/FlatProtonLogKsiLogTGun
src_IOMC_FlatProtonLogKsiLogTGun_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_plugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins,PLUGINS))
