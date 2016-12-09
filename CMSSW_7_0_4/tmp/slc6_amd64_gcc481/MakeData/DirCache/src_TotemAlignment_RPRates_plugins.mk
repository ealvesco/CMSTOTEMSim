ifeq ($(strip $(TotemAlignmentRPRatesPlugins)),)
TotemAlignmentRPRatesPlugins_files := $(patsubst src/TotemAlignment/RPRates/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPRates/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPRates/plugins/$(file). Please fix src/TotemAlignment/RPRates/plugins/BuildFile.))))
TotemAlignmentRPRatesPlugins := self/src/TotemAlignment/RPRates/plugins
TotemAlignmentRPRatesPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRates/plugins/BuildFile
TotemAlignmentRPRatesPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder root hepmc TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord SimG4CMS/TotemRPProtTranspPar TotemAlignment/RPRates
TotemAlignmentRPRatesPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPRatesPlugins,TotemAlignmentRPRatesPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPRates/plugins))
TotemAlignmentRPRatesPlugins_PACKAGE := self/src/TotemAlignment/RPRates/plugins
ALL_PRODS += TotemAlignmentRPRatesPlugins
TotemAlignmentRPRatesPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRatesPlugins,src/TotemAlignment/RPRates/plugins,src_TotemAlignment_RPRates_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPRatesPlugins,src/TotemAlignment/RPRates/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPRates_plugins
src_TotemAlignment_RPRates_plugins_parent := TotemAlignment/RPRates
src_TotemAlignment_RPRates_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_plugins,src/TotemAlignment/RPRates/plugins,PLUGINS))
