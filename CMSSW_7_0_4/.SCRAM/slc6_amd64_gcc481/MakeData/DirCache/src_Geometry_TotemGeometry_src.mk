ifeq ($(strip $(Geometry/TotemGeometry)),)
ALL_COMMONRULES += src_Geometry_TotemGeometry_src
src_Geometry_TotemGeometry_src_parent := Geometry/TotemGeometry
src_Geometry_TotemGeometry_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemGeometry_src,src/Geometry/TotemGeometry/src,LIBRARY))
GeometryTotemGeometry := self/Geometry/TotemGeometry
Geometry/TotemGeometry := GeometryTotemGeometry
GeometryTotemGeometry_files := $(patsubst src/Geometry/TotemGeometry/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemGeometry/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemGeometry_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemGeometry/BuildFile
GeometryTotemGeometry_LOC_USE := self  DataFormats/DetId DataFormats/T1DetId DataFormats/T2DetId DataFormats/T2Cluster FWCore/Framework Geometry/Records clhep
GeometryTotemGeometry_EX_LIB   := GeometryTotemGeometry
GeometryTotemGeometry_EX_USE   := $(foreach d,$(GeometryTotemGeometry_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemGeometry_PACKAGE := self/src/Geometry/TotemGeometry/src
ALL_PRODS += GeometryTotemGeometry
GeometryTotemGeometry_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemGeometry,src/Geometry/TotemGeometry/src,src_Geometry_TotemGeometry_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
