ifeq ($(strip $(TotemAlignment/T2TrkBasedInternalAlignment)),)
ALL_COMMONRULES += src_TotemAlignment_T2TrkBasedInternalAlignment_src
src_TotemAlignment_T2TrkBasedInternalAlignment_src_parent := TotemAlignment/T2TrkBasedInternalAlignment
src_TotemAlignment_T2TrkBasedInternalAlignment_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_T2TrkBasedInternalAlignment_src,src/TotemAlignment/T2TrkBasedInternalAlignment/src,LIBRARY))
TotemAlignmentT2TrkBasedInternalAlignment := self/TotemAlignment/T2TrkBasedInternalAlignment
TotemAlignment/T2TrkBasedInternalAlignment := TotemAlignmentT2TrkBasedInternalAlignment
TotemAlignmentT2TrkBasedInternalAlignment_files := $(patsubst src/TotemAlignment/T2TrkBasedInternalAlignment/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T2TrkBasedInternalAlignment/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentT2TrkBasedInternalAlignment_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/T2TrkBasedInternalAlignment/BuildFile
TotemAlignmentT2TrkBasedInternalAlignment_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts clhep DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road rootminuit2 rootrflx rootminuit
TotemAlignmentT2TrkBasedInternalAlignment_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentT2TrkBasedInternalAlignment,TotemAlignmentT2TrkBasedInternalAlignment,$(SCRAMSTORENAME_LIB),src/TotemAlignment/T2TrkBasedInternalAlignment/src))
TotemAlignmentT2TrkBasedInternalAlignment_PACKAGE := self/src/TotemAlignment/T2TrkBasedInternalAlignment/src
ALL_PRODS += TotemAlignmentT2TrkBasedInternalAlignment
TotemAlignmentT2TrkBasedInternalAlignment_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/src,src_TotemAlignment_T2TrkBasedInternalAlignment_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
