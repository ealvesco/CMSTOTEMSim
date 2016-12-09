ifeq ($(strip $(PyGeometryTotemRPGeometryBuilder)),)
PyGeometryTotemRPGeometryBuilder := self/src/Geometry/TotemRPGeometryBuilder/python
src_Geometry_TotemRPGeometryBuilder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/TotemRPGeometryBuilder/python)
PyGeometryTotemRPGeometryBuilder_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/python/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPGeometryBuilder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryTotemRPGeometryBuilder_LOC_USE := self  
PyGeometryTotemRPGeometryBuilder_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/python
ALL_PRODS += PyGeometryTotemRPGeometryBuilder
PyGeometryTotemRPGeometryBuilder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/python,src_Geometry_TotemRPGeometryBuilder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/python))
endif
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_python
src_Geometry_TotemRPGeometryBuilder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_python,src/Geometry/TotemRPGeometryBuilder/python,PYTHON))
