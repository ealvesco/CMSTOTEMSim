ifeq ($(strip $(PyRecoTotemRPRPTimingDetectorsRecoHitsProducer)),)
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python)
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_files := $(patsubst src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_LOC_USE := self  
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_PACKAGE := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python
ALL_PRODS += PyRecoTotemRPRPTimingDetectorsRecoHitsProducer
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPTimingDetectorsRecoHitsProducer,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPTimingDetectorsRecoHitsProducer,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python,PYTHON))
