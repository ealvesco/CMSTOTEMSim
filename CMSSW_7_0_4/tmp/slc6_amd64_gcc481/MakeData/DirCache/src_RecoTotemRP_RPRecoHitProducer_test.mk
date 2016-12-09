ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_test
src_RecoTotemRP_RPRecoHitProducer_test_parent := RecoTotemRP/RPRecoHitProducer
src_RecoTotemRP_RPRecoHitProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_test,src/RecoTotemRP/RPRecoHitProducer/test,TEST))
