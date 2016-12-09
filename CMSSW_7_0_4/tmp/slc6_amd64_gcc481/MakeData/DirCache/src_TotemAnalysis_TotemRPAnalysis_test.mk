ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_test
src_TotemAnalysis_TotemRPAnalysis_test_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_test,src/TotemAnalysis/TotemRPAnalysis/test,TEST))
