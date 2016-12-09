ifeq ($(strip $(DataFormats/T1DigiSantiard)),)
ALL_COMMONRULES += src_DataFormats_T1DigiSantiard_src
src_DataFormats_T1DigiSantiard_src_parent := DataFormats/T1DigiSantiard
src_DataFormats_T1DigiSantiard_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiSantiard_src,src/DataFormats/T1DigiSantiard/src,LIBRARY))
DataFormatsT1DigiSantiard := self/DataFormats/T1DigiSantiard
DataFormats/T1DigiSantiard := DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_files := $(patsubst src/DataFormats/T1DigiSantiard/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiSantiard/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiSantiard_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiSantiard/BuildFile
DataFormatsT1DigiSantiard_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiSantiard_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiSantiardCapabilities,DataFormatsT1DigiSantiard,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiSantiard/src))
DataFormatsT1DigiSantiard_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiSantiard,0,src/DataFormats/T1DigiSantiard/src/classes.h,src/DataFormats/T1DigiSantiard/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiSantiard_EX_LIB   := DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_EX_USE   := $(foreach d,$(DataFormatsT1DigiSantiard_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiSantiard_PACKAGE := self/src/DataFormats/T1DigiSantiard/src
ALL_PRODS += DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiSantiard,src/DataFormats/T1DigiSantiard/src,src_DataFormats_T1DigiSantiard_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
