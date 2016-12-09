/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _DockWidget_h_
#define _DockWidget_h_

#include <QDockWidget>
#include <QDomElement>
#include "TotemDQMLite/Core/interface/DQMPlot.h"

#include <string>

class TabWindow;
class QEvent;
class MainWindow;

/**
 * \ingroup TotemDQM
 * \brief Special QDockWidget for DQM
 *
 * Features added to the normal QDockWidget:
 * - automatically removes from the MainWindow DockWidget's list while closing
 * - automatically changes itself to Window (reaction on alt+tab) while detaching from the Main Window
 * - resizes itself after mouse scroll was used
 */
class DockWidget : public QDockWidget
{
  Q_OBJECT

  private:
    bool firstRefreshAfterShow;
    bool toBeWindow, applicationLayoutFloating;
    TabWindow *tabWindow;

  public:
    DockWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0, std::string windowName = "Untitled");

    /// constructor for zoomed objects (one object in the DockWidget)
    DockWidget(DQMPlot*, std::string, QWidget *parent = 0, Qt::WindowFlags flags = 0, std::string windowName = "Untitled");
    
    MainWindow* GetMainWindow()
      { return (MainWindow*)parent(); }

    /// Spreads the information to TabWindow after event number was changed
    void EventChanged(int eventNr);

    /// Spreads the information to TabWindow after run index was changed
    void RunChanged(int idx);

    void RunAndEventChanged(int runNr, int eventNr);

    /// Spreads the information to TabWindow after event number limit was changed
    void EventLimitChanged(int minEventNr, int maxEventNr);

    /// Spreads the information to TabWindow after run number limit was changed
    void RunsChanged();

    void Refresh();                                 ///< Refreshes all the canvases
    void ReloadCanvas();                            ///< Realoads the graphs from plotManager
    void ClearCanvas();                             ///< Clears all the graphs from all the canvases

    // saving / loading layout
    void SaveLayout(QDomDocument&, QDomElement&);
    bool LoadLayout(QDomElement&);
    bool LoadLayout(std::string);

    /// returns the default directory with layouts
    static std::string GetDefaultLayoutDirectory();

    virtual bool event(QEvent *e);

  public slots:
    void ChangeToWindow(bool t);

};

#endif
