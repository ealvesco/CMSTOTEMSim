ifeq ($(strip $(PyRecoTotemRPRPSingleCandidateTrackFinder)),)
PyRecoTotemRPRPSingleCandidateTrackFinder := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/python
src_RecoTotemRP_RPSingleCandidateTrackFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPSingleCandidateTrackFinder/python)
PyRecoTotemRPRPSingleCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPSingleCandidateTrackFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPSingleCandidateTrackFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPSingleCandidateTrackFinder_LOC_USE := self  
PyRecoTotemRPRPSingleCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/python
ALL_PRODS += PyRecoTotemRPRPSingleCandidateTrackFinder
PyRecoTotemRPRPSingleCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/python,src_RecoTotemRP_RPSingleCandidateTrackFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPSingleCandidateTrackFinder_python
src_RecoTotemRP_RPSingleCandidateTrackFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPSingleCandidateTrackFinder_python,src/RecoTotemRP/RPSingleCandidateTrackFinder/python,PYTHON))
