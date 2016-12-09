ifeq ($(strip $(PyRecoTotemRPRPRecoHitProducer)),)
PyRecoTotemRPRPRecoHitProducer := self/src/RecoTotemRP/RPRecoHitProducer/python
src_RecoTotemRP_RPRecoHitProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPRecoHitProducer/python)
PyRecoTotemRPRPRecoHitProducer_files := $(patsubst src/RecoTotemRP/RPRecoHitProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoHitProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPRecoHitProducer_LOC_USE := self  
PyRecoTotemRPRPRecoHitProducer_PACKAGE := self/src/RecoTotemRP/RPRecoHitProducer/python
ALL_PRODS += PyRecoTotemRPRPRecoHitProducer
PyRecoTotemRPRPRecoHitProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/python,src_RecoTotemRP_RPRecoHitProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_python
src_RecoTotemRP_RPRecoHitProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_python,src/RecoTotemRP/RPRecoHitProducer/python,PYTHON))
