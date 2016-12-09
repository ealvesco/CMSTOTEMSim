ifeq ($(strip $(TotemAlignment/RPDataFormats)),)
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_src
src_TotemAlignment_RPDataFormats_src_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_src,src/TotemAlignment/RPDataFormats/src,LIBRARY))
TotemAlignmentRPDataFormats := self/TotemAlignment/RPDataFormats
TotemAlignment/RPDataFormats := TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_files := $(patsubst src/TotemAlignment/RPDataFormats/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/BuildFile
TotemAlignmentRPDataFormats_LOC_USE := self  FWCore/Framework DataFormats/Common DataFormats/Provenance rootrflx DetectorDescription/Core xerces-c root
TotemAlignmentRPDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPDataFormatsCapabilities,TotemAlignmentRPDataFormats,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPDataFormats/src))
TotemAlignmentRPDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAlignmentRPDataFormats,0,src/TotemAlignment/RPDataFormats/src/classes.h,src/TotemAlignment/RPDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB), --fail_on_warnings,Capabilities))
TotemAlignmentRPDataFormats_EX_LIB   := TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_EX_USE   := $(foreach d,$(TotemAlignmentRPDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPDataFormats_PACKAGE := self/src/TotemAlignment/RPDataFormats/src
ALL_PRODS += TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/src,src_TotemAlignment_RPDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
