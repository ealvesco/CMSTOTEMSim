ifeq ($(strip $(PyTotemRPValidationHitDistributions)),)
PyTotemRPValidationHitDistributions := self/src/TotemRPValidation/HitDistributions/python
src_TotemRPValidation_HitDistributions_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/HitDistributions/python)
PyTotemRPValidationHitDistributions_files := $(patsubst src/TotemRPValidation/HitDistributions/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/HitDistributions/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationHitDistributions_LOC_USE := self  
PyTotemRPValidationHitDistributions_PACKAGE := self/src/TotemRPValidation/HitDistributions/python
ALL_PRODS += PyTotemRPValidationHitDistributions
PyTotemRPValidationHitDistributions_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/python,src_TotemRPValidation_HitDistributions_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_python
src_TotemRPValidation_HitDistributions_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_python,src/TotemRPValidation/HitDistributions/python,PYTHON))
