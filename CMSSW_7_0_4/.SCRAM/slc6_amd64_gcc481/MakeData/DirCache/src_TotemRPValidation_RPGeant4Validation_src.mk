ifeq ($(strip $(TotemRPValidation/RPGeant4Validation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPGeant4Validation_src
src_TotemRPValidation_RPGeant4Validation_src_parent := TotemRPValidation/RPGeant4Validation
src_TotemRPValidation_RPGeant4Validation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPGeant4Validation_src,src/TotemRPValidation/RPGeant4Validation/src,LIBRARY))
TotemRPValidationRPGeant4Validation := self/TotemRPValidation/RPGeant4Validation
TotemRPValidation/RPGeant4Validation := TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_files := $(patsubst src/TotemRPValidation/RPGeant4Validation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPGeant4Validation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPGeant4Validation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPGeant4Validation/BuildFile
TotemRPValidationRPGeant4Validation_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses
TotemRPValidationRPGeant4Validation_EX_LIB   := TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_EX_USE   := $(foreach d,$(TotemRPValidationRPGeant4Validation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationRPGeant4Validation_PACKAGE := self/src/TotemRPValidation/RPGeant4Validation/src
ALL_PRODS += TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPGeant4Validation,src/TotemRPValidation/RPGeant4Validation/src,src_TotemRPValidation_RPGeant4Validation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
