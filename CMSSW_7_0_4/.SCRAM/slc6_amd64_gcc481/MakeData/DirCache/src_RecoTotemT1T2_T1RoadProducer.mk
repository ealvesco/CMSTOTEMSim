ifeq ($(strip $(RecoTotemT1T2/T1RoadProducer)),)
src_RecoTotemT1T2_T1RoadProducer := self/RecoTotemT1T2/T1RoadProducer
RecoTotemT1T2/T1RoadProducer  := src_RecoTotemT1T2_T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RoadProducer/BuildFile
src_RecoTotemT1T2_T1RoadProducer_LOC_USE := boost SimDataFormats/Track FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiWire root DataFormats/T1Road Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_T1RoadProducer_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1RoadProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer))
endif

