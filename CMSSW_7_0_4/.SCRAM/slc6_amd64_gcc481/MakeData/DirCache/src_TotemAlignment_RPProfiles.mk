ifeq ($(strip $(TotemAlignment/RPProfiles)),)
src_TotemAlignment_RPProfiles := self/TotemAlignment/RPProfiles
TotemAlignment/RPProfiles  := src_TotemAlignment_RPProfiles
src_TotemAlignment_RPProfiles_BuildFile    := $(WORKINGDIR)/cache/bf/src/TotemAlignment/RPProfiles/BuildFile
src_TotemAlignment_RPProfiles_LOC_USE := self
src_TotemAlignment_RPProfiles_EX_USE   := $(foreach d,$(src_TotemAlignment_RPProfiles_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_TotemAlignment_RPProfiles
src_TotemAlignment_RPProfiles_INIT_FUNC += $$(eval $$(call EmptyPackage,src_TotemAlignment_RPProfiles,src/TotemAlignment/RPProfiles))
endif

