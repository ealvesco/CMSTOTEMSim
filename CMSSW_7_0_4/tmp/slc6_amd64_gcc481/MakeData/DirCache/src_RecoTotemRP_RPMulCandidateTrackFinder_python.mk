ifeq ($(strip $(PyRecoTotemRPRPMulCandidateTrackFinder)),)
PyRecoTotemRPRPMulCandidateTrackFinder := self/src/RecoTotemRP/RPMulCandidateTrackFinder/python
src_RecoTotemRP_RPMulCandidateTrackFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPMulCandidateTrackFinder/python)
PyRecoTotemRPRPMulCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPMulCandidateTrackFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulCandidateTrackFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPMulCandidateTrackFinder_LOC_USE := self  
PyRecoTotemRPRPMulCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPMulCandidateTrackFinder/python
ALL_PRODS += PyRecoTotemRPRPMulCandidateTrackFinder
PyRecoTotemRPRPMulCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/python,src_RecoTotemRP_RPMulCandidateTrackFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulCandidateTrackFinder_python
src_RecoTotemRP_RPMulCandidateTrackFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulCandidateTrackFinder_python,src/RecoTotemRP/RPMulCandidateTrackFinder/python,PYTHON))
