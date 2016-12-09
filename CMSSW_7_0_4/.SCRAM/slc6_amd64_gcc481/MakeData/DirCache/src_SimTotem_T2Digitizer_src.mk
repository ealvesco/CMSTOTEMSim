ifeq ($(strip $(SimTotem/T2Digitizer)),)
ALL_COMMONRULES += src_SimTotem_T2Digitizer_src
src_SimTotem_T2Digitizer_src_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_src,src/SimTotem/T2Digitizer/src,LIBRARY))
SimTotemT2Digitizer := self/SimTotem/T2Digitizer
SimTotem/T2Digitizer := SimTotemT2Digitizer
SimTotemT2Digitizer_files := $(patsubst src/SimTotem/T2Digitizer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/T2Digitizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemT2Digitizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T2Digitizer/BuildFile
SimTotemT2Digitizer_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Utilities/Timing Utilities/General FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId DataFormats/T2DigiVfat SimDataFormats/TrackingHit Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimTracker/Common Mixing/Base Geometry/TotemT2AlignmentDataFormats geant4 root boost clhep gsl hepmc SimDataFormats/GeneratorProducts TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemT2Digitizer_EX_LIB   := SimTotemT2Digitizer
SimTotemT2Digitizer_EX_USE   := $(foreach d,$(SimTotemT2Digitizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemT2Digitizer_PACKAGE := self/src/SimTotem/T2Digitizer/src
ALL_PRODS += SimTotemT2Digitizer
SimTotemT2Digitizer_INIT_FUNC        += $$(eval $$(call Library,SimTotemT2Digitizer,src/SimTotem/T2Digitizer/src,src_SimTotem_T2Digitizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
