ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_test
src_TotemRPValidation_RecoTrackRP_test_parent := TotemRPValidation/RecoTrackRP
src_TotemRPValidation_RecoTrackRP_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_test,src/TotemRPValidation/RecoTrackRP/test,TEST))
