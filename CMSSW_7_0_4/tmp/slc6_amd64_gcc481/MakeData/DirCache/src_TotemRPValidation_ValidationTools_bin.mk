ifeq ($(strip $(ValidationTest)),)
ValidationTest_files := $(patsubst src/TotemRPValidation/ValidationTools/bin/%,%,$(foreach file,test.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ValidationTools/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ValidationTools/bin/$(file). Please fix src/TotemRPValidation/ValidationTools/bin/BuildFile.))))
ValidationTest := self/src/TotemRPValidation/ValidationTools/bin
ValidationTest_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationTools/bin/BuildFile
ValidationTest_LOC_USE := self  root TotemRPValidation/ValidationTools
ValidationTest_PACKAGE := self/src/TotemRPValidation/ValidationTools/bin
ALL_PRODS += ValidationTest
ValidationTest_INIT_FUNC        += $$(eval $$(call Binary,ValidationTest,src/TotemRPValidation/ValidationTools/bin,src_TotemRPValidation_ValidationTools_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ValidationTest,src/TotemRPValidation/ValidationTools/bin))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationTools_bin
src_TotemRPValidation_ValidationTools_bin_parent := TotemRPValidation/ValidationTools
src_TotemRPValidation_ValidationTools_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationTools_bin,src/TotemRPValidation/ValidationTools/bin,BINARY))
