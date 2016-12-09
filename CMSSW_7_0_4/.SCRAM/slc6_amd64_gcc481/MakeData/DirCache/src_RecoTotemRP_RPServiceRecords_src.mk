ifeq ($(strip $(RecoTotemRP/RPServiceRecords)),)
ALL_COMMONRULES += src_RecoTotemRP_RPServiceRecords_src
src_RecoTotemRP_RPServiceRecords_src_parent := RecoTotemRP/RPServiceRecords
src_RecoTotemRP_RPServiceRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPServiceRecords_src,src/RecoTotemRP/RPServiceRecords/src,LIBRARY))
RecoTotemRPRPServiceRecords := self/RecoTotemRP/RPServiceRecords
RecoTotemRP/RPServiceRecords := RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_files := $(patsubst src/RecoTotemRP/RPServiceRecords/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPServiceRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPServiceRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPServiceRecords/BuildFile
RecoTotemRPRPServiceRecords_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes
RecoTotemRPRPServiceRecords_EX_LIB   := RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_EX_USE   := $(foreach d,$(RecoTotemRPRPServiceRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPServiceRecords_PACKAGE := self/src/RecoTotemRP/RPServiceRecords/src
ALL_PRODS += RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPServiceRecords,src/RecoTotemRP/RPServiceRecords/src,src_RecoTotemRP_RPServiceRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
