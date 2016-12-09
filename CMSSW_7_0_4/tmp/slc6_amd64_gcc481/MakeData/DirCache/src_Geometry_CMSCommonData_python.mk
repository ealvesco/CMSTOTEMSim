ifeq ($(strip $(PyGeometryCMSCommonData)),)
PyGeometryCMSCommonData := self/src/Geometry/CMSCommonData/python
src_Geometry_CMSCommonData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/CMSCommonData/python)
PyGeometryCMSCommonData_files := $(patsubst src/Geometry/CMSCommonData/python/%,%,$(wildcard $(foreach dir,src/Geometry/CMSCommonData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryCMSCommonData_LOC_USE := self  
PyGeometryCMSCommonData_PACKAGE := self/src/Geometry/CMSCommonData/python
ALL_PRODS += PyGeometryCMSCommonData
PyGeometryCMSCommonData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryCMSCommonData,src/Geometry/CMSCommonData/python,src_Geometry_CMSCommonData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryCMSCommonData,src/Geometry/CMSCommonData/python))
endif
ALL_COMMONRULES += src_Geometry_CMSCommonData_python
src_Geometry_CMSCommonData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_CMSCommonData_python,src/Geometry/CMSCommonData/python,PYTHON))
