ifeq ($(strip $(TotemAlignmentRPTrackBasedPlugins)),)
TotemAlignmentRPTrackBasedPlugins_files := $(patsubst src/TotemAlignment/RPTrackBased/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/plugins/$(file). Please fix src/TotemAlignment/RPTrackBased/plugins/BuildFile.))))
TotemAlignmentRPTrackBasedPlugins := self/src/TotemAlignment/RPTrackBased/plugins
TotemAlignmentRPTrackBasedPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/plugins/BuildFile
TotemAlignmentRPTrackBasedPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAlignmentRPTrackBasedPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet hepmc clhep DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder root TotemAlignment/RPTrackBased TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord Geometry/TotemRPDetTopology
TotemAlignmentRPTrackBasedPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPTrackBasedPlugins,TotemAlignmentRPTrackBasedPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPTrackBased/plugins))
TotemAlignmentRPTrackBasedPlugins_PACKAGE := self/src/TotemAlignment/RPTrackBased/plugins
ALL_PRODS += TotemAlignmentRPTrackBasedPlugins
TotemAlignmentRPTrackBasedPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPTrackBasedPlugins,src/TotemAlignment/RPTrackBased/plugins,src_TotemAlignment_RPTrackBased_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPTrackBasedPlugins,src/TotemAlignment/RPTrackBased/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_plugins
src_TotemAlignment_RPTrackBased_plugins_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_plugins,src/TotemAlignment/RPTrackBased/plugins,PLUGINS))
