ifeq ($(strip $(UATree/UABaseTree)),)
ALL_COMMONRULES += src_UATree_UABaseTree_src
src_UATree_UABaseTree_src_parent := UATree/UABaseTree
src_UATree_UABaseTree_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_UABaseTree_src,src/UATree/UABaseTree/src,LIBRARY))
UATreeUABaseTree := self/UATree/UABaseTree
UATree/UABaseTree := UATreeUABaseTree
UATreeUABaseTree_files := $(patsubst src/UATree/UABaseTree/src/%,%,$(wildcard $(foreach dir,src/UATree/UABaseTree/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeUABaseTree_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/UABaseTree/BuildFile
UATreeUABaseTree_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/Common DataFormats/Candidate DataFormats/HepMCCandidate SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts SimDataFormats/PileupSummaryInfo DataFormats/METReco L1Trigger/GlobalTriggerAnalyzer HLTrigger/HLTcore CondFormats/L1TObjects CondFormats/DataRecord DataFormats/L1GlobalTrigger DataFormats/Math DataFormats/TrackReco DataFormats/VertexReco DataFormats/JetReco DataFormats/MuonReco RecoEgamma/EgammaTools JetMETCorrections/Algorithms JetMETCorrections/Objects JetMETCorrections/Modules DataFormats/BeamSpot DataFormats/HLTReco DataFormats/CaloTowers DataFormats/HcalDetId UATree/UADataFormat UATree/MitEdm DataFormats/DetId RecoLocalTracker/SiStripClusterizer CondFormats/CastorObjects CondFormats/JetMETObjects CalibFormats/CastorObjects CalibFormats/HcalObjects TotemAnalysis/TotemAnalysisEvent rootrflx
UATreeUABaseTree_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UATreeUABaseTree,UATreeUABaseTree,$(SCRAMSTORENAME_LIB),src/UATree/UABaseTree/src))
UATreeUABaseTree_PACKAGE := self/src/UATree/UABaseTree/src
ALL_PRODS += UATreeUABaseTree
UATreeUABaseTree_CLASS := LIBRARY
UATree/UABaseTree_forbigobj+=UATreeUABaseTree
UATreeUABaseTree_INIT_FUNC        += $$(eval $$(call Library,UATreeUABaseTree,src/UATree/UABaseTree/src,src_UATree_UABaseTree_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
