ifeq ($(strip $(PyTotemRPValidationEdgeEfficiency)),)
PyTotemRPValidationEdgeEfficiency := self/src/TotemRPValidation/EdgeEfficiency/python
src_TotemRPValidation_EdgeEfficiency_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/EdgeEfficiency/python)
PyTotemRPValidationEdgeEfficiency_files := $(patsubst src/TotemRPValidation/EdgeEfficiency/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/EdgeEfficiency/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationEdgeEfficiency_LOC_USE := self  
PyTotemRPValidationEdgeEfficiency_PACKAGE := self/src/TotemRPValidation/EdgeEfficiency/python
ALL_PRODS += PyTotemRPValidationEdgeEfficiency
PyTotemRPValidationEdgeEfficiency_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/python,src_TotemRPValidation_EdgeEfficiency_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_EdgeEfficiency_python
src_TotemRPValidation_EdgeEfficiency_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_EdgeEfficiency_python,src/TotemRPValidation/EdgeEfficiency/python,PYTHON))
