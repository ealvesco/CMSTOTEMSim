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
