ifeq ($(strip $(RecoTotemRP/RPInverseParameterization)),)
ALL_COMMONRULES += src_RecoTotemRP_RPInverseParameterization_src
src_RecoTotemRP_RPInverseParameterization_src_parent := RecoTotemRP/RPInverseParameterization
src_RecoTotemRP_RPInverseParameterization_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInverseParameterization_src,src/RecoTotemRP/RPInverseParameterization/src,LIBRARY))
RecoTotemRPRPInverseParameterization := self/RecoTotemRP/RPInverseParameterization
RecoTotemRP/RPInverseParameterization := RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_files := $(patsubst src/RecoTotemRP/RPInverseParameterization/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInverseParameterization/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPInverseParameterization_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPInverseParameterization/BuildFile
RecoTotemRPRPInverseParameterization_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord FWCore/Utilities rootminuit2
RecoTotemRPRPInverseParameterization_EX_LIB   := RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_EX_USE   := $(foreach d,$(RecoTotemRPRPInverseParameterization_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPInverseParameterization_PACKAGE := self/src/RecoTotemRP/RPInverseParameterization/src
ALL_PRODS += RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPInverseParameterization,src/RecoTotemRP/RPInverseParameterization/src,src_RecoTotemRP_RPInverseParameterization_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
