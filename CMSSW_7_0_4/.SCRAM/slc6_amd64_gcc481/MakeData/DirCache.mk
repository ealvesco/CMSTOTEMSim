ifeq ($(strip $(DataFormats/DetId)),)
ALL_COMMONRULES += src_DataFormats_DetId_src
src_DataFormats_DetId_src_parent := DataFormats/DetId
src_DataFormats_DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_DetId_src,src/DataFormats/DetId/src,LIBRARY))
DataFormatsDetId := self/DataFormats/DetId
DataFormats/DetId := DataFormatsDetId
DataFormatsDetId_files := $(patsubst src/DataFormats/DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsDetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/DetId/BuildFile
DataFormatsDetId_LOC_USE := self  boost rootrflx DataFormats/Common
DataFormatsDetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsDetIdCapabilities,DataFormatsDetId,$(SCRAMSTORENAME_LIB),src/DataFormats/DetId/src))
DataFormatsDetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsDetId,0,src/DataFormats/DetId/src/classes.h,src/DataFormats/DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsDetId_EX_LIB   := DataFormatsDetId
DataFormatsDetId_EX_USE   := $(foreach d,$(DataFormatsDetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsDetId_PACKAGE := self/src/DataFormats/DetId/src
ALL_PRODS += DataFormatsDetId
DataFormatsDetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsDetId,src/DataFormats/DetId/src,src_DataFormats_DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1Cluster)),)
ALL_COMMONRULES += src_DataFormats_T1Cluster_src
src_DataFormats_T1Cluster_src_parent := DataFormats/T1Cluster
src_DataFormats_T1Cluster_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1Cluster_src,src/DataFormats/T1Cluster/src,LIBRARY))
DataFormatsT1Cluster := self/DataFormats/T1Cluster
DataFormats/T1Cluster := DataFormatsT1Cluster
DataFormatsT1Cluster_files := $(patsubst src/DataFormats/T1Cluster/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1Cluster/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1Cluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1Cluster/BuildFile
DataFormatsT1Cluster_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1Cluster_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1ClusterCapabilities,DataFormatsT1Cluster,$(SCRAMSTORENAME_LIB),src/DataFormats/T1Cluster/src))
DataFormatsT1Cluster_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1Cluster,0,src/DataFormats/T1Cluster/src/classes.h,src/DataFormats/T1Cluster/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1Cluster_EX_LIB   := DataFormatsT1Cluster
DataFormatsT1Cluster_EX_USE   := $(foreach d,$(DataFormatsT1Cluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1Cluster_PACKAGE := self/src/DataFormats/T1Cluster/src
ALL_PRODS += DataFormatsT1Cluster
DataFormatsT1Cluster_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1Cluster,src/DataFormats/T1Cluster/src,src_DataFormats_T1Cluster_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1DetId)),)
ALL_COMMONRULES += src_DataFormats_T1DetId_src
src_DataFormats_T1DetId_src_parent := DataFormats/T1DetId
src_DataFormats_T1DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DetId_src,src/DataFormats/T1DetId/src,LIBRARY))
DataFormatsT1DetId := self/DataFormats/T1DetId
DataFormats/T1DetId := DataFormatsT1DetId
DataFormatsT1DetId_files := $(patsubst src/DataFormats/T1DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DetId/BuildFile
DataFormatsT1DetId_LOC_USE := self  DataFormats/Common DataFormats/DetId FWCore/Utilities boost rootrflx
DataFormatsT1DetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DetIdCapabilities,DataFormatsT1DetId,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DetId/src))
DataFormatsT1DetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DetId,0,src/DataFormats/T1DetId/src/classes.h,src/DataFormats/T1DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DetId_EX_LIB   := DataFormatsT1DetId
DataFormatsT1DetId_EX_USE   := $(foreach d,$(DataFormatsT1DetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DetId_PACKAGE := self/src/DataFormats/T1DetId/src
ALL_PRODS += DataFormatsT1DetId
DataFormatsT1DetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DetId,src/DataFormats/T1DetId/src,src_DataFormats_T1DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1Digi)),)
ALL_COMMONRULES += src_DataFormats_T1Digi_src
src_DataFormats_T1Digi_src_parent := DataFormats/T1Digi
src_DataFormats_T1Digi_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1Digi_src,src/DataFormats/T1Digi/src,LIBRARY))
DataFormatsT1Digi := self/DataFormats/T1Digi
DataFormats/T1Digi := DataFormatsT1Digi
DataFormatsT1Digi_files := $(patsubst src/DataFormats/T1Digi/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1Digi/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1Digi_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1Digi/BuildFile
DataFormatsT1Digi_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1Digi_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiCapabilities,DataFormatsT1Digi,$(SCRAMSTORENAME_LIB),src/DataFormats/T1Digi/src))
DataFormatsT1Digi_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1Digi,0,src/DataFormats/T1Digi/src/classes.h,src/DataFormats/T1Digi/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1Digi_EX_LIB   := DataFormatsT1Digi
DataFormatsT1Digi_EX_USE   := $(foreach d,$(DataFormatsT1Digi_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1Digi_PACKAGE := self/src/DataFormats/T1Digi/src
ALL_PRODS += DataFormatsT1Digi
DataFormatsT1Digi_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1Digi,src/DataFormats/T1Digi/src,src_DataFormats_T1Digi_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1DigiSantiard)),)
ALL_COMMONRULES += src_DataFormats_T1DigiSantiard_src
src_DataFormats_T1DigiSantiard_src_parent := DataFormats/T1DigiSantiard
src_DataFormats_T1DigiSantiard_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiSantiard_src,src/DataFormats/T1DigiSantiard/src,LIBRARY))
DataFormatsT1DigiSantiard := self/DataFormats/T1DigiSantiard
DataFormats/T1DigiSantiard := DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_files := $(patsubst src/DataFormats/T1DigiSantiard/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiSantiard/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiSantiard_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiSantiard/BuildFile
DataFormatsT1DigiSantiard_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiSantiard_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiSantiardCapabilities,DataFormatsT1DigiSantiard,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiSantiard/src))
DataFormatsT1DigiSantiard_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiSantiard,0,src/DataFormats/T1DigiSantiard/src/classes.h,src/DataFormats/T1DigiSantiard/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiSantiard_EX_LIB   := DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_EX_USE   := $(foreach d,$(DataFormatsT1DigiSantiard_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiSantiard_PACKAGE := self/src/DataFormats/T1DigiSantiard/src
ALL_PRODS += DataFormatsT1DigiSantiard
DataFormatsT1DigiSantiard_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiSantiard,src/DataFormats/T1DigiSantiard/src,src_DataFormats_T1DigiSantiard_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1DigiVfat)),)
ALL_COMMONRULES += src_DataFormats_T1DigiVfat_src
src_DataFormats_T1DigiVfat_src_parent := DataFormats/T1DigiVfat
src_DataFormats_T1DigiVfat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiVfat_src,src/DataFormats/T1DigiVfat/src,LIBRARY))
DataFormatsT1DigiVfat := self/DataFormats/T1DigiVfat
DataFormats/T1DigiVfat := DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_files := $(patsubst src/DataFormats/T1DigiVfat/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiVfat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiVfat_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiVfat/BuildFile
DataFormatsT1DigiVfat_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiVfat_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiVfatCapabilities,DataFormatsT1DigiVfat,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiVfat/src))
DataFormatsT1DigiVfat_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiVfat,0,src/DataFormats/T1DigiVfat/src/classes.h,src/DataFormats/T1DigiVfat/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiVfat_EX_LIB   := DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_EX_USE   := $(foreach d,$(DataFormatsT1DigiVfat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiVfat_PACKAGE := self/src/DataFormats/T1DigiVfat/src
ALL_PRODS += DataFormatsT1DigiVfat
DataFormatsT1DigiVfat_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiVfat,src/DataFormats/T1DigiVfat/src,src_DataFormats_T1DigiVfat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1DigiWire)),)
ALL_COMMONRULES += src_DataFormats_T1DigiWire_src
src_DataFormats_T1DigiWire_src_parent := DataFormats/T1DigiWire
src_DataFormats_T1DigiWire_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1DigiWire_src,src/DataFormats/T1DigiWire/src,LIBRARY))
DataFormatsT1DigiWire := self/DataFormats/T1DigiWire
DataFormats/T1DigiWire := DataFormatsT1DigiWire
DataFormatsT1DigiWire_files := $(patsubst src/DataFormats/T1DigiWire/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1DigiWire/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1DigiWire_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1DigiWire/BuildFile
DataFormatsT1DigiWire_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1DigiWire_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1DigiWireCapabilities,DataFormatsT1DigiWire,$(SCRAMSTORENAME_LIB),src/DataFormats/T1DigiWire/src))
DataFormatsT1DigiWire_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1DigiWire,0,src/DataFormats/T1DigiWire/src/classes.h,src/DataFormats/T1DigiWire/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1DigiWire_EX_LIB   := DataFormatsT1DigiWire
DataFormatsT1DigiWire_EX_USE   := $(foreach d,$(DataFormatsT1DigiWire_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1DigiWire_PACKAGE := self/src/DataFormats/T1DigiWire/src
ALL_PRODS += DataFormatsT1DigiWire
DataFormatsT1DigiWire_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1DigiWire,src/DataFormats/T1DigiWire/src,src_DataFormats_T1DigiWire_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1RawData)),)
ALL_COMMONRULES += src_DataFormats_T1RawData_src
src_DataFormats_T1RawData_src_parent := DataFormats/T1RawData
src_DataFormats_T1RawData_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1RawData_src,src/DataFormats/T1RawData/src,LIBRARY))
DataFormatsT1RawData := self/DataFormats/T1RawData
DataFormats/T1RawData := DataFormatsT1RawData
DataFormatsT1RawData_files := $(patsubst src/DataFormats/T1RawData/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1RawData/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1RawData_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1RawData/BuildFile
DataFormatsT1RawData_LOC_USE := self  DataFormats/Common
DataFormatsT1RawData_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RawDataCapabilities,DataFormatsT1RawData,$(SCRAMSTORENAME_LIB),src/DataFormats/T1RawData/src))
DataFormatsT1RawData_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1RawData,0,src/DataFormats/T1RawData/src/classes.h,src/DataFormats/T1RawData/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1RawData_EX_LIB   := DataFormatsT1RawData
DataFormatsT1RawData_EX_USE   := $(foreach d,$(DataFormatsT1RawData_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1RawData_PACKAGE := self/src/DataFormats/T1RawData/src
ALL_PRODS += DataFormatsT1RawData
DataFormatsT1RawData_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1RawData,src/DataFormats/T1RawData/src,src_DataFormats_T1RawData_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1RecHit)),)
ALL_COMMONRULES += src_DataFormats_T1RecHit_src
src_DataFormats_T1RecHit_src_parent := DataFormats/T1RecHit
src_DataFormats_T1RecHit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1RecHit_src,src/DataFormats/T1RecHit/src,LIBRARY))
DataFormatsT1RecHit := self/DataFormats/T1RecHit
DataFormats/T1RecHit := DataFormatsT1RecHit
DataFormatsT1RecHit_files := $(patsubst src/DataFormats/T1RecHit/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1RecHit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1RecHit/BuildFile
DataFormatsT1RecHit_LOC_USE := self  DataFormats/Common DataFormats/T1DetId DataFormats/TrackingRecHit rootrflx
DataFormatsT1RecHit_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RecHitCapabilities,DataFormatsT1RecHit,$(SCRAMSTORENAME_LIB),src/DataFormats/T1RecHit/src))
DataFormatsT1RecHit_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1RecHit,0,src/DataFormats/T1RecHit/src/classes.h,src/DataFormats/T1RecHit/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1RecHit_EX_LIB   := DataFormatsT1RecHit
DataFormatsT1RecHit_EX_USE   := $(foreach d,$(DataFormatsT1RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1RecHit_PACKAGE := self/src/DataFormats/T1RecHit/src
ALL_PRODS += DataFormatsT1RecHit
DataFormatsT1RecHit_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1RecHit,src/DataFormats/T1RecHit/src,src_DataFormats_T1RecHit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1Road)),)
ALL_COMMONRULES += src_DataFormats_T1Road_src
src_DataFormats_T1Road_src_parent := DataFormats/T1Road
src_DataFormats_T1Road_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1Road_src,src/DataFormats/T1Road/src,LIBRARY))
DataFormatsT1Road := self/DataFormats/T1Road
DataFormats/T1Road := DataFormatsT1Road
DataFormatsT1Road_files := $(patsubst src/DataFormats/T1Road/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1Road/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1Road_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1Road/BuildFile
DataFormatsT1Road_LOC_USE := self  DataFormats/Common DataFormats/TrackingRecHit DataFormats/T1DetId rootrflx
DataFormatsT1Road_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1RoadCapabilities,DataFormatsT1Road,$(SCRAMSTORENAME_LIB),src/DataFormats/T1Road/src))
DataFormatsT1Road_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1Road,0,src/DataFormats/T1Road/src/classes.h,src/DataFormats/T1Road/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1Road_EX_LIB   := DataFormatsT1Road
DataFormatsT1Road_EX_USE   := $(foreach d,$(DataFormatsT1Road_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1Road_PACKAGE := self/src/DataFormats/T1Road/src
ALL_PRODS += DataFormatsT1Road
DataFormatsT1Road_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1Road,src/DataFormats/T1Road/src,src_DataFormats_T1Road_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1T2Track)),)
ALL_COMMONRULES += src_DataFormats_T1T2Track_src
src_DataFormats_T1T2Track_src_parent := DataFormats/T1T2Track
src_DataFormats_T1T2Track_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1T2Track_src,src/DataFormats/T1T2Track/src,LIBRARY))
DataFormatsT1T2Track := self/DataFormats/T1T2Track
DataFormats/T1T2Track := DataFormatsT1T2Track
DataFormatsT1T2Track_files := $(patsubst src/DataFormats/T1T2Track/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1T2Track/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1T2Track_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1T2Track/BuildFile
DataFormatsT1T2Track_LOC_USE := self  FWCore/Framework DataFormats/Common boost FWCore/Utilities DataFormats/TrackingRecHit DataFormats/T1Road DataFormats/T2Hit DataFormats/T2Road rootrflx root clhep
DataFormatsT1T2Track_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1T2TrackCapabilities,DataFormatsT1T2Track,$(SCRAMSTORENAME_LIB),src/DataFormats/T1T2Track/src))
DataFormatsT1T2Track_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1T2Track,0,src/DataFormats/T1T2Track/src/classes.h,src/DataFormats/T1T2Track/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1T2Track_EX_LIB   := DataFormatsT1T2Track
DataFormatsT1T2Track_EX_USE   := $(foreach d,$(DataFormatsT1T2Track_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1T2Track_PACKAGE := self/src/DataFormats/T1T2Track/src
ALL_PRODS += DataFormatsT1T2Track
DataFormatsT1T2Track_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1T2Track,src/DataFormats/T1T2Track/src,src_DataFormats_T1T2Track_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T1TestElements)),)
ALL_COMMONRULES += src_DataFormats_T1TestElements_src
src_DataFormats_T1TestElements_src_parent := DataFormats/T1TestElements
src_DataFormats_T1TestElements_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T1TestElements_src,src/DataFormats/T1TestElements/src,LIBRARY))
DataFormatsT1TestElements := self/DataFormats/T1TestElements
DataFormats/T1TestElements := DataFormatsT1TestElements
DataFormatsT1TestElements_files := $(patsubst src/DataFormats/T1TestElements/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T1TestElements/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT1TestElements_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T1TestElements/BuildFile
DataFormatsT1TestElements_LOC_USE := self  DataFormats/Common DataFormats/T1DetId
DataFormatsT1TestElements_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT1TestElementsCapabilities,DataFormatsT1TestElements,$(SCRAMSTORENAME_LIB),src/DataFormats/T1TestElements/src))
DataFormatsT1TestElements_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT1TestElements,0,src/DataFormats/T1TestElements/src/classes.h,src/DataFormats/T1TestElements/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT1TestElements_EX_LIB   := DataFormatsT1TestElements
DataFormatsT1TestElements_EX_USE   := $(foreach d,$(DataFormatsT1TestElements_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT1TestElements_PACKAGE := self/src/DataFormats/T1TestElements/src
ALL_PRODS += DataFormatsT1TestElements
DataFormatsT1TestElements_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT1TestElements,src/DataFormats/T1TestElements/src,src_DataFormats_T1TestElements_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2Cluster)),)
ALL_COMMONRULES += src_DataFormats_T2Cluster_src
src_DataFormats_T2Cluster_src_parent := DataFormats/T2Cluster
src_DataFormats_T2Cluster_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Cluster_src,src/DataFormats/T2Cluster/src,LIBRARY))
DataFormatsT2Cluster := self/DataFormats/T2Cluster
DataFormats/T2Cluster := DataFormatsT2Cluster
DataFormatsT2Cluster_files := $(patsubst src/DataFormats/T2Cluster/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Cluster/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Cluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Cluster/BuildFile
DataFormatsT2Cluster_LOC_USE := self  FWCore/Framework FWCore/MessageLogger DataFormats/Common DataFormats/T2DetId DataFormats/T2Digi boost rootrflx
DataFormatsT2Cluster_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2ClusterCapabilities,DataFormatsT2Cluster,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Cluster/src))
DataFormatsT2Cluster_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Cluster,0,src/DataFormats/T2Cluster/src/classes.h,src/DataFormats/T2Cluster/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Cluster_EX_LIB   := DataFormatsT2Cluster
DataFormatsT2Cluster_EX_USE   := $(foreach d,$(DataFormatsT2Cluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Cluster_PACKAGE := self/src/DataFormats/T2Cluster/src
ALL_PRODS += DataFormatsT2Cluster
DataFormatsT2Cluster_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Cluster,src/DataFormats/T2Cluster/src,src_DataFormats_T2Cluster_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2DetId)),)
ALL_COMMONRULES += src_DataFormats_T2DetId_src
src_DataFormats_T2DetId_src_parent := DataFormats/T2DetId
src_DataFormats_T2DetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2DetId_src,src/DataFormats/T2DetId/src,LIBRARY))
DataFormatsT2DetId := self/DataFormats/T2DetId
DataFormats/T2DetId := DataFormatsT2DetId
DataFormatsT2DetId_files := $(patsubst src/DataFormats/T2DetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2DetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2DetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2DetId/BuildFile
DataFormatsT2DetId_LOC_USE := self  DataFormats/DetId FWCore/Utilities boost rootrflx
DataFormatsT2DetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DetIdCapabilities,DataFormatsT2DetId,$(SCRAMSTORENAME_LIB),src/DataFormats/T2DetId/src))
DataFormatsT2DetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2DetId,0,src/DataFormats/T2DetId/src/classes.h,src/DataFormats/T2DetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2DetId_EX_LIB   := DataFormatsT2DetId
DataFormatsT2DetId_EX_USE   := $(foreach d,$(DataFormatsT2DetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2DetId_PACKAGE := self/src/DataFormats/T2DetId/src
ALL_PRODS += DataFormatsT2DetId
DataFormatsT2DetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2DetId,src/DataFormats/T2DetId/src,src_DataFormats_T2DetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2Digi)),)
ALL_COMMONRULES += src_DataFormats_T2Digi_src
src_DataFormats_T2Digi_src_parent := DataFormats/T2Digi
src_DataFormats_T2Digi_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Digi_src,src/DataFormats/T2Digi/src,LIBRARY))
DataFormatsT2Digi := self/DataFormats/T2Digi
DataFormats/T2Digi := DataFormatsT2Digi
DataFormatsT2Digi_files := $(patsubst src/DataFormats/T2Digi/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Digi/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Digi_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Digi/BuildFile
DataFormatsT2Digi_LOC_USE := self  FWCore/Framework FWCore/MessageLogger DataFormats/Common DataFormats/T2DetId boost rootrflx
DataFormatsT2Digi_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DigiCapabilities,DataFormatsT2Digi,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Digi/src))
DataFormatsT2Digi_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Digi,0,src/DataFormats/T2Digi/src/classes.h,src/DataFormats/T2Digi/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Digi_EX_LIB   := DataFormatsT2Digi
DataFormatsT2Digi_EX_USE   := $(foreach d,$(DataFormatsT2Digi_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Digi_PACKAGE := self/src/DataFormats/T2Digi/src
ALL_PRODS += DataFormatsT2Digi
DataFormatsT2Digi_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Digi,src/DataFormats/T2Digi/src,src_DataFormats_T2Digi_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2DigiVfat)),)
ALL_COMMONRULES += src_DataFormats_T2DigiVfat_src
src_DataFormats_T2DigiVfat_src_parent := DataFormats/T2DigiVfat
src_DataFormats_T2DigiVfat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2DigiVfat_src,src/DataFormats/T2DigiVfat/src,LIBRARY))
DataFormatsT2DigiVfat := self/DataFormats/T2DigiVfat
DataFormats/T2DigiVfat := DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_files := $(patsubst src/DataFormats/T2DigiVfat/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2DigiVfat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2DigiVfat_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2DigiVfat/BuildFile
DataFormatsT2DigiVfat_LOC_USE := self  DataFormats/Common DataFormats/T2DetId
DataFormatsT2DigiVfat_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2DigiVfatCapabilities,DataFormatsT2DigiVfat,$(SCRAMSTORENAME_LIB),src/DataFormats/T2DigiVfat/src))
DataFormatsT2DigiVfat_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2DigiVfat,0,src/DataFormats/T2DigiVfat/src/classes.h,src/DataFormats/T2DigiVfat/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2DigiVfat_EX_LIB   := DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_EX_USE   := $(foreach d,$(DataFormatsT2DigiVfat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2DigiVfat_PACKAGE := self/src/DataFormats/T2DigiVfat/src
ALL_PRODS += DataFormatsT2DigiVfat
DataFormatsT2DigiVfat_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2DigiVfat,src/DataFormats/T2DigiVfat/src,src_DataFormats_T2DigiVfat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2Hit)),)
ALL_COMMONRULES += src_DataFormats_T2Hit_src
src_DataFormats_T2Hit_src_parent := DataFormats/T2Hit
src_DataFormats_T2Hit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Hit_src,src/DataFormats/T2Hit/src,LIBRARY))
DataFormatsT2Hit := self/DataFormats/T2Hit
DataFormats/T2Hit := DataFormatsT2Hit
DataFormatsT2Hit_files := $(patsubst src/DataFormats/T2Hit/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Hit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Hit_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Hit/BuildFile
DataFormatsT2Hit_LOC_USE := self  FWCore/Framework FWCore/MessageLogger DataFormats/Common DataFormats/T2DetId DataFormats/T2Cluster boost rootrflx
DataFormatsT2Hit_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2HitCapabilities,DataFormatsT2Hit,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Hit/src))
DataFormatsT2Hit_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Hit,0,src/DataFormats/T2Hit/src/classes.h,src/DataFormats/T2Hit/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Hit_EX_LIB   := DataFormatsT2Hit
DataFormatsT2Hit_EX_USE   := $(foreach d,$(DataFormatsT2Hit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Hit_PACKAGE := self/src/DataFormats/T2Hit/src
ALL_PRODS += DataFormatsT2Hit
DataFormatsT2Hit_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Hit,src/DataFormats/T2Hit/src,src_DataFormats_T2Hit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/T2Road)),)
ALL_COMMONRULES += src_DataFormats_T2Road_src
src_DataFormats_T2Road_src_parent := DataFormats/T2Road
src_DataFormats_T2Road_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_T2Road_src,src/DataFormats/T2Road/src,LIBRARY))
DataFormatsT2Road := self/DataFormats/T2Road
DataFormats/T2Road := DataFormatsT2Road
DataFormatsT2Road_files := $(patsubst src/DataFormats/T2Road/src/%,%,$(wildcard $(foreach dir,src/DataFormats/T2Road/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsT2Road_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/T2Road/BuildFile
DataFormatsT2Road_LOC_USE := self  DataFormats/Common FWCore/Framework FWCore/MessageLogger DataFormats/T2Hit DataFormats/T2Cluster boost rootrflx
DataFormatsT2Road_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsT2RoadCapabilities,DataFormatsT2Road,$(SCRAMSTORENAME_LIB),src/DataFormats/T2Road/src))
DataFormatsT2Road_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsT2Road,0,src/DataFormats/T2Road/src/classes.h,src/DataFormats/T2Road/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsT2Road_EX_LIB   := DataFormatsT2Road
DataFormatsT2Road_EX_USE   := $(foreach d,$(DataFormatsT2Road_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsT2Road_PACKAGE := self/src/DataFormats/T2Road/src
ALL_PRODS += DataFormatsT2Road
DataFormatsT2Road_INIT_FUNC        += $$(eval $$(call Library,DataFormatsT2Road,src/DataFormats/T2Road/src,src_DataFormats_T2Road_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/TotemL1Trigger)),)
ALL_COMMONRULES += src_DataFormats_TotemL1Trigger_src
src_DataFormats_TotemL1Trigger_src_parent := DataFormats/TotemL1Trigger
src_DataFormats_TotemL1Trigger_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemL1Trigger_src,src/DataFormats/TotemL1Trigger/src,LIBRARY))
DataFormatsTotemL1Trigger := self/DataFormats/TotemL1Trigger
DataFormats/TotemL1Trigger := DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_files := $(patsubst src/DataFormats/TotemL1Trigger/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemL1Trigger/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemL1Trigger_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemL1Trigger/BuildFile
DataFormatsTotemL1Trigger_LOC_USE := self  DataFormats/DetId DataFormats/T2DetId DataFormats/Common FWCore/Framework FWCore/PluginManager FWCore/Utilities FWCore/MessageLogger rootrflx
DataFormatsTotemL1Trigger_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemL1TriggerCapabilities,DataFormatsTotemL1Trigger,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemL1Trigger/src))
DataFormatsTotemL1Trigger_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemL1Trigger,0,src/DataFormats/TotemL1Trigger/src/classes.h,src/DataFormats/TotemL1Trigger/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemL1Trigger_EX_LIB   := DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_EX_USE   := $(foreach d,$(DataFormatsTotemL1Trigger_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemL1Trigger_PACKAGE := self/src/DataFormats/TotemL1Trigger/src
ALL_PRODS += DataFormatsTotemL1Trigger
DataFormatsTotemL1Trigger_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemL1Trigger,src/DataFormats/TotemL1Trigger/src,src_DataFormats_TotemL1Trigger_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/TotemRPDataTypes)),)
ALL_COMMONRULES += src_DataFormats_TotemRPDataTypes_src
src_DataFormats_TotemRPDataTypes_src_parent := DataFormats/TotemRPDataTypes
src_DataFormats_TotemRPDataTypes_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemRPDataTypes_src,src/DataFormats/TotemRPDataTypes/src,LIBRARY))
DataFormatsTotemRPDataTypes := self/DataFormats/TotemRPDataTypes
DataFormats/TotemRPDataTypes := DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_files := $(patsubst src/DataFormats/TotemRPDataTypes/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemRPDataTypes/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemRPDataTypes_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemRPDataTypes/BuildFile
DataFormatsTotemRPDataTypes_LOC_USE := self  FWCore/Framework boost clhep root rootrflx DataFormats/Common DataFormats/GeometryVector
DataFormatsTotemRPDataTypes_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemRPDataTypesCapabilities,DataFormatsTotemRPDataTypes,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemRPDataTypes/src))
DataFormatsTotemRPDataTypes_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemRPDataTypes,0,src/DataFormats/TotemRPDataTypes/src/classes.h,src/DataFormats/TotemRPDataTypes/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemRPDataTypes_EX_LIB   := DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_EX_USE   := $(foreach d,$(DataFormatsTotemRPDataTypes_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemRPDataTypes_PACKAGE := self/src/DataFormats/TotemRPDataTypes/src
ALL_PRODS += DataFormatsTotemRPDataTypes
DataFormatsTotemRPDataTypes_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemRPDataTypes,src/DataFormats/TotemRPDataTypes/src,src_DataFormats_TotemRPDataTypes_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(DataFormats/TotemRPDetId)),)
ALL_COMMONRULES += src_DataFormats_TotemRPDetId_src
src_DataFormats_TotemRPDetId_src_parent := DataFormats/TotemRPDetId
src_DataFormats_TotemRPDetId_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_DataFormats_TotemRPDetId_src,src/DataFormats/TotemRPDetId/src,LIBRARY))
DataFormatsTotemRPDetId := self/DataFormats/TotemRPDetId
DataFormats/TotemRPDetId := DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_files := $(patsubst src/DataFormats/TotemRPDetId/src/%,%,$(wildcard $(foreach dir,src/DataFormats/TotemRPDetId/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DataFormatsTotemRPDetId_BuildFile    := $(WORKINGDIR)/cache/bf/src/DataFormats/TotemRPDetId/BuildFile
DataFormatsTotemRPDetId_LOC_USE := self  DataFormats/DetId FWCore/Utilities rootrflx
DataFormatsTotemRPDetId_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DataFormatsTotemRPDetIdCapabilities,DataFormatsTotemRPDetId,$(SCRAMSTORENAME_LIB),src/DataFormats/TotemRPDetId/src))
DataFormatsTotemRPDetId_PRE_INIT_FUNC += $$(eval $$(call LCGDict,DataFormatsTotemRPDetId,0,src/DataFormats/TotemRPDetId/src/classes.h,src/DataFormats/TotemRPDetId/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
DataFormatsTotemRPDetId_EX_LIB   := DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_EX_USE   := $(foreach d,$(DataFormatsTotemRPDetId_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DataFormatsTotemRPDetId_PACKAGE := self/src/DataFormats/TotemRPDetId/src
ALL_PRODS += DataFormatsTotemRPDetId
DataFormatsTotemRPDetId_INIT_FUNC        += $$(eval $$(call Library,DataFormatsTotemRPDetId,src/DataFormats/TotemRPDetId/src,src_DataFormats_TotemRPDetId_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(Geometry/TotemGeometry)),)
ALL_COMMONRULES += src_Geometry_TotemGeometry_src
src_Geometry_TotemGeometry_src_parent := Geometry/TotemGeometry
src_Geometry_TotemGeometry_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemGeometry_src,src/Geometry/TotemGeometry/src,LIBRARY))
GeometryTotemGeometry := self/Geometry/TotemGeometry
Geometry/TotemGeometry := GeometryTotemGeometry
GeometryTotemGeometry_files := $(patsubst src/Geometry/TotemGeometry/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemGeometry/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemGeometry_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemGeometry/BuildFile
GeometryTotemGeometry_LOC_USE := self  DataFormats/DetId DataFormats/T1DetId DataFormats/T2DetId DataFormats/T2Cluster FWCore/Framework Geometry/Records clhep
GeometryTotemGeometry_EX_LIB   := GeometryTotemGeometry
GeometryTotemGeometry_EX_USE   := $(foreach d,$(GeometryTotemGeometry_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemGeometry_PACKAGE := self/src/Geometry/TotemGeometry/src
ALL_PRODS += GeometryTotemGeometry
GeometryTotemGeometry_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemGeometry,src/Geometry/TotemGeometry/src,src_Geometry_TotemGeometry_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(Geometry/TotemRPDetTopology)),)
ALL_COMMONRULES += src_Geometry_TotemRPDetTopology_src
src_Geometry_TotemRPDetTopology_src_parent := Geometry/TotemRPDetTopology
src_Geometry_TotemRPDetTopology_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRPDetTopology_src,src/Geometry/TotemRPDetTopology/src,LIBRARY))
GeometryTotemRPDetTopology := self/Geometry/TotemRPDetTopology
Geometry/TotemRPDetTopology := GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_files := $(patsubst src/Geometry/TotemRPDetTopology/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPDetTopology/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRPDetTopology_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPDetTopology/BuildFile
GeometryTotemRPDetTopology_LOC_USE := self  clhep FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet DataFormats/Common DataFormats/GeometryVector SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts boost hepmc rootrflx DataFormats/TotemRPDataTypes
GeometryTotemRPDetTopology_EX_LIB   := GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_EX_USE   := $(foreach d,$(GeometryTotemRPDetTopology_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRPDetTopology_PACKAGE := self/src/Geometry/TotemRPDetTopology/src
ALL_PRODS += GeometryTotemRPDetTopology
GeometryTotemRPDetTopology_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPDetTopology,src/Geometry/TotemRPDetTopology/src,src_Geometry_TotemRPDetTopology_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(Geometry/TotemRPGeometryBuilder)),)
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_src
src_Geometry_TotemRPGeometryBuilder_src_parent := Geometry/TotemRPGeometryBuilder
src_Geometry_TotemRPGeometryBuilder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_src,src/Geometry/TotemRPGeometryBuilder/src,LIBRARY))
GeometryTotemRPGeometryBuilder := self/Geometry/TotemRPGeometryBuilder
Geometry/TotemRPGeometryBuilder := GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPGeometryBuilder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRPGeometryBuilder_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPGeometryBuilder/BuildFile
GeometryTotemRPGeometryBuilder_LOC_USE := self  SimDataFormats/GeneratorProducts DetectorDescription/Core Geometry/TotemRecords DataFormats/DetId DataFormats/TotemRPDetId Geometry/TrackerNumberingBuilder clhep hepmc FWCore/Framework FWCore/MessageLogger TotemAlignment/RPDataFormats
GeometryTotemRPGeometryBuilder_EX_LIB   := GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_EX_USE   := $(foreach d,$(GeometryTotemRPGeometryBuilder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRPGeometryBuilder_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/src
ALL_PRODS += GeometryTotemRPGeometryBuilder
GeometryTotemRPGeometryBuilder_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/src,src_Geometry_TotemRPGeometryBuilder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(Geometry/TotemRecords)),)
ALL_COMMONRULES += src_Geometry_TotemRecords_src
src_Geometry_TotemRecords_src_parent := Geometry/TotemRecords
src_Geometry_TotemRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemRecords_src,src/Geometry/TotemRecords/src,LIBRARY))
GeometryTotemRecords := self/Geometry/TotemRecords
Geometry/TotemRecords := GeometryTotemRecords
GeometryTotemRecords_files := $(patsubst src/Geometry/TotemRecords/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRecords/BuildFile
GeometryTotemRecords_LOC_USE := self  FWCore/Utilities FWCore/Framework Geometry/Records TotemAlignment/RPRecords CondFormats/DataRecord clhep boost
GeometryTotemRecords_EX_LIB   := GeometryTotemRecords
GeometryTotemRecords_EX_USE   := $(foreach d,$(GeometryTotemRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemRecords_PACKAGE := self/src/Geometry/TotemRecords/src
ALL_PRODS += GeometryTotemRecords
GeometryTotemRecords_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRecords,src/Geometry/TotemRecords/src,src_Geometry_TotemRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(Geometry/TotemT2AlignmentDataFormats)),)
ALL_COMMONRULES += src_Geometry_TotemT2AlignmentDataFormats_src
src_Geometry_TotemT2AlignmentDataFormats_src_parent := Geometry/TotemT2AlignmentDataFormats
src_Geometry_TotemT2AlignmentDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Geometry_TotemT2AlignmentDataFormats_src,src/Geometry/TotemT2AlignmentDataFormats/src,LIBRARY))
GeometryTotemT2AlignmentDataFormats := self/Geometry/TotemT2AlignmentDataFormats
Geometry/TotemT2AlignmentDataFormats := GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_files := $(patsubst src/Geometry/TotemT2AlignmentDataFormats/src/%,%,$(wildcard $(foreach dir,src/Geometry/TotemT2AlignmentDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GeometryTotemT2AlignmentDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemT2AlignmentDataFormats/BuildFile
GeometryTotemT2AlignmentDataFormats_LOC_USE := self  FWCore/Framework rootrflx DetectorDescription/Core Geometry/TotemGeometry
GeometryTotemT2AlignmentDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeometryTotemT2AlignmentDataFormatsCapabilities,GeometryTotemT2AlignmentDataFormats,$(SCRAMSTORENAME_LIB),src/Geometry/TotemT2AlignmentDataFormats/src))
GeometryTotemT2AlignmentDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,GeometryTotemT2AlignmentDataFormats,0,src/Geometry/TotemT2AlignmentDataFormats/src/classes.h,src/Geometry/TotemT2AlignmentDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB), --fail_on_warnings,Capabilities))
GeometryTotemT2AlignmentDataFormats_EX_LIB   := GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_EX_USE   := $(foreach d,$(GeometryTotemT2AlignmentDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeometryTotemT2AlignmentDataFormats_PACKAGE := self/src/Geometry/TotemT2AlignmentDataFormats/src
ALL_PRODS += GeometryTotemT2AlignmentDataFormats
GeometryTotemT2AlignmentDataFormats_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemT2AlignmentDataFormats,src/Geometry/TotemT2AlignmentDataFormats/src,src_Geometry_TotemT2AlignmentDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(L1TriggerTotem/CoincidenceChip)),)
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_src
src_L1TriggerTotem_CoincidenceChip_src_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_src,src/L1TriggerTotem/CoincidenceChip/src,LIBRARY))
L1TriggerTotemCoincidenceChip := self/L1TriggerTotem/CoincidenceChip
L1TriggerTotem/CoincidenceChip := L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/src/%,%,$(wildcard $(foreach dir,src/L1TriggerTotem/CoincidenceChip/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
L1TriggerTotemCoincidenceChip_BuildFile    := $(WORKINGDIR)/cache/bf/src/L1TriggerTotem/CoincidenceChip/BuildFile
L1TriggerTotemCoincidenceChip_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet TotemRawDataLibrary/DataFormats DataFormats/TotemRPDetId rootgraphics rootcore root
L1TriggerTotemCoincidenceChip_PRE_INIT_FUNC += $$(eval $$(call RootDict,L1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/src, L1TriggerTotemCoincidenceChipLinkDef.h))
L1TriggerTotemCoincidenceChip_EX_LIB   := L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_EX_USE   := $(foreach d,$(L1TriggerTotemCoincidenceChip_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
L1TriggerTotemCoincidenceChip_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/src
ALL_PRODS += L1TriggerTotemCoincidenceChip
L1TriggerTotemCoincidenceChip_INIT_FUNC        += $$(eval $$(call Library,L1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/src,src_L1TriggerTotem_CoincidenceChip_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/CentralMCJetReconstruction)),)
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_src
src_RecoTotemRP_CentralMCJetReconstruction_src_parent := RecoTotemRP/CentralMCJetReconstruction
src_RecoTotemRP_CentralMCJetReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_src,src/RecoTotemRP/CentralMCJetReconstruction/src,LIBRARY))
RecoTotemRPCentralMCJetReconstruction := self/RecoTotemRP/CentralMCJetReconstruction
RecoTotemRP/CentralMCJetReconstruction := RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/CentralMCJetReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPCentralMCJetReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/CentralMCJetReconstruction/BuildFile
RecoTotemRPCentralMCJetReconstruction_LOC_USE := self  root rootminuit2 boost rootrflx FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts Geometry/TotemGeometry hepmc fastjet
RecoTotemRPCentralMCJetReconstruction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPCentralMCJetReconstructionCapabilities,RecoTotemRPCentralMCJetReconstruction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/CentralMCJetReconstruction/src))
RecoTotemRPCentralMCJetReconstruction_PRE_INIT_FUNC += $$(eval $$(call LCGDict,RecoTotemRPCentralMCJetReconstruction,0,src/RecoTotemRP/CentralMCJetReconstruction/src/classes.h,src/RecoTotemRP/CentralMCJetReconstruction/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
RecoTotemRPCentralMCJetReconstruction_EX_LIB   := RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_EX_USE   := $(foreach d,$(RecoTotemRPCentralMCJetReconstruction_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPCentralMCJetReconstruction_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/src
ALL_PRODS += RecoTotemRPCentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstruction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/src,src_RecoTotemRP_CentralMCJetReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPClusterSigmaService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_src
src_RecoTotemRP_RPClusterSigmaService_src_parent := RecoTotemRP/RPClusterSigmaService
src_RecoTotemRP_RPClusterSigmaService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_src,src/RecoTotemRP/RPClusterSigmaService/src,LIBRARY))
RecoTotemRPRPClusterSigmaService := self/RecoTotemRP/RPClusterSigmaService
RecoTotemRP/RPClusterSigmaService := RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterSigmaService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPClusterSigmaService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterSigmaService/BuildFile
RecoTotemRPRPClusterSigmaService_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core
RecoTotemRPRPClusterSigmaService_EX_LIB   := RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_EX_USE   := $(foreach d,$(RecoTotemRPRPClusterSigmaService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPClusterSigmaService_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/src
ALL_PRODS += RecoTotemRPRPClusterSigmaService
RecoTotemRPRPClusterSigmaService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/src,src_RecoTotemRP_RPClusterSigmaService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPDetectorMaskingService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPDetectorMaskingService_src
src_RecoTotemRP_RPDetectorMaskingService_src_parent := RecoTotemRP/RPDetectorMaskingService
src_RecoTotemRP_RPDetectorMaskingService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDetectorMaskingService_src,src/RecoTotemRP/RPDetectorMaskingService/src,LIBRARY))
RecoTotemRPRPDetectorMaskingService := self/RecoTotemRP/RPDetectorMaskingService
RecoTotemRP/RPDetectorMaskingService := RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_files := $(patsubst src/RecoTotemRP/RPDetectorMaskingService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDetectorMaskingService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPDetectorMaskingService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPDetectorMaskingService/BuildFile
RecoTotemRPRPDetectorMaskingService_LOC_USE := self  clhep FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common Geometry/TotemRPDetTopology boost DataFormats/TotemRPDataTypes root rootrflx
RecoTotemRPRPDetectorMaskingService_EX_LIB   := RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_EX_USE   := $(foreach d,$(RecoTotemRPRPDetectorMaskingService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPDetectorMaskingService_PACKAGE := self/src/RecoTotemRP/RPDetectorMaskingService/src
ALL_PRODS += RecoTotemRPRPDetectorMaskingService
RecoTotemRPRPDetectorMaskingService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPDetectorMaskingService,src/RecoTotemRP/RPDetectorMaskingService/src,src_RecoTotemRP_RPDetectorMaskingService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPInverseParameterization)),)
ALL_COMMONRULES += src_RecoTotemRP_RPInverseParameterization_src
src_RecoTotemRP_RPInverseParameterization_src_parent := RecoTotemRP/RPInverseParameterization
src_RecoTotemRP_RPInverseParameterization_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInverseParameterization_src,src/RecoTotemRP/RPInverseParameterization/src,LIBRARY))
RecoTotemRPRPInverseParameterization := self/RecoTotemRP/RPInverseParameterization
RecoTotemRP/RPInverseParameterization := RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_files := $(patsubst src/RecoTotemRP/RPInverseParameterization/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInverseParameterization/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPInverseParameterization_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPInverseParameterization/BuildFile
RecoTotemRPRPInverseParameterization_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord FWCore/Utilities rootminuit2
RecoTotemRPRPInverseParameterization_EX_LIB   := RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_EX_USE   := $(foreach d,$(RecoTotemRPRPInverseParameterization_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPInverseParameterization_PACKAGE := self/src/RecoTotemRP/RPInverseParameterization/src
ALL_PRODS += RecoTotemRPRPInverseParameterization
RecoTotemRPRPInverseParameterization_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPInverseParameterization,src/RecoTotemRP/RPInverseParameterization/src,src_RecoTotemRP_RPInverseParameterization_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPNonParallelTrackCandidateFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src_parent := RecoTotemRP/RPNonParallelTrackCandidateFinder
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src,LIBRARY))
RecoTotemRPRPNonParallelTrackCandidateFinder := self/RecoTotemRP/RPNonParallelTrackCandidateFinder
RecoTotemRP/RPNonParallelTrackCandidateFinder := RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPNonParallelTrackCandidateFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/BuildFile
RecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats Geometry/Records DataFormats/TotemRPDetId root rootgraphics
RecoTotemRPRPNonParallelTrackCandidateFinder_EX_LIB   := RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_EX_USE   := $(foreach d,$(RecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPNonParallelTrackCandidateFinder_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src
ALL_PRODS += RecoTotemRPRPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/src,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPRecoDataFormats)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRecoDataFormats_src
src_RecoTotemRP_RPRecoDataFormats_src_parent := RecoTotemRP/RPRecoDataFormats
src_RecoTotemRP_RPRecoDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoDataFormats_src,src/RecoTotemRP/RPRecoDataFormats/src,LIBRARY))
RecoTotemRPRPRecoDataFormats := self/RecoTotemRP/RPRecoDataFormats
RecoTotemRP/RPRecoDataFormats := RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_files := $(patsubst src/RecoTotemRP/RPRecoDataFormats/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRecoDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRecoDataFormats/BuildFile
RecoTotemRPRPRecoDataFormats_LOC_USE := self  FWCore/Framework boost DataFormats/Common DataFormats/TotemRPDataTypes rootrflx clhep SimDataFormats/GeneratorProducts TotemCondFormats/BeamOpticsParamsObjects
RecoTotemRPRPRecoDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPRecoDataFormatsCapabilities,RecoTotemRPRPRecoDataFormats,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPRecoDataFormats/src))
RecoTotemRPRPRecoDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,RecoTotemRPRPRecoDataFormats,0,src/RecoTotemRP/RPRecoDataFormats/src/classes.h,src/RecoTotemRP/RPRecoDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
RecoTotemRPRPRecoDataFormats_EX_LIB   := RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_EX_USE   := $(foreach d,$(RecoTotemRPRPRecoDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPRecoDataFormats_PACKAGE := self/src/RecoTotemRP/RPRecoDataFormats/src
ALL_PRODS += RecoTotemRPRPRecoDataFormats
RecoTotemRPRPRecoDataFormats_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRecoDataFormats,src/RecoTotemRP/RPRecoDataFormats/src,src_RecoTotemRP_RPRecoDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPRomanPotResolutionService)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRomanPotResolutionService_src
src_RecoTotemRP_RPRomanPotResolutionService_src_parent := RecoTotemRP/RPRomanPotResolutionService
src_RecoTotemRP_RPRomanPotResolutionService_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRomanPotResolutionService_src,src/RecoTotemRP/RPRomanPotResolutionService/src,LIBRARY))
RecoTotemRPRPRomanPotResolutionService := self/RecoTotemRP/RPRomanPotResolutionService
RecoTotemRP/RPRomanPotResolutionService := RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_files := $(patsubst src/RecoTotemRP/RPRomanPotResolutionService/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRomanPotResolutionService/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRomanPotResolutionService_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRomanPotResolutionService/BuildFile
RecoTotemRPRPRomanPotResolutionService_LOC_USE := self  FWCore/Framework FWCore/MessageLogger RecoTotemRP/RPRecoDataFormats FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core
RecoTotemRPRPRomanPotResolutionService_EX_LIB   := RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_EX_USE   := $(foreach d,$(RecoTotemRPRPRomanPotResolutionService_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPRomanPotResolutionService_PACKAGE := self/src/RecoTotemRP/RPRomanPotResolutionService/src
ALL_PRODS += RecoTotemRPRPRomanPotResolutionService
RecoTotemRPRPRomanPotResolutionService_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRomanPotResolutionService,src/RecoTotemRP/RPRomanPotResolutionService/src,src_RecoTotemRP_RPRomanPotResolutionService_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPServiceRecords)),)
ALL_COMMONRULES += src_RecoTotemRP_RPServiceRecords_src
src_RecoTotemRP_RPServiceRecords_src_parent := RecoTotemRP/RPServiceRecords
src_RecoTotemRP_RPServiceRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPServiceRecords_src,src/RecoTotemRP/RPServiceRecords/src,LIBRARY))
RecoTotemRPRPServiceRecords := self/RecoTotemRP/RPServiceRecords
RecoTotemRP/RPServiceRecords := RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_files := $(patsubst src/RecoTotemRP/RPServiceRecords/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPServiceRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPServiceRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPServiceRecords/BuildFile
RecoTotemRPRPServiceRecords_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes
RecoTotemRPRPServiceRecords_EX_LIB   := RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_EX_USE   := $(foreach d,$(RecoTotemRPRPServiceRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPServiceRecords_PACKAGE := self/src/RecoTotemRP/RPServiceRecords/src
ALL_PRODS += RecoTotemRPRPServiceRecords
RecoTotemRPRPServiceRecords_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPServiceRecords,src/RecoTotemRP/RPServiceRecords/src,src_RecoTotemRP_RPServiceRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPStationMultiTrackFinderFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_src
src_RecoTotemRP_RPStationMultiTrackFinderFitter_src_parent := RecoTotemRP/RPStationMultiTrackFinderFitter
src_RecoTotemRP_RPStationMultiTrackFinderFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_src,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src,LIBRARY))
RecoTotemRPRPStationMultiTrackFinderFitter := self/RecoTotemRP/RPStationMultiTrackFinderFitter
RecoTotemRP/RPStationMultiTrackFinderFitter := RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPStationMultiTrackFinderFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPStationMultiTrackFinderFitter/BuildFile
RecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords Geometry/TotemRPDetTopology root
RecoTotemRPRPStationMultiTrackFinderFitter_EX_LIB   := RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_EX_USE   := $(foreach d,$(RecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPStationMultiTrackFinderFitter_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/src
ALL_PRODS += RecoTotemRPRPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/src,src_RecoTotemRP_RPStationMultiTrackFinderFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemRP/RPTrackCandidateFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateFitter_src
src_RecoTotemRP_RPTrackCandidateFitter_src_parent := RecoTotemRP/RPTrackCandidateFitter
src_RecoTotemRP_RPTrackCandidateFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateFitter_src,src/RecoTotemRP/RPTrackCandidateFitter/src,LIBRARY))
RecoTotemRPRPTrackCandidateFitter := self/RecoTotemRP/RPTrackCandidateFitter
RecoTotemRP/RPTrackCandidateFitter := RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTrackCandidateFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTrackCandidateFitter/BuildFile
RecoTotemRPRPTrackCandidateFitter_LOC_USE := self  FWCore/Framework boost DataFormats/Common DataFormats/TotemRPDataTypes root clhep Geometry/TotemRPGeometryBuilder RecoTotemRP/RPDetectorMaskingService RecoTotemRP/RPRecoDataFormats Geometry/TotemRPDetTopology FWCore/ParameterSet
RecoTotemRPRPTrackCandidateFitter_EX_LIB   := RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_EX_USE   := $(foreach d,$(RecoTotemRPRPTrackCandidateFitter_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemRPRPTrackCandidateFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateFitter/src
ALL_PRODS += RecoTotemRPRPTrackCandidateFitter
RecoTotemRPRPTrackCandidateFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTrackCandidateFitter,src/RecoTotemRP/RPTrackCandidateFitter/src,src_RecoTotemRP_RPTrackCandidateFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemT1T2/PrimaryVertexProducer)),)
src_RecoTotemT1T2_PrimaryVertexProducer := self/RecoTotemT1T2/PrimaryVertexProducer
RecoTotemT1T2/PrimaryVertexProducer  := src_RecoTotemT1T2_PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/PrimaryVertexProducer/BuildFile
src_RecoTotemT1T2_PrimaryVertexProducer_LOC_USE := clhep boost VertexReco/RecoTools SimDataFormats/Track FWCore/Framework self CommonTools/Clustering1D root DataFormats/T1T2Track Geometry/TotemRecords DataFormats/T1RecHit DataFormats/Common RecoVertex/VertexPrimitives Geometry/TotemGeometry RecoVertex/VertexTools DataFormats/T1T2Road DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_PrimaryVertexProducer_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_PrimaryVertexProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer))
endif

