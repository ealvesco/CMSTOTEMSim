ifeq ($(strip $(PyTotemT1T2ValidationT2RecoValidation)),)
PyTotemT1T2ValidationT2RecoValidation := self/src/TotemT1T2Validation/T2RecoValidation/python
src_TotemT1T2Validation_T2RecoValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2RecoValidation/python)
PyTotemT1T2ValidationT2RecoValidation_files := $(patsubst src/TotemT1T2Validation/T2RecoValidation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2RecoValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2RecoValidation_LOC_USE := self  
PyTotemT1T2ValidationT2RecoValidation_PACKAGE := self/src/TotemT1T2Validation/T2RecoValidation/python
ALL_PRODS += PyTotemT1T2ValidationT2RecoValidation
PyTotemT1T2ValidationT2RecoValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/python,src_TotemT1T2Validation_T2RecoValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2RecoValidation_python
src_TotemT1T2Validation_T2RecoValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2RecoValidation_python,src/TotemT1T2Validation/T2RecoValidation/python,PYTHON))
