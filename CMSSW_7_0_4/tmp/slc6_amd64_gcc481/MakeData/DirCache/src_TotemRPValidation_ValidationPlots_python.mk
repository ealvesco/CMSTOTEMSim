ifeq ($(strip $(PyTotemRPValidationValidationPlots)),)
PyTotemRPValidationValidationPlots := self/src/TotemRPValidation/ValidationPlots/python
src_TotemRPValidation_ValidationPlots_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/ValidationPlots/python)
PyTotemRPValidationValidationPlots_files := $(patsubst src/TotemRPValidation/ValidationPlots/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationPlots/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationValidationPlots_LOC_USE := self  
PyTotemRPValidationValidationPlots_PACKAGE := self/src/TotemRPValidation/ValidationPlots/python
ALL_PRODS += PyTotemRPValidationValidationPlots
PyTotemRPValidationValidationPlots_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/python,src_TotemRPValidation_ValidationPlots_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_python
src_TotemRPValidation_ValidationPlots_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_python,src/TotemRPValidation/ValidationPlots/python,PYTHON))
