ifeq ($(strip $(RecoTotemT1T2T2TrackProducer3Plugins)),)
RecoTotemT1T2T2TrackProducer3Plugins_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2TrackProducer3/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2TrackProducer3/plugins/$(file). Please fix src/RecoTotemT1T2/T2TrackProducer3/plugins/BuildFile.))))
RecoTotemT1T2T2TrackProducer3Plugins := self/src/RecoTotemT1T2/T2TrackProducer3/plugins
RecoTotemT1T2T2TrackProducer3Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2TrackProducer3/plugins/BuildFile
RecoTotemT1T2T2TrackProducer3Plugins_LOC_USE := self  RecoTotemT1T2/T2TrackProducer3 FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Road DataFormats/T1T2Track TotemAnalysis/T2Cuts boost root clhep
RecoTotemT1T2T2TrackProducer3Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2TrackProducer3Plugins,RecoTotemT1T2T2TrackProducer3Plugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2TrackProducer3/plugins))
RecoTotemT1T2T2TrackProducer3Plugins_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/plugins
ALL_PRODS += RecoTotemT1T2T2TrackProducer3Plugins
RecoTotemT1T2T2TrackProducer3Plugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2TrackProducer3Plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins,src_RecoTotemT1T2_T2TrackProducer3_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2TrackProducer3Plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_plugins
src_RecoTotemT1T2_T2TrackProducer3_plugins_parent := RecoTotemT1T2/T2TrackProducer3
src_RecoTotemT1T2_T2TrackProducer3_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins,PLUGINS))
