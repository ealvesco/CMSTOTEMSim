ifeq ($(strip $(Geometry/TotemRPDetTopology)),)
ALL_COMMONRULES += src_Geometry_TotemRPDetTopology_src
src_Geometry_TotemRPDetTopology_src_parent := Geometry/TotemRPDetTopology
src_Geometry_TotemRPDetTopology_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRPDetTopology_src,src/Geometry/TotemRPDetTopology/src,LIBRARY))
GeometryTotemRPDetTopology := self/Geometry/TotemRPDetTopology
Geometry/TotemRPDetTopology := GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_files := $(patsubst src/Geometry/TotemRPDetTopology/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPDetTopology/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRPDetTopology_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPDetTopology/BuildFile
GeometryTotemRPDetTopology_LOC_USE := self  clhep FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet DataFormats/Common DataFormats/GeometryVector SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts boost hepmc rootrflx DataFormats/TotemRPDataTypes
GeometryTotemRPDetTopology_EX_LIB   := GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_EX_USE   := $(foreach d,$(GeometryTotemRPDetTopology_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRPDetTopology_PACKAGE := self/src/Geometry/TotemRPDetTopology/src
ALL_PRODS += GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPDetTopology,src/Geometry/TotemRPDetTopology/src,src_Geometry_TotemRPDetTopology_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
