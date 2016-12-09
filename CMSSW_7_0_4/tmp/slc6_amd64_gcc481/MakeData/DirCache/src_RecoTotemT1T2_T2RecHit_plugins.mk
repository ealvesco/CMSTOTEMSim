ifeq ($(strip $(RecoTotemT1T2T2RecHitPlugins)),)
RecoTotemT1T2T2RecHitPlugins_files := $(patsubst src/RecoTotemT1T2/T2RecHit/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2RecHit/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2RecHit/plugins/$(file). Please fix src/RecoTotemT1T2/T2RecHit/plugins/BuildFile.))))
RecoTotemT1T2T2RecHitPlugins := self/src/RecoTotemT1T2/T2RecHit/plugins
RecoTotemT1T2T2RecHitPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RecHit/plugins/BuildFile
RecoTotemT1T2T2RecHitPlugins_LOC_USE := self  RecoTotemT1T2/T2RecHit FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit
RecoTotemT1T2T2RecHitPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2RecHitPlugins,RecoTotemT1T2T2RecHitPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2RecHit/plugins))
RecoTotemT1T2T2RecHitPlugins_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/plugins
ALL_PRODS += RecoTotemT1T2T2RecHitPlugins
RecoTotemT1T2T2RecHitPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RecHitPlugins,src/RecoTotemT1T2/T2RecHit/plugins,src_RecoTotemT1T2_T2RecHit_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2RecHitPlugins,src/RecoTotemT1T2/T2RecHit/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_plugins
src_RecoTotemT1T2_T2RecHit_plugins_parent := RecoTotemT1T2/T2RecHit
src_RecoTotemT1T2_T2RecHit_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_plugins,src/RecoTotemT1T2/T2RecHit/plugins,PLUGINS))
