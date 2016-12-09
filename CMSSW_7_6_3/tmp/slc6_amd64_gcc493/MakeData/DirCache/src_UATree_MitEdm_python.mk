ifeq ($(strip $(PyUATreeMitEdm)),)
PyUATreeMitEdm := self/src/UATree/MitEdm/python
src_UATree_MitEdm_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/MitEdm/python)
PyUATreeMitEdm_files := $(patsubst src/UATree/MitEdm/python/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeMitEdm_LOC_USE := self  
PyUATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/python
ALL_PRODS += PyUATreeMitEdm
PyUATreeMitEdm_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeMitEdm,src/UATree/MitEdm/python,src_UATree_MitEdm_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeMitEdm,src/UATree/MitEdm/python))
endif
ALL_COMMONRULES += src_UATree_MitEdm_python
src_UATree_MitEdm_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_MitEdm_python,src/UATree/MitEdm/python,PYTHON))
