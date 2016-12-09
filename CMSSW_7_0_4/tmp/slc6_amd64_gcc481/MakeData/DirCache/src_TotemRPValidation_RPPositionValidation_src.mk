ifeq ($(strip $(TotemRPValidation/RPPositionValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPPositionValidation_src
src_TotemRPValidation_RPPositionValidation_src_parent := TotemRPValidation/RPPositionValidation
src_TotemRPValidation_RPPositionValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPPositionValidation_src,src/TotemRPValidation/RPPositionValidation/src,LIBRARY))
TotemRPValidationRPPositionValidation := self/TotemRPValidation/RPPositionValidation
TotemRPValidation/RPPositionValidation := TotemRPValidationRPPositionValidation
TotemRPValidationRPPositionValidation_files := $(patsubst src/TotemRPValidation/RPPositionValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPPositionValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPPositionValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPPositionValidation/BuildFile
TotemRPValidationRPPositionValidation_LOC_USE := self  FWCore/ParameterSet FWCore/Framework Geometry/TotemRPGeometryBuilder hepmc
TotemRPValidationRPPositionValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRPPositionValidation,TotemRPValidationRPPositionValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RPPositionValidation/src))
TotemRPValidationRPPositionValidation_PACKAGE := self/src/TotemRPValidation/RPPositionValidation/src
ALL_PRODS += TotemRPValidationRPPositionValidation
TotemRPValidationRPPositionValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/src,src_TotemRPValidation_RPPositionValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
