ifeq ($(strip $(RecoTotemT1T2/T2RoadPadFinder)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_src
src_RecoTotemT1T2_T2RoadPadFinder_src_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_src,src/RecoTotemT1T2/T2RoadPadFinder/src,LIBRARY))
RecoTotemT1T2T2RoadPadFinder := self/RecoTotemT1T2/T2RoadPadFinder
RecoTotemT1T2/T2RoadPadFinder := RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RoadPadFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2RoadPadFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RoadPadFinder/BuildFile
RecoTotemT1T2T2RoadPadFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Cluster DataFormats/T2Road DataFormats/T1T2Track
RecoTotemT1T2T2RoadPadFinder_EX_LIB   := RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_EX_USE   := $(foreach d,$(RecoTotemT1T2T2RoadPadFinder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2RoadPadFinder_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/src
ALL_PRODS += RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/src,src_RecoTotemT1T2_T2RoadPadFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
