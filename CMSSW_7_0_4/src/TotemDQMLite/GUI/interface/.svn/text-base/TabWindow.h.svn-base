/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#ifndef _TabWindow_h_ 
#define _TabWindow_h_ 

#include <QWidget>
#include <QDomElement>
#include <QVBoxLayout>
#include <string>
#include "TotemDQMLite/Core/interface/DQMPlot.h"


class LayoutMenu;
class CanvasGrid;
class MainWindow;
class DockWidget;

/**
 * \ingroup TotemDQM
 * \brief A container for CanvasGrid and LayoutMenu
 */
class TabWindow : public QWidget
{
  Q_OBJECT

  private:
    QVBoxLayout *layout;
    bool ifLayoutMenu;
    LayoutMenu *layoutMenu;
    CanvasGrid *canvasGrid; QWidget *canvasGridContents;

    MainWindow *GetMainWindow();
    DockWidget *GetDockWidget();


  public:
    TabWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    TabWindow(DQMPlot*, std::string, QWidget *parent = 0, Qt::WindowFlags flags = 0);

    /// Spread the information about event number change to LayoutMenu
    void EventChanged(int eventNr);

    /// Spread the information about run index change to LayoutMenu
    void RunChanged(int n);

    void RunAndEventChanged(int runNr, int eventNr);

    /// Spread the information about event number limit change to LayoutMenu
    void EventLimitChanged(int minEventNr, int maxEventNr);

    /// Spread the information about run number limit change to LayoutMenu
    void RunsChanged();
  
    void Refresh();                                 ///< Refreshes all the canvases
    void Reload();                                  ///< Reloads the graphs from PlotManager
    void Clear();                                   ///< Clears all the graphs from all the canvases

    // saving / loading layout
    void SaveLayout(QDomDocument&, QDomElement&);
    bool LoadLayout(QDomElement&);
    bool LoadLayout(std::string);


  public slots:
    /// Saves Window Layout
    void SaveLayout();
    /// Loads Window Layout
    void LoadLayout();
    /// Clear Window Layout
    void ClearLayout();
    void Screenshot();
};
  
#endif
