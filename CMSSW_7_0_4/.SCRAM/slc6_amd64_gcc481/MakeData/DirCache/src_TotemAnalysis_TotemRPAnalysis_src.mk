ifeq ($(strip $(TotemAnalysis/TotemRPAnalysis)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_src
src_TotemAnalysis_TotemRPAnalysis_src_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_src,src/TotemAnalysis/TotemRPAnalysis/src,LIBRARY))
TotemAnalysisTotemRPAnalysis := self/TotemAnalysis/TotemRPAnalysis
TotemAnalysis/TotemRPAnalysis := TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemRPAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemRPAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemRPAnalysis/BuildFile
TotemAnalysisTotemRPAnalysis_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root hepmc fastjet DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road TotemAnalysis/TotemAnalysisEvent
TotemAnalysisTotemRPAnalysis_EX_LIB   := TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_EX_USE   := $(foreach d,$(TotemAnalysisTotemRPAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemRPAnalysis_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/src
ALL_PRODS += TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/src,src_TotemAnalysis_TotemRPAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
