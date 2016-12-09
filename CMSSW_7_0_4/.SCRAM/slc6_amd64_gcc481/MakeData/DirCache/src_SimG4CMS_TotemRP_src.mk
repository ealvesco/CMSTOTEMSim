ifeq ($(strip $(SimG4CMS/TotemRP)),)
ALL_COMMONRULES += src_SimG4CMS_TotemRP_src
src_SimG4CMS_TotemRP_src_parent := SimG4CMS/TotemRP
src_SimG4CMS_TotemRP_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_src,src/SimG4CMS/TotemRP/src,LIBRARY))
SimG4CMSTotemRP := self/SimG4CMS/TotemRP
SimG4CMS/TotemRP := SimG4CMSTotemRP
SimG4CMSTotemRP_files := $(patsubst src/SimG4CMS/TotemRP/src/%,%,$(wildcard $(foreach dir,src/SimG4CMS/TotemRP/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CMSTotemRP_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRP/BuildFile
SimG4CMSTotemRP_LOC_USE := self  SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo SimDataFormats/SimHitMaker SimDataFormats/CaloHit DetectorDescription/Core FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/MessageLogger DataFormats/TotemRPDetId boost geant4 root rootrflx
SimG4CMSTotemRP_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CMSTotemRPCapabilities,SimG4CMSTotemRP,$(SCRAMSTORENAME_LIB),src/SimG4CMS/TotemRP/src))
SimG4CMSTotemRP_PRE_INIT_FUNC += $$(eval $$(call LCGDict,SimG4CMSTotemRP,0,src/SimG4CMS/TotemRP/src/classes.h,src/SimG4CMS/TotemRP/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
SimG4CMSTotemRP_EX_LIB   := SimG4CMSTotemRP
SimG4CMSTotemRP_EX_USE   := $(foreach d,$(SimG4CMSTotemRP_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CMSTotemRP_PACKAGE := self/src/SimG4CMS/TotemRP/src
ALL_PRODS += SimG4CMSTotemRP
SimG4CMSTotemRP_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSTotemRP,src/SimG4CMS/TotemRP/src,src_SimG4CMS_TotemRP_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
