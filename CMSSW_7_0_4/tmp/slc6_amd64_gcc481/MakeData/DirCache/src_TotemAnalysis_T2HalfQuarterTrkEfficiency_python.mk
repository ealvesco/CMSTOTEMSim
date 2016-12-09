ifeq ($(strip $(PyTotemAnalysisT2HalfQuarterTrkEfficiency)),)
PyTotemAnalysisT2HalfQuarterTrkEfficiency := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python)
PyTotemAnalysisT2HalfQuarterTrkEfficiency_files := $(patsubst src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2HalfQuarterTrkEfficiency_LOC_USE := self  
PyTotemAnalysisT2HalfQuarterTrkEfficiency_PACKAGE := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python
ALL_PRODS += PyTotemAnalysisT2HalfQuarterTrkEfficiency
PyTotemAnalysisT2HalfQuarterTrkEfficiency_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python,PYTHON))
