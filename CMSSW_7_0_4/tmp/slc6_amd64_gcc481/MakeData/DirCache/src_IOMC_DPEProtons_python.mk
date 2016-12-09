ifeq ($(strip $(PyIOMCDPEProtons)),)
PyIOMCDPEProtons := self/src/IOMC/DPEProtons/python
src_IOMC_DPEProtons_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/DPEProtons/python)
PyIOMCDPEProtons_files := $(patsubst src/IOMC/DPEProtons/python/%,%,$(wildcard $(foreach dir,src/IOMC/DPEProtons/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCDPEProtons_LOC_USE := self  
PyIOMCDPEProtons_PACKAGE := self/src/IOMC/DPEProtons/python
ALL_PRODS += PyIOMCDPEProtons
PyIOMCDPEProtons_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCDPEProtons,src/IOMC/DPEProtons/python,src_IOMC_DPEProtons_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCDPEProtons,src/IOMC/DPEProtons/python))
endif
ALL_COMMONRULES += src_IOMC_DPEProtons_python
src_IOMC_DPEProtons_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_python,src/IOMC/DPEProtons/python,PYTHON))
