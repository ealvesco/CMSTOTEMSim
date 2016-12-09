ifeq ($(strip $(PyTotemAlignmentRPTrackBased)),)
PyTotemAlignmentRPTrackBased := self/src/TotemAlignment/RPTrackBased/python
src_TotemAlignment_RPTrackBased_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPTrackBased/python)
PyTotemAlignmentRPTrackBased_files := $(patsubst src/TotemAlignment/RPTrackBased/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPTrackBased/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPTrackBased_LOC_USE := self  
PyTotemAlignmentRPTrackBased_PACKAGE := self/src/TotemAlignment/RPTrackBased/python
ALL_PRODS += PyTotemAlignmentRPTrackBased
PyTotemAlignmentRPTrackBased_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/python,src_TotemAlignment_RPTrackBased_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_python
src_TotemAlignment_RPTrackBased_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_python,src/TotemAlignment/RPTrackBased/python,PYTHON))
