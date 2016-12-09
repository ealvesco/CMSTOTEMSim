ifeq ($(strip $(TotemRecoPrimaryVertexProducerPlugins)),)
TotemRecoPrimaryVertexProducerPlugins_files := $(patsubst src/RecoTotemT1T2/PrimaryVertexProducer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/PrimaryVertexProducer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/PrimaryVertexProducer/plugins/$(file). Please fix src/RecoTotemT1T2/PrimaryVertexProducer/plugins/BuildFile.))))
TotemRecoPrimaryVertexProducerPlugins := self/src/RecoTotemT1T2/PrimaryVertexProducer/plugins
TotemRecoPrimaryVertexProducerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/PrimaryVertexProducer/plugins/BuildFile
TotemRecoPrimaryVertexProducerPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet CommonTools/Clustering1D RecoVertex/VertexPrimitives RecoVertex/VertexTools boost root clhep
TotemRecoPrimaryVertexProducerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRecoPrimaryVertexProducerPlugins,TotemRecoPrimaryVertexProducerPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/PrimaryVertexProducer/plugins))
TotemRecoPrimaryVertexProducerPlugins_PACKAGE := self/src/RecoTotemT1T2/PrimaryVertexProducer/plugins
ALL_PRODS += TotemRecoPrimaryVertexProducerPlugins
TotemRecoPrimaryVertexProducerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRecoPrimaryVertexProducerPlugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins,src_RecoTotemT1T2_PrimaryVertexProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRecoPrimaryVertexProducerPlugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_PrimaryVertexProducer_plugins
src_RecoTotemT1T2_PrimaryVertexProducer_plugins_parent := RecoTotemT1T2/PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_PrimaryVertexProducer_plugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins,PLUGINS))
