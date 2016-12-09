/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "TotemDQMLite/GUI/interface/TabWindow.h"
#include "TotemDQMLite/GUI/interface/CanvasGrid.h"
#include "TotemDQMLite/GUI/interface/LayoutMenu.h"
#include "TotemDQMLite/GUI/interface/DockWidget.h"

#include "FWCore/Utilities/interface/Exception.h"

#include <Q3FileDialog>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include <QMessageBox>
#include <QStatusBar>

//#define DEBUG 1

/**
 * Creates Canvas Grid and LayoutMenu
 */
TabWindow::TabWindow(QWidget *parent, Qt::WindowFlags flags) : QWidget(parent, flags), ifLayoutMenu(true) {
  layout = new QVBoxLayout();

  canvasGridContents = new QWidget(this);
  canvasGrid = new CanvasGrid(canvasGridContents);

  layoutMenu = new LayoutMenu(this);
  layoutMenu->setFixedHeight(100);

  layout->addWidget(canvasGridContents);
  layout->addWidget(layoutMenu);

  // col/row  +/- buttons
  connect(layoutMenu->GetAddColButton(), SIGNAL(clicked()), canvasGrid, SLOT(AddCol()));
  connect(layoutMenu->GetDelColButton(), SIGNAL(clicked()), canvasGrid, SLOT(DelCol()));
  connect(layoutMenu->GetAddRowButton(), SIGNAL(clicked()), canvasGrid, SLOT(AddRow()));
  connect(layoutMenu->GetDelRowButton(), SIGNAL(clicked()), canvasGrid, SLOT(DelRow()));
  
  // save / load layout buttons
  connect(layoutMenu->GetSaveLayout(), SIGNAL(clicked()), this, SLOT(SaveLayout()));
  connect(layoutMenu->GetLoadLayout(), SIGNAL(clicked()), this, SLOT(LoadLayout()));

  setLayout(layout);
}

/**
 * Creates CanvasGrid with given plot (zooming feature)
 *
 * @param mo plot to be zoomed
 * @param ident ident of plot related to PlotManager
 */
TabWindow::TabWindow(DQMPlot *mo, std::string ident, QWidget *parent, Qt::WindowFlags flags) : QWidget(parent, flags), ifLayoutMenu(false) {
  layoutMenu = 0;
  QVBoxLayout *layout = new QVBoxLayout();

  canvasGridContents = new QWidget(this);
  canvasGrid = new CanvasGrid(mo, ident, canvasGridContents);

  layout->addWidget(canvasGridContents);

  setLayout(layout);
}


void TabWindow::EventChanged(int eventNr)
{
  if (layoutMenu)
    layoutMenu->EventChanged(eventNr);
}

void TabWindow::RunChanged(int runNr)
{
  if (layoutMenu)
    layoutMenu->RunChanged(runNr);
}

void TabWindow::RunAndEventChanged(int runNr, int eventNr) {
  if (layoutMenu)
    layoutMenu->RunAndEventChanged(runNr, eventNr);
}

void TabWindow::EventLimitChanged(int minEventNr, int maxEventNr) {
  if (layoutMenu)
  layoutMenu->EventLimitChanged(minEventNr, maxEventNr);
}

void TabWindow::RunsChanged()
{
  if (layoutMenu)
    layoutMenu->RunsChanged();
}

MainWindow *TabWindow::GetMainWindow() {
  return (MainWindow*)parent()->parent();
}

DockWidget *TabWindow::GetDockWidget() {
  return (DockWidget*)parent();
}

void TabWindow::Refresh() {
  canvasGrid->RefreshCanvas();
}

void TabWindow::Reload() {
  // spread the ReloadCanvas
  canvasGrid->ReloadCanvas();
}

void TabWindow::Clear() {
  // spread the ClearCanvas
  canvasGrid->ClearCanvas();
}


/**
 * Writes the content of TabWindow to Layout object (xml)
 */
void TabWindow::SaveLayout(QDomDocument& doc, QDomElement &e) {
  if (ifLayoutMenu)
    e.setAttribute("ifLayout", 1);
  e.setAttribute("windowTitle", GetDockWidget()->windowTitle());
  QDomElement canvas = doc.createElement("CanvasGrid");
  canvasGrid->SaveLayout(doc, canvas);
  e.appendChild(canvas);
}

//----------------------------------------------------------------------------------------------------

bool TabWindow::LoadLayout(QDomElement &e)
{
  if (e.attribute("ifLayout", "") == "") {
    layout->removeWidget(layoutMenu);
    delete layoutMenu;
    layoutMenu = 0;
    ifLayoutMenu = false;
  }

  QString temp;
  if ((temp = e.attribute("windowTitle", "")) != "") {
    GetDockWidget()->setWindowTitle(temp);
  }

  QDomNode n = e.firstChild();
    while( !n.isNull() ) {
      QDomElement e = n.toElement();
        if( !e.isNull() ) {
          if( e.tagName() == "CanvasGrid" ) {
            return canvasGrid->LoadLayout(e);
          }
          else {
            return false;
          }
      }
      n = n.nextSibling();
  }
  return true;
}

