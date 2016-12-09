ifeq ($(strip $(PyIOMCFlatProtonLogKsiLogTGun)),)
PyIOMCFlatProtonLogKsiLogTGun := self/src/IOMC/FlatProtonLogKsiLogTGun/python
src_IOMC_FlatProtonLogKsiLogTGun_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGun/python)
PyIOMCFlatProtonLogKsiLogTGun_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGun/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatProtonLogKsiLogTGun/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatProtonLogKsiLogTGun_LOC_USE := self  
PyIOMCFlatProtonLogKsiLogTGun_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGun/python
ALL_PRODS += PyIOMCFlatProtonLogKsiLogTGun
PyIOMCFlatProtonLogKsiLogTGun_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatProtonLogKsiLogTGun,src/IOMC/FlatProtonLogKsiLogTGun/python,src_IOMC_FlatProtonLogKsiLogTGun_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatProtonLogKsiLogTGun,src/IOMC/FlatProtonLogKsiLogTGun/python))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_python
src_IOMC_FlatProtonLogKsiLogTGun_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_python,src/IOMC/FlatProtonLogKsiLogTGun/python,PYTHON))
