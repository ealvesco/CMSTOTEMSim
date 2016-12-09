ifeq ($(strip $(TotemAnalysisTestBeamPlugins)),)
TotemAnalysisTestBeamPlugins_files := $(patsubst src/TotemAnalysis/TestBeam/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TestBeam/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TestBeam/plugins/$(file). Please fix src/TotemAnalysis/TestBeam/plugins/BuildFile.))))
TotemAnalysisTestBeamPlugins := self/src/TotemAnalysis/TestBeam/plugins
TotemAnalysisTestBeamPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TestBeam/plugins/BuildFile
TotemAnalysisTestBeamPlugins_LOC_FLAGS_CXXFLAGS   := -g3 -O3 $(CUSTOM_FLAGS)
TotemAnalysisTestBeamPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords TotemAnalysis/TestBeam root rootgraphics
TotemAnalysisTestBeamPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTestBeamPlugins,TotemAnalysisTestBeamPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TestBeam/plugins))
TotemAnalysisTestBeamPlugins_PACKAGE := self/src/TotemAnalysis/TestBeam/plugins
ALL_PRODS += TotemAnalysisTestBeamPlugins
TotemAnalysisTestBeamPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTestBeamPlugins,src/TotemAnalysis/TestBeam/plugins,src_TotemAnalysis_TestBeam_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTestBeamPlugins,src/TotemAnalysis/TestBeam/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TestBeam_plugins
src_TotemAnalysis_TestBeam_plugins_parent := TotemAnalysis/TestBeam
src_TotemAnalysis_TestBeam_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TestBeam_plugins,src/TotemAnalysis/TestBeam/plugins,PLUGINS))
