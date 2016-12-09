ALL_COMMONRULES += src_TotemDQMLite_Geometry_test
src_TotemDQMLite_Geometry_test_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_test,src/TotemDQMLite/Geometry/test,TEST))
