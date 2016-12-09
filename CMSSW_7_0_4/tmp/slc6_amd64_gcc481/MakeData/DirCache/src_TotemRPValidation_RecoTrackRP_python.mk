ifeq ($(strip $(PyTotemRPValidationRecoTrackRP)),)
PyTotemRPValidationRecoTrackRP := self/src/TotemRPValidation/RecoTrackRP/python
src_TotemRPValidation_RecoTrackRP_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RecoTrackRP/python)
PyTotemRPValidationRecoTrackRP_files := $(patsubst src/TotemRPValidation/RecoTrackRP/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RecoTrackRP/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRecoTrackRP_LOC_USE := self  
PyTotemRPValidationRecoTrackRP_PACKAGE := self/src/TotemRPValidation/RecoTrackRP/python
ALL_PRODS += PyTotemRPValidationRecoTrackRP
PyTotemRPValidationRecoTrackRP_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/python,src_TotemRPValidation_RecoTrackRP_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_python
src_TotemRPValidation_RecoTrackRP_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_python,src/TotemRPValidation/RecoTrackRP/python,PYTHON))
