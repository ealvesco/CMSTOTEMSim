ifeq ($(strip $(IOMCFlatThetaXYGunPlugins)),)
IOMCFlatThetaXYGunPlugins_files := $(patsubst src/IOMC/FlatThetaXYGun/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatThetaXYGun/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatThetaXYGun/plugins/$(file). Please fix src/IOMC/FlatThetaXYGun/plugins/BuildFile.))))
IOMCFlatThetaXYGunPlugins := self/src/IOMC/FlatThetaXYGun/plugins
IOMCFlatThetaXYGunPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatThetaXYGun/plugins/BuildFile
IOMCFlatThetaXYGunPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatThetaXYGunPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatThetaXYGunPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatThetaXYGunPlugins,IOMCFlatThetaXYGunPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatThetaXYGun/plugins))
IOMCFlatThetaXYGunPlugins_PACKAGE := self/src/IOMC/FlatThetaXYGun/plugins
ALL_PRODS += IOMCFlatThetaXYGunPlugins
IOMCFlatThetaXYGunPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatThetaXYGunPlugins,src/IOMC/FlatThetaXYGun/plugins,src_IOMC_FlatThetaXYGun_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatThetaXYGunPlugins,src/IOMC/FlatThetaXYGun/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_plugins
src_IOMC_FlatThetaXYGun_plugins_parent := IOMC/FlatThetaXYGun
src_IOMC_FlatThetaXYGun_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_plugins,src/IOMC/FlatThetaXYGun/plugins,PLUGINS))
