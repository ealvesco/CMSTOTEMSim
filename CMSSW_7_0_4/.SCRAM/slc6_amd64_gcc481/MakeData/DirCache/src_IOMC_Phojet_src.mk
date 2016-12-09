ifeq ($(strip $(IOMC/Phojet)),)
ALL_COMMONRULES += src_IOMC_Phojet_src
src_IOMC_Phojet_src_parent := IOMC/Phojet
src_IOMC_Phojet_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_IOMC_Phojet_src,src/IOMC/Phojet/src,LIBRARY))
IOMCPhojet := self/IOMC/Phojet
IOMC/Phojet := IOMCPhojet
IOMCPhojet_files := $(patsubst src/IOMC/Phojet/src/%,%,$(wildcard $(foreach dir,src/IOMC/Phojet/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
IOMCPhojet_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Phojet/BuildFile
IOMCPhojet_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCPhojet_EX_LIB   := IOMCPhojet
IOMCPhojet_EX_USE   := $(foreach d,$(IOMCPhojet_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
IOMCPhojet_PACKAGE := self/src/IOMC/Phojet/src
ALL_PRODS += IOMCPhojet
IOMCPhojet_INIT_FUNC        += $$(eval $$(call Library,IOMCPhojet,src/IOMC/Phojet/src,src_IOMC_Phojet_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
