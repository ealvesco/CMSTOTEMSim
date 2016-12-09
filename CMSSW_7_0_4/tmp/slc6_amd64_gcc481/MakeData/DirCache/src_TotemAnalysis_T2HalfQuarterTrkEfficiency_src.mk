ifeq ($(strip $(TotemAnalysis/T2HalfQuarterTrkEfficiency)),)
ALL_COMMONRULES += src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src_parent := TotemAnalysis/T2HalfQuarterTrkEfficiency
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src,LIBRARY))
TotemAnalysisT2HalfQuarterTrkEfficiency := self/TotemAnalysis/T2HalfQuarterTrkEfficiency
TotemAnalysis/T2HalfQuarterTrkEfficiency := TotemAnalysisT2HalfQuarterTrkEfficiency
TotemAnalysisT2HalfQuarterTrkEfficiency_files := $(patsubst src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2HalfQuarterTrkEfficiency_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/BuildFile
TotemAnalysisT2HalfQuarterTrkEfficiency_LOC_USE := self  boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root rootcore SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemAnalysis/T2Cuts DataFormats/T1T2Track clhep xerces-c
TotemAnalysisT2HalfQuarterTrkEfficiency_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2HalfQuarterTrkEfficiency,TotemAnalysisT2HalfQuarterTrkEfficiency,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src))
TotemAnalysisT2HalfQuarterTrkEfficiency_PACKAGE := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src
ALL_PRODS += TotemAnalysisT2HalfQuarterTrkEfficiency
TotemAnalysisT2HalfQuarterTrkEfficiency_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
