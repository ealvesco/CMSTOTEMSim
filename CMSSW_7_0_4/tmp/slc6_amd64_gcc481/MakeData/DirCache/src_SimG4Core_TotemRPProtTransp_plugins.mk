ifeq ($(strip $(SimG4CoreTotemRPProtTranspPlugins)),)
SimG4CoreTotemRPProtTranspPlugins_files := $(patsubst src/SimG4Core/TotemRPProtTransp/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4Core/TotemRPProtTransp/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/TotemRPProtTransp/plugins/$(file). Please fix src/SimG4Core/TotemRPProtTransp/plugins/BuildFile.))))
SimG4CoreTotemRPProtTranspPlugins := self/src/SimG4Core/TotemRPProtTransp/plugins
SimG4CoreTotemRPProtTranspPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/TotemRPProtTransp/plugins/BuildFile
SimG4CoreTotemRPProtTranspPlugins_LOC_USE := self  SimG4Core/Physics FWCore/ParameterSet SimG4Core/TotemRPProtTransp SimG4Core/PhysicsLists FWCore/MessageLogger geant4 FWCore/Framework
SimG4CoreTotemRPProtTranspPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CoreTotemRPProtTranspPlugins,SimG4CoreTotemRPProtTranspPlugins,$(SCRAMSTORENAME_LIB),src/SimG4Core/TotemRPProtTransp/plugins))
SimG4CoreTotemRPProtTranspPlugins_PACKAGE := self/src/SimG4Core/TotemRPProtTransp/plugins
ALL_PRODS += SimG4CoreTotemRPProtTranspPlugins
SimG4CoreTotemRPProtTranspPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreTotemRPProtTranspPlugins,src/SimG4Core/TotemRPProtTransp/plugins,src_SimG4Core_TotemRPProtTransp_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CoreTotemRPProtTranspPlugins,src/SimG4Core/TotemRPProtTransp/plugins))
endif
ALL_COMMONRULES += src_SimG4Core_TotemRPProtTransp_plugins
src_SimG4Core_TotemRPProtTransp_plugins_parent := SimG4Core/TotemRPProtTransp
src_SimG4Core_TotemRPProtTransp_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_TotemRPProtTransp_plugins,src/SimG4Core/TotemRPProtTransp/plugins,PLUGINS))
