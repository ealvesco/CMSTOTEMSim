ifeq ($(strip $(TotemRPValidationElasticReconstructionPlugins)),)
TotemRPValidationElasticReconstructionPlugins_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ElasticReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ElasticReconstruction/plugins/$(file). Please fix src/TotemRPValidation/ElasticReconstruction/plugins/BuildFile.))))
TotemRPValidationElasticReconstructionPlugins := self/src/TotemRPValidation/ElasticReconstruction/plugins
TotemRPValidationElasticReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ElasticReconstruction/plugins/BuildFile
TotemRPValidationElasticReconstructionPlugins_LOC_USE := self  TotemRPValidation/ElasticReconstruction FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats TotemRPValidation/BaseValidationClasses root SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord
TotemRPValidationElasticReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationElasticReconstructionPlugins,TotemRPValidationElasticReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/ElasticReconstruction/plugins))
TotemRPValidationElasticReconstructionPlugins_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/plugins
ALL_PRODS += TotemRPValidationElasticReconstructionPlugins
TotemRPValidationElasticReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationElasticReconstructionPlugins,src/TotemRPValidation/ElasticReconstruction/plugins,src_TotemRPValidation_ElasticReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationElasticReconstructionPlugins,src/TotemRPValidation/ElasticReconstruction/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_plugins
src_TotemRPValidation_ElasticReconstruction_plugins_parent := TotemRPValidation/ElasticReconstruction
src_TotemRPValidation_ElasticReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_plugins,src/TotemRPValidation/ElasticReconstruction/plugins,PLUGINS))
