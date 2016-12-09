ifeq ($(strip $(PyConfigurationCMSTotemStandardSequences)),)
PyConfigurationCMSTotemStandardSequences := self/src/Configuration/CMSTotemStandardSequences/python
src_Configuration_CMSTotemStandardSequences_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/CMSTotemStandardSequences/python)
PyConfigurationCMSTotemStandardSequences_files := $(patsubst src/Configuration/CMSTotemStandardSequences/python/%,%,$(wildcard $(foreach dir,src/Configuration/CMSTotemStandardSequences/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationCMSTotemStandardSequences_LOC_USE := self  
PyConfigurationCMSTotemStandardSequences_PACKAGE := self/src/Configuration/CMSTotemStandardSequences/python
ALL_PRODS += PyConfigurationCMSTotemStandardSequences
PyConfigurationCMSTotemStandardSequences_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationCMSTotemStandardSequences,src/Configuration/CMSTotemStandardSequences/python,src_Configuration_CMSTotemStandardSequences_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationCMSTotemStandardSequences,src/Configuration/CMSTotemStandardSequences/python))
endif
ALL_COMMONRULES += src_Configuration_CMSTotemStandardSequences_python
src_Configuration_CMSTotemStandardSequences_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_CMSTotemStandardSequences_python,src/Configuration/CMSTotemStandardSequences/python,PYTHON))
