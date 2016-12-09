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
