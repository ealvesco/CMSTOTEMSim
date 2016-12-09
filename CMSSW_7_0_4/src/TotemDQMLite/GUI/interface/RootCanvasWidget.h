/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _RootCanvasWidget_h_
#define _RootCanvasWidget_h_

#include "TotemDQMLite/Core/interface/DQMPlot.h"
#include "TotemDQMLite/GUI/interface/QRootCanvas.h"

#include <QWidget>
#include <QMouseEvent>
#include "TFile.h"
#include "TSystem.h"
#include "TApplication.h"
#include "TCanvas.h"

class CanvasGrid;
class MainWindow;

/**
 * \ingroup TotemDQM
 * \brief A Wrapper for TQtWidget class
 *
 * Not only a ROOT Canvas, but it also keeps DQMPlot.
 *
 * Added reaction for double-click (Choose Dialog Window) and on Shift+click or click with both mouse buttons (zooming feature).
 */
class RootCanvasWidget : public QRootCanvas
{
    Q_OBJECT

private:
    DQMPlot *monitorOutput;
    std::string graphIdent;               ///< ident string for monitorOutput
    QWidget *par;

public:
    RootCanvasWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0, bool v = true);

    void DeleteDQMPlot();
    void SetDQMPlot(DQMPlot *monOut);
    void SetGraphIdent(std::string ident)
    { graphIdent = ident; }
    void Refresh();
    void Clear();
    void Reload();                        ///< get new DQMPlot from plotManager

    QWidget *parent();
    MainWindow *GetMainWindow();
    std::string GraphIdent()
    { return graphIdent; }
    DQMPlot *GetDQMPlot()
    { return monitorOutput; }

    virtual bool event(QEvent *e);

private slots:
    void RunChooseDialog(QMouseEvent *);  ///< choosing the graph

    signals:
    void ChooseDialog(QMouseEvent *);
    void OpenInNewWindow(DQMPlot *, std::string);

};

#endif
