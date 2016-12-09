ifeq ($(strip $(Geometry/TotemT2AlignmentDataFormats)),)
ALL_COMMONRULES += src_Geometry_TotemT2AlignmentDataFormats_src
src_Geometry_TotemT2AlignmentDataFormats_src_parent := Geometry/TotemT2AlignmentDataFormats
src_Geometry_TotemT2AlignmentDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemT2AlignmentDataFormats_src,src/Geometry/TotemT2AlignmentDataFormats/src,LIBRARY))
GeometryTotemT2AlignmentDataFormats := self/Geometry/TotemT2AlignmentDataFormats
Geometry/TotemT2AlignmentDataFormats := GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_files := $(patsubst src/Geometry/TotemT2AlignmentDataFormats/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemT2AlignmentDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemT2AlignmentDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemT2AlignmentDataFormats/BuildFile
GeometryTotemT2AlignmentDataFormats_LOC_USE := self  FWCore/Framework rootrflx DetectorDescription/Core Geometry/TotemGeometry
GeometryTotemT2AlignmentDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeometryTotemT2AlignmentDataFormatsCapabilities,GeometryTotemT2AlignmentDataFormats,$(SCRAMSTORENAME_LIB),src/Geometry/TotemT2AlignmentDataFormats/src))
GeometryTotemT2AlignmentDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,GeometryTotemT2AlignmentDataFormats,0,src/Geometry/TotemT2AlignmentDataFormats/src/classes.h,src/Geometry/TotemT2AlignmentDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB), --fail_on_warnings,Capabilities))
GeometryTotemT2AlignmentDataFormats_EX_LIB   := GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_EX_USE   := $(foreach d,$(GeometryTotemT2AlignmentDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemT2AlignmentDataFormats_PACKAGE := self/src/Geometry/TotemT2AlignmentDataFormats/src
ALL_PRODS += GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemT2AlignmentDataFormats,src/Geometry/TotemT2AlignmentDataFormats/src,src_Geometry_TotemT2AlignmentDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
