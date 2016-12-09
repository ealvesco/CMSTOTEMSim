ALL_COMMONRULES += src_IOMC_Phojet_test
src_IOMC_Phojet_test_parent := IOMC/Phojet
src_IOMC_Phojet_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_test,src/IOMC/Phojet/test,TEST))
