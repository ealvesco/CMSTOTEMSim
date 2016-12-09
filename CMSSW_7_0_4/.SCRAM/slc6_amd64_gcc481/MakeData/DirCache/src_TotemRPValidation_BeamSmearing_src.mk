ifeq ($(strip $(TotemRPValidation/BeamSmearing)),)
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_src
src_TotemRPValidation_BeamSmearing_src_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_src,src/TotemRPValidation/BeamSmearing/src,LIBRARY))
TotemRPValidationBeamSmearing := self/TotemRPValidation/BeamSmearing
TotemRPValidation/BeamSmearing := TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_files := $(patsubst src/TotemRPValidation/BeamSmearing/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BeamSmearing/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationBeamSmearing_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BeamSmearing/BuildFile
TotemRPValidationBeamSmearing_LOC_USE := self  FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationBeamSmearing_EX_LIB   := TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_EX_USE   := $(foreach d,$(TotemRPValidationBeamSmearing_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationBeamSmearing_PACKAGE := self/src/TotemRPValidation/BeamSmearing/src
ALL_PRODS += TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/src,src_TotemRPValidation_BeamSmearing_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
