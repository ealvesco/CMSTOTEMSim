ifeq ($(strip $(PyIOMCPhojet)),)
PyIOMCPhojet := self/src/IOMC/Phojet/python
src_IOMC_Phojet_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/Phojet/python)
PyIOMCPhojet_files := $(patsubst src/IOMC/Phojet/python/%,%,$(wildcard $(foreach dir,src/IOMC/Phojet/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCPhojet_LOC_USE := self  
PyIOMCPhojet_PACKAGE := self/src/IOMC/Phojet/python
ALL_PRODS += PyIOMCPhojet
PyIOMCPhojet_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCPhojet,src/IOMC/Phojet/python,src_IOMC_Phojet_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCPhojet,src/IOMC/Phojet/python))
endif
ALL_COMMONRULES += src_IOMC_Phojet_python
src_IOMC_Phojet_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_python,src/IOMC/Phojet/python,PYTHON))
