ifeq ($(strip $(TotemCondFormats/ProtonTransportFunctions)),)
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_src
src_TotemCondFormats_ProtonTransportFunctions_src_parent := TotemCondFormats/ProtonTransportFunctions
src_TotemCondFormats_ProtonTransportFunctions_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_src,src/TotemCondFormats/ProtonTransportFunctions/src,LIBRARY))
TotemCondFormatsProtonTransportFunctions := self/TotemCondFormats/ProtonTransportFunctions
TotemCondFormats/ProtonTransportFunctions := TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/ProtonTransportFunctions/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsProtonTransportFunctions_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/ProtonTransportFunctions/BuildFile
TotemCondFormatsProtonTransportFunctions_LOC_USE := self  FWCore/Framework root TotemCondFormats/BeamOpticsParamsObjects SimG4CMS/TotemRPProtTranspPar
TotemCondFormatsProtonTransportFunctions_EX_LIB   := TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_EX_USE   := $(foreach d,$(TotemCondFormatsProtonTransportFunctions_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsProtonTransportFunctions_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/src
ALL_PRODS += TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/src,src_TotemCondFormats_ProtonTransportFunctions_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
