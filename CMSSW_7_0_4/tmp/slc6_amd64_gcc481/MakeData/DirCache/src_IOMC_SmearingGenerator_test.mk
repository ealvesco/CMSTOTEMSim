ALL_COMMONRULES += src_IOMC_SmearingGenerator_test
src_IOMC_SmearingGenerator_test_parent := IOMC/SmearingGenerator
src_IOMC_SmearingGenerator_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_test,src/IOMC/SmearingGenerator/test,TEST))
