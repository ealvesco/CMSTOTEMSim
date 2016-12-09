ifeq ($(strip $(TotemDQMLite/Modules)),)
ALL_COMMONRULES += src_TotemDQMLite_Modules_src
src_TotemDQMLite_Modules_src_parent := TotemDQMLite/Modules
src_TotemDQMLite_Modules_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_Modules_src,src/TotemDQMLite/Modules/src,LIBRARY))
TotemDQMLiteModules := self/TotemDQMLite/Modules
TotemDQMLite/Modules := TotemDQMLiteModules
TotemDQMLiteModules_files := $(patsubst src/TotemDQMLite/Modules/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/Modules/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteModules_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Modules/BuildFile
TotemDQMLiteModules_LOC_USE := self  FWCore/ParameterSet FWCore/Common TotemDQMLite/Core TotemDQMLite/Geometry Geometry/TotemRPDetTopology Geometry/TotemGeometry DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/T2Hit rootgraphics qt
TotemDQMLiteModules_EX_LIB   := TotemDQMLiteModules
TotemDQMLiteModules_EX_USE   := $(foreach d,$(TotemDQMLiteModules_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteModules_PACKAGE := self/src/TotemDQMLite/Modules/src
ALL_PRODS += TotemDQMLiteModules
TotemDQMLiteModules_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteModules,src/TotemDQMLite/Modules/src,src_TotemDQMLite_Modules_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
