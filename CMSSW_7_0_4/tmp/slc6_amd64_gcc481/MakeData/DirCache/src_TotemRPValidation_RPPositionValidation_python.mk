ifeq ($(strip $(PyTotemRPValidationRPPositionValidation)),)
PyTotemRPValidationRPPositionValidation := self/src/TotemRPValidation/RPPositionValidation/python
src_TotemRPValidation_RPPositionValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPPositionValidation/python)
PyTotemRPValidationRPPositionValidation_files := $(patsubst src/TotemRPValidation/RPPositionValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPPositionValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPPositionValidation_LOC_USE := self  
PyTotemRPValidationRPPositionValidation_PACKAGE := self/src/TotemRPValidation/RPPositionValidation/python
ALL_PRODS += PyTotemRPValidationRPPositionValidation
PyTotemRPValidationRPPositionValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/python,src_TotemRPValidation_RPPositionValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPPositionValidation_python
src_TotemRPValidation_RPPositionValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPPositionValidation_python,src/TotemRPValidation/RPPositionValidation/python,PYTHON))
