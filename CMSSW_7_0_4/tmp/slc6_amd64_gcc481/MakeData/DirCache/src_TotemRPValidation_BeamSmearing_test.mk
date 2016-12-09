ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_test
src_TotemRPValidation_BeamSmearing_test_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_test,src/TotemRPValidation/BeamSmearing/test,TEST))
