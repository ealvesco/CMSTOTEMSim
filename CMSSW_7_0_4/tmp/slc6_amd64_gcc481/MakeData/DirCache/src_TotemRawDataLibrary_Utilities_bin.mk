ifeq ($(strip $(TotemReadFile)),)
TotemReadFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,readFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemReadFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemReadFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemReadFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemReadFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemReadFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemReadFile
TotemReadFile_INIT_FUNC        += $$(eval $$(call Binary,TotemReadFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemReadFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ifeq ($(strip $(TotemCheckFile)),)
TotemCheckFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,checkFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemCheckFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemCheckFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemCheckFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemCheckFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemCheckFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemCheckFile
TotemCheckFile_INIT_FUNC        += $$(eval $$(call Binary,TotemCheckFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCheckFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ifeq ($(strip $(TotemAnalyzeFile)),)
TotemAnalyzeFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,analyzeFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemAnalyzeFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemAnalyzeFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemAnalyzeFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAnalyzeFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemAnalyzeFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemAnalyzeFile
TotemAnalyzeFile_INIT_FUNC        += $$(eval $$(call Binary,TotemAnalyzeFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalyzeFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ALL_COMMONRULES += src_TotemRawDataLibrary_Utilities_bin
src_TotemRawDataLibrary_Utilities_bin_parent := TotemRawDataLibrary/Utilities
src_TotemRawDataLibrary_Utilities_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Utilities_bin,src/TotemRawDataLibrary/Utilities/bin,BINARY))
