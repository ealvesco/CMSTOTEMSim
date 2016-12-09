ifeq ($(strip $(TotemAnalysis/T2ValidRawData)),)
ALL_COMMONRULES += src_TotemAnalysis_T2ValidRawData_src
src_TotemAnalysis_T2ValidRawData_src_parent := TotemAnalysis/T2ValidRawData
src_TotemAnalysis_T2ValidRawData_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2ValidRawData_src,src/TotemAnalysis/T2ValidRawData/src,LIBRARY))
TotemAnalysisT2ValidRawData := self/TotemAnalysis/T2ValidRawData
TotemAnalysis/T2ValidRawData := TotemAnalysisT2ValidRawData
TotemAnalysisT2ValidRawData_files := $(patsubst src/TotemAnalysis/T2ValidRawData/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2ValidRawData/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2ValidRawData_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2ValidRawData/BuildFile
TotemAnalysisT2ValidRawData_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts clhep DataFormats/T2Cluster DataFormats/T2DetId TotemAnalysis/T2Cuts Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord xerces-c
TotemAnalysisT2ValidRawData_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2ValidRawData,TotemAnalysisT2ValidRawData,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2ValidRawData/src))
TotemAnalysisT2ValidRawData_PACKAGE := self/src/TotemAnalysis/T2ValidRawData/src
ALL_PRODS += TotemAnalysisT2ValidRawData
TotemAnalysisT2ValidRawData_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/src,src_TotemAnalysis_T2ValidRawData_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
