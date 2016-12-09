ifeq ($(strip $(IOMCFlatProtonLogKsiLogTGunMulPlugins)),)
IOMCFlatProtonLogKsiLogTGunMulPlugins_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/$(file). Please fix src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/BuildFile.))))
IOMCFlatProtonLogKsiLogTGunMulPlugins := self/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins
IOMCFlatProtonLogKsiLogTGunMulPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/BuildFile
IOMCFlatProtonLogKsiLogTGunMulPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatProtonLogKsiLogTGunMulPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatProtonLogKsiLogTGunMulPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatProtonLogKsiLogTGunMulPlugins,IOMCFlatProtonLogKsiLogTGunMulPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatProtonLogKsiLogTGunMul/plugins))
IOMCFlatProtonLogKsiLogTGunMulPlugins_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins
ALL_PRODS += IOMCFlatProtonLogKsiLogTGunMulPlugins
IOMCFlatProtonLogKsiLogTGunMulPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatProtonLogKsiLogTGunMulPlugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins,src_IOMC_FlatProtonLogKsiLogTGunMul_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatProtonLogKsiLogTGunMulPlugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGunMul_plugins
src_IOMC_FlatProtonLogKsiLogTGunMul_plugins_parent := IOMC/FlatProtonLogKsiLogTGunMul
src_IOMC_FlatProtonLogKsiLogTGunMul_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGunMul_plugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins,PLUGINS))
