ifeq ($(strip $(TotemDQMLite/Core)),)
ALL_COMMONRULES += src_TotemDQMLite_Core_src
src_TotemDQMLite_Core_src_parent := TotemDQMLite/Core
src_TotemDQMLite_Core_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_Core_src,src/TotemDQMLite/Core/src,LIBRARY))
TotemDQMLiteCore := self/TotemDQMLite/Core
TotemDQMLite/Core := TotemDQMLiteCore
TotemDQMLiteCore_files := $(patsubst src/TotemDQMLite/Core/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/Core/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteCore_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Core/BuildFile
TotemDQMLiteCore_LOC_USE := self  FWCore/Framework FWCore/FWLite FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/TotemRPDetId DataFormats/FWLite qt root rootgraphics rootinteractive TotemRawDataLibrary/Readers
TotemDQMLiteCore_EX_LIB   := TotemDQMLiteCore
TotemDQMLiteCore_EX_USE   := $(foreach d,$(TotemDQMLiteCore_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteCore_PACKAGE := self/src/TotemDQMLite/Core/src
ALL_PRODS += TotemDQMLiteCore
TotemDQMLiteCore_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteCore,src/TotemDQMLite/Core/src,src_TotemDQMLite_Core_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
