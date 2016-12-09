ALL_COMMONRULES += src_TotemRawDataLibrary_Readers_test
src_TotemRawDataLibrary_Readers_test_parent := TotemRawDataLibrary/Readers
src_TotemRawDataLibrary_Readers_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Readers_test,src/TotemRawDataLibrary/Readers/test,TEST))
