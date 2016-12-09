ifeq ($(strip $(PyConfigurationInfo)),)
PyConfigurationInfo := self/src/Configuration/Info/python
src_Configuration_Info_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/Info/python)
PyConfigurationInfo_files := $(patsubst src/Configuration/Info/python/%,%,$(wildcard $(foreach dir,src/Configuration/Info/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationInfo_LOC_USE := self  
PyConfigurationInfo_PACKAGE := self/src/Configuration/Info/python
ALL_PRODS += PyConfigurationInfo
PyConfigurationInfo_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationInfo,src/Configuration/Info/python,src_Configuration_Info_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationInfo,src/Configuration/Info/python))
endif
ALL_COMMONRULES += src_Configuration_Info_python
src_Configuration_Info_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_Info_python,src/Configuration/Info/python,PYTHON))
