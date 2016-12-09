ifeq ($(strip $(TotemRPValidationBeamSmearingPlugins)),)
TotemRPValidationBeamSmearingPlugins_files := $(patsubst src/TotemRPValidation/BeamSmearing/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/BeamSmearing/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/BeamSmearing/plugins/$(file). Please fix src/TotemRPValidation/BeamSmearing/plugins/BuildFile.))))
TotemRPValidationBeamSmearingPlugins := self/src/TotemRPValidation/BeamSmearing/plugins
TotemRPValidationBeamSmearingPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BeamSmearing/plugins/BuildFile
TotemRPValidationBeamSmearingPlugins_LOC_USE := self  TotemRPValidation/BeamSmearing FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationBeamSmearingPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationBeamSmearingPlugins,TotemRPValidationBeamSmearingPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/BeamSmearing/plugins))
TotemRPValidationBeamSmearingPlugins_PACKAGE := self/src/TotemRPValidation/BeamSmearing/plugins
ALL_PRODS += TotemRPValidationBeamSmearingPlugins
TotemRPValidationBeamSmearingPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBeamSmearingPlugins,src/TotemRPValidation/BeamSmearing/plugins,src_TotemRPValidation_BeamSmearing_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationBeamSmearingPlugins,src/TotemRPValidation/BeamSmearing/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_plugins
src_TotemRPValidation_BeamSmearing_plugins_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_plugins,src/TotemRPValidation/BeamSmearing/plugins,PLUGINS))
