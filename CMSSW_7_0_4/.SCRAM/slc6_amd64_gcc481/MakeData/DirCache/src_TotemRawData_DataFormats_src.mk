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
