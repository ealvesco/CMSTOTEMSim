ifeq ($(strip $(RecoTotemT1T2T1TrackProducer2Plugins)),)
RecoTotemT1T2T1TrackProducer2Plugins_files := $(patsubst src/RecoTotemT1T2/T1TrackProducer2/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1TrackProducer2/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1TrackProducer2/plugins/$(file). Please fix src/RecoTotemT1T2/T1TrackProducer2/plugins/BuildFile.))))
RecoTotemT1T2T1TrackProducer2Plugins := self/src/RecoTotemT1T2/T1TrackProducer2/plugins
RecoTotemT1T2T1TrackProducer2Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1TrackProducer2/plugins/BuildFile
RecoTotemT1T2T1TrackProducer2Plugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/T1Road DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet CommonTools/Clustering1D RecoVertex/VertexPrimitives RecoVertex/VertexTools boost root clhep
RecoTotemT1T2T1TrackProducer2Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1TrackProducer2Plugins,RecoTotemT1T2T1TrackProducer2Plugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1TrackProducer2/plugins))
RecoTotemT1T2T1TrackProducer2Plugins_PACKAGE := self/src/RecoTotemT1T2/T1TrackProducer2/plugins
ALL_PRODS += RecoTotemT1T2T1TrackProducer2Plugins
RecoTotemT1T2T1TrackProducer2Plugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1TrackProducer2Plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins,src_RecoTotemT1T2_T1TrackProducer2_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1TrackProducer2Plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1TrackProducer2_plugins
src_RecoTotemT1T2_T1TrackProducer2_plugins_parent := RecoTotemT1T2/T1TrackProducer2
src_RecoTotemT1T2_T1TrackProducer2_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1TrackProducer2_plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins,PLUGINS))
