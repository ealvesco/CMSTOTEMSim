ifeq ($(strip $(PyIOMCFlatThetaXYGun)),)
PyIOMCFlatThetaXYGun := self/src/IOMC/FlatThetaXYGun/python
src_IOMC_FlatThetaXYGun_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatThetaXYGun/python)
PyIOMCFlatThetaXYGun_files := $(patsubst src/IOMC/FlatThetaXYGun/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatThetaXYGun/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatThetaXYGun_LOC_USE := self  
PyIOMCFlatThetaXYGun_PACKAGE := self/src/IOMC/FlatThetaXYGun/python
ALL_PRODS += PyIOMCFlatThetaXYGun
PyIOMCFlatThetaXYGun_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatThetaXYGun,src/IOMC/FlatThetaXYGun/python,src_IOMC_FlatThetaXYGun_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatThetaXYGun,src/IOMC/FlatThetaXYGun/python))
endif
ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_python
src_IOMC_FlatThetaXYGun_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_python,src/IOMC/FlatThetaXYGun/python,PYTHON))
