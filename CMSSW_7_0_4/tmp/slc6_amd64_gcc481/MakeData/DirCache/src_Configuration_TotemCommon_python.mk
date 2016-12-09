ifeq ($(strip $(PyConfigurationTotemCommon)),)
PyConfigurationTotemCommon := self/src/Configuration/TotemCommon/python
src_Configuration_TotemCommon_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemCommon/python)
PyConfigurationTotemCommon_files := $(patsubst src/Configuration/TotemCommon/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemCommon/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemCommon_LOC_USE := self  
PyConfigurationTotemCommon_PACKAGE := self/src/Configuration/TotemCommon/python
ALL_PRODS += PyConfigurationTotemCommon
PyConfigurationTotemCommon_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemCommon,src/Configuration/TotemCommon/python,src_Configuration_TotemCommon_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemCommon,src/Configuration/TotemCommon/python))
endif
ALL_COMMONRULES += src_Configuration_TotemCommon_python
src_Configuration_TotemCommon_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemCommon_python,src/Configuration/TotemCommon/python,PYTHON))
