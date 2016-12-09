ifeq ($(strip $(TotemAnalysis/T2DEVNtuplizer)),)
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_src
src_TotemAnalysis_T2DEVNtuplizer_src_parent := TotemAnalysis/T2DEVNtuplizer
src_TotemAnalysis_T2DEVNtuplizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_src,src/TotemAnalysis/T2DEVNtuplizer/src,LIBRARY))
TotemAnalysisT2DEVNtuplizer := self/TotemAnalysis/T2DEVNtuplizer
TotemAnalysis/T2DEVNtuplizer := TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2DEVNtuplizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2DEVNtuplizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2DEVNtuplizer/BuildFile
TotemAnalysisT2DEVNtuplizer_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road fastjet
TotemAnalysisT2DEVNtuplizer_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/src, LinkDef.h))
TotemAnalysisT2DEVNtuplizer_EX_LIB   := TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_EX_USE   := $(foreach d,$(TotemAnalysisT2DEVNtuplizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisT2DEVNtuplizer_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/src
ALL_PRODS += TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/src,src_TotemAnalysis_T2DEVNtuplizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
