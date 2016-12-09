ifeq ($(strip $(SimTotem/RPTimingDetectorsDigiProducer)),)
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_src
src_SimTotem_RPTimingDetectorsDigiProducer_src_parent := SimTotem/RPTimingDetectorsDigiProducer
src_SimTotem_RPTimingDetectorsDigiProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_src,src/SimTotem/RPTimingDetectorsDigiProducer/src,LIBRARY))
SimTotemRPTimingDetectorsDigiProducer := self/SimTotem/RPTimingDetectorsDigiProducer
SimTotem/RPTimingDetectorsDigiProducer := SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPTimingDetectorsDigiProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPTimingDetectorsDigiProducer/BuildFile
SimTotemRPTimingDetectorsDigiProducer_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId
SimTotemRPTimingDetectorsDigiProducer_EX_LIB   := SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_EX_USE   := $(foreach d,$(SimTotemRPTimingDetectorsDigiProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemRPTimingDetectorsDigiProducer_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/src
ALL_PRODS += SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/src,src_SimTotem_RPTimingDetectorsDigiProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
