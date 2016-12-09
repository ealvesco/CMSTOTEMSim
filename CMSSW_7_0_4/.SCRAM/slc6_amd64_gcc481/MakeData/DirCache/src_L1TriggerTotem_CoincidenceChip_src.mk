ifeq ($(strip $(L1TriggerTotem/CoincidenceChip)),)
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_src
src_L1TriggerTotem_CoincidenceChip_src_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_src,src/L1TriggerTotem/CoincidenceChip/src,LIBRARY))
L1TriggerTotemCoincidenceChip := self/L1TriggerTotem/CoincidenceChip
L1TriggerTotem/CoincidenceChip := L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/src/%,%,$(wildcard $(foreach dir,src/L1TriggerTotem/CoincidenceChip/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
L1TriggerTotemCoincidenceChip_BuildFile    := $(WORKINGDIR)/cache/bf/src/L1TriggerTotem/CoincidenceChip/BuildFile
L1TriggerTotemCoincidenceChip_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet TotemRawDataLibrary/DataFormats DataFormats/TotemRPDetId rootgraphics rootcore root
L1TriggerTotemCoincidenceChip_PRE_INIT_FUNC += $$(eval $$(call RootDict,L1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/src, L1TriggerTotemCoincidenceChipLinkDef.h))
L1TriggerTotemCoincidenceChip_EX_LIB   := L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_EX_USE   := $(foreach d,$(L1TriggerTotemCoincidenceChip_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
L1TriggerTotemCoincidenceChip_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/src
ALL_PRODS += L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_INIT_FUNC        += $$(eval $$(call Library,L1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/src,src_L1TriggerTotem_CoincidenceChip_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
