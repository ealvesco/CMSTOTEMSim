ifeq ($(strip $(PyGeometryTotemRPData)),)
PyGeometryTotemRPData := self/src/Geometry/TotemRPData/python
src_Geometry_TotemRPData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/TotemRPData/python)
PyGeometryTotemRPData_files := $(patsubst src/Geometry/TotemRPData/python/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryTotemRPData_LOC_USE := self  
PyGeometryTotemRPData_PACKAGE := self/src/Geometry/TotemRPData/python
ALL_PRODS += PyGeometryTotemRPData
PyGeometryTotemRPData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryTotemRPData,src/Geometry/TotemRPData/python,src_Geometry_TotemRPData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryTotemRPData,src/Geometry/TotemRPData/python))
endif
ALL_COMMONRULES += src_Geometry_TotemRPData_python
src_Geometry_TotemRPData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPData_python,src/Geometry/TotemRPData/python,PYTHON))
