src_L1TriggerTotem_CoincidenceChip_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/L1TriggerTotem/CoincidenceChip/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_L1TriggerTotem_CoincidenceChip_scripts,src/L1TriggerTotem/CoincidenceChip/scripts,$(SCRAMSTORENAME_BIN),*))
