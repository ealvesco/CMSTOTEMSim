ifeq ($(strip $(TotemT1T2Validation/T1Validation)),)
src_TotemT1T2Validation_T1Validation := self/TotemT1T2Validation/T1Validation
TotemT1T2Validation/T1Validation  := src_TotemT1T2Validation_T1Validation
src_TotemT1T2Validation_T1Validation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T1Validation/BuildFile
src_TotemT1T2Validation_T1Validation_LOC_USE := DataFormats/T1DetId clhep boost SimDataFormats/Track FWCore/Framework self DataFormats/DetId CommonTools/Clustering1D DataFormats/T1Cluster DataFormats/T1DigiVfat DataFormats/T1DigiWire root DataFormats/T1T2Track FWCore/MessageLogger Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_TotemT1T2Validation_T1Validation_EX_USE   := $(foreach d,$(src_TotemT1T2Validation_T1Validation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_TotemT1T2Validation_T1Validation
src_TotemT1T2Validation_T1Validation_INIT_FUNC += $$(eval $$(call EmptyPackage,src_TotemT1T2Validation_T1Validation,src/TotemT1T2Validation/T1Validation))
endif

