ifeq ($(strip $(DataFormats/T1T2Track)),)
ALL_COMMONRULES += src_DataFormats_T1T2Track_src
src_DataFormats_T1T2Track_src_parent := DataFormats/T1T2Track
src_DataFormats_T1T2Track_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1T2Track_src,src/DataFormats/T1T2Track/src,LIBRARY))
DataFormatsT1T2Track := self/DataFormats/T1T2Track
DataFormats/T1T2Track := DataFormatsT1T2Track
DataFormatsT1T2Track_files := $(patsubst src/DataFormats/T1T2Track/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1T2Track/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1T2Track_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1T2Track/BuildFile
DataFormatsT1T2Track_LOC_USE := self  FWCore/Framework DataFormats/Common boost FWCore/Utilities DataFormats/TrackingRecHit DataFormats/T1Road DataFormats/T2Hit DataFormats/T2Road rootrflx root clhep
DataFormatsT1T2Track_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1T2TrackCapabilities,DataFormatsT1T2Track,$(SCRAMSTORENAME_LIB),src/DataFormats/T1T2Track/src))
DataFormatsT1T2Track_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1T2Track,0,src/DataFormats/T1T2Track/src/classes.h,src/DataFormats/T1T2Track/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1T2Track_EX_LIB   := DataFormatsT1T2Track
DataFormatsT1T2Track_EX_USE   := $(foreach d,$(DataFormatsT1T2Track_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1T2Track_PACKAGE := self/src/DataFormats/T1T2Track/src
ALL_PRODS += DataFormatsT1T2Track
DataFormatsT1T2Track_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1T2Track,src/DataFormats/T1T2Track/src,src_DataFormats_T1T2Track_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
