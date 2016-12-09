ifeq ($(strip $(TotemAnalysis/TestBeam)),)
ALL_COMMONRULES += src_TotemAnalysis_TestBeam_src
src_TotemAnalysis_TestBeam_src_parent := TotemAnalysis/TestBeam
src_TotemAnalysis_TestBeam_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TestBeam_src,src/TotemAnalysis/TestBeam/src,LIBRARY))
TotemAnalysisTestBeam := self/TotemAnalysis/TestBeam
TotemAnalysis/TestBeam := TotemAnalysisTestBeam
TotemAnalysisTestBeam_files := $(patsubst src/TotemAnalysis/TestBeam/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TestBeam/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTestBeam_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TestBeam/BuildFile
TotemAnalysisTestBeam_LOC_FLAGS_CXXFLAGS   := -g3 -O3 $(CUSTOM_FLAGS)
TotemAnalysisTestBeam_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAnalysisTestBeam_EX_LIB   := TotemAnalysisTestBeam
TotemAnalysisTestBeam_EX_USE   := $(foreach d,$(TotemAnalysisTestBeam_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTestBeam_PACKAGE := self/src/TotemAnalysis/TestBeam/src
ALL_PRODS += TotemAnalysisTestBeam
TotemAnalysisTestBeam_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTestBeam,src/TotemAnalysis/TestBeam/src,src_TotemAnalysis_TestBeam_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
