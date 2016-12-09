ifeq ($(strip $(PyRecoTotemRPRPNonParallelTrackCandidateFinder)),)
PyRecoTotemRPRPNonParallelTrackCandidateFinder := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python)
PyRecoTotemRPRPNonParallelTrackCandidateFinder_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE := self  
PyRecoTotemRPRPNonParallelTrackCandidateFinder_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python
ALL_PRODS += PyRecoTotemRPRPNonParallelTrackCandidateFinder
PyRecoTotemRPRPNonParallelTrackCandidateFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python,PYTHON))
