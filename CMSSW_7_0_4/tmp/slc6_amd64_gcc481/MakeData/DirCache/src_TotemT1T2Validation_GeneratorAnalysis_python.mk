ifeq ($(strip $(PyTotemT1T2ValidationGeneratorAnalysis)),)
PyTotemT1T2ValidationGeneratorAnalysis := self/src/TotemT1T2Validation/GeneratorAnalysis/python
src_TotemT1T2Validation_GeneratorAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/GeneratorAnalysis/python)
PyTotemT1T2ValidationGeneratorAnalysis_files := $(patsubst src/TotemT1T2Validation/GeneratorAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/GeneratorAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationGeneratorAnalysis_LOC_USE := self  
PyTotemT1T2ValidationGeneratorAnalysis_PACKAGE := self/src/TotemT1T2Validation/GeneratorAnalysis/python
ALL_PRODS += PyTotemT1T2ValidationGeneratorAnalysis
PyTotemT1T2ValidationGeneratorAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/python,src_TotemT1T2Validation_GeneratorAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_python
src_TotemT1T2Validation_GeneratorAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_python,src/TotemT1T2Validation/GeneratorAnalysis/python,PYTHON))
