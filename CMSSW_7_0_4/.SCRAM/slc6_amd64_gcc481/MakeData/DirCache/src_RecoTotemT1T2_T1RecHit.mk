ifeq ($(strip $(RecoTotemT1T2/T1RecHit)),)
src_RecoTotemT1T2_T1RecHit := self/RecoTotemT1T2/T1RecHit
RecoTotemT1T2/T1RecHit  := src_RecoTotemT1T2_T1RecHit
src_RecoTotemT1T2_T1RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RecHit/BuildFile
src_RecoTotemT1T2_T1RecHit_LOC_USE := boost FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiWire root Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_T1RecHit_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1RecHit
src_RecoTotemT1T2_T1RecHit_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1RecHit,src/RecoTotemT1T2/T1RecHit))
endif

