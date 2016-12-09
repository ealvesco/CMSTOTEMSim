ifeq ($(strip $(DataFormats/T1DigiWire)),)
ALL_COMMONRULES += src_DataFormats_T1DigiWire_src
src_DataFormats_T1DigiWire_src_parent := DataFormats/T1DigiWire
src_DataFormats_T1DigiWire_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiWire_src,src/DataFormats/T1DigiWire/src,LIBRARY))
DataFormatsT1DigiWire := self/DataFormats/T1DigiWire
DataFormats/T1DigiWire := DataFormatsT1DigiWire
DataFormatsT1DigiWire_files := $(patsubst src/DataFormats/T1DigiWire/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiWire/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiWire_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiWire/BuildFile
DataFormatsT1DigiWire_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiWire_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiWireCapabilities,DataFormatsT1DigiWire,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiWire/src))
DataFormatsT1DigiWire_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiWire,0,src/DataFormats/T1DigiWire/src/classes.h,src/DataFormats/T1DigiWire/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiWire_EX_LIB   := DataFormatsT1DigiWire
DataFormatsT1DigiWire_EX_USE   := $(foreach d,$(DataFormatsT1DigiWire_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiWire_PACKAGE := self/src/DataFormats/T1DigiWire/src
ALL_PRODS += DataFormatsT1DigiWire
DataFormatsT1DigiWire_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiWire,src/DataFormats/T1DigiWire/src,src_DataFormats_T1DigiWire_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
