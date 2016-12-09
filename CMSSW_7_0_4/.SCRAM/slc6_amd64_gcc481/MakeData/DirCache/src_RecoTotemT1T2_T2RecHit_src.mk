ifeq ($(strip $(RecoTotemT1T2/T2RecHit)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_src
src_RecoTotemT1T2_T2RecHit_src_parent := RecoTotemT1T2/T2RecHit
src_RecoTotemT1T2_T2RecHit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_src,src/RecoTotemT1T2/T2RecHit/src,LIBRARY))
RecoTotemT1T2T2RecHit := self/RecoTotemT1T2/T2RecHit
RecoTotemT1T2/T2RecHit := RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_files := $(patsubst src/RecoTotemT1T2/T2RecHit/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RecHit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RecHit/BuildFile
RecoTotemT1T2T2RecHit_LOC_FLAGS_CXXFLAGS   := -O0 -g3 -fno-inline
RecoTotemT1T2T2RecHit_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit Geometry/TotemT2AlignmentDataFormats
RecoTotemT1T2T2RecHit_EX_LIB   := RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_EX_USE   := $(foreach d,$(RecoTotemT1T2T2RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2RecHit_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/src
ALL_PRODS += RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/src,src_RecoTotemT1T2_T2RecHit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
