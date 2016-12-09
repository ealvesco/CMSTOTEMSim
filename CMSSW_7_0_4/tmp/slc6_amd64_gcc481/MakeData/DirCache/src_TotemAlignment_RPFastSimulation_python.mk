ifeq ($(strip $(PyTotemAlignmentRPFastSimulation)),)
PyTotemAlignmentRPFastSimulation := self/src/TotemAlignment/RPFastSimulation/python
src_TotemAlignment_RPFastSimulation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPFastSimulation/python)
PyTotemAlignmentRPFastSimulation_files := $(patsubst src/TotemAlignment/RPFastSimulation/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPFastSimulation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPFastSimulation_LOC_USE := self  
PyTotemAlignmentRPFastSimulation_PACKAGE := self/src/TotemAlignment/RPFastSimulation/python
ALL_PRODS += PyTotemAlignmentRPFastSimulation
PyTotemAlignmentRPFastSimulation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/python,src_TotemAlignment_RPFastSimulation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_python
src_TotemAlignment_RPFastSimulation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_python,src/TotemAlignment/RPFastSimulation/python,PYTHON))
