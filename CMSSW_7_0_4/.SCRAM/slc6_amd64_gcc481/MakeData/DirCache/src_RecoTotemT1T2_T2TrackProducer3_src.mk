ifeq ($(strip $(RecoTotemT1T2/T2TrackProducer3)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_src
src_RecoTotemT1T2_T2TrackProducer3_src_parent := RecoTotemT1T2/T2TrackProducer3
src_RecoTotemT1T2_T2TrackProducer3_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_src,src/RecoTotemT1T2/T2TrackProducer3/src,LIBRARY))
RecoTotemT1T2T2TrackProducer3 := self/RecoTotemT1T2/T2TrackProducer3
RecoTotemT1T2/T2TrackProducer3 := RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2TrackProducer3/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2TrackProducer3_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2TrackProducer3/BuildFile
RecoTotemT1T2T2TrackProducer3_LOC_FLAGS_CXXFLAGS   := -O0 -g3 -fno-inline
RecoTotemT1T2T2TrackProducer3_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/DetId DataFormats/T2DetId DataFormats/T2Hit DataFormats/T2Road DataFormats/T1T2Track TotemAnalysis/T2Cuts clhep root boost
RecoTotemT1T2T2TrackProducer3_EX_LIB   := RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_EX_USE   := $(foreach d,$(RecoTotemT1T2T2TrackProducer3_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2TrackProducer3_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/src
ALL_PRODS += RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/src,src_RecoTotemT1T2_T2TrackProducer3_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
