ifeq ($(strip $(PySimG4CMSForward)),)
PySimG4CMSForward := self/src/SimG4CMS/Forward/python
src_SimG4CMS_Forward_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimG4CMS/Forward/python)
PySimG4CMSForward_files := $(patsubst src/SimG4CMS/Forward/python/%,%,$(wildcard $(foreach dir,src/SimG4CMS/Forward/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimG4CMSForward_LOC_USE := self  
PySimG4CMSForward_PACKAGE := self/src/SimG4CMS/Forward/python
ALL_PRODS += PySimG4CMSForward
PySimG4CMSForward_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimG4CMSForward,src/SimG4CMS/Forward/python,src_SimG4CMS_Forward_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimG4CMSForward,src/SimG4CMS/Forward/python))
endif
ALL_COMMONRULES += src_SimG4CMS_Forward_python
src_SimG4CMS_Forward_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_python,src/SimG4CMS/Forward/python,PYTHON))
