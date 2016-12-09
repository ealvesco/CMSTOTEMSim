ifeq ($(strip $(IOMC/Elegent)),)
ALL_COMMONRULES += src_IOMC_Elegent_src
src_IOMC_Elegent_src_parent := IOMC/Elegent
src_IOMC_Elegent_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_IOMC_Elegent_src,src/IOMC/Elegent/src,LIBRARY))
IOMCElegent := self/IOMC/Elegent
IOMC/Elegent := IOMCElegent
IOMCElegent_files := $(patsubst src/IOMC/Elegent/src/%,%,$(wildcard $(foreach dir,src/IOMC/Elegent/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
IOMCElegent_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/BuildFile
IOMCElegent_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
IOMCElegent_LOC_USE := self  FWCore/Framework SimDataFormats/GeneratorProducts hepmc root clhep
IOMCElegent_EX_LIB   := IOMCElegent
IOMCElegent_EX_USE   := $(foreach d,$(IOMCElegent_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
IOMCElegent_PACKAGE := self/src/IOMC/Elegent/src
ALL_PRODS += IOMCElegent
IOMCElegent_INIT_FUNC        += $$(eval $$(call Library,IOMCElegent,src/IOMC/Elegent/src,src_IOMC_Elegent_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
