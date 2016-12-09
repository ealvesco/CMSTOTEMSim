ifeq ($(strip $(SimTotem/RPDigiProducer)),)
ALL_COMMONRULES += src_SimTotem_RPDigiProducer_src
src_SimTotem_RPDigiProducer_src_parent := SimTotem/RPDigiProducer
src_SimTotem_RPDigiProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_src,src/SimTotem/RPDigiProducer/src,LIBRARY))
SimTotemRPDigiProducer := self/SimTotem/RPDigiProducer
SimTotem/RPDigiProducer := SimTotemRPDigiProducer
SimTotemRPDigiProducer_files := $(patsubst src/SimTotem/RPDigiProducer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/RPDigiProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPDigiProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPDigiProducer/BuildFile
SimTotemRPDigiProducer_LOC_USE := self  SimDataFormats/TrackingHit SimGeneral/NoiseGenerators FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common SimDataFormats/CrossingFrame SimTracker/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Mixing/Base gsl boost geant4 DataFormats/TotemRPDetId TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemRPDigiProducer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemRPDigiProducer,SimTotemRPDigiProducer,$(SCRAMSTORENAME_LIB),src/SimTotem/RPDigiProducer/src))
SimTotemRPDigiProducer_PACKAGE := self/src/SimTotem/RPDigiProducer/src
ALL_PRODS += SimTotemRPDigiProducer
SimTotemRPDigiProducer_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/src,src_SimTotem_RPDigiProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
