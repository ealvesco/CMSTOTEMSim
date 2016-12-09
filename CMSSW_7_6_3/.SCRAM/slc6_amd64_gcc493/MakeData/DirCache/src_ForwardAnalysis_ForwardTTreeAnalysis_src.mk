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
