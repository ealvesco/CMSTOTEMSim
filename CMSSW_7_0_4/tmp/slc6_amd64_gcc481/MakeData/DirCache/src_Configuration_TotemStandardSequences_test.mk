ALL_COMMONRULES += src_Configuration_TotemStandardSequences_test
src_Configuration_TotemStandardSequences_test_parent := Configuration/TotemStandardSequences
src_Configuration_TotemStandardSequences_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemStandardSequences_test,src/Configuration/TotemStandardSequences/test,TEST))
