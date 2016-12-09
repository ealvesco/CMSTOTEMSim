ifeq ($(strip $(PyL1TriggerTotemCoincidenceChip)),)
PyL1TriggerTotemCoincidenceChip := self/src/L1TriggerTotem/CoincidenceChip/python
src_L1TriggerTotem_CoincidenceChip_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/L1TriggerTotem/CoincidenceChip/python)
PyL1TriggerTotemCoincidenceChip_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/python/%,%,$(wildcard $(foreach dir,src/L1TriggerTotem/CoincidenceChip/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyL1TriggerTotemCoincidenceChip_LOC_USE := self  
PyL1TriggerTotemCoincidenceChip_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/python
ALL_PRODS += PyL1TriggerTotemCoincidenceChip
PyL1TriggerTotemCoincidenceChip_INIT_FUNC        += $$(eval $$(call PythonProduct,PyL1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/python,src_L1TriggerTotem_CoincidenceChip_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyL1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/python))
endif
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_python
src_L1TriggerTotem_CoincidenceChip_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_python,src/L1TriggerTotem/CoincidenceChip/python,PYTHON))
