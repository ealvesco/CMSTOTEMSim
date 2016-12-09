ifeq ($(strip $(TotemAlignment/RPRecords)),)
ALL_COMMONRULES += src_TotemAlignment_RPRecords_src
src_TotemAlignment_RPRecords_src_parent := TotemAlignment/RPRecords
src_TotemAlignment_RPRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRecords_src,src/TotemAlignment/RPRecords/src,LIBRARY))
TotemAlignmentRPRecords := self/TotemAlignment/RPRecords
TotemAlignment/RPRecords := TotemAlignmentRPRecords
TotemAlignmentRPRecords_files := $(patsubst src/TotemAlignment/RPRecords/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRecords/BuildFile
TotemAlignmentRPRecords_LOC_USE := self  FWCore/Framework
TotemAlignmentRPRecords_EX_LIB   := TotemAlignmentRPRecords
TotemAlignmentRPRecords_EX_USE   := $(foreach d,$(TotemAlignmentRPRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPRecords_PACKAGE := self/src/TotemAlignment/RPRecords/src
ALL_PRODS += TotemAlignmentRPRecords
TotemAlignmentRPRecords_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRecords,src/TotemAlignment/RPRecords/src,src_TotemAlignment_RPRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
