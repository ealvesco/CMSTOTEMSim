ifeq ($(strip $(DataFormats/T1Digi)),)
ALL_COMMONRULES += src_DataFormats_T1Digi_src
src_DataFormats_T1Digi_src_parent := DataFormats/T1Digi
src_DataFormats_T1Digi_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1Digi_src,src/DataFormats/T1Digi/src,LIBRARY))
DataFormatsT1Digi := self/DataFormats/T1Digi
DataFormats/T1Digi := DataFormatsT1Digi
DataFormatsT1Digi_files := $(patsubst src/DataFormats/T1Digi/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1Digi/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1Digi_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1Digi/BuildFile
DataFormatsT1Digi_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1Digi_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiCapabilities,DataFormatsT1Digi,$(SCRAMSTORENAME_LIB),src/DataFormats/T1Digi/src))
DataFormatsT1Digi_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1Digi,0,src/DataFormats/T1Digi/src/classes.h,src/DataFormats/T1Digi/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1Digi_EX_LIB   := DataFormatsT1Digi
DataFormatsT1Digi_EX_USE   := $(foreach d,$(DataFormatsT1Digi_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1Digi_PACKAGE := self/src/DataFormats/T1Digi/src
ALL_PRODS += DataFormatsT1Digi
DataFormatsT1Digi_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1Digi,src/DataFormats/T1Digi/src,src_DataFormats_T1Digi_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
