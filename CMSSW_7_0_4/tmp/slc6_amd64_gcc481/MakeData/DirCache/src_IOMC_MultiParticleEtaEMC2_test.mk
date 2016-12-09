ALL_COMMONRULES += src_IOMC_MultiParticleEtaEMC2_test
src_IOMC_MultiParticleEtaEMC2_test_parent := IOMC/MultiParticleEtaEMC2
src_IOMC_MultiParticleEtaEMC2_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleEtaEMC2_test,src/IOMC/MultiParticleEtaEMC2/test,TEST))
