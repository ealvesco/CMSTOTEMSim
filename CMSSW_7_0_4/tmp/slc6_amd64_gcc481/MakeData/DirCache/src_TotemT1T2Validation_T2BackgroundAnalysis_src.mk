ifeq ($(strip $(TotemT1T2Validation/T2BackgroundAnalysis)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2BackgroundAnalysis_src
src_TotemT1T2Validation_T2BackgroundAnalysis_src_parent := TotemT1T2Validation/T2BackgroundAnalysis
src_TotemT1T2Validation_T2BackgroundAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2BackgroundAnalysis_src,src/TotemT1T2Validation/T2BackgroundAnalysis/src,LIBRARY))
TotemT1T2ValidationT2BackgroundAnalysis := self/TotemT1T2Validation/T2BackgroundAnalysis
TotemT1T2Validation/T2BackgroundAnalysis := TotemT1T2ValidationT2BackgroundAnalysis
TotemT1T2ValidationT2BackgroundAnalysis_files := $(patsubst src/TotemT1T2Validation/T2BackgroundAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2BackgroundAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2BackgroundAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2BackgroundAnalysis/BuildFile
TotemT1T2ValidationT2BackgroundAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/T1T2Track SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex Geometry/TotemGeometry TotemAnalysis/T2Cuts
TotemT1T2ValidationT2BackgroundAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2BackgroundAnalysis,TotemT1T2ValidationT2BackgroundAnalysis,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2BackgroundAnalysis/src))
TotemT1T2ValidationT2BackgroundAnalysis_PACKAGE := self/src/TotemT1T2Validation/T2BackgroundAnalysis/src
ALL_PRODS += TotemT1T2ValidationT2BackgroundAnalysis
TotemT1T2ValidationT2BackgroundAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/src,src_TotemT1T2Validation_T2BackgroundAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
