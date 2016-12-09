ifeq ($(strip $(DataFormats/T1Road)),)
ALL_COMMONRULES += src_DataFormats_T1Road_src
src_DataFormats_T1Road_src_parent := DataFormats/T1Road
src_DataFormats_T1Road_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1Road_src,src/DataFormats/T1Road/src,LIBRARY))
DataFormatsT1Road := self/DataFormats/T1Road
DataFormats/T1Road := DataFormatsT1Road
DataFormatsT1Road_files := $(patsubst src/DataFormats/T1Road/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1Road/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1Road_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1Road/BuildFile
DataFormatsT1Road_LOC_USE := self  DataFormats/Common DataFormats/TrackingRecHit DataFormats/T1DetId rootrflx
DataFormatsT1Road_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RoadCapabilities,DataFormatsT1Road,$(SCRAMSTORENAME_LIB),src/DataFormats/T1Road/src))
DataFormatsT1Road_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1Road,0,src/DataFormats/T1Road/src/classes.h,src/DataFormats/T1Road/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1Road_EX_LIB   := DataFormatsT1Road
DataFormatsT1Road_EX_USE   := $(foreach d,$(DataFormatsT1Road_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1Road_PACKAGE := self/src/DataFormats/T1Road/src
ALL_PRODS += DataFormatsT1Road
DataFormatsT1Road_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1Road,src/DataFormats/T1Road/src,src_DataFormats_T1Road_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
