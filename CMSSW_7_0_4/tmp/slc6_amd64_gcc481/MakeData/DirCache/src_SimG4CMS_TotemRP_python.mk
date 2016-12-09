ifeq ($(strip $(PySimG4CMSTotemRP)),)
PySimG4CMSTotemRP := self/src/SimG4CMS/TotemRP/python
src_SimG4CMS_TotemRP_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimG4CMS/TotemRP/python)
PySimG4CMSTotemRP_files := $(patsubst src/SimG4CMS/TotemRP/python/%,%,$(wildcard $(foreach dir,src/SimG4CMS/TotemRP/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimG4CMSTotemRP_LOC_USE := self  
PySimG4CMSTotemRP_PACKAGE := self/src/SimG4CMS/TotemRP/python
ALL_PRODS += PySimG4CMSTotemRP
PySimG4CMSTotemRP_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimG4CMSTotemRP,src/SimG4CMS/TotemRP/python,src_SimG4CMS_TotemRP_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimG4CMSTotemRP,src/SimG4CMS/TotemRP/python))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRP_python
src_SimG4CMS_TotemRP_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_python,src/SimG4CMS/TotemRP/python,PYTHON))
