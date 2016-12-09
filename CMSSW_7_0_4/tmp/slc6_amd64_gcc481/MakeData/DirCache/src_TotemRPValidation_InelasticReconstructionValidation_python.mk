ifeq ($(strip $(PyTotemRPValidationInelasticReconstructionValidation)),)
PyTotemRPValidationInelasticReconstructionValidation := self/src/TotemRPValidation/InelasticReconstructionValidation/python
src_TotemRPValidation_InelasticReconstructionValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/InelasticReconstructionValidation/python)
PyTotemRPValidationInelasticReconstructionValidation_files := $(patsubst src/TotemRPValidation/InelasticReconstructionValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/InelasticReconstructionValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationInelasticReconstructionValidation_LOC_USE := self  
PyTotemRPValidationInelasticReconstructionValidation_PACKAGE := self/src/TotemRPValidation/InelasticReconstructionValidation/python
ALL_PRODS += PyTotemRPValidationInelasticReconstructionValidation
PyTotemRPValidationInelasticReconstructionValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationInelasticReconstructionValidation,src/TotemRPValidation/InelasticReconstructionValidation/python,src_TotemRPValidation_InelasticReconstructionValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationInelasticReconstructionValidation,src/TotemRPValidation/InelasticReconstructionValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_InelasticReconstructionValidation_python
src_TotemRPValidation_InelasticReconstructionValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_InelasticReconstructionValidation_python,src/TotemRPValidation/InelasticReconstructionValidation/python,PYTHON))
