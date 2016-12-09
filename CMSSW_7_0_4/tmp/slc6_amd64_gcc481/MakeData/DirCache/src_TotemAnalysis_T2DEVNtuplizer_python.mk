ifeq ($(strip $(PyTotemAnalysisT2DEVNtuplizer)),)
PyTotemAnalysisT2DEVNtuplizer := self/src/TotemAnalysis/T2DEVNtuplizer/python
src_TotemAnalysis_T2DEVNtuplizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2DEVNtuplizer/python)
PyTotemAnalysisT2DEVNtuplizer_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2DEVNtuplizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2DEVNtuplizer_LOC_USE := self  
PyTotemAnalysisT2DEVNtuplizer_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/python
ALL_PRODS += PyTotemAnalysisT2DEVNtuplizer
PyTotemAnalysisT2DEVNtuplizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/python,src_TotemAnalysis_T2DEVNtuplizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_python
src_TotemAnalysis_T2DEVNtuplizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_python,src/TotemAnalysis/T2DEVNtuplizer/python,PYTHON))
