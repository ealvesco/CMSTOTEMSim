ifeq ($(strip $(PyTotemAlignmentT1Alignment)),)
PyTotemAlignmentT1Alignment := self/src/TotemAlignment/T1Alignment/python
src_TotemAlignment_T1Alignment_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/T1Alignment/python)
PyTotemAlignmentT1Alignment_files := $(patsubst src/TotemAlignment/T1Alignment/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T1Alignment/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentT1Alignment_LOC_USE := self  
PyTotemAlignmentT1Alignment_PACKAGE := self/src/TotemAlignment/T1Alignment/python
ALL_PRODS += PyTotemAlignmentT1Alignment
PyTotemAlignmentT1Alignment_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/python,src_TotemAlignment_T1Alignment_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/python))
endif
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_python
src_TotemAlignment_T1Alignment_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_python,src/TotemAlignment/T1Alignment/python,PYTHON))
