ifeq ($(strip $(TotemDQMLiteGeometryPlugins)),)
TotemDQMLiteGeometryPlugins_files := $(patsubst src/TotemDQMLite/Geometry/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemDQMLite/Geometry/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemDQMLite/Geometry/plugins/$(file). Please fix src/TotemDQMLite/Geometry/plugins/BuildFile.))))
TotemDQMLiteGeometryPlugins := self/src/TotemDQMLite/Geometry/plugins
TotemDQMLiteGeometryPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Geometry/plugins/BuildFile
TotemDQMLiteGeometryPlugins_LOC_USE := self  Geometry/TotemRPGeometryBuilder
TotemDQMLiteGeometryPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemDQMLiteGeometryPlugins,TotemDQMLiteGeometryPlugins,$(SCRAMSTORENAME_LIB),src/TotemDQMLite/Geometry/plugins))
TotemDQMLiteGeometryPlugins_PACKAGE := self/src/TotemDQMLite/Geometry/plugins
ALL_PRODS += TotemDQMLiteGeometryPlugins
TotemDQMLiteGeometryPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteGeometryPlugins,src/TotemDQMLite/Geometry/plugins,src_TotemDQMLite_Geometry_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemDQMLiteGeometryPlugins,src/TotemDQMLite/Geometry/plugins))
endif
ALL_COMMONRULES += src_TotemDQMLite_Geometry_plugins
src_TotemDQMLite_Geometry_plugins_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_plugins,src/TotemDQMLite/Geometry/plugins,PLUGINS))
