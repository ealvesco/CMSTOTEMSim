ifeq ($(strip $(RecoTotemRP/RPRecoDataFormats)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRecoDataFormats_src
src_RecoTotemRP_RPRecoDataFormats_src_parent := RecoTotemRP/RPRecoDataFormats
src_RecoTotemRP_RPRecoDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoDataFormats_src,src/RecoTotemRP/RPRecoDataFormats/src,LIBRARY))
RecoTotemRPRPRecoDataFormats := self/RecoTotemRP/RPRecoDataFormats
RecoTotemRP/RPRecoDataFormats := RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_files := $(patsubst src/RecoTotemRP/RPRecoDataFormats/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRecoDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRecoDataFormats/BuildFile
RecoTotemRPRPRecoDataFormats_LOC_USE := self  FWCore/Framework boost DataFormats/Common DataFormats/TotemRPDataTypes rootrflx clhep SimDataFormats/GeneratorProducts TotemCondFormats/BeamOpticsParamsObjects
RecoTotemRPRPRecoDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPRecoDataFormatsCapabilities,RecoTotemRPRPRecoDataFormats,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPRecoDataFormats/src))
RecoTotemRPRPRecoDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,RecoTotemRPRPRecoDataFormats,0,src/RecoTotemRP/RPRecoDataFormats/src/classes.h,src/RecoTotemRP/RPRecoDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
RecoTotemRPRPRecoDataFormats_EX_LIB   := RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_EX_USE   := $(foreach d,$(RecoTotemRPRPRecoDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPRecoDataFormats_PACKAGE := self/src/RecoTotemRP/RPRecoDataFormats/src
ALL_PRODS += RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRecoDataFormats,src/RecoTotemRP/RPRecoDataFormats/src,src_RecoTotemRP_RPRecoDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
