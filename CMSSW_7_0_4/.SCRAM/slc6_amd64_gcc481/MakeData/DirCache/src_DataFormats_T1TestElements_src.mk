ifeq ($(strip $(DataFormats/T1TestElements)),)
ALL_COMMONRULES += src_DataFormats_T1TestElements_src
src_DataFormats_T1TestElements_src_parent := DataFormats/T1TestElements
src_DataFormats_T1TestElements_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1TestElements_src,src/DataFormats/T1TestElements/src,LIBRARY))
DataFormatsT1TestElements := self/DataFormats/T1TestElements
DataFormats/T1TestElements := DataFormatsT1TestElements
DataFormatsT1TestElements_files := $(patsubst src/DataFormats/T1TestElements/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1TestElements/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1TestElements_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1TestElements/BuildFile
DataFormatsT1TestElements_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1TestElements_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1TestElementsCapabilities,DataFormatsT1TestElements,$(SCRAMSTORENAME_LIB),src/DataFormats/T1TestElements/src))
DataFormatsT1TestElements_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1TestElements,0,src/DataFormats/T1TestElements/src/classes.h,src/DataFormats/T1TestElements/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1TestElements_EX_LIB   := DataFormatsT1TestElements
DataFormatsT1TestElements_EX_USE   := $(foreach d,$(DataFormatsT1TestElements_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1TestElements_PACKAGE := self/src/DataFormats/T1TestElements/src
ALL_PRODS += DataFormatsT1TestElements
DataFormatsT1TestElements_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1TestElements,src/DataFormats/T1TestElements/src,src_DataFormats_T1TestElements_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