ifeq ($(strip $(RecoTotemT1T2/T1MakeCluster)),)
src_RecoTotemT1T2_T1MakeCluster := self/RecoTotemT1T2/T1MakeCluster
RecoTotemT1T2/T1MakeCluster  := src_RecoTotemT1T2_T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1MakeCluster/BuildFile
src_RecoTotemT1T2_T1MakeCluster_LOC_USE := boost FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiVfat DataFormats/T1DigiWire root SimTotem/T1Digitizer TotemRawData/DataFormats TotemCondFormats/DAQInformation FWCore/MessageLogger Geometry/TotemRecords DataFormats/Common Geometry/TotemGeometry DataFormats/T1DigiSantiard FWCore/ParameterSet
src_RecoTotemT1T2_T1MakeCluster_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1MakeCluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster))
endif

ifeq ($(strip $(RecoTotemT1T2/T1RecHit)),)
src_RecoTotemT1T2_T1RecHit := self/RecoTotemT1T2/T1RecHit
RecoTotemT1T2/T1RecHit  := src_RecoTotemT1T2_T1RecHit
src_RecoTotemT1T2_T1RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RecHit/BuildFile
src_RecoTotemT1T2_T1RecHit_LOC_USE := boost FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiWire root Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_T1RecHit_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1RecHit
src_RecoTotemT1T2_T1RecHit_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1RecHit,src/RecoTotemT1T2/T1RecHit))
endif

