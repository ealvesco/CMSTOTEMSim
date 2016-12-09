ifeq ($(strip $(PyGeometryForwardCommonData)),)
PyGeometryForwardCommonData := self/src/Geometry/ForwardCommonData/python
src_Geometry_ForwardCommonData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/ForwardCommonData/python)
PyGeometryForwardCommonData_files := $(patsubst src/Geometry/ForwardCommonData/python/%,%,$(wildcard $(foreach dir,src/Geometry/ForwardCommonData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryForwardCommonData_LOC_USE := self  
PyGeometryForwardCommonData_PACKAGE := self/src/Geometry/ForwardCommonData/python
ALL_PRODS += PyGeometryForwardCommonData
PyGeometryForwardCommonData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryForwardCommonData,src/Geometry/ForwardCommonData/python,src_Geometry_ForwardCommonData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryForwardCommonData,src/Geometry/ForwardCommonData/python))
endif
ALL_COMMONRULES += src_Geometry_ForwardCommonData_python
src_Geometry_ForwardCommonData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_ForwardCommonData_python,src/Geometry/ForwardCommonData/python,PYTHON))
