ifeq ($(strip $(TotemCondFormats/BeamOpticsParamsObjects)),)
ALL_COMMONRULES += src_TotemCondFormats_BeamOpticsParamsObjects_src
src_TotemCondFormats_BeamOpticsParamsObjects_src_parent := TotemCondFormats/BeamOpticsParamsObjects
src_TotemCondFormats_BeamOpticsParamsObjects_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_BeamOpticsParamsObjects_src,src/TotemCondFormats/BeamOpticsParamsObjects/src,LIBRARY))
TotemCondFormatsBeamOpticsParamsObjects := self/TotemCondFormats/BeamOpticsParamsObjects
TotemCondFormats/BeamOpticsParamsObjects := TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_files := $(patsubst src/TotemCondFormats/BeamOpticsParamsObjects/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/BeamOpticsParamsObjects/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsBeamOpticsParamsObjects_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/BeamOpticsParamsObjects/BuildFile
TotemCondFormatsBeamOpticsParamsObjects_LOC_USE := self  FWCore/Framework FWCore/ParameterSet hepmc SimDataFormats/GeneratorProducts root
TotemCondFormatsBeamOpticsParamsObjects_EX_LIB   := TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_EX_USE   := $(foreach d,$(TotemCondFormatsBeamOpticsParamsObjects_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsBeamOpticsParamsObjects_PACKAGE := self/src/TotemCondFormats/BeamOpticsParamsObjects/src
ALL_PRODS += TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsBeamOpticsParamsObjects,src/TotemCondFormats/BeamOpticsParamsObjects/src,src_TotemCondFormats_BeamOpticsParamsObjects_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
