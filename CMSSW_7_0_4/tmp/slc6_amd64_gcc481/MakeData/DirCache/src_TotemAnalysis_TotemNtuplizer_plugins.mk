ifeq ($(strip $(TotemAnalysisTotemNtuplizerPlugins)),)
TotemAnalysisTotemNtuplizerPlugins_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TotemNtuplizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TotemNtuplizer/plugins/$(file). Please fix src/TotemAnalysis/TotemNtuplizer/plugins/BuildFile.))))
TotemAnalysisTotemNtuplizerPlugins := self/src/TotemAnalysis/TotemNtuplizer/plugins
TotemAnalysisTotemNtuplizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemNtuplizer/plugins/BuildFile
TotemAnalysisTotemNtuplizerPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry TotemAnalysis/TotemNtuplizer TotemAnalysis/TotemAnalysisEvent
TotemAnalysisTotemNtuplizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTotemNtuplizerPlugins,TotemAnalysisTotemNtuplizerPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TotemNtuplizer/plugins))
TotemAnalysisTotemNtuplizerPlugins_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/plugins
ALL_PRODS += TotemAnalysisTotemNtuplizerPlugins
TotemAnalysisTotemNtuplizerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemNtuplizerPlugins,src/TotemAnalysis/TotemNtuplizer/plugins,src_TotemAnalysis_TotemNtuplizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTotemNtuplizerPlugins,src/TotemAnalysis/TotemNtuplizer/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_plugins
src_TotemAnalysis_TotemNtuplizer_plugins_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_plugins,src/TotemAnalysis/TotemNtuplizer/plugins,PLUGINS))
