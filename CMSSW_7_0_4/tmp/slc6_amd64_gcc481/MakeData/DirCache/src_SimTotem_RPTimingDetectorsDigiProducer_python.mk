ifeq ($(strip $(PySimTotemRPTimingDetectorsDigiProducer)),)
PySimTotemRPTimingDetectorsDigiProducer := self/src/SimTotem/RPTimingDetectorsDigiProducer/python
src_SimTotem_RPTimingDetectorsDigiProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/RPTimingDetectorsDigiProducer/python)
PySimTotemRPTimingDetectorsDigiProducer_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemRPTimingDetectorsDigiProducer_LOC_USE := self  
PySimTotemRPTimingDetectorsDigiProducer_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/python
ALL_PRODS += PySimTotemRPTimingDetectorsDigiProducer
PySimTotemRPTimingDetectorsDigiProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/python,src_SimTotem_RPTimingDetectorsDigiProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/python))
endif
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_python
src_SimTotem_RPTimingDetectorsDigiProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_python,src/SimTotem/RPTimingDetectorsDigiProducer/python,PYTHON))
