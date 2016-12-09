ifeq ($(strip $(TotemRPValidation/ValidationPlots)),)
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_src
src_TotemRPValidation_ValidationPlots_src_parent := TotemRPValidation/ValidationPlots
src_TotemRPValidation_ValidationPlots_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_src,src/TotemRPValidation/ValidationPlots/src,LIBRARY))
TotemRPValidationValidationPlots := self/TotemRPValidation/ValidationPlots
TotemRPValidation/ValidationPlots := TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_files := $(patsubst src/TotemRPValidation/ValidationPlots/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationPlots/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationValidationPlots_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationPlots/BuildFile
TotemRPValidationValidationPlots_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats TotemRPValidation/ValidationTools root TotemRPValidation/ElasticReconstruction TotemRPValidation/HitDistributions boost
TotemRPValidationValidationPlots_EX_LIB   := TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_EX_USE   := $(foreach d,$(TotemRPValidationValidationPlots_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationValidationPlots_PACKAGE := self/src/TotemRPValidation/ValidationPlots/src
ALL_PRODS += TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/src,src_TotemRPValidation_ValidationPlots_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
