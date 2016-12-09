ifeq ($(strip $(DataFormats/T1DetId)),)
ALL_COMMONRULES += src_DataFormats_T1DetId_src
src_DataFormats_T1DetId_src_parent := DataFormats/T1DetId
src_DataFormats_T1DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DetId_src,src/DataFormats/T1DetId/src,LIBRARY))
DataFormatsT1DetId := self/DataFormats/T1DetId
DataFormats/T1DetId := DataFormatsT1DetId
DataFormatsT1DetId_files := $(patsubst src/DataFormats/T1DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DetId/BuildFile
DataFormatsT1DetId_LOC_USE := self  DataFormats/Common DataFormats/DetId FWCore/Utilities boost rootrflx
DataFormatsT1DetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DetIdCapabilities,DataFormatsT1DetId,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DetId/src))
DataFormatsT1DetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DetId,0,src/DataFormats/T1DetId/src/classes.h,src/DataFormats/T1DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DetId_EX_LIB   := DataFormatsT1DetId
DataFormatsT1DetId_EX_USE   := $(foreach d,$(DataFormatsT1DetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DetId_PACKAGE := self/src/DataFormats/T1DetId/src
ALL_PRODS += DataFormatsT1DetId
DataFormatsT1DetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DetId,src/DataFormats/T1DetId/src,src_DataFormats_T1DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
