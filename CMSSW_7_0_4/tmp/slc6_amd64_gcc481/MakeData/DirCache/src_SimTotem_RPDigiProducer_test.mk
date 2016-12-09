ALL_COMMONRULES += src_SimTotem_RPDigiProducer_test
src_SimTotem_RPDigiProducer_test_parent := SimTotem/RPDigiProducer
src_SimTotem_RPDigiProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_test,src/SimTotem/RPDigiProducer/test,TEST))
