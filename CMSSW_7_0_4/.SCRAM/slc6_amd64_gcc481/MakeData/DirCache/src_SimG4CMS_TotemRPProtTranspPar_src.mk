ifeq ($(strip $(SimG4CMS/TotemRPProtTranspPar)),)
ALL_COMMONRULES += src_SimG4CMS_TotemRPProtTranspPar_src
src_SimG4CMS_TotemRPProtTranspPar_src_parent := SimG4CMS/TotemRPProtTranspPar
src_SimG4CMS_TotemRPProtTranspPar_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRPProtTranspPar_src,src/SimG4CMS/TotemRPProtTranspPar/src,LIBRARY))
SimG4CMSTotemRPProtTranspPar := self/SimG4CMS/TotemRPProtTranspPar
SimG4CMS/TotemRPProtTranspPar := SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/src/%,%,$(wildcard $(foreach dir,src/SimG4CMS/TotemRPProtTranspPar/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CMSTotemRPProtTranspPar_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/BuildFile
SimG4CMSTotemRPProtTranspPar_LOC_USE := self  xerces-c FWCore/MessageLogger root rootrflx
SimG4CMSTotemRPProtTranspPar_PRE_INIT_FUNC += $$(eval $$(call RootDict,SimG4CMSTotemRPProtTranspPar,src/SimG4CMS/TotemRPProtTranspPar/src, SimG4CMSTotemRPProtTranspParLinkDef.h))
SimG4CMSTotemRPProtTranspPar_EX_LIB   := SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_EX_USE   := $(foreach d,$(SimG4CMSTotemRPProtTranspPar_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CMSTotemRPProtTranspPar_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/src
ALL_PRODS += SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSTotemRPProtTranspPar,src/SimG4CMS/TotemRPProtTranspPar/src,src_SimG4CMS_TotemRPProtTranspPar_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
