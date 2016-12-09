ifeq ($(strip $(TotemCondFormats/DAQInformation)),)
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_src
src_TotemCondFormats_DAQInformation_src_parent := TotemCondFormats/DAQInformation
src_TotemCondFormats_DAQInformation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_src,src/TotemCondFormats/DAQInformation/src,LIBRARY))
TotemCondFormatsDAQInformation := self/TotemCondFormats/DAQInformation
TotemCondFormats/DAQInformation := TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_files := $(patsubst src/TotemCondFormats/DAQInformation/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DAQInformation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsDAQInformation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DAQInformation/BuildFile
TotemCondFormatsDAQInformation_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/DataFormats
TotemCondFormatsDAQInformation_EX_LIB   := TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_EX_USE   := $(foreach d,$(TotemCondFormatsDAQInformation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsDAQInformation_PACKAGE := self/src/TotemCondFormats/DAQInformation/src
ALL_PRODS += TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/src,src_TotemCondFormats_DAQInformation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
