ALL_COMMONRULES += src_SimG4CMS_Forward_test
src_SimG4CMS_Forward_test_parent := SimG4CMS/Forward
src_SimG4CMS_Forward_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_test,src/SimG4CMS/Forward/test,TEST))
