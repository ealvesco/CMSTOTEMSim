ifeq ($(strip $(PrintRPAlignmentSummary)),)
PrintRPAlignmentSummary_files := $(patsubst src/TotemAlignment/RPDataFormats/bin/%,%,$(foreach file,PrintRPAlignmentSummary.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPDataFormats/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPDataFormats/bin/$(file). Please fix src/TotemAlignment/RPDataFormats/bin/BuildFile.))))
PrintRPAlignmentSummary := self/src/TotemAlignment/RPDataFormats/bin
PrintRPAlignmentSummary_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/bin/BuildFile
PrintRPAlignmentSummary_LOC_USE := self  TotemAlignment/RPDataFormats
PrintRPAlignmentSummary_PACKAGE := self/src/TotemAlignment/RPDataFormats/bin
ALL_PRODS += PrintRPAlignmentSummary
PrintRPAlignmentSummary_INIT_FUNC        += $$(eval $$(call Binary,PrintRPAlignmentSummary,src/TotemAlignment/RPDataFormats/bin,src_TotemAlignment_RPDataFormats_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,PrintRPAlignmentSummary,src/TotemAlignment/RPDataFormats/bin))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_bin
src_TotemAlignment_RPDataFormats_bin_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_bin,src/TotemAlignment/RPDataFormats/bin,BINARY))
