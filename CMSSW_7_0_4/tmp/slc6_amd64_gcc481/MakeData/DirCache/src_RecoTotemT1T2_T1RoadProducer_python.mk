ifeq ($(strip $(PyRecoTotemT1T2T1RoadProducer)),)
PyRecoTotemT1T2T1RoadProducer := self/src/RecoTotemT1T2/T1RoadProducer/python
src_RecoTotemT1T2_T1RoadProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1RoadProducer/python)
PyRecoTotemT1T2T1RoadProducer_files := $(patsubst src/RecoTotemT1T2/T1RoadProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1RoadProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1RoadProducer_LOC_USE := self  
PyRecoTotemT1T2T1RoadProducer_PACKAGE := self/src/RecoTotemT1T2/T1RoadProducer/python
ALL_PRODS += PyRecoTotemT1T2T1RoadProducer
PyRecoTotemT1T2T1RoadProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer/python,src_RecoTotemT1T2_T1RoadProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RoadProducer_python
src_RecoTotemT1T2_T1RoadProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RoadProducer_python,src/RecoTotemT1T2/T1RoadProducer/python,PYTHON))
