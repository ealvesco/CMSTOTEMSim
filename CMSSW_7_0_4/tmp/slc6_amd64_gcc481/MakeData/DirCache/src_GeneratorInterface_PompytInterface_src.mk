ifeq ($(strip $(GeneratorInterface/PompytInterface)),)
ALL_COMMONRULES += src_GeneratorInterface_PompytInterface_src
src_GeneratorInterface_PompytInterface_src_parent := GeneratorInterface/PompytInterface
src_GeneratorInterface_PompytInterface_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_GeneratorInterface_PompytInterface_src,src/GeneratorInterface/PompytInterface/src,LIBRARY))
GeneratorInterfacePompytInterface := self/GeneratorInterface/PompytInterface
GeneratorInterface/PompytInterface := GeneratorInterfacePompytInterface
GeneratorInterfacePompytInterface_files := $(patsubst src/GeneratorInterface/PompytInterface/src/%,%,$(wildcard $(foreach dir,src/GeneratorInterface/PompytInterface/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeneratorInterfacePompytInterface_BuildFile    := $(WORKINGDIR)/cache/bf/src/GeneratorInterface/PompytInterface/BuildFile
GeneratorInterfacePompytInterface_LOC_FLAGS_LDFLAGS   := $(PYTHIA6_BASE)/lib/pydata.o
GeneratorInterfacePompytInterface_LOC_USE := self  boost FWCore/Framework GeneratorInterface/Pythia6Interface SimDataFormats/GeneratorProducts GeneratorInterface/Core clhep pythia6 f77compiler
GeneratorInterfacePompytInterface_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeneratorInterfacePompytInterface,GeneratorInterfacePompytInterface,$(SCRAMSTORENAME_LIB),src/GeneratorInterface/PompytInterface/src))
GeneratorInterfacePompytInterface_PACKAGE := self/src/GeneratorInterface/PompytInterface/src
ALL_PRODS += GeneratorInterfacePompytInterface
GeneratorInterfacePompytInterface_INIT_FUNC        += $$(eval $$(call Library,GeneratorInterfacePompytInterface,src/GeneratorInterface/PompytInterface/src,src_GeneratorInterface_PompytInterface_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
