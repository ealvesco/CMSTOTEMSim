ifeq ($(strip $(SimG4CMS/Forward)),)
ALL_COMMONRULES += src_SimG4CMS_Forward_src
src_SimG4CMS_Forward_src_parent := SimG4CMS/Forward
src_SimG4CMS_Forward_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_src,src/SimG4CMS/Forward/src,LIBRARY))
SimG4CMSForward := self/SimG4CMS/Forward
SimG4CMS/Forward := SimG4CMSForward
SimG4CMSForward_files := $(patsubst src/SimG4CMS/Forward/src/%,%,$(wildcard $(foreach dir,src/SimG4CMS/Forward/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CMSForward_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/Forward/BuildFile
SimG4CMSForward_LOC_USE := self  DataFormats/T1DetId DataFormats/T2DetId rootrflx FWCore/PluginManager SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo DataFormats/Math SimDataFormats/SimHitMaker SimDataFormats/CaloHit SimDataFormats/Forward DetectorDescription/Core FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger boost geant4core root rootmath
SimG4CMSForward_EX_LIB   := SimG4CMSForward
SimG4CMSForward_EX_USE   := $(foreach d,$(SimG4CMSForward_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CMSForward_PACKAGE := self/src/SimG4CMS/Forward/src
ALL_PRODS += SimG4CMSForward
SimG4CMSForward_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSForward,src/SimG4CMS/Forward/src,src_SimG4CMS_Forward_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
