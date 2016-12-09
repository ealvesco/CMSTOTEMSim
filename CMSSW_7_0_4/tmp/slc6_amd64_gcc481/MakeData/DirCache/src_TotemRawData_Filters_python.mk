ifeq ($(strip $(PyTotemRawDataFilters)),)
PyTotemRawDataFilters := self/src/TotemRawData/Filters/python
src_TotemRawData_Filters_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/Filters/python)
PyTotemRawDataFilters_files := $(patsubst src/TotemRawData/Filters/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/Filters/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataFilters_LOC_USE := self  
PyTotemRawDataFilters_PACKAGE := self/src/TotemRawData/Filters/python
ALL_PRODS += PyTotemRawDataFilters
PyTotemRawDataFilters_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataFilters,src/TotemRawData/Filters/python,src_TotemRawData_Filters_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataFilters,src/TotemRawData/Filters/python))
endif
ALL_COMMONRULES += src_TotemRawData_Filters_python
src_TotemRawData_Filters_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Filters_python,src/TotemRawData/Filters/python,PYTHON))
