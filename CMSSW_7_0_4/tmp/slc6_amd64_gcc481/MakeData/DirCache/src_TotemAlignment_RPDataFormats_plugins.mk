ifeq ($(strip $(TotemAlignmentRPDataFormatsPlugins)),)
TotemAlignmentRPDataFormatsPlugins_files := $(patsubst src/TotemAlignment/RPDataFormats/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPDataFormats/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPDataFormats/plugins/$(file). Please fix src/TotemAlignment/RPDataFormats/plugins/BuildFile.))))
TotemAlignmentRPDataFormatsPlugins := self/src/TotemAlignment/RPDataFormats/plugins
TotemAlignmentRPDataFormatsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/plugins/BuildFile
TotemAlignmentRPDataFormatsPlugins_LOC_USE := self  TotemAlignment/RPDataFormats TotemAlignment/RPRecords FWCore/Framework Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAlignmentRPDataFormatsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPDataFormatsPlugins,TotemAlignmentRPDataFormatsPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPDataFormats/plugins))
TotemAlignmentRPDataFormatsPlugins_PACKAGE := self/src/TotemAlignment/RPDataFormats/plugins
ALL_PRODS += TotemAlignmentRPDataFormatsPlugins
TotemAlignmentRPDataFormatsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPDataFormatsPlugins,src/TotemAlignment/RPDataFormats/plugins,src_TotemAlignment_RPDataFormats_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPDataFormatsPlugins,src/TotemAlignment/RPDataFormats/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_plugins
src_TotemAlignment_RPDataFormats_plugins_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_plugins,src/TotemAlignment/RPDataFormats/plugins,PLUGINS))
