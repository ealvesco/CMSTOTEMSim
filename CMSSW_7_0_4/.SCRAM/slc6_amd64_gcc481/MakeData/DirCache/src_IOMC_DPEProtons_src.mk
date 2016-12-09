ifeq ($(strip $(IOMC/DPEProtons)),)
ALL_COMMONRULES += src_IOMC_DPEProtons_src
src_IOMC_DPEProtons_src_parent := IOMC/DPEProtons
src_IOMC_DPEProtons_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_src,src/IOMC/DPEProtons/src,LIBRARY))
IOMCDPEProtons := self/IOMC/DPEProtons
IOMC/DPEProtons := IOMCDPEProtons
IOMCDPEProtons_files := $(patsubst src/IOMC/DPEProtons/src/%,%,$(wildcard $(foreach dir,src/IOMC/DPEProtons/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
IOMCDPEProtons_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/DPEProtons/BuildFile
IOMCDPEProtons_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCDPEProtons_EX_LIB   := IOMCDPEProtons
IOMCDPEProtons_EX_USE   := $(foreach d,$(IOMCDPEProtons_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
IOMCDPEProtons_PACKAGE := self/src/IOMC/DPEProtons/src
ALL_PRODS += IOMCDPEProtons
IOMCDPEProtons_INIT_FUNC        += $$(eval $$(call Library,IOMCDPEProtons,src/IOMC/DPEProtons/src,src_IOMC_DPEProtons_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
