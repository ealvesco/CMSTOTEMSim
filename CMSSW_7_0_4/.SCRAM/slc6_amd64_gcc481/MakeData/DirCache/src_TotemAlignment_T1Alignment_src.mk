ifeq ($(strip $(TotemAlignment/T1Alignment)),)
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_src
src_TotemAlignment_T1Alignment_src_parent := TotemAlignment/T1Alignment
src_TotemAlignment_T1Alignment_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_src,src/TotemAlignment/T1Alignment/src,LIBRARY))
TotemAlignmentT1Alignment := self/TotemAlignment/T1Alignment
TotemAlignment/T1Alignment := TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_files := $(patsubst src/TotemAlignment/T1Alignment/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T1Alignment/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentT1Alignment_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/T1Alignment/BuildFile
TotemAlignmentT1Alignment_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1T2Track DataFormats/T1RecHit DataFormats/T1Road DataFormats/Common Geometry/TotemGeometry CommonTools/Clustering1D root rootminuit2 clhep FWCore/ParameterSet boost
TotemAlignmentT1Alignment_EX_LIB   := TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_EX_USE   := $(foreach d,$(TotemAlignmentT1Alignment_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentT1Alignment_PACKAGE := self/src/TotemAlignment/T1Alignment/src
ALL_PRODS += TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/src,src_TotemAlignment_T1Alignment_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
