ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_test
src_TotemAlignment_RPDataFormats_test_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_test,src/TotemAlignment/RPDataFormats/test,TEST))
