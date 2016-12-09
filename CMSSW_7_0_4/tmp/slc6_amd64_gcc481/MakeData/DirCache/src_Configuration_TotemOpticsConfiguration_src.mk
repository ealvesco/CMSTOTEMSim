ifeq ($(strip $(Configuration/TotemOpticsConfiguration)),)
ALL_COMMONRULES += src_Configuration_TotemOpticsConfiguration_src
src_Configuration_TotemOpticsConfiguration_src_parent := Configuration/TotemOpticsConfiguration
src_Configuration_TotemOpticsConfiguration_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Configuration_TotemOpticsConfiguration_src,src/Configuration/TotemOpticsConfiguration/src,LIBRARY))
ConfigurationTotemOpticsConfiguration := self/Configuration/TotemOpticsConfiguration
Configuration/TotemOpticsConfiguration := ConfigurationTotemOpticsConfiguration
ConfigurationTotemOpticsConfiguration_files := $(patsubst src/Configuration/TotemOpticsConfiguration/src/%,%,$(wildcard $(foreach dir,src/Configuration/TotemOpticsConfiguration/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
ConfigurationTotemOpticsConfiguration_BuildFile    := $(WORKINGDIR)/cache/bf/src/Configuration/TotemOpticsConfiguration/BuildFile
ConfigurationTotemOpticsConfiguration_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions DataFormats/TotemRPDataTypes root SimG4CMS/TotemRPProtTranspPar
ConfigurationTotemOpticsConfiguration_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,ConfigurationTotemOpticsConfiguration,ConfigurationTotemOpticsConfiguration,$(SCRAMSTORENAME_LIB),src/Configuration/TotemOpticsConfiguration/src))
ConfigurationTotemOpticsConfiguration_PACKAGE := self/src/Configuration/TotemOpticsConfiguration/src
ALL_PRODS += ConfigurationTotemOpticsConfiguration
ConfigurationTotemOpticsConfiguration_INIT_FUNC        += $$(eval $$(call Library,ConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/src,src_Configuration_TotemOpticsConfiguration_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
