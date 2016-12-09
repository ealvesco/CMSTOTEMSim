ifeq ($(strip $(TotemAnalysis/T2Cuts)),)
ALL_COMMONRULES += src_TotemAnalysis_T2Cuts_src
src_TotemAnalysis_T2Cuts_src_parent := TotemAnalysis/T2Cuts
src_TotemAnalysis_T2Cuts_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2Cuts_src,src/TotemAnalysis/T2Cuts/src,LIBRARY))
TotemAnalysisT2Cuts := self/TotemAnalysis/T2Cuts
TotemAnalysis/T2Cuts := TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_files := $(patsubst src/TotemAnalysis/T2Cuts/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2Cuts/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2Cuts_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2Cuts/BuildFile
TotemAnalysisT2Cuts_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1T2Track DataFormats/T1RecHit Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord xerces-c
TotemAnalysisT2Cuts_EX_LIB   := TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_EX_USE   := $(foreach d,$(TotemAnalysisT2Cuts_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisT2Cuts_PACKAGE := self/src/TotemAnalysis/T2Cuts/src
ALL_PRODS += TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2Cuts,src/TotemAnalysis/T2Cuts/src,src_TotemAnalysis_T2Cuts_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
