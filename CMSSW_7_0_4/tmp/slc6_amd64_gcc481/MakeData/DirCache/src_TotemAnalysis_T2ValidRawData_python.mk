ifeq ($(strip $(PyTotemAnalysisT2ValidRawData)),)
PyTotemAnalysisT2ValidRawData := self/src/TotemAnalysis/T2ValidRawData/python
src_TotemAnalysis_T2ValidRawData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2ValidRawData/python)
PyTotemAnalysisT2ValidRawData_files := $(patsubst src/TotemAnalysis/T2ValidRawData/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2ValidRawData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2ValidRawData_LOC_USE := self  
PyTotemAnalysisT2ValidRawData_PACKAGE := self/src/TotemAnalysis/T2ValidRawData/python
ALL_PRODS += PyTotemAnalysisT2ValidRawData
PyTotemAnalysisT2ValidRawData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/python,src_TotemAnalysis_T2ValidRawData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2ValidRawData_python
src_TotemAnalysis_T2ValidRawData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2ValidRawData_python,src/TotemAnalysis/T2ValidRawData/python,PYTHON))
