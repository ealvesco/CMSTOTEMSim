/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

/*************************************************************************************
 * Dialog Window to choose the graph for the canvas
 * **********************************************************************************/

#ifndef _ChoosePlotDialog_h_
#define _ChoosePlotDialog_h_

#include "TotemDQMLite/Core/interface/PlotManager.h"
#include <QDialog>

class QStandardItemModel;
class QTreeWidgetItem;
class QTreeWidget;
class QListView;
class DQMPlot;


/**
 * \ingroup TotemDQM
 * \brief Dialog (Window) to select the plot 
 *
 * Selects the plot to be placed later in the RootCanvasWidget
 */
class ChoosePlotDialog : public QDialog
{
  Q_OBJECT
  
  private:
    QTreeWidget *inTree;
    QStandardItemModel *outModel;
    QListView *outView;

    DQMPlot **mo;
    std::string *graphIdent;

    // auxiliary functions for treeModel (inView) creation
    QTreeWidget *CreateInTree();
    void AddItemToList(QTreeWidgetItem*, std::string, std::string);
    void AddItemToList2(QTreeWidgetItem*, std::string, std::string, std::string);
    void AddItemToListFinal(QTreeWidgetItem*, std::string, std::string);
    //

  public:
    ChoosePlotDialog(QWidget *parent = 0, Qt::WindowFlags f = 0);
    void SetDQMPlot(DQMPlot **_mo) {mo = _mo;}
    void SetIdent(std::string *ident) {graphIdent = ident;}
    void SetDQMPlotIdent(DQMPlot **_mo, std::string *ident) { SetDQMPlot(_mo); SetIdent(ident); }


  public slots:
    void UpdateOutView();
    void Accepted();
    void Empty();

};

#endif
