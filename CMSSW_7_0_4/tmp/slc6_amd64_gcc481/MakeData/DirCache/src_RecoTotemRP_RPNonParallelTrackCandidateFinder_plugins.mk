ifeq ($(strip $(RecoTotemRPRPNonParallelTrackCandidateFinderPlugins)),)
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/$(file). Please fix src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/BuildFile.))))
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/BuildFile
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_LOC_USE := self  FWCore/Framework RecoTotemRP/RPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins))
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins
ALL_PRODS += RecoTotemRPRPNonParallelTrackCandidateFinderPlugins
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins_parent := RecoTotemRP/RPNonParallelTrackCandidateFinder
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins,PLUGINS))
