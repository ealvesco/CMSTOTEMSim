ALL_COMMONRULES += src_SimTotem_T2Digitizer_test
src_SimTotem_T2Digitizer_test_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_test,src/SimTotem/T2Digitizer/test,TEST))
