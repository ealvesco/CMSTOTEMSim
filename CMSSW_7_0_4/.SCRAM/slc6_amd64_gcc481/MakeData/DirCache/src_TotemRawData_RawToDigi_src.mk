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
