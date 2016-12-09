ifeq ($(strip $(TotemCondFormats/DataRecord)),)
ALL_COMMONRULES += src_TotemCondFormats_DataRecord_src
src_TotemCondFormats_DataRecord_src_parent := TotemCondFormats/DataRecord
src_TotemCondFormats_DataRecord_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_DataRecord_src,src/TotemCondFormats/DataRecord/src,LIBRARY))
TotemCondFormatsDataRecord := self/TotemCondFormats/DataRecord
TotemCondFormats/DataRecord := TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_files := $(patsubst src/TotemCondFormats/DataRecord/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DataRecord/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsDataRecord_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DataRecord/BuildFile
TotemCondFormatsDataRecord_LOC_USE := self  FWCore/Framework boost Geometry/TotemRecords
TotemCondFormatsDataRecord_EX_LIB   := TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_EX_USE   := $(foreach d,$(TotemCondFormatsDataRecord_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsDataRecord_PACKAGE := self/src/TotemCondFormats/DataRecord/src
ALL_PRODS += TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDataRecord,src/TotemCondFormats/DataRecord/src,src_TotemCondFormats_DataRecord_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