ifeq ($(strip $(RecoTotemT1T2/T1RoadProducer)),)
src_RecoTotemT1T2_T1RoadProducer := self/RecoTotemT1T2/T1RoadProducer
RecoTotemT1T2/T1RoadProducer  := src_RecoTotemT1T2_T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RoadProducer/BuildFile
src_RecoTotemT1T2_T1RoadProducer_LOC_USE := boost SimDataFormats/Track FWCore/Framework self DataFormats/T1Cluster DataFormats/T1DigiWire root DataFormats/T1Road Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_RecoTotemT1T2_T1RoadProducer_EX_USE   := $(foreach d,$(src_RecoTotemT1T2_T1RoadProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoTotemT1T2_T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_INIT_FUNC += $$(eval $$(call EmptyPackage,src_RecoTotemT1T2_T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer))
endif

ifeq ($(strip $(RecoTotemT1T2/T2MakeCluster)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_src
src_RecoTotemT1T2_T2MakeCluster_src_parent := RecoTotemT1T2/T2MakeCluster
src_RecoTotemT1T2_T2MakeCluster_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_src,src/RecoTotemT1T2/T2MakeCluster/src,LIBRARY))
RecoTotemT1T2T2MakeCluster := self/RecoTotemT1T2/T2MakeCluster
RecoTotemT1T2/T2MakeCluster := RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2MakeCluster/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2MakeCluster_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2MakeCluster/BuildFile
RecoTotemT1T2T2MakeCluster_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId SimDataFormats/GeneratorProducts boost clhep gsl hepmc rootcore rootrflx root FWCore/PluginManager FWCore/ServiceRegistry FWCore/Utilities DataFormats/T2Cluster
RecoTotemT1T2T2MakeCluster_EX_LIB   := RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_EX_USE   := $(foreach d,$(RecoTotemT1T2T2MakeCluster_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/src
ALL_PRODS += RecoTotemT1T2T2MakeCluster
RecoTotemT1T2T2MakeCluster_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/src,src_RecoTotemT1T2_T2MakeCluster_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemT1T2/T2RecHit)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_src
src_RecoTotemT1T2_T2RecHit_src_parent := RecoTotemT1T2/T2RecHit
src_RecoTotemT1T2_T2RecHit_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_src,src/RecoTotemT1T2/T2RecHit/src,LIBRARY))
RecoTotemT1T2T2RecHit := self/RecoTotemT1T2/T2RecHit
RecoTotemT1T2/T2RecHit := RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_files := $(patsubst src/RecoTotemT1T2/T2RecHit/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RecHit/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2RecHit_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RecHit/BuildFile
RecoTotemT1T2T2RecHit_LOC_FLAGS_CXXFLAGS   := -O0 -g3 -fno-inline
RecoTotemT1T2T2RecHit_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit Geometry/TotemT2AlignmentDataFormats
RecoTotemT1T2T2RecHit_EX_LIB   := RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_EX_USE   := $(foreach d,$(RecoTotemT1T2T2RecHit_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2RecHit_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/src
ALL_PRODS += RecoTotemT1T2T2RecHit
RecoTotemT1T2T2RecHit_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/src,src_RecoTotemT1T2_T2RecHit_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemT1T2/T2RoadPadFinder)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_src
src_RecoTotemT1T2_T2RoadPadFinder_src_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_src,src/RecoTotemT1T2/T2RoadPadFinder/src,LIBRARY))
RecoTotemT1T2T2RoadPadFinder := self/RecoTotemT1T2/T2RoadPadFinder
RecoTotemT1T2/T2RoadPadFinder := RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RoadPadFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2RoadPadFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RoadPadFinder/BuildFile
RecoTotemT1T2T2RoadPadFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Cluster DataFormats/T2Road DataFormats/T1T2Track
RecoTotemT1T2T2RoadPadFinder_EX_LIB   := RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_EX_USE   := $(foreach d,$(RecoTotemT1T2T2RoadPadFinder_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2RoadPadFinder_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/src
ALL_PRODS += RecoTotemT1T2T2RoadPadFinder
RecoTotemT1T2T2RoadPadFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/src,src_RecoTotemT1T2_T2RoadPadFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoTotemT1T2/T2TrackProducer3)),)
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_src
src_RecoTotemT1T2_T2TrackProducer3_src_parent := RecoTotemT1T2/T2TrackProducer3
src_RecoTotemT1T2_T2TrackProducer3_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_src,src/RecoTotemT1T2/T2TrackProducer3/src,LIBRARY))
RecoTotemT1T2T2TrackProducer3 := self/RecoTotemT1T2/T2TrackProducer3
RecoTotemT1T2/T2TrackProducer3 := RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/src/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2TrackProducer3/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemT1T2T2TrackProducer3_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2TrackProducer3/BuildFile
RecoTotemT1T2T2TrackProducer3_LOC_FLAGS_CXXFLAGS   := -O0 -g3 -fno-inline
RecoTotemT1T2T2TrackProducer3_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/DetId DataFormats/T2DetId DataFormats/T2Hit DataFormats/T2Road DataFormats/T1T2Track TotemAnalysis/T2Cuts clhep root boost
RecoTotemT1T2T2TrackProducer3_EX_LIB   := RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_EX_USE   := $(foreach d,$(RecoTotemT1T2T2TrackProducer3_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoTotemT1T2T2TrackProducer3_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/src
ALL_PRODS += RecoTotemT1T2T2TrackProducer3
RecoTotemT1T2T2TrackProducer3_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/src,src_RecoTotemT1T2_T2TrackProducer3_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(SimG4CMS/TotemRPProtTranspPar)),)
ALL_COMMONRULES += src_SimG4CMS_TotemRPProtTranspPar_src
src_SimG4CMS_TotemRPProtTranspPar_src_parent := SimG4CMS/TotemRPProtTranspPar
src_SimG4CMS_TotemRPProtTranspPar_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRPProtTranspPar_src,src/SimG4CMS/TotemRPProtTranspPar/src,LIBRARY))
SimG4CMSTotemRPProtTranspPar := self/SimG4CMS/TotemRPProtTranspPar
SimG4CMS/TotemRPProtTranspPar := SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/src/%,%,$(wildcard $(foreach dir,src/SimG4CMS/TotemRPProtTranspPar/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CMSTotemRPProtTranspPar_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/BuildFile
SimG4CMSTotemRPProtTranspPar_LOC_USE := self  xerces-c FWCore/MessageLogger root rootrflx
SimG4CMSTotemRPProtTranspPar_PRE_INIT_FUNC += $$(eval $$(call RootDict,SimG4CMSTotemRPProtTranspPar,src/SimG4CMS/TotemRPProtTranspPar/src, SimG4CMSTotemRPProtTranspParLinkDef.h))
SimG4CMSTotemRPProtTranspPar_EX_LIB   := SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_EX_USE   := $(foreach d,$(SimG4CMSTotemRPProtTranspPar_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CMSTotemRPProtTranspPar_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/src
ALL_PRODS += SimG4CMSTotemRPProtTranspPar
SimG4CMSTotemRPProtTranspPar_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSTotemRPProtTranspPar,src/SimG4CMS/TotemRPProtTranspPar/src,src_SimG4CMS_TotemRPProtTranspPar_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimG4Core/Application)),)
ALL_COMMONRULES += src_SimG4Core_Application_src
src_SimG4Core_Application_src_parent := SimG4Core/Application
src_SimG4Core_Application_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_Application_src,src/SimG4Core/Application/src,LIBRARY))
SimG4CoreApplication := self/SimG4Core/Application
SimG4Core/Application := SimG4CoreApplication
SimG4CoreApplication_files := $(patsubst src/SimG4Core/Application/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/Application/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreApplication_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Application/BuildFile
SimG4CoreApplication_LOC_USE := self  Geometry/TotemRecords SimDataFormats/CaloHit SimDataFormats/TrackingHit DataFormats/Common DataFormats/Math SimDataFormats/GeneratorProducts SimDataFormats/Forward SimDataFormats/Track SimDataFormats/Vertex SimG4Core/Generators SimG4Core/Geometry SimG4Core/MagneticField SimG4Core/Notification SimG4Core/Physics SimG4Core/SensitiveDetector SimG4Core/Watcher SimGeneral/HepPDTRecord SimGeneral/GFlash FWCore/ParameterSet FWCore/PluginManager FWCore/Framework FWCore/Utilities MagneticField/Engine MagneticField/Records clhep xerces-c geant4core hepmc heppdt rootrflx
SimG4CoreApplication_EX_LIB   := SimG4CoreApplication
SimG4CoreApplication_EX_USE   := $(foreach d,$(SimG4CoreApplication_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CoreApplication_PACKAGE := self/src/SimG4Core/Application/src
ALL_PRODS += SimG4CoreApplication
SimG4CoreApplication_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreApplication,src/SimG4Core/Application/src,src_SimG4Core_Application_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimG4Core/Generators)),)
ALL_COMMONRULES += src_SimG4Core_Generators_src
src_SimG4Core_Generators_src_parent := SimG4Core/Generators
src_SimG4Core_Generators_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_Generators_src,src/SimG4Core/Generators/src,LIBRARY))
SimG4CoreGenerators := self/SimG4Core/Generators
SimG4Core/Generators := SimG4CoreGenerators
SimG4CoreGenerators_files := $(patsubst src/SimG4Core/Generators/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/Generators/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreGenerators_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Generators/BuildFile
SimG4CoreGenerators_LOC_USE := self  DataFormats/Math hepmc FWCore/ParameterSet FWCore/MessageLogger SimDataFormats/GeneratorProducts boost geant4core rootmath expat
SimG4CoreGenerators_EX_LIB   := SimG4CoreGenerators
SimG4CoreGenerators_EX_USE   := $(foreach d,$(SimG4CoreGenerators_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CoreGenerators_PACKAGE := self/src/SimG4Core/Generators/src
ALL_PRODS += SimG4CoreGenerators
SimG4CoreGenerators_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreGenerators,src/SimG4Core/Generators/src,src_SimG4Core_Generators_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimG4Core/Notification)),)
ALL_COMMONRULES += src_SimG4Core_Notification_src
src_SimG4Core_Notification_src_parent := SimG4Core/Notification
src_SimG4Core_Notification_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_Notification_src,src/SimG4Core/Notification/src,LIBRARY))
SimG4CoreNotification := self/SimG4Core/Notification
SimG4Core/Notification := SimG4CoreNotification
SimG4CoreNotification_files := $(patsubst src/SimG4Core/Notification/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/Notification/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreNotification_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Notification/BuildFile
SimG4CoreNotification_LOC_USE := self  geant4 DetectorDescription/Core FWCore/MessageLogger rootmath expat
SimG4CoreNotification_EX_LIB   := SimG4CoreNotification
SimG4CoreNotification_EX_USE   := $(foreach d,$(SimG4CoreNotification_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CoreNotification_PACKAGE := self/src/SimG4Core/Notification/src
ALL_PRODS += SimG4CoreNotification
SimG4CoreNotification_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreNotification,src/SimG4Core/Notification/src,src_SimG4Core_Notification_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimG4Core/TotemRPProtTransp)),)
ALL_COMMONRULES += src_SimG4Core_TotemRPProtTransp_src
src_SimG4Core_TotemRPProtTransp_src_parent := SimG4Core/TotemRPProtTransp
src_SimG4Core_TotemRPProtTransp_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_TotemRPProtTransp_src,src/SimG4Core/TotemRPProtTransp/src,LIBRARY))
SimG4CoreTotemRPProtTransp := self/SimG4Core/TotemRPProtTransp
SimG4Core/TotemRPProtTransp := SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_files := $(patsubst src/SimG4Core/TotemRPProtTransp/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/TotemRPProtTransp/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreTotemRPProtTransp_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/TotemRPProtTransp/BuildFile
SimG4CoreTotemRPProtTransp_LOC_USE := self  FWCore/ParameterSet SimG4CMS/TotemRPProtTranspPar geant4 SimG4Core/Geometry FWCore/ServiceRegistry FWCore/MessageLogger root TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects
SimG4CoreTotemRPProtTransp_EX_LIB   := SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_EX_USE   := $(foreach d,$(SimG4CoreTotemRPProtTransp_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimG4CoreTotemRPProtTransp_PACKAGE := self/src/SimG4Core/TotemRPProtTransp/src
ALL_PRODS += SimG4CoreTotemRPProtTransp
SimG4CoreTotemRPProtTransp_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreTotemRPProtTransp,src/SimG4Core/TotemRPProtTransp/src,src_SimG4Core_TotemRPProtTransp_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimTotem/RPTimingDetectorsDigiProducer)),)
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_src
src_SimTotem_RPTimingDetectorsDigiProducer_src_parent := SimTotem/RPTimingDetectorsDigiProducer
src_SimTotem_RPTimingDetectorsDigiProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_src,src/SimTotem/RPTimingDetectorsDigiProducer/src,LIBRARY))
SimTotemRPTimingDetectorsDigiProducer := self/SimTotem/RPTimingDetectorsDigiProducer
SimTotem/RPTimingDetectorsDigiProducer := SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPTimingDetectorsDigiProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPTimingDetectorsDigiProducer/BuildFile
SimTotemRPTimingDetectorsDigiProducer_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId
SimTotemRPTimingDetectorsDigiProducer_EX_LIB   := SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_EX_USE   := $(foreach d,$(SimTotemRPTimingDetectorsDigiProducer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemRPTimingDetectorsDigiProducer_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/src
ALL_PRODS += SimTotemRPTimingDetectorsDigiProducer
SimTotemRPTimingDetectorsDigiProducer_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/src,src_SimTotem_RPTimingDetectorsDigiProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimTotem/T1Digitizer)),)
ALL_COMMONRULES += src_SimTotem_T1Digitizer_src
src_SimTotem_T1Digitizer_src_parent := SimTotem/T1Digitizer
src_SimTotem_T1Digitizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_src,src/SimTotem/T1Digitizer/src,LIBRARY))
SimTotemT1Digitizer := self/SimTotem/T1Digitizer
SimTotem/T1Digitizer := SimTotemT1Digitizer
SimTotemT1Digitizer_files := $(patsubst src/SimTotem/T1Digitizer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/T1Digitizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemT1Digitizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T1Digitizer/BuildFile
SimTotemT1Digitizer_LOC_USE := self  DataFormats/Common DataFormats/Provenance FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimGeneral/HepPDTRecord Utilities/Timing Utilities/General FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/T1Digi DataFormats/DetId DataFormats/T1DetId DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1TestElements boost root rootrflx clhep hepmc SimDataFormats/GeneratorProducts TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemT1Digitizer_EX_LIB   := SimTotemT1Digitizer
SimTotemT1Digitizer_EX_USE   := $(foreach d,$(SimTotemT1Digitizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemT1Digitizer_PACKAGE := self/src/SimTotem/T1Digitizer/src
ALL_PRODS += SimTotemT1Digitizer
SimTotemT1Digitizer_INIT_FUNC        += $$(eval $$(call Library,SimTotemT1Digitizer,src/SimTotem/T1Digitizer/src,src_SimTotem_T1Digitizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(SimTotem/T2Digitizer)),)
ALL_COMMONRULES += src_SimTotem_T2Digitizer_src
src_SimTotem_T2Digitizer_src_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_src,src/SimTotem/T2Digitizer/src,LIBRARY))
SimTotemT2Digitizer := self/SimTotem/T2Digitizer
SimTotem/T2Digitizer := SimTotemT2Digitizer
SimTotemT2Digitizer_files := $(patsubst src/SimTotem/T2Digitizer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/T2Digitizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemT2Digitizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T2Digitizer/BuildFile
SimTotemT2Digitizer_LOC_USE := self  FWCore/Framework FWCore/ParameterSet Utilities/Timing Utilities/General FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId DataFormats/T2DigiVfat SimDataFormats/TrackingHit Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimTracker/Common Mixing/Base Geometry/TotemT2AlignmentDataFormats geant4 root boost clhep gsl hepmc SimDataFormats/GeneratorProducts TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemT2Digitizer_EX_LIB   := SimTotemT2Digitizer
SimTotemT2Digitizer_EX_USE   := $(foreach d,$(SimTotemT2Digitizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
SimTotemT2Digitizer_PACKAGE := self/src/SimTotem/T2Digitizer/src
ALL_PRODS += SimTotemT2Digitizer
SimTotemT2Digitizer_INIT_FUNC        += $$(eval $$(call Library,SimTotemT2Digitizer,src/SimTotem/T2Digitizer/src,src_SimTotem_T2Digitizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAlignment/RPDataFormats)),)
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_src
src_TotemAlignment_RPDataFormats_src_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_src,src/TotemAlignment/RPDataFormats/src,LIBRARY))
TotemAlignmentRPDataFormats := self/TotemAlignment/RPDataFormats
TotemAlignment/RPDataFormats := TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_files := $(patsubst src/TotemAlignment/RPDataFormats/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPDataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/BuildFile
TotemAlignmentRPDataFormats_LOC_USE := self  FWCore/Framework DataFormats/Common DataFormats/Provenance rootrflx DetectorDescription/Core xerces-c root
TotemAlignmentRPDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPDataFormatsCapabilities,TotemAlignmentRPDataFormats,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPDataFormats/src))
TotemAlignmentRPDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAlignmentRPDataFormats,0,src/TotemAlignment/RPDataFormats/src/classes.h,src/TotemAlignment/RPDataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB), --fail_on_warnings,Capabilities))
TotemAlignmentRPDataFormats_EX_LIB   := TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_EX_USE   := $(foreach d,$(TotemAlignmentRPDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPDataFormats_PACKAGE := self/src/TotemAlignment/RPDataFormats/src
ALL_PRODS += TotemAlignmentRPDataFormats
TotemAlignmentRPDataFormats_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/src,src_TotemAlignment_RPDataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAlignment/RPProfiles)),)
src_TotemAlignment_RPProfiles := self/TotemAlignment/RPProfiles
TotemAlignment/RPProfiles  := src_TotemAlignment_RPProfiles
src_TotemAlignment_RPProfiles_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPProfiles/BuildFile
src_TotemAlignment_RPProfiles_LOC_USE := self
src_TotemAlignment_RPProfiles_EX_USE   := $(foreach d,$(src_TotemAlignment_RPProfiles_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_TotemAlignment_RPProfiles
src_TotemAlignment_RPProfiles_INIT_FUNC += $$(eval $$(call EmptyPackage,src_TotemAlignment_RPProfiles,src/TotemAlignment/RPProfiles))
endif

ifeq ($(strip $(TotemAlignment/RPRates)),)
ALL_COMMONRULES += src_TotemAlignment_RPRates_src
src_TotemAlignment_RPRates_src_parent := TotemAlignment/RPRates
src_TotemAlignment_RPRates_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_src,src/TotemAlignment/RPRates/src,LIBRARY))
TotemAlignmentRPRates := self/TotemAlignment/RPRates
TotemAlignment/RPRates := TotemAlignmentRPRates
TotemAlignmentRPRates_files := $(patsubst src/TotemAlignment/RPRates/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRates/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPRates_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRates/BuildFile
TotemAlignmentRPRates_LOC_USE := self  root Geometry/TotemRPGeometryBuilder Geometry/TotemRPDetTopology
TotemAlignmentRPRates_EX_LIB   := TotemAlignmentRPRates
TotemAlignmentRPRates_EX_USE   := $(foreach d,$(TotemAlignmentRPRates_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPRates_PACKAGE := self/src/TotemAlignment/RPRates/src
ALL_PRODS += TotemAlignmentRPRates
TotemAlignmentRPRates_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRates,src/TotemAlignment/RPRates/src,src_TotemAlignment_RPRates_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAlignment/RPRecords)),)
ALL_COMMONRULES += src_TotemAlignment_RPRecords_src
src_TotemAlignment_RPRecords_src_parent := TotemAlignment/RPRecords
src_TotemAlignment_RPRecords_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRecords_src,src/TotemAlignment/RPRecords/src,LIBRARY))
TotemAlignmentRPRecords := self/TotemAlignment/RPRecords
TotemAlignment/RPRecords := TotemAlignmentRPRecords
TotemAlignmentRPRecords_files := $(patsubst src/TotemAlignment/RPRecords/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRecords/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPRecords_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRecords/BuildFile
TotemAlignmentRPRecords_LOC_USE := self  FWCore/Framework
TotemAlignmentRPRecords_EX_LIB   := TotemAlignmentRPRecords
TotemAlignmentRPRecords_EX_USE   := $(foreach d,$(TotemAlignmentRPRecords_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPRecords_PACKAGE := self/src/TotemAlignment/RPRecords/src
ALL_PRODS += TotemAlignmentRPRecords
TotemAlignmentRPRecords_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRecords,src/TotemAlignment/RPRecords/src,src_TotemAlignment_RPRecords_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAlignment/RPTrackBased)),)
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_src
src_TotemAlignment_RPTrackBased_src_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_src,src/TotemAlignment/RPTrackBased/src,LIBRARY))
TotemAlignmentRPTrackBased := self/TotemAlignment/RPTrackBased
TotemAlignment/RPTrackBased := TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_files := $(patsubst src/TotemAlignment/RPTrackBased/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPTrackBased/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentRPTrackBased_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/BuildFile
TotemAlignmentRPTrackBased_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAlignmentRPTrackBased_LOC_USE := self  clhep root rootgraphics DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemAlignment/RPDataFormats RecoTotemRP/RPRecoDataFormats TotemAlignment/RPRecords
TotemAlignmentRPTrackBased_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPTrackBasedCapabilities,TotemAlignmentRPTrackBased,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPTrackBased/src))
TotemAlignmentRPTrackBased_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAlignmentRPTrackBased,0,src/TotemAlignment/RPTrackBased/src/classes.h,src/TotemAlignment/RPTrackBased/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemAlignmentRPTrackBased_EX_LIB   := TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_EX_USE   := $(foreach d,$(TotemAlignmentRPTrackBased_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentRPTrackBased_PACKAGE := self/src/TotemAlignment/RPTrackBased/src
ALL_PRODS += TotemAlignmentRPTrackBased
TotemAlignmentRPTrackBased_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/src,src_TotemAlignment_RPTrackBased_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAlignment/T1Alignment)),)
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_src
src_TotemAlignment_T1Alignment_src_parent := TotemAlignment/T1Alignment
src_TotemAlignment_T1Alignment_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_src,src/TotemAlignment/T1Alignment/src,LIBRARY))
TotemAlignmentT1Alignment := self/TotemAlignment/T1Alignment
TotemAlignment/T1Alignment := TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_files := $(patsubst src/TotemAlignment/T1Alignment/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T1Alignment/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentT1Alignment_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/T1Alignment/BuildFile
TotemAlignmentT1Alignment_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1T2Track DataFormats/T1RecHit DataFormats/T1Road DataFormats/Common Geometry/TotemGeometry CommonTools/Clustering1D root rootminuit2 clhep FWCore/ParameterSet boost
TotemAlignmentT1Alignment_EX_LIB   := TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_EX_USE   := $(foreach d,$(TotemAlignmentT1Alignment_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAlignmentT1Alignment_PACKAGE := self/src/TotemAlignment/T1Alignment/src
ALL_PRODS += TotemAlignmentT1Alignment
TotemAlignmentT1Alignment_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/src,src_TotemAlignment_T1Alignment_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/T2Cuts)),)
ALL_COMMONRULES += src_TotemAnalysis_T2Cuts_src
src_TotemAnalysis_T2Cuts_src_parent := TotemAnalysis/T2Cuts
src_TotemAnalysis_T2Cuts_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2Cuts_src,src/TotemAnalysis/T2Cuts/src,LIBRARY))
TotemAnalysisT2Cuts := self/TotemAnalysis/T2Cuts
TotemAnalysis/T2Cuts := TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_files := $(patsubst src/TotemAnalysis/T2Cuts/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2Cuts/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2Cuts_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2Cuts/BuildFile
TotemAnalysisT2Cuts_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1T2Track DataFormats/T1RecHit Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord xerces-c
TotemAnalysisT2Cuts_EX_LIB   := TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_EX_USE   := $(foreach d,$(TotemAnalysisT2Cuts_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisT2Cuts_PACKAGE := self/src/TotemAnalysis/T2Cuts/src
ALL_PRODS += TotemAnalysisT2Cuts
TotemAnalysisT2Cuts_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2Cuts,src/TotemAnalysis/T2Cuts/src,src_TotemAnalysis_T2Cuts_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/T2DEVNtuplizer)),)
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_src
src_TotemAnalysis_T2DEVNtuplizer_src_parent := TotemAnalysis/T2DEVNtuplizer
src_TotemAnalysis_T2DEVNtuplizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_src,src/TotemAnalysis/T2DEVNtuplizer/src,LIBRARY))
TotemAnalysisT2DEVNtuplizer := self/TotemAnalysis/T2DEVNtuplizer
TotemAnalysis/T2DEVNtuplizer := TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2DEVNtuplizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2DEVNtuplizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2DEVNtuplizer/BuildFile
TotemAnalysisT2DEVNtuplizer_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road fastjet
TotemAnalysisT2DEVNtuplizer_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/src, LinkDef.h))
TotemAnalysisT2DEVNtuplizer_EX_LIB   := TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_EX_USE   := $(foreach d,$(TotemAnalysisT2DEVNtuplizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisT2DEVNtuplizer_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/src
ALL_PRODS += TotemAnalysisT2DEVNtuplizer
TotemAnalysisT2DEVNtuplizer_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/src,src_TotemAnalysis_T2DEVNtuplizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/TestBeam)),)
ALL_COMMONRULES += src_TotemAnalysis_TestBeam_src
src_TotemAnalysis_TestBeam_src_parent := TotemAnalysis/TestBeam
src_TotemAnalysis_TestBeam_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TestBeam_src,src/TotemAnalysis/TestBeam/src,LIBRARY))
TotemAnalysisTestBeam := self/TotemAnalysis/TestBeam
TotemAnalysis/TestBeam := TotemAnalysisTestBeam
TotemAnalysisTestBeam_files := $(patsubst src/TotemAnalysis/TestBeam/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TestBeam/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTestBeam_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TestBeam/BuildFile
TotemAnalysisTestBeam_LOC_FLAGS_CXXFLAGS   := -g3 -O3 $(CUSTOM_FLAGS)
TotemAnalysisTestBeam_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAnalysisTestBeam_EX_LIB   := TotemAnalysisTestBeam
TotemAnalysisTestBeam_EX_USE   := $(foreach d,$(TotemAnalysisTestBeam_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTestBeam_PACKAGE := self/src/TotemAnalysis/TestBeam/src
ALL_PRODS += TotemAnalysisTestBeam
TotemAnalysisTestBeam_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTestBeam,src/TotemAnalysis/TestBeam/src,src_TotemAnalysis_TestBeam_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/TotemNtuplizer)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_src
src_TotemAnalysis_TotemNtuplizer_src_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_src,src/TotemAnalysis/TotemNtuplizer/src,LIBRARY))
TotemAnalysisTotemNtuplizer := self/TotemAnalysis/TotemNtuplizer
TotemAnalysis/TotemNtuplizer := TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemNtuplizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemNtuplizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemNtuplizer/BuildFile
TotemAnalysisTotemNtuplizer_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road TotemAnalysis/TotemAnalysisEvent fastjet
TotemAnalysisTotemNtuplizer_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/src, LinkDef.h))
TotemAnalysisTotemNtuplizer_EX_LIB   := TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_EX_USE   := $(foreach d,$(TotemAnalysisTotemNtuplizer_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemNtuplizer_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/src
ALL_PRODS += TotemAnalysisTotemNtuplizer
TotemAnalysisTotemNtuplizer_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/src,src_TotemAnalysis_TotemNtuplizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemCondFormats/BeamOpticsParamsObjects)),)
ALL_COMMONRULES += src_TotemCondFormats_BeamOpticsParamsObjects_src
src_TotemCondFormats_BeamOpticsParamsObjects_src_parent := TotemCondFormats/BeamOpticsParamsObjects
src_TotemCondFormats_BeamOpticsParamsObjects_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_BeamOpticsParamsObjects_src,src/TotemCondFormats/BeamOpticsParamsObjects/src,LIBRARY))
TotemCondFormatsBeamOpticsParamsObjects := self/TotemCondFormats/BeamOpticsParamsObjects
TotemCondFormats/BeamOpticsParamsObjects := TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_files := $(patsubst src/TotemCondFormats/BeamOpticsParamsObjects/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/BeamOpticsParamsObjects/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsBeamOpticsParamsObjects_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/BeamOpticsParamsObjects/BuildFile
TotemCondFormatsBeamOpticsParamsObjects_LOC_USE := self  FWCore/Framework FWCore/ParameterSet hepmc SimDataFormats/GeneratorProducts root
TotemCondFormatsBeamOpticsParamsObjects_EX_LIB   := TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_EX_USE   := $(foreach d,$(TotemCondFormatsBeamOpticsParamsObjects_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsBeamOpticsParamsObjects_PACKAGE := self/src/TotemCondFormats/BeamOpticsParamsObjects/src
ALL_PRODS += TotemCondFormatsBeamOpticsParamsObjects
TotemCondFormatsBeamOpticsParamsObjects_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsBeamOpticsParamsObjects,src/TotemCondFormats/BeamOpticsParamsObjects/src,src_TotemCondFormats_BeamOpticsParamsObjects_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemCondFormats/DAQInformation)),)
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_src
src_TotemCondFormats_DAQInformation_src_parent := TotemCondFormats/DAQInformation
src_TotemCondFormats_DAQInformation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_src,src/TotemCondFormats/DAQInformation/src,LIBRARY))
TotemCondFormatsDAQInformation := self/TotemCondFormats/DAQInformation
TotemCondFormats/DAQInformation := TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_files := $(patsubst src/TotemCondFormats/DAQInformation/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DAQInformation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsDAQInformation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DAQInformation/BuildFile
TotemCondFormatsDAQInformation_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/DataFormats
TotemCondFormatsDAQInformation_EX_LIB   := TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_EX_USE   := $(foreach d,$(TotemCondFormatsDAQInformation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsDAQInformation_PACKAGE := self/src/TotemCondFormats/DAQInformation/src
ALL_PRODS += TotemCondFormatsDAQInformation
TotemCondFormatsDAQInformation_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/src,src_TotemCondFormats_DAQInformation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemCondFormats/DataRecord)),)
ALL_COMMONRULES += src_TotemCondFormats_DataRecord_src
src_TotemCondFormats_DataRecord_src_parent := TotemCondFormats/DataRecord
src_TotemCondFormats_DataRecord_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_DataRecord_src,src/TotemCondFormats/DataRecord/src,LIBRARY))
TotemCondFormatsDataRecord := self/TotemCondFormats/DataRecord
TotemCondFormats/DataRecord := TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_files := $(patsubst src/TotemCondFormats/DataRecord/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DataRecord/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsDataRecord_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DataRecord/BuildFile
TotemCondFormatsDataRecord_LOC_USE := self  FWCore/Framework boost Geometry/TotemRecords
TotemCondFormatsDataRecord_EX_LIB   := TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_EX_USE   := $(foreach d,$(TotemCondFormatsDataRecord_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsDataRecord_PACKAGE := self/src/TotemCondFormats/DataRecord/src
ALL_PRODS += TotemCondFormatsDataRecord
TotemCondFormatsDataRecord_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDataRecord,src/TotemCondFormats/DataRecord/src,src_TotemCondFormats_DataRecord_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemCondFormats/ProtonTransportFunctions)),)
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_src
src_TotemCondFormats_ProtonTransportFunctions_src_parent := TotemCondFormats/ProtonTransportFunctions
src_TotemCondFormats_ProtonTransportFunctions_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_src,src/TotemCondFormats/ProtonTransportFunctions/src,LIBRARY))
TotemCondFormatsProtonTransportFunctions := self/TotemCondFormats/ProtonTransportFunctions
TotemCondFormats/ProtonTransportFunctions := TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/src/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/ProtonTransportFunctions/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemCondFormatsProtonTransportFunctions_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/ProtonTransportFunctions/BuildFile
TotemCondFormatsProtonTransportFunctions_LOC_USE := self  FWCore/Framework root TotemCondFormats/BeamOpticsParamsObjects SimG4CMS/TotemRPProtTranspPar
TotemCondFormatsProtonTransportFunctions_EX_LIB   := TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_EX_USE   := $(foreach d,$(TotemCondFormatsProtonTransportFunctions_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemCondFormatsProtonTransportFunctions_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/src
ALL_PRODS += TotemCondFormatsProtonTransportFunctions
TotemCondFormatsProtonTransportFunctions_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/src,src_TotemCondFormats_ProtonTransportFunctions_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(TotemDQMLite/GUI)),)
ALL_COMMONRULES += src_TotemDQMLite_GUI_src
src_TotemDQMLite_GUI_src_parent := TotemDQMLite/GUI
src_TotemDQMLite_GUI_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_GUI_src,src/TotemDQMLite/GUI/src,LIBRARY))
TotemDQMLiteGUI := self/TotemDQMLite/GUI
TotemDQMLite/GUI := TotemDQMLiteGUI
TotemDQMLiteGUI_files := $(patsubst src/TotemDQMLite/GUI/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/GUI/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteGUI_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/GUI/BuildFile
TotemDQMLiteGUI_LOC_USE := self  FWCore/Framework FWCore/FWLite FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/TotemRPDetId DataFormats/FWLite TotemRawData/DataFormats TotemDQMLite/Core TotemDQMLite/Modules qt root rootgraphics rootinteractive
TotemDQMLiteGUI_PRE_INIT_FUNC += $$(eval $$(call AddMOC,TotemDQMLiteGUI, MainWindow.h TabWindow.h ChoosePlotDialog.h RunEventNavigationBox.h QRootCanvas.h CanvasGrid.h OpenDialog.h LayoutMenu.h RootCanvasWidget.h DockWidget.h EventAwareSpinBox.h QRootEventHandler.h,src/TotemDQMLite/GUI/interface,src/TotemDQMLite/GUI/src,QT_BASE))
TotemDQMLiteGUI_EX_LIB   := TotemDQMLiteGUI
TotemDQMLiteGUI_EX_USE   := $(foreach d,$(TotemDQMLiteGUI_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteGUI_PACKAGE := self/src/TotemDQMLite/GUI/src
ALL_PRODS += TotemDQMLiteGUI
TotemDQMLiteGUI_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteGUI,src/TotemDQMLite/GUI/src,src_TotemDQMLite_GUI_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemDQMLite/Geometry)),)
ALL_COMMONRULES += src_TotemDQMLite_Geometry_src
src_TotemDQMLite_Geometry_src_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_src,src/TotemDQMLite/Geometry/src,LIBRARY))
TotemDQMLiteGeometry := self/TotemDQMLite/Geometry
TotemDQMLite/Geometry := TotemDQMLiteGeometry
TotemDQMLiteGeometry_files := $(patsubst src/TotemDQMLite/Geometry/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/Geometry/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteGeometry_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Geometry/BuildFile
TotemDQMLiteGeometry_LOC_USE := self  FWCore/Common clhep
TotemDQMLiteGeometry_EX_LIB   := TotemDQMLiteGeometry
TotemDQMLiteGeometry_EX_USE   := $(foreach d,$(TotemDQMLiteGeometry_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteGeometry_PACKAGE := self/src/TotemDQMLite/Geometry/src
ALL_PRODS += TotemDQMLiteGeometry
TotemDQMLiteGeometry_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteGeometry,src/TotemDQMLite/Geometry/src,src_TotemDQMLite_Geometry_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemDQMLite/Modules)),)
ALL_COMMONRULES += src_TotemDQMLite_Modules_src
src_TotemDQMLite_Modules_src_parent := TotemDQMLite/Modules
src_TotemDQMLite_Modules_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemDQMLite_Modules_src,src/TotemDQMLite/Modules/src,LIBRARY))
TotemDQMLiteModules := self/TotemDQMLite/Modules
TotemDQMLite/Modules := TotemDQMLiteModules
TotemDQMLiteModules_files := $(patsubst src/TotemDQMLite/Modules/src/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/Modules/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemDQMLiteModules_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Modules/BuildFile
TotemDQMLiteModules_LOC_USE := self  FWCore/ParameterSet FWCore/Common TotemDQMLite/Core TotemDQMLite/Geometry Geometry/TotemRPDetTopology Geometry/TotemGeometry DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/T2Hit rootgraphics qt
TotemDQMLiteModules_EX_LIB   := TotemDQMLiteModules
TotemDQMLiteModules_EX_USE   := $(foreach d,$(TotemDQMLiteModules_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemDQMLiteModules_PACKAGE := self/src/TotemDQMLite/Modules/src
ALL_PRODS += TotemDQMLiteModules
TotemDQMLiteModules_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteModules,src/TotemDQMLite/Modules/src,src_TotemDQMLite_Modules_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/BaseValidationClasses)),)
ALL_COMMONRULES += src_TotemRPValidation_BaseValidationClasses_src
src_TotemRPValidation_BaseValidationClasses_src_parent := TotemRPValidation/BaseValidationClasses
src_TotemRPValidation_BaseValidationClasses_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_BaseValidationClasses_src,src/TotemRPValidation/BaseValidationClasses/src,LIBRARY))
TotemRPValidationBaseValidationClasses := self/TotemRPValidation/BaseValidationClasses
TotemRPValidation/BaseValidationClasses := TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_files := $(patsubst src/TotemRPValidation/BaseValidationClasses/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BaseValidationClasses/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationBaseValidationClasses_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BaseValidationClasses/BuildFile
TotemRPValidationBaseValidationClasses_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology
TotemRPValidationBaseValidationClasses_EX_LIB   := TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_EX_USE   := $(foreach d,$(TotemRPValidationBaseValidationClasses_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationBaseValidationClasses_PACKAGE := self/src/TotemRPValidation/BaseValidationClasses/src
ALL_PRODS += TotemRPValidationBaseValidationClasses
TotemRPValidationBaseValidationClasses_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBaseValidationClasses,src/TotemRPValidation/BaseValidationClasses/src,src_TotemRPValidation_BaseValidationClasses_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/BeamSmearing)),)
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_src
src_TotemRPValidation_BeamSmearing_src_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_src,src/TotemRPValidation/BeamSmearing/src,LIBRARY))
TotemRPValidationBeamSmearing := self/TotemRPValidation/BeamSmearing
TotemRPValidation/BeamSmearing := TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_files := $(patsubst src/TotemRPValidation/BeamSmearing/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BeamSmearing/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationBeamSmearing_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BeamSmearing/BuildFile
TotemRPValidationBeamSmearing_LOC_USE := self  FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationBeamSmearing_EX_LIB   := TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_EX_USE   := $(foreach d,$(TotemRPValidationBeamSmearing_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationBeamSmearing_PACKAGE := self/src/TotemRPValidation/BeamSmearing/src
ALL_PRODS += TotemRPValidationBeamSmearing
TotemRPValidationBeamSmearing_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/src,src_TotemRPValidation_BeamSmearing_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/ElasticReconstruction)),)
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_src
src_TotemRPValidation_ElasticReconstruction_src_parent := TotemRPValidation/ElasticReconstruction
src_TotemRPValidation_ElasticReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_src,src/TotemRPValidation/ElasticReconstruction/src,LIBRARY))
TotemRPValidationElasticReconstruction := self/TotemRPValidation/ElasticReconstruction
TotemRPValidation/ElasticReconstruction := TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ElasticReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationElasticReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ElasticReconstruction/BuildFile
TotemRPValidationElasticReconstruction_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root rootgraphics rootminuit boost TotemRPValidation/BaseValidationClasses TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord TotemCondFormats/ProtonTransportFunctions
TotemRPValidationElasticReconstruction_EX_LIB   := TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_EX_USE   := $(foreach d,$(TotemRPValidationElasticReconstruction_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationElasticReconstruction_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/src
ALL_PRODS += TotemRPValidationElasticReconstruction
TotemRPValidationElasticReconstruction_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/src,src_TotemRPValidation_ElasticReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/HitDistributions)),)
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_src
src_TotemRPValidation_HitDistributions_src_parent := TotemRPValidation/HitDistributions
src_TotemRPValidation_HitDistributions_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_src,src/TotemRPValidation/HitDistributions/src,LIBRARY))
TotemRPValidationHitDistributions := self/TotemRPValidation/HitDistributions
TotemRPValidation/HitDistributions := TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_files := $(patsubst src/TotemRPValidation/HitDistributions/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/HitDistributions/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationHitDistributions_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/HitDistributions/BuildFile
TotemRPValidationHitDistributions_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root rootgraphics boost DataFormats/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords
TotemRPValidationHitDistributions_EX_LIB   := TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_EX_USE   := $(foreach d,$(TotemRPValidationHitDistributions_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationHitDistributions_PACKAGE := self/src/TotemRPValidation/HitDistributions/src
ALL_PRODS += TotemRPValidationHitDistributions
TotemRPValidationHitDistributions_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/src,src_TotemRPValidation_HitDistributions_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/RPGeant4Validation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPGeant4Validation_src
src_TotemRPValidation_RPGeant4Validation_src_parent := TotemRPValidation/RPGeant4Validation
src_TotemRPValidation_RPGeant4Validation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPGeant4Validation_src,src/TotemRPValidation/RPGeant4Validation/src,LIBRARY))
TotemRPValidationRPGeant4Validation := self/TotemRPValidation/RPGeant4Validation
TotemRPValidation/RPGeant4Validation := TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_files := $(patsubst src/TotemRPValidation/RPGeant4Validation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPGeant4Validation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPGeant4Validation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPGeant4Validation/BuildFile
TotemRPValidationRPGeant4Validation_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses
TotemRPValidationRPGeant4Validation_EX_LIB   := TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_EX_USE   := $(foreach d,$(TotemRPValidationRPGeant4Validation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationRPGeant4Validation_PACKAGE := self/src/TotemRPValidation/RPGeant4Validation/src
ALL_PRODS += TotemRPValidationRPGeant4Validation
TotemRPValidationRPGeant4Validation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPGeant4Validation,src/TotemRPValidation/RPGeant4Validation/src,src_TotemRPValidation_RPGeant4Validation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/ParamMADRefTransport)),)
ALL_COMMONRULES += src_TotemRPValidation_ParamMADRefTransport_src
src_TotemRPValidation_ParamMADRefTransport_src_parent := TotemRPValidation/ParamMADRefTransport
src_TotemRPValidation_ParamMADRefTransport_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ParamMADRefTransport_src,src/TotemRPValidation/ParamMADRefTransport/src,LIBRARY))
TotemRPValidationParamMADRefTransport := self/TotemRPValidation/ParamMADRefTransport
TotemRPValidation/ParamMADRefTransport := TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_files := $(patsubst src/TotemRPValidation/ParamMADRefTransport/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ParamMADRefTransport/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationParamMADRefTransport_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ParamMADRefTransport/BuildFile
TotemRPValidationParamMADRefTransport_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar SimDataFormats/GeneratorProducts SimG4Core/Notification TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord rootminuit2
TotemRPValidationParamMADRefTransport_EX_LIB   := TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_EX_USE   := $(foreach d,$(TotemRPValidationParamMADRefTransport_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationParamMADRefTransport_PACKAGE := self/src/TotemRPValidation/ParamMADRefTransport/src
ALL_PRODS += TotemRPValidationParamMADRefTransport
TotemRPValidationParamMADRefTransport_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationParamMADRefTransport,src/TotemRPValidation/ParamMADRefTransport/src,src_TotemRPValidation_ParamMADRefTransport_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/TransportValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_src
src_TotemRPValidation_TransportValidation_src_parent := TotemRPValidation/TransportValidation
src_TotemRPValidation_TransportValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_src,src/TotemRPValidation/TransportValidation/src,LIBRARY))
TotemRPValidationTransportValidation := self/TotemRPValidation/TransportValidation
TotemRPValidation/TransportValidation := TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_files := $(patsubst src/TotemRPValidation/TransportValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/TransportValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationTransportValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/TransportValidation/BuildFile
TotemRPValidationTransportValidation_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords SimG4CMS/TotemRPProtTranspPar
TotemRPValidationTransportValidation_EX_LIB   := TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_EX_USE   := $(foreach d,$(TotemRPValidationTransportValidation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationTransportValidation_PACKAGE := self/src/TotemRPValidation/TransportValidation/src
ALL_PRODS += TotemRPValidationTransportValidation
TotemRPValidationTransportValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/src,src_TotemRPValidation_TransportValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/ValidationPlots)),)
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_src
src_TotemRPValidation_ValidationPlots_src_parent := TotemRPValidation/ValidationPlots
src_TotemRPValidation_ValidationPlots_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_src,src/TotemRPValidation/ValidationPlots/src,LIBRARY))
TotemRPValidationValidationPlots := self/TotemRPValidation/ValidationPlots
TotemRPValidation/ValidationPlots := TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_files := $(patsubst src/TotemRPValidation/ValidationPlots/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationPlots/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationValidationPlots_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationPlots/BuildFile
TotemRPValidationValidationPlots_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats TotemRPValidation/ValidationTools root TotemRPValidation/ElasticReconstruction TotemRPValidation/HitDistributions boost
TotemRPValidationValidationPlots_EX_LIB   := TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_EX_USE   := $(foreach d,$(TotemRPValidationValidationPlots_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationValidationPlots_PACKAGE := self/src/TotemRPValidation/ValidationPlots/src
ALL_PRODS += TotemRPValidationValidationPlots
TotemRPValidationValidationPlots_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/src,src_TotemRPValidation_ValidationPlots_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRPValidation/ValidationTools)),)
ALL_COMMONRULES += src_TotemRPValidation_ValidationTools_src
src_TotemRPValidation_ValidationTools_src_parent := TotemRPValidation/ValidationTools
src_TotemRPValidation_ValidationTools_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationTools_src,src/TotemRPValidation/ValidationTools/src,LIBRARY))
TotemRPValidationValidationTools := self/TotemRPValidation/ValidationTools
TotemRPValidation/ValidationTools := TotemRPValidationValidationTools
TotemRPValidationValidationTools_files := $(patsubst src/TotemRPValidation/ValidationTools/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationTools/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationValidationTools_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationTools/BuildFile
TotemRPValidationValidationTools_LOC_USE := self  root rootcore
TotemRPValidationValidationTools_PRE_INIT_FUNC += $$(eval $$(call RootDict,TotemRPValidationValidationTools,src/TotemRPValidation/ValidationTools/src, TotemRPValidationValidationToolsLinkDef.h))
TotemRPValidationValidationTools_EX_LIB   := TotemRPValidationValidationTools
TotemRPValidationValidationTools_EX_USE   := $(foreach d,$(TotemRPValidationValidationTools_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRPValidationValidationTools_PACKAGE := self/src/TotemRPValidation/ValidationTools/src
ALL_PRODS += TotemRPValidationValidationTools
TotemRPValidationValidationTools_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationTools,src/TotemRPValidation/ValidationTools/src,src_TotemRPValidation_ValidationTools_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRawData/DataFormats)),)
ALL_COMMONRULES += src_TotemRawData_DataFormats_src
src_TotemRawData_DataFormats_src_parent := TotemRawData/DataFormats
src_TotemRawData_DataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawData_DataFormats_src,src/TotemRawData/DataFormats/src,LIBRARY))
TotemRawDataDataFormats := self/TotemRawData/DataFormats
TotemRawData/DataFormats := TotemRawDataDataFormats
TotemRawDataDataFormats_files := $(patsubst src/TotemRawData/DataFormats/src/%,%,$(wildcard $(foreach dir,src/TotemRawData/DataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/DataFormats/BuildFile
TotemRawDataDataFormats_LOC_USE := self  
TotemRawDataDataFormats_EX_LIB   := TotemRawDataDataFormats
TotemRawDataDataFormats_EX_USE   := $(foreach d,$(TotemRawDataDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataDataFormats_PACKAGE := self/src/TotemRawData/DataFormats/src
ALL_PRODS += TotemRawDataDataFormats
TotemRawDataDataFormats_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataDataFormats,src/TotemRawData/DataFormats/src,src_TotemRawData_DataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRawData/RawToDigi)),)
ALL_COMMONRULES += src_TotemRawData_RawToDigi_src
src_TotemRawData_RawToDigi_src_parent := TotemRawData/RawToDigi
src_TotemRawData_RawToDigi_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_src,src/TotemRawData/RawToDigi/src,LIBRARY))
TotemRawDataRawToDigi := self/TotemRawData/RawToDigi
TotemRawData/RawToDigi := TotemRawDataRawToDigi
TotemRawDataRawToDigi_files := $(patsubst src/TotemRawData/RawToDigi/src/%,%,$(wildcard $(foreach dir,src/TotemRawData/RawToDigi/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataRawToDigi_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/RawToDigi/BuildFile
TotemRawDataRawToDigi_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataRawToDigi_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/DataFormats DataFormats/T2Digi DataFormats/T2DigiVfat DataFormats/T2DetId Geometry/TotemGeometry DataFormats/T1DigiVfat DataFormats/T1DetId DataFormats/T1DigiWire SimTotem/T1Digitizer
TotemRawDataRawToDigi_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataRawToDigiCapabilities,TotemRawDataRawToDigi,$(SCRAMSTORENAME_LIB),src/TotemRawData/RawToDigi/src))
TotemRawDataRawToDigi_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemRawDataRawToDigi,0,src/TotemRawData/RawToDigi/src/classes.h,src/TotemRawData/RawToDigi/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemRawDataRawToDigi_EX_LIB   := TotemRawDataRawToDigi
TotemRawDataRawToDigi_EX_USE   := $(foreach d,$(TotemRawDataRawToDigi_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataRawToDigi_PACKAGE := self/src/TotemRawData/RawToDigi/src
ALL_PRODS += TotemRawDataRawToDigi
TotemRawDataRawToDigi_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataRawToDigi,src/TotemRawData/RawToDigi/src,src_TotemRawData_RawToDigi_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRawDataLibrary/DataFormats)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_DataFormats_src
src_TotemRawDataLibrary_DataFormats_src_parent := TotemRawDataLibrary/DataFormats
src_TotemRawDataLibrary_DataFormats_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_DataFormats_src,src/TotemRawDataLibrary/DataFormats/src,LIBRARY))
TotemRawDataLibraryDataFormats := self/TotemRawDataLibrary/DataFormats
TotemRawDataLibrary/DataFormats := TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_files := $(patsubst src/TotemRawDataLibrary/DataFormats/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/DataFormats/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryDataFormats_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/DataFormats/BuildFile
TotemRawDataLibraryDataFormats_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataLibraryDataFormats_LOC_USE := self  FWCore/Framework rootrflx
TotemRawDataLibraryDataFormats_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataLibraryDataFormatsCapabilities,TotemRawDataLibraryDataFormats,$(SCRAMSTORENAME_LIB),src/TotemRawDataLibrary/DataFormats/src))
TotemRawDataLibraryDataFormats_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemRawDataLibraryDataFormats,0,src/TotemRawDataLibrary/DataFormats/src/classes.h,src/TotemRawDataLibrary/DataFormats/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemRawDataLibraryDataFormats_EX_LIB   := TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_EX_USE   := $(foreach d,$(TotemRawDataLibraryDataFormats_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryDataFormats_PACKAGE := self/src/TotemRawDataLibrary/DataFormats/src
ALL_PRODS += TotemRawDataLibraryDataFormats
TotemRawDataLibraryDataFormats_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryDataFormats,src/TotemRawDataLibrary/DataFormats/src,src_TotemRawDataLibrary_DataFormats_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRawDataLibrary/Readers)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_Readers_src
src_TotemRawDataLibrary_Readers_src_parent := TotemRawDataLibrary/Readers
src_TotemRawDataLibrary_Readers_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Readers_src,src/TotemRawDataLibrary/Readers/src,LIBRARY))
TotemRawDataLibraryReaders := self/TotemRawDataLibrary/Readers
TotemRawDataLibrary/Readers := TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_files := $(patsubst src/TotemRawDataLibrary/Readers/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/Readers/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryReaders_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Readers/BuildFile
TotemRawDataLibraryReaders_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS) -lXrdPosix -lXrdPosixPreload
TotemRawDataLibraryReaders_LOC_FLAGS_CPPDEFINES   := -DUSE_XROOTD=1 -DUSE_CASTOR=1
TotemRawDataLibraryReaders_LOC_USE := self  TotemRawDataLibrary/DataFormats xrootd castor
TotemRawDataLibraryReaders_EX_LIB   := TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_EX_USE   := $(foreach d,$(TotemRawDataLibraryReaders_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryReaders_PACKAGE := self/src/TotemRawDataLibrary/Readers/src
ALL_PRODS += TotemRawDataLibraryReaders
TotemRawDataLibraryReaders_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryReaders,src/TotemRawDataLibrary/Readers/src,src_TotemRawDataLibrary_Readers_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemRawDataLibrary/Utilities)),)
ALL_COMMONRULES += src_TotemRawDataLibrary_Utilities_src
src_TotemRawDataLibrary_Utilities_src_parent := TotemRawDataLibrary/Utilities
src_TotemRawDataLibrary_Utilities_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Utilities_src,src/TotemRawDataLibrary/Utilities/src,LIBRARY))
TotemRawDataLibraryUtilities := self/TotemRawDataLibrary/Utilities
TotemRawDataLibrary/Utilities := TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_files := $(patsubst src/TotemRawDataLibrary/Utilities/src/%,%,$(wildcard $(foreach dir,src/TotemRawDataLibrary/Utilities/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRawDataLibraryUtilities_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/BuildFile
TotemRawDataLibraryUtilities_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataLibraryUtilities_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/DataFormats
TotemRawDataLibraryUtilities_EX_LIB   := TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_EX_USE   := $(foreach d,$(TotemRawDataLibraryUtilities_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemRawDataLibraryUtilities_PACKAGE := self/src/TotemRawDataLibrary/Utilities/src
ALL_PRODS += TotemRawDataLibraryUtilities
TotemRawDataLibraryUtilities_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryUtilities,src/TotemRawDataLibrary/Utilities/src,src_TotemRawDataLibrary_Utilities_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemT1T2Validation/T1Validation)),)
src_TotemT1T2Validation_T1Validation := self/TotemT1T2Validation/T1Validation
TotemT1T2Validation/T1Validation  := src_TotemT1T2Validation_T1Validation
src_TotemT1T2Validation_T1Validation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T1Validation/BuildFile
src_TotemT1T2Validation_T1Validation_LOC_USE := DataFormats/T1DetId clhep boost SimDataFormats/Track FWCore/Framework self DataFormats/DetId CommonTools/Clustering1D DataFormats/T1Cluster DataFormats/T1DigiVfat DataFormats/T1DigiWire root DataFormats/T1T2Track FWCore/MessageLogger Geometry/TotemRecords DataFormats/Common DataFormats/T1RecHit Geometry/TotemGeometry DataFormats/TrackingRecHit FWCore/ParameterSet
src_TotemT1T2Validation_T1Validation_EX_USE   := $(foreach d,$(src_TotemT1T2Validation_T1Validation_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_TotemT1T2Validation_T1Validation
src_TotemT1T2Validation_T1Validation_INIT_FUNC += $$(eval $$(call EmptyPackage,src_TotemT1T2Validation_T1Validation,src/TotemT1T2Validation/T1Validation))
endif

ifeq ($(strip $(UATree/MitEdm)),)
ALL_COMMONRULES += src_UATree_MitEdm_src
src_UATree_MitEdm_src_parent := UATree/MitEdm
src_UATree_MitEdm_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_MitEdm_src,src/UATree/MitEdm/src,LIBRARY))
UATreeMitEdm := self/UATree/MitEdm
UATree/MitEdm := UATreeMitEdm
UATreeMitEdm_files := $(patsubst src/UATree/MitEdm/src/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeMitEdm_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/MitEdm/BuildFile
UATreeMitEdm_LOC_USE := self  DataFormats/TrackReco DataFormats/GsfTrackReco root FWCore/Framework FWCore/ParameterSet FWCore/PluginManager CommonTools/UtilAlgos DataFormats/CaloTowers DataFormats/Common DataFormats/VertexReco DataFormats/CaloRecHit MagneticField/Engine Geometry/CaloGeometry RecoTracker/Record TrackingTools/TransientTrack RecoTracker/TkDetLayers RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives
UATreeMitEdm_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UATreeMitEdmCapabilities,UATreeMitEdm,$(SCRAMSTORENAME_LIB),src/UATree/MitEdm/src))
UATreeMitEdm_PRE_INIT_FUNC += $$(eval $$(call LCGDict,UATreeMitEdm,0,src/UATree/MitEdm/src/classes.h,src/UATree/MitEdm/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
UATreeMitEdm_EX_LIB   := UATreeMitEdm
UATreeMitEdm_EX_USE   := $(foreach d,$(UATreeMitEdm_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/src
ALL_PRODS += UATreeMitEdm
UATreeMitEdm_INIT_FUNC        += $$(eval $$(call Library,UATreeMitEdm,src/UATree/MitEdm/src,src_UATree_MitEdm_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(UATree/UADataFormat)),)
ALL_COMMONRULES += src_UATree_UADataFormat_src
src_UATree_UADataFormat_src_parent := UATree/UADataFormat
src_UATree_UADataFormat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_UADataFormat_src,src/UATree/UADataFormat/src,LIBRARY))
UATreeUADataFormat := self/UATree/UADataFormat
UATree/UADataFormat := UATreeUADataFormat
UATreeUADataFormat_files := $(patsubst src/UATree/UADataFormat/src/%,%,$(wildcard $(foreach dir,src/UATree/UADataFormat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeUADataFormat_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/UADataFormat/BuildFile
UATreeUADataFormat_LOC_USE := self  root rootmath rootrflx rootcore
UATreeUADataFormat_PRE_INIT_FUNC += $$(eval $$(call RootDict,UATreeUADataFormat,src/UATree/UADataFormat/src, LinkDef.h))
UATreeUADataFormat_EX_LIB   := UATreeUADataFormat
UATreeUADataFormat_EX_USE   := $(foreach d,$(UATreeUADataFormat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeUADataFormat_PACKAGE := self/src/UATree/UADataFormat/src
ALL_PRODS += UATreeUADataFormat
UATreeUADataFormat_INIT_FUNC        += $$(eval $$(call Library,UATreeUADataFormat,src/UATree/UADataFormat/src,src_UATree_UADataFormat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(ForwardAnalysis/ForwardTTreeAnalysis)),)
ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_src
src_ForwardAnalysis_ForwardTTreeAnalysis_src_parent := ForwardAnalysis/ForwardTTreeAnalysis
src_ForwardAnalysis_ForwardTTreeAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_src,src/ForwardAnalysis/ForwardTTreeAnalysis/src,LIBRARY))
ForwardAnalysisForwardTTreeAnalysis := self/ForwardAnalysis/ForwardTTreeAnalysis
ForwardAnalysis/ForwardTTreeAnalysis := ForwardAnalysisForwardTTreeAnalysis
ForwardAnalysisForwardTTreeAnalysis_files := $(patsubst src/ForwardAnalysis/ForwardTTreeAnalysis/src/%,%,$(wildcard $(foreach dir,src/ForwardAnalysis/ForwardTTreeAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
ForwardAnalysisForwardTTreeAnalysis_LOC_USE := self  
ForwardAnalysisForwardTTreeAnalysis_PACKAGE := self/src/ForwardAnalysis/ForwardTTreeAnalysis/src
ALL_PRODS += ForwardAnalysisForwardTTreeAnalysis
ForwardAnalysisForwardTTreeAnalysis_INIT_FUNC        += $$(eval $$(call Library,ForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/src,src_ForwardAnalysis_ForwardTTreeAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/TotemAnalysisEvent)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemAnalysisEvent_src
src_TotemAnalysis_TotemAnalysisEvent_src_parent := TotemAnalysis/TotemAnalysisEvent
src_TotemAnalysis_TotemAnalysisEvent_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemAnalysisEvent_src,src/TotemAnalysis/TotemAnalysisEvent/src,LIBRARY))
TotemAnalysisTotemAnalysisEvent := self/TotemAnalysis/TotemAnalysisEvent
TotemAnalysis/TotemAnalysisEvent := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_files := $(patsubst src/TotemAnalysis/TotemAnalysisEvent/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemAnalysisEvent/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemAnalysisEvent_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemAnalysisEvent/BuildFile
TotemAnalysisTotemAnalysisEvent_LOC_USE := self  FWCore/ParameterSet FWCore/Framework root DataFormats/Common
TotemAnalysisTotemAnalysisEvent_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTotemAnalysisEventCapabilities,TotemAnalysisTotemAnalysisEvent,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TotemAnalysisEvent/src))
TotemAnalysisTotemAnalysisEvent_PRE_INIT_FUNC += $$(eval $$(call LCGDict,TotemAnalysisTotemAnalysisEvent,0,src/TotemAnalysis/TotemAnalysisEvent/src/classes.h,src/TotemAnalysis/TotemAnalysisEvent/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,Capabilities))
TotemAnalysisTotemAnalysisEvent_EX_LIB   := TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_EX_USE   := $(foreach d,$(TotemAnalysisTotemAnalysisEvent_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemAnalysisEvent_PACKAGE := self/src/TotemAnalysis/TotemAnalysisEvent/src
ALL_PRODS += TotemAnalysisTotemAnalysisEvent
TotemAnalysisTotemAnalysisEvent_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemAnalysisEvent,src/TotemAnalysis/TotemAnalysisEvent/src,src_TotemAnalysis_TotemAnalysisEvent_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(TotemAnalysis/TotemRPAnalysis)),)
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_src
src_TotemAnalysis_TotemRPAnalysis_src_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_src,src/TotemAnalysis/TotemRPAnalysis/src,LIBRARY))
TotemAnalysisTotemRPAnalysis := self/TotemAnalysis/TotemRPAnalysis
TotemAnalysis/TotemRPAnalysis := TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemRPAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisTotemRPAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemRPAnalysis/BuildFile
TotemAnalysisTotemRPAnalysis_LOC_USE := self  FWCore/ParameterSet FWCore/Framework FWCore/PluginManager clhep root hepmc fastjet DataFormats/TotemRPDataTypes DataFormats/Common DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/DataRecord Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road TotemAnalysis/TotemAnalysisEvent
TotemAnalysisTotemRPAnalysis_EX_LIB   := TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_EX_USE   := $(foreach d,$(TotemAnalysisTotemRPAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TotemAnalysisTotemRPAnalysis_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/src
ALL_PRODS += TotemAnalysisTotemRPAnalysis
TotemAnalysisTotemRPAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/src,src_TotemAnalysis_TotemRPAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
