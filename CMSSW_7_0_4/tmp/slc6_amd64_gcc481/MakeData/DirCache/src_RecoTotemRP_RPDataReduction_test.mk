ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_test
src_RecoTotemRP_RPDataReduction_test_parent := RecoTotemRP/RPDataReduction
src_RecoTotemRP_RPDataReduction_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_test,src/RecoTotemRP/RPDataReduction/test,TEST))
