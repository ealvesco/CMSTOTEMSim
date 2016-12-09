ifeq ($(strip $(PyTotemRawDataReaders)),)
PyTotemRawDataReaders := self/src/TotemRawData/Readers/python
src_TotemRawData_Readers_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/Readers/python)
PyTotemRawDataReaders_files := $(patsubst src/TotemRawData/Readers/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/Readers/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataReaders_LOC_USE := self  
PyTotemRawDataReaders_PACKAGE := self/src/TotemRawData/Readers/python
ALL_PRODS += PyTotemRawDataReaders
PyTotemRawDataReaders_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataReaders,src/TotemRawData/Readers/python,src_TotemRawData_Readers_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataReaders,src/TotemRawData/Readers/python))
endif
ALL_COMMONRULES += src_TotemRawData_Readers_python
src_TotemRawData_Readers_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_python,src/TotemRawData/Readers/python,PYTHON))
