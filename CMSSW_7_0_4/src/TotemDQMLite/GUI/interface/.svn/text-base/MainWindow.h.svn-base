/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#ifndef _MainWindow_h_
#define _MainWindow_h_

#include <qmainwindow.h>
#include <QDomElement>

#include <vector>
#include <string>

class DockWidget;
class ChoosePlotDialog;
class DQMPlot;

namespace cms {
  class Exception;
}

/**
 * \ingroup TotemDQM
 * \brief The main window of TotemDQM.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

  protected:
    /// menu entries the enable status need to be toggled with Open/Close states
    std::vector<QAction*> menuActions;

    /// Menu entry File/Open
    QAction *menuFileOpenAction;

    std::vector<DockWidget*> dockWidgets;

    unsigned int runNr;                             ///< current run number
    unsigned int eventNr;                           ///< current event number, counted from 1
    unsigned int minEventNr;                        ///< minimum event number
    unsigned int maxEventNr;                        ///< maximal event number, counted from 1

    /// reload the graphs from plotManager
    void ReloadCanvas();

    /// clear all the graphs from all the canvases
    void ClearCanvas();

    /// Propagate run-list change
    void RunsChanged();

    /// Propagate event limit change
    void EventLimitChanged();

    /// adds new DockWidget as a tab or a window
    DockWidget* AddDockWidget(bool tabbed);

    /// Adds a new DockWidget from a window layout file.
    /// \param fileName window layout filename
    void AddDockWidgetFrom(std::string, bool tabbed);

    /// Adds a new DockWidget from a window layout file selected in a GUI dialog.
    void AddDockWidgetFrom(bool tabbed);

    void HandleCmsException(const char *where, const cms::Exception &e);
    QString ParseCmsException(const char *where, const cms::Exception &e);

  public:
    /// Creates all the MainWindow structure.
    MainWindow(QWidget* parent);

    virtual ~MainWindow();

    /// creates a new DockWidget
    DockWidget* NewDockWidget();

    /// puts the given DockWidget to the end of the list
    void InsertDockWidget(DockWidget *);

    /// removes the given DockWidget from the list
    void RemoveDockWidget(DockWidget *);

    /// instance of the dialog to choose a plot
    ChoosePlotDialog *chooseDialog;

    /// Runs the Choose Dialog Window
    /// \param mo DQMPlot one wants to change
    /// \param ident plot identification one wants to change (related to mo)
    int ChooseDialog(DQMPlot **mo, std::string *ident, int x = 0, int y = 0, int x_size = 0, int y_size = 0);

    /// processes one <MainWindow> tag
    bool LoadLayout(QDomElement&);

    /// loads an application layout
    void LoadLayout(std::string);

    /// saves an application layout
    void SaveLayout(QDomDocument&, QDomElement&);

  public slots:
    /// Refreshes all the canvases and upadte all DQM Modules
    void Refresh();

    /// refresh all the canvases
    void RefreshCanvas();

    /// Creates a new window
    void AddWindow();

    /// Creates a new window
    void AddTab();

    /// Creates new window from a window layout that is selected from
    /// a graphical dialog.
    void AddWindowFrom();

    /// Just as AddWindowFrom, but it creates a new tab.
    void AddTabFrom();

    /// zooms (creates new DockWidget with only one canvas) a plot
    void OpenCanvasInNewWindow(DQMPlot*, std::string ident);

    /// Runs Open File Dialog and open the selected configuration file
    /// Returs true in case of success.
    bool OpenSource();

    /// Open the specified sources, without the dialog.
    /// if layoutFileName is empty, no layout loaded at start-up
    /// Returs true in case of success.
    bool OpenSource(const std::vector<std::string> &recoFileNames, const std::string &confFileName,
            const std::string &layoutFileName);

    /// Called any time the event number has been changed
    /// \param n new event number, counted from 1
    void EventNrChanged(int n);

    void EventNumberInc()
    {
      EventNrChanged(eventNr + 1);
    }

    void EventNumberDec()
    {
      EventNrChanged(eventNr - 1);
    }

    /// Called any time the run index/number has been changed
    /// \param idx new run index, counted from 0
    void RunNumberChanged(int idx);

    void RunAndEventNumbersChanged(unsigned int runNr, unsigned int eventNr);

    /// Saves the Application Layout
    void SaveLayout();

    /// Loads the Application Layout
    void LoadLayout();

    /// Clears the layout
    /// Removes all Dock Widgets and leaves the Main Window empty
    void ClearLayout();

    /// Close files, releases modules and leaves the Main Window empty.
    void CloseSource();

    /// Saves plots to a ROOT file
    /// All plots registered in the PlotManager are saved to one ROOT file
    void SaveAs();
};

#endif
