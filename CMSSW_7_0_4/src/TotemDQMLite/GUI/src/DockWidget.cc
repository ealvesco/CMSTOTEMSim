/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/


#include "TotemDQMLite/GUI/interface/DockWidget.h"
#include "TotemDQMLite/GUI/interface/TabWindow.h"
#include "TotemDQMLite/GUI/interface/MainWindow.h"

#include <QGridLayout>
#include <QRect>
#include <QWheelEvent>
#include <QInputDialog>

using namespace std;


/**
 * Creates general DockWidget and sets its name
 */
DockWidget::DockWidget(QWidget *parent, Qt::WindowFlags flags, std::string windowName) : QDockWidget(parent, flags)
{
  toBeWindow = false;
  applicationLayoutFloating = false;
  setObjectName("canvas widget");
  setWindowTitle(windowName.c_str());

  firstRefreshAfterShow = true;
  tabWindow = new TabWindow(this);
  setWidget(tabWindow);
}

//----------------------------------------------------------------------------------------------------

/**
 * Creates DockWidget specially for zooming feature
 */
DockWidget::DockWidget(DQMPlot *mo, std::string ident, QWidget *parent, Qt::WindowFlags flags, std::string windowName)
  : QDockWidget(parent, flags)
{
  applicationLayoutFloating = false;
  toBeWindow = false;
  setObjectName("canvas widget");
  setWindowTitle(windowName.c_str());

  firstRefreshAfterShow = true;
  tabWindow = new TabWindow(mo, ident, this);
  setWidget(tabWindow);
}

/**
 * Is responsible for all features that differs DockWidget from QDockWidget (see class description)
 */
bool DockWidget::event(QEvent *e)
{
  if (e->type() == QEvent::UpdateRequest) {
    if (applicationLayoutFloating) {
      setWindowFlags(Qt::Window);
      show();
      applicationLayoutFloating = false;
      toBeWindow = false;
    }
  }
  if (e->type() == QEvent::MouseButtonRelease) {
    if (toBeWindow) {
      setWindowFlags(Qt::Window);
      show();
      toBeWindow = false;
    }
  }
  else if (e->type() == e->Close) {
    ((MainWindow*)parent())->removeDockWidget(this);
    ((MainWindow*)parent())->RemoveDockWidget(this);
    delete this;
    return true; 
  }
/*
  else if (e->type() == e->Wheel) {
    QWheelEvent *event = (QWheelEvent*)e;
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;
    if (event->orientation() == Qt::Vertical) {
      QWidget *objectToResize;
      if (isFloating())
        objectToResize = this;
      else
        objectToResize = (QWidget*)parent();
      double ratio = objectToResize->width() / objectToResize->height();
      int widthAdd = (int)((ratio * 10) * numSteps);
      int heightAdd = (int)(((1.0/ratio) * 10) * numSteps);
        objectToResize->resize(objectToResize->width()+widthAdd, objectToResize->height()+heightAdd);
    }
    event->accept();
    return true;
  }
*/
  //
  else if (e->type() == e->Show) {
    if (firstRefreshAfterShow) {
      firstRefreshAfterShow = false;
      Refresh();
    }
  }
  else if (e->type() == e->MouseButtonDblClick) {
    bool ok;
    QString text = QInputDialog::getText(this, tr("Window Name"),
                                          tr("Write new Window Name:"), QLineEdit::Normal,
                                          windowTitle(), &ok);
    if (ok && !text.isEmpty())
      setWindowTitle(text);
    return false;
  }
  //
  return QDockWidget::event(e);
}


// pass on the eventChanged information to TabWindow
void DockWidget::EventChanged(int eventNr) {
  if (tabWindow)
    tabWindow->EventChanged(eventNr);
  Refresh();
}

void DockWidget::RunAndEventChanged(int runNr, int eventNr) {
  if (tabWindow)
    tabWindow->RunAndEventChanged(runNr, eventNr);
  Refresh();
}

void DockWidget::EventLimitChanged(int minEventNr, int maxEventNr) {
  if (tabWindow)
    tabWindow->EventLimitChanged(minEventNr, maxEventNr);
}

void DockWidget::RunsChanged()
{
  if (tabWindow)
    tabWindow->RunsChanged();
}

void DockWidget::RunChanged(int runNr)
{
  if (tabWindow) {
    tabWindow->RunChanged(runNr);
    Refresh();
  }
}

void DockWidget::Refresh() {
  if (tabWindow)
    tabWindow->Refresh();
}

void DockWidget::ReloadCanvas() {
  if (tabWindow)
    tabWindow->Reload();
}

void DockWidget::ClearCanvas() {
  if (tabWindow)
    tabWindow->Clear();
}

 /**
 * Writes the content of DockWidget to Layout object (xml)
 */
void DockWidget::SaveLayout(QDomDocument& doc, QDomElement &e) {
  const QRect &rec = geometry();
  e.setAttribute("x", rec.x());
  e.setAttribute("y", rec.y());
  e.setAttribute("height", rec.height());
  e.setAttribute("width", rec.width());
  e.setAttribute("isFloating", isFloating());
  e.setAttribute("windowTitle", windowTitle());
  QDomElement canvas;
  if (tabWindow)
    canvas = doc.createElement("TabWindow");
  else 
    canvas = doc.createElement("RootCanvasWidget");
  tabWindow->SaveLayout(doc, canvas);
  e.appendChild(canvas);
}

/**
* Reads the content of the Layout object (xml)
*/
bool DockWidget::LoadLayout(QDomElement &e)
{
  QString temp;
  QRect rec;
  if ((temp = e.attribute("isFloating", "")) != "") {
    if (temp == "0")
      setFloating(false);
    else if (temp == "1") {
      setFloating(true);
      applicationLayoutFloating = true;
    }
  }
  if ((temp = e.attribute("windowTitle", "")) != "") {
    setWindowTitle(temp);
  }
  if ((temp = e.attribute("x", "")) != "")
    rec.setX(temp.toUInt());
  else 
    return false;
  if ((temp = e.attribute("y", "")) != "")
    rec.setY(temp.toUInt());
  else 
    return false;
  if ((temp = e.attribute("height", "")) != "")
    rec.setHeight(temp.toUInt());
  else 
    return false;
  if ((temp = e.attribute("width", "")) != "")
    rec.setWidth(temp.toUInt());
  else 
    return false;
  setGeometry(rec);

  QDomNode n = e.firstChild();
    while( !n.isNull() ) {
      QDomElement e = n.toElement();
        if( !e.isNull() ) {
          if( e.tagName() == "TabWindow" ) {
            return tabWindow->LoadLayout(e);
          }
          else {
            return false;
          }
      }
      n = n.nextSibling();
  }
  return false;
}

/**
* Reads the content of the Layout object (xml)
*/
bool DockWidget::LoadLayout(std::string fileName)
{
  return tabWindow->LoadLayout(fileName);
}

/**
 * Responsible for changing the DockWidget to real Window after detaching it
 */
void DockWidget::ChangeToWindow(bool t)
{
  if (t != isFloating())    // some mistake
    return;

  if (t)
    toBeWindow = true;
}

//----------------------------------------------------------------------------------------------------

string DockWidget::GetDefaultLayoutDirectory()
{
  char *val = getenv("DQM_LAYOUT_DIR");
  if (val)
    return val;
 
  val = getenv("CMSSW_BASE");
  if (val)
    return string(val) + "/src/TotemDQMLite/Modules/layouts/";

  return ".";
}
