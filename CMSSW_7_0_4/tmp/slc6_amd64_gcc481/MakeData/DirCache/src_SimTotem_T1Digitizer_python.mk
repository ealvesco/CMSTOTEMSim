ifeq ($(strip $(PySimTotemT1Digitizer)),)
PySimTotemT1Digitizer := self/src/SimTotem/T1Digitizer/python
src_SimTotem_T1Digitizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/T1Digitizer/python)
PySimTotemT1Digitizer_files := $(patsubst src/SimTotem/T1Digitizer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/T1Digitizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemT1Digitizer_LOC_USE := self  
PySimTotemT1Digitizer_PACKAGE := self/src/SimTotem/T1Digitizer/python
ALL_PRODS += PySimTotemT1Digitizer
PySimTotemT1Digitizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemT1Digitizer,src/SimTotem/T1Digitizer/python,src_SimTotem_T1Digitizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemT1Digitizer,src/SimTotem/T1Digitizer/python))
endif
ALL_COMMONRULES += src_SimTotem_T1Digitizer_python
src_SimTotem_T1Digitizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_python,src/SimTotem/T1Digitizer/python,PYTHON))
