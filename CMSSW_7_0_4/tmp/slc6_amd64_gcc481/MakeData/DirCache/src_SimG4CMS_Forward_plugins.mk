ifeq ($(strip $(SimG4CMSForwardPlugins)),)
SimG4CMSForwardPlugins_files := $(patsubst src/SimG4CMS/Forward/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4CMS/Forward/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/Forward/plugins/$(file). Please fix src/SimG4CMS/Forward/plugins/BuildFile.))))
SimG4CMSForwardPlugins := self/src/SimG4CMS/Forward/plugins
SimG4CMSForwardPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/Forward/plugins/BuildFile
SimG4CMSForwardPlugins_LOC_USE := self  FWCore/PluginManager SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4CMS/Forward SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo DataFormats/Math SimDataFormats/SimHitMaker SimDataFormats/CaloHit SimDataFormats/Forward DetectorDescription/Core FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger boost geant4core root rootmath
SimG4CMSForwardPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CMSForwardPlugins,SimG4CMSForwardPlugins,$(SCRAMSTORENAME_LIB),src/SimG4CMS/Forward/plugins))
SimG4CMSForwardPlugins_PACKAGE := self/src/SimG4CMS/Forward/plugins
ALL_PRODS += SimG4CMSForwardPlugins
SimG4CMSForwardPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSForwardPlugins,src/SimG4CMS/Forward/plugins,src_SimG4CMS_Forward_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CMSForwardPlugins,src/SimG4CMS/Forward/plugins))
endif
ALL_COMMONRULES += src_SimG4CMS_Forward_plugins
src_SimG4CMS_Forward_plugins_parent := SimG4CMS/Forward
src_SimG4CMS_Forward_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_plugins,src/SimG4CMS/Forward/plugins,PLUGINS))
