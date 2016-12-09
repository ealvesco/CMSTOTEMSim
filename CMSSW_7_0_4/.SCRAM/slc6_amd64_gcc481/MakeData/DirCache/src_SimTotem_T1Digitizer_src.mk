ifeq ($(strip $(SimTotem/T1Digitizer)),)
ALL_COMMONRULES += src_SimTotem_T1Digitizer_src
src_SimTotem_T1Digitizer_src_parent := SimTotem/T1Digitizer
src_SimTotem_T1Digitizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_src,src/SimTotem/T1Digitizer/src,LIBRARY))
SimTotemT1Digitizer := self/SimTotem/T1Digitizer
SimTotem/T1Digitizer := SimTotemT1Digitizer
SimTotemT1Digitizer_files := $(patsubst src/SimTotem/T1Digitizer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/T1Digitizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemT1Digitizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T1Digitizer/BuildFile
SimTotemT1Digitizer_LOC_USE := self  DataFormats/Common DataFormats/Provenance FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimGeneral/HepPDTRecord Utilities/Timing Utilities/General FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/T1Digi DataFormats/DetId DataFormats/T1DetId DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1TestElements boost root rootrflx clhep hepmc SimDataFormats/GeneratorProducts TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemT1Digitizer_EX_LIB   := SimTotemT1Digitizer
SimTotemT1Digitizer_EX_USE   := $(foreach d,$(SimTotemT1Digitizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemT1Digitizer_PACKAGE := self/src/SimTotem/T1Digitizer/src
ALL_PRODS += SimTotemT1Digitizer
SimTotemT1Digitizer_INIT_FUNC        += $$(eval $$(call Library,SimTotemT1Digitizer,src/SimTotem/T1Digitizer/src,src_SimTotem_T1Digitizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
