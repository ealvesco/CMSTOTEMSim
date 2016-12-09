ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_test
src_IOMC_FlatThetaXYGun_test_parent := IOMC/FlatThetaXYGun
src_IOMC_FlatThetaXYGun_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_test,src/IOMC/FlatThetaXYGun/test,TEST))
