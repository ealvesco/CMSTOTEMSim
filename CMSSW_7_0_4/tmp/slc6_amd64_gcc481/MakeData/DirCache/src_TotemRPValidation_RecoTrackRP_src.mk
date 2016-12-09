ifeq ($(strip $(TotemRPValidation/RecoTrackRP)),)
ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_src
src_TotemRPValidation_RecoTrackRP_src_parent := TotemRPValidation/RecoTrackRP
src_TotemRPValidation_RecoTrackRP_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_src,src/TotemRPValidation/RecoTrackRP/src,LIBRARY))
TotemRPValidationRecoTrackRP := self/TotemRPValidation/RecoTrackRP
TotemRPValidation/RecoTrackRP := TotemRPValidationRecoTrackRP
TotemRPValidationRecoTrackRP_files := $(patsubst src/TotemRPValidation/RecoTrackRP/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RecoTrackRP/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRecoTrackRP_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RecoTrackRP/BuildFile
TotemRPValidationRecoTrackRP_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses RecoTotemRP/RPRecoDataFormats SimDataFormats/GeneratorProducts SimG4Core/Notification TotemRPValidation/ParamMADRefTransport RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord TotemRPValidation/HitDistributions root rootgraphics Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemRPValidationRecoTrackRP_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRecoTrackRP,TotemRPValidationRecoTrackRP,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RecoTrackRP/src))
TotemRPValidationRecoTrackRP_PACKAGE := self/src/TotemRPValidation/RecoTrackRP/src
ALL_PRODS += TotemRPValidationRecoTrackRP
TotemRPValidationRecoTrackRP_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/src,src_TotemRPValidation_RecoTrackRP_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
