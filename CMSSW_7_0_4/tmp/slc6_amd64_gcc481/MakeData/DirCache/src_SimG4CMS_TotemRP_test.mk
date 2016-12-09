ALL_COMMONRULES += src_SimG4CMS_TotemRP_test
src_SimG4CMS_TotemRP_test_parent := SimG4CMS/TotemRP
src_SimG4CMS_TotemRP_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_test,src/SimG4CMS/TotemRP/test,TEST))
