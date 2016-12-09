ifeq ($(strip $(PyRecoTotemT1T2T2RecHit)),)
PyRecoTotemT1T2T2RecHit := self/src/RecoTotemT1T2/T2RecHit/python
src_RecoTotemT1T2_T2RecHit_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2RecHit/python)
PyRecoTotemT1T2T2RecHit_files := $(patsubst src/RecoTotemT1T2/T2RecHit/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RecHit/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2RecHit_LOC_USE := self  
PyRecoTotemT1T2T2RecHit_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/python
ALL_PRODS += PyRecoTotemT1T2T2RecHit
PyRecoTotemT1T2T2RecHit_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/python,src_RecoTotemT1T2_T2RecHit_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_python
src_RecoTotemT1T2_T2RecHit_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_python,src/RecoTotemT1T2/T2RecHit/python,PYTHON))
