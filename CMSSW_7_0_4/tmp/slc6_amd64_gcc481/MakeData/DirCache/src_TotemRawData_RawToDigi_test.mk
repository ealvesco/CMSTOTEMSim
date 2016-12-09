ALL_COMMONRULES += src_TotemRawData_RawToDigi_test
src_TotemRawData_RawToDigi_test_parent := TotemRawData/RawToDigi
src_TotemRawData_RawToDigi_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_test,src/TotemRawData/RawToDigi/test,TEST))
