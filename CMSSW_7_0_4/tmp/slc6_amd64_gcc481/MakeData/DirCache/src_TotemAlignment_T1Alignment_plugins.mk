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
