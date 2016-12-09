ifeq ($(strip $(DataFormats/T1DigiVfat)),)
ALL_COMMONRULES += src_DataFormats_T1DigiVfat_src
src_DataFormats_T1DigiVfat_src_parent := DataFormats/T1DigiVfat
src_DataFormats_T1DigiVfat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiVfat_src,src/DataFormats/T1DigiVfat/src,LIBRARY))
DataFormatsT1DigiVfat := self/DataFormats/T1DigiVfat
DataFormats/T1DigiVfat := DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_files := $(patsubst src/DataFormats/T1DigiVfat/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiVfat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiVfat_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiVfat/BuildFile
DataFormatsT1DigiVfat_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiVfat_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiVfatCapabilities,DataFormatsT1DigiVfat,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiVfat/src))
DataFormatsT1DigiVfat_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiVfat,0,src/DataFormats/T1DigiVfat/src/classes.h,src/DataFormats/T1DigiVfat/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiVfat_EX_LIB   := DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_EX_USE   := $(foreach d,$(DataFormatsT1DigiVfat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiVfat_PACKAGE := self/src/DataFormats/T1DigiVfat/src
ALL_PRODS += DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiVfat,src/DataFormats/T1DigiVfat/src,src_DataFormats_T1DigiVfat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
