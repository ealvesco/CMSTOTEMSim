ifeq ($(strip $(PyTotemDQMLiteGUI)),)
PyTotemDQMLiteGUI := self/src/TotemDQMLite/GUI/python
src_TotemDQMLite_GUI_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemDQMLite/GUI/python)
PyTotemDQMLiteGUI_files := $(patsubst src/TotemDQMLite/GUI/python/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/GUI/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemDQMLiteGUI_LOC_USE := self  
PyTotemDQMLiteGUI_PACKAGE := self/src/TotemDQMLite/GUI/python
ALL_PRODS += PyTotemDQMLiteGUI
PyTotemDQMLiteGUI_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemDQMLiteGUI,src/TotemDQMLite/GUI/python,src_TotemDQMLite_GUI_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemDQMLiteGUI,src/TotemDQMLite/GUI/python))
endif
ALL_COMMONRULES += src_TotemDQMLite_GUI_python
src_TotemDQMLite_GUI_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_GUI_python,src/TotemDQMLite/GUI/python,PYTHON))
