ifeq ($(strip $(GeneratorInterfaceCosmicRayInterfacePlugins)),)
GeneratorInterfaceCosmicRayInterfacePlugins_files := $(patsubst src/GeneratorInterface/CosmicRayInterface/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/GeneratorInterface/CosmicRayInterface/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/GeneratorInterface/CosmicRayInterface/plugins/$(file). Please fix src/GeneratorInterface/CosmicRayInterface/plugins/BuildFile.))))
GeneratorInterfaceCosmicRayInterfacePlugins := self/src/GeneratorInterface/CosmicRayInterface/plugins
GeneratorInterfaceCosmicRayInterfacePlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/GeneratorInterface/CosmicRayInterface/plugins/BuildFile
GeneratorInterfaceCosmicRayInterfacePlugins_LOC_USE := self  GeneratorInterface/CosmicRayInterface
GeneratorInterfaceCosmicRayInterfacePlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeneratorInterfaceCosmicRayInterfacePlugins,GeneratorInterfaceCosmicRayInterfacePlugins,$(SCRAMSTORENAME_LIB),src/GeneratorInterface/CosmicRayInterface/plugins))
GeneratorInterfaceCosmicRayInterfacePlugins_PACKAGE := self/src/GeneratorInterface/CosmicRayInterface/plugins
ALL_PRODS += GeneratorInterfaceCosmicRayInterfacePlugins
GeneratorInterfaceCosmicRayInterfacePlugins_INIT_FUNC        += $$(eval $$(call Library,GeneratorInterfaceCosmicRayInterfacePlugins,src/GeneratorInterface/CosmicRayInterface/plugins,src_GeneratorInterface_CosmicRayInterface_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,GeneratorInterfaceCosmicRayInterfacePlugins,src/GeneratorInterface/CosmicRayInterface/plugins))
endif
ALL_COMMONRULES += src_GeneratorInterface_CosmicRayInterface_plugins
src_GeneratorInterface_CosmicRayInterface_plugins_parent := GeneratorInterface/CosmicRayInterface
src_GeneratorInterface_CosmicRayInterface_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GeneratorInterface_CosmicRayInterface_plugins,src/GeneratorInterface/CosmicRayInterface/plugins,PLUGINS))
