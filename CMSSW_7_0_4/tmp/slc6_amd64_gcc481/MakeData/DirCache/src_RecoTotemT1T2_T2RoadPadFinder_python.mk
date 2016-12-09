ifeq ($(strip $(PyRecoTotemT1T2T2RoadPadFinder)),)
PyRecoTotemT1T2T2RoadPadFinder := self/src/RecoTotemT1T2/T2RoadPadFinder/python
src_RecoTotemT1T2_T2RoadPadFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2RoadPadFinder/python)
PyRecoTotemT1T2T2RoadPadFinder_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RoadPadFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2RoadPadFinder_LOC_USE := self  
PyRecoTotemT1T2T2RoadPadFinder_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/python
ALL_PRODS += PyRecoTotemT1T2T2RoadPadFinder
PyRecoTotemT1T2T2RoadPadFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/python,src_RecoTotemT1T2_T2RoadPadFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_python
src_RecoTotemT1T2_T2RoadPadFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_python,src/RecoTotemT1T2/T2RoadPadFinder/python,PYTHON))
