ifeq ($(strip $(PyRecoTotemRPRPClusterSigmaService)),)
PyRecoTotemRPRPClusterSigmaService := self/src/RecoTotemRP/RPClusterSigmaService/python
src_RecoTotemRP_RPClusterSigmaService_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPClusterSigmaService/python)
PyRecoTotemRPRPClusterSigmaService_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterSigmaService/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPClusterSigmaService_LOC_USE := self  
PyRecoTotemRPRPClusterSigmaService_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/python
ALL_PRODS += PyRecoTotemRPRPClusterSigmaService
PyRecoTotemRPRPClusterSigmaService_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/python,src_RecoTotemRP_RPClusterSigmaService_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_python
src_RecoTotemRP_RPClusterSigmaService_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_python,src/RecoTotemRP/RPClusterSigmaService/python,PYTHON))
