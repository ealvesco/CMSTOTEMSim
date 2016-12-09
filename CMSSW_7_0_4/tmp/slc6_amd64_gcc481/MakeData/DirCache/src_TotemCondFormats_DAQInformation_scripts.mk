src_TotemCondFormats_DAQInformation_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemCondFormats/DAQInformation/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemCondFormats_DAQInformation_scripts,src/TotemCondFormats/DAQInformation/scripts,$(SCRAMSTORENAME_BIN),*))
