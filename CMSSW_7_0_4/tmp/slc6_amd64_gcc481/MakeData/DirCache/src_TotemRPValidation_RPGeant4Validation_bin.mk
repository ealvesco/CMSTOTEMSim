ifeq ($(strip $(RPGeant4Validate)),)
RPGeant4Validate_files := $(patsubst src/TotemRPValidation/RPGeant4Validation/bin/%,%,$(foreach file,RPGeant4Validate.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/RPGeant4Validation/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/RPGeant4Validation/bin/$(file). Please fix src/TotemRPValidation/RPGeant4Validation/bin/BuildFile.))))
RPGeant4Validate := self/src/TotemRPValidation/RPGeant4Validation/bin
RPGeant4Validate_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPGeant4Validation/bin/BuildFile
RPGeant4Validate_LOC_USE := self  TotemRPValidation/RPGeant4Validation
RPGeant4Validate_PACKAGE := self/src/TotemRPValidation/RPGeant4Validation/bin
ALL_PRODS += RPGeant4Validate
RPGeant4Validate_INIT_FUNC        += $$(eval $$(call Binary,RPGeant4Validate,src/TotemRPValidation/RPGeant4Validation/bin,src_TotemRPValidation_RPGeant4Validation_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RPGeant4Validate,src/TotemRPValidation/RPGeant4Validation/bin))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPGeant4Validation_bin
src_TotemRPValidation_RPGeant4Validation_bin_parent := TotemRPValidation/RPGeant4Validation
src_TotemRPValidation_RPGeant4Validation_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPGeant4Validation_bin,src/TotemRPValidation/RPGeant4Validation/bin,BINARY))
