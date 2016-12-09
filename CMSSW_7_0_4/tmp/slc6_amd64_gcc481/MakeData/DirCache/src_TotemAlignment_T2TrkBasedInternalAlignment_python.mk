ifeq ($(strip $(PyTotemAlignmentT2TrkBasedInternalAlignment)),)
PyTotemAlignmentT2TrkBasedInternalAlignment := self/src/TotemAlignment/T2TrkBasedInternalAlignment/python
src_TotemAlignment_T2TrkBasedInternalAlignment_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/T2TrkBasedInternalAlignment/python)
PyTotemAlignmentT2TrkBasedInternalAlignment_files := $(patsubst src/TotemAlignment/T2TrkBasedInternalAlignment/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T2TrkBasedInternalAlignment/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentT2TrkBasedInternalAlignment_LOC_USE := self  
PyTotemAlignmentT2TrkBasedInternalAlignment_PACKAGE := self/src/TotemAlignment/T2TrkBasedInternalAlignment/python
ALL_PRODS += PyTotemAlignmentT2TrkBasedInternalAlignment
PyTotemAlignmentT2TrkBasedInternalAlignment_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/python,src_TotemAlignment_T2TrkBasedInternalAlignment_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/python))
endif
ALL_COMMONRULES += src_TotemAlignment_T2TrkBasedInternalAlignment_python
src_TotemAlignment_T2TrkBasedInternalAlignment_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T2TrkBasedInternalAlignment_python,src/TotemAlignment/T2TrkBasedInternalAlignment/python,PYTHON))
