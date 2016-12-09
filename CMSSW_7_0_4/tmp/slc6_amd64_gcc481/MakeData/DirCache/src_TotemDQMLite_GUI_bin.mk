ifeq ($(strip $(TotemDQMLite)),)
TotemDQMLite_files := $(patsubst src/TotemDQMLite/GUI/bin/%,%,$(foreach file,TotemDQMLite.cc,$(eval xfile:=$(wildcard src/TotemDQMLite/GUI/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemDQMLite/GUI/bin/$(file). Please fix src/TotemDQMLite/GUI/bin/BuildFile.))))
TotemDQMLite := self/src/TotemDQMLite/GUI/bin
TotemDQMLite_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/GUI/bin/BuildFile
TotemDQMLite_LOC_USE := self  FWCore/Framework FWCore/FWLite FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/TotemRPDetId DataFormats/FWLite TotemDQMLite/Core TotemDQMLite/GUI qt root rootgraphics rootinteractive
TotemDQMLite_PACKAGE := self/src/TotemDQMLite/GUI/bin
ALL_PRODS += TotemDQMLite
TotemDQMLite_INIT_FUNC        += $$(eval $$(call Binary,TotemDQMLite,src/TotemDQMLite/GUI/bin,src_TotemDQMLite_GUI_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemDQMLite,src/TotemDQMLite/GUI/bin))
endif
ifeq ($(strip $(TotemDQMLiteBatch)),)
TotemDQMLiteBatch_files := $(patsubst src/TotemDQMLite/GUI/bin/%,%,$(foreach file,TotemDQMLiteBatch.cc,$(eval xfile:=$(wildcard src/TotemDQMLite/GUI/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemDQMLite/GUI/bin/$(file). Please fix src/TotemDQMLite/GUI/bin/BuildFile.))))
TotemDQMLiteBatch := self/src/TotemDQMLite/GUI/bin
TotemDQMLiteBatch_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/GUI/bin/BuildFile
TotemDQMLiteBatch_LOC_USE := self  FWCore/Framework FWCore/FWLite FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/TotemRPDetId DataFormats/FWLite TotemDQMLite/Core TotemDQMLite/GUI qt root rootgraphics rootinteractive
TotemDQMLiteBatch_PACKAGE := self/src/TotemDQMLite/GUI/bin
ALL_PRODS += TotemDQMLiteBatch
TotemDQMLiteBatch_INIT_FUNC        += $$(eval $$(call Binary,TotemDQMLiteBatch,src/TotemDQMLite/GUI/bin,src_TotemDQMLite_GUI_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemDQMLiteBatch,src/TotemDQMLite/GUI/bin))
endif
ALL_COMMONRULES += src_TotemDQMLite_GUI_bin
src_TotemDQMLite_GUI_bin_parent := TotemDQMLite/GUI
src_TotemDQMLite_GUI_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_GUI_bin,src/TotemDQMLite/GUI/bin,BINARY))
