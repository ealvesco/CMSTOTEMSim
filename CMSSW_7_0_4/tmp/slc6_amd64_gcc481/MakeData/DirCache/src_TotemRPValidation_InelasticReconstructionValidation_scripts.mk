src_TotemRPValidation_InelasticReconstructionValidation_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemRPValidation/InelasticReconstructionValidation/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemRPValidation_InelasticReconstructionValidation_scripts,src/TotemRPValidation/InelasticReconstructionValidation/scripts,$(SCRAMSTORENAME_BIN),*))
