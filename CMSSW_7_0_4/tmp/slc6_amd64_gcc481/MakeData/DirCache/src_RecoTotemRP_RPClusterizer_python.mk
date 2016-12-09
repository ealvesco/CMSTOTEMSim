ifeq ($(strip $(PyRecoTotemRPRPClusterizer)),)
PyRecoTotemRPRPClusterizer := self/src/RecoTotemRP/RPClusterizer/python
src_RecoTotemRP_RPClusterizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPClusterizer/python)
PyRecoTotemRPRPClusterizer_files := $(patsubst src/RecoTotemRP/RPClusterizer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPClusterizer_LOC_USE := self  
PyRecoTotemRPRPClusterizer_PACKAGE := self/src/RecoTotemRP/RPClusterizer/python
ALL_PRODS += PyRecoTotemRPRPClusterizer
PyRecoTotemRPRPClusterizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/python,src_RecoTotemRP_RPClusterizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_python
src_RecoTotemRP_RPClusterizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_python,src/RecoTotemRP/RPClusterizer/python,PYTHON))
