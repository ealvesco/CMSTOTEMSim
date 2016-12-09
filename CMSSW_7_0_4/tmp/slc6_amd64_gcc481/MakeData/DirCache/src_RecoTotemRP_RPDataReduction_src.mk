ifeq ($(strip $(RecoTotemRP/RPDataReduction)),)
ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_src
src_RecoTotemRP_RPDataReduction_src_parent := RecoTotemRP/RPDataReduction
src_RecoTotemRP_RPDataReduction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_src,src/RecoTotemRP/RPDataReduction/src,LIBRARY))
RecoTotemRPRPDataReduction := self/RecoTotemRP/RPDataReduction
RecoTotemRP/RPDataReduction := RecoTotemRPRPDataReduction
RecoTotemRPRPDataReduction_files := $(patsubst src/RecoTotemRP/RPDataReduction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDataReduction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPDataReduction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPDataReduction/BuildFile
RecoTotemRPRPDataReduction_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats DataFormats/TotemRPDetId DataFormats/Common DataFormats/TotemL1Trigger DataFormats/T1T2Track DataFormats/T2Cluster DataFormats/T2Hit DataFormats/T1Road DataFormats/T2DetId TotemRawDataLibrary/DataFormats Geometry/TotemRecords Geometry/TotemRPGeometryBuilder Geometry/TotemRPDetTopology TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord root clhep rootgraphics boost
RecoTotemRPRPDataReduction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPDataReduction,RecoTotemRPRPDataReduction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPDataReduction/src))
RecoTotemRPRPDataReduction_PACKAGE := self/src/RecoTotemRP/RPDataReduction/src
ALL_PRODS += RecoTotemRPRPDataReduction
RecoTotemRPRPDataReduction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/src,src_RecoTotemRP_RPDataReduction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
