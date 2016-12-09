ifeq ($(strip $(SimG4CMSTotemRPPlugins)),)
SimG4CMSTotemRPPlugins_files := $(patsubst src/SimG4CMS/TotemRP/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRP/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRP/plugins/$(file). Please fix src/SimG4CMS/TotemRP/plugins/BuildFile.))))
SimG4CMSTotemRPPlugins := self/src/SimG4CMS/TotemRP/plugins
SimG4CMSTotemRPPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRP/plugins/BuildFile
SimG4CMSTotemRPPlugins_LOC_USE := self  SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo SimDataFormats/SimHitMaker SimDataFormats/CaloHit DetectorDescription/Core FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/TotemRPDetId boost geant4 root rootrflx SimG4CMS/TotemRP
SimG4CMSTotemRPPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CMSTotemRPPlugins,SimG4CMSTotemRPPlugins,$(SCRAMSTORENAME_LIB),src/SimG4CMS/TotemRP/plugins))
SimG4CMSTotemRPPlugins_PACKAGE := self/src/SimG4CMS/TotemRP/plugins
ALL_PRODS += SimG4CMSTotemRPPlugins
SimG4CMSTotemRPPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSTotemRPPlugins,src/SimG4CMS/TotemRP/plugins,src_SimG4CMS_TotemRP_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CMSTotemRPPlugins,src/SimG4CMS/TotemRP/plugins))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRP_plugins
src_SimG4CMS_TotemRP_plugins_parent := SimG4CMS/TotemRP
src_SimG4CMS_TotemRP_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_plugins,src/SimG4CMS/TotemRP/plugins,PLUGINS))
