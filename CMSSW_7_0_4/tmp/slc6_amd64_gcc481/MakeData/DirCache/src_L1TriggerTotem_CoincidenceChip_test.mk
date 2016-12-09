ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_test
src_L1TriggerTotem_CoincidenceChip_test_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_test,src/L1TriggerTotem/CoincidenceChip/test,TEST))
