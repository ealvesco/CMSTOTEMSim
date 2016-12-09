ifeq ($(strip $(PyTotemRPValidationAcceptance)),)
PyTotemRPValidationAcceptance := self/src/TotemRPValidation/Acceptance/python
src_TotemRPValidation_Acceptance_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/Acceptance/python)
PyTotemRPValidationAcceptance_files := $(patsubst src/TotemRPValidation/Acceptance/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/Acceptance/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationAcceptance_LOC_USE := self  
PyTotemRPValidationAcceptance_PACKAGE := self/src/TotemRPValidation/Acceptance/python
ALL_PRODS += PyTotemRPValidationAcceptance
PyTotemRPValidationAcceptance_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationAcceptance,src/TotemRPValidation/Acceptance/python,src_TotemRPValidation_Acceptance_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationAcceptance,src/TotemRPValidation/Acceptance/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_Acceptance_python
src_TotemRPValidation_Acceptance_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_Acceptance_python,src/TotemRPValidation/Acceptance/python,PYTHON))
