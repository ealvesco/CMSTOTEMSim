ifeq ($(strip $(TotemRPValidation/ValidationTools)),)
ALL_COMMONRULES += src_TotemRPValidation_ValidationTools_src
src_TotemRPValidation_ValidationTools_src_parent := TotemRPValidation/ValidationTools
src_TotemRPValidation_ValidationTools_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationTools_src,src/TotemRPValidation/ValidationTools/src,LIBRARY))
TotemRPValidationValidationTools := self/TotemRPValidation/ValidationTools
TotemRPValidation/ValidationTools := TotemRPValidationValidationTools
TotemRPValidationValidationTools_files := $(patsubst src/TotemRPValidation/ValidationTools/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationTools/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationValidationTools_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationTools/BuildFile
TotemRPValidationValidationTools_LOC_USE := self  root rootcore
TotemRPValidationValidationTools_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemRPValidationValidationTools,src/TotemRPValidation/ValidationTools/src, TotemRPValidationValidationToolsLinkDef.h))
TotemRPValidationValidationTools_EX_LIB   := TotemRPValidationValidationTools
TotemRPValidationValidationTools_EX_USE   := $(foreach d,$(TotemRPValidationValidationTools_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationValidationTools_PACKAGE := self/src/TotemRPValidation/ValidationTools/src
ALL_PRODS += TotemRPValidationValidationTools
TotemRPValidationValidationTools_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationTools,src/TotemRPValidation/ValidationTools/src,src_TotemRPValidation_ValidationTools_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
