ALL_COMMONRULES += src_Geometry_ForwardCommonData_test
src_Geometry_ForwardCommonData_test_parent := Geometry/ForwardCommonData
src_Geometry_ForwardCommonData_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_ForwardCommonData_test,src/Geometry/ForwardCommonData/test,TEST))
