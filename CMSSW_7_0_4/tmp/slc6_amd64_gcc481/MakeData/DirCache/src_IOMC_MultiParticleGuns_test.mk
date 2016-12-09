ALL_COMMONRULES += src_IOMC_MultiParticleGuns_test
src_IOMC_MultiParticleGuns_test_parent := IOMC/MultiParticleGuns
src_IOMC_MultiParticleGuns_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleGuns_test,src/IOMC/MultiParticleGuns/test,TEST))
