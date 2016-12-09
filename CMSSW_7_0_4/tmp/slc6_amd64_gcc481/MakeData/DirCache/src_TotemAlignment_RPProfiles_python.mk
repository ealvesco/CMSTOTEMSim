ifeq ($(strip $(PyTotemAlignmentRPProfiles)),)
PyTotemAlignmentRPProfiles := self/src/TotemAlignment/RPProfiles/python
src_TotemAlignment_RPProfiles_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPProfiles/python)
PyTotemAlignmentRPProfiles_files := $(patsubst src/TotemAlignment/RPProfiles/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPProfiles/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPProfiles_LOC_USE := self  
PyTotemAlignmentRPProfiles_PACKAGE := self/src/TotemAlignment/RPProfiles/python
ALL_PRODS += PyTotemAlignmentRPProfiles
PyTotemAlignmentRPProfiles_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPProfiles,src/TotemAlignment/RPProfiles/python,src_TotemAlignment_RPProfiles_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPProfiles,src/TotemAlignment/RPProfiles/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPProfiles_python
src_TotemAlignment_RPProfiles_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_python,src/TotemAlignment/RPProfiles/python,PYTHON))
