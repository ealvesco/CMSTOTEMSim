ifeq ($(strip $(PyUATreeUABaseTree)),)
PyUATreeUABaseTree := self/src/UATree/UABaseTree/python
src_UATree_UABaseTree_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/UABaseTree/python)
PyUATreeUABaseTree_files := $(patsubst src/UATree/UABaseTree/python/%,%,$(wildcard $(foreach dir,src/UATree/UABaseTree/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeUABaseTree_LOC_USE := self  
PyUATreeUABaseTree_PACKAGE := self/src/UATree/UABaseTree/python
ALL_PRODS += PyUATreeUABaseTree
PyUATreeUABaseTree_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeUABaseTree,src/UATree/UABaseTree/python,src_UATree_UABaseTree_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeUABaseTree,src/UATree/UABaseTree/python))
endif
ALL_COMMONRULES += src_UATree_UABaseTree_python
src_UATree_UABaseTree_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_UABaseTree_python,src/UATree/UABaseTree/python,PYTHON))
