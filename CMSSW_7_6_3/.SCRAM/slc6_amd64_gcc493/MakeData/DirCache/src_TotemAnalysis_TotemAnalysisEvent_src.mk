ifeq ($(strip $(TotemAnalysis/TotemAnalysisEvent)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemAnalysisEvent_src
src_TotemAnalysis_TotemAnalysisEvent_src_parent := TotemAnalysis/TotemAnalysisEvent
src_TotemAnalysis_TotemAnalysisEvent_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemAnalysisEvent_src,src/TotemAnalysis/TotemAnalysisEvent/src,LIBRARY))
TotemAnalysisTotemAnalysisEvent := self/TotemAnalysis/TotemAnalysisEvent
TotemAnalysis/TotemAnalysisEvent := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_files := $(patsubst src/TotemAnalysis/TotemAnalysisEvent/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemAnalysisEvent/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemAnalysisEvent_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemAnalysisEvent/BuildFile
TotemAnalysisTotemAnalysisEvent_LOC_USE := self  FWCore/ParameterSet FWCore/Framework root DataFormats/Common
TotemAnalysisTotemAnalysisEvent_LCGDICTS  := x 
TotemAnalysisTotemAnalysisEvent_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAnalysisTotemAnalysisEvent,src/TotemAnalysis/TotemAnalysisEvent/src/classes.h,src/TotemAnalysis/TotemAnalysisEvent/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,))
TotemAnalysisTotemAnalysisEvent_EX_LIB   := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_EX_USE   := $(foreach d,$(TotemAnalysisTotemAnalysisEvent_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemAnalysisEvent_PACKAGE := self/src/TotemAnalysis/TotemAnalysisEvent/src
ALL_PRODS += TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_CLASS := LIBRARY
TotemAnalysis/TotemAnalysisEvent_forbigobj+=TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemAnalysisEvent,src/TotemAnalysis/TotemAnalysisEvent/src,src_TotemAnalysis_TotemAnalysisEvent_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
