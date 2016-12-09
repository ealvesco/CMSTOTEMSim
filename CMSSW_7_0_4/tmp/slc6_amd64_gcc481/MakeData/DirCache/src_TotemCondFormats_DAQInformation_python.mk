ifeq ($(strip $(PyTotemCondFormatsDAQInformation)),)
PyTotemCondFormatsDAQInformation := self/src/TotemCondFormats/DAQInformation/python
src_TotemCondFormats_DAQInformation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemCondFormats/DAQInformation/python)
PyTotemCondFormatsDAQInformation_files := $(patsubst src/TotemCondFormats/DAQInformation/python/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DAQInformation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemCondFormatsDAQInformation_LOC_USE := self  
PyTotemCondFormatsDAQInformation_PACKAGE := self/src/TotemCondFormats/DAQInformation/python
ALL_PRODS += PyTotemCondFormatsDAQInformation
PyTotemCondFormatsDAQInformation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/python,src_TotemCondFormats_DAQInformation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/python))
endif
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_python
src_TotemCondFormats_DAQInformation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_python,src/TotemCondFormats/DAQInformation/python,PYTHON))
