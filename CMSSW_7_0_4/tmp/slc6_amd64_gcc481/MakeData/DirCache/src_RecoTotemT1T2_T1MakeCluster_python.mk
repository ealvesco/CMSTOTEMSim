ifeq ($(strip $(PyRecoTotemT1T2T1MakeCluster)),)
PyRecoTotemT1T2T1MakeCluster := self/src/RecoTotemT1T2/T1MakeCluster/python
src_RecoTotemT1T2_T1MakeCluster_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1MakeCluster/python)
PyRecoTotemT1T2T1MakeCluster_files := $(patsubst src/RecoTotemT1T2/T1MakeCluster/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1MakeCluster/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1MakeCluster_LOC_USE := self  
PyRecoTotemT1T2T1MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T1MakeCluster/python
ALL_PRODS += PyRecoTotemT1T2T1MakeCluster
PyRecoTotemT1T2T1MakeCluster_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster/python,src_RecoTotemT1T2_T1MakeCluster_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1MakeCluster_python
src_RecoTotemT1T2_T1MakeCluster_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1MakeCluster_python,src/RecoTotemT1T2/T1MakeCluster/python,PYTHON))
