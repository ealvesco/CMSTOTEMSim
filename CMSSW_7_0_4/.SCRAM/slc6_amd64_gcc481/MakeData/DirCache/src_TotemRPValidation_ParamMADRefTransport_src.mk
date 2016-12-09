ifeq ($(strip $(TotemRPValidation/ParamMADRefTransport)),)
ALL_COMMONRULES += src_TotemRPValidation_ParamMADRefTransport_src
src_TotemRPValidation_ParamMADRefTransport_src_parent := TotemRPValidation/ParamMADRefTransport
src_TotemRPValidation_ParamMADRefTransport_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ParamMADRefTransport_src,src/TotemRPValidation/ParamMADRefTransport/src,LIBRARY))
TotemRPValidationParamMADRefTransport := self/TotemRPValidation/ParamMADRefTransport
TotemRPValidation/ParamMADRefTransport := TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_files := $(patsubst src/TotemRPValidation/ParamMADRefTransport/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ParamMADRefTransport/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationParamMADRefTransport_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ParamMADRefTransport/BuildFile
TotemRPValidationParamMADRefTransport_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar SimDataFormats/GeneratorProducts SimG4Core/Notification TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord rootminuit2
TotemRPValidationParamMADRefTransport_EX_LIB   := TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_EX_USE   := $(foreach d,$(TotemRPValidationParamMADRefTransport_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationParamMADRefTransport_PACKAGE := self/src/TotemRPValidation/ParamMADRefTransport/src
ALL_PRODS += TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationParamMADRefTransport,src/TotemRPValidation/ParamMADRefTransport/src,src_TotemRPValidation_ParamMADRefTransport_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
