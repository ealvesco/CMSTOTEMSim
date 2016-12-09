ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/Configuration)
subdirs_src_Configuration = src_Configuration_TotemCommon src_Configuration_TotemOpticsConfiguration src_Configuration_TotemStandardSequences src_Configuration_CMSTotemStandardSequences src_Configuration_Info
ALL_PACKAGES += $(patsubst src/%,%,src/Configuration/CMSTotemStandardSequences)
subdirs_src_Configuration_CMSTotemStandardSequences := src_Configuration_CMSTotemStandardSequences_test src_Configuration_CMSTotemStandardSequences_python src_Configuration_CMSTotemStandardSequences_data src_Configuration_CMSTotemStandardSequences_drivers
ifeq ($(strip $(PyConfigurationCMSTotemStandardSequences)),)
PyConfigurationCMSTotemStandardSequences := self/src/Configuration/CMSTotemStandardSequences/python
src_Configuration_CMSTotemStandardSequences_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/CMSTotemStandardSequences/python)
PyConfigurationCMSTotemStandardSequences_files := $(patsubst src/Configuration/CMSTotemStandardSequences/python/%,%,$(wildcard $(foreach dir,src/Configuration/CMSTotemStandardSequences/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationCMSTotemStandardSequences_LOC_USE := self  
PyConfigurationCMSTotemStandardSequences_PACKAGE := self/src/Configuration/CMSTotemStandardSequences/python
ALL_PRODS += PyConfigurationCMSTotemStandardSequences
PyConfigurationCMSTotemStandardSequences_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationCMSTotemStandardSequences,src/Configuration/CMSTotemStandardSequences/python,src_Configuration_CMSTotemStandardSequences_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationCMSTotemStandardSequences,src/Configuration/CMSTotemStandardSequences/python))
endif
ALL_COMMONRULES += src_Configuration_CMSTotemStandardSequences_python
src_Configuration_CMSTotemStandardSequences_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_CMSTotemStandardSequences_python,src/Configuration/CMSTotemStandardSequences/python,PYTHON))
ALL_COMMONRULES += src_Configuration_CMSTotemStandardSequences_test
src_Configuration_CMSTotemStandardSequences_test_parent := Configuration/CMSTotemStandardSequences
src_Configuration_CMSTotemStandardSequences_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_CMSTotemStandardSequences_test,src/Configuration/CMSTotemStandardSequences/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/Configuration/Info)
subdirs_src_Configuration_Info := src_Configuration_Info_python
ifeq ($(strip $(PyConfigurationInfo)),)
PyConfigurationInfo := self/src/Configuration/Info/python
src_Configuration_Info_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/Info/python)
PyConfigurationInfo_files := $(patsubst src/Configuration/Info/python/%,%,$(wildcard $(foreach dir,src/Configuration/Info/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationInfo_LOC_USE := self  
PyConfigurationInfo_PACKAGE := self/src/Configuration/Info/python
ALL_PRODS += PyConfigurationInfo
PyConfigurationInfo_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationInfo,src/Configuration/Info/python,src_Configuration_Info_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationInfo,src/Configuration/Info/python))
endif
ALL_COMMONRULES += src_Configuration_Info_python
src_Configuration_Info_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_Info_python,src/Configuration/Info/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/Configuration/TotemCommon)
subdirs_src_Configuration_TotemCommon := src_Configuration_TotemCommon_python
ifeq ($(strip $(PyConfigurationTotemCommon)),)
PyConfigurationTotemCommon := self/src/Configuration/TotemCommon/python
src_Configuration_TotemCommon_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemCommon/python)
PyConfigurationTotemCommon_files := $(patsubst src/Configuration/TotemCommon/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemCommon/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemCommon_LOC_USE := self  
PyConfigurationTotemCommon_PACKAGE := self/src/Configuration/TotemCommon/python
ALL_PRODS += PyConfigurationTotemCommon
PyConfigurationTotemCommon_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemCommon,src/Configuration/TotemCommon/python,src_Configuration_TotemCommon_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemCommon,src/Configuration/TotemCommon/python))
endif
ALL_COMMONRULES += src_Configuration_TotemCommon_python
src_Configuration_TotemCommon_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemCommon_python,src/Configuration/TotemCommon/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/Configuration/TotemOpticsConfiguration)
subdirs_src_Configuration_TotemOpticsConfiguration := src_Configuration_TotemOpticsConfiguration_interface src_Configuration_TotemOpticsConfiguration_python src_Configuration_TotemOpticsConfiguration_src
ifeq ($(strip $(PyConfigurationTotemOpticsConfiguration)),)
PyConfigurationTotemOpticsConfiguration := self/src/Configuration/TotemOpticsConfiguration/python
src_Configuration_TotemOpticsConfiguration_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemOpticsConfiguration/python)
PyConfigurationTotemOpticsConfiguration_files := $(patsubst src/Configuration/TotemOpticsConfiguration/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemOpticsConfiguration/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemOpticsConfiguration_LOC_USE := self  
PyConfigurationTotemOpticsConfiguration_PACKAGE := self/src/Configuration/TotemOpticsConfiguration/python
ALL_PRODS += PyConfigurationTotemOpticsConfiguration
PyConfigurationTotemOpticsConfiguration_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/python,src_Configuration_TotemOpticsConfiguration_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/python))
endif
ALL_COMMONRULES += src_Configuration_TotemOpticsConfiguration_python
src_Configuration_TotemOpticsConfiguration_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemOpticsConfiguration_python,src/Configuration/TotemOpticsConfiguration/python,PYTHON))
ifeq ($(strip $(Configuration/TotemOpticsConfiguration)),)
ALL_COMMONRULES += src_Configuration_TotemOpticsConfiguration_src
src_Configuration_TotemOpticsConfiguration_src_parent := Configuration/TotemOpticsConfiguration
src_Configuration_TotemOpticsConfiguration_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Configuration_TotemOpticsConfiguration_src,src/Configuration/TotemOpticsConfiguration/src,LIBRARY))
ConfigurationTotemOpticsConfiguration := self/Configuration/TotemOpticsConfiguration
Configuration/TotemOpticsConfiguration := ConfigurationTotemOpticsConfiguration
ConfigurationTotemOpticsConfiguration_files := $(patsubst src/Configuration/TotemOpticsConfiguration/src/%,%,$(wildcard $(foreach dir,src/Configuration/TotemOpticsConfiguration/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
ConfigurationTotemOpticsConfiguration_BuildFile    := $(WORKINGDIR)/cache/bf/src/Configuration/TotemOpticsConfiguration/BuildFile
ConfigurationTotemOpticsConfiguration_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions DataFormats/TotemRPDataTypes root SimG4CMS/TotemRPProtTranspPar
ConfigurationTotemOpticsConfiguration_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,ConfigurationTotemOpticsConfiguration,ConfigurationTotemOpticsConfiguration,$(SCRAMSTORENAME_LIB),src/Configuration/TotemOpticsConfiguration/src))
ConfigurationTotemOpticsConfiguration_PACKAGE := self/src/Configuration/TotemOpticsConfiguration/src
ALL_PRODS += ConfigurationTotemOpticsConfiguration
ConfigurationTotemOpticsConfiguration_INIT_FUNC        += $$(eval $$(call Library,ConfigurationTotemOpticsConfiguration,src/Configuration/TotemOpticsConfiguration/src,src_Configuration_TotemOpticsConfiguration_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_PACKAGES += $(patsubst src/%,%,src/Configuration/TotemStandardSequences)
subdirs_src_Configuration_TotemStandardSequences := src_Configuration_TotemStandardSequences_test src_Configuration_TotemStandardSequences_python
ifeq ($(strip $(PyConfigurationTotemStandardSequences)),)
PyConfigurationTotemStandardSequences := self/src/Configuration/TotemStandardSequences/python
src_Configuration_TotemStandardSequences_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/TotemStandardSequences/python)
PyConfigurationTotemStandardSequences_files := $(patsubst src/Configuration/TotemStandardSequences/python/%,%,$(wildcard $(foreach dir,src/Configuration/TotemStandardSequences/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationTotemStandardSequences_LOC_USE := self  
PyConfigurationTotemStandardSequences_PACKAGE := self/src/Configuration/TotemStandardSequences/python
ALL_PRODS += PyConfigurationTotemStandardSequences
PyConfigurationTotemStandardSequences_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationTotemStandardSequences,src/Configuration/TotemStandardSequences/python,src_Configuration_TotemStandardSequences_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationTotemStandardSequences,src/Configuration/TotemStandardSequences/python))
endif
ALL_COMMONRULES += src_Configuration_TotemStandardSequences_python
src_Configuration_TotemStandardSequences_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemStandardSequences_python,src/Configuration/TotemStandardSequences/python,PYTHON))
ALL_COMMONRULES += src_Configuration_TotemStandardSequences_test
src_Configuration_TotemStandardSequences_test_parent := Configuration/TotemStandardSequences
src_Configuration_TotemStandardSequences_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_TotemStandardSequences_test,src/Configuration/TotemStandardSequences/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/DataFormats)
subdirs_src_DataFormats = src_DataFormats_T1T2Track src_DataFormats_T1Digi src_DataFormats_T1TestElements src_DataFormats_TotemData src_DataFormats_T2Digi src_DataFormats_T1RecHit src_DataFormats_T1Cluster src_DataFormats_T2Cluster src_DataFormats_T1RawData src_DataFormats_DetId src_DataFormats_T2Hit src_DataFormats_T1Road src_DataFormats_T2Road src_DataFormats_T1DetId src_DataFormats_T2DetId src_DataFormats_T1DigiVfat src_DataFormats_T2DigiVfat src_DataFormats_TotemRPDetId src_DataFormats_T1DigiSantiard src_DataFormats_T1DigiWire src_DataFormats_TotemL1Trigger src_DataFormats_TotemRPDataTypes
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/DetId)
subdirs_src_DataFormats_DetId := src_DataFormats_DetId_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1Cluster)
subdirs_src_DataFormats_T1Cluster := src_DataFormats_T1Cluster_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1DetId)
subdirs_src_DataFormats_T1DetId := src_DataFormats_T1DetId_interface src_DataFormats_T1DetId_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1Digi)
subdirs_src_DataFormats_T1Digi := src_DataFormats_T1Digi_interface src_DataFormats_T1Digi_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1DigiSantiard)
subdirs_src_DataFormats_T1DigiSantiard := src_DataFormats_T1DigiSantiard_interface src_DataFormats_T1DigiSantiard_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1DigiVfat)
subdirs_src_DataFormats_T1DigiVfat := src_DataFormats_T1DigiVfat_interface src_DataFormats_T1DigiVfat_src
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/Geometry)
subdirs_src_Geometry = src_Geometry_TotemRPAlignmentData src_Geometry_TotemT2AlignmentDataFormats src_Geometry_TotemGeometry src_Geometry_TotemRPData src_Geometry_TotemRPDetTopology src_Geometry_CMSCommonData src_Geometry_ForwardCommonData src_Geometry_ForwardSimData src_Geometry_TotemRecords src_Geometry_TotemRPOptics src_Geometry_TotemRPGeometryBuilder
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1DigiWire)
subdirs_src_DataFormats_T1DigiWire := src_DataFormats_T1DigiWire_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1RawData)
subdirs_src_DataFormats_T1RawData := src_DataFormats_T1RawData_interface src_DataFormats_T1RawData_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1RecHit)
subdirs_src_DataFormats_T1RecHit := src_DataFormats_T1RecHit_interface src_DataFormats_T1RecHit_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1Road)
subdirs_src_DataFormats_T1Road := src_DataFormats_T1Road_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1T2Track)
subdirs_src_DataFormats_T1T2Track := src_DataFormats_T1T2Track_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T1TestElements)
subdirs_src_DataFormats_T1TestElements := src_DataFormats_T1TestElements_interface src_DataFormats_T1TestElements_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2Cluster)
subdirs_src_DataFormats_T2Cluster := src_DataFormats_T2Cluster_interface src_DataFormats_T2Cluster_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2DetId)
subdirs_src_DataFormats_T2DetId := src_DataFormats_T2DetId_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2Digi)
subdirs_src_DataFormats_T2Digi := src_DataFormats_T2Digi_interface src_DataFormats_T2Digi_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2DigiVfat)
subdirs_src_DataFormats_T2DigiVfat := src_DataFormats_T2DigiVfat_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2Hit)
subdirs_src_DataFormats_T2Hit := src_DataFormats_T2Hit_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/T2Road)
subdirs_src_DataFormats_T2Road := src_DataFormats_T2Road_interface src_DataFormats_T2Road_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/TotemData)
subdirs_src_DataFormats_TotemData := 
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/TotemL1Trigger)
subdirs_src_DataFormats_TotemL1Trigger := src_DataFormats_TotemL1Trigger_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/TotemRPDataTypes)
subdirs_src_DataFormats_TotemRPDataTypes := src_DataFormats_TotemRPDataTypes_src
ALL_PACKAGES += $(patsubst src/%,%,src/DataFormats/TotemRPDetId)
subdirs_src_DataFormats_TotemRPDetId := src_DataFormats_TotemRPDetId_src
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/Documentation)
subdirs_src_Documentation = src_Documentation_Totem
ALL_PACKAGES += $(patsubst src/%,%,src/Documentation/Totem)
subdirs_src_Documentation_Totem := 
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/GeneratorInterface)
subdirs_src_GeneratorInterface = src_GeneratorInterface_CosmicRayInterface src_GeneratorInterface_PompytInterface
ALL_PACKAGES += $(patsubst src/%,%,src/GeneratorInterface/CosmicRayInterface)
subdirs_src_GeneratorInterface_CosmicRayInterface := src_GeneratorInterface_CosmicRayInterface_interface src_GeneratorInterface_CosmicRayInterface_plugins src_GeneratorInterface_CosmicRayInterface_scripts src_GeneratorInterface_CosmicRayInterface_src
ifeq ($(strip $(GeneratorInterfaceCosmicRayInterfacePlugins)),)
GeneratorInterfaceCosmicRayInterfacePlugins_files := $(patsubst src/GeneratorInterface/CosmicRayInterface/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/GeneratorInterface/CosmicRayInterface/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/GeneratorInterface/CosmicRayInterface/plugins/$(file). Please fix src/GeneratorInterface/CosmicRayInterface/plugins/BuildFile.))))
GeneratorInterfaceCosmicRayInterfacePlugins := self/src/GeneratorInterface/CosmicRayInterface/plugins
GeneratorInterfaceCosmicRayInterfacePlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/GeneratorInterface/CosmicRayInterface/plugins/BuildFile
GeneratorInterfaceCosmicRayInterfacePlugins_LOC_USE := self  GeneratorInterface/CosmicRayInterface
GeneratorInterfaceCosmicRayInterfacePlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeneratorInterfaceCosmicRayInterfacePlugins,GeneratorInterfaceCosmicRayInterfacePlugins,$(SCRAMSTORENAME_LIB),src/GeneratorInterface/CosmicRayInterface/plugins))
GeneratorInterfaceCosmicRayInterfacePlugins_PACKAGE := self/src/GeneratorInterface/CosmicRayInterface/plugins
ALL_PRODS += GeneratorInterfaceCosmicRayInterfacePlugins
GeneratorInterfaceCosmicRayInterfacePlugins_INIT_FUNC        += $$(eval $$(call Library,GeneratorInterfaceCosmicRayInterfacePlugins,src/GeneratorInterface/CosmicRayInterface/plugins,src_GeneratorInterface_CosmicRayInterface_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,GeneratorInterfaceCosmicRayInterfacePlugins,src/GeneratorInterface/CosmicRayInterface/plugins))
endif
ALL_COMMONRULES += src_GeneratorInterface_CosmicRayInterface_plugins
src_GeneratorInterface_CosmicRayInterface_plugins_parent := GeneratorInterface/CosmicRayInterface
src_GeneratorInterface_CosmicRayInterface_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GeneratorInterface_CosmicRayInterface_plugins,src/GeneratorInterface/CosmicRayInterface/plugins,PLUGINS))
src_GeneratorInterface_CosmicRayInterface_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/GeneratorInterface/CosmicRayInterface/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_GeneratorInterface_CosmicRayInterface_scripts,src/GeneratorInterface/CosmicRayInterface/scripts,$(SCRAMSTORENAME_BIN),*))
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/CMSCommonData)
subdirs_src_Geometry_CMSCommonData := src_Geometry_CMSCommonData_python
ifeq ($(strip $(PyGeometryCMSCommonData)),)
PyGeometryCMSCommonData := self/src/Geometry/CMSCommonData/python
src_Geometry_CMSCommonData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/CMSCommonData/python)
PyGeometryCMSCommonData_files := $(patsubst src/Geometry/CMSCommonData/python/%,%,$(wildcard $(foreach dir,src/Geometry/CMSCommonData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryCMSCommonData_LOC_USE := self  
PyGeometryCMSCommonData_PACKAGE := self/src/Geometry/CMSCommonData/python
ALL_PRODS += PyGeometryCMSCommonData
PyGeometryCMSCommonData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryCMSCommonData,src/Geometry/CMSCommonData/python,src_Geometry_CMSCommonData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryCMSCommonData,src/Geometry/CMSCommonData/python))
endif
ALL_COMMONRULES += src_Geometry_CMSCommonData_python
src_Geometry_CMSCommonData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_CMSCommonData_python,src/Geometry/CMSCommonData/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/ForwardCommonData)
subdirs_src_Geometry_ForwardCommonData := src_Geometry_ForwardCommonData_test src_Geometry_ForwardCommonData_python src_Geometry_ForwardCommonData_data
ifeq ($(strip $(PyGeometryForwardCommonData)),)
PyGeometryForwardCommonData := self/src/Geometry/ForwardCommonData/python
src_Geometry_ForwardCommonData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/ForwardCommonData/python)
PyGeometryForwardCommonData_files := $(patsubst src/Geometry/ForwardCommonData/python/%,%,$(wildcard $(foreach dir,src/Geometry/ForwardCommonData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryForwardCommonData_LOC_USE := self  
PyGeometryForwardCommonData_PACKAGE := self/src/Geometry/ForwardCommonData/python
ALL_PRODS += PyGeometryForwardCommonData
PyGeometryForwardCommonData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryForwardCommonData,src/Geometry/ForwardCommonData/python,src_Geometry_ForwardCommonData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryForwardCommonData,src/Geometry/ForwardCommonData/python))
endif
ALL_COMMONRULES += src_Geometry_ForwardCommonData_python
src_Geometry_ForwardCommonData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_ForwardCommonData_python,src/Geometry/ForwardCommonData/python,PYTHON))
ALL_COMMONRULES += src_Geometry_ForwardCommonData_test
src_Geometry_ForwardCommonData_test_parent := Geometry/ForwardCommonData
src_Geometry_ForwardCommonData_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_ForwardCommonData_test,src/Geometry/ForwardCommonData/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/ForwardSimData)
subdirs_src_Geometry_ForwardSimData := 
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemGeometry)
subdirs_src_Geometry_TotemGeometry := src_Geometry_TotemGeometry_interface src_Geometry_TotemGeometry_src src_Geometry_TotemGeometry_data
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRPAlignmentData)
subdirs_src_Geometry_TotemRPAlignmentData := src_Geometry_TotemRPAlignmentData_data
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/IOMC)
subdirs_src_IOMC = src_IOMC_FlatProtonLogKsiLogTGunMul src_IOMC_MultiParticleEtaEMC2 src_IOMC_FlatProtonLogKsiLogTGun src_IOMC_Elegent src_IOMC_FlatThetaXYGun src_IOMC_Phojet src_IOMC_MultiParticleGuns src_IOMC_SmearingGenerator src_IOMC_DPEProtons
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRPData)
subdirs_src_Geometry_TotemRPData := src_Geometry_TotemRPData_test src_Geometry_TotemRPData_python
ifeq ($(strip $(PyGeometryTotemRPData)),)
PyGeometryTotemRPData := self/src/Geometry/TotemRPData/python
src_Geometry_TotemRPData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/TotemRPData/python)
PyGeometryTotemRPData_files := $(patsubst src/Geometry/TotemRPData/python/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryTotemRPData_LOC_USE := self  
PyGeometryTotemRPData_PACKAGE := self/src/Geometry/TotemRPData/python
ALL_PRODS += PyGeometryTotemRPData
PyGeometryTotemRPData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryTotemRPData,src/Geometry/TotemRPData/python,src_Geometry_TotemRPData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryTotemRPData,src/Geometry/TotemRPData/python))
endif
ALL_COMMONRULES += src_Geometry_TotemRPData_python
src_Geometry_TotemRPData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPData_python,src/Geometry/TotemRPData/python,PYTHON))
ALL_COMMONRULES += src_Geometry_TotemRPData_test
src_Geometry_TotemRPData_test_parent := Geometry/TotemRPData
src_Geometry_TotemRPData_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPData_test,src/Geometry/TotemRPData/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRPDetTopology)
subdirs_src_Geometry_TotemRPDetTopology := src_Geometry_TotemRPDetTopology_interface src_Geometry_TotemRPDetTopology_src
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRPGeometryBuilder)
subdirs_src_Geometry_TotemRPGeometryBuilder := src_Geometry_TotemRPGeometryBuilder_interface src_Geometry_TotemRPGeometryBuilder_plugins src_Geometry_TotemRPGeometryBuilder_python src_Geometry_TotemRPGeometryBuilder_doc src_Geometry_TotemRPGeometryBuilder_src
ifeq ($(strip $(GeometryTotemRPGeometryBuilderPlugins)),)
GeometryTotemRPGeometryBuilderPlugins_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/Geometry/TotemRPGeometryBuilder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Geometry/TotemRPGeometryBuilder/plugins/$(file). Please fix src/Geometry/TotemRPGeometryBuilder/plugins/BuildFile.))))
GeometryTotemRPGeometryBuilderPlugins := self/src/Geometry/TotemRPGeometryBuilder/plugins
GeometryTotemRPGeometryBuilderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/Geometry/TotemRPGeometryBuilder/plugins/BuildFile
GeometryTotemRPGeometryBuilderPlugins_LOC_USE := self  SimDataFormats/GeneratorProducts DetectorDescription/Core Geometry/TotemRecords TotemAlignment/RPRecords DataFormats/DetId DataFormats/TotemRPDetId Geometry/TrackerNumberingBuilder Geometry/TotemRPGeometryBuilder clhep hepmc
GeometryTotemRPGeometryBuilderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GeometryTotemRPGeometryBuilderPlugins,GeometryTotemRPGeometryBuilderPlugins,$(SCRAMSTORENAME_LIB),src/Geometry/TotemRPGeometryBuilder/plugins))
GeometryTotemRPGeometryBuilderPlugins_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/plugins
ALL_PRODS += GeometryTotemRPGeometryBuilderPlugins
GeometryTotemRPGeometryBuilderPlugins_INIT_FUNC        += $$(eval $$(call Library,GeometryTotemRPGeometryBuilderPlugins,src/Geometry/TotemRPGeometryBuilder/plugins,src_Geometry_TotemRPGeometryBuilder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,GeometryTotemRPGeometryBuilderPlugins,src/Geometry/TotemRPGeometryBuilder/plugins))
endif
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_plugins
src_Geometry_TotemRPGeometryBuilder_plugins_parent := Geometry/TotemRPGeometryBuilder
src_Geometry_TotemRPGeometryBuilder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_plugins,src/Geometry/TotemRPGeometryBuilder/plugins,PLUGINS))
ifeq ($(strip $(PyGeometryTotemRPGeometryBuilder)),)
PyGeometryTotemRPGeometryBuilder := self/src/Geometry/TotemRPGeometryBuilder/python
src_Geometry_TotemRPGeometryBuilder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Geometry/TotemRPGeometryBuilder/python)
PyGeometryTotemRPGeometryBuilder_files := $(patsubst src/Geometry/TotemRPGeometryBuilder/python/%,%,$(wildcard $(foreach dir,src/Geometry/TotemRPGeometryBuilder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeometryTotemRPGeometryBuilder_LOC_USE := self  
PyGeometryTotemRPGeometryBuilder_PACKAGE := self/src/Geometry/TotemRPGeometryBuilder/python
ALL_PRODS += PyGeometryTotemRPGeometryBuilder
PyGeometryTotemRPGeometryBuilder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/python,src_Geometry_TotemRPGeometryBuilder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeometryTotemRPGeometryBuilder,src/Geometry/TotemRPGeometryBuilder/python))
endif
ALL_COMMONRULES += src_Geometry_TotemRPGeometryBuilder_python
src_Geometry_TotemRPGeometryBuilder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Geometry_TotemRPGeometryBuilder_python,src/Geometry/TotemRPGeometryBuilder/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRPOptics)
subdirs_src_Geometry_TotemRPOptics := src_Geometry_TotemRPOptics_data
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemRecords)
subdirs_src_Geometry_TotemRecords := src_Geometry_TotemRecords_src
ALL_PACKAGES += $(patsubst src/%,%,src/Geometry/TotemT2AlignmentDataFormats)
subdirs_src_Geometry_TotemT2AlignmentDataFormats := src_Geometry_TotemT2AlignmentDataFormats_src
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/DPEProtons)
subdirs_src_IOMC_DPEProtons := src_IOMC_DPEProtons_test src_IOMC_DPEProtons_interface src_IOMC_DPEProtons_plugins src_IOMC_DPEProtons_python src_IOMC_DPEProtons_src
ifeq ($(strip $(IOMCDPEProtonsPlugins)),)
IOMCDPEProtonsPlugins_files := $(patsubst src/IOMC/DPEProtons/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/DPEProtons/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/DPEProtons/plugins/$(file). Please fix src/IOMC/DPEProtons/plugins/BuildFile.))))
IOMCDPEProtonsPlugins := self/src/IOMC/DPEProtons/plugins
IOMCDPEProtonsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/DPEProtons/plugins/BuildFile
IOMCDPEProtonsPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCDPEProtonsPlugins_LOC_USE := self  IOMC/DPEProtons boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCDPEProtonsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCDPEProtonsPlugins,IOMCDPEProtonsPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/DPEProtons/plugins))
IOMCDPEProtonsPlugins_PACKAGE := self/src/IOMC/DPEProtons/plugins
ALL_PRODS += IOMCDPEProtonsPlugins
IOMCDPEProtonsPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCDPEProtonsPlugins,src/IOMC/DPEProtons/plugins,src_IOMC_DPEProtons_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCDPEProtonsPlugins,src/IOMC/DPEProtons/plugins))
endif
ALL_COMMONRULES += src_IOMC_DPEProtons_plugins
src_IOMC_DPEProtons_plugins_parent := IOMC/DPEProtons
src_IOMC_DPEProtons_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_plugins,src/IOMC/DPEProtons/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCDPEProtons)),)
PyIOMCDPEProtons := self/src/IOMC/DPEProtons/python
src_IOMC_DPEProtons_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/DPEProtons/python)
PyIOMCDPEProtons_files := $(patsubst src/IOMC/DPEProtons/python/%,%,$(wildcard $(foreach dir,src/IOMC/DPEProtons/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCDPEProtons_LOC_USE := self  
PyIOMCDPEProtons_PACKAGE := self/src/IOMC/DPEProtons/python
ALL_PRODS += PyIOMCDPEProtons
PyIOMCDPEProtons_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCDPEProtons,src/IOMC/DPEProtons/python,src_IOMC_DPEProtons_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCDPEProtons,src/IOMC/DPEProtons/python))
endif
ALL_COMMONRULES += src_IOMC_DPEProtons_python
src_IOMC_DPEProtons_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_python,src/IOMC/DPEProtons/python,PYTHON))
ALL_COMMONRULES += src_IOMC_DPEProtons_test
src_IOMC_DPEProtons_test_parent := IOMC/DPEProtons
src_IOMC_DPEProtons_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_DPEProtons_test,src/IOMC/DPEProtons/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/Elegent)
subdirs_src_IOMC_Elegent := src_IOMC_Elegent_test src_IOMC_Elegent_plugins src_IOMC_Elegent_python src_IOMC_Elegent_src src_IOMC_Elegent_bin src_IOMC_Elegent_elegent
ifeq ($(strip $(ElegentBDistributionSampler)),)
ElegentBDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentBDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentBDistributionSampler := self/src/IOMC/Elegent/bin
ElegentBDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentBDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentBDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentBDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentBDistributionSampler
ElegentBDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentBDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentBDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentSDistributionSampler)),)
ElegentSDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentSDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentSDistributionSampler := self/src/IOMC/Elegent/bin
ElegentSDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentSDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentSDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentSDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentSDistributionSampler
ElegentSDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentSDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentSDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentTDistributionSampler)),)
ElegentTDistributionSampler_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentTDistributionSampler.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentTDistributionSampler := self/src/IOMC/Elegent/bin
ElegentTDistributionSampler_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentTDistributionSampler_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentTDistributionSampler_LOC_USE := self  IOMC/Elegent
ElegentTDistributionSampler_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentTDistributionSampler
ElegentTDistributionSampler_INIT_FUNC        += $$(eval $$(call Binary,ElegentTDistributionSampler,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentTDistributionSampler,src/IOMC/Elegent/bin))
endif
ifeq ($(strip $(ElegentTest)),)
ElegentTest_files := $(patsubst src/IOMC/Elegent/bin/%,%,$(foreach file,ElegentTest.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/bin/$(file). Please fix src/IOMC/Elegent/bin/BuildFile.))))
ElegentTest := self/src/IOMC/Elegent/bin
ElegentTest_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/bin/BuildFile
ElegentTest_LOC_FLAGS_CXXFLAGS   := -O3 -g3 -I$(CMSSW_BASE)/src/IOMC/Elegent/elegent
ElegentTest_LOC_USE := self  IOMC/Elegent
ElegentTest_PACKAGE := self/src/IOMC/Elegent/bin
ALL_PRODS += ElegentTest
ElegentTest_INIT_FUNC        += $$(eval $$(call Binary,ElegentTest,src/IOMC/Elegent/bin,src_IOMC_Elegent_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ElegentTest,src/IOMC/Elegent/bin))
endif
ALL_COMMONRULES += src_IOMC_Elegent_bin
src_IOMC_Elegent_bin_parent := IOMC/Elegent
src_IOMC_Elegent_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_bin,src/IOMC/Elegent/bin,BINARY))
ifeq ($(strip $(IOMCElegentPlugins)),)
IOMCElegentPlugins_files := $(patsubst src/IOMC/Elegent/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/Elegent/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Elegent/plugins/$(file). Please fix src/IOMC/Elegent/plugins/BuildFile.))))
IOMCElegentPlugins := self/src/IOMC/Elegent/plugins
IOMCElegentPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Elegent/plugins/BuildFile
IOMCElegentPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3
IOMCElegentPlugins_LOC_USE := self  FWCore/Framework SimDataFormats/GeneratorProducts IOMC/Elegent hepmc root
IOMCElegentPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCElegentPlugins,IOMCElegentPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/Elegent/plugins))
IOMCElegentPlugins_PACKAGE := self/src/IOMC/Elegent/plugins
ALL_PRODS += IOMCElegentPlugins
IOMCElegentPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCElegentPlugins,src/IOMC/Elegent/plugins,src_IOMC_Elegent_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCElegentPlugins,src/IOMC/Elegent/plugins))
endif
ALL_COMMONRULES += src_IOMC_Elegent_plugins
src_IOMC_Elegent_plugins_parent := IOMC/Elegent
src_IOMC_Elegent_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_plugins,src/IOMC/Elegent/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCElegent)),)
PyIOMCElegent := self/src/IOMC/Elegent/python
src_IOMC_Elegent_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/Elegent/python)
PyIOMCElegent_files := $(patsubst src/IOMC/Elegent/python/%,%,$(wildcard $(foreach dir,src/IOMC/Elegent/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCElegent_LOC_USE := self  
PyIOMCElegent_PACKAGE := self/src/IOMC/Elegent/python
ALL_PRODS += PyIOMCElegent
PyIOMCElegent_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCElegent,src/IOMC/Elegent/python,src_IOMC_Elegent_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCElegent,src/IOMC/Elegent/python))
endif
ALL_COMMONRULES += src_IOMC_Elegent_python
src_IOMC_Elegent_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_python,src/IOMC/Elegent/python,PYTHON))
ALL_COMMONRULES += src_IOMC_Elegent_test
src_IOMC_Elegent_test_parent := IOMC/Elegent
src_IOMC_Elegent_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Elegent_test,src/IOMC/Elegent/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGun)
subdirs_src_IOMC_FlatProtonLogKsiLogTGun := src_IOMC_FlatProtonLogKsiLogTGun_test src_IOMC_FlatProtonLogKsiLogTGun_interface src_IOMC_FlatProtonLogKsiLogTGun_plugins src_IOMC_FlatProtonLogKsiLogTGun_python
ifeq ($(strip $(IOMCFlatProtonLogKsiLogTGunPlugins)),)
IOMCFlatProtonLogKsiLogTGunPlugins_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGun/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatProtonLogKsiLogTGun/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatProtonLogKsiLogTGun/plugins/$(file). Please fix src/IOMC/FlatProtonLogKsiLogTGun/plugins/BuildFile.))))
IOMCFlatProtonLogKsiLogTGunPlugins := self/src/IOMC/FlatProtonLogKsiLogTGun/plugins
IOMCFlatProtonLogKsiLogTGunPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatProtonLogKsiLogTGun/plugins/BuildFile
IOMCFlatProtonLogKsiLogTGunPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatProtonLogKsiLogTGunPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatProtonLogKsiLogTGunPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatProtonLogKsiLogTGunPlugins,IOMCFlatProtonLogKsiLogTGunPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatProtonLogKsiLogTGun/plugins))
IOMCFlatProtonLogKsiLogTGunPlugins_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGun/plugins
ALL_PRODS += IOMCFlatProtonLogKsiLogTGunPlugins
IOMCFlatProtonLogKsiLogTGunPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatProtonLogKsiLogTGunPlugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins,src_IOMC_FlatProtonLogKsiLogTGun_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatProtonLogKsiLogTGunPlugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_plugins
src_IOMC_FlatProtonLogKsiLogTGun_plugins_parent := IOMC/FlatProtonLogKsiLogTGun
src_IOMC_FlatProtonLogKsiLogTGun_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_plugins,src/IOMC/FlatProtonLogKsiLogTGun/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCFlatProtonLogKsiLogTGun)),)
PyIOMCFlatProtonLogKsiLogTGun := self/src/IOMC/FlatProtonLogKsiLogTGun/python
src_IOMC_FlatProtonLogKsiLogTGun_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGun/python)
PyIOMCFlatProtonLogKsiLogTGun_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGun/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatProtonLogKsiLogTGun/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatProtonLogKsiLogTGun_LOC_USE := self  
PyIOMCFlatProtonLogKsiLogTGun_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGun/python
ALL_PRODS += PyIOMCFlatProtonLogKsiLogTGun
PyIOMCFlatProtonLogKsiLogTGun_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatProtonLogKsiLogTGun,src/IOMC/FlatProtonLogKsiLogTGun/python,src_IOMC_FlatProtonLogKsiLogTGun_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatProtonLogKsiLogTGun,src/IOMC/FlatProtonLogKsiLogTGun/python))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_python
src_IOMC_FlatProtonLogKsiLogTGun_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_python,src/IOMC/FlatProtonLogKsiLogTGun/python,PYTHON))
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGun_test
src_IOMC_FlatProtonLogKsiLogTGun_test_parent := IOMC/FlatProtonLogKsiLogTGun
src_IOMC_FlatProtonLogKsiLogTGun_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGun_test,src/IOMC/FlatProtonLogKsiLogTGun/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGunMul)
subdirs_src_IOMC_FlatProtonLogKsiLogTGunMul := src_IOMC_FlatProtonLogKsiLogTGunMul_test src_IOMC_FlatProtonLogKsiLogTGunMul_interface src_IOMC_FlatProtonLogKsiLogTGunMul_plugins src_IOMC_FlatProtonLogKsiLogTGunMul_python
ifeq ($(strip $(IOMCFlatProtonLogKsiLogTGunMulPlugins)),)
IOMCFlatProtonLogKsiLogTGunMulPlugins_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/$(file). Please fix src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/BuildFile.))))
IOMCFlatProtonLogKsiLogTGunMulPlugins := self/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins
IOMCFlatProtonLogKsiLogTGunMulPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins/BuildFile
IOMCFlatProtonLogKsiLogTGunMulPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatProtonLogKsiLogTGunMulPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatProtonLogKsiLogTGunMulPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatProtonLogKsiLogTGunMulPlugins,IOMCFlatProtonLogKsiLogTGunMulPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatProtonLogKsiLogTGunMul/plugins))
IOMCFlatProtonLogKsiLogTGunMulPlugins_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGunMul/plugins
ALL_PRODS += IOMCFlatProtonLogKsiLogTGunMulPlugins
IOMCFlatProtonLogKsiLogTGunMulPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatProtonLogKsiLogTGunMulPlugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins,src_IOMC_FlatProtonLogKsiLogTGunMul_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatProtonLogKsiLogTGunMulPlugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGunMul_plugins
src_IOMC_FlatProtonLogKsiLogTGunMul_plugins_parent := IOMC/FlatProtonLogKsiLogTGunMul
src_IOMC_FlatProtonLogKsiLogTGunMul_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGunMul_plugins,src/IOMC/FlatProtonLogKsiLogTGunMul/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCFlatProtonLogKsiLogTGunMul)),)
PyIOMCFlatProtonLogKsiLogTGunMul := self/src/IOMC/FlatProtonLogKsiLogTGunMul/python
src_IOMC_FlatProtonLogKsiLogTGunMul_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatProtonLogKsiLogTGunMul/python)
PyIOMCFlatProtonLogKsiLogTGunMul_files := $(patsubst src/IOMC/FlatProtonLogKsiLogTGunMul/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatProtonLogKsiLogTGunMul/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatProtonLogKsiLogTGunMul_LOC_USE := self  
PyIOMCFlatProtonLogKsiLogTGunMul_PACKAGE := self/src/IOMC/FlatProtonLogKsiLogTGunMul/python
ALL_PRODS += PyIOMCFlatProtonLogKsiLogTGunMul
PyIOMCFlatProtonLogKsiLogTGunMul_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatProtonLogKsiLogTGunMul,src/IOMC/FlatProtonLogKsiLogTGunMul/python,src_IOMC_FlatProtonLogKsiLogTGunMul_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatProtonLogKsiLogTGunMul,src/IOMC/FlatProtonLogKsiLogTGunMul/python))
endif
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGunMul_python
src_IOMC_FlatProtonLogKsiLogTGunMul_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGunMul_python,src/IOMC/FlatProtonLogKsiLogTGunMul/python,PYTHON))
ALL_COMMONRULES += src_IOMC_FlatProtonLogKsiLogTGunMul_test
src_IOMC_FlatProtonLogKsiLogTGunMul_test_parent := IOMC/FlatProtonLogKsiLogTGunMul
src_IOMC_FlatProtonLogKsiLogTGunMul_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatProtonLogKsiLogTGunMul_test,src/IOMC/FlatProtonLogKsiLogTGunMul/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/FlatThetaXYGun)
subdirs_src_IOMC_FlatThetaXYGun := src_IOMC_FlatThetaXYGun_test src_IOMC_FlatThetaXYGun_plugins src_IOMC_FlatThetaXYGun_python
ifeq ($(strip $(IOMCFlatThetaXYGunPlugins)),)
IOMCFlatThetaXYGunPlugins_files := $(patsubst src/IOMC/FlatThetaXYGun/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/FlatThetaXYGun/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/FlatThetaXYGun/plugins/$(file). Please fix src/IOMC/FlatThetaXYGun/plugins/BuildFile.))))
IOMCFlatThetaXYGunPlugins := self/src/IOMC/FlatThetaXYGun/plugins
IOMCFlatThetaXYGunPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/FlatThetaXYGun/plugins/BuildFile
IOMCFlatThetaXYGunPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCFlatThetaXYGunPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep
IOMCFlatThetaXYGunPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCFlatThetaXYGunPlugins,IOMCFlatThetaXYGunPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/FlatThetaXYGun/plugins))
IOMCFlatThetaXYGunPlugins_PACKAGE := self/src/IOMC/FlatThetaXYGun/plugins
ALL_PRODS += IOMCFlatThetaXYGunPlugins
IOMCFlatThetaXYGunPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCFlatThetaXYGunPlugins,src/IOMC/FlatThetaXYGun/plugins,src_IOMC_FlatThetaXYGun_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCFlatThetaXYGunPlugins,src/IOMC/FlatThetaXYGun/plugins))
endif
ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_plugins
src_IOMC_FlatThetaXYGun_plugins_parent := IOMC/FlatThetaXYGun
src_IOMC_FlatThetaXYGun_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_plugins,src/IOMC/FlatThetaXYGun/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCFlatThetaXYGun)),)
PyIOMCFlatThetaXYGun := self/src/IOMC/FlatThetaXYGun/python
src_IOMC_FlatThetaXYGun_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/FlatThetaXYGun/python)
PyIOMCFlatThetaXYGun_files := $(patsubst src/IOMC/FlatThetaXYGun/python/%,%,$(wildcard $(foreach dir,src/IOMC/FlatThetaXYGun/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCFlatThetaXYGun_LOC_USE := self  
PyIOMCFlatThetaXYGun_PACKAGE := self/src/IOMC/FlatThetaXYGun/python
ALL_PRODS += PyIOMCFlatThetaXYGun
PyIOMCFlatThetaXYGun_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCFlatThetaXYGun,src/IOMC/FlatThetaXYGun/python,src_IOMC_FlatThetaXYGun_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCFlatThetaXYGun,src/IOMC/FlatThetaXYGun/python))
endif
ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_python
src_IOMC_FlatThetaXYGun_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_python,src/IOMC/FlatThetaXYGun/python,PYTHON))
ALL_COMMONRULES += src_IOMC_FlatThetaXYGun_test
src_IOMC_FlatThetaXYGun_test_parent := IOMC/FlatThetaXYGun
src_IOMC_FlatThetaXYGun_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_FlatThetaXYGun_test,src/IOMC/FlatThetaXYGun/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/SimG4CMS)
subdirs_src_SimG4CMS = src_SimG4CMS_Forward src_SimG4CMS_TotemRP src_SimG4CMS_TotemRPProtTranspPar
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/MultiParticleEtaEMC2)
subdirs_src_IOMC_MultiParticleEtaEMC2 := src_IOMC_MultiParticleEtaEMC2_test src_IOMC_MultiParticleEtaEMC2_plugins src_IOMC_MultiParticleEtaEMC2_data
ifeq ($(strip $(IOMCMultiParticleEtaEMC2Plugins)),)
IOMCMultiParticleEtaEMC2Plugins_files := $(patsubst src/IOMC/MultiParticleEtaEMC2/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/MultiParticleEtaEMC2/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/MultiParticleEtaEMC2/plugins/$(file). Please fix src/IOMC/MultiParticleEtaEMC2/plugins/BuildFile.))))
IOMCMultiParticleEtaEMC2Plugins := self/src/IOMC/MultiParticleEtaEMC2/plugins
IOMCMultiParticleEtaEMC2Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/MultiParticleEtaEMC2/plugins/BuildFile
IOMCMultiParticleEtaEMC2Plugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCMultiParticleEtaEMC2Plugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord clhep hepmc heppdt
IOMCMultiParticleEtaEMC2Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCMultiParticleEtaEMC2Plugins,IOMCMultiParticleEtaEMC2Plugins,$(SCRAMSTORENAME_LIB),src/IOMC/MultiParticleEtaEMC2/plugins))
IOMCMultiParticleEtaEMC2Plugins_PACKAGE := self/src/IOMC/MultiParticleEtaEMC2/plugins
ALL_PRODS += IOMCMultiParticleEtaEMC2Plugins
IOMCMultiParticleEtaEMC2Plugins_INIT_FUNC        += $$(eval $$(call Library,IOMCMultiParticleEtaEMC2Plugins,src/IOMC/MultiParticleEtaEMC2/plugins,src_IOMC_MultiParticleEtaEMC2_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCMultiParticleEtaEMC2Plugins,src/IOMC/MultiParticleEtaEMC2/plugins))
endif
ALL_COMMONRULES += src_IOMC_MultiParticleEtaEMC2_plugins
src_IOMC_MultiParticleEtaEMC2_plugins_parent := IOMC/MultiParticleEtaEMC2
src_IOMC_MultiParticleEtaEMC2_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleEtaEMC2_plugins,src/IOMC/MultiParticleEtaEMC2/plugins,PLUGINS))
ALL_COMMONRULES += src_IOMC_MultiParticleEtaEMC2_test
src_IOMC_MultiParticleEtaEMC2_test_parent := IOMC/MultiParticleEtaEMC2
src_IOMC_MultiParticleEtaEMC2_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleEtaEMC2_test,src/IOMC/MultiParticleEtaEMC2/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/MultiParticleGuns)
subdirs_src_IOMC_MultiParticleGuns := src_IOMC_MultiParticleGuns_test src_IOMC_MultiParticleGuns_plugins
ifeq ($(strip $(IOMCMultiParticleGunsPlugins)),)
IOMCMultiParticleGunsPlugins_files := $(patsubst src/IOMC/MultiParticleGuns/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/MultiParticleGuns/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/MultiParticleGuns/plugins/$(file). Please fix src/IOMC/MultiParticleGuns/plugins/BuildFile.))))
IOMCMultiParticleGunsPlugins := self/src/IOMC/MultiParticleGuns/plugins
IOMCMultiParticleGunsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/MultiParticleGuns/plugins/BuildFile
IOMCMultiParticleGunsPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCMultiParticleGunsPlugins_LOC_USE := self  boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord clhep hepmc heppdt
IOMCMultiParticleGunsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCMultiParticleGunsPlugins,IOMCMultiParticleGunsPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/MultiParticleGuns/plugins))
IOMCMultiParticleGunsPlugins_PACKAGE := self/src/IOMC/MultiParticleGuns/plugins
ALL_PRODS += IOMCMultiParticleGunsPlugins
IOMCMultiParticleGunsPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCMultiParticleGunsPlugins,src/IOMC/MultiParticleGuns/plugins,src_IOMC_MultiParticleGuns_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCMultiParticleGunsPlugins,src/IOMC/MultiParticleGuns/plugins))
endif
ALL_COMMONRULES += src_IOMC_MultiParticleGuns_plugins
src_IOMC_MultiParticleGuns_plugins_parent := IOMC/MultiParticleGuns
src_IOMC_MultiParticleGuns_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleGuns_plugins,src/IOMC/MultiParticleGuns/plugins,PLUGINS))
ALL_COMMONRULES += src_IOMC_MultiParticleGuns_test
src_IOMC_MultiParticleGuns_test_parent := IOMC/MultiParticleGuns
src_IOMC_MultiParticleGuns_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_MultiParticleGuns_test,src/IOMC/MultiParticleGuns/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/Phojet)
subdirs_src_IOMC_Phojet := src_IOMC_Phojet_test src_IOMC_Phojet_interface src_IOMC_Phojet_plugins src_IOMC_Phojet_python src_IOMC_Phojet_src src_IOMC_Phojet_data
ifeq ($(strip $(IOMCPhojetPlugins)),)
IOMCPhojetPlugins_files := $(patsubst src/IOMC/Phojet/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/Phojet/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/Phojet/plugins/$(file). Please fix src/IOMC/Phojet/plugins/BuildFile.))))
IOMCPhojetPlugins := self/src/IOMC/Phojet/plugins
IOMCPhojetPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/Phojet/plugins/BuildFile
IOMCPhojetPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCPhojetPlugins_LOC_USE := self  IOMC/Phojet boost FWCore/Framework SimDataFormats/GeneratorProducts SimGeneral/HepPDTRecord hepmc clhep root
IOMCPhojetPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCPhojetPlugins,IOMCPhojetPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/Phojet/plugins))
IOMCPhojetPlugins_PACKAGE := self/src/IOMC/Phojet/plugins
ALL_PRODS += IOMCPhojetPlugins
IOMCPhojetPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCPhojetPlugins,src/IOMC/Phojet/plugins,src_IOMC_Phojet_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCPhojetPlugins,src/IOMC/Phojet/plugins))
endif
ALL_COMMONRULES += src_IOMC_Phojet_plugins
src_IOMC_Phojet_plugins_parent := IOMC/Phojet
src_IOMC_Phojet_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_plugins,src/IOMC/Phojet/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCPhojet)),)
PyIOMCPhojet := self/src/IOMC/Phojet/python
src_IOMC_Phojet_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/Phojet/python)
PyIOMCPhojet_files := $(patsubst src/IOMC/Phojet/python/%,%,$(wildcard $(foreach dir,src/IOMC/Phojet/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCPhojet_LOC_USE := self  
PyIOMCPhojet_PACKAGE := self/src/IOMC/Phojet/python
ALL_PRODS += PyIOMCPhojet
PyIOMCPhojet_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCPhojet,src/IOMC/Phojet/python,src_IOMC_Phojet_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCPhojet,src/IOMC/Phojet/python))
endif
ALL_COMMONRULES += src_IOMC_Phojet_python
src_IOMC_Phojet_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_python,src/IOMC/Phojet/python,PYTHON))
ALL_COMMONRULES += src_IOMC_Phojet_test
src_IOMC_Phojet_test_parent := IOMC/Phojet
src_IOMC_Phojet_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_Phojet_test,src/IOMC/Phojet/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/IOMC/SmearingGenerator)
subdirs_src_IOMC_SmearingGenerator := src_IOMC_SmearingGenerator_test src_IOMC_SmearingGenerator_plugins src_IOMC_SmearingGenerator_python
ifeq ($(strip $(IOMCSmearingGeneratorPlugins)),)
IOMCSmearingGeneratorPlugins_files := $(patsubst src/IOMC/SmearingGenerator/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/IOMC/SmearingGenerator/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/IOMC/SmearingGenerator/plugins/$(file). Please fix src/IOMC/SmearingGenerator/plugins/BuildFile.))))
IOMCSmearingGeneratorPlugins := self/src/IOMC/SmearingGenerator/plugins
IOMCSmearingGeneratorPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/IOMC/SmearingGenerator/plugins/BuildFile
IOMCSmearingGeneratorPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
IOMCSmearingGeneratorPlugins_LOC_USE := self  FWCore/Framework SimDataFormats/GeneratorProducts hepmc root TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord clhep
IOMCSmearingGeneratorPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,IOMCSmearingGeneratorPlugins,IOMCSmearingGeneratorPlugins,$(SCRAMSTORENAME_LIB),src/IOMC/SmearingGenerator/plugins))
IOMCSmearingGeneratorPlugins_PACKAGE := self/src/IOMC/SmearingGenerator/plugins
ALL_PRODS += IOMCSmearingGeneratorPlugins
IOMCSmearingGeneratorPlugins_INIT_FUNC        += $$(eval $$(call Library,IOMCSmearingGeneratorPlugins,src/IOMC/SmearingGenerator/plugins,src_IOMC_SmearingGenerator_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,IOMCSmearingGeneratorPlugins,src/IOMC/SmearingGenerator/plugins))
endif
ALL_COMMONRULES += src_IOMC_SmearingGenerator_plugins
src_IOMC_SmearingGenerator_plugins_parent := IOMC/SmearingGenerator
src_IOMC_SmearingGenerator_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_plugins,src/IOMC/SmearingGenerator/plugins,PLUGINS))
ifeq ($(strip $(PyIOMCSmearingGenerator)),)
PyIOMCSmearingGenerator := self/src/IOMC/SmearingGenerator/python
src_IOMC_SmearingGenerator_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/IOMC/SmearingGenerator/python)
PyIOMCSmearingGenerator_files := $(patsubst src/IOMC/SmearingGenerator/python/%,%,$(wildcard $(foreach dir,src/IOMC/SmearingGenerator/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyIOMCSmearingGenerator_LOC_USE := self  
PyIOMCSmearingGenerator_PACKAGE := self/src/IOMC/SmearingGenerator/python
ALL_PRODS += PyIOMCSmearingGenerator
PyIOMCSmearingGenerator_INIT_FUNC        += $$(eval $$(call PythonProduct,PyIOMCSmearingGenerator,src/IOMC/SmearingGenerator/python,src_IOMC_SmearingGenerator_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyIOMCSmearingGenerator,src/IOMC/SmearingGenerator/python))
endif
ALL_COMMONRULES += src_IOMC_SmearingGenerator_python
src_IOMC_SmearingGenerator_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_python,src/IOMC/SmearingGenerator/python,PYTHON))
ALL_COMMONRULES += src_IOMC_SmearingGenerator_test
src_IOMC_SmearingGenerator_test_parent := IOMC/SmearingGenerator
src_IOMC_SmearingGenerator_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_IOMC_SmearingGenerator_test,src/IOMC/SmearingGenerator/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/L1TriggerTotem)
subdirs_src_L1TriggerTotem = src_L1TriggerTotem_CoincidenceChip
ALL_PACKAGES += $(patsubst src/%,%,src/L1TriggerTotem/CoincidenceChip)
subdirs_src_L1TriggerTotem_CoincidenceChip := src_L1TriggerTotem_CoincidenceChip_test src_L1TriggerTotem_CoincidenceChip_plugins src_L1TriggerTotem_CoincidenceChip_python src_L1TriggerTotem_CoincidenceChip_scripts src_L1TriggerTotem_CoincidenceChip_src
ifeq ($(strip $(L1TriggerTotemCoincidenceChipPlugins)),)
L1TriggerTotemCoincidenceChipPlugins_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/L1TriggerTotem/CoincidenceChip/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/L1TriggerTotem/CoincidenceChip/plugins/$(file). Please fix src/L1TriggerTotem/CoincidenceChip/plugins/BuildFile.))))
L1TriggerTotemCoincidenceChipPlugins := self/src/L1TriggerTotem/CoincidenceChip/plugins
L1TriggerTotemCoincidenceChipPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/L1TriggerTotem/CoincidenceChip/plugins/BuildFile
L1TriggerTotemCoincidenceChipPlugins_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet L1TriggerTotem/CoincidenceChip DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId DataFormats/TotemL1Trigger DataFormats/T2Digi DataFormats/T2DetId hepmc SimDataFormats/GeneratorProducts rootgraphics TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
L1TriggerTotemCoincidenceChipPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,L1TriggerTotemCoincidenceChipPlugins,L1TriggerTotemCoincidenceChipPlugins,$(SCRAMSTORENAME_LIB),src/L1TriggerTotem/CoincidenceChip/plugins))
L1TriggerTotemCoincidenceChipPlugins_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/plugins
ALL_PRODS += L1TriggerTotemCoincidenceChipPlugins
L1TriggerTotemCoincidenceChipPlugins_INIT_FUNC        += $$(eval $$(call Library,L1TriggerTotemCoincidenceChipPlugins,src/L1TriggerTotem/CoincidenceChip/plugins,src_L1TriggerTotem_CoincidenceChip_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,L1TriggerTotemCoincidenceChipPlugins,src/L1TriggerTotem/CoincidenceChip/plugins))
endif
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_plugins
src_L1TriggerTotem_CoincidenceChip_plugins_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_plugins,src/L1TriggerTotem/CoincidenceChip/plugins,PLUGINS))
ifeq ($(strip $(PyL1TriggerTotemCoincidenceChip)),)
PyL1TriggerTotemCoincidenceChip := self/src/L1TriggerTotem/CoincidenceChip/python
src_L1TriggerTotem_CoincidenceChip_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/L1TriggerTotem/CoincidenceChip/python)
PyL1TriggerTotemCoincidenceChip_files := $(patsubst src/L1TriggerTotem/CoincidenceChip/python/%,%,$(wildcard $(foreach dir,src/L1TriggerTotem/CoincidenceChip/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyL1TriggerTotemCoincidenceChip_LOC_USE := self  
PyL1TriggerTotemCoincidenceChip_PACKAGE := self/src/L1TriggerTotem/CoincidenceChip/python
ALL_PRODS += PyL1TriggerTotemCoincidenceChip
PyL1TriggerTotemCoincidenceChip_INIT_FUNC        += $$(eval $$(call PythonProduct,PyL1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/python,src_L1TriggerTotem_CoincidenceChip_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyL1TriggerTotemCoincidenceChip,src/L1TriggerTotem/CoincidenceChip/python))
endif
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_python
src_L1TriggerTotem_CoincidenceChip_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_python,src/L1TriggerTotem/CoincidenceChip/python,PYTHON))
src_L1TriggerTotem_CoincidenceChip_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/L1TriggerTotem/CoincidenceChip/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_L1TriggerTotem_CoincidenceChip_scripts,src/L1TriggerTotem/CoincidenceChip/scripts,$(SCRAMSTORENAME_BIN),*))
ALL_COMMONRULES += src_L1TriggerTotem_CoincidenceChip_test
src_L1TriggerTotem_CoincidenceChip_test_parent := L1TriggerTotem/CoincidenceChip
src_L1TriggerTotem_CoincidenceChip_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L1TriggerTotem_CoincidenceChip_test,src/L1TriggerTotem/CoincidenceChip/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/MergingSoftware)
subdirs_src_MergingSoftware = src_MergingSoftware_MergeCMSTOTEMNTuples
ALL_PACKAGES += $(patsubst src/%,%,src/MergingSoftware/MergeCMSTOTEMNTuples)
subdirs_src_MergingSoftware_MergeCMSTOTEMNTuples := src_MergingSoftware_MergeCMSTOTEMNTuples_CMSdataFormat
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/RecoTotemRP)
subdirs_src_RecoTotemRP = src_RecoTotemRP_RPInelasticReconstruction src_RecoTotemRP_RPRecoDataFormats src_RecoTotemRP_RPTrackCandidateFitter src_RecoTotemRP_RPNonParallelTrackCandidateFinder src_RecoTotemRP_RPServiceRecords src_RecoTotemRP_RPClusterSigmaService src_RecoTotemRP_RPDataReduction src_RecoTotemRP_RPElasticReconstruction src_RecoTotemRP_RPStationMultiTrackFinderFitter src_RecoTotemRP_RPTrackCandidateCollectionFitter src_RecoTotemRP_RPSingleCandidateTrackFinder src_RecoTotemRP_RPRecoHitProducer src_RecoTotemRP_RPDetectorMaskingService src_RecoTotemRP_RPRomanPotResolutionService src_RecoTotemRP_RPMulCandidateTrackFinder src_RecoTotemRP_RPMulTrackCandidateCollectionFitter src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer src_RecoTotemRP_RPInverseParameterization src_RecoTotemRP_RPClusterizer src_RecoTotemRP_CentralMCJetReconstruction
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/CentralMCJetReconstruction)
subdirs_src_RecoTotemRP_CentralMCJetReconstruction := src_RecoTotemRP_CentralMCJetReconstruction_plugins src_RecoTotemRP_CentralMCJetReconstruction_python src_RecoTotemRP_CentralMCJetReconstruction_src
ifeq ($(strip $(RecoTotemRPCentralMCJetReconstructionPlugins)),)
RecoTotemRPCentralMCJetReconstructionPlugins_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/CentralMCJetReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/CentralMCJetReconstruction/plugins/$(file). Please fix src/RecoTotemRP/CentralMCJetReconstruction/plugins/BuildFile.))))
RecoTotemRPCentralMCJetReconstructionPlugins := self/src/RecoTotemRP/CentralMCJetReconstruction/plugins
RecoTotemRPCentralMCJetReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/CentralMCJetReconstruction/plugins/BuildFile
RecoTotemRPCentralMCJetReconstructionPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry RecoTotemRP/CentralMCJetReconstruction
RecoTotemRPCentralMCJetReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPCentralMCJetReconstructionPlugins,RecoTotemRPCentralMCJetReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/CentralMCJetReconstruction/plugins))
RecoTotemRPCentralMCJetReconstructionPlugins_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/plugins
ALL_PRODS += RecoTotemRPCentralMCJetReconstructionPlugins
RecoTotemRPCentralMCJetReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPCentralMCJetReconstructionPlugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins,src_RecoTotemRP_CentralMCJetReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPCentralMCJetReconstructionPlugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_plugins
src_RecoTotemRP_CentralMCJetReconstruction_plugins_parent := RecoTotemRP/CentralMCJetReconstruction
src_RecoTotemRP_CentralMCJetReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_plugins,src/RecoTotemRP/CentralMCJetReconstruction/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPCentralMCJetReconstruction)),)
PyRecoTotemRPCentralMCJetReconstruction := self/src/RecoTotemRP/CentralMCJetReconstruction/python
src_RecoTotemRP_CentralMCJetReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/CentralMCJetReconstruction/python)
PyRecoTotemRPCentralMCJetReconstruction_files := $(patsubst src/RecoTotemRP/CentralMCJetReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/CentralMCJetReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPCentralMCJetReconstruction_LOC_USE := self  
PyRecoTotemRPCentralMCJetReconstruction_PACKAGE := self/src/RecoTotemRP/CentralMCJetReconstruction/python
ALL_PRODS += PyRecoTotemRPCentralMCJetReconstruction
PyRecoTotemRPCentralMCJetReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/python,src_RecoTotemRP_CentralMCJetReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPCentralMCJetReconstruction,src/RecoTotemRP/CentralMCJetReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_CentralMCJetReconstruction_python
src_RecoTotemRP_CentralMCJetReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_CentralMCJetReconstruction_python,src/RecoTotemRP/CentralMCJetReconstruction/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPClusterSigmaService)
subdirs_src_RecoTotemRP_RPClusterSigmaService := src_RecoTotemRP_RPClusterSigmaService_interface src_RecoTotemRP_RPClusterSigmaService_plugins src_RecoTotemRP_RPClusterSigmaService_python src_RecoTotemRP_RPClusterSigmaService_src
ifeq ($(strip $(RecoTotemRPRPClusterSigmaServicePlugins)),)
RecoTotemRPRPClusterSigmaServicePlugins_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPClusterSigmaService/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPClusterSigmaService/plugins/$(file). Please fix src/RecoTotemRP/RPClusterSigmaService/plugins/BuildFile.))))
RecoTotemRPRPClusterSigmaServicePlugins := self/src/RecoTotemRP/RPClusterSigmaService/plugins
RecoTotemRPRPClusterSigmaServicePlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterSigmaService/plugins/BuildFile
RecoTotemRPRPClusterSigmaServicePlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords CondCore/PluginSystem DetectorDescription/Core RecoTotemRP/RPClusterSigmaService
RecoTotemRPRPClusterSigmaServicePlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPClusterSigmaServicePlugins,RecoTotemRPRPClusterSigmaServicePlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPClusterSigmaService/plugins))
RecoTotemRPRPClusterSigmaServicePlugins_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/plugins
ALL_PRODS += RecoTotemRPRPClusterSigmaServicePlugins
RecoTotemRPRPClusterSigmaServicePlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterSigmaServicePlugins,src/RecoTotemRP/RPClusterSigmaService/plugins,src_RecoTotemRP_RPClusterSigmaService_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPClusterSigmaServicePlugins,src/RecoTotemRP/RPClusterSigmaService/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_plugins
src_RecoTotemRP_RPClusterSigmaService_plugins_parent := RecoTotemRP/RPClusterSigmaService
src_RecoTotemRP_RPClusterSigmaService_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_plugins,src/RecoTotemRP/RPClusterSigmaService/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPRPClusterSigmaService)),)
PyRecoTotemRPRPClusterSigmaService := self/src/RecoTotemRP/RPClusterSigmaService/python
src_RecoTotemRP_RPClusterSigmaService_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPClusterSigmaService/python)
PyRecoTotemRPRPClusterSigmaService_files := $(patsubst src/RecoTotemRP/RPClusterSigmaService/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterSigmaService/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPClusterSigmaService_LOC_USE := self  
PyRecoTotemRPRPClusterSigmaService_PACKAGE := self/src/RecoTotemRP/RPClusterSigmaService/python
ALL_PRODS += PyRecoTotemRPRPClusterSigmaService
PyRecoTotemRPRPClusterSigmaService_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/python,src_RecoTotemRP_RPClusterSigmaService_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPClusterSigmaService,src/RecoTotemRP/RPClusterSigmaService/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterSigmaService_python
src_RecoTotemRP_RPClusterSigmaService_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterSigmaService_python,src/RecoTotemRP/RPClusterSigmaService/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPClusterizer)
subdirs_src_RecoTotemRP_RPClusterizer := src_RecoTotemRP_RPClusterizer_test src_RecoTotemRP_RPClusterizer_interface src_RecoTotemRP_RPClusterizer_python src_RecoTotemRP_RPClusterizer_doc src_RecoTotemRP_RPClusterizer_src
ifeq ($(strip $(PyRecoTotemRPRPClusterizer)),)
PyRecoTotemRPRPClusterizer := self/src/RecoTotemRP/RPClusterizer/python
src_RecoTotemRP_RPClusterizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPClusterizer/python)
PyRecoTotemRPRPClusterizer_files := $(patsubst src/RecoTotemRP/RPClusterizer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPClusterizer_LOC_USE := self  
PyRecoTotemRPRPClusterizer_PACKAGE := self/src/RecoTotemRP/RPClusterizer/python
ALL_PRODS += PyRecoTotemRPRPClusterizer
PyRecoTotemRPRPClusterizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/python,src_RecoTotemRP_RPClusterizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_python
src_RecoTotemRP_RPClusterizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_python,src/RecoTotemRP/RPClusterizer/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPClusterizer)),)
ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_src
src_RecoTotemRP_RPClusterizer_src_parent := RecoTotemRP/RPClusterizer
src_RecoTotemRP_RPClusterizer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_src,src/RecoTotemRP/RPClusterizer/src,LIBRARY))
RecoTotemRPRPClusterizer := self/RecoTotemRP/RPClusterizer
RecoTotemRP/RPClusterizer := RecoTotemRPRPClusterizer
RecoTotemRPRPClusterizer_files := $(patsubst src/RecoTotemRP/RPClusterizer/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPClusterizer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPClusterizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPClusterizer/BuildFile
RecoTotemRPRPClusterizer_LOC_USE := self  FWCore/Framework FWCore/ParameterSet boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology SimDataFormats/TrackingHit
RecoTotemRPRPClusterizer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPClusterizer,RecoTotemRPRPClusterizer,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPClusterizer/src))
RecoTotemRPRPClusterizer_PACKAGE := self/src/RecoTotemRP/RPClusterizer/src
ALL_PRODS += RecoTotemRPRPClusterizer
RecoTotemRPRPClusterizer_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPClusterizer,src/RecoTotemRP/RPClusterizer/src,src_RecoTotemRP_RPClusterizer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPClusterizer_test
src_RecoTotemRP_RPClusterizer_test_parent := RecoTotemRP/RPClusterizer
src_RecoTotemRP_RPClusterizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPClusterizer_test,src/RecoTotemRP/RPClusterizer/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPDataReduction)
subdirs_src_RecoTotemRP_RPDataReduction := src_RecoTotemRP_RPDataReduction_test src_RecoTotemRP_RPDataReduction_interface src_RecoTotemRP_RPDataReduction_python src_RecoTotemRP_RPDataReduction_doc src_RecoTotemRP_RPDataReduction_src
ifeq ($(strip $(PyRecoTotemRPRPDataReduction)),)
PyRecoTotemRPRPDataReduction := self/src/RecoTotemRP/RPDataReduction/python
src_RecoTotemRP_RPDataReduction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPDataReduction/python)
PyRecoTotemRPRPDataReduction_files := $(patsubst src/RecoTotemRP/RPDataReduction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDataReduction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPDataReduction_LOC_USE := self  
PyRecoTotemRPRPDataReduction_PACKAGE := self/src/RecoTotemRP/RPDataReduction/python
ALL_PRODS += PyRecoTotemRPRPDataReduction
PyRecoTotemRPRPDataReduction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/python,src_RecoTotemRP_RPDataReduction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_python
src_RecoTotemRP_RPDataReduction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_python,src/RecoTotemRP/RPDataReduction/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPDataReduction)),)
ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_src
src_RecoTotemRP_RPDataReduction_src_parent := RecoTotemRP/RPDataReduction
src_RecoTotemRP_RPDataReduction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_src,src/RecoTotemRP/RPDataReduction/src,LIBRARY))
RecoTotemRPRPDataReduction := self/RecoTotemRP/RPDataReduction
RecoTotemRP/RPDataReduction := RecoTotemRPRPDataReduction
RecoTotemRPRPDataReduction_files := $(patsubst src/RecoTotemRP/RPDataReduction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPDataReduction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPDataReduction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPDataReduction/BuildFile
RecoTotemRPRPDataReduction_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats DataFormats/TotemRPDetId DataFormats/Common DataFormats/TotemL1Trigger DataFormats/T1T2Track DataFormats/T2Cluster DataFormats/T2Hit DataFormats/T1Road DataFormats/T2DetId TotemRawDataLibrary/DataFormats Geometry/TotemRecords Geometry/TotemRPGeometryBuilder Geometry/TotemRPDetTopology TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord root clhep rootgraphics boost
RecoTotemRPRPDataReduction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPDataReduction,RecoTotemRPRPDataReduction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPDataReduction/src))
RecoTotemRPRPDataReduction_PACKAGE := self/src/RecoTotemRP/RPDataReduction/src
ALL_PRODS += RecoTotemRPRPDataReduction
RecoTotemRPRPDataReduction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPDataReduction,src/RecoTotemRP/RPDataReduction/src,src_RecoTotemRP_RPDataReduction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPDataReduction_test
src_RecoTotemRP_RPDataReduction_test_parent := RecoTotemRP/RPDataReduction
src_RecoTotemRP_RPDataReduction_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPDataReduction_test,src/RecoTotemRP/RPDataReduction/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPDetectorMaskingService)
subdirs_src_RecoTotemRP_RPDetectorMaskingService := src_RecoTotemRP_RPDetectorMaskingService_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPElasticReconstruction)
subdirs_src_RecoTotemRP_RPElasticReconstruction := src_RecoTotemRP_RPElasticReconstruction_test src_RecoTotemRP_RPElasticReconstruction_plugins src_RecoTotemRP_RPElasticReconstruction_python
ifeq ($(strip $(RecoTotemRPRPElasticReconstructionPlugins)),)
RecoTotemRPRPElasticReconstructionPlugins_files := $(patsubst src/RecoTotemRP/RPElasticReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPElasticReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPElasticReconstruction/plugins/$(file). Please fix src/RecoTotemRP/RPElasticReconstruction/plugins/BuildFile.))))
RecoTotemRPRPElasticReconstructionPlugins := self/src/RecoTotemRP/RPElasticReconstruction/plugins
RecoTotemRPRPElasticReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPElasticReconstruction/plugins/BuildFile
RecoTotemRPRPElasticReconstructionPlugins_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord TotemRawDataLibrary/DataFormats
RecoTotemRPRPElasticReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPElasticReconstructionPlugins,RecoTotemRPRPElasticReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPElasticReconstruction/plugins))
RecoTotemRPRPElasticReconstructionPlugins_PACKAGE := self/src/RecoTotemRP/RPElasticReconstruction/plugins
ALL_PRODS += RecoTotemRPRPElasticReconstructionPlugins
RecoTotemRPRPElasticReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPElasticReconstructionPlugins,src/RecoTotemRP/RPElasticReconstruction/plugins,src_RecoTotemRP_RPElasticReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPElasticReconstructionPlugins,src/RecoTotemRP/RPElasticReconstruction/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPElasticReconstruction_plugins
src_RecoTotemRP_RPElasticReconstruction_plugins_parent := RecoTotemRP/RPElasticReconstruction
src_RecoTotemRP_RPElasticReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPElasticReconstruction_plugins,src/RecoTotemRP/RPElasticReconstruction/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPRPElasticReconstruction)),)
PyRecoTotemRPRPElasticReconstruction := self/src/RecoTotemRP/RPElasticReconstruction/python
src_RecoTotemRP_RPElasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPElasticReconstruction/python)
PyRecoTotemRPRPElasticReconstruction_files := $(patsubst src/RecoTotemRP/RPElasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPElasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPElasticReconstruction_LOC_USE := self  
PyRecoTotemRPRPElasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPElasticReconstruction/python
ALL_PRODS += PyRecoTotemRPRPElasticReconstruction
PyRecoTotemRPRPElasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPElasticReconstruction,src/RecoTotemRP/RPElasticReconstruction/python,src_RecoTotemRP_RPElasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPElasticReconstruction,src/RecoTotemRP/RPElasticReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPElasticReconstruction_python
src_RecoTotemRP_RPElasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPElasticReconstruction_python,src/RecoTotemRP/RPElasticReconstruction/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemRP_RPElasticReconstruction_test
src_RecoTotemRP_RPElasticReconstruction_test_parent := RecoTotemRP/RPElasticReconstruction
src_RecoTotemRP_RPElasticReconstruction_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPElasticReconstruction_test,src/RecoTotemRP/RPElasticReconstruction/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPInelasticReconstruction)
subdirs_src_RecoTotemRP_RPInelasticReconstruction := src_RecoTotemRP_RPInelasticReconstruction_test src_RecoTotemRP_RPInelasticReconstruction_interface src_RecoTotemRP_RPInelasticReconstruction_python src_RecoTotemRP_RPInelasticReconstruction_src
ifeq ($(strip $(PyRecoTotemRPRPInelasticReconstruction)),)
PyRecoTotemRPRPInelasticReconstruction := self/src/RecoTotemRP/RPInelasticReconstruction/python
src_RecoTotemRP_RPInelasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPInelasticReconstruction/python)
PyRecoTotemRPRPInelasticReconstruction_files := $(patsubst src/RecoTotemRP/RPInelasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInelasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPInelasticReconstruction_LOC_USE := self  
PyRecoTotemRPRPInelasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPInelasticReconstruction/python
ALL_PRODS += PyRecoTotemRPRPInelasticReconstruction
PyRecoTotemRPRPInelasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/python,src_RecoTotemRP_RPInelasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPInelasticReconstruction_python
src_RecoTotemRP_RPInelasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInelasticReconstruction_python,src/RecoTotemRP/RPInelasticReconstruction/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPInelasticReconstruction)),)
ALL_COMMONRULES += src_RecoTotemRP_RPInelasticReconstruction_src
src_RecoTotemRP_RPInelasticReconstruction_src_parent := RecoTotemRP/RPInelasticReconstruction
src_RecoTotemRP_RPInelasticReconstruction_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInelasticReconstruction_src,src/RecoTotemRP/RPInelasticReconstruction/src,LIBRARY))
RecoTotemRPRPInelasticReconstruction := self/RecoTotemRP/RPInelasticReconstruction
RecoTotemRP/RPInelasticReconstruction := RecoTotemRPRPInelasticReconstruction
RecoTotemRPRPInelasticReconstruction_files := $(patsubst src/RecoTotemRP/RPInelasticReconstruction/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPInelasticReconstruction/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPInelasticReconstruction_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPInelasticReconstruction/BuildFile
RecoTotemRPRPInelasticReconstruction_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter SimG4CMS/TotemRPProtTranspPar RecoTotemRP/RPInverseParameterization SimDataFormats/GeneratorProducts SimG4Core/Notification RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord rootminuit2
RecoTotemRPRPInelasticReconstruction_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPInelasticReconstruction,RecoTotemRPRPInelasticReconstruction,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPInelasticReconstruction/src))
RecoTotemRPRPInelasticReconstruction_PACKAGE := self/src/RecoTotemRP/RPInelasticReconstruction/src
ALL_PRODS += RecoTotemRPRPInelasticReconstruction
RecoTotemRPRPInelasticReconstruction_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPInelasticReconstruction,src/RecoTotemRP/RPInelasticReconstruction/src,src_RecoTotemRP_RPInelasticReconstruction_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPInelasticReconstruction_test
src_RecoTotemRP_RPInelasticReconstruction_test_parent := RecoTotemRP/RPInelasticReconstruction
src_RecoTotemRP_RPInelasticReconstruction_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPInelasticReconstruction_test,src/RecoTotemRP/RPInelasticReconstruction/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPInverseParameterization)
subdirs_src_RecoTotemRP_RPInverseParameterization := src_RecoTotemRP_RPInverseParameterization_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPMulCandidateTrackFinder)
subdirs_src_RecoTotemRP_RPMulCandidateTrackFinder := src_RecoTotemRP_RPMulCandidateTrackFinder_test src_RecoTotemRP_RPMulCandidateTrackFinder_interface src_RecoTotemRP_RPMulCandidateTrackFinder_python src_RecoTotemRP_RPMulCandidateTrackFinder_src
ifeq ($(strip $(PyRecoTotemRPRPMulCandidateTrackFinder)),)
PyRecoTotemRPRPMulCandidateTrackFinder := self/src/RecoTotemRP/RPMulCandidateTrackFinder/python
src_RecoTotemRP_RPMulCandidateTrackFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPMulCandidateTrackFinder/python)
PyRecoTotemRPRPMulCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPMulCandidateTrackFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulCandidateTrackFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPMulCandidateTrackFinder_LOC_USE := self  
PyRecoTotemRPRPMulCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPMulCandidateTrackFinder/python
ALL_PRODS += PyRecoTotemRPRPMulCandidateTrackFinder
PyRecoTotemRPRPMulCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/python,src_RecoTotemRP_RPMulCandidateTrackFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulCandidateTrackFinder_python
src_RecoTotemRP_RPMulCandidateTrackFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulCandidateTrackFinder_python,src/RecoTotemRP/RPMulCandidateTrackFinder/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPMulCandidateTrackFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPMulCandidateTrackFinder_src
src_RecoTotemRP_RPMulCandidateTrackFinder_src_parent := RecoTotemRP/RPMulCandidateTrackFinder
src_RecoTotemRP_RPMulCandidateTrackFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulCandidateTrackFinder_src,src/RecoTotemRP/RPMulCandidateTrackFinder/src,LIBRARY))
RecoTotemRPRPMulCandidateTrackFinder := self/RecoTotemRP/RPMulCandidateTrackFinder
RecoTotemRP/RPMulCandidateTrackFinder := RecoTotemRPRPMulCandidateTrackFinder
RecoTotemRPRPMulCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPMulCandidateTrackFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulCandidateTrackFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPMulCandidateTrackFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPMulCandidateTrackFinder/BuildFile
RecoTotemRPRPMulCandidateTrackFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost root rootgraphics DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId
RecoTotemRPRPMulCandidateTrackFinder_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPMulCandidateTrackFinder,RecoTotemRPRPMulCandidateTrackFinder,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPMulCandidateTrackFinder/src))
RecoTotemRPRPMulCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPMulCandidateTrackFinder/src
ALL_PRODS += RecoTotemRPRPMulCandidateTrackFinder
RecoTotemRPRPMulCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPMulCandidateTrackFinder,src/RecoTotemRP/RPMulCandidateTrackFinder/src,src_RecoTotemRP_RPMulCandidateTrackFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulCandidateTrackFinder_test
src_RecoTotemRP_RPMulCandidateTrackFinder_test_parent := RecoTotemRP/RPMulCandidateTrackFinder
src_RecoTotemRP_RPMulCandidateTrackFinder_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulCandidateTrackFinder_test,src/RecoTotemRP/RPMulCandidateTrackFinder/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter)
subdirs_src_RecoTotemRP_RPMulTrackCandidateCollectionFitter := src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_test src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_interface src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src
ifeq ($(strip $(PyRecoTotemRPRPMulTrackCandidateCollectionFitter)),)
PyRecoTotemRPRPMulTrackCandidateCollectionFitter := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python)
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_LOC_USE := self  
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python
ALL_PRODS += PyRecoTotemRPRPMulTrackCandidateCollectionFitter
PyRecoTotemRPRPMulTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_python,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPMulTrackCandidateCollectionFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src_parent := RecoTotemRP/RPMulTrackCandidateCollectionFitter
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src,LIBRARY))
RecoTotemRPRPMulTrackCandidateCollectionFitter := self/RecoTotemRP/RPMulTrackCandidateCollectionFitter
RecoTotemRP/RPMulTrackCandidateCollectionFitter := RecoTotemRPRPMulTrackCandidateCollectionFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPMulTrackCandidateCollectionFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/BuildFile
RecoTotemRPRPMulTrackCandidateCollectionFitter_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPMulTrackCandidateCollectionFitter,RecoTotemRPRPMulTrackCandidateCollectionFitter,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src))
RecoTotemRPRPMulTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src
ALL_PRODS += RecoTotemRPRPMulTrackCandidateCollectionFitter
RecoTotemRPRPMulTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPMulTrackCandidateCollectionFitter,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/src,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_test
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_test_parent := RecoTotemRP/RPMulTrackCandidateCollectionFitter
src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPMulTrackCandidateCollectionFitter_test,src/RecoTotemRP/RPMulTrackCandidateCollectionFitter/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/SimTotem)
subdirs_src_SimTotem = src_SimTotem_T1Digitizer src_SimTotem_T2Digitizer src_SimTotem_RPDigiProducer src_SimTotem_RPTimingDetectorsDigiProducer
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPNonParallelTrackCandidateFinder)
subdirs_src_RecoTotemRP_RPNonParallelTrackCandidateFinder := src_RecoTotemRP_RPNonParallelTrackCandidateFinder_test src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python src_RecoTotemRP_RPNonParallelTrackCandidateFinder_src
ifeq ($(strip $(RecoTotemRPRPNonParallelTrackCandidateFinderPlugins)),)
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/$(file). Please fix src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/BuildFile.))))
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins/BuildFile
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_LOC_USE := self  FWCore/Framework RecoTotemRP/RPNonParallelTrackCandidateFinder
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins))
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins
ALL_PRODS += RecoTotemRPRPNonParallelTrackCandidateFinderPlugins
RecoTotemRPRPNonParallelTrackCandidateFinderPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPNonParallelTrackCandidateFinderPlugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins_parent := RecoTotemRP/RPNonParallelTrackCandidateFinder
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_plugins,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPRPNonParallelTrackCandidateFinder)),)
PyRecoTotemRPRPNonParallelTrackCandidateFinder := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python)
PyRecoTotemRPRPNonParallelTrackCandidateFinder_files := $(patsubst src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPNonParallelTrackCandidateFinder_LOC_USE := self  
PyRecoTotemRPRPNonParallelTrackCandidateFinder_PACKAGE := self/src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python
ALL_PRODS += PyRecoTotemRPRPNonParallelTrackCandidateFinder
PyRecoTotemRPRPNonParallelTrackCandidateFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPNonParallelTrackCandidateFinder,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_python,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemRP_RPNonParallelTrackCandidateFinder_test
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_test_parent := RecoTotemRP/RPNonParallelTrackCandidateFinder
src_RecoTotemRP_RPNonParallelTrackCandidateFinder_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPNonParallelTrackCandidateFinder_test,src/RecoTotemRP/RPNonParallelTrackCandidateFinder/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPRecoDataFormats)
subdirs_src_RecoTotemRP_RPRecoDataFormats := src_RecoTotemRP_RPRecoDataFormats_interface src_RecoTotemRP_RPRecoDataFormats_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPRecoHitProducer)
subdirs_src_RecoTotemRP_RPRecoHitProducer := src_RecoTotemRP_RPRecoHitProducer_test src_RecoTotemRP_RPRecoHitProducer_python src_RecoTotemRP_RPRecoHitProducer_src
ifeq ($(strip $(PyRecoTotemRPRPRecoHitProducer)),)
PyRecoTotemRPRPRecoHitProducer := self/src/RecoTotemRP/RPRecoHitProducer/python
src_RecoTotemRP_RPRecoHitProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPRecoHitProducer/python)
PyRecoTotemRPRPRecoHitProducer_files := $(patsubst src/RecoTotemRP/RPRecoHitProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoHitProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPRecoHitProducer_LOC_USE := self  
PyRecoTotemRPRPRecoHitProducer_PACKAGE := self/src/RecoTotemRP/RPRecoHitProducer/python
ALL_PRODS += PyRecoTotemRPRPRecoHitProducer
PyRecoTotemRPRPRecoHitProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/python,src_RecoTotemRP_RPRecoHitProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_python
src_RecoTotemRP_RPRecoHitProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_python,src/RecoTotemRP/RPRecoHitProducer/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPRecoHitProducer)),)
ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_src
src_RecoTotemRP_RPRecoHitProducer_src_parent := RecoTotemRP/RPRecoHitProducer
src_RecoTotemRP_RPRecoHitProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_src,src/RecoTotemRP/RPRecoHitProducer/src,LIBRARY))
RecoTotemRPRPRecoHitProducer := self/RecoTotemRP/RPRecoHitProducer
RecoTotemRP/RPRecoHitProducer := RecoTotemRPRPRecoHitProducer
RecoTotemRPRPRecoHitProducer_files := $(patsubst src/RecoTotemRP/RPRecoHitProducer/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPRecoHitProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPRecoHitProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPRecoHitProducer/BuildFile
RecoTotemRPRPRecoHitProducer_LOC_USE := self  clhep FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common RecoTotemRP/RPClusterSigmaService Geometry/TotemRPDetTopology DataFormats/TotemRPDataTypes RecoTotemRP/RPServiceRecords boost root rootrflx
RecoTotemRPRPRecoHitProducer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPRecoHitProducer,RecoTotemRPRPRecoHitProducer,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPRecoHitProducer/src))
RecoTotemRPRPRecoHitProducer_PACKAGE := self/src/RecoTotemRP/RPRecoHitProducer/src
ALL_PRODS += RecoTotemRPRPRecoHitProducer
RecoTotemRPRPRecoHitProducer_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPRecoHitProducer,src/RecoTotemRP/RPRecoHitProducer/src,src_RecoTotemRP_RPRecoHitProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPRecoHitProducer_test
src_RecoTotemRP_RPRecoHitProducer_test_parent := RecoTotemRP/RPRecoHitProducer
src_RecoTotemRP_RPRecoHitProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPRecoHitProducer_test,src/RecoTotemRP/RPRecoHitProducer/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPRomanPotResolutionService)
subdirs_src_RecoTotemRP_RPRomanPotResolutionService := src_RecoTotemRP_RPRomanPotResolutionService_interface src_RecoTotemRP_RPRomanPotResolutionService_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPServiceRecords)
subdirs_src_RecoTotemRP_RPServiceRecords := src_RecoTotemRP_RPServiceRecords_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPSingleCandidateTrackFinder)
subdirs_src_RecoTotemRP_RPSingleCandidateTrackFinder := src_RecoTotemRP_RPSingleCandidateTrackFinder_test src_RecoTotemRP_RPSingleCandidateTrackFinder_interface src_RecoTotemRP_RPSingleCandidateTrackFinder_python src_RecoTotemRP_RPSingleCandidateTrackFinder_src
ifeq ($(strip $(PyRecoTotemRPRPSingleCandidateTrackFinder)),)
PyRecoTotemRPRPSingleCandidateTrackFinder := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/python
src_RecoTotemRP_RPSingleCandidateTrackFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPSingleCandidateTrackFinder/python)
PyRecoTotemRPRPSingleCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPSingleCandidateTrackFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPSingleCandidateTrackFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPSingleCandidateTrackFinder_LOC_USE := self  
PyRecoTotemRPRPSingleCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/python
ALL_PRODS += PyRecoTotemRPRPSingleCandidateTrackFinder
PyRecoTotemRPRPSingleCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/python,src_RecoTotemRP_RPSingleCandidateTrackFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPSingleCandidateTrackFinder_python
src_RecoTotemRP_RPSingleCandidateTrackFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPSingleCandidateTrackFinder_python,src/RecoTotemRP/RPSingleCandidateTrackFinder/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPSingleCandidateTrackFinder)),)
ALL_COMMONRULES += src_RecoTotemRP_RPSingleCandidateTrackFinder_src
src_RecoTotemRP_RPSingleCandidateTrackFinder_src_parent := RecoTotemRP/RPSingleCandidateTrackFinder
src_RecoTotemRP_RPSingleCandidateTrackFinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPSingleCandidateTrackFinder_src,src/RecoTotemRP/RPSingleCandidateTrackFinder/src,LIBRARY))
RecoTotemRPRPSingleCandidateTrackFinder := self/RecoTotemRP/RPSingleCandidateTrackFinder
RecoTotemRP/RPSingleCandidateTrackFinder := RecoTotemRPRPSingleCandidateTrackFinder
RecoTotemRPRPSingleCandidateTrackFinder_files := $(patsubst src/RecoTotemRP/RPSingleCandidateTrackFinder/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPSingleCandidateTrackFinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPSingleCandidateTrackFinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPSingleCandidateTrackFinder/BuildFile
RecoTotemRPRPSingleCandidateTrackFinder_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId
RecoTotemRPRPSingleCandidateTrackFinder_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPSingleCandidateTrackFinder,RecoTotemRPRPSingleCandidateTrackFinder,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPSingleCandidateTrackFinder/src))
RecoTotemRPRPSingleCandidateTrackFinder_PACKAGE := self/src/RecoTotemRP/RPSingleCandidateTrackFinder/src
ALL_PRODS += RecoTotemRPRPSingleCandidateTrackFinder
RecoTotemRPRPSingleCandidateTrackFinder_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPSingleCandidateTrackFinder,src/RecoTotemRP/RPSingleCandidateTrackFinder/src,src_RecoTotemRP_RPSingleCandidateTrackFinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPSingleCandidateTrackFinder_test
src_RecoTotemRP_RPSingleCandidateTrackFinder_test_parent := RecoTotemRP/RPSingleCandidateTrackFinder
src_RecoTotemRP_RPSingleCandidateTrackFinder_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPSingleCandidateTrackFinder_test,src/RecoTotemRP/RPSingleCandidateTrackFinder/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPStationMultiTrackFinderFitter)
subdirs_src_RecoTotemRP_RPStationMultiTrackFinderFitter := src_RecoTotemRP_RPStationMultiTrackFinderFitter_test src_RecoTotemRP_RPStationMultiTrackFinderFitter_interface src_RecoTotemRP_RPStationMultiTrackFinderFitter_utils src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins src_RecoTotemRP_RPStationMultiTrackFinderFitter_python src_RecoTotemRP_RPStationMultiTrackFinderFitter_doc src_RecoTotemRP_RPStationMultiTrackFinderFitter_src
ifeq ($(strip $(RecoTotemRPRPStationMultiTrackFinderFitterAuto)),)
RecoTotemRPRPStationMultiTrackFinderFitterAuto_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPStationMultiTrackFinderFitterAuto := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins
RecoTotemRPRPStationMultiTrackFinderFitterAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins/BuildFile
RecoTotemRPRPStationMultiTrackFinderFitterAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/Common DataFormats/TotemRPDataTypes RecoTotemRP/RPRecoDataFormats Geometry/TotemRPGeometryBuilder Geometry/TotemRecords RecoTotemRP/RPStationMultiTrackFinderFitter
RecoTotemRPRPStationMultiTrackFinderFitterAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPStationMultiTrackFinderFitterAuto,RecoTotemRPRPStationMultiTrackFinderFitterAuto,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins))
RecoTotemRPRPStationMultiTrackFinderFitterAuto_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins
ALL_PRODS += RecoTotemRPRPStationMultiTrackFinderFitterAuto
RecoTotemRPRPStationMultiTrackFinderFitterAuto_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPStationMultiTrackFinderFitterAuto,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins,src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPStationMultiTrackFinderFitterAuto,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins
src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins_parent := RecoTotemRP/RPStationMultiTrackFinderFitter
src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_plugins,src/RecoTotemRP/RPStationMultiTrackFinderFitter/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPRPStationMultiTrackFinderFitter)),)
PyRecoTotemRPRPStationMultiTrackFinderFitter := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/python
src_RecoTotemRP_RPStationMultiTrackFinderFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python)
PyRecoTotemRPRPStationMultiTrackFinderFitter_files := $(patsubst src/RecoTotemRP/RPStationMultiTrackFinderFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPStationMultiTrackFinderFitter_LOC_USE := self  
PyRecoTotemRPRPStationMultiTrackFinderFitter_PACKAGE := self/src/RecoTotemRP/RPStationMultiTrackFinderFitter/python
ALL_PRODS += PyRecoTotemRPRPStationMultiTrackFinderFitter
PyRecoTotemRPRPStationMultiTrackFinderFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python,src_RecoTotemRP_RPStationMultiTrackFinderFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPStationMultiTrackFinderFitter,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_python
src_RecoTotemRP_RPStationMultiTrackFinderFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_python,src/RecoTotemRP/RPStationMultiTrackFinderFitter/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemRP_RPStationMultiTrackFinderFitter_test
src_RecoTotemRP_RPStationMultiTrackFinderFitter_test_parent := RecoTotemRP/RPStationMultiTrackFinderFitter
src_RecoTotemRP_RPStationMultiTrackFinderFitter_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPStationMultiTrackFinderFitter_test,src/RecoTotemRP/RPStationMultiTrackFinderFitter/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer)
subdirs_src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer := src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_test src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_doc
ifeq ($(strip $(RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto)),)
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_files := $(patsubst src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins/BuildFile
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet SimTotem/RPTimingDetectorsDigiProducer
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins))
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_PACKAGE := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins
ALL_PRODS += RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto
RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemRPRPTimingDetectorsRecoHitsProducerAuto,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins_parent := RecoTotemRP/RPTimingDetectorsRecoHitsProducer
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_plugins,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemRPRPTimingDetectorsRecoHitsProducer)),)
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python)
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_files := $(patsubst src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_LOC_USE := self  
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_PACKAGE := self/src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python
ALL_PRODS += PyRecoTotemRPRPTimingDetectorsRecoHitsProducer
PyRecoTotemRPRPTimingDetectorsRecoHitsProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPTimingDetectorsRecoHitsProducer,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPTimingDetectorsRecoHitsProducer,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_python,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_test
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_test_parent := RecoTotemRP/RPTimingDetectorsRecoHitsProducer
src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTimingDetectorsRecoHitsProducer_test,src/RecoTotemRP/RPTimingDetectorsRecoHitsProducer/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPTrackCandidateFitter)
subdirs_src_RecoTotemRP_RPTrackCandidateFitter := src_RecoTotemRP_RPTrackCandidateFitter_interface src_RecoTotemRP_RPTrackCandidateFitter_src
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemRP/RPTrackCandidateCollectionFitter)
subdirs_src_RecoTotemRP_RPTrackCandidateCollectionFitter := src_RecoTotemRP_RPTrackCandidateCollectionFitter_python src_RecoTotemRP_RPTrackCandidateCollectionFitter_src
ifeq ($(strip $(PyRecoTotemRPRPTrackCandidateCollectionFitter)),)
PyRecoTotemRPRPTrackCandidateCollectionFitter := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/python
src_RecoTotemRP_RPTrackCandidateCollectionFitter_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python)
PyRecoTotemRPRPTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateCollectionFitter/python/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemRPRPTrackCandidateCollectionFitter_LOC_USE := self  
PyRecoTotemRPRPTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/python
ALL_PRODS += PyRecoTotemRPRPTrackCandidateCollectionFitter
PyRecoTotemRPRPTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python,src_RecoTotemRP_RPTrackCandidateCollectionFitter_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python))
endif
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateCollectionFitter_python
src_RecoTotemRP_RPTrackCandidateCollectionFitter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateCollectionFitter_python,src/RecoTotemRP/RPTrackCandidateCollectionFitter/python,PYTHON))
ifeq ($(strip $(RecoTotemRP/RPTrackCandidateCollectionFitter)),)
ALL_COMMONRULES += src_RecoTotemRP_RPTrackCandidateCollectionFitter_src
src_RecoTotemRP_RPTrackCandidateCollectionFitter_src_parent := RecoTotemRP/RPTrackCandidateCollectionFitter
src_RecoTotemRP_RPTrackCandidateCollectionFitter_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoTotemRP_RPTrackCandidateCollectionFitter_src,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src,LIBRARY))
RecoTotemRPRPTrackCandidateCollectionFitter := self/RecoTotemRP/RPTrackCandidateCollectionFitter
RecoTotemRP/RPTrackCandidateCollectionFitter := RecoTotemRPRPTrackCandidateCollectionFitter
RecoTotemRPRPTrackCandidateCollectionFitter_files := $(patsubst src/RecoTotemRP/RPTrackCandidateCollectionFitter/src/%,%,$(wildcard $(foreach dir,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoTotemRPRPTrackCandidateCollectionFitter_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemRP/RPTrackCandidateCollectionFitter/BuildFile
RecoTotemRPRPTrackCandidateCollectionFitter_LOC_USE := self  root FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common boost DataFormats/TotemRPDataTypes Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats clhep Geometry/TotemRecords DataFormats/TotemRPDetId RecoTotemRP/RPTrackCandidateFitter
RecoTotemRPRPTrackCandidateCollectionFitter_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemRPRPTrackCandidateCollectionFitter,RecoTotemRPRPTrackCandidateCollectionFitter,$(SCRAMSTORENAME_LIB),src/RecoTotemRP/RPTrackCandidateCollectionFitter/src))
RecoTotemRPRPTrackCandidateCollectionFitter_PACKAGE := self/src/RecoTotemRP/RPTrackCandidateCollectionFitter/src
ALL_PRODS += RecoTotemRPRPTrackCandidateCollectionFitter
RecoTotemRPRPTrackCandidateCollectionFitter_INIT_FUNC        += $$(eval $$(call Library,RecoTotemRPRPTrackCandidateCollectionFitter,src/RecoTotemRP/RPTrackCandidateCollectionFitter/src,src_RecoTotemRP_RPTrackCandidateCollectionFitter_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/RecoTotemT1T2)
subdirs_src_RecoTotemT1T2 = src_RecoTotemT1T2_T1TrackProducer2 src_RecoTotemT1T2_T2TrackProducer3 src_RecoTotemT1T2_T1RecHit src_RecoTotemT1T2_T1MakeCluster src_RecoTotemT1T2_T2RecHit src_RecoTotemT1T2_PrimaryVertexProducer src_RecoTotemT1T2_T2MakeCluster src_RecoTotemT1T2_T2RoadPadFinder src_RecoTotemT1T2_T1RoadProducer
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/PrimaryVertexProducer)
subdirs_src_RecoTotemT1T2_PrimaryVertexProducer := src_RecoTotemT1T2_PrimaryVertexProducer_plugins src_RecoTotemT1T2_PrimaryVertexProducer_python
ifeq ($(strip $(TotemRecoPrimaryVertexProducerPlugins)),)
TotemRecoPrimaryVertexProducerPlugins_files := $(patsubst src/RecoTotemT1T2/PrimaryVertexProducer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/PrimaryVertexProducer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/PrimaryVertexProducer/plugins/$(file). Please fix src/RecoTotemT1T2/PrimaryVertexProducer/plugins/BuildFile.))))
TotemRecoPrimaryVertexProducerPlugins := self/src/RecoTotemT1T2/PrimaryVertexProducer/plugins
TotemRecoPrimaryVertexProducerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/PrimaryVertexProducer/plugins/BuildFile
TotemRecoPrimaryVertexProducerPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet CommonTools/Clustering1D RecoVertex/VertexPrimitives RecoVertex/VertexTools boost root clhep
TotemRecoPrimaryVertexProducerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRecoPrimaryVertexProducerPlugins,TotemRecoPrimaryVertexProducerPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/PrimaryVertexProducer/plugins))
TotemRecoPrimaryVertexProducerPlugins_PACKAGE := self/src/RecoTotemT1T2/PrimaryVertexProducer/plugins
ALL_PRODS += TotemRecoPrimaryVertexProducerPlugins
TotemRecoPrimaryVertexProducerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRecoPrimaryVertexProducerPlugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins,src_RecoTotemT1T2_PrimaryVertexProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRecoPrimaryVertexProducerPlugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_PrimaryVertexProducer_plugins
src_RecoTotemT1T2_PrimaryVertexProducer_plugins_parent := RecoTotemT1T2/PrimaryVertexProducer
src_RecoTotemT1T2_PrimaryVertexProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_PrimaryVertexProducer_plugins,src/RecoTotemT1T2/PrimaryVertexProducer/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2PrimaryVertexProducer)),)
PyRecoTotemT1T2PrimaryVertexProducer := self/src/RecoTotemT1T2/PrimaryVertexProducer/python
src_RecoTotemT1T2_PrimaryVertexProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/PrimaryVertexProducer/python)
PyRecoTotemT1T2PrimaryVertexProducer_files := $(patsubst src/RecoTotemT1T2/PrimaryVertexProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/PrimaryVertexProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2PrimaryVertexProducer_LOC_USE := self  
PyRecoTotemT1T2PrimaryVertexProducer_PACKAGE := self/src/RecoTotemT1T2/PrimaryVertexProducer/python
ALL_PRODS += PyRecoTotemT1T2PrimaryVertexProducer
PyRecoTotemT1T2PrimaryVertexProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer/python,src_RecoTotemT1T2_PrimaryVertexProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2PrimaryVertexProducer,src/RecoTotemT1T2/PrimaryVertexProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_PrimaryVertexProducer_python
src_RecoTotemT1T2_PrimaryVertexProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_PrimaryVertexProducer_python,src/RecoTotemT1T2/PrimaryVertexProducer/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T1MakeCluster)
subdirs_src_RecoTotemT1T2_T1MakeCluster := src_RecoTotemT1T2_T1MakeCluster_plugins src_RecoTotemT1T2_T1MakeCluster_python
ifeq ($(strip $(RecoTotemT1T2T1MakeClusterPlugins)),)
RecoTotemT1T2T1MakeClusterPlugins_files := $(patsubst src/RecoTotemT1T2/T1MakeCluster/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1MakeCluster/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1MakeCluster/plugins/$(file). Please fix src/RecoTotemT1T2/T1MakeCluster/plugins/BuildFile.))))
RecoTotemT1T2T1MakeClusterPlugins := self/src/RecoTotemT1T2/T1MakeCluster/plugins
RecoTotemT1T2T1MakeClusterPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1MakeCluster/plugins/BuildFile
RecoTotemT1T2T1MakeClusterPlugins_LOC_USE := self  DataFormats/Common FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger Geometry/TotemRecords DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1Cluster Geometry/TotemGeometry TotemRawDataLibrary/DataFormats SimTotem/T1Digitizer boost root
RecoTotemT1T2T1MakeClusterPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1MakeClusterPlugins,RecoTotemT1T2T1MakeClusterPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1MakeCluster/plugins))
RecoTotemT1T2T1MakeClusterPlugins_PACKAGE := self/src/RecoTotemT1T2/T1MakeCluster/plugins
ALL_PRODS += RecoTotemT1T2T1MakeClusterPlugins
RecoTotemT1T2T1MakeClusterPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1MakeClusterPlugins,src/RecoTotemT1T2/T1MakeCluster/plugins,src_RecoTotemT1T2_T1MakeCluster_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1MakeClusterPlugins,src/RecoTotemT1T2/T1MakeCluster/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1MakeCluster_plugins
src_RecoTotemT1T2_T1MakeCluster_plugins_parent := RecoTotemT1T2/T1MakeCluster
src_RecoTotemT1T2_T1MakeCluster_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1MakeCluster_plugins,src/RecoTotemT1T2/T1MakeCluster/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T1MakeCluster)),)
PyRecoTotemT1T2T1MakeCluster := self/src/RecoTotemT1T2/T1MakeCluster/python
src_RecoTotemT1T2_T1MakeCluster_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1MakeCluster/python)
PyRecoTotemT1T2T1MakeCluster_files := $(patsubst src/RecoTotemT1T2/T1MakeCluster/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1MakeCluster/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1MakeCluster_LOC_USE := self  
PyRecoTotemT1T2T1MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T1MakeCluster/python
ALL_PRODS += PyRecoTotemT1T2T1MakeCluster
PyRecoTotemT1T2T1MakeCluster_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster/python,src_RecoTotemT1T2_T1MakeCluster_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1MakeCluster,src/RecoTotemT1T2/T1MakeCluster/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1MakeCluster_python
src_RecoTotemT1T2_T1MakeCluster_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1MakeCluster_python,src/RecoTotemT1T2/T1MakeCluster/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T1RecHit)
subdirs_src_RecoTotemT1T2_T1RecHit := src_RecoTotemT1T2_T1RecHit_test src_RecoTotemT1T2_T1RecHit_interface src_RecoTotemT1T2_T1RecHit_plugins src_RecoTotemT1T2_T1RecHit_python
ifeq ($(strip $(RecoTotemT1T2T1RecHitPlugins)),)
RecoTotemT1T2T1RecHitPlugins_files := $(patsubst src/RecoTotemT1T2/T1RecHit/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1RecHit/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1RecHit/plugins/$(file). Please fix src/RecoTotemT1T2/T1RecHit/plugins/BuildFile.))))
RecoTotemT1T2T1RecHitPlugins := self/src/RecoTotemT1T2/T1RecHit/plugins
RecoTotemT1T2T1RecHitPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RecHit/plugins/BuildFile
RecoTotemT1T2T1RecHitPlugins_LOC_USE := self  root FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/T1Cluster DataFormats/Common DataFormats/GeometryVector Geometry/TotemGeometry FWCore/ParameterSet boost
RecoTotemT1T2T1RecHitPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1RecHitPlugins,RecoTotemT1T2T1RecHitPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1RecHit/plugins))
RecoTotemT1T2T1RecHitPlugins_PACKAGE := self/src/RecoTotemT1T2/T1RecHit/plugins
ALL_PRODS += RecoTotemT1T2T1RecHitPlugins
RecoTotemT1T2T1RecHitPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1RecHitPlugins,src/RecoTotemT1T2/T1RecHit/plugins,src_RecoTotemT1T2_T1RecHit_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1RecHitPlugins,src/RecoTotemT1T2/T1RecHit/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RecHit_plugins
src_RecoTotemT1T2_T1RecHit_plugins_parent := RecoTotemT1T2/T1RecHit
src_RecoTotemT1T2_T1RecHit_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RecHit_plugins,src/RecoTotemT1T2/T1RecHit/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T1RecHit)),)
PyRecoTotemT1T2T1RecHit := self/src/RecoTotemT1T2/T1RecHit/python
src_RecoTotemT1T2_T1RecHit_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1RecHit/python)
PyRecoTotemT1T2T1RecHit_files := $(patsubst src/RecoTotemT1T2/T1RecHit/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1RecHit/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1RecHit_LOC_USE := self  
PyRecoTotemT1T2T1RecHit_PACKAGE := self/src/RecoTotemT1T2/T1RecHit/python
ALL_PRODS += PyRecoTotemT1T2T1RecHit
PyRecoTotemT1T2T1RecHit_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1RecHit,src/RecoTotemT1T2/T1RecHit/python,src_RecoTotemT1T2_T1RecHit_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1RecHit,src/RecoTotemT1T2/T1RecHit/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RecHit_python
src_RecoTotemT1T2_T1RecHit_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RecHit_python,src/RecoTotemT1T2/T1RecHit/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemT1T2_T1RecHit_test
src_RecoTotemT1T2_T1RecHit_test_parent := RecoTotemT1T2/T1RecHit
src_RecoTotemT1T2_T1RecHit_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RecHit_test,src/RecoTotemT1T2/T1RecHit/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T1RoadProducer)
subdirs_src_RecoTotemT1T2_T1RoadProducer := src_RecoTotemT1T2_T1RoadProducer_plugins src_RecoTotemT1T2_T1RoadProducer_python
ifeq ($(strip $(RecoTotemT1T2T1RoadProducerPlugins)),)
RecoTotemT1T2T1RoadProducerPlugins_files := $(patsubst src/RecoTotemT1T2/T1RoadProducer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1RoadProducer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1RoadProducer/plugins/$(file). Please fix src/RecoTotemT1T2/T1RoadProducer/plugins/BuildFile.))))
RecoTotemT1T2T1RoadProducerPlugins := self/src/RecoTotemT1T2/T1RoadProducer/plugins
RecoTotemT1T2T1RoadProducerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1RoadProducer/plugins/BuildFile
RecoTotemT1T2T1RoadProducerPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1DigiWire DataFormats/T1Cluster DataFormats/T1Road DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet boost root
RecoTotemT1T2T1RoadProducerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1RoadProducerPlugins,RecoTotemT1T2T1RoadProducerPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1RoadProducer/plugins))
RecoTotemT1T2T1RoadProducerPlugins_PACKAGE := self/src/RecoTotemT1T2/T1RoadProducer/plugins
ALL_PRODS += RecoTotemT1T2T1RoadProducerPlugins
RecoTotemT1T2T1RoadProducerPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1RoadProducerPlugins,src/RecoTotemT1T2/T1RoadProducer/plugins,src_RecoTotemT1T2_T1RoadProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1RoadProducerPlugins,src/RecoTotemT1T2/T1RoadProducer/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RoadProducer_plugins
src_RecoTotemT1T2_T1RoadProducer_plugins_parent := RecoTotemT1T2/T1RoadProducer
src_RecoTotemT1T2_T1RoadProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RoadProducer_plugins,src/RecoTotemT1T2/T1RoadProducer/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T1RoadProducer)),)
PyRecoTotemT1T2T1RoadProducer := self/src/RecoTotemT1T2/T1RoadProducer/python
src_RecoTotemT1T2_T1RoadProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1RoadProducer/python)
PyRecoTotemT1T2T1RoadProducer_files := $(patsubst src/RecoTotemT1T2/T1RoadProducer/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1RoadProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1RoadProducer_LOC_USE := self  
PyRecoTotemT1T2T1RoadProducer_PACKAGE := self/src/RecoTotemT1T2/T1RoadProducer/python
ALL_PRODS += PyRecoTotemT1T2T1RoadProducer
PyRecoTotemT1T2T1RoadProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer/python,src_RecoTotemT1T2_T1RoadProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1RoadProducer,src/RecoTotemT1T2/T1RoadProducer/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1RoadProducer_python
src_RecoTotemT1T2_T1RoadProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1RoadProducer_python,src/RecoTotemT1T2/T1RoadProducer/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T1TrackProducer2)
subdirs_src_RecoTotemT1T2_T1TrackProducer2 := src_RecoTotemT1T2_T1TrackProducer2_test src_RecoTotemT1T2_T1TrackProducer2_interface src_RecoTotemT1T2_T1TrackProducer2_plugins src_RecoTotemT1T2_T1TrackProducer2_python
ifeq ($(strip $(RecoTotemT1T2T1TrackProducer2Plugins)),)
RecoTotemT1T2T1TrackProducer2Plugins_files := $(patsubst src/RecoTotemT1T2/T1TrackProducer2/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T1TrackProducer2/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T1TrackProducer2/plugins/$(file). Please fix src/RecoTotemT1T2/T1TrackProducer2/plugins/BuildFile.))))
RecoTotemT1T2T1TrackProducer2Plugins := self/src/RecoTotemT1T2/T1TrackProducer2/plugins
RecoTotemT1T2T1TrackProducer2Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T1TrackProducer2/plugins/BuildFile
RecoTotemT1T2T1TrackProducer2Plugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/T1Road DataFormats/Common SimDataFormats/Track Geometry/TotemGeometry FWCore/ParameterSet CommonTools/Clustering1D RecoVertex/VertexPrimitives RecoVertex/VertexTools boost root clhep
RecoTotemT1T2T1TrackProducer2Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T1TrackProducer2Plugins,RecoTotemT1T2T1TrackProducer2Plugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T1TrackProducer2/plugins))
RecoTotemT1T2T1TrackProducer2Plugins_PACKAGE := self/src/RecoTotemT1T2/T1TrackProducer2/plugins
ALL_PRODS += RecoTotemT1T2T1TrackProducer2Plugins
RecoTotemT1T2T1TrackProducer2Plugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T1TrackProducer2Plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins,src_RecoTotemT1T2_T1TrackProducer2_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T1TrackProducer2Plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1TrackProducer2_plugins
src_RecoTotemT1T2_T1TrackProducer2_plugins_parent := RecoTotemT1T2/T1TrackProducer2
src_RecoTotemT1T2_T1TrackProducer2_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1TrackProducer2_plugins,src/RecoTotemT1T2/T1TrackProducer2/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T1TrackProducer2)),)
PyRecoTotemT1T2T1TrackProducer2 := self/src/RecoTotemT1T2/T1TrackProducer2/python
src_RecoTotemT1T2_T1TrackProducer2_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T1TrackProducer2/python)
PyRecoTotemT1T2T1TrackProducer2_files := $(patsubst src/RecoTotemT1T2/T1TrackProducer2/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T1TrackProducer2/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T1TrackProducer2_LOC_USE := self  
PyRecoTotemT1T2T1TrackProducer2_PACKAGE := self/src/RecoTotemT1T2/T1TrackProducer2/python
ALL_PRODS += PyRecoTotemT1T2T1TrackProducer2
PyRecoTotemT1T2T1TrackProducer2_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T1TrackProducer2,src/RecoTotemT1T2/T1TrackProducer2/python,src_RecoTotemT1T2_T1TrackProducer2_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T1TrackProducer2,src/RecoTotemT1T2/T1TrackProducer2/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T1TrackProducer2_python
src_RecoTotemT1T2_T1TrackProducer2_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1TrackProducer2_python,src/RecoTotemT1T2/T1TrackProducer2/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemT1T2_T1TrackProducer2_test
src_RecoTotemT1T2_T1TrackProducer2_test_parent := RecoTotemT1T2/T1TrackProducer2
src_RecoTotemT1T2_T1TrackProducer2_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T1TrackProducer2_test,src/RecoTotemT1T2/T1TrackProducer2/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T2MakeCluster)
subdirs_src_RecoTotemT1T2_T2MakeCluster := src_RecoTotemT1T2_T2MakeCluster_plugins src_RecoTotemT1T2_T2MakeCluster_python src_RecoTotemT1T2_T2MakeCluster_src
ifeq ($(strip $(RecoTotemT1T2T2MakeClusterPlugins)),)
RecoTotemT1T2T2MakeClusterPlugins_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2MakeCluster/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2MakeCluster/plugins/$(file). Please fix src/RecoTotemT1T2/T2MakeCluster/plugins/BuildFile.))))
RecoTotemT1T2T2MakeClusterPlugins := self/src/RecoTotemT1T2/T2MakeCluster/plugins
RecoTotemT1T2T2MakeClusterPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2MakeCluster/plugins/BuildFile
RecoTotemT1T2T2MakeClusterPlugins_LOC_USE := self  RecoTotemT1T2/T2MakeCluster FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId boost root clhep DataFormats/T2Cluster
RecoTotemT1T2T2MakeClusterPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2MakeClusterPlugins,RecoTotemT1T2T2MakeClusterPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2MakeCluster/plugins))
RecoTotemT1T2T2MakeClusterPlugins_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/plugins
ALL_PRODS += RecoTotemT1T2T2MakeClusterPlugins
RecoTotemT1T2T2MakeClusterPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2MakeClusterPlugins,src/RecoTotemT1T2/T2MakeCluster/plugins,src_RecoTotemT1T2_T2MakeCluster_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2MakeClusterPlugins,src/RecoTotemT1T2/T2MakeCluster/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_plugins
src_RecoTotemT1T2_T2MakeCluster_plugins_parent := RecoTotemT1T2/T2MakeCluster
src_RecoTotemT1T2_T2MakeCluster_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_plugins,src/RecoTotemT1T2/T2MakeCluster/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T2MakeCluster)),)
PyRecoTotemT1T2T2MakeCluster := self/src/RecoTotemT1T2/T2MakeCluster/python
src_RecoTotemT1T2_T2MakeCluster_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2MakeCluster/python)
PyRecoTotemT1T2T2MakeCluster_files := $(patsubst src/RecoTotemT1T2/T2MakeCluster/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2MakeCluster/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2MakeCluster_LOC_USE := self  
PyRecoTotemT1T2T2MakeCluster_PACKAGE := self/src/RecoTotemT1T2/T2MakeCluster/python
ALL_PRODS += PyRecoTotemT1T2T2MakeCluster
PyRecoTotemT1T2T2MakeCluster_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/python,src_RecoTotemT1T2_T2MakeCluster_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2MakeCluster,src/RecoTotemT1T2/T2MakeCluster/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2MakeCluster_python
src_RecoTotemT1T2_T2MakeCluster_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2MakeCluster_python,src/RecoTotemT1T2/T2MakeCluster/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T2RecHit)
subdirs_src_RecoTotemT1T2_T2RecHit := src_RecoTotemT1T2_T2RecHit_test src_RecoTotemT1T2_T2RecHit_interface src_RecoTotemT1T2_T2RecHit_plugins src_RecoTotemT1T2_T2RecHit_python src_RecoTotemT1T2_T2RecHit_src src_RecoTotemT1T2_T2RecHit_data
ifeq ($(strip $(RecoTotemT1T2T2RecHitPlugins)),)
RecoTotemT1T2T2RecHitPlugins_files := $(patsubst src/RecoTotemT1T2/T2RecHit/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2RecHit/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2RecHit/plugins/$(file). Please fix src/RecoTotemT1T2/T2RecHit/plugins/BuildFile.))))
RecoTotemT1T2T2RecHitPlugins := self/src/RecoTotemT1T2/T2RecHit/plugins
RecoTotemT1T2T2RecHitPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RecHit/plugins/BuildFile
RecoTotemT1T2T2RecHitPlugins_LOC_USE := self  RecoTotemT1T2/T2RecHit FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit
RecoTotemT1T2T2RecHitPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2RecHitPlugins,RecoTotemT1T2T2RecHitPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2RecHit/plugins))
RecoTotemT1T2T2RecHitPlugins_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/plugins
ALL_PRODS += RecoTotemT1T2T2RecHitPlugins
RecoTotemT1T2T2RecHitPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RecHitPlugins,src/RecoTotemT1T2/T2RecHit/plugins,src_RecoTotemT1T2_T2RecHit_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2RecHitPlugins,src/RecoTotemT1T2/T2RecHit/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_plugins
src_RecoTotemT1T2_T2RecHit_plugins_parent := RecoTotemT1T2/T2RecHit
src_RecoTotemT1T2_T2RecHit_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_plugins,src/RecoTotemT1T2/T2RecHit/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T2RecHit)),)
PyRecoTotemT1T2T2RecHit := self/src/RecoTotemT1T2/T2RecHit/python
src_RecoTotemT1T2_T2RecHit_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2RecHit/python)
PyRecoTotemT1T2T2RecHit_files := $(patsubst src/RecoTotemT1T2/T2RecHit/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RecHit/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2RecHit_LOC_USE := self  
PyRecoTotemT1T2T2RecHit_PACKAGE := self/src/RecoTotemT1T2/T2RecHit/python
ALL_PRODS += PyRecoTotemT1T2T2RecHit
PyRecoTotemT1T2T2RecHit_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/python,src_RecoTotemT1T2_T2RecHit_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2RecHit,src/RecoTotemT1T2/T2RecHit/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_python
src_RecoTotemT1T2_T2RecHit_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_python,src/RecoTotemT1T2/T2RecHit/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemT1T2_T2RecHit_test
src_RecoTotemT1T2_T2RecHit_test_parent := RecoTotemT1T2/T2RecHit
src_RecoTotemT1T2_T2RecHit_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RecHit_test,src/RecoTotemT1T2/T2RecHit/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T2RoadPadFinder)
subdirs_src_RecoTotemT1T2_T2RoadPadFinder := src_RecoTotemT1T2_T2RoadPadFinder_test src_RecoTotemT1T2_T2RoadPadFinder_plugins src_RecoTotemT1T2_T2RoadPadFinder_python src_RecoTotemT1T2_T2RoadPadFinder_src
ifeq ($(strip $(RecoTotemT1T2T2RoadPadFinderPlugins)),)
RecoTotemT1T2T2RoadPadFinderPlugins_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2RoadPadFinder/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2RoadPadFinder/plugins/$(file). Please fix src/RecoTotemT1T2/T2RoadPadFinder/plugins/BuildFile.))))
RecoTotemT1T2T2RoadPadFinderPlugins := self/src/RecoTotemT1T2/T2RoadPadFinder/plugins
RecoTotemT1T2T2RoadPadFinderPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2RoadPadFinder/plugins/BuildFile
RecoTotemT1T2T2RoadPadFinderPlugins_LOC_USE := self  RecoTotemT1T2/T2RoadPadFinder FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId boost root MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Road DataFormats/T2Cluster
RecoTotemT1T2T2RoadPadFinderPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2RoadPadFinderPlugins,RecoTotemT1T2T2RoadPadFinderPlugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2RoadPadFinder/plugins))
RecoTotemT1T2T2RoadPadFinderPlugins_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/plugins
ALL_PRODS += RecoTotemT1T2T2RoadPadFinderPlugins
RecoTotemT1T2T2RoadPadFinderPlugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2RoadPadFinderPlugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins,src_RecoTotemT1T2_T2RoadPadFinder_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2RoadPadFinderPlugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_plugins
src_RecoTotemT1T2_T2RoadPadFinder_plugins_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_plugins,src/RecoTotemT1T2/T2RoadPadFinder/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T2RoadPadFinder)),)
PyRecoTotemT1T2T2RoadPadFinder := self/src/RecoTotemT1T2/T2RoadPadFinder/python
src_RecoTotemT1T2_T2RoadPadFinder_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2RoadPadFinder/python)
PyRecoTotemT1T2T2RoadPadFinder_files := $(patsubst src/RecoTotemT1T2/T2RoadPadFinder/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2RoadPadFinder/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2RoadPadFinder_LOC_USE := self  
PyRecoTotemT1T2T2RoadPadFinder_PACKAGE := self/src/RecoTotemT1T2/T2RoadPadFinder/python
ALL_PRODS += PyRecoTotemT1T2T2RoadPadFinder
PyRecoTotemT1T2T2RoadPadFinder_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/python,src_RecoTotemT1T2_T2RoadPadFinder_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2RoadPadFinder,src/RecoTotemT1T2/T2RoadPadFinder/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_python
src_RecoTotemT1T2_T2RoadPadFinder_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_python,src/RecoTotemT1T2/T2RoadPadFinder/python,PYTHON))
ALL_COMMONRULES += src_RecoTotemT1T2_T2RoadPadFinder_test
src_RecoTotemT1T2_T2RoadPadFinder_test_parent := RecoTotemT1T2/T2RoadPadFinder
src_RecoTotemT1T2_T2RoadPadFinder_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2RoadPadFinder_test,src/RecoTotemT1T2/T2RoadPadFinder/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/RecoTotemT1T2/T2TrackProducer3)
subdirs_src_RecoTotemT1T2_T2TrackProducer3 := src_RecoTotemT1T2_T2TrackProducer3_plugins src_RecoTotemT1T2_T2TrackProducer3_python src_RecoTotemT1T2_T2TrackProducer3_src
ifeq ($(strip $(RecoTotemT1T2T2TrackProducer3Plugins)),)
RecoTotemT1T2T2TrackProducer3Plugins_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoTotemT1T2/T2TrackProducer3/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoTotemT1T2/T2TrackProducer3/plugins/$(file). Please fix src/RecoTotemT1T2/T2TrackProducer3/plugins/BuildFile.))))
RecoTotemT1T2T2TrackProducer3Plugins := self/src/RecoTotemT1T2/T2TrackProducer3/plugins
RecoTotemT1T2T2TrackProducer3Plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoTotemT1T2/T2TrackProducer3/plugins/BuildFile
RecoTotemT1T2T2TrackProducer3Plugins_LOC_USE := self  RecoTotemT1T2/T2TrackProducer3 FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry Utilities/Timing FWCore/MessageLogger DataFormats/T2DetId DataFormats/DetId MagneticField/Records MagneticField/Engine DataFormats/T2Hit DataFormats/T2Road DataFormats/T1T2Track TotemAnalysis/T2Cuts boost root clhep
RecoTotemT1T2T2TrackProducer3Plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoTotemT1T2T2TrackProducer3Plugins,RecoTotemT1T2T2TrackProducer3Plugins,$(SCRAMSTORENAME_LIB),src/RecoTotemT1T2/T2TrackProducer3/plugins))
RecoTotemT1T2T2TrackProducer3Plugins_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/plugins
ALL_PRODS += RecoTotemT1T2T2TrackProducer3Plugins
RecoTotemT1T2T2TrackProducer3Plugins_INIT_FUNC        += $$(eval $$(call Library,RecoTotemT1T2T2TrackProducer3Plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins,src_RecoTotemT1T2_T2TrackProducer3_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RecoTotemT1T2T2TrackProducer3Plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_plugins
src_RecoTotemT1T2_T2TrackProducer3_plugins_parent := RecoTotemT1T2/T2TrackProducer3
src_RecoTotemT1T2_T2TrackProducer3_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_plugins,src/RecoTotemT1T2/T2TrackProducer3/plugins,PLUGINS))
ifeq ($(strip $(PyRecoTotemT1T2T2TrackProducer3)),)
PyRecoTotemT1T2T2TrackProducer3 := self/src/RecoTotemT1T2/T2TrackProducer3/python
src_RecoTotemT1T2_T2TrackProducer3_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoTotemT1T2/T2TrackProducer3/python)
PyRecoTotemT1T2T2TrackProducer3_files := $(patsubst src/RecoTotemT1T2/T2TrackProducer3/python/%,%,$(wildcard $(foreach dir,src/RecoTotemT1T2/T2TrackProducer3/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoTotemT1T2T2TrackProducer3_LOC_USE := self  
PyRecoTotemT1T2T2TrackProducer3_PACKAGE := self/src/RecoTotemT1T2/T2TrackProducer3/python
ALL_PRODS += PyRecoTotemT1T2T2TrackProducer3
PyRecoTotemT1T2T2TrackProducer3_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/python,src_RecoTotemT1T2_T2TrackProducer3_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoTotemT1T2T2TrackProducer3,src/RecoTotemT1T2/T2TrackProducer3/python))
endif
ALL_COMMONRULES += src_RecoTotemT1T2_T2TrackProducer3_python
src_RecoTotemT1T2_T2TrackProducer3_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoTotemT1T2_T2TrackProducer3_python,src/RecoTotemT1T2/T2TrackProducer3/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4CMS/Forward)
subdirs_src_SimG4CMS_Forward := src_SimG4CMS_Forward_test src_SimG4CMS_Forward_plugins src_SimG4CMS_Forward_python src_SimG4CMS_Forward_doc src_SimG4CMS_Forward_src src_SimG4CMS_Forward_data
ifeq ($(strip $(SimG4CMSForwardPlugins)),)
SimG4CMSForwardPlugins_files := $(patsubst src/SimG4CMS/Forward/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4CMS/Forward/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/Forward/plugins/$(file). Please fix src/SimG4CMS/Forward/plugins/BuildFile.))))
SimG4CMSForwardPlugins := self/src/SimG4CMS/Forward/plugins
SimG4CMSForwardPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/Forward/plugins/BuildFile
SimG4CMSForwardPlugins_LOC_USE := self  FWCore/PluginManager SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4CMS/Forward SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo DataFormats/Math SimDataFormats/SimHitMaker SimDataFormats/CaloHit SimDataFormats/Forward DetectorDescription/Core FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger boost geant4core root rootmath
SimG4CMSForwardPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CMSForwardPlugins,SimG4CMSForwardPlugins,$(SCRAMSTORENAME_LIB),src/SimG4CMS/Forward/plugins))
SimG4CMSForwardPlugins_PACKAGE := self/src/SimG4CMS/Forward/plugins
ALL_PRODS += SimG4CMSForwardPlugins
SimG4CMSForwardPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSForwardPlugins,src/SimG4CMS/Forward/plugins,src_SimG4CMS_Forward_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CMSForwardPlugins,src/SimG4CMS/Forward/plugins))
endif
ALL_COMMONRULES += src_SimG4CMS_Forward_plugins
src_SimG4CMS_Forward_plugins_parent := SimG4CMS/Forward
src_SimG4CMS_Forward_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_plugins,src/SimG4CMS/Forward/plugins,PLUGINS))
ifeq ($(strip $(PySimG4CMSForward)),)
PySimG4CMSForward := self/src/SimG4CMS/Forward/python
src_SimG4CMS_Forward_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimG4CMS/Forward/python)
PySimG4CMSForward_files := $(patsubst src/SimG4CMS/Forward/python/%,%,$(wildcard $(foreach dir,src/SimG4CMS/Forward/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimG4CMSForward_LOC_USE := self  
PySimG4CMSForward_PACKAGE := self/src/SimG4CMS/Forward/python
ALL_PRODS += PySimG4CMSForward
PySimG4CMSForward_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimG4CMSForward,src/SimG4CMS/Forward/python,src_SimG4CMS_Forward_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimG4CMSForward,src/SimG4CMS/Forward/python))
endif
ALL_COMMONRULES += src_SimG4CMS_Forward_python
src_SimG4CMS_Forward_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_python,src/SimG4CMS/Forward/python,PYTHON))
ALL_COMMONRULES += src_SimG4CMS_Forward_test
src_SimG4CMS_Forward_test_parent := SimG4CMS/Forward
src_SimG4CMS_Forward_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_Forward_test,src/SimG4CMS/Forward/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4CMS/TotemRP)
subdirs_src_SimG4CMS_TotemRP := src_SimG4CMS_TotemRP_test src_SimG4CMS_TotemRP_plugins src_SimG4CMS_TotemRP_python src_SimG4CMS_TotemRP_src
ifeq ($(strip $(SimG4CMSTotemRPPlugins)),)
SimG4CMSTotemRPPlugins_files := $(patsubst src/SimG4CMS/TotemRP/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRP/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRP/plugins/$(file). Please fix src/SimG4CMS/TotemRP/plugins/BuildFile.))))
SimG4CMSTotemRPPlugins := self/src/SimG4CMS/TotemRP/plugins
SimG4CMSTotemRPPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRP/plugins/BuildFile
SimG4CMSTotemRPPlugins_LOC_USE := self  SimG4Core/Watcher SimG4Core/SensitiveDetector SimG4Core/Notification SimG4Core/Application SimG4CMS/Calo SimDataFormats/SimHitMaker SimDataFormats/CaloHit DetectorDescription/Core FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/TotemRPDetId boost geant4 root rootrflx SimG4CMS/TotemRP
SimG4CMSTotemRPPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CMSTotemRPPlugins,SimG4CMSTotemRPPlugins,$(SCRAMSTORENAME_LIB),src/SimG4CMS/TotemRP/plugins))
SimG4CMSTotemRPPlugins_PACKAGE := self/src/SimG4CMS/TotemRP/plugins
ALL_PRODS += SimG4CMSTotemRPPlugins
SimG4CMSTotemRPPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CMSTotemRPPlugins,src/SimG4CMS/TotemRP/plugins,src_SimG4CMS_TotemRP_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CMSTotemRPPlugins,src/SimG4CMS/TotemRP/plugins))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRP_plugins
src_SimG4CMS_TotemRP_plugins_parent := SimG4CMS/TotemRP
src_SimG4CMS_TotemRP_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_plugins,src/SimG4CMS/TotemRP/plugins,PLUGINS))
ifeq ($(strip $(PySimG4CMSTotemRP)),)
PySimG4CMSTotemRP := self/src/SimG4CMS/TotemRP/python
src_SimG4CMS_TotemRP_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimG4CMS/TotemRP/python)
PySimG4CMSTotemRP_files := $(patsubst src/SimG4CMS/TotemRP/python/%,%,$(wildcard $(foreach dir,src/SimG4CMS/TotemRP/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimG4CMSTotemRP_LOC_USE := self  
PySimG4CMSTotemRP_PACKAGE := self/src/SimG4CMS/TotemRP/python
ALL_PRODS += PySimG4CMSTotemRP
PySimG4CMSTotemRP_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimG4CMSTotemRP,src/SimG4CMS/TotemRP/python,src_SimG4CMS_TotemRP_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimG4CMSTotemRP,src/SimG4CMS/TotemRP/python))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRP_python
src_SimG4CMS_TotemRP_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_python,src/SimG4CMS/TotemRP/python,PYTHON))
ALL_COMMONRULES += src_SimG4CMS_TotemRP_test
src_SimG4CMS_TotemRP_test_parent := SimG4CMS/TotemRP
src_SimG4CMS_TotemRP_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRP_test,src/SimG4CMS/TotemRP/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4CMS/TotemRPProtTranspPar)
subdirs_src_SimG4CMS_TotemRPProtTranspPar := src_SimG4CMS_TotemRPProtTranspPar_interface src_SimG4CMS_TotemRPProtTranspPar_src src_SimG4CMS_TotemRPProtTranspPar_bin
ifeq ($(strip $(TotemRPFindApproximation)),)
TotemRPFindApproximation_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/bin/%,%,$(foreach file,FindApproximation.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRPProtTranspPar/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRPProtTranspPar/bin/$(file). Please fix src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile.))))
TotemRPFindApproximation := self/src/SimG4CMS/TotemRPProtTranspPar/bin
TotemRPFindApproximation_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile
TotemRPFindApproximation_LOC_USE := self  root xerces-c SimG4CMS/TotemRPProtTranspPar
TotemRPFindApproximation_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/bin
ALL_PRODS += TotemRPFindApproximation
TotemRPFindApproximation_INIT_FUNC        += $$(eval $$(call Binary,TotemRPFindApproximation,src/SimG4CMS/TotemRPProtTranspPar/bin,src_SimG4CMS_TotemRPProtTranspPar_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPFindApproximation,src/SimG4CMS/TotemRPProtTranspPar/bin))
endif
ifeq ($(strip $(TotemRPFindApertures)),)
TotemRPFindApertures_files := $(patsubst src/SimG4CMS/TotemRPProtTranspPar/bin/%,%,$(foreach file,FindApertures.cc,$(eval xfile:=$(wildcard src/SimG4CMS/TotemRPProtTranspPar/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4CMS/TotemRPProtTranspPar/bin/$(file). Please fix src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile.))))
TotemRPFindApertures := self/src/SimG4CMS/TotemRPProtTranspPar/bin
TotemRPFindApertures_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4CMS/TotemRPProtTranspPar/bin/BuildFile
TotemRPFindApertures_LOC_USE := self  root xerces-c SimG4CMS/TotemRPProtTranspPar
TotemRPFindApertures_PACKAGE := self/src/SimG4CMS/TotemRPProtTranspPar/bin
ALL_PRODS += TotemRPFindApertures
TotemRPFindApertures_INIT_FUNC        += $$(eval $$(call Binary,TotemRPFindApertures,src/SimG4CMS/TotemRPProtTranspPar/bin,src_SimG4CMS_TotemRPProtTranspPar_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPFindApertures,src/SimG4CMS/TotemRPProtTranspPar/bin))
endif
ALL_COMMONRULES += src_SimG4CMS_TotemRPProtTranspPar_bin
src_SimG4CMS_TotemRPProtTranspPar_bin_parent := SimG4CMS/TotemRPProtTranspPar
src_SimG4CMS_TotemRPProtTranspPar_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4CMS_TotemRPProtTranspPar_bin,src/SimG4CMS/TotemRPProtTranspPar/bin,BINARY))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/SimG4Core)
subdirs_src_SimG4Core = src_SimG4Core_HelpfulWatchers src_SimG4Core_Application src_SimG4Core_Notification src_SimG4Core_TotemRPProtTransp src_SimG4Core_Generators
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4Core/Application)
subdirs_src_SimG4Core_Application := src_SimG4Core_Application_test src_SimG4Core_Application_plugins src_SimG4Core_Application_python src_SimG4Core_Application_src
ifeq ($(strip $(SimG4CoreApplicationPlugins)),)
SimG4CoreApplicationPlugins_files := $(patsubst src/SimG4Core/Application/plugins/%,%,$(foreach file,OscarProducer.cc,$(eval xfile:=$(wildcard src/SimG4Core/Application/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/Application/plugins/$(file). Please fix src/SimG4Core/Application/plugins/BuildFile.))))
SimG4CoreApplicationPlugins := self/src/SimG4Core/Application/plugins
SimG4CoreApplicationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Application/plugins/BuildFile
SimG4CoreApplicationPlugins_LOC_USE := self  SimG4Core/TotemRPProtTransp FWCore/Concurrency FWCore/Framework FWCore/ParameterSet SimG4Core/Application geant4core hepmc
SimG4CoreApplicationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CoreApplicationPlugins,SimG4CoreApplicationPlugins,$(SCRAMSTORENAME_LIB),src/SimG4Core/Application/plugins))
SimG4CoreApplicationPlugins_PACKAGE := self/src/SimG4Core/Application/plugins
ALL_PRODS += SimG4CoreApplicationPlugins
SimG4CoreApplicationPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreApplicationPlugins,src/SimG4Core/Application/plugins,src_SimG4Core_Application_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CoreApplicationPlugins,src/SimG4Core/Application/plugins))
endif
ALL_COMMONRULES += src_SimG4Core_Application_plugins
src_SimG4Core_Application_plugins_parent := SimG4Core/Application
src_SimG4Core_Application_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_Application_plugins,src/SimG4Core/Application/plugins,PLUGINS))
ifeq ($(strip $(PySimG4CoreApplication)),)
PySimG4CoreApplication := self/src/SimG4Core/Application/python
src_SimG4Core_Application_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimG4Core/Application/python)
PySimG4CoreApplication_files := $(patsubst src/SimG4Core/Application/python/%,%,$(wildcard $(foreach dir,src/SimG4Core/Application/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimG4CoreApplication_LOC_USE := self  
PySimG4CoreApplication_PACKAGE := self/src/SimG4Core/Application/python
ALL_PRODS += PySimG4CoreApplication
PySimG4CoreApplication_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimG4CoreApplication,src/SimG4Core/Application/python,src_SimG4Core_Application_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimG4CoreApplication,src/SimG4Core/Application/python))
endif
ALL_COMMONRULES += src_SimG4Core_Application_python
src_SimG4Core_Application_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_Application_python,src/SimG4Core/Application/python,PYTHON))
ifeq ($(strip $(SimHitCaloHitDumper)),)
SimHitCaloHitDumper_files := $(patsubst src/SimG4Core/Application/test/%,%,$(foreach file,SimHitCaloHitDumper.cc,$(eval xfile:=$(wildcard src/SimG4Core/Application/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/Application/test/$(file). Please fix src/SimG4Core/Application/test/BuildFile.))))
SimHitCaloHitDumper := self/src/SimG4Core/Application/test
SimHitCaloHitDumper_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Application/test/BuildFile
SimHitCaloHitDumper_LOC_USE := self  FWCore/ServiceRegistry FWCore/Framework FWCore/MessageLogger SimDataFormats/TrackingHit SimDataFormats/CaloHit SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex
SimHitCaloHitDumper_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimHitCaloHitDumper,SimHitCaloHitDumper,$(SCRAMSTORENAME_LIB),src/SimG4Core/Application/test))
SimHitCaloHitDumper_PACKAGE := self/src/SimG4Core/Application/test
ALL_PRODS += SimHitCaloHitDumper
SimHitCaloHitDumper_INIT_FUNC        += $$(eval $$(call Library,SimHitCaloHitDumper,src/SimG4Core/Application/test,src_SimG4Core_Application_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimHitCaloHitDumper,src/SimG4Core/Application/test))
endif
ifeq ($(strip $(SimTrackSimVertexDumper)),)
SimTrackSimVertexDumper_files := $(patsubst src/SimG4Core/Application/test/%,%,$(foreach file,SimTrackSimVertexDumper.cc,$(eval xfile:=$(wildcard src/SimG4Core/Application/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/Application/test/$(file). Please fix src/SimG4Core/Application/test/BuildFile.))))
SimTrackSimVertexDumper := self/src/SimG4Core/Application/test
SimTrackSimVertexDumper_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Application/test/BuildFile
SimTrackSimVertexDumper_LOC_USE := self  FWCore/ServiceRegistry FWCore/Framework FWCore/MessageLogger SimDataFormats/TrackingHit SimDataFormats/CaloHit SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex
SimTrackSimVertexDumper_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTrackSimVertexDumper,SimTrackSimVertexDumper,$(SCRAMSTORENAME_LIB),src/SimG4Core/Application/test))
SimTrackSimVertexDumper_PACKAGE := self/src/SimG4Core/Application/test
ALL_PRODS += SimTrackSimVertexDumper
SimTrackSimVertexDumper_INIT_FUNC        += $$(eval $$(call Library,SimTrackSimVertexDumper,src/SimG4Core/Application/test,src_SimG4Core_Application_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTrackSimVertexDumper,src/SimG4Core/Application/test))
endif
ALL_COMMONRULES += src_SimG4Core_Application_test
src_SimG4Core_Application_test_parent := SimG4Core/Application
src_SimG4Core_Application_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_Application_test,src/SimG4Core/Application/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4Core/Generators)
subdirs_src_SimG4Core_Generators := src_SimG4Core_Generators_doc src_SimG4Core_Generators_src
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4Core/HelpfulWatchers)
subdirs_src_SimG4Core_HelpfulWatchers := src_SimG4Core_HelpfulWatchers_src
ifeq ($(strip $(SimG4Core/HelpfulWatchers)),)
ALL_COMMONRULES += src_SimG4Core_HelpfulWatchers_src
src_SimG4Core_HelpfulWatchers_src_parent := SimG4Core/HelpfulWatchers
src_SimG4Core_HelpfulWatchers_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimG4Core_HelpfulWatchers_src,src/SimG4Core/HelpfulWatchers/src,LIBRARY))
SimG4CoreHelpfulWatchers := self/SimG4Core/HelpfulWatchers
SimG4Core/HelpfulWatchers := SimG4CoreHelpfulWatchers
SimG4CoreHelpfulWatchers_files := $(patsubst src/SimG4Core/HelpfulWatchers/src/%,%,$(wildcard $(foreach dir,src/SimG4Core/HelpfulWatchers/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimG4CoreHelpfulWatchers_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/HelpfulWatchers/BuildFile
SimG4CoreHelpfulWatchers_LOC_USE := self  FWCore/Framework SimG4Core/Watcher SimG4Core/Notification boost geant4
SimG4CoreHelpfulWatchers_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CoreHelpfulWatchers,SimG4CoreHelpfulWatchers,$(SCRAMSTORENAME_LIB),src/SimG4Core/HelpfulWatchers/src))
SimG4CoreHelpfulWatchers_PACKAGE := self/src/SimG4Core/HelpfulWatchers/src
ALL_PRODS += SimG4CoreHelpfulWatchers
SimG4CoreHelpfulWatchers_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreHelpfulWatchers,src/SimG4Core/HelpfulWatchers/src,src_SimG4Core_HelpfulWatchers_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4Core/Notification)
subdirs_src_SimG4Core_Notification := src_SimG4Core_Notification_test src_SimG4Core_Notification_doc src_SimG4Core_Notification_src
ifeq ($(strip $(testSimG4CoreNotifications)),)
testSimG4CoreNotifications_files := $(patsubst src/SimG4Core/Notification/test/%,%,$(foreach file,simactivityregistry_t.cppunit.cpp,$(eval xfile:=$(wildcard src/SimG4Core/Notification/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/Notification/test/$(file). Please fix src/SimG4Core/Notification/test/BuildFile.))))
testSimG4CoreNotifications := self/src/SimG4Core/Notification/test
testSimG4CoreNotifications_TEST_RUNNER_CMD :=  testSimG4CoreNotifications 
testSimG4CoreNotifications_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/Notification/test/BuildFile
testSimG4CoreNotifications_LOC_USE := self  boost cppunit SimG4Core/Notification
testSimG4CoreNotifications_PACKAGE := self/src/SimG4Core/Notification/test
ALL_PRODS += testSimG4CoreNotifications
testSimG4CoreNotifications_INIT_FUNC        += $$(eval $$(call Binary,testSimG4CoreNotifications,src/SimG4Core/Notification/test,src_SimG4Core_Notification_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,testSimG4CoreNotifications,src/SimG4Core/Notification/test))
endif
ALL_COMMONRULES += src_SimG4Core_Notification_test
src_SimG4Core_Notification_test_parent := SimG4Core/Notification
src_SimG4Core_Notification_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_Notification_test,src/SimG4Core/Notification/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimG4Core/TotemRPProtTransp)
subdirs_src_SimG4Core_TotemRPProtTransp := src_SimG4Core_TotemRPProtTransp_plugins src_SimG4Core_TotemRPProtTransp_src
ifeq ($(strip $(SimG4CoreTotemRPProtTranspPlugins)),)
SimG4CoreTotemRPProtTranspPlugins_files := $(patsubst src/SimG4Core/TotemRPProtTransp/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimG4Core/TotemRPProtTransp/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimG4Core/TotemRPProtTransp/plugins/$(file). Please fix src/SimG4Core/TotemRPProtTransp/plugins/BuildFile.))))
SimG4CoreTotemRPProtTranspPlugins := self/src/SimG4Core/TotemRPProtTransp/plugins
SimG4CoreTotemRPProtTranspPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimG4Core/TotemRPProtTransp/plugins/BuildFile
SimG4CoreTotemRPProtTranspPlugins_LOC_USE := self  SimG4Core/Physics FWCore/ParameterSet SimG4Core/TotemRPProtTransp SimG4Core/PhysicsLists FWCore/MessageLogger geant4 FWCore/Framework
SimG4CoreTotemRPProtTranspPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimG4CoreTotemRPProtTranspPlugins,SimG4CoreTotemRPProtTranspPlugins,$(SCRAMSTORENAME_LIB),src/SimG4Core/TotemRPProtTransp/plugins))
SimG4CoreTotemRPProtTranspPlugins_PACKAGE := self/src/SimG4Core/TotemRPProtTransp/plugins
ALL_PRODS += SimG4CoreTotemRPProtTranspPlugins
SimG4CoreTotemRPProtTranspPlugins_INIT_FUNC        += $$(eval $$(call Library,SimG4CoreTotemRPProtTranspPlugins,src/SimG4Core/TotemRPProtTransp/plugins,src_SimG4Core_TotemRPProtTransp_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimG4CoreTotemRPProtTranspPlugins,src/SimG4Core/TotemRPProtTransp/plugins))
endif
ALL_COMMONRULES += src_SimG4Core_TotemRPProtTransp_plugins
src_SimG4Core_TotemRPProtTransp_plugins_parent := SimG4Core/TotemRPProtTransp
src_SimG4Core_TotemRPProtTransp_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimG4Core_TotemRPProtTransp_plugins,src/SimG4Core/TotemRPProtTransp/plugins,PLUGINS))
ALL_PACKAGES += $(patsubst src/%,%,src/SimTotem/RPDigiProducer)
subdirs_src_SimTotem_RPDigiProducer := src_SimTotem_RPDigiProducer_test src_SimTotem_RPDigiProducer_python src_SimTotem_RPDigiProducer_src
ifeq ($(strip $(PySimTotemRPDigiProducer)),)
PySimTotemRPDigiProducer := self/src/SimTotem/RPDigiProducer/python
src_SimTotem_RPDigiProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/RPDigiProducer/python)
PySimTotemRPDigiProducer_files := $(patsubst src/SimTotem/RPDigiProducer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/RPDigiProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemRPDigiProducer_LOC_USE := self  
PySimTotemRPDigiProducer_PACKAGE := self/src/SimTotem/RPDigiProducer/python
ALL_PRODS += PySimTotemRPDigiProducer
PySimTotemRPDigiProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/python,src_SimTotem_RPDigiProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/python))
endif
ALL_COMMONRULES += src_SimTotem_RPDigiProducer_python
src_SimTotem_RPDigiProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_python,src/SimTotem/RPDigiProducer/python,PYTHON))
ifeq ($(strip $(SimTotem/RPDigiProducer)),)
ALL_COMMONRULES += src_SimTotem_RPDigiProducer_src
src_SimTotem_RPDigiProducer_src_parent := SimTotem/RPDigiProducer
src_SimTotem_RPDigiProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_src,src/SimTotem/RPDigiProducer/src,LIBRARY))
SimTotemRPDigiProducer := self/SimTotem/RPDigiProducer
SimTotem/RPDigiProducer := SimTotemRPDigiProducer
SimTotemRPDigiProducer_files := $(patsubst src/SimTotem/RPDigiProducer/src/%,%,$(wildcard $(foreach dir,src/SimTotem/RPDigiProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPDigiProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPDigiProducer/BuildFile
SimTotemRPDigiProducer_LOC_USE := self  SimDataFormats/TrackingHit SimGeneral/NoiseGenerators FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common SimDataFormats/CrossingFrame SimTracker/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Mixing/Base gsl boost geant4 DataFormats/TotemRPDetId TotemCondFormats/DAQInformation TotemCondFormats/DataRecord
SimTotemRPDigiProducer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemRPDigiProducer,SimTotemRPDigiProducer,$(SCRAMSTORENAME_LIB),src/SimTotem/RPDigiProducer/src))
SimTotemRPDigiProducer_PACKAGE := self/src/SimTotem/RPDigiProducer/src
ALL_PRODS += SimTotemRPDigiProducer
SimTotemRPDigiProducer_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPDigiProducer,src/SimTotem/RPDigiProducer/src,src_SimTotem_RPDigiProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/UATree)
subdirs_src_UATree = src_UATree_MitEdm src_UATree_UABaseTree src_UATree_UADataFormat
ALL_COMMONRULES += src_SimTotem_RPDigiProducer_test
src_SimTotem_RPDigiProducer_test_parent := SimTotem/RPDigiProducer
src_SimTotem_RPDigiProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPDigiProducer_test,src/SimTotem/RPDigiProducer/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimTotem/RPTimingDetectorsDigiProducer)
subdirs_src_SimTotem_RPTimingDetectorsDigiProducer := src_SimTotem_RPTimingDetectorsDigiProducer_test src_SimTotem_RPTimingDetectorsDigiProducer_interface src_SimTotem_RPTimingDetectorsDigiProducer_plugins src_SimTotem_RPTimingDetectorsDigiProducer_python src_SimTotem_RPTimingDetectorsDigiProducer_src
ifeq ($(strip $(SimTotemRPTimingDetectorsDigiProducerAuto)),)
SimTotemRPTimingDetectorsDigiProducerAuto_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/plugins/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
SimTotemRPTimingDetectorsDigiProducerAuto := self/src/SimTotem/RPTimingDetectorsDigiProducer/plugins
SimTotemRPTimingDetectorsDigiProducerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/RPTimingDetectorsDigiProducer/plugins/BuildFile
SimTotemRPTimingDetectorsDigiProducerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId SimTotem/RPTimingDetectorsDigiProducer CommonTools/UtilAlgos PhysicsTools/UtilAlgos Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
SimTotemRPTimingDetectorsDigiProducerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemRPTimingDetectorsDigiProducerAuto,SimTotemRPTimingDetectorsDigiProducerAuto,$(SCRAMSTORENAME_LIB),src/SimTotem/RPTimingDetectorsDigiProducer/plugins))
SimTotemRPTimingDetectorsDigiProducerAuto_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/plugins
ALL_PRODS += SimTotemRPTimingDetectorsDigiProducerAuto
SimTotemRPTimingDetectorsDigiProducerAuto_INIT_FUNC        += $$(eval $$(call Library,SimTotemRPTimingDetectorsDigiProducerAuto,src/SimTotem/RPTimingDetectorsDigiProducer/plugins,src_SimTotem_RPTimingDetectorsDigiProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemRPTimingDetectorsDigiProducerAuto,src/SimTotem/RPTimingDetectorsDigiProducer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_plugins
src_SimTotem_RPTimingDetectorsDigiProducer_plugins_parent := SimTotem/RPTimingDetectorsDigiProducer
src_SimTotem_RPTimingDetectorsDigiProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_plugins,src/SimTotem/RPTimingDetectorsDigiProducer/plugins,PLUGINS))
ifeq ($(strip $(PySimTotemRPTimingDetectorsDigiProducer)),)
PySimTotemRPTimingDetectorsDigiProducer := self/src/SimTotem/RPTimingDetectorsDigiProducer/python
src_SimTotem_RPTimingDetectorsDigiProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/RPTimingDetectorsDigiProducer/python)
PySimTotemRPTimingDetectorsDigiProducer_files := $(patsubst src/SimTotem/RPTimingDetectorsDigiProducer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/RPTimingDetectorsDigiProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemRPTimingDetectorsDigiProducer_LOC_USE := self  
PySimTotemRPTimingDetectorsDigiProducer_PACKAGE := self/src/SimTotem/RPTimingDetectorsDigiProducer/python
ALL_PRODS += PySimTotemRPTimingDetectorsDigiProducer
PySimTotemRPTimingDetectorsDigiProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/python,src_SimTotem_RPTimingDetectorsDigiProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemRPTimingDetectorsDigiProducer,src/SimTotem/RPTimingDetectorsDigiProducer/python))
endif
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_python
src_SimTotem_RPTimingDetectorsDigiProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_python,src/SimTotem/RPTimingDetectorsDigiProducer/python,PYTHON))
ALL_COMMONRULES += src_SimTotem_RPTimingDetectorsDigiProducer_test
src_SimTotem_RPTimingDetectorsDigiProducer_test_parent := SimTotem/RPTimingDetectorsDigiProducer
src_SimTotem_RPTimingDetectorsDigiProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_RPTimingDetectorsDigiProducer_test,src/SimTotem/RPTimingDetectorsDigiProducer/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/SimTotem/T1Digitizer)
subdirs_src_SimTotem_T1Digitizer := src_SimTotem_T1Digitizer_interface src_SimTotem_T1Digitizer_plugins src_SimTotem_T1Digitizer_python src_SimTotem_T1Digitizer_src
ifeq ($(strip $(SimTotemT1DigitizerPlugins)),)
SimTotemT1DigitizerPlugins_files := $(patsubst src/SimTotem/T1Digitizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimTotem/T1Digitizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimTotem/T1Digitizer/plugins/$(file). Please fix src/SimTotem/T1Digitizer/plugins/BuildFile.))))
SimTotemT1DigitizerPlugins := self/src/SimTotem/T1Digitizer/plugins
SimTotemT1DigitizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T1Digitizer/plugins/BuildFile
SimTotemT1DigitizerPlugins_LOC_USE := self  SimTotem/T1Digitizer DataFormats/Common DataFormats/Provenance FWCore/Framework FWCore/ParameterSet Geometry/TotemRecords Geometry/CommonDetUnit Geometry/TotemGeometry SimGeneral/HepPDTRecord Utilities/Timing FWCore/MessageLogger MagneticField/Records MagneticField/Engine DataFormats/DetId DataFormats/T1Digi DataFormats/T1DetId DataFormats/T1DigiWire DataFormats/T1DigiSantiard DataFormats/T1DigiVfat DataFormats/T1TestElements boost root clhep
SimTotemT1DigitizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemT1DigitizerPlugins,SimTotemT1DigitizerPlugins,$(SCRAMSTORENAME_LIB),src/SimTotem/T1Digitizer/plugins))
SimTotemT1DigitizerPlugins_PACKAGE := self/src/SimTotem/T1Digitizer/plugins
ALL_PRODS += SimTotemT1DigitizerPlugins
SimTotemT1DigitizerPlugins_INIT_FUNC        += $$(eval $$(call Library,SimTotemT1DigitizerPlugins,src/SimTotem/T1Digitizer/plugins,src_SimTotem_T1Digitizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemT1DigitizerPlugins,src/SimTotem/T1Digitizer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_T1Digitizer_plugins
src_SimTotem_T1Digitizer_plugins_parent := SimTotem/T1Digitizer
src_SimTotem_T1Digitizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_plugins,src/SimTotem/T1Digitizer/plugins,PLUGINS))
ifeq ($(strip $(PySimTotemT1Digitizer)),)
PySimTotemT1Digitizer := self/src/SimTotem/T1Digitizer/python
src_SimTotem_T1Digitizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/T1Digitizer/python)
PySimTotemT1Digitizer_files := $(patsubst src/SimTotem/T1Digitizer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/T1Digitizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemT1Digitizer_LOC_USE := self  
PySimTotemT1Digitizer_PACKAGE := self/src/SimTotem/T1Digitizer/python
ALL_PRODS += PySimTotemT1Digitizer
PySimTotemT1Digitizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemT1Digitizer,src/SimTotem/T1Digitizer/python,src_SimTotem_T1Digitizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemT1Digitizer,src/SimTotem/T1Digitizer/python))
endif
ALL_COMMONRULES += src_SimTotem_T1Digitizer_python
src_SimTotem_T1Digitizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T1Digitizer_python,src/SimTotem/T1Digitizer/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/SimTotem/T2Digitizer)
subdirs_src_SimTotem_T2Digitizer := src_SimTotem_T2Digitizer_test src_SimTotem_T2Digitizer_plugins src_SimTotem_T2Digitizer_python src_SimTotem_T2Digitizer_src
ifeq ($(strip $(SimTotemT2DigitizerPlugins)),)
SimTotemT2DigitizerPlugins_files := $(patsubst src/SimTotem/T2Digitizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/SimTotem/T2Digitizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/SimTotem/T2Digitizer/plugins/$(file). Please fix src/SimTotem/T2Digitizer/plugins/BuildFile.))))
SimTotemT2DigitizerPlugins := self/src/SimTotem/T2Digitizer/plugins
SimTotemT2DigitizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/SimTotem/T2Digitizer/plugins/BuildFile
SimTotemT2DigitizerPlugins_LOC_USE := self  SimTotem/T2Digitizer FWCore/Framework FWCore/ParameterSet Utilities/Timing FWCore/MessageLogger DataFormats/T2Digi DataFormats/DetId DataFormats/T2DetId DataFormats/T2DigiVfat SimDataFormats/TrackingHit Geometry/TotemRecords Geometry/TotemT2AlignmentDataFormats Geometry/CommonDetUnit Geometry/TotemGeometry SimTracker/Common Mixing/Base geant4 root boost clhep gsl hepmc
SimTotemT2DigitizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,SimTotemT2DigitizerPlugins,SimTotemT2DigitizerPlugins,$(SCRAMSTORENAME_LIB),src/SimTotem/T2Digitizer/plugins))
SimTotemT2DigitizerPlugins_PACKAGE := self/src/SimTotem/T2Digitizer/plugins
ALL_PRODS += SimTotemT2DigitizerPlugins
SimTotemT2DigitizerPlugins_INIT_FUNC        += $$(eval $$(call Library,SimTotemT2DigitizerPlugins,src/SimTotem/T2Digitizer/plugins,src_SimTotem_T2Digitizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,SimTotemT2DigitizerPlugins,src/SimTotem/T2Digitizer/plugins))
endif
ALL_COMMONRULES += src_SimTotem_T2Digitizer_plugins
src_SimTotem_T2Digitizer_plugins_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_plugins,src/SimTotem/T2Digitizer/plugins,PLUGINS))
ifeq ($(strip $(PySimTotemT2Digitizer)),)
PySimTotemT2Digitizer := self/src/SimTotem/T2Digitizer/python
src_SimTotem_T2Digitizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SimTotem/T2Digitizer/python)
PySimTotemT2Digitizer_files := $(patsubst src/SimTotem/T2Digitizer/python/%,%,$(wildcard $(foreach dir,src/SimTotem/T2Digitizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySimTotemT2Digitizer_LOC_USE := self  
PySimTotemT2Digitizer_PACKAGE := self/src/SimTotem/T2Digitizer/python
ALL_PRODS += PySimTotemT2Digitizer
PySimTotemT2Digitizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PySimTotemT2Digitizer,src/SimTotem/T2Digitizer/python,src_SimTotem_T2Digitizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PySimTotemT2Digitizer,src/SimTotem/T2Digitizer/python))
endif
ALL_COMMONRULES += src_SimTotem_T2Digitizer_python
src_SimTotem_T2Digitizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_python,src/SimTotem/T2Digitizer/python,PYTHON))
ALL_COMMONRULES += src_SimTotem_T2Digitizer_test
src_SimTotem_T2Digitizer_test_parent := SimTotem/T2Digitizer
src_SimTotem_T2Digitizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SimTotem_T2Digitizer_test,src/SimTotem/T2Digitizer/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemAlignment)
subdirs_src_TotemAlignment = src_TotemAlignment_RPRates src_TotemAlignment_T2TrkBasedInternalAlignment src_TotemAlignment_RPRecords src_TotemAlignment_T1Alignment src_TotemAlignment_RPFastSimulation src_TotemAlignment_RPProfiles src_TotemAlignment_RPTrackBased src_TotemAlignment_RPDataFormats src_TotemAlignment_RPData
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPData)
subdirs_src_TotemAlignment_RPData := src_TotemAlignment_RPData_LHC
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPDataFormats)
subdirs_src_TotemAlignment_RPDataFormats := src_TotemAlignment_RPDataFormats_test src_TotemAlignment_RPDataFormats_plugins src_TotemAlignment_RPDataFormats_python src_TotemAlignment_RPDataFormats_src src_TotemAlignment_RPDataFormats_bin
ifeq ($(strip $(PrintRPAlignmentSummary)),)
PrintRPAlignmentSummary_files := $(patsubst src/TotemAlignment/RPDataFormats/bin/%,%,$(foreach file,PrintRPAlignmentSummary.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPDataFormats/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPDataFormats/bin/$(file). Please fix src/TotemAlignment/RPDataFormats/bin/BuildFile.))))
PrintRPAlignmentSummary := self/src/TotemAlignment/RPDataFormats/bin
PrintRPAlignmentSummary_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/bin/BuildFile
PrintRPAlignmentSummary_LOC_USE := self  TotemAlignment/RPDataFormats
PrintRPAlignmentSummary_PACKAGE := self/src/TotemAlignment/RPDataFormats/bin
ALL_PRODS += PrintRPAlignmentSummary
PrintRPAlignmentSummary_INIT_FUNC        += $$(eval $$(call Binary,PrintRPAlignmentSummary,src/TotemAlignment/RPDataFormats/bin,src_TotemAlignment_RPDataFormats_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,PrintRPAlignmentSummary,src/TotemAlignment/RPDataFormats/bin))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_bin
src_TotemAlignment_RPDataFormats_bin_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_bin,src/TotemAlignment/RPDataFormats/bin,BINARY))
ifeq ($(strip $(TotemAlignmentRPDataFormatsPlugins)),)
TotemAlignmentRPDataFormatsPlugins_files := $(patsubst src/TotemAlignment/RPDataFormats/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPDataFormats/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPDataFormats/plugins/$(file). Please fix src/TotemAlignment/RPDataFormats/plugins/BuildFile.))))
TotemAlignmentRPDataFormatsPlugins := self/src/TotemAlignment/RPDataFormats/plugins
TotemAlignmentRPDataFormatsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPDataFormats/plugins/BuildFile
TotemAlignmentRPDataFormatsPlugins_LOC_USE := self  TotemAlignment/RPDataFormats TotemAlignment/RPRecords FWCore/Framework Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAlignmentRPDataFormatsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPDataFormatsPlugins,TotemAlignmentRPDataFormatsPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPDataFormats/plugins))
TotemAlignmentRPDataFormatsPlugins_PACKAGE := self/src/TotemAlignment/RPDataFormats/plugins
ALL_PRODS += TotemAlignmentRPDataFormatsPlugins
TotemAlignmentRPDataFormatsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPDataFormatsPlugins,src/TotemAlignment/RPDataFormats/plugins,src_TotemAlignment_RPDataFormats_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPDataFormatsPlugins,src/TotemAlignment/RPDataFormats/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_plugins
src_TotemAlignment_RPDataFormats_plugins_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_plugins,src/TotemAlignment/RPDataFormats/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentRPDataFormats)),)
PyTotemAlignmentRPDataFormats := self/src/TotemAlignment/RPDataFormats/python
src_TotemAlignment_RPDataFormats_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPDataFormats/python)
PyTotemAlignmentRPDataFormats_files := $(patsubst src/TotemAlignment/RPDataFormats/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPDataFormats/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPDataFormats_LOC_USE := self  
PyTotemAlignmentRPDataFormats_PACKAGE := self/src/TotemAlignment/RPDataFormats/python
ALL_PRODS += PyTotemAlignmentRPDataFormats
PyTotemAlignmentRPDataFormats_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/python,src_TotemAlignment_RPDataFormats_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPDataFormats,src/TotemAlignment/RPDataFormats/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_python
src_TotemAlignment_RPDataFormats_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_python,src/TotemAlignment/RPDataFormats/python,PYTHON))
ALL_COMMONRULES += src_TotemAlignment_RPDataFormats_test
src_TotemAlignment_RPDataFormats_test_parent := TotemAlignment/RPDataFormats
src_TotemAlignment_RPDataFormats_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPDataFormats_test,src/TotemAlignment/RPDataFormats/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPFastSimulation)
subdirs_src_TotemAlignment_RPFastSimulation := src_TotemAlignment_RPFastSimulation_test src_TotemAlignment_RPFastSimulation_plugins src_TotemAlignment_RPFastSimulation_python
ifeq ($(strip $(TotemAlignmentRPFastSimulation)),)
TotemAlignmentRPFastSimulation_files := $(patsubst src/TotemAlignment/RPFastSimulation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPFastSimulation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPFastSimulation/plugins/$(file). Please fix src/TotemAlignment/RPFastSimulation/plugins/BuildFile.))))
TotemAlignmentRPFastSimulation := self/src/TotemAlignment/RPFastSimulation/plugins
TotemAlignmentRPFastSimulation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPFastSimulation/plugins/BuildFile
TotemAlignmentRPFastSimulation_LOC_USE := self  hepmc clhep FWCore/Framework FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities SimDataFormats/GeneratorProducts Geometry/TotemRPDetTopology DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder Geometry/TotemRecords RecoTotemRP/RPRecoDataFormats TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord SimG4CMS/TotemRPProtTranspPar TotemAlignment/RPDataFormats
TotemAlignmentRPFastSimulation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPFastSimulation,TotemAlignmentRPFastSimulation,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPFastSimulation/plugins))
TotemAlignmentRPFastSimulation_PACKAGE := self/src/TotemAlignment/RPFastSimulation/plugins
ALL_PRODS += TotemAlignmentRPFastSimulation
TotemAlignmentRPFastSimulation_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/plugins,src_TotemAlignment_RPFastSimulation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_plugins
src_TotemAlignment_RPFastSimulation_plugins_parent := TotemAlignment/RPFastSimulation
src_TotemAlignment_RPFastSimulation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_plugins,src/TotemAlignment/RPFastSimulation/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentRPFastSimulation)),)
PyTotemAlignmentRPFastSimulation := self/src/TotemAlignment/RPFastSimulation/python
src_TotemAlignment_RPFastSimulation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPFastSimulation/python)
PyTotemAlignmentRPFastSimulation_files := $(patsubst src/TotemAlignment/RPFastSimulation/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPFastSimulation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPFastSimulation_LOC_USE := self  
PyTotemAlignmentRPFastSimulation_PACKAGE := self/src/TotemAlignment/RPFastSimulation/python
ALL_PRODS += PyTotemAlignmentRPFastSimulation
PyTotemAlignmentRPFastSimulation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/python,src_TotemAlignment_RPFastSimulation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPFastSimulation,src/TotemAlignment/RPFastSimulation/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_python
src_TotemAlignment_RPFastSimulation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_python,src/TotemAlignment/RPFastSimulation/python,PYTHON))
ALL_COMMONRULES += src_TotemAlignment_RPFastSimulation_test
src_TotemAlignment_RPFastSimulation_test_parent := TotemAlignment/RPFastSimulation
src_TotemAlignment_RPFastSimulation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPFastSimulation_test,src/TotemAlignment/RPFastSimulation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPProfiles)
subdirs_src_TotemAlignment_RPProfiles := src_TotemAlignment_RPProfiles_test src_TotemAlignment_RPProfiles_plugins src_TotemAlignment_RPProfiles_python
ifeq ($(strip $(TotemAlignmentRPProfilesPlugins)),)
TotemAlignmentRPProfilesPlugins_files := $(patsubst src/TotemAlignment/RPProfiles/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPProfiles/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPProfiles/plugins/$(file). Please fix src/TotemAlignment/RPProfiles/plugins/BuildFile.))))
TotemAlignmentRPProfilesPlugins := self/src/TotemAlignment/RPProfiles/plugins
TotemAlignmentRPProfilesPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPProfiles/plugins/BuildFile
TotemAlignmentRPProfilesPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder TotemAlignment/RPTrackBased root
TotemAlignmentRPProfilesPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPProfilesPlugins,TotemAlignmentRPProfilesPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPProfiles/plugins))
TotemAlignmentRPProfilesPlugins_PACKAGE := self/src/TotemAlignment/RPProfiles/plugins
ALL_PRODS += TotemAlignmentRPProfilesPlugins
TotemAlignmentRPProfilesPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPProfilesPlugins,src/TotemAlignment/RPProfiles/plugins,src_TotemAlignment_RPProfiles_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPProfilesPlugins,src/TotemAlignment/RPProfiles/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPProfiles_plugins
src_TotemAlignment_RPProfiles_plugins_parent := TotemAlignment/RPProfiles
src_TotemAlignment_RPProfiles_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_plugins,src/TotemAlignment/RPProfiles/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentRPProfiles)),)
PyTotemAlignmentRPProfiles := self/src/TotemAlignment/RPProfiles/python
src_TotemAlignment_RPProfiles_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPProfiles/python)
PyTotemAlignmentRPProfiles_files := $(patsubst src/TotemAlignment/RPProfiles/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPProfiles/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPProfiles_LOC_USE := self  
PyTotemAlignmentRPProfiles_PACKAGE := self/src/TotemAlignment/RPProfiles/python
ALL_PRODS += PyTotemAlignmentRPProfiles
PyTotemAlignmentRPProfiles_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPProfiles,src/TotemAlignment/RPProfiles/python,src_TotemAlignment_RPProfiles_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPProfiles,src/TotemAlignment/RPProfiles/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPProfiles_python
src_TotemAlignment_RPProfiles_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_python,src/TotemAlignment/RPProfiles/python,PYTHON))
ALL_COMMONRULES += src_TotemAlignment_RPProfiles_test
src_TotemAlignment_RPProfiles_test_parent := TotemAlignment/RPProfiles
src_TotemAlignment_RPProfiles_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPProfiles_test,src/TotemAlignment/RPProfiles/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPRates)
subdirs_src_TotemAlignment_RPRates := src_TotemAlignment_RPRates_plugins src_TotemAlignment_RPRates_python src_TotemAlignment_RPRates_src
ifeq ($(strip $(TotemAlignmentRPRatesPlugins)),)
TotemAlignmentRPRatesPlugins_files := $(patsubst src/TotemAlignment/RPRates/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPRates/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPRates/plugins/$(file). Please fix src/TotemAlignment/RPRates/plugins/BuildFile.))))
TotemAlignmentRPRatesPlugins := self/src/TotemAlignment/RPRates/plugins
TotemAlignmentRPRatesPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPRates/plugins/BuildFile
TotemAlignmentRPRatesPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder root hepmc TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord SimG4CMS/TotemRPProtTranspPar TotemAlignment/RPRates
TotemAlignmentRPRatesPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPRatesPlugins,TotemAlignmentRPRatesPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPRates/plugins))
TotemAlignmentRPRatesPlugins_PACKAGE := self/src/TotemAlignment/RPRates/plugins
ALL_PRODS += TotemAlignmentRPRatesPlugins
TotemAlignmentRPRatesPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPRatesPlugins,src/TotemAlignment/RPRates/plugins,src_TotemAlignment_RPRates_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPRatesPlugins,src/TotemAlignment/RPRates/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPRates_plugins
src_TotemAlignment_RPRates_plugins_parent := TotemAlignment/RPRates
src_TotemAlignment_RPRates_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_plugins,src/TotemAlignment/RPRates/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentRPRates)),)
PyTotemAlignmentRPRates := self/src/TotemAlignment/RPRates/python
src_TotemAlignment_RPRates_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPRates/python)
PyTotemAlignmentRPRates_files := $(patsubst src/TotemAlignment/RPRates/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPRates/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPRates_LOC_USE := self  
PyTotemAlignmentRPRates_PACKAGE := self/src/TotemAlignment/RPRates/python
ALL_PRODS += PyTotemAlignmentRPRates
PyTotemAlignmentRPRates_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPRates,src/TotemAlignment/RPRates/python,src_TotemAlignment_RPRates_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPRates,src/TotemAlignment/RPRates/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPRates_python
src_TotemAlignment_RPRates_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPRates_python,src/TotemAlignment/RPRates/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPRecords)
subdirs_src_TotemAlignment_RPRecords := src_TotemAlignment_RPRecords_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/RPTrackBased)
subdirs_src_TotemAlignment_RPTrackBased := src_TotemAlignment_RPTrackBased_test src_TotemAlignment_RPTrackBased_plugins src_TotemAlignment_RPTrackBased_python src_TotemAlignment_RPTrackBased_src
ifeq ($(strip $(TotemAlignmentRPTrackBasedPlugins)),)
TotemAlignmentRPTrackBasedPlugins_files := $(patsubst src/TotemAlignment/RPTrackBased/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/plugins/$(file). Please fix src/TotemAlignment/RPTrackBased/plugins/BuildFile.))))
TotemAlignmentRPTrackBasedPlugins := self/src/TotemAlignment/RPTrackBased/plugins
TotemAlignmentRPTrackBasedPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/plugins/BuildFile
TotemAlignmentRPTrackBasedPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAlignmentRPTrackBasedPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet hepmc clhep DataFormats/TotemRPDetId Geometry/TotemRPGeometryBuilder root TotemAlignment/RPTrackBased TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord Geometry/TotemRPDetTopology
TotemAlignmentRPTrackBasedPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentRPTrackBasedPlugins,TotemAlignmentRPTrackBasedPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/RPTrackBased/plugins))
TotemAlignmentRPTrackBasedPlugins_PACKAGE := self/src/TotemAlignment/RPTrackBased/plugins
ALL_PRODS += TotemAlignmentRPTrackBasedPlugins
TotemAlignmentRPTrackBasedPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentRPTrackBasedPlugins,src/TotemAlignment/RPTrackBased/plugins,src_TotemAlignment_RPTrackBased_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentRPTrackBasedPlugins,src/TotemAlignment/RPTrackBased/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_plugins
src_TotemAlignment_RPTrackBased_plugins_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_plugins,src/TotemAlignment/RPTrackBased/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentRPTrackBased)),)
PyTotemAlignmentRPTrackBased := self/src/TotemAlignment/RPTrackBased/python
src_TotemAlignment_RPTrackBased_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/RPTrackBased/python)
PyTotemAlignmentRPTrackBased_files := $(patsubst src/TotemAlignment/RPTrackBased/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/RPTrackBased/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentRPTrackBased_LOC_USE := self  
PyTotemAlignmentRPTrackBased_PACKAGE := self/src/TotemAlignment/RPTrackBased/python
ALL_PRODS += PyTotemAlignmentRPTrackBased
PyTotemAlignmentRPTrackBased_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/python,src_TotemAlignment_RPTrackBased_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentRPTrackBased,src/TotemAlignment/RPTrackBased/python))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_python
src_TotemAlignment_RPTrackBased_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_python,src/TotemAlignment/RPTrackBased/python,PYTHON))
ifeq ($(strip $(refactorStatisticalResults)),)
refactorStatisticalResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,refactorStatisticalResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
refactorStatisticalResults := self/src/TotemAlignment/RPTrackBased/test
refactorStatisticalResults_TEST_RUNNER_CMD :=  refactorStatisticalResults 
refactorStatisticalResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
refactorStatisticalResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
refactorStatisticalResults_LOC_USE := self  TotemAlignment/RPDataFormats
refactorStatisticalResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += refactorStatisticalResults
refactorStatisticalResults_INIT_FUNC        += $$(eval $$(call Binary,refactorStatisticalResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,refactorStatisticalResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(analyzeStatisticalResults)),)
analyzeStatisticalResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,analyzeStatisticalResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
analyzeStatisticalResults := self/src/TotemAlignment/RPTrackBased/test
analyzeStatisticalResults_TEST_RUNNER_CMD :=  analyzeStatisticalResults 
analyzeStatisticalResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
analyzeStatisticalResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
analyzeStatisticalResults_LOC_USE := self  root TotemAlignment/RPDataFormats
analyzeStatisticalResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += analyzeStatisticalResults
analyzeStatisticalResults_INIT_FUNC        += $$(eval $$(call Binary,analyzeStatisticalResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,analyzeStatisticalResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(summarizeRealAlignmentResults)),)
summarizeRealAlignmentResults_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,summarizeRealAlignmentResults.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
summarizeRealAlignmentResults := self/src/TotemAlignment/RPTrackBased/test
summarizeRealAlignmentResults_TEST_RUNNER_CMD :=  summarizeRealAlignmentResults 
summarizeRealAlignmentResults_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
summarizeRealAlignmentResults_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
summarizeRealAlignmentResults_LOC_USE := self  root TotemAlignment/RPDataFormats
summarizeRealAlignmentResults_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += summarizeRealAlignmentResults
summarizeRealAlignmentResults_INIT_FUNC        += $$(eval $$(call Binary,summarizeRealAlignmentResults,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,summarizeRealAlignmentResults,src/TotemAlignment/RPTrackBased/test))
endif
ifeq ($(strip $(TaskDataTestReader)),)
TaskDataTestReader_files := $(patsubst src/TotemAlignment/RPTrackBased/test/%,%,$(foreach file,TaskDataTestReader.cc,$(eval xfile:=$(wildcard src/TotemAlignment/RPTrackBased/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/RPTrackBased/test/$(file). Please fix src/TotemAlignment/RPTrackBased/test/BuildFile.))))
TaskDataTestReader := self/src/TotemAlignment/RPTrackBased/test
TaskDataTestReader_TEST_RUNNER_CMD :=  TaskDataTestReader 
TaskDataTestReader_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPTrackBased/test/BuildFile
TaskDataTestReader_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TaskDataTestReader_LOC_USE := self  TotemAlignment/RPTrackBased
TaskDataTestReader_PACKAGE := self/src/TotemAlignment/RPTrackBased/test
ALL_PRODS += TaskDataTestReader
TaskDataTestReader_INIT_FUNC        += $$(eval $$(call Binary,TaskDataTestReader,src/TotemAlignment/RPTrackBased/test,src_TotemAlignment_RPTrackBased_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TaskDataTestReader,src/TotemAlignment/RPTrackBased/test))
endif
ALL_COMMONRULES += src_TotemAlignment_RPTrackBased_test
src_TotemAlignment_RPTrackBased_test_parent := TotemAlignment/RPTrackBased
src_TotemAlignment_RPTrackBased_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_RPTrackBased_test,src/TotemAlignment/RPTrackBased/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/T1Alignment)
subdirs_src_TotemAlignment_T1Alignment := src_TotemAlignment_T1Alignment_test src_TotemAlignment_T1Alignment_plugins src_TotemAlignment_T1Alignment_python src_TotemAlignment_T1Alignment_src
ifeq ($(strip $(TotemAlignmentT1AlignmentPlugins)),)
TotemAlignmentT1AlignmentPlugins_files := $(patsubst src/TotemAlignment/T1Alignment/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAlignment/T1Alignment/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAlignment/T1Alignment/plugins/$(file). Please fix src/TotemAlignment/T1Alignment/plugins/BuildFile.))))
TotemAlignmentT1AlignmentPlugins := self/src/TotemAlignment/T1Alignment/plugins
TotemAlignmentT1AlignmentPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/T1Alignment/plugins/BuildFile
TotemAlignmentT1AlignmentPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/T1Road DataFormats/Common Geometry/TotemGeometry FWCore/ParameterSet CommonTools/Clustering1D boost root rootminuit2 clhep
TotemAlignmentT1AlignmentPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentT1AlignmentPlugins,TotemAlignmentT1AlignmentPlugins,$(SCRAMSTORENAME_LIB),src/TotemAlignment/T1Alignment/plugins))
TotemAlignmentT1AlignmentPlugins_PACKAGE := self/src/TotemAlignment/T1Alignment/plugins
ALL_PRODS += TotemAlignmentT1AlignmentPlugins
TotemAlignmentT1AlignmentPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentT1AlignmentPlugins,src/TotemAlignment/T1Alignment/plugins,src_TotemAlignment_T1Alignment_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAlignmentT1AlignmentPlugins,src/TotemAlignment/T1Alignment/plugins))
endif
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_plugins
src_TotemAlignment_T1Alignment_plugins_parent := TotemAlignment/T1Alignment
src_TotemAlignment_T1Alignment_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_plugins,src/TotemAlignment/T1Alignment/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAlignmentT1Alignment)),)
PyTotemAlignmentT1Alignment := self/src/TotemAlignment/T1Alignment/python
src_TotemAlignment_T1Alignment_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/T1Alignment/python)
PyTotemAlignmentT1Alignment_files := $(patsubst src/TotemAlignment/T1Alignment/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T1Alignment/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentT1Alignment_LOC_USE := self  
PyTotemAlignmentT1Alignment_PACKAGE := self/src/TotemAlignment/T1Alignment/python
ALL_PRODS += PyTotemAlignmentT1Alignment
PyTotemAlignmentT1Alignment_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/python,src_TotemAlignment_T1Alignment_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentT1Alignment,src/TotemAlignment/T1Alignment/python))
endif
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_python
src_TotemAlignment_T1Alignment_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_python,src/TotemAlignment/T1Alignment/python,PYTHON))
ALL_COMMONRULES += src_TotemAlignment_T1Alignment_test
src_TotemAlignment_T1Alignment_test_parent := TotemAlignment/T1Alignment
src_TotemAlignment_T1Alignment_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T1Alignment_test,src/TotemAlignment/T1Alignment/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAlignment/T2TrkBasedInternalAlignment)
subdirs_src_TotemAlignment_T2TrkBasedInternalAlignment := src_TotemAlignment_T2TrkBasedInternalAlignment_test src_TotemAlignment_T2TrkBasedInternalAlignment_interface src_TotemAlignment_T2TrkBasedInternalAlignment_python src_TotemAlignment_T2TrkBasedInternalAlignment_src
ifeq ($(strip $(PyTotemAlignmentT2TrkBasedInternalAlignment)),)
PyTotemAlignmentT2TrkBasedInternalAlignment := self/src/TotemAlignment/T2TrkBasedInternalAlignment/python
src_TotemAlignment_T2TrkBasedInternalAlignment_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAlignment/T2TrkBasedInternalAlignment/python)
PyTotemAlignmentT2TrkBasedInternalAlignment_files := $(patsubst src/TotemAlignment/T2TrkBasedInternalAlignment/python/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T2TrkBasedInternalAlignment/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAlignmentT2TrkBasedInternalAlignment_LOC_USE := self  
PyTotemAlignmentT2TrkBasedInternalAlignment_PACKAGE := self/src/TotemAlignment/T2TrkBasedInternalAlignment/python
ALL_PRODS += PyTotemAlignmentT2TrkBasedInternalAlignment
PyTotemAlignmentT2TrkBasedInternalAlignment_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/python,src_TotemAlignment_T2TrkBasedInternalAlignment_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/python))
endif
ALL_COMMONRULES += src_TotemAlignment_T2TrkBasedInternalAlignment_python
src_TotemAlignment_T2TrkBasedInternalAlignment_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T2TrkBasedInternalAlignment_python,src/TotemAlignment/T2TrkBasedInternalAlignment/python,PYTHON))
ifeq ($(strip $(TotemAlignment/T2TrkBasedInternalAlignment)),)
ALL_COMMONRULES += src_TotemAlignment_T2TrkBasedInternalAlignment_src
src_TotemAlignment_T2TrkBasedInternalAlignment_src_parent := TotemAlignment/T2TrkBasedInternalAlignment
src_TotemAlignment_T2TrkBasedInternalAlignment_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAlignment_T2TrkBasedInternalAlignment_src,src/TotemAlignment/T2TrkBasedInternalAlignment/src,LIBRARY))
TotemAlignmentT2TrkBasedInternalAlignment := self/TotemAlignment/T2TrkBasedInternalAlignment
TotemAlignment/T2TrkBasedInternalAlignment := TotemAlignmentT2TrkBasedInternalAlignment
TotemAlignmentT2TrkBasedInternalAlignment_files := $(patsubst src/TotemAlignment/T2TrkBasedInternalAlignment/src/%,%,$(wildcard $(foreach dir,src/TotemAlignment/T2TrkBasedInternalAlignment/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAlignmentT2TrkBasedInternalAlignment_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/T2TrkBasedInternalAlignment/BuildFile
TotemAlignmentT2TrkBasedInternalAlignment_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts clhep DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road rootminuit2 rootrflx rootminuit
TotemAlignmentT2TrkBasedInternalAlignment_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAlignmentT2TrkBasedInternalAlignment,TotemAlignmentT2TrkBasedInternalAlignment,$(SCRAMSTORENAME_LIB),src/TotemAlignment/T2TrkBasedInternalAlignment/src))
TotemAlignmentT2TrkBasedInternalAlignment_PACKAGE := self/src/TotemAlignment/T2TrkBasedInternalAlignment/src
ALL_PRODS += TotemAlignmentT2TrkBasedInternalAlignment
TotemAlignmentT2TrkBasedInternalAlignment_INIT_FUNC        += $$(eval $$(call Library,TotemAlignmentT2TrkBasedInternalAlignment,src/TotemAlignment/T2TrkBasedInternalAlignment/src,src_TotemAlignment_T2TrkBasedInternalAlignment_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemAlignment_T2TrkBasedInternalAlignment_test
src_TotemAlignment_T2TrkBasedInternalAlignment_test_parent := TotemAlignment/T2TrkBasedInternalAlignment
src_TotemAlignment_T2TrkBasedInternalAlignment_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAlignment_T2TrkBasedInternalAlignment_test,src/TotemAlignment/T2TrkBasedInternalAlignment/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemAnalysis)
subdirs_src_TotemAnalysis = src_TotemAnalysis_T1Analysis src_TotemAnalysis_TotemAnalysisEvent src_TotemAnalysis_TestBeam src_TotemAnalysis_T2HalfQuarterTrkEfficiency src_TotemAnalysis_T2Cuts src_TotemAnalysis_TotemNtuplizer src_TotemAnalysis_RPTimingDetectorsAnalysis src_TotemAnalysis_TotemRPAnalysis src_TotemAnalysis_T2DEVNtuplizer src_TotemAnalysis_T2ValidRawData
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/RPTimingDetectorsAnalysis)
subdirs_src_TotemAnalysis_RPTimingDetectorsAnalysis := src_TotemAnalysis_RPTimingDetectorsAnalysis_test src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins src_TotemAnalysis_RPTimingDetectorsAnalysis_python src_TotemAnalysis_RPTimingDetectorsAnalysis_doc
ifeq ($(strip $(TotemAnalysisRPTimingDetectorsAnalysisAuto)),)
TotemAnalysisRPTimingDetectorsAnalysisAuto_files := $(patsubst src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisRPTimingDetectorsAnalysisAuto := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins
TotemAnalysisRPTimingDetectorsAnalysisAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins/BuildFile
TotemAnalysisRPTimingDetectorsAnalysisAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet SimDataFormats/TrackingHit boost geant4 DataFormats/TotemRPDetId CommonTools/UtilAlgos PhysicsTools/UtilAlgos Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemAnalysisRPTimingDetectorsAnalysisAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisRPTimingDetectorsAnalysisAuto,TotemAnalysisRPTimingDetectorsAnalysisAuto,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins))
TotemAnalysisRPTimingDetectorsAnalysisAuto_PACKAGE := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins
ALL_PRODS += TotemAnalysisRPTimingDetectorsAnalysisAuto
TotemAnalysisRPTimingDetectorsAnalysisAuto_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisRPTimingDetectorsAnalysisAuto,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins,src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisRPTimingDetectorsAnalysisAuto,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins
src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins_parent := TotemAnalysis/RPTimingDetectorsAnalysis
src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_RPTimingDetectorsAnalysis_plugins,src/TotemAnalysis/RPTimingDetectorsAnalysis/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAnalysisRPTimingDetectorsAnalysis)),)
PyTotemAnalysisRPTimingDetectorsAnalysis := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/python
src_TotemAnalysis_RPTimingDetectorsAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/RPTimingDetectorsAnalysis/python)
PyTotemAnalysisRPTimingDetectorsAnalysis_files := $(patsubst src/TotemAnalysis/RPTimingDetectorsAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/RPTimingDetectorsAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisRPTimingDetectorsAnalysis_LOC_USE := self  
PyTotemAnalysisRPTimingDetectorsAnalysis_PACKAGE := self/src/TotemAnalysis/RPTimingDetectorsAnalysis/python
ALL_PRODS += PyTotemAnalysisRPTimingDetectorsAnalysis
PyTotemAnalysisRPTimingDetectorsAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisRPTimingDetectorsAnalysis,src/TotemAnalysis/RPTimingDetectorsAnalysis/python,src_TotemAnalysis_RPTimingDetectorsAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisRPTimingDetectorsAnalysis,src/TotemAnalysis/RPTimingDetectorsAnalysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_RPTimingDetectorsAnalysis_python
src_TotemAnalysis_RPTimingDetectorsAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_RPTimingDetectorsAnalysis_python,src/TotemAnalysis/RPTimingDetectorsAnalysis/python,PYTHON))
ALL_COMMONRULES += src_TotemAnalysis_RPTimingDetectorsAnalysis_test
src_TotemAnalysis_RPTimingDetectorsAnalysis_test_parent := TotemAnalysis/RPTimingDetectorsAnalysis
src_TotemAnalysis_RPTimingDetectorsAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_RPTimingDetectorsAnalysis_test,src/TotemAnalysis/RPTimingDetectorsAnalysis/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/T1Analysis)
subdirs_src_TotemAnalysis_T1Analysis := src_TotemAnalysis_T1Analysis_interface src_TotemAnalysis_T1Analysis_plugins src_TotemAnalysis_T1Analysis_python
ifeq ($(strip $(TotemAnalysisT1AnalysisPlugins)),)
TotemAnalysisT1AnalysisPlugins_files := $(patsubst src/TotemAnalysis/T1Analysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/T1Analysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/T1Analysis/plugins/$(file). Please fix src/TotemAnalysis/T1Analysis/plugins/BuildFile.))))
TotemAnalysisT1AnalysisPlugins := self/src/TotemAnalysis/T1Analysis/plugins
TotemAnalysisT1AnalysisPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T1Analysis/plugins/BuildFile
TotemAnalysisT1AnalysisPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry clhep root boost DataFormats/Common TotemCondFormats/DataRecord Geometry/TotemRecords DataFormats/TotemL1Trigger DataFormats/T2Cluster DataFormats/T2DetId DataFormats/T1Cluster DataFormats/T1DetId Geometry/TotemGeometry TotemAnalysis/T2Cuts DataFormats/T2Road DataFormats/T1Road
TotemAnalysisT1AnalysisPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT1AnalysisPlugins,TotemAnalysisT1AnalysisPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T1Analysis/plugins))
TotemAnalysisT1AnalysisPlugins_PACKAGE := self/src/TotemAnalysis/T1Analysis/plugins
ALL_PRODS += TotemAnalysisT1AnalysisPlugins
TotemAnalysisT1AnalysisPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT1AnalysisPlugins,src/TotemAnalysis/T1Analysis/plugins,src_TotemAnalysis_T1Analysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisT1AnalysisPlugins,src/TotemAnalysis/T1Analysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_T1Analysis_plugins
src_TotemAnalysis_T1Analysis_plugins_parent := TotemAnalysis/T1Analysis
src_TotemAnalysis_T1Analysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T1Analysis_plugins,src/TotemAnalysis/T1Analysis/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAnalysisT1Analysis)),)
PyTotemAnalysisT1Analysis := self/src/TotemAnalysis/T1Analysis/python
src_TotemAnalysis_T1Analysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T1Analysis/python)
PyTotemAnalysisT1Analysis_files := $(patsubst src/TotemAnalysis/T1Analysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T1Analysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT1Analysis_LOC_USE := self  
PyTotemAnalysisT1Analysis_PACKAGE := self/src/TotemAnalysis/T1Analysis/python
ALL_PRODS += PyTotemAnalysisT1Analysis
PyTotemAnalysisT1Analysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT1Analysis,src/TotemAnalysis/T1Analysis/python,src_TotemAnalysis_T1Analysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT1Analysis,src/TotemAnalysis/T1Analysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T1Analysis_python
src_TotemAnalysis_T1Analysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T1Analysis_python,src/TotemAnalysis/T1Analysis/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/T2Cuts)
subdirs_src_TotemAnalysis_T2Cuts := src_TotemAnalysis_T2Cuts_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/T2DEVNtuplizer)
subdirs_src_TotemAnalysis_T2DEVNtuplizer := src_TotemAnalysis_T2DEVNtuplizer_interface src_TotemAnalysis_T2DEVNtuplizer_plugins src_TotemAnalysis_T2DEVNtuplizer_python src_TotemAnalysis_T2DEVNtuplizer_src
ifeq ($(strip $(TotemAnalysisT2DEVNtuplizerPlugins)),)
TotemAnalysisT2DEVNtuplizerPlugins_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/T2DEVNtuplizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/T2DEVNtuplizer/plugins/$(file). Please fix src/TotemAnalysis/T2DEVNtuplizer/plugins/BuildFile.))))
TotemAnalysisT2DEVNtuplizerPlugins := self/src/TotemAnalysis/T2DEVNtuplizer/plugins
TotemAnalysisT2DEVNtuplizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2DEVNtuplizer/plugins/BuildFile
TotemAnalysisT2DEVNtuplizerPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry TotemAnalysis/T2DEVNtuplizer SimGeneral/HepPDTRecord
TotemAnalysisT2DEVNtuplizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2DEVNtuplizerPlugins,TotemAnalysisT2DEVNtuplizerPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2DEVNtuplizer/plugins))
TotemAnalysisT2DEVNtuplizerPlugins_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/plugins
ALL_PRODS += TotemAnalysisT2DEVNtuplizerPlugins
TotemAnalysisT2DEVNtuplizerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2DEVNtuplizerPlugins,src/TotemAnalysis/T2DEVNtuplizer/plugins,src_TotemAnalysis_T2DEVNtuplizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisT2DEVNtuplizerPlugins,src/TotemAnalysis/T2DEVNtuplizer/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_plugins
src_TotemAnalysis_T2DEVNtuplizer_plugins_parent := TotemAnalysis/T2DEVNtuplizer
src_TotemAnalysis_T2DEVNtuplizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_plugins,src/TotemAnalysis/T2DEVNtuplizer/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAnalysisT2DEVNtuplizer)),)
PyTotemAnalysisT2DEVNtuplizer := self/src/TotemAnalysis/T2DEVNtuplizer/python
src_TotemAnalysis_T2DEVNtuplizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2DEVNtuplizer/python)
PyTotemAnalysisT2DEVNtuplizer_files := $(patsubst src/TotemAnalysis/T2DEVNtuplizer/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2DEVNtuplizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2DEVNtuplizer_LOC_USE := self  
PyTotemAnalysisT2DEVNtuplizer_PACKAGE := self/src/TotemAnalysis/T2DEVNtuplizer/python
ALL_PRODS += PyTotemAnalysisT2DEVNtuplizer
PyTotemAnalysisT2DEVNtuplizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/python,src_TotemAnalysis_T2DEVNtuplizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2DEVNtuplizer,src/TotemAnalysis/T2DEVNtuplizer/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2DEVNtuplizer_python
src_TotemAnalysis_T2DEVNtuplizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2DEVNtuplizer_python,src/TotemAnalysis/T2DEVNtuplizer/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/T2HalfQuarterTrkEfficiency)
subdirs_src_TotemAnalysis_T2HalfQuarterTrkEfficiency := src_TotemAnalysis_T2HalfQuarterTrkEfficiency_test src_TotemAnalysis_T2HalfQuarterTrkEfficiency_interface src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src
ifeq ($(strip $(PyTotemAnalysisT2HalfQuarterTrkEfficiency)),)
PyTotemAnalysisT2HalfQuarterTrkEfficiency := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python)
PyTotemAnalysisT2HalfQuarterTrkEfficiency_files := $(patsubst src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2HalfQuarterTrkEfficiency_LOC_USE := self  
PyTotemAnalysisT2HalfQuarterTrkEfficiency_PACKAGE := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python
ALL_PRODS += PyTotemAnalysisT2HalfQuarterTrkEfficiency
PyTotemAnalysisT2HalfQuarterTrkEfficiency_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_python,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/python,PYTHON))
ifeq ($(strip $(TotemAnalysis/T2HalfQuarterTrkEfficiency)),)
ALL_COMMONRULES += src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src_parent := TotemAnalysis/T2HalfQuarterTrkEfficiency
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src,LIBRARY))
TotemAnalysisT2HalfQuarterTrkEfficiency := self/TotemAnalysis/T2HalfQuarterTrkEfficiency
TotemAnalysis/T2HalfQuarterTrkEfficiency := TotemAnalysisT2HalfQuarterTrkEfficiency
TotemAnalysisT2HalfQuarterTrkEfficiency_files := $(patsubst src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2HalfQuarterTrkEfficiency_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/BuildFile
TotemAnalysisT2HalfQuarterTrkEfficiency_LOC_USE := self  boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root rootcore SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemAnalysis/T2Cuts DataFormats/T1T2Track clhep xerces-c
TotemAnalysisT2HalfQuarterTrkEfficiency_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2HalfQuarterTrkEfficiency,TotemAnalysisT2HalfQuarterTrkEfficiency,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src))
TotemAnalysisT2HalfQuarterTrkEfficiency_PACKAGE := self/src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src
ALL_PRODS += TotemAnalysisT2HalfQuarterTrkEfficiency
TotemAnalysisT2HalfQuarterTrkEfficiency_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2HalfQuarterTrkEfficiency,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/src,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2HalfQuarterTrkEfficiency_test
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_test_parent := TotemAnalysis/T2HalfQuarterTrkEfficiency
src_TotemAnalysis_T2HalfQuarterTrkEfficiency_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2HalfQuarterTrkEfficiency_test,src/TotemAnalysis/T2HalfQuarterTrkEfficiency/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/T2ValidRawData)
subdirs_src_TotemAnalysis_T2ValidRawData := src_TotemAnalysis_T2ValidRawData_test src_TotemAnalysis_T2ValidRawData_python src_TotemAnalysis_T2ValidRawData_src
ifeq ($(strip $(PyTotemAnalysisT2ValidRawData)),)
PyTotemAnalysisT2ValidRawData := self/src/TotemAnalysis/T2ValidRawData/python
src_TotemAnalysis_T2ValidRawData_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/T2ValidRawData/python)
PyTotemAnalysisT2ValidRawData_files := $(patsubst src/TotemAnalysis/T2ValidRawData/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2ValidRawData/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisT2ValidRawData_LOC_USE := self  
PyTotemAnalysisT2ValidRawData_PACKAGE := self/src/TotemAnalysis/T2ValidRawData/python
ALL_PRODS += PyTotemAnalysisT2ValidRawData
PyTotemAnalysisT2ValidRawData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/python,src_TotemAnalysis_T2ValidRawData_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2ValidRawData_python
src_TotemAnalysis_T2ValidRawData_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2ValidRawData_python,src/TotemAnalysis/T2ValidRawData/python,PYTHON))
ifeq ($(strip $(TotemAnalysis/T2ValidRawData)),)
ALL_COMMONRULES += src_TotemAnalysis_T2ValidRawData_src
src_TotemAnalysis_T2ValidRawData_src_parent := TotemAnalysis/T2ValidRawData
src_TotemAnalysis_T2ValidRawData_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2ValidRawData_src,src/TotemAnalysis/T2ValidRawData/src,LIBRARY))
TotemAnalysisT2ValidRawData := self/TotemAnalysis/T2ValidRawData
TotemAnalysis/T2ValidRawData := TotemAnalysisT2ValidRawData
TotemAnalysisT2ValidRawData_files := $(patsubst src/TotemAnalysis/T2ValidRawData/src/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/T2ValidRawData/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemAnalysisT2ValidRawData_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/T2ValidRawData/BuildFile
TotemAnalysisT2ValidRawData_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts clhep DataFormats/T2Cluster DataFormats/T2DetId TotemAnalysis/T2Cuts Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord xerces-c
TotemAnalysisT2ValidRawData_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisT2ValidRawData,TotemAnalysisT2ValidRawData,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/T2ValidRawData/src))
TotemAnalysisT2ValidRawData_PACKAGE := self/src/TotemAnalysis/T2ValidRawData/src
ALL_PRODS += TotemAnalysisT2ValidRawData
TotemAnalysisT2ValidRawData_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisT2ValidRawData,src/TotemAnalysis/T2ValidRawData/src,src_TotemAnalysis_T2ValidRawData_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemAnalysis_T2ValidRawData_test
src_TotemAnalysis_T2ValidRawData_test_parent := TotemAnalysis/T2ValidRawData
src_TotemAnalysis_T2ValidRawData_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_T2ValidRawData_test,src/TotemAnalysis/T2ValidRawData/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/TestBeam)
subdirs_src_TotemAnalysis_TestBeam := src_TotemAnalysis_TestBeam_interface src_TotemAnalysis_TestBeam_plugins src_TotemAnalysis_TestBeam_src
ifeq ($(strip $(TotemAnalysisTestBeamPlugins)),)
TotemAnalysisTestBeamPlugins_files := $(patsubst src/TotemAnalysis/TestBeam/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TestBeam/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TestBeam/plugins/$(file). Please fix src/TotemAnalysis/TestBeam/plugins/BuildFile.))))
TotemAnalysisTestBeamPlugins := self/src/TotemAnalysis/TestBeam/plugins
TotemAnalysisTestBeamPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TestBeam/plugins/BuildFile
TotemAnalysisTestBeamPlugins_LOC_FLAGS_CXXFLAGS   := -g3 -O3 $(CUSTOM_FLAGS)
TotemAnalysisTestBeamPlugins_LOC_USE := self  FWCore/Framework Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords TotemAnalysis/TestBeam root rootgraphics
TotemAnalysisTestBeamPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTestBeamPlugins,TotemAnalysisTestBeamPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TestBeam/plugins))
TotemAnalysisTestBeamPlugins_PACKAGE := self/src/TotemAnalysis/TestBeam/plugins
ALL_PRODS += TotemAnalysisTestBeamPlugins
TotemAnalysisTestBeamPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTestBeamPlugins,src/TotemAnalysis/TestBeam/plugins,src_TotemAnalysis_TestBeam_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTestBeamPlugins,src/TotemAnalysis/TestBeam/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TestBeam_plugins
src_TotemAnalysis_TestBeam_plugins_parent := TotemAnalysis/TestBeam
src_TotemAnalysis_TestBeam_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TestBeam_plugins,src/TotemAnalysis/TestBeam/plugins,PLUGINS))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/TotemNtuplizer)
subdirs_src_TotemAnalysis_TotemNtuplizer := src_TotemAnalysis_TotemNtuplizer_plugins src_TotemAnalysis_TotemNtuplizer_python src_TotemAnalysis_TotemNtuplizer_src src_TotemAnalysis_TotemNtuplizer_test
ifeq ($(strip $(TotemAnalysisTotemNtuplizerPlugins)),)
TotemAnalysisTotemNtuplizerPlugins_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TotemNtuplizer/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TotemNtuplizer/plugins/$(file). Please fix src/TotemAnalysis/TotemNtuplizer/plugins/BuildFile.))))
TotemAnalysisTotemNtuplizerPlugins := self/src/TotemAnalysis/TotemNtuplizer/plugins
TotemAnalysisTotemNtuplizerPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemNtuplizer/plugins/BuildFile
TotemAnalysisTotemNtuplizerPlugins_LOC_USE := self  FWCore/Framework FWCore/ServiceRegistry TotemAnalysis/TotemNtuplizer TotemAnalysis/TotemAnalysisEvent
TotemAnalysisTotemNtuplizerPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTotemNtuplizerPlugins,TotemAnalysisTotemNtuplizerPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TotemNtuplizer/plugins))
TotemAnalysisTotemNtuplizerPlugins_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/plugins
ALL_PRODS += TotemAnalysisTotemNtuplizerPlugins
TotemAnalysisTotemNtuplizerPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemNtuplizerPlugins,src/TotemAnalysis/TotemNtuplizer/plugins,src_TotemAnalysis_TotemNtuplizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTotemNtuplizerPlugins,src/TotemAnalysis/TotemNtuplizer/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_plugins
src_TotemAnalysis_TotemNtuplizer_plugins_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_plugins,src/TotemAnalysis/TotemNtuplizer/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAnalysisTotemNtuplizer)),)
PyTotemAnalysisTotemNtuplizer := self/src/TotemAnalysis/TotemNtuplizer/python
src_TotemAnalysis_TotemNtuplizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/TotemNtuplizer/python)
PyTotemAnalysisTotemNtuplizer_files := $(patsubst src/TotemAnalysis/TotemNtuplizer/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemNtuplizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisTotemNtuplizer_LOC_USE := self  
PyTotemAnalysisTotemNtuplizer_PACKAGE := self/src/TotemAnalysis/TotemNtuplizer/python
ALL_PRODS += PyTotemAnalysisTotemNtuplizer
PyTotemAnalysisTotemNtuplizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/python,src_TotemAnalysis_TotemNtuplizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisTotemNtuplizer,src/TotemAnalysis/TotemNtuplizer/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_python
src_TotemAnalysis_TotemNtuplizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_python,src/TotemAnalysis/TotemNtuplizer/python,PYTHON))
ALL_COMMONRULES += src_TotemAnalysis_TotemNtuplizer_test
src_TotemAnalysis_TotemNtuplizer_test_parent := TotemAnalysis/TotemNtuplizer
src_TotemAnalysis_TotemNtuplizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemNtuplizer_test,src/TotemAnalysis/TotemNtuplizer/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemCondFormats)
subdirs_src_TotemCondFormats = src_TotemCondFormats_BeamOpticsParamsObjects src_TotemCondFormats_ProtonTransportFunctions src_TotemCondFormats_DataRecord src_TotemCondFormats_DAQInformation
ALL_PACKAGES += $(patsubst src/%,%,src/TotemCondFormats/BeamOpticsParamsObjects)
subdirs_src_TotemCondFormats_BeamOpticsParamsObjects := src_TotemCondFormats_BeamOpticsParamsObjects_interface src_TotemCondFormats_BeamOpticsParamsObjects_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemCondFormats/DAQInformation)
subdirs_src_TotemCondFormats_DAQInformation := src_TotemCondFormats_DAQInformation_test src_TotemCondFormats_DAQInformation_interface src_TotemCondFormats_DAQInformation_plugins src_TotemCondFormats_DAQInformation_python src_TotemCondFormats_DAQInformation_scripts src_TotemCondFormats_DAQInformation_src
ifeq ($(strip $(TotemCondFormatsDAQInformationPlugins)),)
TotemCondFormatsDAQInformationPlugins_files := $(patsubst src/TotemCondFormats/DAQInformation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemCondFormats/DAQInformation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemCondFormats/DAQInformation/plugins/$(file). Please fix src/TotemCondFormats/DAQInformation/plugins/BuildFile.))))
TotemCondFormatsDAQInformationPlugins := self/src/TotemCondFormats/DAQInformation/plugins
TotemCondFormatsDAQInformationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/DAQInformation/plugins/BuildFile
TotemCondFormatsDAQInformationPlugins_LOC_USE := self  FWCore/Framework TotemCondFormats/DataRecord TotemCondFormats/DAQInformation xerces-c
TotemCondFormatsDAQInformationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemCondFormatsDAQInformationPlugins,TotemCondFormatsDAQInformationPlugins,$(SCRAMSTORENAME_LIB),src/TotemCondFormats/DAQInformation/plugins))
TotemCondFormatsDAQInformationPlugins_PACKAGE := self/src/TotemCondFormats/DAQInformation/plugins
ALL_PRODS += TotemCondFormatsDAQInformationPlugins
TotemCondFormatsDAQInformationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsDAQInformationPlugins,src/TotemCondFormats/DAQInformation/plugins,src_TotemCondFormats_DAQInformation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCondFormatsDAQInformationPlugins,src/TotemCondFormats/DAQInformation/plugins))
endif
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_plugins
src_TotemCondFormats_DAQInformation_plugins_parent := TotemCondFormats/DAQInformation
src_TotemCondFormats_DAQInformation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_plugins,src/TotemCondFormats/DAQInformation/plugins,PLUGINS))
ifeq ($(strip $(PyTotemCondFormatsDAQInformation)),)
PyTotemCondFormatsDAQInformation := self/src/TotemCondFormats/DAQInformation/python
src_TotemCondFormats_DAQInformation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemCondFormats/DAQInformation/python)
PyTotemCondFormatsDAQInformation_files := $(patsubst src/TotemCondFormats/DAQInformation/python/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/DAQInformation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemCondFormatsDAQInformation_LOC_USE := self  
PyTotemCondFormatsDAQInformation_PACKAGE := self/src/TotemCondFormats/DAQInformation/python
ALL_PRODS += PyTotemCondFormatsDAQInformation
PyTotemCondFormatsDAQInformation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/python,src_TotemCondFormats_DAQInformation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemCondFormatsDAQInformation,src/TotemCondFormats/DAQInformation/python))
endif
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_python
src_TotemCondFormats_DAQInformation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_python,src/TotemCondFormats/DAQInformation/python,PYTHON))
src_TotemCondFormats_DAQInformation_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemCondFormats/DAQInformation/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemCondFormats_DAQInformation_scripts,src/TotemCondFormats/DAQInformation/scripts,$(SCRAMSTORENAME_BIN),*))
ALL_COMMONRULES += src_TotemCondFormats_DAQInformation_test
src_TotemCondFormats_DAQInformation_test_parent := TotemCondFormats/DAQInformation
src_TotemCondFormats_DAQInformation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_DAQInformation_test,src/TotemCondFormats/DAQInformation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemCondFormats/DataRecord)
subdirs_src_TotemCondFormats_DataRecord := src_TotemCondFormats_DataRecord_interface src_TotemCondFormats_DataRecord_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemCondFormats/ProtonTransportFunctions)
subdirs_src_TotemCondFormats_ProtonTransportFunctions := src_TotemCondFormats_ProtonTransportFunctions_interface src_TotemCondFormats_ProtonTransportFunctions_plugins src_TotemCondFormats_ProtonTransportFunctions_python src_TotemCondFormats_ProtonTransportFunctions_src
ifeq ($(strip $(TotemCondFormatsProtonTransportFunctionsPlugins)),)
TotemCondFormatsProtonTransportFunctionsPlugins_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemCondFormats/ProtonTransportFunctions/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemCondFormats/ProtonTransportFunctions/plugins/$(file). Please fix src/TotemCondFormats/ProtonTransportFunctions/plugins/BuildFile.))))
TotemCondFormatsProtonTransportFunctionsPlugins := self/src/TotemCondFormats/ProtonTransportFunctions/plugins
TotemCondFormatsProtonTransportFunctionsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemCondFormats/ProtonTransportFunctions/plugins/BuildFile
TotemCondFormatsProtonTransportFunctionsPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet root TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects SimG4CMS/TotemRPProtTranspPar clhep Geometry/TotemRecords Geometry/TotemRPGeometryBuilder TotemCondFormats/ProtonTransportFunctions
TotemCondFormatsProtonTransportFunctionsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemCondFormatsProtonTransportFunctionsPlugins,TotemCondFormatsProtonTransportFunctionsPlugins,$(SCRAMSTORENAME_LIB),src/TotemCondFormats/ProtonTransportFunctions/plugins))
TotemCondFormatsProtonTransportFunctionsPlugins_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/plugins
ALL_PRODS += TotemCondFormatsProtonTransportFunctionsPlugins
TotemCondFormatsProtonTransportFunctionsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemCondFormatsProtonTransportFunctionsPlugins,src/TotemCondFormats/ProtonTransportFunctions/plugins,src_TotemCondFormats_ProtonTransportFunctions_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCondFormatsProtonTransportFunctionsPlugins,src/TotemCondFormats/ProtonTransportFunctions/plugins))
endif
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_plugins
src_TotemCondFormats_ProtonTransportFunctions_plugins_parent := TotemCondFormats/ProtonTransportFunctions
src_TotemCondFormats_ProtonTransportFunctions_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_plugins,src/TotemCondFormats/ProtonTransportFunctions/plugins,PLUGINS))
ifeq ($(strip $(PyTotemCondFormatsProtonTransportFunctions)),)
PyTotemCondFormatsProtonTransportFunctions := self/src/TotemCondFormats/ProtonTransportFunctions/python
src_TotemCondFormats_ProtonTransportFunctions_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemCondFormats/ProtonTransportFunctions/python)
PyTotemCondFormatsProtonTransportFunctions_files := $(patsubst src/TotemCondFormats/ProtonTransportFunctions/python/%,%,$(wildcard $(foreach dir,src/TotemCondFormats/ProtonTransportFunctions/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemCondFormatsProtonTransportFunctions_LOC_USE := self  
PyTotemCondFormatsProtonTransportFunctions_PACKAGE := self/src/TotemCondFormats/ProtonTransportFunctions/python
ALL_PRODS += PyTotemCondFormatsProtonTransportFunctions
PyTotemCondFormatsProtonTransportFunctions_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/python,src_TotemCondFormats_ProtonTransportFunctions_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemCondFormatsProtonTransportFunctions,src/TotemCondFormats/ProtonTransportFunctions/python))
endif
ALL_COMMONRULES += src_TotemCondFormats_ProtonTransportFunctions_python
src_TotemCondFormats_ProtonTransportFunctions_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemCondFormats_ProtonTransportFunctions_python,src/TotemCondFormats/ProtonTransportFunctions/python,PYTHON))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemDQMLite)
subdirs_src_TotemDQMLite = src_TotemDQMLite_GUI src_TotemDQMLite_Core src_TotemDQMLite_Modules src_TotemDQMLite_Geometry
ALL_PACKAGES += $(patsubst src/%,%,src/TotemDQMLite/Core)
subdirs_src_TotemDQMLite_Core := src_TotemDQMLite_Core_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemDQMLite/GUI)
subdirs_src_TotemDQMLite_GUI := src_TotemDQMLite_GUI_python src_TotemDQMLite_GUI_scripts src_TotemDQMLite_GUI_src src_TotemDQMLite_GUI_bin
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
ifeq ($(strip $(PyTotemDQMLiteGUI)),)
PyTotemDQMLiteGUI := self/src/TotemDQMLite/GUI/python
src_TotemDQMLite_GUI_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemDQMLite/GUI/python)
PyTotemDQMLiteGUI_files := $(patsubst src/TotemDQMLite/GUI/python/%,%,$(wildcard $(foreach dir,src/TotemDQMLite/GUI/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemDQMLiteGUI_LOC_USE := self  
PyTotemDQMLiteGUI_PACKAGE := self/src/TotemDQMLite/GUI/python
ALL_PRODS += PyTotemDQMLiteGUI
PyTotemDQMLiteGUI_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemDQMLiteGUI,src/TotemDQMLite/GUI/python,src_TotemDQMLite_GUI_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemDQMLiteGUI,src/TotemDQMLite/GUI/python))
endif
ALL_COMMONRULES += src_TotemDQMLite_GUI_python
src_TotemDQMLite_GUI_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_GUI_python,src/TotemDQMLite/GUI/python,PYTHON))
src_TotemDQMLite_GUI_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemDQMLite/GUI/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemDQMLite_GUI_scripts,src/TotemDQMLite/GUI/scripts,$(SCRAMSTORENAME_BIN),*))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemDQMLite/Geometry)
subdirs_src_TotemDQMLite_Geometry := src_TotemDQMLite_Geometry_test src_TotemDQMLite_Geometry_plugins src_TotemDQMLite_Geometry_src
ifeq ($(strip $(TotemDQMLiteGeometryPlugins)),)
TotemDQMLiteGeometryPlugins_files := $(patsubst src/TotemDQMLite/Geometry/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemDQMLite/Geometry/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemDQMLite/Geometry/plugins/$(file). Please fix src/TotemDQMLite/Geometry/plugins/BuildFile.))))
TotemDQMLiteGeometryPlugins := self/src/TotemDQMLite/Geometry/plugins
TotemDQMLiteGeometryPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemDQMLite/Geometry/plugins/BuildFile
TotemDQMLiteGeometryPlugins_LOC_USE := self  Geometry/TotemRPGeometryBuilder
TotemDQMLiteGeometryPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemDQMLiteGeometryPlugins,TotemDQMLiteGeometryPlugins,$(SCRAMSTORENAME_LIB),src/TotemDQMLite/Geometry/plugins))
TotemDQMLiteGeometryPlugins_PACKAGE := self/src/TotemDQMLite/Geometry/plugins
ALL_PRODS += TotemDQMLiteGeometryPlugins
TotemDQMLiteGeometryPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemDQMLiteGeometryPlugins,src/TotemDQMLite/Geometry/plugins,src_TotemDQMLite_Geometry_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemDQMLiteGeometryPlugins,src/TotemDQMLite/Geometry/plugins))
endif
ALL_COMMONRULES += src_TotemDQMLite_Geometry_plugins
src_TotemDQMLite_Geometry_plugins_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_plugins,src/TotemDQMLite/Geometry/plugins,PLUGINS))
ALL_COMMONRULES += src_TotemDQMLite_Geometry_test
src_TotemDQMLite_Geometry_test_parent := TotemDQMLite/Geometry
src_TotemDQMLite_Geometry_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemDQMLite_Geometry_test,src/TotemDQMLite/Geometry/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemDQMLite/Modules)
subdirs_src_TotemDQMLite_Modules := src_TotemDQMLite_Modules_interface src_TotemDQMLite_Modules_src
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemRPValidation)
subdirs_src_TotemRPValidation = src_TotemRPValidation_RecoTrackRP src_TotemRPValidation_RPPositionValidation src_TotemRPValidation_Acceptance src_TotemRPValidation_ElasticReconstruction src_TotemRPValidation_InelasticReconstructionValidation src_TotemRPValidation_EdgeEfficiency src_TotemRPValidation_BeamSmearing src_TotemRPValidation_ParamMADRefTransport src_TotemRPValidation_RPGeant4Validation src_TotemRPValidation_GeneratorValidation src_TotemRPValidation_BaseValidationClasses src_TotemRPValidation_RPAngleValidation src_TotemRPValidation_HitDistributions src_TotemRPValidation_TransportValidation src_TotemRPValidation_RPReconstructedTracksValidation src_TotemRPValidation_ValidationTools src_TotemRPValidation_ValidationPlots src_TotemRPValidation_Examples
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/Acceptance)
subdirs_src_TotemRPValidation_Acceptance := src_TotemRPValidation_Acceptance_plugins src_TotemRPValidation_Acceptance_python
ALL_COMMONRULES += src_TotemRPValidation_Acceptance_plugins
src_TotemRPValidation_Acceptance_plugins_parent := TotemRPValidation/Acceptance
src_TotemRPValidation_Acceptance_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_Acceptance_plugins,src/TotemRPValidation/Acceptance/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationAcceptance)),)
PyTotemRPValidationAcceptance := self/src/TotemRPValidation/Acceptance/python
src_TotemRPValidation_Acceptance_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/Acceptance/python)
PyTotemRPValidationAcceptance_files := $(patsubst src/TotemRPValidation/Acceptance/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/Acceptance/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationAcceptance_LOC_USE := self  
PyTotemRPValidationAcceptance_PACKAGE := self/src/TotemRPValidation/Acceptance/python
ALL_PRODS += PyTotemRPValidationAcceptance
PyTotemRPValidationAcceptance_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationAcceptance,src/TotemRPValidation/Acceptance/python,src_TotemRPValidation_Acceptance_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationAcceptance,src/TotemRPValidation/Acceptance/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_Acceptance_python
src_TotemRPValidation_Acceptance_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_Acceptance_python,src/TotemRPValidation/Acceptance/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/BaseValidationClasses)
subdirs_src_TotemRPValidation_BaseValidationClasses := src_TotemRPValidation_BaseValidationClasses_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/BeamSmearing)
subdirs_src_TotemRPValidation_BeamSmearing := src_TotemRPValidation_BeamSmearing_test src_TotemRPValidation_BeamSmearing_interface src_TotemRPValidation_BeamSmearing_plugins src_TotemRPValidation_BeamSmearing_python src_TotemRPValidation_BeamSmearing_src
ifeq ($(strip $(TotemRPValidationBeamSmearingPlugins)),)
TotemRPValidationBeamSmearingPlugins_files := $(patsubst src/TotemRPValidation/BeamSmearing/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/BeamSmearing/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/BeamSmearing/plugins/$(file). Please fix src/TotemRPValidation/BeamSmearing/plugins/BuildFile.))))
TotemRPValidationBeamSmearingPlugins := self/src/TotemRPValidation/BeamSmearing/plugins
TotemRPValidationBeamSmearingPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/BeamSmearing/plugins/BuildFile
TotemRPValidationBeamSmearingPlugins_LOC_USE := self  TotemRPValidation/BeamSmearing FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationBeamSmearingPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationBeamSmearingPlugins,TotemRPValidationBeamSmearingPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/BeamSmearing/plugins))
TotemRPValidationBeamSmearingPlugins_PACKAGE := self/src/TotemRPValidation/BeamSmearing/plugins
ALL_PRODS += TotemRPValidationBeamSmearingPlugins
TotemRPValidationBeamSmearingPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationBeamSmearingPlugins,src/TotemRPValidation/BeamSmearing/plugins,src_TotemRPValidation_BeamSmearing_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationBeamSmearingPlugins,src/TotemRPValidation/BeamSmearing/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_plugins
src_TotemRPValidation_BeamSmearing_plugins_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_plugins,src/TotemRPValidation/BeamSmearing/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationBeamSmearing)),)
PyTotemRPValidationBeamSmearing := self/src/TotemRPValidation/BeamSmearing/python
src_TotemRPValidation_BeamSmearing_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/BeamSmearing/python)
PyTotemRPValidationBeamSmearing_files := $(patsubst src/TotemRPValidation/BeamSmearing/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/BeamSmearing/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationBeamSmearing_LOC_USE := self  
PyTotemRPValidationBeamSmearing_PACKAGE := self/src/TotemRPValidation/BeamSmearing/python
ALL_PRODS += PyTotemRPValidationBeamSmearing
PyTotemRPValidationBeamSmearing_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/python,src_TotemRPValidation_BeamSmearing_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationBeamSmearing,src/TotemRPValidation/BeamSmearing/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_python
src_TotemRPValidation_BeamSmearing_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_python,src/TotemRPValidation/BeamSmearing/python,PYTHON))
ALL_COMMONRULES += src_TotemRPValidation_BeamSmearing_test
src_TotemRPValidation_BeamSmearing_test_parent := TotemRPValidation/BeamSmearing
src_TotemRPValidation_BeamSmearing_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_BeamSmearing_test,src/TotemRPValidation/BeamSmearing/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/EdgeEfficiency)
subdirs_src_TotemRPValidation_EdgeEfficiency := src_TotemRPValidation_EdgeEfficiency_test src_TotemRPValidation_EdgeEfficiency_interface src_TotemRPValidation_EdgeEfficiency_python src_TotemRPValidation_EdgeEfficiency_src
ifeq ($(strip $(PyTotemRPValidationEdgeEfficiency)),)
PyTotemRPValidationEdgeEfficiency := self/src/TotemRPValidation/EdgeEfficiency/python
src_TotemRPValidation_EdgeEfficiency_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/EdgeEfficiency/python)
PyTotemRPValidationEdgeEfficiency_files := $(patsubst src/TotemRPValidation/EdgeEfficiency/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/EdgeEfficiency/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationEdgeEfficiency_LOC_USE := self  
PyTotemRPValidationEdgeEfficiency_PACKAGE := self/src/TotemRPValidation/EdgeEfficiency/python
ALL_PRODS += PyTotemRPValidationEdgeEfficiency
PyTotemRPValidationEdgeEfficiency_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/python,src_TotemRPValidation_EdgeEfficiency_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_EdgeEfficiency_python
src_TotemRPValidation_EdgeEfficiency_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_EdgeEfficiency_python,src/TotemRPValidation/EdgeEfficiency/python,PYTHON))
ifeq ($(strip $(TotemRPValidation/EdgeEfficiency)),)
ALL_COMMONRULES += src_TotemRPValidation_EdgeEfficiency_src
src_TotemRPValidation_EdgeEfficiency_src_parent := TotemRPValidation/EdgeEfficiency
src_TotemRPValidation_EdgeEfficiency_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_EdgeEfficiency_src,src/TotemRPValidation/EdgeEfficiency/src,LIBRARY))
TotemRPValidationEdgeEfficiency := self/TotemRPValidation/EdgeEfficiency
TotemRPValidation/EdgeEfficiency := TotemRPValidationEdgeEfficiency
TotemRPValidationEdgeEfficiency_files := $(patsubst src/TotemRPValidation/EdgeEfficiency/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/EdgeEfficiency/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationEdgeEfficiency_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/EdgeEfficiency/BuildFile
TotemRPValidationEdgeEfficiency_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/Common DataFormats/TotemRPDataTypes Geometry/TotemRPGeometryBuilder RecoTotemRP/RPRecoDataFormats Geometry/Records DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses root rootgraphics rootinteractive rootrflx
TotemRPValidationEdgeEfficiency_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationEdgeEfficiency,TotemRPValidationEdgeEfficiency,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/EdgeEfficiency/src))
TotemRPValidationEdgeEfficiency_PACKAGE := self/src/TotemRPValidation/EdgeEfficiency/src
ALL_PRODS += TotemRPValidationEdgeEfficiency
TotemRPValidationEdgeEfficiency_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationEdgeEfficiency,src/TotemRPValidation/EdgeEfficiency/src,src_TotemRPValidation_EdgeEfficiency_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemRPValidation_EdgeEfficiency_test
src_TotemRPValidation_EdgeEfficiency_test_parent := TotemRPValidation/EdgeEfficiency
src_TotemRPValidation_EdgeEfficiency_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_EdgeEfficiency_test,src/TotemRPValidation/EdgeEfficiency/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/ElasticReconstruction)
subdirs_src_TotemRPValidation_ElasticReconstruction := src_TotemRPValidation_ElasticReconstruction_plugins src_TotemRPValidation_ElasticReconstruction_python src_TotemRPValidation_ElasticReconstruction_src
ifeq ($(strip $(TotemRPValidationElasticReconstructionPlugins)),)
TotemRPValidationElasticReconstructionPlugins_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ElasticReconstruction/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ElasticReconstruction/plugins/$(file). Please fix src/TotemRPValidation/ElasticReconstruction/plugins/BuildFile.))))
TotemRPValidationElasticReconstructionPlugins := self/src/TotemRPValidation/ElasticReconstruction/plugins
TotemRPValidationElasticReconstructionPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ElasticReconstruction/plugins/BuildFile
TotemRPValidationElasticReconstructionPlugins_LOC_USE := self  TotemRPValidation/ElasticReconstruction FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats TotemRPValidation/BaseValidationClasses root SimG4CMS/TotemRPProtTranspPar TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord
TotemRPValidationElasticReconstructionPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationElasticReconstructionPlugins,TotemRPValidationElasticReconstructionPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/ElasticReconstruction/plugins))
TotemRPValidationElasticReconstructionPlugins_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/plugins
ALL_PRODS += TotemRPValidationElasticReconstructionPlugins
TotemRPValidationElasticReconstructionPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationElasticReconstructionPlugins,src/TotemRPValidation/ElasticReconstruction/plugins,src_TotemRPValidation_ElasticReconstruction_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationElasticReconstructionPlugins,src/TotemRPValidation/ElasticReconstruction/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_plugins
src_TotemRPValidation_ElasticReconstruction_plugins_parent := TotemRPValidation/ElasticReconstruction
src_TotemRPValidation_ElasticReconstruction_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_plugins,src/TotemRPValidation/ElasticReconstruction/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationElasticReconstruction)),)
PyTotemRPValidationElasticReconstruction := self/src/TotemRPValidation/ElasticReconstruction/python
src_TotemRPValidation_ElasticReconstruction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/ElasticReconstruction/python)
PyTotemRPValidationElasticReconstruction_files := $(patsubst src/TotemRPValidation/ElasticReconstruction/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ElasticReconstruction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationElasticReconstruction_LOC_USE := self  
PyTotemRPValidationElasticReconstruction_PACKAGE := self/src/TotemRPValidation/ElasticReconstruction/python
ALL_PRODS += PyTotemRPValidationElasticReconstruction
PyTotemRPValidationElasticReconstruction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/python,src_TotemRPValidation_ElasticReconstruction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationElasticReconstruction,src/TotemRPValidation/ElasticReconstruction/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_ElasticReconstruction_python
src_TotemRPValidation_ElasticReconstruction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ElasticReconstruction_python,src/TotemRPValidation/ElasticReconstruction/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/Examples)
subdirs_src_TotemRPValidation_Examples := 
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/GeneratorValidation)
subdirs_src_TotemRPValidation_GeneratorValidation := src_TotemRPValidation_GeneratorValidation_plugins src_TotemRPValidation_GeneratorValidation_python
ifeq ($(strip $(TotemRPValidationGeneratorValidationPlugins)),)
TotemRPValidationGeneratorValidationPlugins_files := $(patsubst src/TotemRPValidation/GeneratorValidation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/GeneratorValidation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/GeneratorValidation/plugins/$(file). Please fix src/TotemRPValidation/GeneratorValidation/plugins/BuildFile.))))
TotemRPValidationGeneratorValidationPlugins := self/src/TotemRPValidation/GeneratorValidation/plugins
TotemRPValidationGeneratorValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/GeneratorValidation/plugins/BuildFile
TotemRPValidationGeneratorValidationPlugins_LOC_USE := self  FWCore/Framework root SimDataFormats/GeneratorProducts
TotemRPValidationGeneratorValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationGeneratorValidationPlugins,TotemRPValidationGeneratorValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/GeneratorValidation/plugins))
TotemRPValidationGeneratorValidationPlugins_PACKAGE := self/src/TotemRPValidation/GeneratorValidation/plugins
ALL_PRODS += TotemRPValidationGeneratorValidationPlugins
TotemRPValidationGeneratorValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationGeneratorValidationPlugins,src/TotemRPValidation/GeneratorValidation/plugins,src_TotemRPValidation_GeneratorValidation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationGeneratorValidationPlugins,src/TotemRPValidation/GeneratorValidation/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_GeneratorValidation_plugins
src_TotemRPValidation_GeneratorValidation_plugins_parent := TotemRPValidation/GeneratorValidation
src_TotemRPValidation_GeneratorValidation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_GeneratorValidation_plugins,src/TotemRPValidation/GeneratorValidation/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationGeneratorValidation)),)
PyTotemRPValidationGeneratorValidation := self/src/TotemRPValidation/GeneratorValidation/python
src_TotemRPValidation_GeneratorValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/GeneratorValidation/python)
PyTotemRPValidationGeneratorValidation_files := $(patsubst src/TotemRPValidation/GeneratorValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/GeneratorValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationGeneratorValidation_LOC_USE := self  
PyTotemRPValidationGeneratorValidation_PACKAGE := self/src/TotemRPValidation/GeneratorValidation/python
ALL_PRODS += PyTotemRPValidationGeneratorValidation
PyTotemRPValidationGeneratorValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationGeneratorValidation,src/TotemRPValidation/GeneratorValidation/python,src_TotemRPValidation_GeneratorValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationGeneratorValidation,src/TotemRPValidation/GeneratorValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_GeneratorValidation_python
src_TotemRPValidation_GeneratorValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_GeneratorValidation_python,src/TotemRPValidation/GeneratorValidation/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/HitDistributions)
subdirs_src_TotemRPValidation_HitDistributions := src_TotemRPValidation_HitDistributions_test src_TotemRPValidation_HitDistributions_interface src_TotemRPValidation_HitDistributions_plugins src_TotemRPValidation_HitDistributions_python src_TotemRPValidation_HitDistributions_src
ifeq ($(strip $(TotemRPValidationHitDistributionsPlugins)),)
TotemRPValidationHitDistributionsPlugins_files := $(patsubst src/TotemRPValidation/HitDistributions/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/HitDistributions/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/HitDistributions/plugins/$(file). Please fix src/TotemRPValidation/HitDistributions/plugins/BuildFile.))))
TotemRPValidationHitDistributionsPlugins := self/src/TotemRPValidation/HitDistributions/plugins
TotemRPValidationHitDistributionsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/HitDistributions/plugins/BuildFile
TotemRPValidationHitDistributionsPlugins_LOC_USE := self  TotemRPValidation/HitDistributions FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost DataFormats/Common Geometry/TotemRPDetTopology Geometry/TotemRPGeometryBuilder clhep Geometry/TotemRecords
TotemRPValidationHitDistributionsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationHitDistributionsPlugins,TotemRPValidationHitDistributionsPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/HitDistributions/plugins))
TotemRPValidationHitDistributionsPlugins_PACKAGE := self/src/TotemRPValidation/HitDistributions/plugins
ALL_PRODS += TotemRPValidationHitDistributionsPlugins
TotemRPValidationHitDistributionsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationHitDistributionsPlugins,src/TotemRPValidation/HitDistributions/plugins,src_TotemRPValidation_HitDistributions_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationHitDistributionsPlugins,src/TotemRPValidation/HitDistributions/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_plugins
src_TotemRPValidation_HitDistributions_plugins_parent := TotemRPValidation/HitDistributions
src_TotemRPValidation_HitDistributions_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_plugins,src/TotemRPValidation/HitDistributions/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationHitDistributions)),)
PyTotemRPValidationHitDistributions := self/src/TotemRPValidation/HitDistributions/python
src_TotemRPValidation_HitDistributions_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/HitDistributions/python)
PyTotemRPValidationHitDistributions_files := $(patsubst src/TotemRPValidation/HitDistributions/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/HitDistributions/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationHitDistributions_LOC_USE := self  
PyTotemRPValidationHitDistributions_PACKAGE := self/src/TotemRPValidation/HitDistributions/python
ALL_PRODS += PyTotemRPValidationHitDistributions
PyTotemRPValidationHitDistributions_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/python,src_TotemRPValidation_HitDistributions_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationHitDistributions,src/TotemRPValidation/HitDistributions/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_python
src_TotemRPValidation_HitDistributions_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_python,src/TotemRPValidation/HitDistributions/python,PYTHON))
ALL_COMMONRULES += src_TotemRPValidation_HitDistributions_test
src_TotemRPValidation_HitDistributions_test_parent := TotemRPValidation/HitDistributions
src_TotemRPValidation_HitDistributions_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_HitDistributions_test,src/TotemRPValidation/HitDistributions/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/InelasticReconstructionValidation)
subdirs_src_TotemRPValidation_InelasticReconstructionValidation := src_TotemRPValidation_InelasticReconstructionValidation_python src_TotemRPValidation_InelasticReconstructionValidation_scripts src_TotemRPValidation_InelasticReconstructionValidation_src
ifeq ($(strip $(PyTotemRPValidationInelasticReconstructionValidation)),)
PyTotemRPValidationInelasticReconstructionValidation := self/src/TotemRPValidation/InelasticReconstructionValidation/python
src_TotemRPValidation_InelasticReconstructionValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/InelasticReconstructionValidation/python)
PyTotemRPValidationInelasticReconstructionValidation_files := $(patsubst src/TotemRPValidation/InelasticReconstructionValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/InelasticReconstructionValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationInelasticReconstructionValidation_LOC_USE := self  
PyTotemRPValidationInelasticReconstructionValidation_PACKAGE := self/src/TotemRPValidation/InelasticReconstructionValidation/python
ALL_PRODS += PyTotemRPValidationInelasticReconstructionValidation
PyTotemRPValidationInelasticReconstructionValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationInelasticReconstructionValidation,src/TotemRPValidation/InelasticReconstructionValidation/python,src_TotemRPValidation_InelasticReconstructionValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationInelasticReconstructionValidation,src/TotemRPValidation/InelasticReconstructionValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_InelasticReconstructionValidation_python
src_TotemRPValidation_InelasticReconstructionValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_InelasticReconstructionValidation_python,src/TotemRPValidation/InelasticReconstructionValidation/python,PYTHON))
src_TotemRPValidation_InelasticReconstructionValidation_scripts_files := $(filter-out \#% %\#,$(notdir $(wildcard $(foreach dir,$(LOCALTOP)/src/TotemRPValidation/InelasticReconstructionValidation/scripts,$(dir)/*))))
$(eval $(call Src2StoreCopy,src_TotemRPValidation_InelasticReconstructionValidation_scripts,src/TotemRPValidation/InelasticReconstructionValidation/scripts,$(SCRAMSTORENAME_BIN),*))
ifeq ($(strip $(TotemRPValidation/InelasticReconstructionValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_InelasticReconstructionValidation_src
src_TotemRPValidation_InelasticReconstructionValidation_src_parent := TotemRPValidation/InelasticReconstructionValidation
src_TotemRPValidation_InelasticReconstructionValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_InelasticReconstructionValidation_src,src/TotemRPValidation/InelasticReconstructionValidation/src,LIBRARY))
TotemRPValidationInelasticReconstructionValidation := self/TotemRPValidation/InelasticReconstructionValidation
TotemRPValidation/InelasticReconstructionValidation := TotemRPValidationInelasticReconstructionValidation
TotemRPValidationInelasticReconstructionValidation_files := $(patsubst src/TotemRPValidation/InelasticReconstructionValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/InelasticReconstructionValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationInelasticReconstructionValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/InelasticReconstructionValidation/BuildFile
TotemRPValidationInelasticReconstructionValidation_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses RecoTotemRP/RPRecoDataFormats SimDataFormats/GeneratorProducts SimG4Core/Notification TotemRPValidation/ParamMADRefTransport TotemRPValidation/ValidationTools TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord
TotemRPValidationInelasticReconstructionValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationInelasticReconstructionValidation,TotemRPValidationInelasticReconstructionValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/InelasticReconstructionValidation/src))
TotemRPValidationInelasticReconstructionValidation_PACKAGE := self/src/TotemRPValidation/InelasticReconstructionValidation/src
ALL_PRODS += TotemRPValidationInelasticReconstructionValidation
TotemRPValidationInelasticReconstructionValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationInelasticReconstructionValidation,src/TotemRPValidation/InelasticReconstructionValidation/src,src_TotemRPValidation_InelasticReconstructionValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/ParamMADRefTransport)
subdirs_src_TotemRPValidation_ParamMADRefTransport := src_TotemRPValidation_ParamMADRefTransport_interface src_TotemRPValidation_ParamMADRefTransport_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/RPAngleValidation)
subdirs_src_TotemRPValidation_RPAngleValidation := src_TotemRPValidation_RPAngleValidation_python src_TotemRPValidation_RPAngleValidation_src
ifeq ($(strip $(PyTotemRPValidationRPAngleValidation)),)
PyTotemRPValidationRPAngleValidation := self/src/TotemRPValidation/RPAngleValidation/python
src_TotemRPValidation_RPAngleValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPAngleValidation/python)
PyTotemRPValidationRPAngleValidation_files := $(patsubst src/TotemRPValidation/RPAngleValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPAngleValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPAngleValidation_LOC_USE := self  
PyTotemRPValidationRPAngleValidation_PACKAGE := self/src/TotemRPValidation/RPAngleValidation/python
ALL_PRODS += PyTotemRPValidationRPAngleValidation
PyTotemRPValidationRPAngleValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/python,src_TotemRPValidation_RPAngleValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPAngleValidation_python
src_TotemRPValidation_RPAngleValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPAngleValidation_python,src/TotemRPValidation/RPAngleValidation/python,PYTHON))
ifeq ($(strip $(TotemRPValidation/RPAngleValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPAngleValidation_src
src_TotemRPValidation_RPAngleValidation_src_parent := TotemRPValidation/RPAngleValidation
src_TotemRPValidation_RPAngleValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPAngleValidation_src,src/TotemRPValidation/RPAngleValidation/src,LIBRARY))
TotemRPValidationRPAngleValidation := self/TotemRPValidation/RPAngleValidation
TotemRPValidation/RPAngleValidation := TotemRPValidationRPAngleValidation
TotemRPValidationRPAngleValidation_files := $(patsubst src/TotemRPValidation/RPAngleValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPAngleValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPAngleValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPAngleValidation/BuildFile
TotemRPValidationRPAngleValidation_LOC_USE := self  FWCore/ParameterSet FWCore/Framework hepmc TotemCondFormats/DataRecord TotemCondFormats/BeamOpticsParamsObjects RecoTotemRP/RPRomanPotResolutionService
TotemRPValidationRPAngleValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRPAngleValidation,TotemRPValidationRPAngleValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RPAngleValidation/src))
TotemRPValidationRPAngleValidation_PACKAGE := self/src/TotemRPValidation/RPAngleValidation/src
ALL_PRODS += TotemRPValidationRPAngleValidation
TotemRPValidationRPAngleValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPAngleValidation,src/TotemRPValidation/RPAngleValidation/src,src_TotemRPValidation_RPAngleValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/RPGeant4Validation)
subdirs_src_TotemRPValidation_RPGeant4Validation := src_TotemRPValidation_RPGeant4Validation_interface src_TotemRPValidation_RPGeant4Validation_src src_TotemRPValidation_RPGeant4Validation_bin
ifeq ($(strip $(RPGeant4Validate)),)
RPGeant4Validate_files := $(patsubst src/TotemRPValidation/RPGeant4Validation/bin/%,%,$(foreach file,RPGeant4Validate.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/RPGeant4Validation/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/RPGeant4Validation/bin/$(file). Please fix src/TotemRPValidation/RPGeant4Validation/bin/BuildFile.))))
RPGeant4Validate := self/src/TotemRPValidation/RPGeant4Validation/bin
RPGeant4Validate_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPGeant4Validation/bin/BuildFile
RPGeant4Validate_LOC_USE := self  TotemRPValidation/RPGeant4Validation
RPGeant4Validate_PACKAGE := self/src/TotemRPValidation/RPGeant4Validation/bin
ALL_PRODS += RPGeant4Validate
RPGeant4Validate_INIT_FUNC        += $$(eval $$(call Binary,RPGeant4Validate,src/TotemRPValidation/RPGeant4Validation/bin,src_TotemRPValidation_RPGeant4Validation_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,RPGeant4Validate,src/TotemRPValidation/RPGeant4Validation/bin))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPGeant4Validation_bin
src_TotemRPValidation_RPGeant4Validation_bin_parent := TotemRPValidation/RPGeant4Validation
src_TotemRPValidation_RPGeant4Validation_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPGeant4Validation_bin,src/TotemRPValidation/RPGeant4Validation/bin,BINARY))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/RPPositionValidation)
subdirs_src_TotemRPValidation_RPPositionValidation := src_TotemRPValidation_RPPositionValidation_test src_TotemRPValidation_RPPositionValidation_interface src_TotemRPValidation_RPPositionValidation_python src_TotemRPValidation_RPPositionValidation_src
ifeq ($(strip $(PyTotemRPValidationRPPositionValidation)),)
PyTotemRPValidationRPPositionValidation := self/src/TotemRPValidation/RPPositionValidation/python
src_TotemRPValidation_RPPositionValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPPositionValidation/python)
PyTotemRPValidationRPPositionValidation_files := $(patsubst src/TotemRPValidation/RPPositionValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPPositionValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPPositionValidation_LOC_USE := self  
PyTotemRPValidationRPPositionValidation_PACKAGE := self/src/TotemRPValidation/RPPositionValidation/python
ALL_PRODS += PyTotemRPValidationRPPositionValidation
PyTotemRPValidationRPPositionValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/python,src_TotemRPValidation_RPPositionValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPPositionValidation_python
src_TotemRPValidation_RPPositionValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPPositionValidation_python,src/TotemRPValidation/RPPositionValidation/python,PYTHON))
ifeq ($(strip $(TotemRPValidation/RPPositionValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPPositionValidation_src
src_TotemRPValidation_RPPositionValidation_src_parent := TotemRPValidation/RPPositionValidation
src_TotemRPValidation_RPPositionValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPPositionValidation_src,src/TotemRPValidation/RPPositionValidation/src,LIBRARY))
TotemRPValidationRPPositionValidation := self/TotemRPValidation/RPPositionValidation
TotemRPValidation/RPPositionValidation := TotemRPValidationRPPositionValidation
TotemRPValidationRPPositionValidation_files := $(patsubst src/TotemRPValidation/RPPositionValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPPositionValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPPositionValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPPositionValidation/BuildFile
TotemRPValidationRPPositionValidation_LOC_USE := self  FWCore/ParameterSet FWCore/Framework Geometry/TotemRPGeometryBuilder hepmc
TotemRPValidationRPPositionValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRPPositionValidation,TotemRPValidationRPPositionValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RPPositionValidation/src))
TotemRPValidationRPPositionValidation_PACKAGE := self/src/TotemRPValidation/RPPositionValidation/src
ALL_PRODS += TotemRPValidationRPPositionValidation
TotemRPValidationRPPositionValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPPositionValidation,src/TotemRPValidation/RPPositionValidation/src,src_TotemRPValidation_RPPositionValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPPositionValidation_test
src_TotemRPValidation_RPPositionValidation_test_parent := TotemRPValidation/RPPositionValidation
src_TotemRPValidation_RPPositionValidation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPPositionValidation_test,src/TotemRPValidation/RPPositionValidation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/RPReconstructedTracksValidation)
subdirs_src_TotemRPValidation_RPReconstructedTracksValidation := src_TotemRPValidation_RPReconstructedTracksValidation_test src_TotemRPValidation_RPReconstructedTracksValidation_interface src_TotemRPValidation_RPReconstructedTracksValidation_python src_TotemRPValidation_RPReconstructedTracksValidation_src
ifeq ($(strip $(PyTotemRPValidationRPReconstructedTracksValidation)),)
PyTotemRPValidationRPReconstructedTracksValidation := self/src/TotemRPValidation/RPReconstructedTracksValidation/python
src_TotemRPValidation_RPReconstructedTracksValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RPReconstructedTracksValidation/python)
PyTotemRPValidationRPReconstructedTracksValidation_files := $(patsubst src/TotemRPValidation/RPReconstructedTracksValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPReconstructedTracksValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRPReconstructedTracksValidation_LOC_USE := self  
PyTotemRPValidationRPReconstructedTracksValidation_PACKAGE := self/src/TotemRPValidation/RPReconstructedTracksValidation/python
ALL_PRODS += PyTotemRPValidationRPReconstructedTracksValidation
PyTotemRPValidationRPReconstructedTracksValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRPReconstructedTracksValidation,src/TotemRPValidation/RPReconstructedTracksValidation/python,src_TotemRPValidation_RPReconstructedTracksValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRPReconstructedTracksValidation,src/TotemRPValidation/RPReconstructedTracksValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPReconstructedTracksValidation_python
src_TotemRPValidation_RPReconstructedTracksValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPReconstructedTracksValidation_python,src/TotemRPValidation/RPReconstructedTracksValidation/python,PYTHON))
ifeq ($(strip $(TotemRPValidation/RPReconstructedTracksValidation)),)
ALL_COMMONRULES += src_TotemRPValidation_RPReconstructedTracksValidation_src
src_TotemRPValidation_RPReconstructedTracksValidation_src_parent := TotemRPValidation/RPReconstructedTracksValidation
src_TotemRPValidation_RPReconstructedTracksValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPReconstructedTracksValidation_src,src/TotemRPValidation/RPReconstructedTracksValidation/src,LIBRARY))
TotemRPValidationRPReconstructedTracksValidation := self/TotemRPValidation/RPReconstructedTracksValidation
TotemRPValidation/RPReconstructedTracksValidation := TotemRPValidationRPReconstructedTracksValidation
TotemRPValidationRPReconstructedTracksValidation_files := $(patsubst src/TotemRPValidation/RPReconstructedTracksValidation/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RPReconstructedTracksValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRPReconstructedTracksValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RPReconstructedTracksValidation/BuildFile
TotemRPValidationRPReconstructedTracksValidation_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses RecoTotemRP/RPRecoDataFormats SimDataFormats/GeneratorProducts SimG4Core/Notification TotemRPValidation/ParamMADRefTransport RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord TotemRPValidation/HitDistributions root rootgraphics Geometry/TotemRPGeometryBuilder Geometry/TotemRecords DataFormats/TotemL1Trigger
TotemRPValidationRPReconstructedTracksValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRPReconstructedTracksValidation,TotemRPValidationRPReconstructedTracksValidation,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RPReconstructedTracksValidation/src))
TotemRPValidationRPReconstructedTracksValidation_PACKAGE := self/src/TotemRPValidation/RPReconstructedTracksValidation/src
ALL_PRODS += TotemRPValidationRPReconstructedTracksValidation
TotemRPValidationRPReconstructedTracksValidation_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRPReconstructedTracksValidation,src/TotemRPValidation/RPReconstructedTracksValidation/src,src_TotemRPValidation_RPReconstructedTracksValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemRPValidation_RPReconstructedTracksValidation_test
src_TotemRPValidation_RPReconstructedTracksValidation_test_parent := TotemRPValidation/RPReconstructedTracksValidation
src_TotemRPValidation_RPReconstructedTracksValidation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RPReconstructedTracksValidation_test,src/TotemRPValidation/RPReconstructedTracksValidation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/RecoTrackRP)
subdirs_src_TotemRPValidation_RecoTrackRP := src_TotemRPValidation_RecoTrackRP_test src_TotemRPValidation_RecoTrackRP_python src_TotemRPValidation_RecoTrackRP_src
ifeq ($(strip $(PyTotemRPValidationRecoTrackRP)),)
PyTotemRPValidationRecoTrackRP := self/src/TotemRPValidation/RecoTrackRP/python
src_TotemRPValidation_RecoTrackRP_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/RecoTrackRP/python)
PyTotemRPValidationRecoTrackRP_files := $(patsubst src/TotemRPValidation/RecoTrackRP/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RecoTrackRP/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationRecoTrackRP_LOC_USE := self  
PyTotemRPValidationRecoTrackRP_PACKAGE := self/src/TotemRPValidation/RecoTrackRP/python
ALL_PRODS += PyTotemRPValidationRecoTrackRP
PyTotemRPValidationRecoTrackRP_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/python,src_TotemRPValidation_RecoTrackRP_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_python
src_TotemRPValidation_RecoTrackRP_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_python,src/TotemRPValidation/RecoTrackRP/python,PYTHON))
ifeq ($(strip $(TotemRPValidation/RecoTrackRP)),)
ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_src
src_TotemRPValidation_RecoTrackRP_src_parent := TotemRPValidation/RecoTrackRP
src_TotemRPValidation_RecoTrackRP_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_src,src/TotemRPValidation/RecoTrackRP/src,LIBRARY))
TotemRPValidationRecoTrackRP := self/TotemRPValidation/RecoTrackRP
TotemRPValidation/RecoTrackRP := TotemRPValidationRecoTrackRP
TotemRPValidationRecoTrackRP_files := $(patsubst src/TotemRPValidation/RecoTrackRP/src/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/RecoTrackRP/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemRPValidationRecoTrackRP_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/RecoTrackRP/BuildFile
TotemRPValidationRecoTrackRP_LOC_USE := self  SimDataFormats/TrackingHit FWCore/ParameterSet DataFormats/TotemRPDataTypes FWCore/Framework DataFormats/Common clhep gsl boost geant4 DataFormats/TotemRPDetId Geometry/TotemRPDetTopology TotemRPValidation/BaseValidationClasses RecoTotemRP/RPRecoDataFormats SimDataFormats/GeneratorProducts SimG4Core/Notification TotemRPValidation/ParamMADRefTransport RecoTotemRP/RPRomanPotResolutionService TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/DataRecord TotemRPValidation/HitDistributions root rootgraphics Geometry/TotemRPGeometryBuilder Geometry/TotemRecords
TotemRPValidationRecoTrackRP_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationRecoTrackRP,TotemRPValidationRecoTrackRP,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/RecoTrackRP/src))
TotemRPValidationRecoTrackRP_PACKAGE := self/src/TotemRPValidation/RecoTrackRP/src
ALL_PRODS += TotemRPValidationRecoTrackRP
TotemRPValidationRecoTrackRP_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationRecoTrackRP,src/TotemRPValidation/RecoTrackRP/src,src_TotemRPValidation_RecoTrackRP_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemRPValidation_RecoTrackRP_test
src_TotemRPValidation_RecoTrackRP_test_parent := TotemRPValidation/RecoTrackRP
src_TotemRPValidation_RecoTrackRP_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_RecoTrackRP_test,src/TotemRPValidation/RecoTrackRP/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/TransportValidation)
subdirs_src_TotemRPValidation_TransportValidation := src_TotemRPValidation_TransportValidation_interface src_TotemRPValidation_TransportValidation_plugins src_TotemRPValidation_TransportValidation_python src_TotemRPValidation_TransportValidation_src
ifeq ($(strip $(TotemRPValidationTransportValidationPlugins)),)
TotemRPValidationTransportValidationPlugins_files := $(patsubst src/TotemRPValidation/TransportValidation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/TransportValidation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/TransportValidation/plugins/$(file). Please fix src/TotemRPValidation/TransportValidation/plugins/BuildFile.))))
TotemRPValidationTransportValidationPlugins := self/src/TotemRPValidation/TransportValidation/plugins
TotemRPValidationTransportValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/TransportValidation/plugins/BuildFile
TotemRPValidationTransportValidationPlugins_LOC_USE := self  TotemRPValidation/TransportValidation FWCore/Framework TotemCondFormats/BeamOpticsParamsObjects TotemCondFormats/ProtonTransportFunctions TotemCondFormats/DataRecord
TotemRPValidationTransportValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationTransportValidationPlugins,TotemRPValidationTransportValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/TransportValidation/plugins))
TotemRPValidationTransportValidationPlugins_PACKAGE := self/src/TotemRPValidation/TransportValidation/plugins
ALL_PRODS += TotemRPValidationTransportValidationPlugins
TotemRPValidationTransportValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationTransportValidationPlugins,src/TotemRPValidation/TransportValidation/plugins,src_TotemRPValidation_TransportValidation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationTransportValidationPlugins,src/TotemRPValidation/TransportValidation/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_plugins
src_TotemRPValidation_TransportValidation_plugins_parent := TotemRPValidation/TransportValidation
src_TotemRPValidation_TransportValidation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_plugins,src/TotemRPValidation/TransportValidation/plugins,PLUGINS))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/ValidationPlots)
subdirs_src_TotemRPValidation_ValidationPlots := src_TotemRPValidation_ValidationPlots_test src_TotemRPValidation_ValidationPlots_interface src_TotemRPValidation_ValidationPlots_plugins src_TotemRPValidation_ValidationPlots_python src_TotemRPValidation_ValidationPlots_src
ifeq ($(strip $(PyTotemRPValidationTransportValidation)),)
PyTotemRPValidationTransportValidation := self/src/TotemRPValidation/TransportValidation/python
src_TotemRPValidation_TransportValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/TransportValidation/python)
PyTotemRPValidationTransportValidation_files := $(patsubst src/TotemRPValidation/TransportValidation/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/TransportValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationTransportValidation_LOC_USE := self  
PyTotemRPValidationTransportValidation_PACKAGE := self/src/TotemRPValidation/TransportValidation/python
ALL_PRODS += PyTotemRPValidationTransportValidation
PyTotemRPValidationTransportValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/python,src_TotemRPValidation_TransportValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationTransportValidation,src/TotemRPValidation/TransportValidation/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_TransportValidation_python
src_TotemRPValidation_TransportValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_TransportValidation_python,src/TotemRPValidation/TransportValidation/python,PYTHON))
ifeq ($(strip $(TotemRPValidationValidationPlotsPlugins)),)
TotemRPValidationValidationPlotsPlugins_files := $(patsubst src/TotemRPValidation/ValidationPlots/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ValidationPlots/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ValidationPlots/plugins/$(file). Please fix src/TotemRPValidation/ValidationPlots/plugins/BuildFile.))))
TotemRPValidationValidationPlotsPlugins := self/src/TotemRPValidation/ValidationPlots/plugins
TotemRPValidationValidationPlotsPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationPlots/plugins/BuildFile
TotemRPValidationValidationPlotsPlugins_LOC_USE := self  FWCore/Framework DataFormats/TotemRPDataTypes DataFormats/TotemRPDetId RecoTotemRP/RPRecoDataFormats root boost TotemRPValidation/ValidationTools TotemRPValidation/ValidationPlots TotemRPValidation/ElasticReconstruction TotemRPValidation/BaseValidationClasses
TotemRPValidationValidationPlotsPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRPValidationValidationPlotsPlugins,TotemRPValidationValidationPlotsPlugins,$(SCRAMSTORENAME_LIB),src/TotemRPValidation/ValidationPlots/plugins))
TotemRPValidationValidationPlotsPlugins_PACKAGE := self/src/TotemRPValidation/ValidationPlots/plugins
ALL_PRODS += TotemRPValidationValidationPlotsPlugins
TotemRPValidationValidationPlotsPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRPValidationValidationPlotsPlugins,src/TotemRPValidation/ValidationPlots/plugins,src_TotemRPValidation_ValidationPlots_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRPValidationValidationPlotsPlugins,src/TotemRPValidation/ValidationPlots/plugins))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_plugins
src_TotemRPValidation_ValidationPlots_plugins_parent := TotemRPValidation/ValidationPlots
src_TotemRPValidation_ValidationPlots_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_plugins,src/TotemRPValidation/ValidationPlots/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRPValidationValidationPlots)),)
PyTotemRPValidationValidationPlots := self/src/TotemRPValidation/ValidationPlots/python
src_TotemRPValidation_ValidationPlots_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRPValidation/ValidationPlots/python)
PyTotemRPValidationValidationPlots_files := $(patsubst src/TotemRPValidation/ValidationPlots/python/%,%,$(wildcard $(foreach dir,src/TotemRPValidation/ValidationPlots/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRPValidationValidationPlots_LOC_USE := self  
PyTotemRPValidationValidationPlots_PACKAGE := self/src/TotemRPValidation/ValidationPlots/python
ALL_PRODS += PyTotemRPValidationValidationPlots
PyTotemRPValidationValidationPlots_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/python,src_TotemRPValidation_ValidationPlots_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRPValidationValidationPlots,src/TotemRPValidation/ValidationPlots/python))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_python
src_TotemRPValidation_ValidationPlots_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_python,src/TotemRPValidation/ValidationPlots/python,PYTHON))
ALL_COMMONRULES += src_TotemRPValidation_ValidationPlots_test
src_TotemRPValidation_ValidationPlots_test_parent := TotemRPValidation/ValidationPlots
src_TotemRPValidation_ValidationPlots_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationPlots_test,src/TotemRPValidation/ValidationPlots/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRPValidation/ValidationTools)
subdirs_src_TotemRPValidation_ValidationTools := src_TotemRPValidation_ValidationTools_interface src_TotemRPValidation_ValidationTools_src src_TotemRPValidation_ValidationTools_bin
ifeq ($(strip $(ValidationTest)),)
ValidationTest_files := $(patsubst src/TotemRPValidation/ValidationTools/bin/%,%,$(foreach file,test.cc,$(eval xfile:=$(wildcard src/TotemRPValidation/ValidationTools/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRPValidation/ValidationTools/bin/$(file). Please fix src/TotemRPValidation/ValidationTools/bin/BuildFile.))))
ValidationTest := self/src/TotemRPValidation/ValidationTools/bin
ValidationTest_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRPValidation/ValidationTools/bin/BuildFile
ValidationTest_LOC_USE := self  root TotemRPValidation/ValidationTools
ValidationTest_PACKAGE := self/src/TotemRPValidation/ValidationTools/bin
ALL_PRODS += ValidationTest
ValidationTest_INIT_FUNC        += $$(eval $$(call Binary,ValidationTest,src/TotemRPValidation/ValidationTools/bin,src_TotemRPValidation_ValidationTools_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,ValidationTest,src/TotemRPValidation/ValidationTools/bin))
endif
ALL_COMMONRULES += src_TotemRPValidation_ValidationTools_bin
src_TotemRPValidation_ValidationTools_bin_parent := TotemRPValidation/ValidationTools
src_TotemRPValidation_ValidationTools_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRPValidation_ValidationTools_bin,src/TotemRPValidation/ValidationTools/bin,BINARY))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemRawData)
subdirs_src_TotemRawData = src_TotemRawData_DataFormats src_TotemRawData_Readers src_TotemRawData_Filters src_TotemRawData_RawToDigi
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawData/DataFormats)
subdirs_src_TotemRawData_DataFormats := src_TotemRawData_DataFormats_interface src_TotemRawData_DataFormats_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawData/Filters)
subdirs_src_TotemRawData_Filters := src_TotemRawData_Filters_test src_TotemRawData_Filters_plugins src_TotemRawData_Filters_python
ifeq ($(strip $(TotemRawDataLibraryFiltresPlugins)),)
TotemRawDataLibraryFiltresPlugins_files := $(patsubst src/TotemRawData/Filters/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/Filters/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/Filters/plugins/$(file). Please fix src/TotemRawData/Filters/plugins/BuildFile.))))
TotemRawDataLibraryFiltresPlugins := self/src/TotemRawData/Filters/plugins
TotemRawDataLibraryFiltresPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/Filters/plugins/BuildFile
TotemRawDataLibraryFiltresPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet TotemRawDataLibrary/DataFormats
TotemRawDataLibraryFiltresPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataLibraryFiltresPlugins,TotemRawDataLibraryFiltresPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/Filters/plugins))
TotemRawDataLibraryFiltresPlugins_PACKAGE := self/src/TotemRawData/Filters/plugins
ALL_PRODS += TotemRawDataLibraryFiltresPlugins
TotemRawDataLibraryFiltresPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataLibraryFiltresPlugins,src/TotemRawData/Filters/plugins,src_TotemRawData_Filters_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataLibraryFiltresPlugins,src/TotemRawData/Filters/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_Filters_plugins
src_TotemRawData_Filters_plugins_parent := TotemRawData/Filters
src_TotemRawData_Filters_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Filters_plugins,src/TotemRawData/Filters/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRawDataFilters)),)
PyTotemRawDataFilters := self/src/TotemRawData/Filters/python
src_TotemRawData_Filters_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/Filters/python)
PyTotemRawDataFilters_files := $(patsubst src/TotemRawData/Filters/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/Filters/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataFilters_LOC_USE := self  
PyTotemRawDataFilters_PACKAGE := self/src/TotemRawData/Filters/python
ALL_PRODS += PyTotemRawDataFilters
PyTotemRawDataFilters_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataFilters,src/TotemRawData/Filters/python,src_TotemRawData_Filters_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataFilters,src/TotemRawData/Filters/python))
endif
ALL_COMMONRULES += src_TotemRawData_Filters_python
src_TotemRawData_Filters_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Filters_python,src/TotemRawData/Filters/python,PYTHON))
ALL_COMMONRULES += src_TotemRawData_Filters_test
src_TotemRawData_Filters_test_parent := TotemRawData/Filters
src_TotemRawData_Filters_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Filters_test,src/TotemRawData/Filters/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawData/RawToDigi)
subdirs_src_TotemRawData_RawToDigi := src_TotemRawData_RawToDigi_test src_TotemRawData_RawToDigi_interface src_TotemRawData_RawToDigi_plugins src_TotemRawData_RawToDigi_python src_TotemRawData_RawToDigi_src
ifeq ($(strip $(TotemRawDataRawToDigiPlugins)),)
TotemRawDataRawToDigiPlugins_files := $(patsubst src/TotemRawData/RawToDigi/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/RawToDigi/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/RawToDigi/plugins/$(file). Please fix src/TotemRawData/RawToDigi/plugins/BuildFile.))))
TotemRawDataRawToDigiPlugins := self/src/TotemRawData/RawToDigi/plugins
TotemRawDataRawToDigiPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/RawToDigi/plugins/BuildFile
TotemRawDataRawToDigiPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataRawToDigiPlugins_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats DataFormats/TotemRPDataTypes DataFormats/T2Digi DataFormats/T2DetId DataFormats/TotemL1Trigger DataFormats/Common DataFormats/DetId DataFormats/T1DigiVfat DataFormats/T1DetId DataFormats/T1DigiWire TotemCondFormats/DataRecord TotemCondFormats/DAQInformation
TotemRawDataRawToDigiPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataRawToDigiPlugins,TotemRawDataRawToDigiPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/RawToDigi/plugins))
TotemRawDataRawToDigiPlugins_PACKAGE := self/src/TotemRawData/RawToDigi/plugins
ALL_PRODS += TotemRawDataRawToDigiPlugins
TotemRawDataRawToDigiPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataRawToDigiPlugins,src/TotemRawData/RawToDigi/plugins,src_TotemRawData_RawToDigi_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataRawToDigiPlugins,src/TotemRawData/RawToDigi/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_RawToDigi_plugins
src_TotemRawData_RawToDigi_plugins_parent := TotemRawData/RawToDigi
src_TotemRawData_RawToDigi_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_plugins,src/TotemRawData/RawToDigi/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRawDataRawToDigi)),)
PyTotemRawDataRawToDigi := self/src/TotemRawData/RawToDigi/python
src_TotemRawData_RawToDigi_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/RawToDigi/python)
PyTotemRawDataRawToDigi_files := $(patsubst src/TotemRawData/RawToDigi/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/RawToDigi/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataRawToDigi_LOC_USE := self  
PyTotemRawDataRawToDigi_PACKAGE := self/src/TotemRawData/RawToDigi/python
ALL_PRODS += PyTotemRawDataRawToDigi
PyTotemRawDataRawToDigi_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataRawToDigi,src/TotemRawData/RawToDigi/python,src_TotemRawData_RawToDigi_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataRawToDigi,src/TotemRawData/RawToDigi/python))
endif
ALL_COMMONRULES += src_TotemRawData_RawToDigi_python
src_TotemRawData_RawToDigi_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_python,src/TotemRawData/RawToDigi/python,PYTHON))
ALL_COMMONRULES += src_TotemRawData_RawToDigi_test
src_TotemRawData_RawToDigi_test_parent := TotemRawData/RawToDigi
src_TotemRawData_RawToDigi_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_RawToDigi_test,src/TotemRawData/RawToDigi/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawData/Readers)
subdirs_src_TotemRawData_Readers := src_TotemRawData_Readers_test src_TotemRawData_Readers_plugins src_TotemRawData_Readers_python
ifeq ($(strip $(TotemRawDataReadersPlugins)),)
TotemRawDataReadersPlugins_files := $(patsubst src/TotemRawData/Readers/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemRawData/Readers/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawData/Readers/plugins/$(file). Please fix src/TotemRawData/Readers/plugins/BuildFile.))))
TotemRawDataReadersPlugins := self/src/TotemRawData/Readers/plugins
TotemRawDataReadersPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawData/Readers/plugins/BuildFile
TotemRawDataReadersPlugins_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemRawDataReadersPlugins_LOC_USE := self  FWCore/Framework TotemRawDataLibrary/Readers TotemRawData/DataFormats
TotemRawDataReadersPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemRawDataReadersPlugins,TotemRawDataReadersPlugins,$(SCRAMSTORENAME_LIB),src/TotemRawData/Readers/plugins))
TotemRawDataReadersPlugins_PACKAGE := self/src/TotemRawData/Readers/plugins
ALL_PRODS += TotemRawDataReadersPlugins
TotemRawDataReadersPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemRawDataReadersPlugins,src/TotemRawData/Readers/plugins,src_TotemRawData_Readers_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemRawDataReadersPlugins,src/TotemRawData/Readers/plugins))
endif
ALL_COMMONRULES += src_TotemRawData_Readers_plugins
src_TotemRawData_Readers_plugins_parent := TotemRawData/Readers
src_TotemRawData_Readers_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_plugins,src/TotemRawData/Readers/plugins,PLUGINS))
ifeq ($(strip $(PyTotemRawDataReaders)),)
PyTotemRawDataReaders := self/src/TotemRawData/Readers/python
src_TotemRawData_Readers_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemRawData/Readers/python)
PyTotemRawDataReaders_files := $(patsubst src/TotemRawData/Readers/python/%,%,$(wildcard $(foreach dir,src/TotemRawData/Readers/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemRawDataReaders_LOC_USE := self  
PyTotemRawDataReaders_PACKAGE := self/src/TotemRawData/Readers/python
ALL_PRODS += PyTotemRawDataReaders
PyTotemRawDataReaders_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemRawDataReaders,src/TotemRawData/Readers/python,src_TotemRawData_Readers_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemRawDataReaders,src/TotemRawData/Readers/python))
endif
ALL_COMMONRULES += src_TotemRawData_Readers_python
src_TotemRawData_Readers_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_python,src/TotemRawData/Readers/python,PYTHON))
ALL_COMMONRULES += src_TotemRawData_Readers_test
src_TotemRawData_Readers_test_parent := TotemRawData/Readers
src_TotemRawData_Readers_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawData_Readers_test,src/TotemRawData/Readers/test,TEST))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemRawDataLibrary)
subdirs_src_TotemRawDataLibrary = src_TotemRawDataLibrary_DataFormats src_TotemRawDataLibrary_Readers src_TotemRawDataLibrary_DAQA src_TotemRawDataLibrary_Utilities
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawDataLibrary/DAQA)
subdirs_src_TotemRawDataLibrary_DAQA := src_TotemRawDataLibrary_DAQA_test src_TotemRawDataLibrary_DAQA_interface
ALL_COMMONRULES += src_TotemRawDataLibrary_DAQA_test
src_TotemRawDataLibrary_DAQA_test_parent := TotemRawDataLibrary/DAQA
src_TotemRawDataLibrary_DAQA_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_DAQA_test,src/TotemRawDataLibrary/DAQA/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawDataLibrary/DataFormats)
subdirs_src_TotemRawDataLibrary_DataFormats := src_TotemRawDataLibrary_DataFormats_test src_TotemRawDataLibrary_DataFormats_src
ALL_COMMONRULES += src_TotemRawDataLibrary_DataFormats_test
src_TotemRawDataLibrary_DataFormats_test_parent := TotemRawDataLibrary/DataFormats
src_TotemRawDataLibrary_DataFormats_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_DataFormats_test,src/TotemRawDataLibrary/DataFormats/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawDataLibrary/Readers)
subdirs_src_TotemRawDataLibrary_Readers := src_TotemRawDataLibrary_Readers_test src_TotemRawDataLibrary_Readers_src
ALL_COMMONRULES += src_TotemRawDataLibrary_Readers_test
src_TotemRawDataLibrary_Readers_test_parent := TotemRawDataLibrary/Readers
src_TotemRawDataLibrary_Readers_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Readers_test,src/TotemRawDataLibrary/Readers/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemRawDataLibrary/Utilities)
subdirs_src_TotemRawDataLibrary_Utilities := src_TotemRawDataLibrary_Utilities_interface src_TotemRawDataLibrary_Utilities_src src_TotemRawDataLibrary_Utilities_bin
ifeq ($(strip $(TotemReadFile)),)
TotemReadFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,readFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemReadFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemReadFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemReadFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemReadFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemReadFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemReadFile
TotemReadFile_INIT_FUNC        += $$(eval $$(call Binary,TotemReadFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemReadFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ifeq ($(strip $(TotemCheckFile)),)
TotemCheckFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,checkFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemCheckFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemCheckFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemCheckFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemCheckFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemCheckFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemCheckFile
TotemCheckFile_INIT_FUNC        += $$(eval $$(call Binary,TotemCheckFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemCheckFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ifeq ($(strip $(TotemAnalyzeFile)),)
TotemAnalyzeFile_files := $(patsubst src/TotemRawDataLibrary/Utilities/bin/%,%,$(foreach file,analyzeFile.cc,$(eval xfile:=$(wildcard src/TotemRawDataLibrary/Utilities/bin/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemRawDataLibrary/Utilities/bin/$(file). Please fix src/TotemRawDataLibrary/Utilities/bin/BuildFile.))))
TotemAnalyzeFile := self/src/TotemRawDataLibrary/Utilities/bin
TotemAnalyzeFile_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemRawDataLibrary/Utilities/bin/BuildFile
TotemAnalyzeFile_LOC_FLAGS_CXXFLAGS   := -O3 -g3 $(CUSTOM_FLAGS)
TotemAnalyzeFile_LOC_USE := self  TotemRawDataLibrary/Utilities TotemRawDataLibrary/Readers
TotemAnalyzeFile_PACKAGE := self/src/TotemRawDataLibrary/Utilities/bin
ALL_PRODS += TotemAnalyzeFile
TotemAnalyzeFile_INIT_FUNC        += $$(eval $$(call Binary,TotemAnalyzeFile,src/TotemRawDataLibrary/Utilities/bin,src_TotemRawDataLibrary_Utilities_bin,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_BIN),bin,$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalyzeFile,src/TotemRawDataLibrary/Utilities/bin))
endif
ALL_COMMONRULES += src_TotemRawDataLibrary_Utilities_bin
src_TotemRawDataLibrary_Utilities_bin_parent := TotemRawDataLibrary/Utilities
src_TotemRawDataLibrary_Utilities_bin_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemRawDataLibrary_Utilities_bin,src/TotemRawDataLibrary/Utilities/bin,BINARY))
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/TotemT1T2Validation)
subdirs_src_TotemT1T2Validation = src_TotemT1T2Validation_T1Validation src_TotemT1T2Validation_T2BackgroundAnalysis src_TotemT1T2Validation_T2RecoValidation src_TotemT1T2Validation_GeneratorAnalysis src_TotemT1T2Validation_T2GeometryValidation
ALL_PACKAGES += $(patsubst src/%,%,src/TotemT1T2Validation/GeneratorAnalysis)
subdirs_src_TotemT1T2Validation_GeneratorAnalysis := src_TotemT1T2Validation_GeneratorAnalysis_test src_TotemT1T2Validation_GeneratorAnalysis_plugins src_TotemT1T2Validation_GeneratorAnalysis_python src_TotemT1T2Validation_GeneratorAnalysis_src
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_plugins
src_TotemT1T2Validation_GeneratorAnalysis_plugins_parent := TotemT1T2Validation/GeneratorAnalysis
src_TotemT1T2Validation_GeneratorAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_plugins,src/TotemT1T2Validation/GeneratorAnalysis/plugins,PLUGINS))
ifeq ($(strip $(PyTotemT1T2ValidationGeneratorAnalysis)),)
PyTotemT1T2ValidationGeneratorAnalysis := self/src/TotemT1T2Validation/GeneratorAnalysis/python
src_TotemT1T2Validation_GeneratorAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/GeneratorAnalysis/python)
PyTotemT1T2ValidationGeneratorAnalysis_files := $(patsubst src/TotemT1T2Validation/GeneratorAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/GeneratorAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationGeneratorAnalysis_LOC_USE := self  
PyTotemT1T2ValidationGeneratorAnalysis_PACKAGE := self/src/TotemT1T2Validation/GeneratorAnalysis/python
ALL_PRODS += PyTotemT1T2ValidationGeneratorAnalysis
PyTotemT1T2ValidationGeneratorAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/python,src_TotemT1T2Validation_GeneratorAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_python
src_TotemT1T2Validation_GeneratorAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_python,src/TotemT1T2Validation/GeneratorAnalysis/python,PYTHON))
ifeq ($(strip $(TotemT1T2Validation/GeneratorAnalysis)),)
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_src
src_TotemT1T2Validation_GeneratorAnalysis_src_parent := TotemT1T2Validation/GeneratorAnalysis
src_TotemT1T2Validation_GeneratorAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_src,src/TotemT1T2Validation/GeneratorAnalysis/src,LIBRARY))
TotemT1T2ValidationGeneratorAnalysis := self/TotemT1T2Validation/GeneratorAnalysis
TotemT1T2Validation/GeneratorAnalysis := TotemT1T2ValidationGeneratorAnalysis
TotemT1T2ValidationGeneratorAnalysis_files := $(patsubst src/TotemT1T2Validation/GeneratorAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/GeneratorAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationGeneratorAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/GeneratorAnalysis/BuildFile
TotemT1T2ValidationGeneratorAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/T1T2Track SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex Geometry/TotemGeometry TotemAnalysis/T2Cuts FWCore/MessageLogger boost root DataFormats/T2DetId SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep SimGeneral/HepPDTRecord
TotemT1T2ValidationGeneratorAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationGeneratorAnalysis,TotemT1T2ValidationGeneratorAnalysis,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/GeneratorAnalysis/src))
TotemT1T2ValidationGeneratorAnalysis_PACKAGE := self/src/TotemT1T2Validation/GeneratorAnalysis/src
ALL_PRODS += TotemT1T2ValidationGeneratorAnalysis
TotemT1T2ValidationGeneratorAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationGeneratorAnalysis,src/TotemT1T2Validation/GeneratorAnalysis/src,src_TotemT1T2Validation_GeneratorAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_GeneratorAnalysis_test
src_TotemT1T2Validation_GeneratorAnalysis_test_parent := TotemT1T2Validation/GeneratorAnalysis
src_TotemT1T2Validation_GeneratorAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_GeneratorAnalysis_test,src/TotemT1T2Validation/GeneratorAnalysis/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemT1T2Validation/T1Validation)
subdirs_src_TotemT1T2Validation_T1Validation := src_TotemT1T2Validation_T1Validation_test src_TotemT1T2Validation_T1Validation_plugins src_TotemT1T2Validation_T1Validation_python
ifeq ($(strip $(TotemT1T2ValidationT1ValidationPlugins)),)
TotemT1T2ValidationT1ValidationPlugins_files := $(patsubst src/TotemT1T2Validation/T1Validation/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemT1T2Validation/T1Validation/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemT1T2Validation/T1Validation/plugins/$(file). Please fix src/TotemT1T2Validation/T1Validation/plugins/BuildFile.))))
TotemT1T2ValidationT1ValidationPlugins := self/src/TotemT1T2Validation/T1Validation/plugins
TotemT1T2ValidationT1ValidationPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T1Validation/plugins/BuildFile
TotemT1T2ValidationT1ValidationPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger DataFormats/T1DigiWire DataFormats/T1DigiVfat DataFormats/DetId DataFormats/T1DetId Geometry/TotemGeometry Geometry/TotemRecords DataFormats/TrackingRecHit DataFormats/T1RecHit DataFormats/T1T2Track DataFormats/Common DataFormats/T1Cluster SimDataFormats/Track CommonTools/Clustering1D boost root clhep
TotemT1T2ValidationT1ValidationPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT1ValidationPlugins,TotemT1T2ValidationT1ValidationPlugins,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T1Validation/plugins))
TotemT1T2ValidationT1ValidationPlugins_PACKAGE := self/src/TotemT1T2Validation/T1Validation/plugins
ALL_PRODS += TotemT1T2ValidationT1ValidationPlugins
TotemT1T2ValidationT1ValidationPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT1ValidationPlugins,src/TotemT1T2Validation/T1Validation/plugins,src_TotemT1T2Validation_T1Validation_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemT1T2ValidationT1ValidationPlugins,src/TotemT1T2Validation/T1Validation/plugins))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T1Validation_plugins
src_TotemT1T2Validation_T1Validation_plugins_parent := TotemT1T2Validation/T1Validation
src_TotemT1T2Validation_T1Validation_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T1Validation_plugins,src/TotemT1T2Validation/T1Validation/plugins,PLUGINS))
ifeq ($(strip $(PyTotemT1T2ValidationT1Validation)),)
PyTotemT1T2ValidationT1Validation := self/src/TotemT1T2Validation/T1Validation/python
src_TotemT1T2Validation_T1Validation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T1Validation/python)
PyTotemT1T2ValidationT1Validation_files := $(patsubst src/TotemT1T2Validation/T1Validation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T1Validation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT1Validation_LOC_USE := self  
PyTotemT1T2ValidationT1Validation_PACKAGE := self/src/TotemT1T2Validation/T1Validation/python
ALL_PRODS += PyTotemT1T2ValidationT1Validation
PyTotemT1T2ValidationT1Validation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT1Validation,src/TotemT1T2Validation/T1Validation/python,src_TotemT1T2Validation_T1Validation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT1Validation,src/TotemT1T2Validation/T1Validation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T1Validation_python
src_TotemT1T2Validation_T1Validation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T1Validation_python,src/TotemT1T2Validation/T1Validation/python,PYTHON))
ALL_COMMONRULES += src_TotemT1T2Validation_T1Validation_test
src_TotemT1T2Validation_T1Validation_test_parent := TotemT1T2Validation/T1Validation
src_TotemT1T2Validation_T1Validation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T1Validation_test,src/TotemT1T2Validation/T1Validation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemT1T2Validation/T2BackgroundAnalysis)
subdirs_src_TotemT1T2Validation_T2BackgroundAnalysis := src_TotemT1T2Validation_T2BackgroundAnalysis_test src_TotemT1T2Validation_T2BackgroundAnalysis_interface src_TotemT1T2Validation_T2BackgroundAnalysis_python src_TotemT1T2Validation_T2BackgroundAnalysis_src
ifeq ($(strip $(PyTotemT1T2ValidationT2BackgroundAnalysis)),)
PyTotemT1T2ValidationT2BackgroundAnalysis := self/src/TotemT1T2Validation/T2BackgroundAnalysis/python
src_TotemT1T2Validation_T2BackgroundAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2BackgroundAnalysis/python)
PyTotemT1T2ValidationT2BackgroundAnalysis_files := $(patsubst src/TotemT1T2Validation/T2BackgroundAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2BackgroundAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2BackgroundAnalysis_LOC_USE := self  
PyTotemT1T2ValidationT2BackgroundAnalysis_PACKAGE := self/src/TotemT1T2Validation/T2BackgroundAnalysis/python
ALL_PRODS += PyTotemT1T2ValidationT2BackgroundAnalysis
PyTotemT1T2ValidationT2BackgroundAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/python,src_TotemT1T2Validation_T2BackgroundAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2BackgroundAnalysis_python
src_TotemT1T2Validation_T2BackgroundAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2BackgroundAnalysis_python,src/TotemT1T2Validation/T2BackgroundAnalysis/python,PYTHON))
ifeq ($(strip $(TotemT1T2Validation/T2BackgroundAnalysis)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2BackgroundAnalysis_src
src_TotemT1T2Validation_T2BackgroundAnalysis_src_parent := TotemT1T2Validation/T2BackgroundAnalysis
src_TotemT1T2Validation_T2BackgroundAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2BackgroundAnalysis_src,src/TotemT1T2Validation/T2BackgroundAnalysis/src,LIBRARY))
TotemT1T2ValidationT2BackgroundAnalysis := self/TotemT1T2Validation/T2BackgroundAnalysis
TotemT1T2Validation/T2BackgroundAnalysis := TotemT1T2ValidationT2BackgroundAnalysis
TotemT1T2ValidationT2BackgroundAnalysis_files := $(patsubst src/TotemT1T2Validation/T2BackgroundAnalysis/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2BackgroundAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2BackgroundAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2BackgroundAnalysis/BuildFile
TotemT1T2ValidationT2BackgroundAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/T1T2Track SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex Geometry/TotemGeometry TotemAnalysis/T2Cuts
TotemT1T2ValidationT2BackgroundAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2BackgroundAnalysis,TotemT1T2ValidationT2BackgroundAnalysis,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2BackgroundAnalysis/src))
TotemT1T2ValidationT2BackgroundAnalysis_PACKAGE := self/src/TotemT1T2Validation/T2BackgroundAnalysis/src
ALL_PRODS += TotemT1T2ValidationT2BackgroundAnalysis
TotemT1T2ValidationT2BackgroundAnalysis_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2BackgroundAnalysis,src/TotemT1T2Validation/T2BackgroundAnalysis/src,src_TotemT1T2Validation_T2BackgroundAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2BackgroundAnalysis_test
src_TotemT1T2Validation_T2BackgroundAnalysis_test_parent := TotemT1T2Validation/T2BackgroundAnalysis
src_TotemT1T2Validation_T2BackgroundAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2BackgroundAnalysis_test,src/TotemT1T2Validation/T2BackgroundAnalysis/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemT1T2Validation/T2GeometryValidation)
subdirs_src_TotemT1T2Validation_T2GeometryValidation := src_TotemT1T2Validation_T2GeometryValidation_test src_TotemT1T2Validation_T2GeometryValidation_interface src_TotemT1T2Validation_T2GeometryValidation_python src_TotemT1T2Validation_T2GeometryValidation_src
ifeq ($(strip $(PyTotemT1T2ValidationT2GeometryValidation)),)
PyTotemT1T2ValidationT2GeometryValidation := self/src/TotemT1T2Validation/T2GeometryValidation/python
src_TotemT1T2Validation_T2GeometryValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2GeometryValidation/python)
PyTotemT1T2ValidationT2GeometryValidation_files := $(patsubst src/TotemT1T2Validation/T2GeometryValidation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2GeometryValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2GeometryValidation_LOC_USE := self  
PyTotemT1T2ValidationT2GeometryValidation_PACKAGE := self/src/TotemT1T2Validation/T2GeometryValidation/python
ALL_PRODS += PyTotemT1T2ValidationT2GeometryValidation
PyTotemT1T2ValidationT2GeometryValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/python,src_TotemT1T2Validation_T2GeometryValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2GeometryValidation_python
src_TotemT1T2Validation_T2GeometryValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2GeometryValidation_python,src/TotemT1T2Validation/T2GeometryValidation/python,PYTHON))
ifeq ($(strip $(TotemT1T2Validation/T2GeometryValidation)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2GeometryValidation_src
src_TotemT1T2Validation_T2GeometryValidation_src_parent := TotemT1T2Validation/T2GeometryValidation
src_TotemT1T2Validation_T2GeometryValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2GeometryValidation_src,src/TotemT1T2Validation/T2GeometryValidation/src,LIBRARY))
TotemT1T2ValidationT2GeometryValidation := self/TotemT1T2Validation/T2GeometryValidation
TotemT1T2Validation/T2GeometryValidation := TotemT1T2ValidationT2GeometryValidation
TotemT1T2ValidationT2GeometryValidation_files := $(patsubst src/TotemT1T2Validation/T2GeometryValidation/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2GeometryValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2GeometryValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2GeometryValidation/BuildFile
TotemT1T2ValidationT2GeometryValidation_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root rootcore DataFormats/T2Cluster TotemRawData/RawToDigi TotemRawDataLibrary/DataFormats TotemCondFormats/DAQInformation TotemCondFormats/DataRecord SimDataFormats/GeneratorProducts DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep xerces-c
TotemT1T2ValidationT2GeometryValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2GeometryValidation,TotemT1T2ValidationT2GeometryValidation,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2GeometryValidation/src))
TotemT1T2ValidationT2GeometryValidation_PACKAGE := self/src/TotemT1T2Validation/T2GeometryValidation/src
ALL_PRODS += TotemT1T2ValidationT2GeometryValidation
TotemT1T2ValidationT2GeometryValidation_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2GeometryValidation,src/TotemT1T2Validation/T2GeometryValidation/src,src_TotemT1T2Validation_T2GeometryValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2GeometryValidation_test
src_TotemT1T2Validation_T2GeometryValidation_test_parent := TotemT1T2Validation/T2GeometryValidation
src_TotemT1T2Validation_T2GeometryValidation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2GeometryValidation_test,src/TotemT1T2Validation/T2GeometryValidation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemT1T2Validation/T2RecoValidation)
subdirs_src_TotemT1T2Validation_T2RecoValidation := src_TotemT1T2Validation_T2RecoValidation_test src_TotemT1T2Validation_T2RecoValidation_python src_TotemT1T2Validation_T2RecoValidation_src
ifeq ($(strip $(PyTotemT1T2ValidationT2RecoValidation)),)
PyTotemT1T2ValidationT2RecoValidation := self/src/TotemT1T2Validation/T2RecoValidation/python
src_TotemT1T2Validation_T2RecoValidation_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemT1T2Validation/T2RecoValidation/python)
PyTotemT1T2ValidationT2RecoValidation_files := $(patsubst src/TotemT1T2Validation/T2RecoValidation/python/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2RecoValidation/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemT1T2ValidationT2RecoValidation_LOC_USE := self  
PyTotemT1T2ValidationT2RecoValidation_PACKAGE := self/src/TotemT1T2Validation/T2RecoValidation/python
ALL_PRODS += PyTotemT1T2ValidationT2RecoValidation
PyTotemT1T2ValidationT2RecoValidation_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/python,src_TotemT1T2Validation_T2RecoValidation_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/python))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2RecoValidation_python
src_TotemT1T2Validation_T2RecoValidation_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2RecoValidation_python,src/TotemT1T2Validation/T2RecoValidation/python,PYTHON))
ifeq ($(strip $(TotemT1T2Validation/T2RecoValidation)),)
ALL_COMMONRULES += src_TotemT1T2Validation_T2RecoValidation_src
src_TotemT1T2Validation_T2RecoValidation_src_parent := TotemT1T2Validation/T2RecoValidation
src_TotemT1T2Validation_T2RecoValidation_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2RecoValidation_src,src/TotemT1T2Validation/T2RecoValidation/src,LIBRARY))
TotemT1T2ValidationT2RecoValidation := self/TotemT1T2Validation/T2RecoValidation
TotemT1T2Validation/T2RecoValidation := TotemT1T2ValidationT2RecoValidation
TotemT1T2ValidationT2RecoValidation_files := $(patsubst src/TotemT1T2Validation/T2RecoValidation/src/%,%,$(wildcard $(foreach dir,src/TotemT1T2Validation/T2RecoValidation/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
TotemT1T2ValidationT2RecoValidation_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemT1T2Validation/T2RecoValidation/BuildFile
TotemT1T2ValidationT2RecoValidation_LOC_USE := self  FWCore/MessageLogger boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet root SimDataFormats/GeneratorProducts DataFormats/T2Cluster DataFormats/T2DetId Geometry/TotemGeometry SimDataFormats/TrackingHit SimDataFormats/CrossingFrame DataFormats/T2Road clhep
TotemT1T2ValidationT2RecoValidation_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemT1T2ValidationT2RecoValidation,TotemT1T2ValidationT2RecoValidation,$(SCRAMSTORENAME_LIB),src/TotemT1T2Validation/T2RecoValidation/src))
TotemT1T2ValidationT2RecoValidation_PACKAGE := self/src/TotemT1T2Validation/T2RecoValidation/src
ALL_PRODS += TotemT1T2ValidationT2RecoValidation
TotemT1T2ValidationT2RecoValidation_INIT_FUNC        += $$(eval $$(call Library,TotemT1T2ValidationT2RecoValidation,src/TotemT1T2Validation/T2RecoValidation/src,src_TotemT1T2Validation_T2RecoValidation_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_COMMONRULES += src_TotemT1T2Validation_T2RecoValidation_test
src_TotemT1T2Validation_T2RecoValidation_test_parent := TotemT1T2Validation/T2RecoValidation
src_TotemT1T2Validation_T2RecoValidation_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemT1T2Validation_T2RecoValidation_test,src/TotemT1T2Validation/T2RecoValidation/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/UATree/MitEdm)
subdirs_src_UATree_MitEdm := src_UATree_MitEdm_python src_UATree_MitEdm_src
ifeq ($(strip $(PyUATreeMitEdm)),)
PyUATreeMitEdm := self/src/UATree/MitEdm/python
src_UATree_MitEdm_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/MitEdm/python)
PyUATreeMitEdm_files := $(patsubst src/UATree/MitEdm/python/%,%,$(wildcard $(foreach dir,src/UATree/MitEdm/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeMitEdm_LOC_USE := self  
PyUATreeMitEdm_PACKAGE := self/src/UATree/MitEdm/python
ALL_PRODS += PyUATreeMitEdm
PyUATreeMitEdm_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeMitEdm,src/UATree/MitEdm/python,src_UATree_MitEdm_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeMitEdm,src/UATree/MitEdm/python))
endif
ALL_COMMONRULES += src_UATree_MitEdm_python
src_UATree_MitEdm_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_MitEdm_python,src/UATree/MitEdm/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/UATree/UABaseTree)
subdirs_src_UATree_UABaseTree := src_UATree_UABaseTree_interface src_UATree_UABaseTree_python src_UATree_UABaseTree_macros src_UATree_UABaseTree_src
ifeq ($(strip $(PyUATreeUABaseTree)),)
PyUATreeUABaseTree := self/src/UATree/UABaseTree/python
src_UATree_UABaseTree_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/UATree/UABaseTree/python)
PyUATreeUABaseTree_files := $(patsubst src/UATree/UABaseTree/python/%,%,$(wildcard $(foreach dir,src/UATree/UABaseTree/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyUATreeUABaseTree_LOC_USE := self  
PyUATreeUABaseTree_PACKAGE := self/src/UATree/UABaseTree/python
ALL_PRODS += PyUATreeUABaseTree
PyUATreeUABaseTree_INIT_FUNC        += $$(eval $$(call PythonProduct,PyUATreeUABaseTree,src/UATree/UABaseTree/python,src_UATree_UABaseTree_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyUATreeUABaseTree,src/UATree/UABaseTree/python))
endif
ALL_COMMONRULES += src_UATree_UABaseTree_python
src_UATree_UABaseTree_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_UATree_UABaseTree_python,src/UATree/UABaseTree/python,PYTHON))
ifeq ($(strip $(UATree/UABaseTree)),)
ALL_COMMONRULES += src_UATree_UABaseTree_src
src_UATree_UABaseTree_src_parent := UATree/UABaseTree
src_UATree_UABaseTree_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_UABaseTree_src,src/UATree/UABaseTree/src,LIBRARY))
UATreeUABaseTree := self/UATree/UABaseTree
UATree/UABaseTree := UATreeUABaseTree
UATreeUABaseTree_files := $(patsubst src/UATree/UABaseTree/src/%,%,$(wildcard $(foreach dir,src/UATree/UABaseTree/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeUABaseTree_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/UABaseTree/BuildFile
UATreeUABaseTree_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/Common DataFormats/Candidate DataFormats/HepMCCandidate SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts SimDataFormats/PileupSummaryInfo DataFormats/METReco L1Trigger/GlobalTriggerAnalyzer HLTrigger/HLTcore CondFormats/L1TObjects CondFormats/DataRecord DataFormats/L1GlobalTrigger DataFormats/Math DataFormats/TrackReco DataFormats/VertexReco DataFormats/JetReco DataFormats/MuonReco RecoEgamma/EgammaTools JetMETCorrections/Algorithms JetMETCorrections/Objects JetMETCorrections/Modules DataFormats/BeamSpot DataFormats/HLTReco DataFormats/CaloTowers DataFormats/HcalDetId UATree/UADataFormat UATree/MitEdm DataFormats/DetId CondFormats/CastorObjects CondFormats/JetMETObjects CalibFormats/CastorObjects CalibFormats/HcalObjects rootrflx
UATreeUABaseTree_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UATreeUABaseTree,UATreeUABaseTree,$(SCRAMSTORENAME_LIB),src/UATree/UABaseTree/src))
UATreeUABaseTree_PACKAGE := self/src/UATree/UABaseTree/src
ALL_PRODS += UATreeUABaseTree
UATreeUABaseTree_INIT_FUNC        += $$(eval $$(call Library,UATreeUABaseTree,src/UATree/UABaseTree/src,src_UATree_UABaseTree_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ALL_PACKAGES += $(patsubst src/%,%,src/UATree/UADataFormat)
subdirs_src_UATree_UADataFormat := src_UATree_UADataFormat_src
ALL_SUBSYSTEMS+=$(patsubst src/%,%,src/ForwardAnalysis)
subdirs_src_ForwardAnalysis = src_ForwardAnalysis_ForwardTTreeAnalysis
ALL_PACKAGES += $(patsubst src/%,%,src/ForwardAnalysis/ForwardTTreeAnalysis)
subdirs_src_ForwardAnalysis_ForwardTTreeAnalysis := src_ForwardAnalysis_ForwardTTreeAnalysis_plugins src_ForwardAnalysis_ForwardTTreeAnalysis_python src_ForwardAnalysis_ForwardTTreeAnalysis_src
ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_plugins
src_ForwardAnalysis_ForwardTTreeAnalysis_plugins_parent := ForwardAnalysis/ForwardTTreeAnalysis
src_ForwardAnalysis_ForwardTTreeAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_plugins,src/ForwardAnalysis/ForwardTTreeAnalysis/plugins,PLUGINS))
ifeq ($(strip $(PyForwardAnalysisForwardTTreeAnalysis)),)
PyForwardAnalysisForwardTTreeAnalysis := self/src/ForwardAnalysis/ForwardTTreeAnalysis/python
src_ForwardAnalysis_ForwardTTreeAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/ForwardAnalysis/ForwardTTreeAnalysis/python)
PyForwardAnalysisForwardTTreeAnalysis_files := $(patsubst src/ForwardAnalysis/ForwardTTreeAnalysis/python/%,%,$(wildcard $(foreach dir,src/ForwardAnalysis/ForwardTTreeAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyForwardAnalysisForwardTTreeAnalysis_LOC_USE := self  
PyForwardAnalysisForwardTTreeAnalysis_PACKAGE := self/src/ForwardAnalysis/ForwardTTreeAnalysis/python
ALL_PRODS += PyForwardAnalysisForwardTTreeAnalysis
PyForwardAnalysisForwardTTreeAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/python,src_ForwardAnalysis_ForwardTTreeAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyForwardAnalysisForwardTTreeAnalysis,src/ForwardAnalysis/ForwardTTreeAnalysis/python))
endif
ALL_COMMONRULES += src_ForwardAnalysis_ForwardTTreeAnalysis_python
src_ForwardAnalysis_ForwardTTreeAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_ForwardAnalysis_ForwardTTreeAnalysis_python,src/ForwardAnalysis/ForwardTTreeAnalysis/python,PYTHON))
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/TotemAnalysisEvent)
subdirs_src_TotemAnalysis_TotemAnalysisEvent := src_TotemAnalysis_TotemAnalysisEvent_interface src_TotemAnalysis_TotemAnalysisEvent_src
ALL_PACKAGES += $(patsubst src/%,%,src/TotemAnalysis/TotemRPAnalysis)
subdirs_src_TotemAnalysis_TotemRPAnalysis := src_TotemAnalysis_TotemRPAnalysis_src src_TotemAnalysis_TotemRPAnalysis_plugins src_TotemAnalysis_TotemRPAnalysis_python src_TotemAnalysis_TotemRPAnalysis_test
ifeq ($(strip $(TotemAnalysisTotemAnalysisEventPlugins)),)
TotemAnalysisTotemAnalysisEventPlugins_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/TotemAnalysis/TotemRPAnalysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/TotemAnalysis/TotemRPAnalysis/plugins/$(file). Please fix src/TotemAnalysis/TotemRPAnalysis/plugins/BuildFile.))))
TotemAnalysisTotemAnalysisEventPlugins := self/src/TotemAnalysis/TotemRPAnalysis/plugins
TotemAnalysisTotemAnalysisEventPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAnalysis/TotemRPAnalysis/plugins/BuildFile
TotemAnalysisTotemAnalysisEventPlugins_LOC_USE := self  FWCore/Framework FWCore/ParameterSet CommonTools/UtilAlgos TotemAnalysis/TotemRPAnalysis TotemAnalysis/TotemAnalysisEvent ForwardAnalysis/ForwardTTreeAnalysis root hepmc clhep boost_header
TotemAnalysisTotemAnalysisEventPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,TotemAnalysisTotemAnalysisEventPlugins,TotemAnalysisTotemAnalysisEventPlugins,$(SCRAMSTORENAME_LIB),src/TotemAnalysis/TotemRPAnalysis/plugins))
TotemAnalysisTotemAnalysisEventPlugins_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/plugins
ALL_PRODS += TotemAnalysisTotemAnalysisEventPlugins
TotemAnalysisTotemAnalysisEventPlugins_INIT_FUNC        += $$(eval $$(call Library,TotemAnalysisTotemAnalysisEventPlugins,src/TotemAnalysis/TotemRPAnalysis/plugins,src_TotemAnalysis_TotemRPAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
else
$(eval $(call MultipleWarningMsg,TotemAnalysisTotemAnalysisEventPlugins,src/TotemAnalysis/TotemRPAnalysis/plugins))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_plugins
src_TotemAnalysis_TotemRPAnalysis_plugins_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_plugins,src/TotemAnalysis/TotemRPAnalysis/plugins,PLUGINS))
ifeq ($(strip $(PyTotemAnalysisTotemRPAnalysis)),)
PyTotemAnalysisTotemRPAnalysis := self/src/TotemAnalysis/TotemRPAnalysis/python
src_TotemAnalysis_TotemRPAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/TotemAnalysis/TotemRPAnalysis/python)
PyTotemAnalysisTotemRPAnalysis_files := $(patsubst src/TotemAnalysis/TotemRPAnalysis/python/%,%,$(wildcard $(foreach dir,src/TotemAnalysis/TotemRPAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyTotemAnalysisTotemRPAnalysis_LOC_USE := self  
PyTotemAnalysisTotemRPAnalysis_PACKAGE := self/src/TotemAnalysis/TotemRPAnalysis/python
ALL_PRODS += PyTotemAnalysisTotemRPAnalysis
PyTotemAnalysisTotemRPAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyTotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/python,src_TotemAnalysis_TotemRPAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyTotemAnalysisTotemRPAnalysis,src/TotemAnalysis/TotemRPAnalysis/python))
endif
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_python
src_TotemAnalysis_TotemRPAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_python,src/TotemAnalysis/TotemRPAnalysis/python,PYTHON))
ALL_COMMONRULES += src_TotemAnalysis_TotemRPAnalysis_test
src_TotemAnalysis_TotemRPAnalysis_test_parent := TotemAnalysis/TotemRPAnalysis
src_TotemAnalysis_TotemRPAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_TotemAnalysis_TotemRPAnalysis_test,src/TotemAnalysis/TotemRPAnalysis/test,TEST))
ALL_PACKAGES += $(patsubst src/%,%,src/GeneratorInterface/PompytInterface)
subdirs_src_GeneratorInterface_PompytInterface := src_GeneratorInterface_PompytInterface_src src_GeneratorInterface_PompytInterface_python src_GeneratorInterface_PompytInterface_test
ifeq ($(strip $(PyGeneratorInterfacePompytInterface)),)
PyGeneratorInterfacePompytInterface := self/src/GeneratorInterface/PompytInterface/python
src_GeneratorInterface_PompytInterface_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/GeneratorInterface/PompytInterface/python)
PyGeneratorInterfacePompytInterface_files := $(patsubst src/GeneratorInterface/PompytInterface/python/%,%,$(wildcard $(foreach dir,src/GeneratorInterface/PompytInterface/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGeneratorInterfacePompytInterface_LOC_USE := self  
PyGeneratorInterfacePompytInterface_PACKAGE := self/src/GeneratorInterface/PompytInterface/python
ALL_PRODS += PyGeneratorInterfacePompytInterface
PyGeneratorInterfacePompytInterface_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGeneratorInterfacePompytInterface,src/GeneratorInterface/PompytInterface/python,src_GeneratorInterface_PompytInterface_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyGeneratorInterfacePompytInterface,src/GeneratorInterface/PompytInterface/python))
endif
ALL_COMMONRULES += src_GeneratorInterface_PompytInterface_python
src_GeneratorInterface_PompytInterface_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GeneratorInterface_PompytInterface_python,src/GeneratorInterface/PompytInterface/python,PYTHON))
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
ALL_COMMONRULES += src_GeneratorInterface_PompytInterface_test
src_GeneratorInterface_PompytInterface_test_parent := GeneratorInterface/PompytInterface
src_GeneratorInterface_PompytInterface_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GeneratorInterface_PompytInterface_test,src/GeneratorInterface/PompytInterface/test,TEST))
