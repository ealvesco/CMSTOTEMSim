/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "TotemDQMLite/GUI/interface/RootCanvasWidget.h"
#include "TotemDQMLite/Core/interface/SingleRootPlot.h"
#include "TotemDQMLite/Core/interface/PlotManager.h"
#include "TotemDQMLite/GUI/interface/ChoosePlotDialog.h"
#include "TotemDQMLite/GUI/interface/MainWindow.h"

#include "FWCore/Utilities/interface/Exception.h"

#include "TFile.h"


#include <QStatusBar>
#include <QMessageBox>

#include <iostream>
using namespace std;

RootCanvasWidget::RootCanvasWidget(QWidget *parent, Qt::WindowFlags flags, bool v) : QRootCanvas(parent) {
    setAcceptDrops(true);
    Clear();
    par = parent;
    flags = flags;
    v = v;

}

void RootCanvasWidget::SetDQMPlot(DQMPlot *monOut) {
    monitorOutput = monOut;
}

void RootCanvasWidget::DeleteDQMPlot() {
    if (monitorOutput)
        delete monitorOutput;
}

/**
 * Draws graph on canvas
 */
void RootCanvasWidget::Refresh() {
    try {
        GetCanvas()->cd();
        GetCanvas()->Clear();
        monitorOutput->Draw();
        GetCanvas()->Update();
    }
    catch (...) {
        edm::LogError("RootCanvasWidget") << "EXCEPTION: RootCanvasWidget while Refreshing";
        throw;
    }
}

/**
 * Clears the canvas
 */
void RootCanvasWidget::Clear() {
    try {
        monitorOutput = &singleRootOutputEmpty;
        graphIdent = "";
        GetCanvas()->cd();
        GetCanvas()->SetFillColor(0);
        monitorOutput->Draw();
        GetCanvas()->Update();
    }
    catch (...) {
        edm::LogError("RootCanvasWidget") << "EXCEPTION: RootCanvasWidget while Clearing";
        throw;
    }
}

/**
 * Reloads the canvas
 *
 * RootCanvasWidget class contains not only DQMPlot, but also string identification for this DQMPlot related to PlotManager.
 *
 * So, whenever DQMPlot pointer is somehow destroyed (e.g. after loading new configuration file or just new data files), the DQM Plot can be reload from the string identification.
 */
void RootCanvasWidget::Reload() {
    try {
        DQMPlot *mo = 0;
        mo = PlotManager::Get(graphIdent);
        if (mo)
            SetDQMPlot(mo);
    }
    catch (...) {
        edm::LogError("RootCanvasWidget") << "EXCEPTION: RootCanvasWidget while Reloading";
        throw;
    }
}

QWidget *RootCanvasWidget::parent() {
    return par;
}

MainWindow *RootCanvasWidget::GetMainWindow() {
    return (MainWindow*)parent()->parent()->parent()->parent();
}

/********************************************************************************
 * SIGNALS
 * *****************************************************************************/

/// reaction for clicking canvas
/**
 * Adding reactions for clicking on canvas
 *
 * Reactions:
 * - click both (right and left) bittons or click middle button (OpenInNewWindow() SIGNAL)
 * - press only left button (while 'ctrl' key is pressed) - drag & drop (switching the root canvases)
 * - double click while 'Shift' key is pressed (OpenInNewWindow() SIGNAL)
 * - double click (ChooseDialog() SIGNAL)
 */
bool RootCanvasWidget::event(QEvent *e)
{
    if (e->type() == e->MouseButtonPress) {
        QMouseEvent *me = (QMouseEvent *) e;

        // ctrl + left click
        /*
        if (me->state() == Qt::ControlButton && me->buttons() == Qt::LeftButton && me->buttons() != Qt::RightButton) {
          emit ChooseDialog(me);
          return false;  // this is important to stop propagation of the event
        }
        */

        // click both (right and left) bittons or click middle button
        if ((me->buttons() == (Qt::LeftButton | Qt::RightButton)) || (me->buttons() == Qt::MidButton) || (((me->modifiers() == Qt::AltModifier) || (me->modifiers() == Qt::ShiftModifier)) && me->buttons() == Qt::LeftButton && me->buttons() != Qt::RightButton))  {
            emit OpenInNewWindow(monitorOutput, graphIdent);
            return true;
        }

        // press only left button - drag & drop (switching the root canvases)
        if (me->state() == Qt::ControlButton && me->buttons() == Qt::LeftButton && me->buttons() != Qt::RightButton) {
            // drag and drop
            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;
            QString text = QString("switch the canvases");
            QPixmap iconPixmap = QPixmap();
            mimeData->setText(text);
            drag->setMimeData(mimeData);
            drag->setPixmap(iconPixmap);

            drag->exec();

            me->accept();
        }
    }

    // double click
    if (e->type() == QEvent::MouseButtonDblClick) {
        QMouseEvent *me = (QMouseEvent*)e;
        if (me->modifiers() == Qt::ShiftModifier) {
            emit OpenInNewWindow(monitorOutput, graphIdent);
            return true;
        }
        else {
            emit ChooseDialog((QMouseEvent *) e);
            return true;
        }
    }
    else if (e->type() == QEvent::DragEnter) {
        QDragEnterEvent *event = (QDragEnterEvent*)e;
        if (event->mimeData()->hasText() && event->mimeData()->text() == "switch the canvases") {
            event->acceptProposedAction();
            return true;
        }
        else {
            event->ignore();
            return false;
        }
    }
    else if (e->type() == QEvent::DragMove) {
        QDragMoveEvent *event = (QDragMoveEvent*)e;
        if (event->mimeData()->hasText() && event->mimeData()->text() == "switch the canvases") {
            event->acceptProposedAction();
            return true;
        }
        else {
            event->ignore();
            return false;
        }
    }
    else if (e->type() == QEvent::Drop) {
        QDropEvent *event = (QDropEvent*)e;
        if (event->mimeData()->hasText() && event->mimeData()->text() == "switch the canvases") {
            // switching the canvases (monitorOutputs & graphIdent)
            RootCanvasWidget *source = (RootCanvasWidget*)event->source();
            DQMPlot *tempMO = monitorOutput;
            std::string tempGI = graphIdent;
            SetDQMPlot(source->GetDQMPlot());
            SetGraphIdent(source->GraphIdent());
            source->SetDQMPlot(tempMO);
            source->SetGraphIdent(tempGI);
            Refresh();
            source->Refresh();
            //
            event->acceptProposedAction();
            return true;
        }
        else {
            event->ignore();
            return false;
        }

        event->acceptProposedAction();
    }

    // pass the event further
    return QRootCanvas::event(e);
}


/**
 * Selects the plot for canvas
 *
 * Uses ChooseDialog window
 */
void RootCanvasWidget::RunChooseDialog(QMouseEvent *mouseEvent) {
    try {
        DQMPlot **mo;
        std::string *ident;
        mo = new DQMPlot*;
        ident = new std::string();
        int status = GetMainWindow()->ChooseDialog(mo, ident, mouseEvent->globalX() - 200, mouseEvent->globalY() - 250);
        if (status == QDialog::Accepted && *mo) {
            SetDQMPlot(*mo);
            SetGraphIdent(*ident);
            Refresh();
        }

        delete mo;
        delete ident;

    }
    catch (cms::Exception &e) {
        edm::LogError("RootCanvasWidget") << e;
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        Clear();
    }
}
