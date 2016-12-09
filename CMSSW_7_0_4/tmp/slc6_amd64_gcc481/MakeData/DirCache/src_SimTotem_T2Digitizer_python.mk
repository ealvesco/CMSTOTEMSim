ifeq ($(strip $(PySimTotemT2Digitizer)),)
PySimTotemT2Digitizer := self/src/SimTotem/T2Digitizer/python
src_SimTotem_T2Digitizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/T2Digitizer/python)
PySimTotemT2Digitizer_files := $(patsubst src/SimTotem/T2Digitizer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/T2Digitizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemT2Digitizer_LOC_USE := self  
PySimTotemT2Digitizer_PACKAGE := self/src/SimTotem/T2Digitizer/python
ALL_PRODS += PySimTotemT2Digitizer
PySimTotemT2Digitizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemT2Digitizer,src/SimTotem/T2Digitizer/python,src_SimTotem_T2Digitizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemT2Digitizer,src/SimTotem/T2Digitizer/python))
endif
ALL_COMMONRULES += src_SimTotem_T2Digitizer_python
src_SimTotem_T2Digitizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_python,src/SimTotem/T2Digitizer/python,PYTHON))
