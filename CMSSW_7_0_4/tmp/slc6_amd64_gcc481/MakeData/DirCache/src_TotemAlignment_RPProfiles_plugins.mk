ifeq ($(strip $(TotemAlignmentRPProfilesPlugins)),)
TotemAlignmentRPProfilesPlugins_files := $(patsubst src/TotemAlignment/RPProfiles/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPProfiles/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPProfiles/plugins/$(file). Please fix src/TotemAlignment/RPProfiles/plugins/BuildFile.))))
TotemAlignmentRPProfilesPlugins := self/src/TotemAlignment/RPProfiles/plugins
TotemAlignmentRPProfilesPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPProfiles/plugins/BuildFile
TotemAlignmentRPProfilesPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder TotemAlignment/RPTrackBased root
TotemAlignmentRPProfilesPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPProfilesPlugins,TotemAlignmentRPProfilesPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPProfiles/plugins))
TotemAlignmentRPProfilesPlugins_PACKAGE := self/src/TotemAlignment/RPProfiles/plugins
ALL_PRODS += TotemAlignmentRPProfilesPlugins
TotemAlignmentRPProfilesPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPProfilesPlugins,src/TotemAlignment/RPProfiles/plugins,src_TotemAlignment_RPProfiles_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPProfilesPlugins,src/TotemAlignment/RPProfiles/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPProfiles_plugins
src_TotemAlignment_RPProfiles_plugins_parent := TotemAlignment/RPProfiles
src_TotemAlignment_RPProfiles_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_plugins,src/TotemAlignment/RPProfiles/plugins,PLUGINS))
