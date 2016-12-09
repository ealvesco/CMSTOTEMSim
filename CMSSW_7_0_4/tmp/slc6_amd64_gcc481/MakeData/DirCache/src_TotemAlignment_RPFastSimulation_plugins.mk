ifeq ($(strip $(TotemAlignmentRPFastSimulation)),)
TotemAlignmentRPFastSimulation_files := $(patsubst src/TotemAlignment/RPFastSimulation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPFastSimulation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPFastSimulation/plugins/$(file). Please fix src/TotemAlignment/RPFastSimulation/plugins/BuildFile.))))
TotemAlignmentRPFastSimulation := self/src/TotemAlignment/RPFastSimulation/plugins
TotemAlignmentRPFastSimulation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPFastSimulation/plugins/BuildFile
TotemAlignmentRPFastSimulation_LOC_USE := self  hepmc clhep FWCore/Framework FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities SimDataFormats/GeneratorProducts Geometry/TotemRPDetTopology DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder Geometry/TotemRecords RecoTotemRP/RPRecoDataFormats TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord SimG4CMS/TotemRPProtTranspPar TotemAlignment/RPDataFormats
TotemAlignmentRPFastSimulation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPFastSimulation,TotemAlignmentRPFastSimulation,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPFastSimulation/plugins))
TotemAlignmentRPFastSimulation_PACKAGE := self/src/TotemAlignment/RPFastSimulation/plugins
ALL_PRODS += TotemAlignmentRPFastSimulation
TotemAlignmentRPFastSimulation_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/plugins,src_TotemAlignment_RPFastSimulation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_plugins
src_TotemAlignment_RPFastSimulation_plugins_parent := TotemAlignment/RPFastSimulation
src_TotemAlignment_RPFastSimulation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_plugins,src/TotemAlignment/RPFastSimulation/plugins,PLUGINS))
