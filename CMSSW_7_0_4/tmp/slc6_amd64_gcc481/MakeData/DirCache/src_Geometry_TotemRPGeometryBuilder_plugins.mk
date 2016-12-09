ifeq ($(strip $(GeometryTotemRPGeometryBuilderPlugins)),)
GeometryTotemRPGeometryBuilderPlugins_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/Geometry/TotemRPGeometryBuilder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Geometry/TotemRPGeometryBuilder/plugins/$(file). Please fix src/Geometry/TotemRPGeometryBuilder/plugins/BuildFile.))))
GeometryTotemRPGeometryBuilderPlugins := self/src/Geometry/TotemRPGeometryBuilder/plugins
GeometryTotemRPGeometryBuilderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPGeometryBuilder/plugins/BuildFile
GeometryTotemRPGeometryBuilderPlugins_LOC_USE := self  SimDataFormats/GeneratorProducts DetectorDescription/Core Geometry/TotemRecords TotemAlignment/RPRecords DataFormats/DetId DataFormats/TotemRPDetId Geometry/TrackerNumberingBuilder Geometry/TotemRPGeometryBuilder clhep hepmc
GeometryTotemRPGeometryBuilderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeometryTotemRPGeometryBuilderPlugins,GeometryTotemRPGeometryBuilderPlugins,$(SCRAMSTORENAME_LIB),src/Geometry/TotemRPGeometryBuilder/plugins))
GeometryTotemRPGeometryBuilderPlugins_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/plugins
ALL_PRODS += GeometryTotemRPGeometryBuilderPlugins
GeometryTotemRPGeometryBuilderPlugins_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPGeometryBuilderPlugins,src/Geometry/TotemRPGeometryBuilder/plugins,src_Geometry_TotemRPGeometryBuilder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,GeometryTotemRPGeometryBuilderPlugins,src/Geometry/TotemRPGeometryBuilder/plugins))
endif
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_plugins
src_Geometry_TotemRPGeometryBuilder_plugins_parent := Geometry/TotemRPGeometryBuilder
src_Geometry_TotemRPGeometryBuilder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_plugins,src/Geometry/TotemRPGeometryBuilder/plugins,PLUGINS))
