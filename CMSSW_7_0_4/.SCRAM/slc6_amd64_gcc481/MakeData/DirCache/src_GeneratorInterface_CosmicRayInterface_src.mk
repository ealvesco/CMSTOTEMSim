ifeq ($(strip $(GeneratorInterface/CosmicRayInterface)),)
ALL_COMMONRULES += src_GeneratorInterface_CosmicRayInterface_src
src_GeneratorInterface_CosmicRayInterface_src_parent := GeneratorInterface/CosmicRayInterface
src_GeneratorInterface_CosmicRayInterface_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_GeneratorInterface_CosmicRayInterface_src,src/GeneratorInterface/CosmicRayInterface/src,LIBRARY))
GeneratorInterfaceCosmicRayInterface := self/GeneratorInterface/CosmicRayInterface
GeneratorInterface/CosmicRayInterface := GeneratorInterfaceCosmicRayInterface
GeneratorInterfaceCosmicRayInterface_files := $(patsubst src/GeneratorInterface/CosmicRayInterface/src/%,%,$(wildcard $(foreach dir,src/GeneratorInterface/CosmicRayInterface/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeneratorInterfaceCosmicRayInterface_BuildFile    := $(WORKINGDIR)/cache/bf/src/GeneratorInterface/CosmicRayInterface/BuildFile
GeneratorInterfaceCosmicRayInterface_LOC_FLAGS_CPPDEFINES   := -D__SIBYLL__ -D__QGSJET01__ -D__QGSJETII__
GeneratorInterfaceCosmicRayInterface_LOC_USE := self  clhep boost GeneratorInterface/Core FWCore/Framework SimDataFormats/GeneratorProducts GeneratorInterface/ExternalDecays f77compiler
GeneratorInterfaceCosmicRayInterface_EX_LIB   := GeneratorInterfaceCosmicRayInterface
GeneratorInterfaceCosmicRayInterface_EX_USE   := $(foreach d,$(GeneratorInterfaceCosmicRayInterface_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeneratorInterfaceCosmicRayInterface_PACKAGE := self/src/GeneratorInterface/CosmicRayInterface/src
ALL_PRODS += GeneratorInterfaceCosmicRayInterface
GeneratorInterfaceCosmicRayInterface_INIT_FUNC        += $$(eval $$(call Library,GeneratorInterfaceCosmicRayInterface,src/GeneratorInterface/CosmicRayInterface/src,src_GeneratorInterface_CosmicRayInterface_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
