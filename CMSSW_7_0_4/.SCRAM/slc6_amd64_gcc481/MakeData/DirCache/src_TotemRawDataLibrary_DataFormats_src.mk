ifeq ($(strip $(TotemRawDataLibrary/DataFormats)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_DataFormats_src
src_TotemRawDataLibrary_DataFormats_src_parent := TotemRawDataLibrary/DataFormats
src_TotemRawDataLibrary_DataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_DataFormats_src,src/TotemRawDataLibrary/DataFormats/src,LIBRARY))
TotemRawDataLibraryDataFormats := self/TotemRawDataLibrary/DataFormats
TotemRawDataLibrary/DataFormats := TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_files := $(patsubst src/TotemRawDataLibrary/DataFormats/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/DataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/DataFormats/BuildFile
TotemRawDataLibraryDataFormats_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataLibraryDataFormats_LOC_USE := self  FWCore/Framework rootrflx
TotemRawDataLibraryDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataLibraryDataFormatsCapabilities,TotemRawDataLibraryDataFormats,$(SCRAMSTORENAME_LIB),src/TotemRawDataLibrary/DataFormats/src))
TotemRawDataLibraryDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemRawDataLibraryDataFormats,0,src/TotemRawDataLibrary/DataFormats/src/classes.h,src/TotemRawDataLibrary/DataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemRawDataLibraryDataFormats_EX_LIB   := TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_EX_USE   := $(foreach d,$(TotemRawDataLibraryDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryDataFormats_PACKAGE := self/src/TotemRawDataLibrary/DataFormats/src
ALL_PRODS += TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryDataFormats,src/TotemRawDataLibrary/DataFormats/src,src_TotemRawDataLibrary_DataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
