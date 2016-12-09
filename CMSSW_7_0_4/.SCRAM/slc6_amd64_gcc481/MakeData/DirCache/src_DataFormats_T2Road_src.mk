ifeq ($(strip $(DataFormats/T2Road)),)
ALL_COMMONRULES += src_DataFormats_T2Road_src
src_DataFormats_T2Road_src_parent := DataFormats/T2Road
src_DataFormats_T2Road_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Road_src,src/DataFormats/T2Road/src,LIBRARY))
DataFormatsT2Road := self/DataFormats/T2Road
DataFormats/T2Road := DataFormatsT2Road
DataFormatsT2Road_files := $(patsubst src/DataFormats/T2Road/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Road/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Road_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Road/BuildFile
DataFormatsT2Road_LOC_USE := self  DataFormats/Common FWCore/Framework FWCore/MessageLogger DataFormats/T2Hit DataFormats/T2Cluster boost rootrflx
DataFormatsT2Road_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2RoadCapabilities,DataFormatsT2Road,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Road/src))
DataFormatsT2Road_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Road,0,src/DataFormats/T2Road/src/classes.h,src/DataFormats/T2Road/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Road_EX_LIB   := DataFormatsT2Road
DataFormatsT2Road_EX_USE   := $(foreach d,$(DataFormatsT2Road_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Road_PACKAGE := self/src/DataFormats/T2Road/src
ALL_PRODS += DataFormatsT2Road
DataFormatsT2Road_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Road,src/DataFormats/T2Road/src,src_DataFormats_T2Road_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
