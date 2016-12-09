ifeq ($(strip $(RecoTotemRP/CentralMCJetReconstruction)),)
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_src
src_RecoTotemRP_CentralMCJetReconstruction_src_parent := RecoTotemRP/CentralMCJetReconstruction
src_RecoTotemRP_CentralMCJetReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_src,src/RecoTotemRP/CentralMCJetReconstruction/src,LIBRARY))
RecoTotemRPCentralMCJetReconstruction := self/RecoTotemRP/CentralMCJetReconstruction
RecoTotemRP/CentralMCJetReconstruction := RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/CentralMCJetReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPCentralMCJetReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/CentralMCJetReconstruction/BuildFile
RecoTotemRPCentralMCJetReconstruction_LOC_USE := self  root rootminuit2 boost rootrflx FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts Geometry/TotemGeometry hepmc fastjet
RecoTotemRPCentralMCJetReconstruction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPCentralMCJetReconstructionCapabilities,RecoTotemRPCentralMCJetReconstruction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/CentralMCJetReconstruction/src))
RecoTotemRPCentralMCJetReconstruction_PRE_INIT_FUNC += $$(eval $$(call LCGDict,RecoTotemRPCentralMCJetReconstruction,0,src/RecoTotemRP/CentralMCJetReconstruction/src/classes.h,src/RecoTotemRP/CentralMCJetReconstruction/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
RecoTotemRPCentralMCJetReconstruction_EX_LIB   := RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_EX_USE   := $(foreach d,$(RecoTotemRPCentralMCJetReconstruction_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPCentralMCJetReconstruction_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/src
ALL_PRODS += RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/src,src_RecoTotemRP_CentralMCJetReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
