ifeq ($(strip $(PyTotemT1T2ValidationT1Validation)),)
PyTotemT1T2ValidationT1Validation := self/src/TotemT1T2Validation/T1Validation/python
src_TotemT1T2Validation_T1Validation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T1Validation/python)
PyTotemT1T2ValidationT1Validation_files := $(patsubst src/TotemT1T2Validation/T1Validation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T1Validation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT1Validation_LOC_USE := self  
PyTotemT1T2ValidationT1Validation_PACKAGE := self/src/TotemT1T2Validation/T1Validation/python
ALL_PRODS += PyTotemT1T2ValidationT1Validation
PyTotemT1T2ValidationT1Validation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT1Validation,src/TotemT1T2Validation/T1Validation/python,src_TotemT1T2Validation_T1Validation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT1Validation,src/TotemT1T2Validation/T1Validation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T1Validation_python
src_TotemT1T2Validation_T1Validation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T1Validation_python,src/TotemT1T2Validation/T1Validation/python,PYTHON))
