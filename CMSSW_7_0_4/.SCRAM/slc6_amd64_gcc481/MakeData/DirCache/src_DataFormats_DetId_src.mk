ifeq ($(strip $(DataFormats/DetId)),)
ALL_COMMONRULES += src_DataFormats_DetId_src
src_DataFormats_DetId_src_parent := DataFormats/DetId
src_DataFormats_DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_DetId_src,src/DataFormats/DetId/src,LIBRARY))
DataFormatsDetId := self/DataFormats/DetId
DataFormats/DetId := DataFormatsDetId
DataFormatsDetId_files := $(patsubst src/DataFormats/DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsDetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/DetId/BuildFile
DataFormatsDetId_LOC_USE := self  boost rootrflx DataFormats/Common
DataFormatsDetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsDetIdCapabilities,DataFormatsDetId,$(SCRAMSTORENAME_LIB),src/DataFormats/DetId/src))
DataFormatsDetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsDetId,0,src/DataFormats/DetId/src/classes.h,src/DataFormats/DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsDetId_EX_LIB   := DataFormatsDetId
DataFormatsDetId_EX_USE   := $(foreach d,$(DataFormatsDetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsDetId_PACKAGE := self/src/DataFormats/DetId/src
ALL_PRODS += DataFormatsDetId
DataFormatsDetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsDetId,src/DataFormats/DetId/src,src_DataFormats_DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
