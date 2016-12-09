ifeq ($(strip $(L1TriggerTotemCoincidenceChipPlugins)),)
L1TriggerTotemCoincidenceChipPlugins_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/L1TriggerTotem/CoincidenceChip/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/L1TriggerTotem/CoincidenceChip/plugins/$(file). Please fix src/L1TriggerTotem/CoincidenceChip/plugins/BuildFile.))))
L1TriggerTotemCoincidenceChipPlugins := self/src/L1TriggerTotem/CoincidenceChip/plugins
L1TriggerTotemCoincidenceChipPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/L1TriggerTotem/CoincidenceChip/plugins/BuildFile
L1TriggerTotemCoincidenceChipPlugins_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet L1TriggerTotem/CoincidenceChip DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId DataFormats/TotemL1Trigger DataFormats/T2Digi DataFormats/T2DetId hepmc SimDataFormats/GeneratorProducts rootgraphics TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
L1TriggerTotemCoincidenceChipPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,L1TriggerTotemCoincidenceChipPlugins,L1TriggerTotemCoincidenceChipPlugins,$(SCRAMSTORENAME_LIB),src/L1TriggerTotem/CoincidenceChip/plugins))
L1TriggerTotemCoincidenceChipPlugins_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/plugins
ALL_PRODS += L1TriggerTotemCoincidenceChipPlugins
L1TriggerTotemCoincidenceChipPlugins_INIT_FUNC        += $$(eval $$(call Library,L1TriggerTotemCoincidenceChipPlugins,src/L1TriggerTotem/CoincidenceChip/plugins,src_L1TriggerTotem_CoincidenceChip_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,L1TriggerTotemCoincidenceChipPlugins,src/L1TriggerTotem/CoincidenceChip/plugins))
endif
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_plugins
src_L1TriggerTotem_CoincidenceChip_plugins_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_plugins,src/L1TriggerTotem/CoincidenceChip/plugins,PLUGINS))
