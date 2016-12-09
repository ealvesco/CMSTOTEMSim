ALL_COMMONRULES += src_IOMC_DPEProtons_test
src_IOMC_DPEProtons_test_parent := IOMC/DPEProtons
src_IOMC_DPEProtons_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_test,src/IOMC/DPEProtons/test,TEST))
