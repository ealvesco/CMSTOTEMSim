ifeq ($(strip $(PyTotemRPValidationRPAngleValidation)),)
PyTotemRPValidationRPAngleValidation := self/src/TotemRPValidation/RPAngleValidation/python
src_TotemRPValidation_RPAngleValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPAngleValidation/python)
PyTotemRPValidationRPAngleValidation_files := $(patsubst src/TotemRPValidation/RPAngleValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPAngleValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPAngleValidation_LOC_USE := self  
PyTotemRPValidationRPAngleValidation_PACKAGE := self/src/TotemRPValidation/RPAngleValidation/python
ALL_PRODS += PyTotemRPValidationRPAngleValidation
PyTotemRPValidationRPAngleValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/python,src_TotemRPValidation_RPAngleValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPAngleValidation_python
src_TotemRPValidation_RPAngleValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPAngleValidation_python,src/TotemRPValidation/RPAngleValidation/python,PYTHON))
