src_GeneratorInterface_CosmicRayInterface_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/GeneratorInterface/CosmicRayInterface/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_GeneratorInterface_CosmicRayInterface_scripts,src/GeneratorInterface/CosmicRayInterface/scripts,$(SCRAMSTORENAME_BIN),*))
