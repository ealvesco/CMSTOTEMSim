ALL_SUBSYSTEMS+=TotemAnalysis
subdirs_src_TotemAnalysis = src_TotemAnalysis_TotemAnalysisEvent
ALL_PACKAGES += TotemAnalysis/TotemAnalysisEvent
subdirs_src_TotemAnalysis_TotemAnalysisEvent := src_TotemAnalysis_TotemAnalysisEvent_interface src_TotemAnalysis_TotemAnalysisEvent_src
ALL_SUBSYSTEMS+=UATree
subdirs_src_UATree = src_UATree_MitEdm src_UATree_UABaseTree src_UATree_UADataFormat
ALL_PACKAGES += UATree/MitEdm
subdirs_src_UATree_MitEdm := src_UATree_MitEdm_python src_UATree_MitEdm_src
ifeq ($(strip $(PyUATreeMitEdm)),)
PyUATreeMitEdm := self/src/UATree/MitEdm/python
src_UATree_MitEdm_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/MitEdm/python)
PyUATreeMitEdm_files := $(patsubst src/UATree/MitEdm/python/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeMitEdm_LOC_USE := self  
PyUATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/python
ALL_PRODS += PyUATreeMitEdm
PyUATreeMitEdm_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeMitEdm,src/UATree/MitEdm/python,src_UATree_MitEdm_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeMitEdm,src/UATree/MitEdm/python))
endif
ALL_COMMONRULES += src_UATree_MitEdm_python
src_UATree_MitEdm_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_MitEdm_python,src/UATree/MitEdm/python,PYTHON))
ALL_PACKAGES += UATree/UABaseTree
subdirs_src_UATree_UABaseTree := src_UATree_UABaseTree_python src_UATree_UABaseTree_src src_UATree_UABaseTree_data
ifeq ($(strip $(PyUATreeUABaseTree)),)
PyUATreeUABaseTree := self/src/UATree/UABaseTree/python
src_UATree_UABaseTree_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/UABaseTree/python)
PyUATreeUABaseTree_files := $(patsubst src/UATree/UABaseTree/python/%,%,$(wildcard $(foreach dir,src/UATree/UABaseTree/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeUABaseTree_LOC_USE := self  
PyUATreeUABaseTree_PACKAGE := self/src/UATree/UABaseTree/python
ALL_PRODS += PyUATreeUABaseTree
PyUATreeUABaseTree_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeUABaseTree,src/UATree/UABaseTree/python,src_UATree_UABaseTree_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeUABaseTree,src/UATree/UABaseTree/python))
endif
ALL_COMMONRULES += src_UATree_UABaseTree_python
src_UATree_UABaseTree_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_UABaseTree_python,src/UATree/UABaseTree/python,PYTHON))
ALL_PACKAGES += UATree/UADataFormat
subdirs_src_UATree_UADataFormat := src_UATree_UADataFormat_src
ALL_SUBSYSTEMS+=crab_projects
subdirs_src_crab_projects = src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v1 src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v3 src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV_v2
ALL_PACKAGES += crab_projects/crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV
subdirs_src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV := 
ALL_PACKAGES += crab_projects/crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v1
subdirs_src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v1 := src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v1_results src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v1_inputs
ALL_PACKAGES += crab_projects/crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v3
subdirs_src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v3 := src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v3_results src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-POMWIGSDMinusDijets-pT20GeV-v3_inputs
ALL_PACKAGES += crab_projects/crab_DIGI-HLT_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV
subdirs_src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV := src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV_results src_crab_projects_crab_DIGI-HLT_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV_inputs
ALL_PACKAGES += crab_projects/crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV
subdirs_src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV := 
ALL_PACKAGES += crab_projects/crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV_v2
subdirs_src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-POMWIGSDMINUSDijets-pT20GeV_v2 := 
ALL_PACKAGES += crab_projects/crab_RECO_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV
subdirs_src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV := src_crab_projects_crab_RECO_Production_CMS-RP-NewFormat-PYTHIA8Dijets-pT20GeV_results
ALL_SUBSYSTEMS+=CMS-TOTEM-Ntuples
subdirs_src_CMS-TOTEM-Ntuples = src_CMS-TOTEM-Ntuples_Merge src_CMS-TOTEM-Ntuples_CMSdataFormat src_CMS-TOTEM-Ntuples_Config src_CMS-TOTEM-Ntuples_Scripts src_CMS-TOTEM-Ntuples_TOTEMdataFormat src_CMS-TOTEM-Ntuples_Workspace
ALL_PACKAGES += CMS-TOTEM-Ntuples/CMSdataFormat
subdirs_src_CMS-TOTEM-Ntuples_CMSdataFormat := src_CMS-TOTEM-Ntuples_CMSdataFormat_utilities src_CMS-TOTEM-Ntuples_CMSdataFormat_lib
ALL_PACKAGES += CMS-TOTEM-Ntuples/Config
subdirs_src_CMS-TOTEM-Ntuples_Config := src_CMS-TOTEM-Ntuples_Config_crab_projects
ALL_PACKAGES += CMS-TOTEM-Ntuples/Merge
subdirs_src_CMS-TOTEM-Ntuples_Merge := 
ALL_PACKAGES += CMS-TOTEM-Ntuples/Scripts
subdirs_src_CMS-TOTEM-Ntuples_Scripts := 
ALL_PACKAGES += CMS-TOTEM-Ntuples/TOTEMdataFormat
subdirs_src_CMS-TOTEM-Ntuples_TOTEMdataFormat := src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src
ALL_PACKAGES += CMS-TOTEM-Ntuples/Workspace
subdirs_src_CMS-TOTEM-Ntuples_Workspace := src_CMS-TOTEM-Ntuples_Workspace_parametrization
