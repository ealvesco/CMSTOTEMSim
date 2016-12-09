ifeq ($(strip $(RecoTotemRP/RPClusterizer)),)
ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_src
src_RecoTotemRP_RPClusterizer_src_parent := RecoTotemRP/RPClusterizer
src_RecoTotemRP_RPClusterizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_src,src/RecoTotemRP/RPClusterizer/src,LIBRARY))
RecoTotemRPRPClusterizer := self/RecoTotemRP/RPClusterizer
RecoTotemRP/RPClusterizer := RecoTotemRPRPClusterizer
RecoTotemRPRPClusterizer_files := $(patsubst src/RecoTotemRP/RPClusterizer/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPClusterizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterizer/BuildFile
RecoTotemRPRPClusterizer_LOC_USE := self  FWCore/Framework FWCore/ParameterSet boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology SimDataFormats/TrackingHit
RecoTotemRPRPClusterizer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPClusterizer,RecoTotemRPRPClusterizer,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPClusterizer/src))
RecoTotemRPRPClusterizer_PACKAGE := self/src/RecoTotemRP/RPClusterizer/src
ALL_PRODS += RecoTotemRPRPClusterizer
RecoTotemRPRPClusterizer_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/src,src_RecoTotemRP_RPClusterizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
