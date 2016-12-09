ifeq ($(strip $(DataFormats/T1RawData)),)
ALL_COMMONRULES += src_DataFormats_T1RawData_src
src_DataFormats_T1RawData_src_parent := DataFormats/T1RawData
src_DataFormats_T1RawData_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1RawData_src,src/DataFormats/T1RawData/src,LIBRARY))
DataFormatsT1RawData := self/DataFormats/T1RawData
DataFormats/T1RawData := DataFormatsT1RawData
DataFormatsT1RawData_files := $(patsubst src/DataFormats/T1RawData/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1RawData/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1RawData_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1RawData/BuildFile
DataFormatsT1RawData_LOC_USE := self  DataFormats/Common
DataFormatsT1RawData_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RawDataCapabilities,DataFormatsT1RawData,$(SCRAMSTORENAME_LIB),src/DataFormats/T1RawData/src))
DataFormatsT1RawData_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1RawData,0,src/DataFormats/T1RawData/src/classes.h,src/DataFormats/T1RawData/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1RawData_EX_LIB   := DataFormatsT1RawData
DataFormatsT1RawData_EX_USE   := $(foreach d,$(DataFormatsT1RawData_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1RawData_PACKAGE := self/src/DataFormats/T1RawData/src
ALL_PRODS += DataFormatsT1RawData
DataFormatsT1RawData_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1RawData,src/DataFormats/T1RawData/src,src_DataFormats_T1RawData_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
