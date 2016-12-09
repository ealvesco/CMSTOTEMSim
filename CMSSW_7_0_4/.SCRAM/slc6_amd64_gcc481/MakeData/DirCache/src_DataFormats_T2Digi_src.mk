ifeq ($(strip $(DataFormats/T2Digi)),)
ALL_COMMONRULES += src_DataFormats_T2Digi_src
src_DataFormats_T2Digi_src_parent := DataFormats/T2Digi
src_DataFormats_T2Digi_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Digi_src,src/DataFormats/T2Digi/src,LIBRARY))
DataFormatsT2Digi := self/DataFormats/T2Digi
DataFormats/T2Digi := DataFormatsT2Digi
DataFormatsT2Digi_files := $(patsubst src/DataFormats/T2Digi/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Digi/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Digi_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Digi/BuildFile
DataFormatsT2Digi_LOC_USE := self  FWCore/Framework FWCore/MessageLogger DataFormats/Common DataFormats/T2DetId boost rootrflx
DataFormatsT2Digi_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DigiCapabilities,DataFormatsT2Digi,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Digi/src))
DataFormatsT2Digi_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Digi,0,src/DataFormats/T2Digi/src/classes.h,src/DataFormats/T2Digi/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Digi_EX_LIB   := DataFormatsT2Digi
DataFormatsT2Digi_EX_USE   := $(foreach d,$(DataFormatsT2Digi_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Digi_PACKAGE := self/src/DataFormats/T2Digi/src
ALL_PRODS += DataFormatsT2Digi
DataFormatsT2Digi_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Digi,src/DataFormats/T2Digi/src,src_DataFormats_T2Digi_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
