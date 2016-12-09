ifeq ($(strip $(PyRecoTotemRPRPElasticReconstruction)),)
PyRecoTotemRPRPElasticReconstruction := self/src/RecoTotemRP/RPElasticReconstruction/python
src_RecoTotemRP_RPElasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPElasticReconstruction/python)
PyRecoTotemRPRPElasticReconstruction_files := $(patsubst src/RecoTotemRP/RPElasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPElasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPElasticReconstruction_LOC_USE := self  
PyRecoTotemRPRPElasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPElasticReconstruction/python
ALL_PRODS += PyRecoTotemRPRPElasticReconstruction
PyRecoTotemRPRPElasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPElasticReconstruction,src/RecoTotemRP/RPElasticReconstruction/python,src_RecoTotemRP_RPElasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPElasticReconstruction,src/RecoTotemRP/RPElasticReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPElasticReconstruction_python
src_RecoTotemRP_RPElasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPElasticReconstruction_python,src/RecoTotemRP/RPElasticReconstruction/python,PYTHON))
