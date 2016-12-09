ALL_COMMONRULES += src_Geometry_TotemRPData_test
src_Geometry_TotemRPData_test_parent := Geometry/TotemRPData
src_Geometry_TotemRPData_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPData_test,src/Geometry/TotemRPData/test,TEST))
