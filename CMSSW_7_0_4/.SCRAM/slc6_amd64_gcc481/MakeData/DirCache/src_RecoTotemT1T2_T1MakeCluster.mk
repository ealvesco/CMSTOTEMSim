ifeq ($(strip $(RecoTotemT1T2/T1MakeCluster)),)
src_RecoTotemT1T2_T1MakeCluster := self/RecoTotemT1T2/T1MakeCluster
RecoTotemT1T2/T1MakeCluster  := src_RecoTotemT1T2_T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1MakeCluster/BuildFile
src_RecoTotemT1T2_T1MakeCluster_LOC_USE := boost FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiVfat DataFormats/T1DigiWire root SimTotem/T1Digitizer TotemRawData/DataFormats TotemCondFormats/DAQInformation FWCore/MessageLogger Geometry/TotemRecords DataFormats/Common Geometry/TotemGeometry DataFormats/T1DigiSantiard FWCore/ParameterSet
src_RecoTotemT1T2_T1MakeCluster_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1MakeCluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster))
endif

