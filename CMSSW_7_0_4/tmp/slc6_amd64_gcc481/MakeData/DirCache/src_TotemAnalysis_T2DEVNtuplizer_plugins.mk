ifeq ($(strip $(TotemAnalysisT2DEVNtuplizerPlugins)),)
TotemAnalysisT2DEVNtuplizerPlugins_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/T2DEVNtuplizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/T2DEVNtuplizer/plugins/$(file). Please fix src/TotemAnalysis/T2DEVNtuplizer/plugins/BuildFile.))))
TotemAnalysisT2DEVNtuplizerPlugins := self/src/TotemAnalysis/T2DEVNtuplizer/plugins
TotemAnalysisT2DEVNtuplizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2DEVNtuplizer/plugins/BuildFile
TotemAnalysisT2DEVNtuplizerPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry TotemAnalysis/T2DEVNtuplizer SimGeneral/HepPDTRecord
TotemAnalysisT2DEVNtuplizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2DEVNtuplizerPlugins,TotemAnalysisT2DEVNtuplizerPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2DEVNtuplizer/plugins))
TotemAnalysisT2DEVNtuplizerPlugins_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/plugins
ALL_PRODS += TotemAnalysisT2DEVNtuplizerPlugins
TotemAnalysisT2DEVNtuplizerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2DEVNtuplizerPlugins,src/TotemAnalysis/T2DEVNtuplizer/plugins,src_TotemAnalysis_T2DEVNtuplizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisT2DEVNtuplizerPlugins,src/TotemAnalysis/T2DEVNtuplizer/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_plugins
src_TotemAnalysis_T2DEVNtuplizer_plugins_parent := TotemAnalysis/T2DEVNtuplizer
src_TotemAnalysis_T2DEVNtuplizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_plugins,src/TotemAnalysis/T2DEVNtuplizer/plugins,PLUGINS))
