ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_test
src_TotemAnalysis_TotemNtuplizer_test_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_test,src/TotemAnalysis/TotemNtuplizer/test,TEST))
