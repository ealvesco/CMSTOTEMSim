ifeq ($(strip $(TotemRPValidation/EdgeEfficiency)),)
ALL_COMMONRULES += src_TotemRPValidation_EdgeEfficiency_src
src_TotemRPValidation_EdgeEfficiency_src_parent := TotemRPValidation/EdgeEfficiency
src_TotemRPValidation_EdgeEfficiency_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_EdgeEfficiency_src,src/TotemRPValidation/EdgeEfficiency/src,LIBRARY))
TotemRPValidationEdgeEfficiency := self/TotemRPValidation/EdgeEfficiency
TotemRPValidation/EdgeEfficiency := TotemRPValidationEdgeEfficiency
TotemRPValidationEdgeEfficiency_files := $(patsubst src/TotemRPValidation/EdgeEfficiency/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/EdgeEfficiency/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationEdgeEfficiency_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/EdgeEfficiency/BuildFile
TotemRPValidationEdgeEfficiency_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats Geometry/Records DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses root rootgraphics rootinteractive rootrflx
TotemRPValidationEdgeEfficiency_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationEdgeEfficiency,TotemRPValidationEdgeEfficiency,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/EdgeEfficiency/src))
TotemRPValidationEdgeEfficiency_PACKAGE := self/src/TotemRPValidation/EdgeEfficiency/src
ALL_PRODS += TotemRPValidationEdgeEfficiency
TotemRPValidationEdgeEfficiency_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/src,src_TotemRPValidation_EdgeEfficiency_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
