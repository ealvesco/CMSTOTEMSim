ifeq ($(strip $(TotemRPFindApproximation)),)
TotemRPFindApproximation_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/bin/%,%,$(foreach file,FindApproximation.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRPProtTranspPar/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRPProtTranspPar/bin/$(file). Please fix src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile.))))
TotemRPFindApproximation := self/src/SimG4CMS/TotemRPProtTranspPar/bin
TotemRPFindApproximation_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile
TotemRPFindApproximation_LOC_USE := self  root xerces-c SimG4CMS/TotemRPProtTranspPar
TotemRPFindApproximation_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/bin
ALL_PRODS += TotemRPFindApproximation
TotemRPFindApproximation_INIT_FUNC        += $$(eval $$(call Binary,TotemRPFindApproximation,src/SimG4CMS/TotemRPProtTranspPar/bin,src_SimG4CMS_TotemRPProtTranspPar_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPFindApproximation,src/SimG4CMS/TotemRPProtTranspPar/bin))
endif
ifeq ($(strip $(TotemRPFindApertures)),)
TotemRPFindApertures_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/bin/%,%,$(foreach file,FindApertures.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRPProtTranspPar/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRPProtTranspPar/bin/$(file). Please fix src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile.))))
TotemRPFindApertures := self/src/SimG4CMS/TotemRPProtTranspPar/bin
TotemRPFindApertures_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile
TotemRPFindApertures_LOC_USE := self  root xerces-c SimG4CMS/TotemRPProtTranspPar
TotemRPFindApertures_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/bin
ALL_PRODS += TotemRPFindApertures
TotemRPFindApertures_INIT_FUNC        += $$(eval $$(call Binary,TotemRPFindApertures,src/SimG4CMS/TotemRPProtTranspPar/bin,src_SimG4CMS_TotemRPProtTranspPar_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPFindApertures,src/SimG4CMS/TotemRPProtTranspPar/bin))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRPProtTranspPar_bin
src_SimG4CMS_TotemRPProtTranspPar_bin_parent := SimG4CMS/TotemRPProtTranspPar
src_SimG4CMS_TotemRPProtTranspPar_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRPProtTranspPar_bin,src/SimG4CMS/TotemRPProtTranspPar/bin,BINARY))
