ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_test
src_IOMC_FlatProtonLogKsiLogTGun_test_parent := IOMC/FlatProtonLogKsiLogTGun
src_IOMC_FlatProtonLogKsiLogTGun_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_test,src/IOMC/FlatProtonLogKsiLogTGun/test,TEST))
