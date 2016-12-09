ifeq ($(strip $(PyTotemRPValidationElasticReconstruction)),)
PyTotemRPValidationElasticReconstruction := self/src/TotemRPValidation/ElasticReconstruction/python
src_TotemRPValidation_ElasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/ElasticReconstruction/python)
PyTotemRPValidationElasticReconstruction_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ElasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationElasticReconstruction_LOC_USE := self  
PyTotemRPValidationElasticReconstruction_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/python
ALL_PRODS += PyTotemRPValidationElasticReconstruction
PyTotemRPValidationElasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/python,src_TotemRPValidation_ElasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_python
src_TotemRPValidation_ElasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_python,src/TotemRPValidation/ElasticReconstruction/python,PYTHON))
