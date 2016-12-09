ifeq ($(strip $(TotemRPValidationHitDistributionsPlugins)),)
TotemRPValidationHitDistributionsPlugins_files := $(patsubst src/TotemRPValidation/HitDistributions/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/HitDistributions/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/HitDistributions/plugins/$(file). Please fix src/TotemRPValidation/HitDistributions/plugins/BuildFile.))))
TotemRPValidationHitDistributionsPlugins := self/src/TotemRPValidation/HitDistributions/plugins
TotemRPValidationHitDistributionsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/HitDistributions/plugins/BuildFile
TotemRPValidationHitDistributionsPlugins_LOC_USE := self  TotemRPValidation/HitDistributions FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost DataFormats/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords
TotemRPValidationHitDistributionsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationHitDistributionsPlugins,TotemRPValidationHitDistributionsPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/HitDistributions/plugins))
TotemRPValidationHitDistributionsPlugins_PACKAGE := self/src/TotemRPValidation/HitDistributions/plugins
ALL_PRODS += TotemRPValidationHitDistributionsPlugins
TotemRPValidationHitDistributionsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationHitDistributionsPlugins,src/TotemRPValidation/HitDistributions/plugins,src_TotemRPValidation_HitDistributions_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationHitDistributionsPlugins,src/TotemRPValidation/HitDistributions/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_plugins
src_TotemRPValidation_HitDistributions_plugins_parent := TotemRPValidation/HitDistributions
src_TotemRPValidation_HitDistributions_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_plugins,src/TotemRPValidation/HitDistributions/plugins,PLUGINS))
