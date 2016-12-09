ifeq ($(strip $(PyTotemRPValidationTransportValidation)),)
PyTotemRPValidationTransportValidation := self/src/TotemRPValidation/TransportValidation/python
src_TotemRPValidation_TransportValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/TransportValidation/python)
PyTotemRPValidationTransportValidation_files := $(patsubst src/TotemRPValidation/TransportValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/TransportValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationTransportValidation_LOC_USE := self  
PyTotemRPValidationTransportValidation_PACKAGE := self/src/TotemRPValidation/TransportValidation/python
ALL_PRODS += PyTotemRPValidationTransportValidation
PyTotemRPValidationTransportValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/python,src_TotemRPValidation_TransportValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_python
src_TotemRPValidation_TransportValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_python,src/TotemRPValidation/TransportValidation/python,PYTHON))
