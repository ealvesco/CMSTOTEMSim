ifeq ($(strip $(TotemRPValidationValidationPlotsPlugins)),)
TotemRPValidationValidationPlotsPlugins_files := $(patsubst src/TotemRPValidation/ValidationPlots/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ValidationPlots/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ValidationPlots/plugins/$(file). Please fix src/TotemRPValidation/ValidationPlots/plugins/BuildFile.))))
TotemRPValidationValidationPlotsPlugins := self/src/TotemRPValidation/ValidationPlots/plugins
TotemRPValidationValidationPlotsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationPlots/plugins/BuildFile
TotemRPValidationValidationPlotsPlugins_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost TotemRPValidation/ValidationTools TotemRPValidation/ValidationPlots TotemRPValidation/ElasticReconstruction TotemRPValidation/BaseValidationClasses
TotemRPValidationValidationPlotsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationValidationPlotsPlugins,TotemRPValidationValidationPlotsPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/ValidationPlots/plugins))
TotemRPValidationValidationPlotsPlugins_PACKAGE := self/src/TotemRPValidation/ValidationPlots/plugins
ALL_PRODS += TotemRPValidationValidationPlotsPlugins
TotemRPValidationValidationPlotsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationPlotsPlugins,src/TotemRPValidation/ValidationPlots/plugins,src_TotemRPValidation_ValidationPlots_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationValidationPlotsPlugins,src/TotemRPValidation/ValidationPlots/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_plugins
src_TotemRPValidation_ValidationPlots_plugins_parent := TotemRPValidation/ValidationPlots
src_TotemRPValidation_ValidationPlots_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_plugins,src/TotemRPValidation/ValidationPlots/plugins,PLUGINS))
