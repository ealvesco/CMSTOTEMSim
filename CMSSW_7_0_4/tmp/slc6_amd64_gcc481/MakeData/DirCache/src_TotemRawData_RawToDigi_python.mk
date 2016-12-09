ifeq ($(strip $(PyTotemRawDataRawToDigi)),)
PyTotemRawDataRawToDigi := self/src/TotemRawData/RawToDigi/python
src_TotemRawData_RawToDigi_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/RawToDigi/python)
PyTotemRawDataRawToDigi_files := $(patsubst src/TotemRawData/RawToDigi/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/RawToDigi/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataRawToDigi_LOC_USE := self  
PyTotemRawDataRawToDigi_PACKAGE := self/src/TotemRawData/RawToDigi/python
ALL_PRODS += PyTotemRawDataRawToDigi
PyTotemRawDataRawToDigi_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataRawToDigi,src/TotemRawData/RawToDigi/python,src_TotemRawData_RawToDigi_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataRawToDigi,src/TotemRawData/RawToDigi/python))
endif
ALL_COMMONRULES += src_TotemRawData_RawToDigi_python
src_TotemRawData_RawToDigi_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_python,src/TotemRawData/RawToDigi/python,PYTHON))
