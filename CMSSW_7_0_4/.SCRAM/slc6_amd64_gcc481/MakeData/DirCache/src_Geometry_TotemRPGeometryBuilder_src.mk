ifeq ($(strip $(Geometry/TotemRPGeometryBuilder)),)
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_src
src_Geometry_TotemRPGeometryBuilder_src_parent := Geometry/TotemRPGeometryBuilder
src_Geometry_TotemRPGeometryBuilder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_src,src/Geometry/TotemRPGeometryBuilder/src,LIBRARY))
GeometryTotemRPGeometryBuilder := self/Geometry/TotemRPGeometryBuilder
Geometry/TotemRPGeometryBuilder := GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPGeometryBuilder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRPGeometryBuilder_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPGeometryBuilder/BuildFile
GeometryTotemRPGeometryBuilder_LOC_USE := self  SimDataFormats/GeneratorProducts DetectorDescription/Core Geometry/TotemRecords DataFormats/DetId DataFormats/TotemRPDetId Geometry/TrackerNumberingBuilder clhep hepmc FWCore/Framework FWCore/MessageLogger TotemAlignment/RPDataFormats
GeometryTotemRPGeometryBuilder_EX_LIB   := GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_EX_USE   := $(foreach d,$(GeometryTotemRPGeometryBuilder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRPGeometryBuilder_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/src
ALL_PRODS += GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/src,src_Geometry_TotemRPGeometryBuilder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
