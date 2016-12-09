ifeq ($(strip $(PyTotemT1T2ValidationT2GeometryValidation)),)
PyTotemT1T2ValidationT2GeometryValidation := self/src/TotemT1T2Validation/T2GeometryValidation/python
src_TotemT1T2Validation_T2GeometryValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2GeometryValidation/python)
PyTotemT1T2ValidationT2GeometryValidation_files := $(patsubst src/TotemT1T2Validation/T2GeometryValidation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2GeometryValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2GeometryValidation_LOC_USE := self  
PyTotemT1T2ValidationT2GeometryValidation_PACKAGE := self/src/TotemT1T2Validation/T2GeometryValidation/python
ALL_PRODS += PyTotemT1T2ValidationT2GeometryValidation
PyTotemT1T2ValidationT2GeometryValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/python,src_TotemT1T2Validation_T2GeometryValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2GeometryValidation_python
src_TotemT1T2Validation_T2GeometryValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2GeometryValidation_python,src/TotemT1T2Validation/T2GeometryValidation/python,PYTHON))
