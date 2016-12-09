ifeq ($(strip $(ElegentBDistributionSampler)),)
ElegentBDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentBDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentBDistributionSampler := self/src/IOMC/Elegent/bin
ElegentBDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentBDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentBDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentBDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentBDistributionSampler
ElegentBDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentBDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentBDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentSDistributionSampler)),)
ElegentSDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentSDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentSDistributionSampler := self/src/IOMC/Elegent/bin
ElegentSDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentSDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentSDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentSDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentSDistributionSampler
ElegentSDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentSDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentSDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentTDistributionSampler)),)
ElegentTDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentTDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentTDistributionSampler := self/src/IOMC/Elegent/bin
ElegentTDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentTDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentTDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentTDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentTDistributionSampler
ElegentTDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentTDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentTDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentTest)),)
ElegentTest_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentTest.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentTest := self/src/IOMC/Elegent/bin
ElegentTest_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentTest_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentTest_LOC_USE := self  IOMC/Elegent
ElegentTest_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentTest
ElegentTest_INIT_FUNC        += $$(eval $$(call Binary,ElegentTest,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentTest,src/IOMC/Elegent/bin))
endif
ALL_COMMONRULES += src_IOMC_Elegent_bin
src_IOMC_Elegent_bin_parent := IOMC/Elegent
src_IOMC_Elegent_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_bin,src/IOMC/Elegent/bin,BINARY))
