ifeq ($(strip $(TotemT1T2ValidationT1ValidationPlugins)),)
TotemT1T2ValidationT1ValidationPlugins_files := $(patsubst src/TotemT1T2Validation/T1Validation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemT1T2Validation/T1Validation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemT1T2Validation/T1Validation/plugins/$(file). Please fix src/TotemT1T2Validation/T1Validation/plugins/BuildFile.))))
TotemT1T2ValidationT1ValidationPlugins := self/src/TotemT1T2Validation/T1Validation/plugins
TotemT1T2ValidationT1ValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T1Validation/plugins/BuildFile
TotemT1T2ValidationT1ValidationPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/DetId DataFormats/T1DetId Geometry/TotemGeometry Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/Common DataFormats/T1Cluster SimDataFormats/Track CommonTools/Clustering1D boost root clhep
TotemT1T2ValidationT1ValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT1ValidationPlugins,TotemT1T2ValidationT1ValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T1Validation/plugins))
TotemT1T2ValidationT1ValidationPlugins_PACKAGE := self/src/TotemT1T2Validation/T1Validation/plugins
ALL_PRODS += TotemT1T2ValidationT1ValidationPlugins
TotemT1T2ValidationT1ValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT1ValidationPlugins,src/TotemT1T2Validation/T1Validation/plugins,src_TotemT1T2Validation_T1Validation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemT1T2ValidationT1ValidationPlugins,src/TotemT1T2Validation/T1Validation/plugins))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T1Validation_plugins
src_TotemT1T2Validation_T1Validation_plugins_parent := TotemT1T2Validation/T1Validation
src_TotemT1T2Validation_T1Validation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T1Validation_plugins,src/TotemT1T2Validation/T1Validation/plugins,PLUGINS))
