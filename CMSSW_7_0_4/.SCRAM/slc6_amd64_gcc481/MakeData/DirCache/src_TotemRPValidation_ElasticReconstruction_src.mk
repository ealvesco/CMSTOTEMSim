ifeq ($(strip $(TotemRPValidation/ElasticReconstruction)),)
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_src
src_TotemRPValidation_ElasticReconstruction_src_parent := TotemRPValidation/ElasticReconstruction
src_TotemRPValidation_ElasticReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_src,src/TotemRPValidation/ElasticReconstruction/src,LIBRARY))
TotemRPValidationElasticReconstruction := self/TotemRPValidation/ElasticReconstruction
TotemRPValidation/ElasticReconstruction := TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ElasticReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationElasticReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ElasticReconstruction/BuildFile
TotemRPValidationElasticReconstruction_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root rootgraphics rootminuit boost TotemRPValidation/BaseValidationClasses TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord TotemCondFormats/ProtonTransportFunctions
TotemRPValidationElasticReconstruction_EX_LIB   := TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_EX_USE   := $(foreach d,$(TotemRPValidationElasticReconstruction_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationElasticReconstruction_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/src
ALL_PRODS += TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/src,src_TotemRPValidation_ElasticReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
