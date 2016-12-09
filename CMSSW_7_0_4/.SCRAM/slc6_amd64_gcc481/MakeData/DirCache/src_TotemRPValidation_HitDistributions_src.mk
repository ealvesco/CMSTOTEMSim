ifeq ($(strip $(TotemRPValidation/HitDistributions)),)
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_src
src_TotemRPValidation_HitDistributions_src_parent := TotemRPValidation/HitDistributions
src_TotemRPValidation_HitDistributions_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_src,src/TotemRPValidation/HitDistributions/src,LIBRARY))
TotemRPValidationHitDistributions := self/TotemRPValidation/HitDistributions
TotemRPValidation/HitDistributions := TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_files := $(patsubst src/TotemRPValidation/HitDistributions/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/HitDistributions/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationHitDistributions_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/HitDistributions/BuildFile
TotemRPValidationHitDistributions_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root rootgraphics boost DataFormats/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords
TotemRPValidationHitDistributions_EX_LIB   := TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_EX_USE   := $(foreach d,$(TotemRPValidationHitDistributions_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationHitDistributions_PACKAGE := self/src/TotemRPValidation/HitDistributions/src
ALL_PRODS += TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/src,src_TotemRPValidation_HitDistributions_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
