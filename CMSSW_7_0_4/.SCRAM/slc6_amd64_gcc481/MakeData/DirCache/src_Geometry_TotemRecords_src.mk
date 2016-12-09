ifeq ($(strip $(Geometry/TotemRecords)),)
ALL_COMMONRULES += src_Geometry_TotemRecords_src
src_Geometry_TotemRecords_src_parent := Geometry/TotemRecords
src_Geometry_TotemRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRecords_src,src/Geometry/TotemRecords/src,LIBRARY))
GeometryTotemRecords := self/Geometry/TotemRecords
Geometry/TotemRecords := GeometryTotemRecords
GeometryTotemRecords_files := $(patsubst src/Geometry/TotemRecords/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRecords/BuildFile
GeometryTotemRecords_LOC_USE := self  FWCore/Utilities FWCore/Framework Geometry/Records TotemAlignment/RPRecords CondFormats/DataRecord clhep boost
GeometryTotemRecords_EX_LIB   := GeometryTotemRecords
GeometryTotemRecords_EX_USE   := $(foreach d,$(GeometryTotemRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRecords_PACKAGE := self/src/Geometry/TotemRecords/src
ALL_PRODS += GeometryTotemRecords
GeometryTotemRecords_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRecords,src/Geometry/TotemRecords/src,src_Geometry_TotemRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
