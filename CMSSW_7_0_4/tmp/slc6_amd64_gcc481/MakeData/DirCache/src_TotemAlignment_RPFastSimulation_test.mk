ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_test
src_TotemAlignment_RPFastSimulation_test_parent := TotemAlignment/RPFastSimulation
src_TotemAlignment_RPFastSimulation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_test,src/TotemAlignment/RPFastSimulation/test,TEST))