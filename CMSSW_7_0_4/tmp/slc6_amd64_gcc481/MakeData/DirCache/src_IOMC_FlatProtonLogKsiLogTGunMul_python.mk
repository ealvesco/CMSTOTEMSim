ifeq ($(strip $(PyIOMCFlatProtonLogKsiLogTGunMul)),)
PyIOMCFlatProtonLogKsiLogTGunMul := self/src/IOMC/FlatProtonLogKsiLogTGunMul/python
src_IOMC_FlatProtonLogKsiLogTGunMul_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGunMul/python)
PyIOMCFlatProtonLogKsiLogTGunMul_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGunMul/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatProtonLogKsiLogTGunMul/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatProtonLogKsiLogTGunMul_LOC_USE := self  
PyIOMCFlatProtonLogKsiLogTGunMul_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGunMul/python
ALL_PRODS += PyIOMCFlatProtonLogKsiLogTGunMul
PyIOMCFlatProtonLogKsiLogTGunMul_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatProtonLogKsiLogTGunMul,src/IOMC/FlatProtonLogKsiLogTGunMul/python,src_IOMC_FlatProtonLogKsiLogTGunMul_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatProtonLogKsiLogTGunMul,src/IOMC/FlatProtonLogKsiLogTGunMul/python))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGunMul_python
src_IOMC_FlatProtonLogKsiLogTGunMul_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGunMul_python,src/IOMC/FlatProtonLogKsiLogTGunMul/python,PYTHON))
