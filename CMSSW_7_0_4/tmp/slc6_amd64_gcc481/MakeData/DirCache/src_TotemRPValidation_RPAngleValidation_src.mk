ifeq ($(strip $(TotemRPValidation/RPAngleValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPAngleValidation_src
src_TotemRPValidation_RPAngleValidation_src_parent := TotemRPValidation/RPAngleValidation
src_TotemRPValidation_RPAngleValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPAngleValidation_src,src/TotemRPValidation/RPAngleValidation/src,LIBRARY))
TotemRPValidationRPAngleValidation := self/TotemRPValidation/RPAngleValidation
TotemRPValidation/RPAngleValidation := TotemRPValidationRPAngleValidation
TotemRPValidationRPAngleValidation_files := $(patsubst src/TotemRPValidation/RPAngleValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPAngleValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPAngleValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPAngleValidation/BuildFile
TotemRPValidationRPAngleValidation_LOC_USE := self  FWCore/ParameterSet FWCore/Framework hepmc TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects RecoTotemRP/RPRomanPotResolutionService
TotemRPValidationRPAngleValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRPAngleValidation,TotemRPValidationRPAngleValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RPAngleValidation/src))
TotemRPValidationRPAngleValidation_PACKAGE := self/src/TotemRPValidation/RPAngleValidation/src
ALL_PRODS += TotemRPValidationRPAngleValidation
TotemRPValidationRPAngleValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/src,src_TotemRPValidation_RPAngleValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
