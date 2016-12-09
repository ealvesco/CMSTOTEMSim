ifeq ($(strip $(PyRecoTotemRPRPTrackCandidateCollectionFitter)),)
PyRecoTotemRPRPTrackCandidateCollectionFitter := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/python
src_RecoTotemRP_RPTrackCandidateCollectionFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python)
PyRecoTotemRPRPTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateCollectionFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPTrackCandidateCollectionFitter_LOC_USE := self  
PyRecoTotemRPRPTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/python
ALL_PRODS += PyRecoTotemRPRPTrackCandidateCollectionFitter
PyRecoTotemRPRPTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python,src_RecoTotemRP_RPTrackCandidateCollectionFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateCollectionFitter_python
src_RecoTotemRP_RPTrackCandidateCollectionFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateCollectionFitter_python,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python,PYTHON))
