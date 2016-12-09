src_TotemDQMLite_GUI_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemDQMLite/GUI/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemDQMLite_GUI_scripts,src/TotemDQMLite/GUI/scripts,$(SCRAMSTORENAME_BIN),*))
