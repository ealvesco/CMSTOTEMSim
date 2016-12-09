ifeq ($(strip $(TotemRawDataLibrary/Readers)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_Readers_src
src_TotemRawDataLibrary_Readers_src_parent := TotemRawDataLibrary/Readers
src_TotemRawDataLibrary_Readers_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Readers_src,src/TotemRawDataLibrary/Readers/src,LIBRARY))
TotemRawDataLibraryReaders := self/TotemRawDataLibrary/Readers
TotemRawDataLibrary/Readers := TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_files := $(patsubst src/TotemRawDataLibrary/Readers/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/Readers/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryReaders_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Readers/BuildFile
TotemRawDataLibraryReaders_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS) -lXrdPosix -lXrdPosixPreload
TotemRawDataLibraryReaders_LOC_FLAGS_CPPDEFINES   := -DUSE_XROOTD=1 -DUSE_CASTOR=1
TotemRawDataLibraryReaders_LOC_USE := self  TotemRawDataLibrary/DataFormats xrootd castor
TotemRawDataLibraryReaders_EX_LIB   := TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_EX_USE   := $(foreach d,$(TotemRawDataLibraryReaders_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryReaders_PACKAGE := self/src/TotemRawDataLibrary/Readers/src
ALL_PRODS += TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryReaders,src/TotemRawDataLibrary/Readers/src,src_TotemRawDataLibrary_Readers_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
