ALL_COMMONRULES += src_IOMC_Elegent_test
src_IOMC_Elegent_test_parent := IOMC/Elegent
src_IOMC_Elegent_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_test,src/IOMC/Elegent/test,TEST))
