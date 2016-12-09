ifeq ($(strip $(PyGeneratorInterfacePompytInterface)),)
PyGeneratorInterfacePompytInterface := self/src/GeneratorInterface/PompytInterface/python
src_GeneratorInterface_PompytInterface_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/GeneratorInterface/PompytInterface/python)
PyGeneratorInterfacePompytInterface_files := $(patsubst src/GeneratorInterface/PompytInterface/python/%,%,$(wildcard $(foreach dir,src/GeneratorInterface/PompytInterface/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeneratorInterfacePompytInterface_LOC_USE := self  
PyGeneratorInterfacePompytInterface_PACKAGE := self/src/GeneratorInterface/PompytInterface/python
ALL_PRODS += PyGeneratorInterfacePompytInterface
PyGeneratorInterfacePompytInterface_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeneratorInterfacePompytInterface,src/GeneratorInterface/PompytInterface/python,src_GeneratorInterface_PompytInterface_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeneratorInterfacePompytInterface,src/GeneratorInterface/PompytInterface/python))
endif
ALL_COMMONRULES += src_GeneratorInterface_PompytInterface_python
src_GeneratorInterface_PompytInterface_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GeneratorInterface_PompytInterface_python,src/GeneratorInterface/PompytInterface/python,PYTHON))
