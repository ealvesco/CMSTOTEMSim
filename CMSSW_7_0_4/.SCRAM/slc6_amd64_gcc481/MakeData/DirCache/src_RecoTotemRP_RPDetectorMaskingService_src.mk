ifeq ($(strip $(RecoTotemRP/RPDetectorMaskingService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPDetectorMaskingService_src
src_RecoTotemRP_RPDetectorMaskingService_src_parent := RecoTotemRP/RPDetectorMaskingService
src_RecoTotemRP_RPDetectorMaskingService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDetectorMaskingService_src,src/RecoTotemRP/RPDetectorMaskingService/src,LIBRARY))
RecoTotemRPRPDetectorMaskingService := self/RecoTotemRP/RPDetectorMaskingService
RecoTotemRP/RPDetectorMaskingService := RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_files := $(patsubst src/RecoTotemRP/RPDetectorMaskingService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDetectorMaskingService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPDetectorMaskingService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPDetectorMaskingService/BuildFile
RecoTotemRPRPDetectorMaskingService_LOC_USE := self  clhep FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common Geometry/TotemRPDetTopology boost DataFormats/TotemRPDataTypes root rootrflx
RecoTotemRPRPDetectorMaskingService_EX_LIB   := RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_EX_USE   := $(foreach d,$(RecoTotemRPRPDetectorMaskingService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPDetectorMaskingService_PACKAGE := self/src/RecoTotemRP/RPDetectorMaskingService/src
ALL_PRODS += RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPDetectorMaskingService,src/RecoTotemRP/RPDetectorMaskingService/src,src_RecoTotemRP_RPDetectorMaskingService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
