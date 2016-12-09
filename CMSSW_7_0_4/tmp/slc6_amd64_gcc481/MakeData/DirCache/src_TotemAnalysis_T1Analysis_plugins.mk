ifeq ($(strip $(TotemAnalysisT1AnalysisPlugins)),)
TotemAnalysisT1AnalysisPlugins_files := $(patsubst src/TotemAnalysis/T1Analysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/T1Analysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/T1Analysis/plugins/$(file). Please fix src/TotemAnalysis/T1Analysis/plugins/BuildFile.))))
TotemAnalysisT1AnalysisPlugins := self/src/TotemAnalysis/T1Analysis/plugins
TotemAnalysisT1AnalysisPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T1Analysis/plugins/BuildFile
TotemAnalysisT1AnalysisPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry clhep root boost DataFormats/Common TotemCondFormats/DataRecord Geometry/TotemRecords DataFormats/TotemL1Trigger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road
TotemAnalysisT1AnalysisPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT1AnalysisPlugins,TotemAnalysisT1AnalysisPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T1Analysis/plugins))
TotemAnalysisT1AnalysisPlugins_PACKAGE := self/src/TotemAnalysis/T1Analysis/plugins
ALL_PRODS += TotemAnalysisT1AnalysisPlugins
TotemAnalysisT1AnalysisPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT1AnalysisPlugins,src/TotemAnalysis/T1Analysis/plugins,src_TotemAnalysis_T1Analysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisT1AnalysisPlugins,src/TotemAnalysis/T1Analysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_T1Analysis_plugins
src_TotemAnalysis_T1Analysis_plugins_parent := TotemAnalysis/T1Analysis
src_TotemAnalysis_T1Analysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T1Analysis_plugins,src/TotemAnalysis/T1Analysis/plugins,PLUGINS))
