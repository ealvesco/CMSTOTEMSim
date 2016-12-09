ifeq ($(strip $(PyIOMCSmearingGenerator)),)
PyIOMCSmearingGenerator := self/src/IOMC/SmearingGenerator/python
src_IOMC_SmearingGenerator_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/SmearingGenerator/python)
PyIOMCSmearingGenerator_files := $(patsubst src/IOMC/SmearingGenerator/python/%,%,$(wildcard $(foreach dir,src/IOMC/SmearingGenerator/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCSmearingGenerator_LOC_USE := self  
PyIOMCSmearingGenerator_PACKAGE := self/src/IOMC/SmearingGenerator/python
ALL_PRODS += PyIOMCSmearingGenerator
PyIOMCSmearingGenerator_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCSmearingGenerator,src/IOMC/SmearingGenerator/python,src_IOMC_SmearingGenerator_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCSmearingGenerator,src/IOMC/SmearingGenerator/python))
endif
ALL_COMMONRULES += src_IOMC_SmearingGenerator_python
src_IOMC_SmearingGenerator_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_python,src/IOMC/SmearingGenerator/python,PYTHON))