//----------------------------------------------------------------------------------------------------

/**
 * Reads the content of Layout object (xml)
 */
bool TabWindow::LoadLayout(std::string fileName)
{
  GetMainWindow()->statusBar()->showMessage("Loading layout...");

  QString path(fileName.c_str());
  QDomDocument doc("layout");

  QFile file(path);
  if( !file.open( IO_ReadOnly ) ) {
    QMessageBox::critical(NULL, "A problem with layout", "The layout file `" + path + "' cannot be opened.");
    GetMainWindow()->statusBar()->showMessage("Layout NOT loaded.", 5000);
    return false;
  }

  if( !doc.setContent( &file ) ) {
    QMessageBox::critical(NULL, "A problem with layout", "The layout file `" + path + "' cannot be parsed. Is it a proper .lay file?");
    GetMainWindow()->statusBar()->showMessage("Layout NOT loaded.", 5000);
    file.close();
    return false;
  }
  file.close();

  CanvasGrid::loadLayoutMissingPlots = false;

  QDomElement root = doc.documentElement();
  if( root.tagName() != "layout" ) {
    QMessageBox::critical(NULL, "A problem with layout", "The layout file `" + path + "' has wrong structure. Is it a proper .lay file?");
    GetMainWindow()->statusBar()->showMessage("Layout NOT loaded.", 5000);
    return false;
  }

  QDomNode n = root.firstChild();
  while( !n.isNull() ) {
    QDomElement e = n.toElement();
    if( !e.isNull() ) {
      if ( e.tagName() != "TabWindow" || !LoadLayout(e)) {
        QMessageBox::critical(NULL, "A problem with layout", "The layout file `" + path + "' has wrong structure. Is it a proper .lay file?");
        GetMainWindow()->statusBar()->showMessage("Layout NOT loaded.", 5000);
      }
    }
    n = n.nextSibling();
  }

  if (CanvasGrid::loadLayoutMissingPlots)
    QMessageBox::warning(NULL, "A problem with application layout", "Some plots (see console) could not have been loaded -- they are not available by PlotManager. Does your configuration file let these plots be produced?");

  GetMainWindow()->statusBar()->showMessage("Layout loaded.", 5000);
  return true;
}

//----------------------------------------------------------------------------------------------------

void TabWindow::SaveLayout()
{
  QString path = Q3FileDialog::getSaveFileName(DockWidget::GetDefaultLayoutDirectory().c_str(), 
    "layout (*.lay);;all (*)", this, "save file dialog", "Choose a filename to save layout");
  if (!path.isNull()) {
    // add extension if not given
    if (path.indexOf('.') == -1)
      path += ".lay";

    QDomDocument doc("layout");
    QDomElement root = doc.createElement("layout");
    doc.appendChild(root);
    QDomElement tabWindow = doc.createElement("TabWindow");
    SaveLayout(doc, tabWindow);
    root.appendChild(tabWindow);
    
    QFile file(path);
    if (!file.open( IO_WriteOnly )) {
      QMessageBox::critical(NULL, "A problem with layout", "The layout file `" + path + " cannot be opened for writing.");
      GetMainWindow()->statusBar()->showMessage("Layout not saved", 8000);
      return;
    }

    QTextStream ts( &file );
    ts << doc.toString();

    file.close();
    GetMainWindow()->statusBar()->showMessage("Layout saved", 8000);
  }
  else {
    GetMainWindow()->statusBar()->showMessage("Layout not saved", 8000);
  }
}

//----------------------------------------------------------------------------------------------------

void TabWindow::LoadLayout()
{
  QString path = Q3FileDialog::getOpenFileName(DockWidget::GetDefaultLayoutDirectory().c_str(), 
    "layout (*.lay);;all (*)", this, "save file dialog", "Choose a layout to load");
  if (!path.isNull())
    LoadLayout(path.toUtf8().constData());
//    LoadLayout(path.toStdString());
}

void TabWindow::ClearLayout() {
  layout->removeWidget(canvasGridContents);
  delete canvasGrid;
  delete canvasGridContents;
  canvasGridContents = new QWidget(this);
  canvasGrid = new CanvasGrid(canvasGridContents);
  layout->insertWidget(0, canvasGridContents);
}

/**
 * Creates screenshot of all visible in the current window plots
 */
void TabWindow::Screenshot() {
  canvasGrid->Screenshot();
}
