ifeq ($(strip $(TotemDQMLite/Geometry)),)
ALL_COMMONRULES += src_TotemDQMLite_Geometry_src
src_TotemDQMLite_Geometry_src_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_src,src/TotemDQMLite/Geometry/src,LIBRARY))
TotemDQMLiteGeometry := self/TotemDQMLite/Geometry
TotemDQMLite/Geometry := TotemDQMLiteGeometry
TotemDQMLiteGeometry_files := $(patsubst src/TotemDQMLite/Geometry/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/Geometry/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteGeometry_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Geometry/BuildFile
TotemDQMLiteGeometry_LOC_USE := self  FWCore/Common clhep
TotemDQMLiteGeometry_EX_LIB   := TotemDQMLiteGeometry
TotemDQMLiteGeometry_EX_USE   := $(foreach d,$(TotemDQMLiteGeometry_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteGeometry_PACKAGE := self/src/TotemDQMLite/Geometry/src
ALL_PRODS += TotemDQMLiteGeometry
TotemDQMLiteGeometry_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteGeometry,src/TotemDQMLite/Geometry/src,src_TotemDQMLite_Geometry_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
