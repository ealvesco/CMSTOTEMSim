ifeq ($(strip $(PyRecoTotemRPRPMulTrackCandidateCollectionFitter)),)
PyRecoTotemRPRPMulTrackCandidateCollectionFitter := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python)
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_LOC_USE := self  
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python
ALL_PRODS += PyRecoTotemRPRPMulTrackCandidateCollectionFitter
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python,PYTHON))
