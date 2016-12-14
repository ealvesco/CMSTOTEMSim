ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_plugins
src_ForwardAnalysis_ForwardTTreeAnalysis_plugins_parent := ForwardAnalysis/ForwardTTreeAnalysis
src_ForwardAnalysis_ForwardTTreeAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_plugins,src/ForwardAnalysis/ForwardTTreeAnalysis/plugins,PLUGINS))
ifeq ($(strip $(ForwardAnalysis/ForwardTTreeAnalysis)),)
ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_src
src_ForwardAnalysis_ForwardTTreeAnalysis_src_parent := ForwardAnalysis/ForwardTTreeAnalysis
src_ForwardAnalysis_ForwardTTreeAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_src,src/ForwardAnalysis/ForwardTTreeAnalysis/src,LIBRARY))
ForwardAnalysisForwardTTreeAnalysis := self/ForwardAnalysis/ForwardTTreeAnalysis
ForwardAnalysis/ForwardTTreeAnalysis := ForwardAnalysisForwardTTreeAnalysis
ForwardAnalysisForwardTTreeAnalysis_files := $(patsubst src/ForwardAnalysis/ForwardTTreeAnalysis/src/%,%,$(wildcard $(foreach dir,src/ForwardAnalysis/ForwardTTreeAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
ForwardAnalysisForwardTTreeAnalysis_LOC_USE := self  
ForwardAnalysisForwardTTreeAnalysis_PACKAGE := self/src/ForwardAnalysis/ForwardTTreeAnalysis/src
ALL_PRODS += ForwardAnalysisForwardTTreeAnalysis
ForwardAnalysisForwardTTreeAnalysis_CLASS := LIBRARY
ForwardAnalysis/ForwardTTreeAnalysis_forbigobj+=ForwardAnalysisForwardTTreeAnalysis
ForwardAnalysisForwardTTreeAnalysis_INIT_FUNC        += $$(eval $$(call Library,ForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/src,src_ForwardAnalysis_ForwardTTreeAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/TotemAnalysisEvent)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemAnalysisEvent_src
src_TotemAnalysis_TotemAnalysisEvent_src_parent := TotemAnalysis/TotemAnalysisEvent
src_TotemAnalysis_TotemAnalysisEvent_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemAnalysisEvent_src,src/TotemAnalysis/TotemAnalysisEvent/src,LIBRARY))
TotemAnalysisTotemAnalysisEvent := self/TotemAnalysis/TotemAnalysisEvent
TotemAnalysis/TotemAnalysisEvent := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_files := $(patsubst src/TotemAnalysis/TotemAnalysisEvent/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemAnalysisEvent/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemAnalysisEvent_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemAnalysisEvent/BuildFile
TotemAnalysisTotemAnalysisEvent_LOC_USE := self  FWCore/ParameterSet FWCore/Framework root DataFormats/Common
TotemAnalysisTotemAnalysisEvent_LCGDICTS  := x 
TotemAnalysisTotemAnalysisEvent_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAnalysisTotemAnalysisEvent,src/TotemAnalysis/TotemAnalysisEvent/src/classes.h,src/TotemAnalysis/TotemAnalysisEvent/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,))
TotemAnalysisTotemAnalysisEvent_EX_LIB   := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_EX_USE   := $(foreach d,$(TotemAnalysisTotemAnalysisEvent_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemAnalysisEvent_PACKAGE := self/src/TotemAnalysis/TotemAnalysisEvent/src
ALL_PRODS += TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_CLASS := LIBRARY
TotemAnalysis/TotemAnalysisEvent_forbigobj+=TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemAnalysisEvent,src/TotemAnalysis/TotemAnalysisEvent/src,src_TotemAnalysis_TotemAnalysisEvent_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(UATree/MitEdm)),)
ALL_COMMONRULES += src_UATree_MitEdm_src
src_UATree_MitEdm_src_parent := UATree/MitEdm
src_UATree_MitEdm_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_MitEdm_src,src/UATree/MitEdm/src,LIBRARY))
UATreeMitEdm := self/UATree/MitEdm
UATree/MitEdm := UATreeMitEdm
UATreeMitEdm_files := $(patsubst src/UATree/MitEdm/src/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeMitEdm_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/MitEdm/BuildFile
UATreeMitEdm_LOC_USE := self  DataFormats/TrackReco DataFormats/GsfTrackReco root FWCore/Framework FWCore/ParameterSet FWCore/PluginManager CommonTools/UtilAlgos DataFormats/CaloTowers DataFormats/Common DataFormats/VertexReco DataFormats/CaloRecHit MagneticField/Engine Geometry/CaloGeometry RecoTracker/Record TrackingTools/TransientTrack RecoTracker/TkDetLayers RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives
UATreeMitEdm_LCGDICTS  := x 
UATreeMitEdm_PRE_INIT_FUNC += $$(eval $$(call LCGDict,UATreeMitEdm,src/UATree/MitEdm/src/classes.h,src/UATree/MitEdm/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,))
UATreeMitEdm_EX_LIB   := UATreeMitEdm
UATreeMitEdm_EX_USE   := $(foreach d,$(UATreeMitEdm_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/src
ALL_PRODS += UATreeMitEdm
UATreeMitEdm_CLASS := LIBRARY
UATree/MitEdm_forbigobj+=UATreeMitEdm
UATreeMitEdm_INIT_FUNC        += $$(eval $$(call Library,UATreeMitEdm,src/UATree/MitEdm/src,src_UATree_MitEdm_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(UATree/UADataFormat)),)
ALL_COMMONRULES += src_UATree_UADataFormat_src
src_UATree_UADataFormat_src_parent := UATree/UADataFormat
src_UATree_UADataFormat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_UADataFormat_src,src/UATree/UADataFormat/src,LIBRARY))
UATreeUADataFormat := self/UATree/UADataFormat
UATree/UADataFormat := UATreeUADataFormat
UATreeUADataFormat_files := $(patsubst src/UATree/UADataFormat/src/%,%,$(wildcard $(foreach dir,src/UATree/UADataFormat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeUADataFormat_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/UADataFormat/BuildFile
UATreeUADataFormat_LOC_USE := self  root rootmath rootrflx rootcore
UATreeUADataFormat_EX_LIB   := UATreeUADataFormat
UATreeUADataFormat_EX_USE   := $(foreach d,$(UATreeUADataFormat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeUADataFormat_PACKAGE := self/src/UATree/UADataFormat/src
ALL_PRODS += UATreeUADataFormat
UATreeUADataFormat_CLASS := LIBRARY
UATree/UADataFormat_forbigobj+=UATreeUADataFormat
UATreeUADataFormat_INIT_FUNC        += $$(eval $$(call Library,UATreeUADataFormat,src/UATree/UADataFormat/src,src_UATree_UADataFormat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(CMS-TOTEM-Ntuples/TOTEMdataFormat)),)
ALL_COMMONRULES += src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src
src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src_parent := CMS-TOTEM-Ntuples/TOTEMdataFormat
src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src,LIBRARY))
CMS-TOTEM-NtuplesTOTEMdataFormat := self/CMS-TOTEM-Ntuples/TOTEMdataFormat
CMS-TOTEM-Ntuples/TOTEMdataFormat := CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_files := $(patsubst src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src/%,%,$(wildcard $(foreach dir,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
CMS-TOTEM-NtuplesTOTEMdataFormat_LOC_USE := self  
CMS-TOTEM-NtuplesTOTEMdataFormat_PACKAGE := self/src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src
ALL_PRODS += CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_CLASS := LIBRARY
CMS-TOTEM-Ntuples/TOTEMdataFormat_forbigobj+=CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_INIT_FUNC        += $$(eval $$(call Library,CMS-TOTEM-NtuplesTOTEMdataFormat,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src,src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
