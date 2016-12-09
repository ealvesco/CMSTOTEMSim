ifeq ($(strip $(PyRecoTotemT1T2PrimaryVertexProducer)),)
PyRecoTotemT1T2PrimaryVertexProducer := self/src/RecoTotemT1T2/PrimaryVertexProducer/python
src_RecoTotemT1T2_PrimaryVertexProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/PrimaryVertexProducer/python)
PyRecoTotemT1T2PrimaryVertexProducer_files := $(patsubst src/RecoTotemT1T2/PrimaryVertexProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/PrimaryVertexProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2PrimaryVertexProducer_LOC_USE := self  
PyRecoTotemT1T2PrimaryVertexProducer_PACKAGE := self/src/RecoTotemT1T2/PrimaryVertexProducer/python
ALL_PRODS += PyRecoTotemT1T2PrimaryVertexProducer
PyRecoTotemT1T2PrimaryVertexProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer/python,src_RecoTotemT1T2_PrimaryVertexProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_PrimaryVertexProducer_python
src_RecoTotemT1T2_PrimaryVertexProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_PrimaryVertexProducer_python,src/RecoTotemT1T2/PrimaryVertexProducer/python,PYTHON))
