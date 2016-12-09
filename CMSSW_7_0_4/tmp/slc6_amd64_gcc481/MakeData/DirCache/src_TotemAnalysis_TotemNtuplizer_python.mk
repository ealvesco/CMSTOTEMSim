ifeq ($(strip $(PyTotemAnalysisTotemNtuplizer)),)
PyTotemAnalysisTotemNtuplizer := self/src/TotemAnalysis/TotemNtuplizer/python
src_TotemAnalysis_TotemNtuplizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/TotemNtuplizer/python)
PyTotemAnalysisTotemNtuplizer_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemNtuplizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisTotemNtuplizer_LOC_USE := self  
PyTotemAnalysisTotemNtuplizer_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/python
ALL_PRODS += PyTotemAnalysisTotemNtuplizer
PyTotemAnalysisTotemNtuplizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/python,src_TotemAnalysis_TotemNtuplizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_python
src_TotemAnalysis_TotemNtuplizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_python,src/TotemAnalysis/TotemNtuplizer/python,PYTHON))
