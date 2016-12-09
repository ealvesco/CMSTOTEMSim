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
