ifeq ($(strip $(RecoTotemT1T2T1RoadProducerPlugins)),)
RecoTotemT1T2T1RoadProducerPlugins_files := $(patsubst src/RecoTotemT1T2/T1RoadProducer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1RoadProducer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1RoadProducer/plugins/$(file). Please fix src/RecoTotemT1T2/T1RoadProducer/plugins/BuildFile.))))
RecoTotemT1T2T1RoadProducerPlugins := self/src/RecoTotemT1T2/T1RoadProducer/plugins
RecoTotemT1T2T1RoadProducerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RoadProducer/plugins/BuildFile
RecoTotemT1T2T1RoadProducerPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1DigiWire DataFormats/T1Cluster DataFormats/T1Road DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet boost root
RecoTotemT1T2T1RoadProducerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1RoadProducerPlugins,RecoTotemT1T2T1RoadProducerPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1RoadProducer/plugins))
RecoTotemT1T2T1RoadProducerPlugins_PACKAGE := self/src/RecoTotemT1T2/T1RoadProducer/plugins
ALL_PRODS += RecoTotemT1T2T1RoadProducerPlugins
RecoTotemT1T2T1RoadProducerPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1RoadProducerPlugins,src/RecoTotemT1T2/T1RoadProducer/plugins,src_RecoTotemT1T2_T1RoadProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1RoadProducerPlugins,src/RecoTotemT1T2/T1RoadProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RoadProducer_plugins
src_RecoTotemT1T2_T1RoadProducer_plugins_parent := RecoTotemT1T2/T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RoadProducer_plugins,src/RecoTotemT1T2/T1RoadProducer/plugins,PLUGINS))
