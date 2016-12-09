ifeq ($(strip $(PyTotemRPValidationRPReconstructedTracksValidation)),)
PyTotemRPValidationRPReconstructedTracksValidation := self/src/TotemRPValidation/RPReconstructedTracksValidation/python
src_TotemRPValidation_RPReconstructedTracksValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPReconstructedTracksValidation/python)
PyTotemRPValidationRPReconstructedTracksValidation_files := $(patsubst src/TotemRPValidation/RPReconstructedTracksValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPReconstructedTracksValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPReconstructedTracksValidation_LOC_USE := self  
PyTotemRPValidationRPReconstructedTracksValidation_PACKAGE := self/src/TotemRPValidation/RPReconstructedTracksValidation/python
ALL_PRODS += PyTotemRPValidationRPReconstructedTracksValidation
PyTotemRPValidationRPReconstructedTracksValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPReconstructedTracksValidation,src/TotemRPValidation/RPReconstructedTracksValidation/python,src_TotemRPValidation_RPReconstructedTracksValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPReconstructedTracksValidation,src/TotemRPValidation/RPReconstructedTracksValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPReconstructedTracksValidation_python
src_TotemRPValidation_RPReconstructedTracksValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPReconstructedTracksValidation_python,src/TotemRPValidation/RPReconstructedTracksValidation/python,PYTHON))
