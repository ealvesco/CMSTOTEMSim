ifeq ($(strip $(DataFormats/TotemL1Trigger)),)
ALL_COMMONRULES += src_DataFormats_TotemL1Trigger_src
src_DataFormats_TotemL1Trigger_src_parent := DataFormats/TotemL1Trigger
src_DataFormats_TotemL1Trigger_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemL1Trigger_src,src/DataFormats/TotemL1Trigger/src,LIBRARY))
DataFormatsTotemL1Trigger := self/DataFormats/TotemL1Trigger
DataFormats/TotemL1Trigger := DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_files := $(patsubst src/DataFormats/TotemL1Trigger/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemL1Trigger/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemL1Trigger_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemL1Trigger/BuildFile
DataFormatsTotemL1Trigger_LOC_USE := self  DataFormats/DetId DataFormats/T2DetId DataFormats/Common FWCore/Framework FWCore/PluginManager FWCore/Utilities FWCore/MessageLogger rootrflx
DataFormatsTotemL1Trigger_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemL1TriggerCapabilities,DataFormatsTotemL1Trigger,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemL1Trigger/src))
DataFormatsTotemL1Trigger_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemL1Trigger,0,src/DataFormats/TotemL1Trigger/src/classes.h,src/DataFormats/TotemL1Trigger/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemL1Trigger_EX_LIB   := DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_EX_USE   := $(foreach d,$(DataFormatsTotemL1Trigger_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemL1Trigger_PACKAGE := self/src/DataFormats/TotemL1Trigger/src
ALL_PRODS += DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemL1Trigger,src/DataFormats/TotemL1Trigger/src,src_DataFormats_TotemL1Trigger_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
