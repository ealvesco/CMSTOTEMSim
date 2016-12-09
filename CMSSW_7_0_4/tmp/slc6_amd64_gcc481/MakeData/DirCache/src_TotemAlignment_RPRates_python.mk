ifeq ($(strip $(PyTotemAlignmentRPRates)),)
PyTotemAlignmentRPRates := self/src/TotemAlignment/RPRates/python
src_TotemAlignment_RPRates_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPRates/python)
PyTotemAlignmentRPRates_files := $(patsubst src/TotemAlignment/RPRates/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRates/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPRates_LOC_USE := self  
PyTotemAlignmentRPRates_PACKAGE := self/src/TotemAlignment/RPRates/python
ALL_PRODS += PyTotemAlignmentRPRates
PyTotemAlignmentRPRates_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPRates,src/TotemAlignment/RPRates/python,src_TotemAlignment_RPRates_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPRates,src/TotemAlignment/RPRates/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPRates_python
src_TotemAlignment_RPRates_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_python,src/TotemAlignment/RPRates/python,PYTHON))
