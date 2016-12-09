ifeq ($(strip $(PyConfigurationTotemOpticsConfiguration)),)
PyConfigurationTotemOpticsConfiguration := self/src/Configuration/TotemOpticsConfiguration/python
src_Configuration_TotemOpticsConfiguration_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemOpticsConfiguration/python)
PyConfigurationTotemOpticsConfiguration_files := $(patsubst src/Configuration/TotemOpticsConfiguration/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemOpticsConfiguration/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemOpticsConfiguration_LOC_USE := self  
PyConfigurationTotemOpticsConfiguration_PACKAGE := self/src/Configuration/TotemOpticsConfiguration/python
ALL_PRODS += PyConfigurationTotemOpticsConfiguration
PyConfigurationTotemOpticsConfiguration_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/python,src_Configuration_TotemOpticsConfiguration_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/python))
endif
ALL_COMMONRULES += src_Configuration_TotemOpticsConfiguration_python
src_Configuration_TotemOpticsConfiguration_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemOpticsConfiguration_python,src/Configuration/TotemOpticsConfiguration/python,PYTHON))
