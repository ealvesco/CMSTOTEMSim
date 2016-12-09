ALL_COMMONRULES += src_TotemRawDataLibrary_DAQA_test
src_TotemRawDataLibrary_DAQA_test_parent := TotemRawDataLibrary/DAQA
src_TotemRawDataLibrary_DAQA_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_DAQA_test,src/TotemRawDataLibrary/DAQA/test,TEST))
