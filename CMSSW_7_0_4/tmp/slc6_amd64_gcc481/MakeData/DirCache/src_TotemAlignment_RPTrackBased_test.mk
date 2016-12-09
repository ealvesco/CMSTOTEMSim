ifeq ($(strip $(refactorStatisticalResults)),)
refactorStatisticalResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,refactorStatisticalResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
refactorStatisticalResults := self/src/TotemAlignment/RPTrackBased/test
refactorStatisticalResults_TEST_RUNNER_CMD :=  refactorStatisticalResults 
refactorStatisticalResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
refactorStatisticalResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
refactorStatisticalResults_LOC_USE := self  TotemAlignment/RPDataFormats
refactorStatisticalResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += refactorStatisticalResults
refactorStatisticalResults_INIT_FUNC        += $$(eval $$(call Binary,refactorStatisticalResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,refactorStatisticalResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(analyzeStatisticalResults)),)
analyzeStatisticalResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,analyzeStatisticalResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
analyzeStatisticalResults := self/src/TotemAlignment/RPTrackBased/test
analyzeStatisticalResults_TEST_RUNNER_CMD :=  analyzeStatisticalResults 
analyzeStatisticalResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
analyzeStatisticalResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
analyzeStatisticalResults_LOC_USE := self  root TotemAlignment/RPDataFormats
analyzeStatisticalResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += analyzeStatisticalResults
analyzeStatisticalResults_INIT_FUNC        += $$(eval $$(call Binary,analyzeStatisticalResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,analyzeStatisticalResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(summarizeRealAlignmentResults)),)
summarizeRealAlignmentResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,summarizeRealAlignmentResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
summarizeRealAlignmentResults := self/src/TotemAlignment/RPTrackBased/test
summarizeRealAlignmentResults_TEST_RUNNER_CMD :=  summarizeRealAlignmentResults 
summarizeRealAlignmentResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
summarizeRealAlignmentResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
summarizeRealAlignmentResults_LOC_USE := self  root TotemAlignment/RPDataFormats
summarizeRealAlignmentResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += summarizeRealAlignmentResults
summarizeRealAlignmentResults_INIT_FUNC        += $$(eval $$(call Binary,summarizeRealAlignmentResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,summarizeRealAlignmentResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(TaskDataTestReader)),)
TaskDataTestReader_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,TaskDataTestReader.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
TaskDataTestReader := self/src/TotemAlignment/RPTrackBased/test
TaskDataTestReader_TEST_RUNNER_CMD :=  TaskDataTestReader 
TaskDataTestReader_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
TaskDataTestReader_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TaskDataTestReader_LOC_USE := self  TotemAlignment/RPTrackBased
TaskDataTestReader_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += TaskDataTestReader
TaskDataTestReader_INIT_FUNC        += $$(eval $$(call Binary,TaskDataTestReader,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TaskDataTestReader,src/TotemAlignment/RPTrackBased/test))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_test
src_TotemAlignment_RPTrackBased_test_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_test,src/TotemAlignment/RPTrackBased/test,TEST))
