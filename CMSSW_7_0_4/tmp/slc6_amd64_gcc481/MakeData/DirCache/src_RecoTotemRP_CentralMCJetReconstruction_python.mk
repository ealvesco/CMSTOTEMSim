ifeq ($(strip $(PyRecoTotemRPCentralMCJetReconstruction)),)
PyRecoTotemRPCentralMCJetReconstruction := self/src/RecoTotemRP/CentralMCJetReconstruction/python
src_RecoTotemRP_CentralMCJetReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/CentralMCJetReconstruction/python)
PyRecoTotemRPCentralMCJetReconstruction_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/CentralMCJetReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPCentralMCJetReconstruction_LOC_USE := self  
PyRecoTotemRPCentralMCJetReconstruction_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/python
ALL_PRODS += PyRecoTotemRPCentralMCJetReconstruction
PyRecoTotemRPCentralMCJetReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/python,src_RecoTotemRP_CentralMCJetReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_python
src_RecoTotemRP_CentralMCJetReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_python,src/RecoTotemRP/CentralMCJetReconstruction/python,PYTHON))
