ifeq ($(strip $(TotemAnalysisRPTimingDetectorsAnalysisAuto)),)
TotemAnalysisRPTimingDetectorsAnalysisAuto_files := $(patsubst src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisRPTimingDetectorsAnalysisAuto := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins
TotemAnalysisRPTimingDetectorsAnalysisAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins/BuildFile
TotemAnalysisRPTimingDetectorsAnalysisAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet SimDataFormats/TrackingHit boost geant4 DataFormats/TotemRPDetId CommonTools/UtilAlgos PhysicsTools/UtilAlgos Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAnalysisRPTimingDetectorsAnalysisAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisRPTimingDetectorsAnalysisAuto,TotemAnalysisRPTimingDetectorsAnalysisAuto,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins))
TotemAnalysisRPTimingDetectorsAnalysisAuto_PACKAGE := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins
ALL_PRODS += TotemAnalysisRPTimingDetectorsAnalysisAuto
TotemAnalysisRPTimingDetectorsAnalysisAuto_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisRPTimingDetectorsAnalysisAuto,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins,src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisRPTimingDetectorsAnalysisAuto,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins
src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins_parent := TotemAnalysis/RPTimingDetectorsAnalysis
src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins,PLUGINS))
