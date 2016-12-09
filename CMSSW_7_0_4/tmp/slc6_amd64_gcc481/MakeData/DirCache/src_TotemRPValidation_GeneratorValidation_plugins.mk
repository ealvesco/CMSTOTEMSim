ifeq ($(strip $(TotemRPValidationGeneratorValidationPlugins)),)
TotemRPValidationGeneratorValidationPlugins_files := $(patsubst src/TotemRPValidation/GeneratorValidation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/GeneratorValidation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/GeneratorValidation/plugins/$(file). Please fix src/TotemRPValidation/GeneratorValidation/plugins/BuildFile.))))
TotemRPValidationGeneratorValidationPlugins := self/src/TotemRPValidation/GeneratorValidation/plugins
TotemRPValidationGeneratorValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/GeneratorValidation/plugins/BuildFile
TotemRPValidationGeneratorValidationPlugins_LOC_USE := self  FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationGeneratorValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationGeneratorValidationPlugins,TotemRPValidationGeneratorValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/GeneratorValidation/plugins))
TotemRPValidationGeneratorValidationPlugins_PACKAGE := self/src/TotemRPValidation/GeneratorValidation/plugins
ALL_PRODS += TotemRPValidationGeneratorValidationPlugins
TotemRPValidationGeneratorValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationGeneratorValidationPlugins,src/TotemRPValidation/GeneratorValidation/plugins,src_TotemRPValidation_GeneratorValidation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationGeneratorValidationPlugins,src/TotemRPValidation/GeneratorValidation/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_GeneratorValidation_plugins
src_TotemRPValidation_GeneratorValidation_plugins_parent := TotemRPValidation/GeneratorValidation
src_TotemRPValidation_GeneratorValidation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_GeneratorValidation_plugins,src/TotemRPValidation/GeneratorValidation/plugins,PLUGINS))
