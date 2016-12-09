ifeq ($(strip $(DataFormats/T2DetId)),)
ALL_COMMONRULES += src_DataFormats_T2DetId_src
src_DataFormats_T2DetId_src_parent := DataFormats/T2DetId
src_DataFormats_T2DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2DetId_src,src/DataFormats/T2DetId/src,LIBRARY))
DataFormatsT2DetId := self/DataFormats/T2DetId
DataFormats/T2DetId := DataFormatsT2DetId
DataFormatsT2DetId_files := $(patsubst src/DataFormats/T2DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2DetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2DetId/BuildFile
DataFormatsT2DetId_LOC_USE := self  DataFormats/DetId FWCore/Utilities boost rootrflx
DataFormatsT2DetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DetIdCapabilities,DataFormatsT2DetId,$(SCRAMSTORENAME_LIB),src/DataFormats/T2DetId/src))
DataFormatsT2DetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2DetId,0,src/DataFormats/T2DetId/src/classes.h,src/DataFormats/T2DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2DetId_EX_LIB   := DataFormatsT2DetId
DataFormatsT2DetId_EX_USE   := $(foreach d,$(DataFormatsT2DetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2DetId_PACKAGE := self/src/DataFormats/T2DetId/src
ALL_PRODS += DataFormatsT2DetId
DataFormatsT2DetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2DetId,src/DataFormats/T2DetId/src,src_DataFormats_T2DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
