ifeq ($(strip $(RecoTotemT1T2/PrimaryVertexProducer)),)
src_RecoTotemT1T2_PrimaryVertexProducer := self/RecoTotemT1T2/PrimaryVertexProducer
RecoTotemT1T2/PrimaryVertexProducer  := src_RecoTotemT1T2_PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/PrimaryVertexProducer/BuildFile
src_RecoTotemT1T2_PrimaryVertexProducer_LOC_USE := clhep boost VertexReco/RecoTools SimDataFormats/Track FWCore/Framework self CommonTools/Clustering1D root DataFormats/T1T2Track Geometry/TotemRecords DataFormats/T1RecHit DataFormats/Common RecoVertex/VertexPrimitives Geometry/TotemGeometry RecoVertex/VertexTools DataFormats/T1T2Road DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_PrimaryVertexProducer_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_PrimaryVertexProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer))
endif

