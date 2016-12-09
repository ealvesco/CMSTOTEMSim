ifeq ($(strip $(PyConfigurationTotemStandardSequences)),)
PyConfigurationTotemStandardSequences := self/src/Configuration/TotemStandardSequences/python
src_Configuration_TotemStandardSequences_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemStandardSequences/python)
PyConfigurationTotemStandardSequences_files := $(patsubst src/Configuration/TotemStandardSequences/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemStandardSequences/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemStandardSequences_LOC_USE := self  
PyConfigurationTotemStandardSequences_PACKAGE := self/src/Configuration/TotemStandardSequences/python
ALL_PRODS += PyConfigurationTotemStandardSequences
PyConfigurationTotemStandardSequences_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemStandardSequences,src/Configuration/TotemStandardSequences/python,src_Configuration_TotemStandardSequences_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemStandardSequences,src/Configuration/TotemStandardSequences/python))
endif
ALL_COMMONRULES += src_Configuration_TotemStandardSequences_python
src_Configuration_TotemStandardSequences_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemStandardSequences_python,src/Configuration/TotemStandardSequences/python,PYTHON))
