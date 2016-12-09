ifeq ($(strip $(TotemT1T2Validation/T2GeometryValidation)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2GeometryValidation_src
src_TotemT1T2Validation_T2GeometryValidation_src_parent := TotemT1T2Validation/T2GeometryValidation
src_TotemT1T2Validation_T2GeometryValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2GeometryValidation_src,src/TotemT1T2Validation/T2GeometryValidation/src,LIBRARY))
TotemT1T2ValidationT2GeometryValidation := self/TotemT1T2Validation/T2GeometryValidation
TotemT1T2Validation/T2GeometryValidation := TotemT1T2ValidationT2GeometryValidation
TotemT1T2ValidationT2GeometryValidation_files := $(patsubst src/TotemT1T2Validation/T2GeometryValidation/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2GeometryValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2GeometryValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2GeometryValidation/BuildFile
TotemT1T2ValidationT2GeometryValidation_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root rootcore DataFormats/T2Cluster TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord SimDataFormats/GeneratorProducts DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep xerces-c
TotemT1T2ValidationT2GeometryValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2GeometryValidation,TotemT1T2ValidationT2GeometryValidation,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2GeometryValidation/src))
TotemT1T2ValidationT2GeometryValidation_PACKAGE := self/src/TotemT1T2Validation/T2GeometryValidation/src
ALL_PRODS += TotemT1T2ValidationT2GeometryValidation
TotemT1T2ValidationT2GeometryValidation_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/src,src_TotemT1T2Validation_T2GeometryValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
