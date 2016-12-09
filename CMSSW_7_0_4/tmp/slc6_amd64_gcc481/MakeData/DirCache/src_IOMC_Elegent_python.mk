ifeq ($(strip $(PyIOMCElegent)),)
PyIOMCElegent := self/src/IOMC/Elegent/python
src_IOMC_Elegent_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/Elegent/python)
PyIOMCElegent_files := $(patsubst src/IOMC/Elegent/python/%,%,$(wildcard $(foreach dir,src/IOMC/Elegent/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCElegent_LOC_USE := self  
PyIOMCElegent_PACKAGE := self/src/IOMC/Elegent/python
ALL_PRODS += PyIOMCElegent
PyIOMCElegent_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCElegent,src/IOMC/Elegent/python,src_IOMC_Elegent_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCElegent,src/IOMC/Elegent/python))
endif
ALL_COMMONRULES += src_IOMC_Elegent_python
src_IOMC_Elegent_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_python,src/IOMC/Elegent/python,PYTHON))
