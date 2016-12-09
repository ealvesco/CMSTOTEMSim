ifeq ($(strip $(TotemAlignment/RPTrackBased)),)
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_src
src_TotemAlignment_RPTrackBased_src_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_src,src/TotemAlignment/RPTrackBased/src,LIBRARY))
TotemAlignmentRPTrackBased := self/TotemAlignment/RPTrackBased
TotemAlignment/RPTrackBased := TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_files := $(patsubst src/TotemAlignment/RPTrackBased/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPTrackBased/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPTrackBased_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/BuildFile
TotemAlignmentRPTrackBased_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAlignmentRPTrackBased_LOC_USE := self  clhep root rootgraphics DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemAlignment/RPDataFormats RecoTotemRP/RPRecoDataFormats TotemAlignment/RPRecords
TotemAlignmentRPTrackBased_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPTrackBasedCapabilities,TotemAlignmentRPTrackBased,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPTrackBased/src))
TotemAlignmentRPTrackBased_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAlignmentRPTrackBased,0,src/TotemAlignment/RPTrackBased/src/classes.h,src/TotemAlignment/RPTrackBased/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemAlignmentRPTrackBased_EX_LIB   := TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_EX_USE   := $(foreach d,$(TotemAlignmentRPTrackBased_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPTrackBased_PACKAGE := self/src/TotemAlignment/RPTrackBased/src
ALL_PRODS += TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/src,src_TotemAlignment_RPTrackBased_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
