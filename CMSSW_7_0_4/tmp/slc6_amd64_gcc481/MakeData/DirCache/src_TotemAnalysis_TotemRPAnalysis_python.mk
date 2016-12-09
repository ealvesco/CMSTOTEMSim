ifeq ($(strip $(PyTotemAnalysisTotemRPAnalysis)),)
PyTotemAnalysisTotemRPAnalysis := self/src/TotemAnalysis/TotemRPAnalysis/python
src_TotemAnalysis_TotemRPAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/TotemRPAnalysis/python)
PyTotemAnalysisTotemRPAnalysis_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemRPAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisTotemRPAnalysis_LOC_USE := self  
PyTotemAnalysisTotemRPAnalysis_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/python
ALL_PRODS += PyTotemAnalysisTotemRPAnalysis
PyTotemAnalysisTotemRPAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/python,src_TotemAnalysis_TotemRPAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_python
src_TotemAnalysis_TotemRPAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_python,src/TotemAnalysis/TotemRPAnalysis/python,PYTHON))
