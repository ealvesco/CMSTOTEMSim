ifeq ($(strip $(RecoTotemRPRPElasticReconstructionPlugins)),)
RecoTotemRPRPElasticReconstructionPlugins_files := $(patsubst src/RecoTotemRP/RPElasticReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPElasticReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPElasticReconstruction/plugins/$(file). Please fix src/RecoTotemRP/RPElasticReconstruction/plugins/BuildFile.))))
RecoTotemRPRPElasticReconstructionPlugins := self/src/RecoTotemRP/RPElasticReconstruction/plugins
RecoTotemRPRPElasticReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPElasticReconstruction/plugins/BuildFile
RecoTotemRPRPElasticReconstructionPlugins_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord TotemRawDataLibrary/DataFormats
RecoTotemRPRPElasticReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPElasticReconstructionPlugins,RecoTotemRPRPElasticReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPElasticReconstruction/plugins))
RecoTotemRPRPElasticReconstructionPlugins_PACKAGE := self/src/RecoTotemRP/RPElasticReconstruction/plugins
ALL_PRODS += RecoTotemRPRPElasticReconstructionPlugins
RecoTotemRPRPElasticReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPElasticReconstructionPlugins,src/RecoTotemRP/RPElasticReconstruction/plugins,src_RecoTotemRP_RPElasticReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPElasticReconstructionPlugins,src/RecoTotemRP/RPElasticReconstruction/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPElasticReconstruction_plugins
src_RecoTotemRP_RPElasticReconstruction_plugins_parent := RecoTotemRP/RPElasticReconstruction
src_RecoTotemRP_RPElasticReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPElasticReconstruction_plugins,src/RecoTotemRP/RPElasticReconstruction/plugins,PLUGINS))
