ifeq ($(strip $(SimTotemT2DigitizerPlugins)),)
SimTotemT2DigitizerPlugins_files := $(patsubst src/SimTotem/T2Digitizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimTotem/T2Digitizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimTotem/T2Digitizer/plugins/$(file). Please fix src/SimTotem/T2Digitizer/plugins/BuildFile.))))
SimTotemT2DigitizerPlugins := self/src/SimTotem/T2Digitizer/plugins
SimTotemT2DigitizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T2Digitizer/plugins/BuildFile
SimTotemT2DigitizerPlugins_LOC_USE := self  SimTotem/T2Digitizer FWCore/Framework FWCore/ParameterSet Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId DataFormats/T2DigiVfat SimDataFormats/TrackingHit Geometry/TotemRecords Geometry/TotemT2AlignmentDataFormats Geometry/CommonDetUnit Geometry/TotemGeometry SimTracker/Common Mixing/Base geant4 root boost clhep gsl hepmc
SimTotemT2DigitizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemT2DigitizerPlugins,SimTotemT2DigitizerPlugins,$(SCRAMSTORENAME_LIB),src/SimTotem/T2Digitizer/plugins))
SimTotemT2DigitizerPlugins_PACKAGE := self/src/SimTotem/T2Digitizer/plugins
ALL_PRODS += SimTotemT2DigitizerPlugins
SimTotemT2DigitizerPlugins_INIT_FUNC        += $$(eval $$(call Library,SimTotemT2DigitizerPlugins,src/SimTotem/T2Digitizer/plugins,src_SimTotem_T2Digitizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemT2DigitizerPlugins,src/SimTotem/T2Digitizer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_T2Digitizer_plugins
src_SimTotem_T2Digitizer_plugins_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_plugins,src/SimTotem/T2Digitizer/plugins,PLUGINS))
