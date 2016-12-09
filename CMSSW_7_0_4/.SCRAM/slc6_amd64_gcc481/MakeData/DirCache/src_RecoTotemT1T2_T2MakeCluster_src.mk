ifeq ($(strip $(RecoTotemT1T2/T2MakeCluster)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_src
src_RecoTotemT1T2_T2MakeCluster_src_parent := RecoTotemT1T2/T2MakeCluster
src_RecoTotemT1T2_T2MakeCluster_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_src,src/RecoTotemT1T2/T2MakeCluster/src,LIBRARY))
RecoTotemT1T2T2MakeCluster := self/RecoTotemT1T2/T2MakeCluster
RecoTotemT1T2/T2MakeCluster := RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2MakeCluster/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2MakeCluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2MakeCluster/BuildFile
RecoTotemT1T2T2MakeCluster_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId SimDataFormats/GeneratorProducts boost clhep gsl hepmc rootcore rootrflx root FWCore/PluginManager FWCore/ServiceRegistry FWCore/Utilities DataFormats/T2Cluster
RecoTotemT1T2T2MakeCluster_EX_LIB   := RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_EX_USE   := $(foreach d,$(RecoTotemT1T2T2MakeCluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/src
ALL_PRODS += RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/src,src_RecoTotemT1T2_T2MakeCluster_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
