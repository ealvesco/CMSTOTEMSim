ifeq ($(strip $(PyTotemAlignmentRPDataFormats)),)
PyTotemAlignmentRPDataFormats := self/src/TotemAlignment/RPDataFormats/python
src_TotemAlignment_RPDataFormats_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPDataFormats/python)
PyTotemAlignmentRPDataFormats_files := $(patsubst src/TotemAlignment/RPDataFormats/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPDataFormats/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPDataFormats_LOC_USE := self  
PyTotemAlignmentRPDataFormats_PACKAGE := self/src/TotemAlignment/RPDataFormats/python
ALL_PRODS += PyTotemAlignmentRPDataFormats
PyTotemAlignmentRPDataFormats_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/python,src_TotemAlignment_RPDataFormats_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_python
src_TotemAlignment_RPDataFormats_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_python,src/TotemAlignment/RPDataFormats/python,PYTHON))
