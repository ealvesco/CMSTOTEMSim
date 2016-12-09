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
