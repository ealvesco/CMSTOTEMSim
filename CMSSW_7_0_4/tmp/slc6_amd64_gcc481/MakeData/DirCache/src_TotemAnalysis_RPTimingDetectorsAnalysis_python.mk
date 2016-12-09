ifeq ($(strip $(PyTotemAnalysisRPTimingDetectorsAnalysis)),)
PyTotemAnalysisRPTimingDetectorsAnalysis := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/python
src_TotemAnalysis_RPTimingDetectorsAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/RPTimingDetectorsAnalysis/python)
PyTotemAnalysisRPTimingDetectorsAnalysis_files := $(patsubst src/TotemAnalysis/RPTimingDetectorsAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/RPTimingDetectorsAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisRPTimingDetectorsAnalysis_LOC_USE := self  
PyTotemAnalysisRPTimingDetectorsAnalysis_PACKAGE := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/python
ALL_PRODS += PyTotemAnalysisRPTimingDetectorsAnalysis
PyTotemAnalysisRPTimingDetectorsAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisRPTimingDetectorsAnalysis,src/TotemAnalysis/RPTimingDetectorsAnalysis/python,src_TotemAnalysis_RPTimingDetectorsAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisRPTimingDetectorsAnalysis,src/TotemAnalysis/RPTimingDetectorsAnalysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_RPTimingDetectorsAnalysis_python
src_TotemAnalysis_RPTimingDetectorsAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_RPTimingDetectorsAnalysis_python,src/TotemAnalysis/RPTimingDetectorsAnalysis/python,PYTHON))
