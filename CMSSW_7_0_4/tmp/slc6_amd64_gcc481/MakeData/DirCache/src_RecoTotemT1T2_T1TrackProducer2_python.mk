ifeq ($(strip $(PyRecoTotemT1T2T1TrackProducer2)),)
PyRecoTotemT1T2T1TrackProducer2 := self/src/RecoTotemT1T2/T1TrackProducer2/python
src_RecoTotemT1T2_T1TrackProducer2_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1TrackProducer2/python)
PyRecoTotemT1T2T1TrackProducer2_files := $(patsubst src/RecoTotemT1T2/T1TrackProducer2/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1TrackProducer2/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1TrackProducer2_LOC_USE := self  
PyRecoTotemT1T2T1TrackProducer2_PACKAGE := self/src/RecoTotemT1T2/T1TrackProducer2/python
ALL_PRODS += PyRecoTotemT1T2T1TrackProducer2
PyRecoTotemT1T2T1TrackProducer2_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1TrackProducer2,src/RecoTotemT1T2/T1TrackProducer2/python,src_RecoTotemT1T2_T1TrackProducer2_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1TrackProducer2,src/RecoTotemT1T2/T1TrackProducer2/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1TrackProducer2_python
src_RecoTotemT1T2_T1TrackProducer2_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1TrackProducer2_python,src/RecoTotemT1T2/T1TrackProducer2/python,PYTHON))
