ifeq ($(strip $(TotemRPValidation/TransportValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_src
src_TotemRPValidation_TransportValidation_src_parent := TotemRPValidation/TransportValidation
src_TotemRPValidation_TransportValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_src,src/TotemRPValidation/TransportValidation/src,LIBRARY))
TotemRPValidationTransportValidation := self/TotemRPValidation/TransportValidation
TotemRPValidation/TransportValidation := TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_files := $(patsubst src/TotemRPValidation/TransportValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/TransportValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationTransportValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/TransportValidation/BuildFile
TotemRPValidationTransportValidation_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords SimG4CMS/TotemRPProtTranspPar
TotemRPValidationTransportValidation_EX_LIB   := TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_EX_USE   := $(foreach d,$(TotemRPValidationTransportValidation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationTransportValidation_PACKAGE := self/src/TotemRPValidation/TransportValidation/src
ALL_PRODS += TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/src,src_TotemRPValidation_TransportValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
