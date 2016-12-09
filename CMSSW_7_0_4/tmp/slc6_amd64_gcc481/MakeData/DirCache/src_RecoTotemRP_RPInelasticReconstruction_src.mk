ifeq ($(strip $(RecoTotemRP/RPInelasticReconstruction)),)
ALL_COMMONRULES += src_RecoTotemRP_RPInelasticReconstruction_src
src_RecoTotemRP_RPInelasticReconstruction_src_parent := RecoTotemRP/RPInelasticReconstruction
src_RecoTotemRP_RPInelasticReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInelasticReconstruction_src,src/RecoTotemRP/RPInelasticReconstruction/src,LIBRARY))
RecoTotemRPRPInelasticReconstruction := self/RecoTotemRP/RPInelasticReconstruction
RecoTotemRP/RPInelasticReconstruction := RecoTotemRPRPInelasticReconstruction
RecoTotemRPRPInelasticReconstruction_files := $(patsubst src/RecoTotemRP/RPInelasticReconstruction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInelasticReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPInelasticReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPInelasticReconstruction/BuildFile
RecoTotemRPRPInelasticReconstruction_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar RecoTotemRP/RPInverseParameterization SimDataFormats/GeneratorProducts SimG4Core/Notification RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord rootminuit2
RecoTotemRPRPInelasticReconstruction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPInelasticReconstruction,RecoTotemRPRPInelasticReconstruction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPInelasticReconstruction/src))
RecoTotemRPRPInelasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPInelasticReconstruction/src
ALL_PRODS += RecoTotemRPRPInelasticReconstruction
RecoTotemRPRPInelasticReconstruction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/src,src_RecoTotemRP_RPInelasticReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
