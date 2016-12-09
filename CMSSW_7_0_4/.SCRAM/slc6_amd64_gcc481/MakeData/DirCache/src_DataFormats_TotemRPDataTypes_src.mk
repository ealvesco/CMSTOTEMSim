ifeq ($(strip $(DataFormats/TotemRPDataTypes)),)
ALL_COMMONRULES += src_DataFormats_TotemRPDataTypes_src
src_DataFormats_TotemRPDataTypes_src_parent := DataFormats/TotemRPDataTypes
src_DataFormats_TotemRPDataTypes_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemRPDataTypes_src,src/DataFormats/TotemRPDataTypes/src,LIBRARY))
DataFormatsTotemRPDataTypes := self/DataFormats/TotemRPDataTypes
DataFormats/TotemRPDataTypes := DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_files := $(patsubst src/DataFormats/TotemRPDataTypes/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemRPDataTypes/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemRPDataTypes_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemRPDataTypes/BuildFile
DataFormatsTotemRPDataTypes_LOC_USE := self  FWCore/Framework boost clhep root rootrflx DataFormats/Common DataFormats/GeometryVector
DataFormatsTotemRPDataTypes_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemRPDataTypesCapabilities,DataFormatsTotemRPDataTypes,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemRPDataTypes/src))
DataFormatsTotemRPDataTypes_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemRPDataTypes,0,src/DataFormats/TotemRPDataTypes/src/classes.h,src/DataFormats/TotemRPDataTypes/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemRPDataTypes_EX_LIB   := DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_EX_USE   := $(foreach d,$(DataFormatsTotemRPDataTypes_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemRPDataTypes_PACKAGE := self/src/DataFormats/TotemRPDataTypes/src
ALL_PRODS += DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemRPDataTypes,src/DataFormats/TotemRPDataTypes/src,src_DataFormats_TotemRPDataTypes_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
