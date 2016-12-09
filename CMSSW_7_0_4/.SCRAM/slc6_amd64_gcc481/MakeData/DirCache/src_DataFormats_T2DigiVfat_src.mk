ifeq ($(strip $(DataFormats/T2DigiVfat)),)
ALL_COMMONRULES += src_DataFormats_T2DigiVfat_src
src_DataFormats_T2DigiVfat_src_parent := DataFormats/T2DigiVfat
src_DataFormats_T2DigiVfat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2DigiVfat_src,src/DataFormats/T2DigiVfat/src,LIBRARY))
DataFormatsT2DigiVfat := self/DataFormats/T2DigiVfat
DataFormats/T2DigiVfat := DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_files := $(patsubst src/DataFormats/T2DigiVfat/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2DigiVfat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2DigiVfat_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2DigiVfat/BuildFile
DataFormatsT2DigiVfat_LOC_USE := self  DataFormats/Common DataFormats/T2DetId
DataFormatsT2DigiVfat_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DigiVfatCapabilities,DataFormatsT2DigiVfat,$(SCRAMSTORENAME_LIB),src/DataFormats/T2DigiVfat/src))
DataFormatsT2DigiVfat_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2DigiVfat,0,src/DataFormats/T2DigiVfat/src/classes.h,src/DataFormats/T2DigiVfat/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2DigiVfat_EX_LIB   := DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_EX_USE   := $(foreach d,$(DataFormatsT2DigiVfat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2DigiVfat_PACKAGE := self/src/DataFormats/T2DigiVfat/src
ALL_PRODS += DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2DigiVfat,src/DataFormats/T2DigiVfat/src,src_DataFormats_T2DigiVfat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
