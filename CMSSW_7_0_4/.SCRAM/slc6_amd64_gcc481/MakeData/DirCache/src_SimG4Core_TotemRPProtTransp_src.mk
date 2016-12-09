ifeq ($(strip $(SimG4Core/TotemRPProtTransp)),)
ALL_COMMONRULES += src_SimG4Core_TotemRPProtTransp_src
src_SimG4Core_TotemRPProtTransp_src_parent := SimG4Core/TotemRPProtTransp
src_SimG4Core_TotemRPProtTransp_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_TotemRPProtTransp_src,src/SimG4Core/TotemRPProtTransp/src,LIBRARY))
SimG4CoreTotemRPProtTransp := self/SimG4Core/TotemRPProtTransp
SimG4Core/TotemRPProtTransp := SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_files := $(patsubst src/SimG4Core/TotemRPProtTransp/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/TotemRPProtTransp/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreTotemRPProtTransp_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/TotemRPProtTransp/BuildFile
SimG4CoreTotemRPProtTransp_LOC_USE := self  FWCore/ParameterSet SimG4CMS/TotemRPProtTranspPar geant4 SimG4Core/Geometry FWCore/ServiceRegistry FWCore/MessageLogger root TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects
SimG4CoreTotemRPProtTransp_EX_LIB   := SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_EX_USE   := $(foreach d,$(SimG4CoreTotemRPProtTransp_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CoreTotemRPProtTransp_PACKAGE := self/src/SimG4Core/TotemRPProtTransp/src
ALL_PRODS += SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreTotemRPProtTransp,src/SimG4Core/TotemRPProtTransp/src,src_SimG4Core_TotemRPProtTransp_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
