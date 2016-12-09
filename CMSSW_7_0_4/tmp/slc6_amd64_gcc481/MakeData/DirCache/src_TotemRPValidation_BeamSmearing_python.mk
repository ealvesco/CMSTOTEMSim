ifeq ($(strip $(PyTotemRPValidationBeamSmearing)),)
PyTotemRPValidationBeamSmearing := self/src/TotemRPValidation/BeamSmearing/python
src_TotemRPValidation_BeamSmearing_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/BeamSmearing/python)
PyTotemRPValidationBeamSmearing_files := $(patsubst src/TotemRPValidation/BeamSmearing/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BeamSmearing/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationBeamSmearing_LOC_USE := self  
PyTotemRPValidationBeamSmearing_PACKAGE := self/src/TotemRPValidation/BeamSmearing/python
ALL_PRODS += PyTotemRPValidationBeamSmearing
PyTotemRPValidationBeamSmearing_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/python,src_TotemRPValidation_BeamSmearing_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_python
src_TotemRPValidation_BeamSmearing_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_python,src/TotemRPValidation/BeamSmearing/python,PYTHON))
