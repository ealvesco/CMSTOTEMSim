ifeq ($(strip $(RecoTotemRP/RPClusterSigmaService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_src
src_RecoTotemRP_RPClusterSigmaService_src_parent := RecoTotemRP/RPClusterSigmaService
src_RecoTotemRP_RPClusterSigmaService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_src,src/RecoTotemRP/RPClusterSigmaService/src,LIBRARY))
RecoTotemRPRPClusterSigmaService := self/RecoTotemRP/RPClusterSigmaService
RecoTotemRP/RPClusterSigmaService := RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterSigmaService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPClusterSigmaService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterSigmaService/BuildFile
RecoTotemRPRPClusterSigmaService_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core
RecoTotemRPRPClusterSigmaService_EX_LIB   := RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_EX_USE   := $(foreach d,$(RecoTotemRPRPClusterSigmaService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPClusterSigmaService_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/src
ALL_PRODS += RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/src,src_RecoTotemRP_RPClusterSigmaService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
