ifeq ($(strip $(TotemT1T2Validation/T2RecoValidation)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2RecoValidation_src
src_TotemT1T2Validation_T2RecoValidation_src_parent := TotemT1T2Validation/T2RecoValidation
src_TotemT1T2Validation_T2RecoValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2RecoValidation_src,src/TotemT1T2Validation/T2RecoValidation/src,LIBRARY))
TotemT1T2ValidationT2RecoValidation := self/TotemT1T2Validation/T2RecoValidation
TotemT1T2Validation/T2RecoValidation := TotemT1T2ValidationT2RecoValidation
TotemT1T2ValidationT2RecoValidation_files := $(patsubst src/TotemT1T2Validation/T2RecoValidation/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2RecoValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2RecoValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2RecoValidation/BuildFile
TotemT1T2ValidationT2RecoValidation_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep
TotemT1T2ValidationT2RecoValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2RecoValidation,TotemT1T2ValidationT2RecoValidation,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2RecoValidation/src))
TotemT1T2ValidationT2RecoValidation_PACKAGE := self/src/TotemT1T2Validation/T2RecoValidation/src
ALL_PRODS += TotemT1T2ValidationT2RecoValidation
TotemT1T2ValidationT2RecoValidation_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/src,src_TotemT1T2Validation_T2RecoValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
