ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_test
src_RecoTotemT1T2_T2RoadPadFinder_test_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_test,src/RecoTotemT1T2/T2RoadPadFinder/test,TEST))
