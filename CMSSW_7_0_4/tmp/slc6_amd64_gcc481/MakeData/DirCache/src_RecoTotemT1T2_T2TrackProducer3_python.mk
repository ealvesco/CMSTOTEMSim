ifeq ($(strip $(PyRecoTotemT1T2T2TrackProducer3)),)
PyRecoTotemT1T2T2TrackProducer3 := self/src/RecoTotemT1T2/T2TrackProducer3/python
src_RecoTotemT1T2_T2TrackProducer3_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2TrackProducer3/python)
PyRecoTotemT1T2T2TrackProducer3_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2TrackProducer3/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2TrackProducer3_LOC_USE := self  
PyRecoTotemT1T2T2TrackProducer3_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/python
ALL_PRODS += PyRecoTotemT1T2T2TrackProducer3
PyRecoTotemT1T2T2TrackProducer3_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/python,src_RecoTotemT1T2_T2TrackProducer3_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_python
src_RecoTotemT1T2_T2TrackProducer3_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_python,src/RecoTotemT1T2/T2TrackProducer3/python,PYTHON))
