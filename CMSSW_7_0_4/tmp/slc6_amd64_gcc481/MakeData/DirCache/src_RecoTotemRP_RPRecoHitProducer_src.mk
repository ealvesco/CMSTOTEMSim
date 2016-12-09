ifeq ($(strip $(RecoTotemRP/RPRecoHitProducer)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_src
src_RecoTotemRP_RPRecoHitProducer_src_parent := RecoTotemRP/RPRecoHitProducer
src_RecoTotemRP_RPRecoHitProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_src,src/RecoTotemRP/RPRecoHitProducer/src,LIBRARY))
RecoTotemRPRPRecoHitProducer := self/RecoTotemRP/RPRecoHitProducer
RecoTotemRP/RPRecoHitProducer := RecoTotemRPRPRecoHitProducer
RecoTotemRPRPRecoHitProducer_files := $(patsubst src/RecoTotemRP/RPRecoHitProducer/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoHitProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRecoHitProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRecoHitProducer/BuildFile
RecoTotemRPRPRecoHitProducer_LOC_USE := self  clhep FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common RecoTotemRP/RPClusterSigmaService Geometry/TotemRPDetTopology DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords boost root rootrflx
RecoTotemRPRPRecoHitProducer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPRecoHitProducer,RecoTotemRPRPRecoHitProducer,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPRecoHitProducer/src))
RecoTotemRPRPRecoHitProducer_PACKAGE := self/src/RecoTotemRP/RPRecoHitProducer/src
ALL_PRODS += RecoTotemRPRPRecoHitProducer
RecoTotemRPRPRecoHitProducer_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/src,src_RecoTotemRP_RPRecoHitProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
