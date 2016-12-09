ifeq ($(strip $(DataFormats/TotemRPDetId)),)
ALL_COMMONRULES += src_DataFormats_TotemRPDetId_src
src_DataFormats_TotemRPDetId_src_parent := DataFormats/TotemRPDetId
src_DataFormats_TotemRPDetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemRPDetId_src,src/DataFormats/TotemRPDetId/src,LIBRARY))
DataFormatsTotemRPDetId := self/DataFormats/TotemRPDetId
DataFormats/TotemRPDetId := DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_files := $(patsubst src/DataFormats/TotemRPDetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemRPDetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemRPDetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemRPDetId/BuildFile
DataFormatsTotemRPDetId_LOC_USE := self  DataFormats/DetId FWCore/Utilities rootrflx
DataFormatsTotemRPDetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemRPDetIdCapabilities,DataFormatsTotemRPDetId,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemRPDetId/src))
DataFormatsTotemRPDetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemRPDetId,0,src/DataFormats/TotemRPDetId/src/classes.h,src/DataFormats/TotemRPDetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemRPDetId_EX_LIB   := DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_EX_USE   := $(foreach d,$(DataFormatsTotemRPDetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemRPDetId_PACKAGE := self/src/DataFormats/TotemRPDetId/src
ALL_PRODS += DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemRPDetId,src/DataFormats/TotemRPDetId/src,src_DataFormats_TotemRPDetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
