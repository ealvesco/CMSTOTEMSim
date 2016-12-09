ifeq ($(strip $(TotemAlignment/RPRates)),)
ALL_COMMONRULES += src_TotemAlignment_RPRates_src
src_TotemAlignment_RPRates_src_parent := TotemAlignment/RPRates
src_TotemAlignment_RPRates_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_src,src/TotemAlignment/RPRates/src,LIBRARY))
TotemAlignmentRPRates := self/TotemAlignment/RPRates
TotemAlignment/RPRates := TotemAlignmentRPRates
TotemAlignmentRPRates_files := $(patsubst src/TotemAlignment/RPRates/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRates/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPRates_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRates/BuildFile
TotemAlignmentRPRates_LOC_USE := self  root Geometry/TotemRPGeometryBuilder Geometry/TotemRPDetTopology
TotemAlignmentRPRates_EX_LIB   := TotemAlignmentRPRates
TotemAlignmentRPRates_EX_USE   := $(foreach d,$(TotemAlignmentRPRates_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPRates_PACKAGE := self/src/TotemAlignment/RPRates/src
ALL_PRODS += TotemAlignmentRPRates
TotemAlignmentRPRates_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRates,src/TotemAlignment/RPRates/src,src_TotemAlignment_RPRates_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
