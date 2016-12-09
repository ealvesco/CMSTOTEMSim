ifeq ($(strip $(PyRecoTotemRPRPInelasticReconstruction)),)
PyRecoTotemRPRPInelasticReconstruction := self/src/RecoTotemRP/RPInelasticReconstruction/python
src_RecoTotemRP_RPInelasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPInelasticReconstruction/python)
PyRecoTotemRPRPInelasticReconstruction_files := $(patsubst src/RecoTotemRP/RPInelasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInelasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPInelasticReconstruction_LOC_USE := self  
PyRecoTotemRPRPInelasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPInelasticReconstruction/python
ALL_PRODS += PyRecoTotemRPRPInelasticReconstruction
PyRecoTotemRPRPInelasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/python,src_RecoTotemRP_RPInelasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPInelasticReconstruction_python
src_RecoTotemRP_RPInelasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInelasticReconstruction_python,src/RecoTotemRP/RPInelasticReconstruction/python,PYTHON))
