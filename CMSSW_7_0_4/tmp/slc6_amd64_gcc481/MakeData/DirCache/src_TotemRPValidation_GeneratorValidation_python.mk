ifeq ($(strip $(PyTotemRPValidationGeneratorValidation)),)
PyTotemRPValidationGeneratorValidation := self/src/TotemRPValidation/GeneratorValidation/python
src_TotemRPValidation_GeneratorValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/GeneratorValidation/python)
PyTotemRPValidationGeneratorValidation_files := $(patsubst src/TotemRPValidation/GeneratorValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/GeneratorValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationGeneratorValidation_LOC_USE := self  
PyTotemRPValidationGeneratorValidation_PACKAGE := self/src/TotemRPValidation/GeneratorValidation/python
ALL_PRODS += PyTotemRPValidationGeneratorValidation
PyTotemRPValidationGeneratorValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationGeneratorValidation,src/TotemRPValidation/GeneratorValidation/python,src_TotemRPValidation_GeneratorValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationGeneratorValidation,src/TotemRPValidation/GeneratorValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_GeneratorValidation_python
src_TotemRPValidation_GeneratorValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_GeneratorValidation_python,src/TotemRPValidation/GeneratorValidation/python,PYTHON))
