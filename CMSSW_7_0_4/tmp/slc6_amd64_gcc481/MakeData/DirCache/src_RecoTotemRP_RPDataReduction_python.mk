ifeq ($(strip $(PyRecoTotemRPRPDataReduction)),)
PyRecoTotemRPRPDataReduction := self/src/RecoTotemRP/RPDataReduction/python
src_RecoTotemRP_RPDataReduction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPDataReduction/python)
PyRecoTotemRPRPDataReduction_files := $(patsubst src/RecoTotemRP/RPDataReduction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDataReduction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPDataReduction_LOC_USE := self  
PyRecoTotemRPRPDataReduction_PACKAGE := self/src/RecoTotemRP/RPDataReduction/python
ALL_PRODS += PyRecoTotemRPRPDataReduction
PyRecoTotemRPRPDataReduction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/python,src_RecoTotemRP_RPDataReduction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_python
src_RecoTotemRP_RPDataReduction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_python,src/RecoTotemRP/RPDataReduction/python,PYTHON))
