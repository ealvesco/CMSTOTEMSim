ifeq ($(strip $(SimTotemT1DigitizerPlugins)),)
SimTotemT1DigitizerPlugins_files := $(patsubst src/SimTotem/T1Digitizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimTotem/T1Digitizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimTotem/T1Digitizer/plugins/$(file). Please fix src/SimTotem/T1Digitizer/plugins/BuildFile.))))
SimTotemT1DigitizerPlugins := self/src/SimTotem/T1Digitizer/plugins
SimTotemT1DigitizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T1Digitizer/plugins/BuildFile
SimTotemT1DigitizerPlugins_LOC_USE := self  SimTotem/T1Digitizer DataFormats/Common DataFormats/Provenance FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimGeneral/HepPDTRecord Utilities/Timing FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/DetId DataFormats/T1Digi DataFormats/T1DetId DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1TestElements boost root clhep
SimTotemT1DigitizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemT1DigitizerPlugins,SimTotemT1DigitizerPlugins,$(SCRAMSTORENAME_LIB),src/SimTotem/T1Digitizer/plugins))
SimTotemT1DigitizerPlugins_PACKAGE := self/src/SimTotem/T1Digitizer/plugins
ALL_PRODS += SimTotemT1DigitizerPlugins
SimTotemT1DigitizerPlugins_INIT_FUNC        += $$(eval $$(call Library,SimTotemT1DigitizerPlugins,src/SimTotem/T1Digitizer/plugins,src_SimTotem_T1Digitizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemT1DigitizerPlugins,src/SimTotem/T1Digitizer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_T1Digitizer_plugins
src_SimTotem_T1Digitizer_plugins_parent := SimTotem/T1Digitizer
src_SimTotem_T1Digitizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_plugins,src/SimTotem/T1Digitizer/plugins,PLUGINS))
