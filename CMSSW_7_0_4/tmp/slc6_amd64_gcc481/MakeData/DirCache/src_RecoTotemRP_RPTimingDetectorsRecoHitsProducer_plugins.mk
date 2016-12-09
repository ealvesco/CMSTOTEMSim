ifeq ($(strip $(RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto)),)
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_files := $(patsubst src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins/BuildFile
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet SimTotem/RPTimingDetectorsDigiProducer
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins))
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_PACKAGE := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins
ALL_PRODS += RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins_parent := RecoTotemRP/RPTimingDetectorsRecoHitsProducer
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins,PLUGINS))
