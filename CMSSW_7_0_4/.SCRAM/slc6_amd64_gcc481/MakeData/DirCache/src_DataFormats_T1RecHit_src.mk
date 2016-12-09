ifeq ($(strip $(DataFormats/T1RecHit)),)
ALL_COMMONRULES += src_DataFormats_T1RecHit_src
src_DataFormats_T1RecHit_src_parent := DataFormats/T1RecHit
src_DataFormats_T1RecHit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1RecHit_src,src/DataFormats/T1RecHit/src,LIBRARY))
DataFormatsT1RecHit := self/DataFormats/T1RecHit
DataFormats/T1RecHit := DataFormatsT1RecHit
DataFormatsT1RecHit_files := $(patsubst src/DataFormats/T1RecHit/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1RecHit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1RecHit/BuildFile
DataFormatsT1RecHit_LOC_USE := self  DataFormats/Common DataFormats/T1DetId DataFormats/TrackingRecHit rootrflx
DataFormatsT1RecHit_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RecHitCapabilities,DataFormatsT1RecHit,$(SCRAMSTORENAME_LIB),src/DataFormats/T1RecHit/src))
DataFormatsT1RecHit_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1RecHit,0,src/DataFormats/T1RecHit/src/classes.h,src/DataFormats/T1RecHit/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1RecHit_EX_LIB   := DataFormatsT1RecHit
DataFormatsT1RecHit_EX_USE   := $(foreach d,$(DataFormatsT1RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1RecHit_PACKAGE := self/src/DataFormats/T1RecHit/src
ALL_PRODS += DataFormatsT1RecHit
DataFormatsT1RecHit_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1RecHit,src/DataFormats/T1RecHit/src,src_DataFormats_T1RecHit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
