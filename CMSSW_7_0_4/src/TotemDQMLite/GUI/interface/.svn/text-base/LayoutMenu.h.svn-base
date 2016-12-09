/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#ifndef _LayoutMenu_h_ 
#define _LayoutMenu_h_ 

#include "TotemDQMLite/GUI/interface/MainWindow.h"
#include "TotemDQMLite/GUI/interface/RunEventNavigationBox.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>

/**
 * \ingroup TotemDQM
 * \brief The part of the DockWidget below canvases, where all the buttons are placed.
 */
class LayoutMenu : public QWidget
{
  Q_OBJECT

  private:
    QPushButton *addColButton, *delColButton, *addRowButton, *delRowButton;
    QPushButton *saveLayoutButton, *loadLayoutButton;
    RunEventNavigationBox *runEventNavigationBox;
	QPushButton *refreshButton, *screenshotButton, *saveRootButton;

    /// returns pointer to the parent MainWindow
    MainWindow *GetMainWindow();

  public:
    LayoutMenu(QWidget *parent = 0, Qt::WindowFlags flags = 0);

    void RunsChanged();
    void EventLimitChanged(int minEventNr, int maxEventNr);
    void RunChanged(int runIdx);
    void EventChanged(int eventNr);
    void RunAndEventChanged(int runNr, int eventNr);

    // getters for buttons
    QPushButton *GetAddColButton() { return addColButton; }
    QPushButton *GetDelColButton() { return delColButton; }
    QPushButton *GetAddRowButton() { return addRowButton; }
    QPushButton *GetDelRowButton() { return delRowButton; }
    QPushButton *GetSaveLayout() { return saveLayoutButton; }       ///< Returns the SaveLayout button
    QPushButton *GetLoadLayout() { return loadLayoutButton; }       ///< Returns the LoadLayout button
};

#endif
