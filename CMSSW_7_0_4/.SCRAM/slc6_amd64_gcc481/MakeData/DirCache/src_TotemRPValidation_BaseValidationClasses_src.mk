ifeq ($(strip $(TotemRPValidation/BaseValidationClasses)),)
ALL_COMMONRULES += src_TotemRPValidation_BaseValidationClasses_src
src_TotemRPValidation_BaseValidationClasses_src_parent := TotemRPValidation/BaseValidationClasses
src_TotemRPValidation_BaseValidationClasses_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_BaseValidationClasses_src,src/TotemRPValidation/BaseValidationClasses/src,LIBRARY))
TotemRPValidationBaseValidationClasses := self/TotemRPValidation/BaseValidationClasses
TotemRPValidation/BaseValidationClasses := TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_files := $(patsubst src/TotemRPValidation/BaseValidationClasses/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BaseValidationClasses/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationBaseValidationClasses_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BaseValidationClasses/BuildFile
TotemRPValidationBaseValidationClasses_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology
TotemRPValidationBaseValidationClasses_EX_LIB   := TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_EX_USE   := $(foreach d,$(TotemRPValidationBaseValidationClasses_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationBaseValidationClasses_PACKAGE := self/src/TotemRPValidation/BaseValidationClasses/src
ALL_PRODS += TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBaseValidationClasses,src/TotemRPValidation/BaseValidationClasses/src,src_TotemRPValidation_BaseValidationClasses_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
