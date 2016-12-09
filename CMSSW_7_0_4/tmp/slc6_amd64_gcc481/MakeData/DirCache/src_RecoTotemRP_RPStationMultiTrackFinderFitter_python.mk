ifeq ($(strip $(PyRecoTotemRPRPStationMultiTrackFinderFitter)),)
PyRecoTotemRPRPStationMultiTrackFinderFitter := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/python
src_RecoTotemRP_RPStationMultiTrackFinderFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python)
PyRecoTotemRPRPStationMultiTrackFinderFitter_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE := self  
PyRecoTotemRPRPStationMultiTrackFinderFitter_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/python
ALL_PRODS += PyRecoTotemRPRPStationMultiTrackFinderFitter
PyRecoTotemRPRPStationMultiTrackFinderFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python,src_RecoTotemRP_RPStationMultiTrackFinderFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_python
src_RecoTotemRP_RPStationMultiTrackFinderFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_python,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python,PYTHON))
