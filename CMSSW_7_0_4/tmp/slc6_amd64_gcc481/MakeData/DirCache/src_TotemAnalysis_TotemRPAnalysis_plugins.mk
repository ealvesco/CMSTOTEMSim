ifeq ($(strip $(TotemAnalysisTotemAnalysisEventPlugins)),)
TotemAnalysisTotemAnalysisEventPlugins_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TotemRPAnalysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TotemRPAnalysis/plugins/$(file). Please fix src/TotemAnalysis/TotemRPAnalysis/plugins/BuildFile.))))
TotemAnalysisTotemAnalysisEventPlugins := self/src/TotemAnalysis/TotemRPAnalysis/plugins
TotemAnalysisTotemAnalysisEventPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemRPAnalysis/plugins/BuildFile
TotemAnalysisTotemAnalysisEventPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet CommonTools/UtilAlgos TotemAnalysis/TotemRPAnalysis TotemAnalysis/TotemAnalysisEvent ForwardAnalysis/ForwardTTreeAnalysis root hepmc clhep boost_header
TotemAnalysisTotemAnalysisEventPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTotemAnalysisEventPlugins,TotemAnalysisTotemAnalysisEventPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TotemRPAnalysis/plugins))
TotemAnalysisTotemAnalysisEventPlugins_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/plugins
ALL_PRODS += TotemAnalysisTotemAnalysisEventPlugins
TotemAnalysisTotemAnalysisEventPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemAnalysisEventPlugins,src/TotemAnalysis/TotemRPAnalysis/plugins,src_TotemAnalysis_TotemRPAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTotemAnalysisEventPlugins,src/TotemAnalysis/TotemRPAnalysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_plugins
src_TotemAnalysis_TotemRPAnalysis_plugins_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_plugins,src/TotemAnalysis/TotemRPAnalysis/plugins,PLUGINS))
