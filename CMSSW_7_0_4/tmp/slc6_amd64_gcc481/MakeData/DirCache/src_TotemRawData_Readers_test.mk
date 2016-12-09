ALL_COMMONRULES += src_TotemRawData_Readers_test
src_TotemRawData_Readers_test_parent := TotemRawData/Readers
src_TotemRawData_Readers_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_test,src/TotemRawData/Readers/test,TEST))
