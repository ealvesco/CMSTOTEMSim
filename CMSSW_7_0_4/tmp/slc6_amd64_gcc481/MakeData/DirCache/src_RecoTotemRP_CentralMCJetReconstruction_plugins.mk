ifeq ($(strip $(RecoTotemRPCentralMCJetReconstructionPlugins)),)
RecoTotemRPCentralMCJetReconstructionPlugins_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/CentralMCJetReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/CentralMCJetReconstruction/plugins/$(file). Please fix src/RecoTotemRP/CentralMCJetReconstruction/plugins/BuildFile.))))
RecoTotemRPCentralMCJetReconstructionPlugins := self/src/RecoTotemRP/CentralMCJetReconstruction/plugins
RecoTotemRPCentralMCJetReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/CentralMCJetReconstruction/plugins/BuildFile
RecoTotemRPCentralMCJetReconstructionPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry RecoTotemRP/CentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPCentralMCJetReconstructionPlugins,RecoTotemRPCentralMCJetReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/CentralMCJetReconstruction/plugins))
RecoTotemRPCentralMCJetReconstructionPlugins_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/plugins
ALL_PRODS += RecoTotemRPCentralMCJetReconstructionPlugins
RecoTotemRPCentralMCJetReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPCentralMCJetReconstructionPlugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins,src_RecoTotemRP_CentralMCJetReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPCentralMCJetReconstructionPlugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_plugins
src_RecoTotemRP_CentralMCJetReconstruction_plugins_parent := RecoTotemRP/CentralMCJetReconstruction
src_RecoTotemRP_CentralMCJetReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_plugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins,PLUGINS))
