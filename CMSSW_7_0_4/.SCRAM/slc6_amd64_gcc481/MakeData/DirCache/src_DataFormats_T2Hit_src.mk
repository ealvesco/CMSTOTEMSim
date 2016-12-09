ifeq ($(strip $(DataFormats/T2Hit)),)
ALL_COMMONRULES += src_DataFormats_T2Hit_src
src_DataFormats_T2Hit_src_parent := DataFormats/T2Hit
src_DataFormats_T2Hit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Hit_src,src/DataFormats/T2Hit/src,LIBRARY))
DataFormatsT2Hit := self/DataFormats/T2Hit
DataFormats/T2Hit := DataFormatsT2Hit
DataFormatsT2Hit_files := $(patsubst src/DataFormats/T2Hit/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Hit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Hit_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Hit/BuildFile
DataFormatsT2Hit_LOC_USE := self  FWCore/Framework FWCore/MessageLogger DataFormats/Common DataFormats/T2DetId DataFormats/T2Cluster boost rootrflx
DataFormatsT2Hit_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2HitCapabilities,DataFormatsT2Hit,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Hit/src))
DataFormatsT2Hit_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Hit,0,src/DataFormats/T2Hit/src/classes.h,src/DataFormats/T2Hit/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Hit_EX_LIB   := DataFormatsT2Hit
DataFormatsT2Hit_EX_USE   := $(foreach d,$(DataFormatsT2Hit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Hit_PACKAGE := self/src/DataFormats/T2Hit/src
ALL_PRODS += DataFormatsT2Hit
DataFormatsT2Hit_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Hit,src/DataFormats/T2Hit/src,src_DataFormats_T2Hit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
