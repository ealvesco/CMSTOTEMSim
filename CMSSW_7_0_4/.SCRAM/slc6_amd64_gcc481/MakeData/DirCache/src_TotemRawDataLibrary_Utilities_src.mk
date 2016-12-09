ifeq ($(strip $(TotemRawDataLibrary/Utilities)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_Utilities_src
src_TotemRawDataLibrary_Utilities_src_parent := TotemRawDataLibrary/Utilities
src_TotemRawDataLibrary_Utilities_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Utilities_src,src/TotemRawDataLibrary/Utilities/src,LIBRARY))
TotemRawDataLibraryUtilities := self/TotemRawDataLibrary/Utilities
TotemRawDataLibrary/Utilities := TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_files := $(patsubst src/TotemRawDataLibrary/Utilities/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/Utilities/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryUtilities_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/BuildFile
TotemRawDataLibraryUtilities_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataLibraryUtilities_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/DataFormats
TotemRawDataLibraryUtilities_EX_LIB   := TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_EX_USE   := $(foreach d,$(TotemRawDataLibraryUtilities_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryUtilities_PACKAGE := self/src/TotemRawDataLibrary/Utilities/src
ALL_PRODS += TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryUtilities,src/TotemRawDataLibrary/Utilities/src,src_TotemRawDataLibrary_Utilities_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
