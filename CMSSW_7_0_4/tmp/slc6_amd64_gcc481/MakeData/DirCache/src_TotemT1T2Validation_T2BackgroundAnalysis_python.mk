ifeq ($(strip $(PyTotemT1T2ValidationT2BackgroundAnalysis)),)
PyTotemT1T2ValidationT2BackgroundAnalysis := self/src/TotemT1T2Validation/T2BackgroundAnalysis/python
src_TotemT1T2Validation_T2BackgroundAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2BackgroundAnalysis/python)
PyTotemT1T2ValidationT2BackgroundAnalysis_files := $(patsubst src/TotemT1T2Validation/T2BackgroundAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2BackgroundAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2BackgroundAnalysis_LOC_USE := self  
PyTotemT1T2ValidationT2BackgroundAnalysis_PACKAGE := self/src/TotemT1T2Validation/T2BackgroundAnalysis/python
ALL_PRODS += PyTotemT1T2ValidationT2BackgroundAnalysis
PyTotemT1T2ValidationT2BackgroundAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/python,src_TotemT1T2Validation_T2BackgroundAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2BackgroundAnalysis_python
src_TotemT1T2Validation_T2BackgroundAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2BackgroundAnalysis_python,src/TotemT1T2Validation/T2BackgroundAnalysis/python,PYTHON))
