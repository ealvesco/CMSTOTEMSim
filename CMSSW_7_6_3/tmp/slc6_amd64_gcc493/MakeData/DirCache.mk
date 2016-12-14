ALL_SUBSYSTEMS+=ForwardAnalysis
subdirs_src_ForwardAnalysis = src_ForwardAnalysis_ForwardTTreeAnalysis
ALL_PACKAGES += ForwardAnalysis/ForwardTTreeAnalysis
subdirs_src_ForwardAnalysis_ForwardTTreeAnalysis := src_ForwardAnalysis_ForwardTTreeAnalysis_plugins src_ForwardAnalysis_ForwardTTreeAnalysis_python src_ForwardAnalysis_ForwardTTreeAnalysis_src
ifeq ($(strip $(PyForwardAnalysisForwardTTreeAnalysis)),)
PyForwardAnalysisForwardTTreeAnalysis := self/src/ForwardAnalysis/ForwardTTreeAnalysis/python
src_ForwardAnalysis_ForwardTTreeAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/ForwardAnalysis/ForwardTTreeAnalysis/python)
PyForwardAnalysisForwardTTreeAnalysis_files := $(patsubst src/ForwardAnalysis/ForwardTTreeAnalysis/python/%,%,$(wildcard $(foreach dir,src/ForwardAnalysis/ForwardTTreeAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyForwardAnalysisForwardTTreeAnalysis_LOC_USE := self  
PyForwardAnalysisForwardTTreeAnalysis_PACKAGE := self/src/ForwardAnalysis/ForwardTTreeAnalysis/python
ALL_PRODS += PyForwardAnalysisForwardTTreeAnalysis
PyForwardAnalysisForwardTTreeAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/python,src_ForwardAnalysis_ForwardTTreeAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/python))
endif
ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_python
src_ForwardAnalysis_ForwardTTreeAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_python,src/ForwardAnalysis/ForwardTTreeAnalysis/python,PYTHON))
ALL_SUBSYSTEMS+=TotemAnalysis
subdirs_src_TotemAnalysis = src_TotemAnalysis_TotemAnalysisEvent
ALL_PACKAGES += TotemAnalysis/TotemAnalysisEvent
subdirs_src_TotemAnalysis_TotemAnalysisEvent := src_TotemAnalysis_TotemAnalysisEvent_src
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
subdirs_src_UATree_UABaseTree := src_UATree_UABaseTree_python src_UATree_UABaseTree_src
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
ALL_SUBSYSTEMS+=CMS-TOTEM-Ntuples
subdirs_src_CMS-TOTEM-Ntuples = src_CMS-TOTEM-Ntuples_Merge src_CMS-TOTEM-Ntuples_CMSdataFormat src_CMS-TOTEM-Ntuples_Config src_CMS-TOTEM-Ntuples_Scripts src_CMS-TOTEM-Ntuples_TOTEMdataFormat src_CMS-TOTEM-Ntuples_Workspace
ALL_PACKAGES += CMS-TOTEM-Ntuples/CMSdataFormat
subdirs_src_CMS-TOTEM-Ntuples_CMSdataFormat := src_CMS-TOTEM-Ntuples_CMSdataFormat_utilities src_CMS-TOTEM-Ntuples_CMSdataFormat_lib
ALL_PACKAGES += CMS-TOTEM-Ntuples/Config
subdirs_src_CMS-TOTEM-Ntuples_Config := 
ALL_PACKAGES += CMS-TOTEM-Ntuples/Merge
subdirs_src_CMS-TOTEM-Ntuples_Merge := 
ALL_PACKAGES += CMS-TOTEM-Ntuples/Scripts
subdirs_src_CMS-TOTEM-Ntuples_Scripts := 
ALL_PACKAGES += CMS-TOTEM-Ntuples/TOTEMdataFormat
subdirs_src_CMS-TOTEM-Ntuples_TOTEMdataFormat := src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src
ALL_PACKAGES += CMS-TOTEM-Ntuples/Workspace
subdirs_src_CMS-TOTEM-Ntuples_Workspace := 
ALL_SUBSYSTEMS+=pythons
subdirs_src_pythons = 
