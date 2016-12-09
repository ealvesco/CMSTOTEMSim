ifeq ($(strip $(TotemAnalysis/TotemNtuplizer)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_src
src_TotemAnalysis_TotemNtuplizer_src_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_src,src/TotemAnalysis/TotemNtuplizer/src,LIBRARY))
TotemAnalysisTotemNtuplizer := self/TotemAnalysis/TotemNtuplizer
TotemAnalysis/TotemNtuplizer := TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemNtuplizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemNtuplizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemNtuplizer/BuildFile
TotemAnalysisTotemNtuplizer_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road TotemAnalysis/TotemAnalysisEvent fastjet
TotemAnalysisTotemNtuplizer_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/src, LinkDef.h))
TotemAnalysisTotemNtuplizer_EX_LIB   := TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_EX_USE   := $(foreach d,$(TotemAnalysisTotemNtuplizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemNtuplizer_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/src
ALL_PRODS += TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/src,src_TotemAnalysis_TotemNtuplizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
