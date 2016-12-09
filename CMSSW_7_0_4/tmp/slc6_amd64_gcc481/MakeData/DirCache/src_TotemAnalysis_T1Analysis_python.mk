ifeq ($(strip $(PyTotemAnalysisT1Analysis)),)
PyTotemAnalysisT1Analysis := self/src/TotemAnalysis/T1Analysis/python
src_TotemAnalysis_T1Analysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T1Analysis/python)
PyTotemAnalysisT1Analysis_files := $(patsubst src/TotemAnalysis/T1Analysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T1Analysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT1Analysis_LOC_USE := self  
PyTotemAnalysisT1Analysis_PACKAGE := self/src/TotemAnalysis/T1Analysis/python
ALL_PRODS += PyTotemAnalysisT1Analysis
PyTotemAnalysisT1Analysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT1Analysis,src/TotemAnalysis/T1Analysis/python,src_TotemAnalysis_T1Analysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT1Analysis,src/TotemAnalysis/T1Analysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T1Analysis_python
src_TotemAnalysis_T1Analysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T1Analysis_python,src/TotemAnalysis/T1Analysis/python,PYTHON))
