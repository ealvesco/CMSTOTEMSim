ifeq ($(strip $(UATree/MitEdm)),)
ALL_COMMONRULES += src_UATree_MitEdm_src
src_UATree_MitEdm_src_parent := UATree/MitEdm
src_UATree_MitEdm_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_MitEdm_src,src/UATree/MitEdm/src,LIBRARY))
UATreeMitEdm := self/UATree/MitEdm
UATree/MitEdm := UATreeMitEdm
UATreeMitEdm_files := $(patsubst src/UATree/MitEdm/src/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeMitEdm_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/MitEdm/BuildFile
UATreeMitEdm_LOC_USE := self  DataFormats/TrackReco DataFormats/GsfTrackReco root FWCore/Framework FWCore/ParameterSet FWCore/PluginManager CommonTools/UtilAlgos DataFormats/CaloTowers DataFormats/Common DataFormats/VertexReco DataFormats/CaloRecHit MagneticField/Engine Geometry/CaloGeometry RecoTracker/Record TrackingTools/TransientTrack RecoTracker/TkDetLayers RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives
UATreeMitEdm_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UATreeMitEdmCapabilities,UATreeMitEdm,$(SCRAMSTORENAME_LIB),src/UATree/MitEdm/src))
UATreeMitEdm_PRE_INIT_FUNC += $$(eval $$(call LCGDict,UATreeMitEdm,0,src/UATree/MitEdm/src/classes.h,src/UATree/MitEdm/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
UATreeMitEdm_EX_LIB   := UATreeMitEdm
UATreeMitEdm_EX_USE   := $(foreach d,$(UATreeMitEdm_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/src
ALL_PRODS += UATreeMitEdm
UATreeMitEdm_INIT_FUNC        += $$(eval $$(call Library,UATreeMitEdm,src/UATree/MitEdm/src,src_UATree_MitEdm_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
