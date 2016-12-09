ifeq ($(strip $(RecoTotemRP/RPRomanPotResolutionService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRomanPotResolutionService_src
src_RecoTotemRP_RPRomanPotResolutionService_src_parent := RecoTotemRP/RPRomanPotResolutionService
src_RecoTotemRP_RPRomanPotResolutionService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRomanPotResolutionService_src,src/RecoTotemRP/RPRomanPotResolutionService/src,LIBRARY))
RecoTotemRPRPRomanPotResolutionService := self/RecoTotemRP/RPRomanPotResolutionService
RecoTotemRP/RPRomanPotResolutionService := RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_files := $(patsubst src/RecoTotemRP/RPRomanPotResolutionService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRomanPotResolutionService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRomanPotResolutionService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRomanPotResolutionService/BuildFile
RecoTotemRPRPRomanPotResolutionService_LOC_USE := self  FWCore/Framework FWCore/MessageLogger RecoTotemRP/RPRecoDataFormats FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core
RecoTotemRPRPRomanPotResolutionService_EX_LIB   := RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_EX_USE   := $(foreach d,$(RecoTotemRPRPRomanPotResolutionService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPRomanPotResolutionService_PACKAGE := self/src/RecoTotemRP/RPRomanPotResolutionService/src
ALL_PRODS += RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRomanPotResolutionService,src/RecoTotemRP/RPRomanPotResolutionService/src,src_RecoTotemRP_RPRomanPotResolutionService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
