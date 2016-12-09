ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_test
src_RecoTotemRP_RPClusterizer_test_parent := RecoTotemRP/RPClusterizer
src_RecoTotemRP_RPClusterizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_test,src/RecoTotemRP/RPClusterizer/test,TEST))
