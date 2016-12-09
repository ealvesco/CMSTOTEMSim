ifeq ($(strip $(CMS-TOTEM-Ntuples/TOTEMdataFormat)),)
ALL_COMMONRULES += src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src
src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src_parent := CMS-TOTEM-Ntuples/TOTEMdataFormat
src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src,LIBRARY))
CMS-TOTEM-NtuplesTOTEMdataFormat := self/CMS-TOTEM-Ntuples/TOTEMdataFormat
CMS-TOTEM-Ntuples/TOTEMdataFormat := CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_files := $(patsubst src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src/%,%,$(wildcard $(foreach dir,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
CMS-TOTEM-NtuplesTOTEMdataFormat_LOC_USE := self  
CMS-TOTEM-NtuplesTOTEMdataFormat_PACKAGE := self/src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src
ALL_PRODS += CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_CLASS := LIBRARY
CMS-TOTEM-Ntuples/TOTEMdataFormat_forbigobj+=CMS-TOTEM-NtuplesTOTEMdataFormat
CMS-TOTEM-NtuplesTOTEMdataFormat_INIT_FUNC        += $$(eval $$(call Library,CMS-TOTEM-NtuplesTOTEMdataFormat,src/CMS-TOTEM-Ntuples/TOTEMdataFormat/src,src_CMS-TOTEM-Ntuples_TOTEMdataFormat_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
