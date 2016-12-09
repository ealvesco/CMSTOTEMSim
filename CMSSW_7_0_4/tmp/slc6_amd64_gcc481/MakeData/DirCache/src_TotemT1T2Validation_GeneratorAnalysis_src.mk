ifeq ($(strip $(TotemT1T2Validation/GeneratorAnalysis)),)
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_src
src_TotemT1T2Validation_GeneratorAnalysis_src_parent := TotemT1T2Validation/GeneratorAnalysis
src_TotemT1T2Validation_GeneratorAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_src,src/TotemT1T2Validation/GeneratorAnalysis/src,LIBRARY))
TotemT1T2ValidationGeneratorAnalysis := self/TotemT1T2Validation/GeneratorAnalysis
TotemT1T2Validation/GeneratorAnalysis := TotemT1T2ValidationGeneratorAnalysis
TotemT1T2ValidationGeneratorAnalysis_files := $(patsubst src/TotemT1T2Validation/GeneratorAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/GeneratorAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationGeneratorAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/GeneratorAnalysis/BuildFile
TotemT1T2ValidationGeneratorAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/T1T2Track SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex Geometry/TotemGeometry TotemAnalysis/T2Cuts FWCore/MessageLogger boost root DataFormats/T2DetId SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep SimGeneral/HepPDTRecord
TotemT1T2ValidationGeneratorAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationGeneratorAnalysis,TotemT1T2ValidationGeneratorAnalysis,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/GeneratorAnalysis/src))
TotemT1T2ValidationGeneratorAnalysis_PACKAGE := self/src/TotemT1T2Validation/GeneratorAnalysis/src
ALL_PRODS += TotemT1T2ValidationGeneratorAnalysis
TotemT1T2ValidationGeneratorAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/src,src_TotemT1T2Validation_GeneratorAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
