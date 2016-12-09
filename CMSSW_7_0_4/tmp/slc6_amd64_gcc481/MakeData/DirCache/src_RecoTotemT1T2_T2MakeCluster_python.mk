ifeq ($(strip $(PyRecoTotemT1T2T2MakeCluster)),)
PyRecoTotemT1T2T2MakeCluster := self/src/RecoTotemT1T2/T2MakeCluster/python
src_RecoTotemT1T2_T2MakeCluster_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2MakeCluster/python)
PyRecoTotemT1T2T2MakeCluster_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2MakeCluster/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2MakeCluster_LOC_USE := self  
PyRecoTotemT1T2T2MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/python
ALL_PRODS += PyRecoTotemT1T2T2MakeCluster
PyRecoTotemT1T2T2MakeCluster_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/python,src_RecoTotemT1T2_T2MakeCluster_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_python
src_RecoTotemT1T2_T2MakeCluster_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_python,src/RecoTotemT1T2/T2MakeCluster/python,PYTHON))
