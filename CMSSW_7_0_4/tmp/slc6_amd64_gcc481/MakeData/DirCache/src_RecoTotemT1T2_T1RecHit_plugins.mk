ifeq ($(strip $(RecoTotemT1T2T1RecHitPlugins)),)
RecoTotemT1T2T1RecHitPlugins_files := $(patsubst src/RecoTotemT1T2/T1RecHit/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1RecHit/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1RecHit/plugins/$(file). Please fix src/RecoTotemT1T2/T1RecHit/plugins/BuildFile.))))
RecoTotemT1T2T1RecHitPlugins := self/src/RecoTotemT1T2/T1RecHit/plugins
RecoTotemT1T2T1RecHitPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RecHit/plugins/BuildFile
RecoTotemT1T2T1RecHitPlugins_LOC_USE := self  root FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/T1Cluster DataFormats/Common DataFormats/GeometryVector Geometry/TotemGeometry FWCore/ParameterSet boost
RecoTotemT1T2T1RecHitPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1RecHitPlugins,RecoTotemT1T2T1RecHitPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1RecHit/plugins))
RecoTotemT1T2T1RecHitPlugins_PACKAGE := self/src/RecoTotemT1T2/T1RecHit/plugins
ALL_PRODS += RecoTotemT1T2T1RecHitPlugins
RecoTotemT1T2T1RecHitPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1RecHitPlugins,src/RecoTotemT1T2/T1RecHit/plugins,src_RecoTotemT1T2_T1RecHit_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1RecHitPlugins,src/RecoTotemT1T2/T1RecHit/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RecHit_plugins
src_RecoTotemT1T2_T1RecHit_plugins_parent := RecoTotemT1T2/T1RecHit
src_RecoTotemT1T2_T1RecHit_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RecHit_plugins,src/RecoTotemT1T2/T1RecHit/plugins,PLUGINS))
