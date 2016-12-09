ifeq ($(strip $(PyTotemCondFormatsProtonTransportFunctions)),)
PyTotemCondFormatsProtonTransportFunctions := self/src/TotemCondFormats/ProtonTransportFunctions/python
src_TotemCondFormats_ProtonTransportFunctions_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemCondFormats/ProtonTransportFunctions/python)
PyTotemCondFormatsProtonTransportFunctions_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/python/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/ProtonTransportFunctions/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemCondFormatsProtonTransportFunctions_LOC_USE := self  
PyTotemCondFormatsProtonTransportFunctions_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/python
ALL_PRODS += PyTotemCondFormatsProtonTransportFunctions
PyTotemCondFormatsProtonTransportFunctions_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/python,src_TotemCondFormats_ProtonTransportFunctions_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/python))
endif
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_python
src_TotemCondFormats_ProtonTransportFunctions_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_python,src/TotemCondFormats/ProtonTransportFunctions/python,PYTHON))
