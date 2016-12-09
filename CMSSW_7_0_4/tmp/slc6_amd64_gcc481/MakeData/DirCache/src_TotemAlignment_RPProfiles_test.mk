ALL_COMMONRULES += src_TotemAlignment_RPProfiles_test
src_TotemAlignment_RPProfiles_test_parent := TotemAlignment/RPProfiles
src_TotemAlignment_RPProfiles_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_test,src/TotemAlignment/RPProfiles/test,TEST))
