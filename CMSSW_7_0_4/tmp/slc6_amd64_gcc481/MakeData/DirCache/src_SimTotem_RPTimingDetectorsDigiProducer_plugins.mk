ifeq ($(strip $(SimTotemRPTimingDetectorsDigiProducerAuto)),)
SimTotemRPTimingDetectorsDigiProducerAuto_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/plugins/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPTimingDetectorsDigiProducerAuto := self/src/SimTotem/RPTimingDetectorsDigiProducer/plugins
SimTotemRPTimingDetectorsDigiProducerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPTimingDetectorsDigiProducer/plugins/BuildFile
SimTotemRPTimingDetectorsDigiProducerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId SimTotem/RPTimingDetectorsDigiProducer CommonTools/UtilAlgos PhysicsTools/UtilAlgos Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
SimTotemRPTimingDetectorsDigiProducerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemRPTimingDetectorsDigiProducerAuto,SimTotemRPTimingDetectorsDigiProducerAuto,$(SCRAMSTORENAME_LIB),src/SimTotem/RPTimingDetectorsDigiProducer/plugins))
SimTotemRPTimingDetectorsDigiProducerAuto_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/plugins
ALL_PRODS += SimTotemRPTimingDetectorsDigiProducerAuto
SimTotemRPTimingDetectorsDigiProducerAuto_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPTimingDetectorsDigiProducerAuto,src/SimTotem/RPTimingDetectorsDigiProducer/plugins,src_SimTotem_RPTimingDetectorsDigiProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemRPTimingDetectorsDigiProducerAuto,src/SimTotem/RPTimingDetectorsDigiProducer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_plugins
src_SimTotem_RPTimingDetectorsDigiProducer_plugins_parent := SimTotem/RPTimingDetectorsDigiProducer
src_SimTotem_RPTimingDetectorsDigiProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_plugins,src/SimTotem/RPTimingDetectorsDigiProducer/plugins,PLUGINS))
