ifeq ($(strip $(PySimTotemRPDigiProducer)),)
PySimTotemRPDigiProducer := self/src/SimTotem/RPDigiProducer/python
src_SimTotem_RPDigiProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/RPDigiProducer/python)
PySimTotemRPDigiProducer_files := $(patsubst src/SimTotem/RPDigiProducer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/RPDigiProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemRPDigiProducer_LOC_USE := self  
PySimTotemRPDigiProducer_PACKAGE := self/src/SimTotem/RPDigiProducer/python
ALL_PRODS += PySimTotemRPDigiProducer
PySimTotemRPDigiProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/python,src_SimTotem_RPDigiProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/python))
endif
ALL_COMMONRULES += src_SimTotem_RPDigiProducer_python
src_SimTotem_RPDigiProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_python,src/SimTotem/RPDigiProducer/python,PYTHON))
