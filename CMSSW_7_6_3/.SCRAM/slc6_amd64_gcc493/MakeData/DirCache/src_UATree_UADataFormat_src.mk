ifeq ($(strip $(UATree/UADataFormat)),)
ALL_COMMONRULES += src_UATree_UADataFormat_src
src_UATree_UADataFormat_src_parent := UATree/UADataFormat
src_UATree_UADataFormat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_UATree_UADataFormat_src,src/UATree/UADataFormat/src,LIBRARY))
UATreeUADataFormat := self/UATree/UADataFormat
UATree/UADataFormat := UATreeUADataFormat
UATreeUADataFormat_files := $(patsubst src/UATree/UADataFormat/src/%,%,$(wildcard $(foreach dir,src/UATree/UADataFormat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
UATreeUADataFormat_BuildFile    := $(WORKINGDIR)/cache/bf/src/UATree/UADataFormat/BuildFile
UATreeUADataFormat_LOC_USE := self  root rootmath rootrflx rootcore
UATreeUADataFormat_EX_LIB   := UATreeUADataFormat
UATreeUADataFormat_EX_USE   := $(foreach d,$(UATreeUADataFormat_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
UATreeUADataFormat_PACKAGE := self/src/UATree/UADataFormat/src
ALL_PRODS += UATreeUADataFormat
UATreeUADataFormat_CLASS := LIBRARY
UATree/UADataFormat_forbigobj+=UATreeUADataFormat
UATreeUADataFormat_INIT_FUNC        += $$(eval $$(call Library,UATreeUADataFormat,src/UATree/UADataFormat/src,src_UATree_UADataFormat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
