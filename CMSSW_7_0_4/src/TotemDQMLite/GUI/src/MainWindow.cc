/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/MainWindow.h"
#include "TotemDQMLite/GUI/interface/OpenDialog.h"
#include "TotemDQMLite/GUI/interface/ProcessManager.h"
#include "TotemDQMLite/GUI/interface/DockWidget.h"
#include "TotemDQMLite/GUI/interface/RootCanvasWidget.h"
#include "TotemDQMLite/Core/interface/DQMExceptions.h"
#include "TotemDQMLite/GUI/interface/CanvasGrid.h"
#include "TotemDQMLite/GUI/interface/ChoosePlotDialog.h"

#include "FWCore/Utilities/interface/Exception.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTimer>
#include <qdebug.h>
#include <Q3FileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QDesktopWidget>

#include "TROOT.h"
#include "TApplication.h"
#include "TCanvas.h"

#include <vector>

using namespace std;

//#define DEBUG 1

//----------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), chooseDialog(NULL)
{
#ifdef DEBUG
  cout << ">> MainWindow::MainWindow" << endl;
#endif

  setObjectName("MainWindow");
  resize(800, 600);

  // create shortcuts
  QShortcut *shortcutPlus = new QShortcut(QKeySequence("+"), this);
  connect(shortcutPlus, SIGNAL(activated()), this, SLOT(EventNumberInc()));
  QShortcut *shortcutMinus = new QShortcut(QKeySequence("-"), this);
  connect(shortcutMinus, SIGNAL(activated()), this, SLOT(EventNumberDec()));

  QMenu *menu = menuBar()->addMenu(tr("&File"));
  menu->addSeparator();
  menuFileOpenAction = menu->addAction(tr("&Open"), this, SLOT(OpenSource()));
  menuActions.push_back(menu->addAction(tr("&Close"), this, SLOT(CloseSource())));
  menu->addAction(tr("&Quit"), this, SLOT(close()));

  menu = menuBar()->addMenu(tr("&View"));
  menuActions.push_back(menu->addAction(tr("&New tab"), this, SLOT(AddTab())));
  menuActions.push_back(menu->addAction(tr("New &tab from..."), this, SLOT(AddTabFrom())));
  menuActions.push_back(menu->addAction(tr("New window"), this, SLOT(AddWindow())));
  menuActions.push_back(menu->addAction(tr("New &window from..."), this, SLOT(AddWindowFrom())));

  menu = menuBar()->addMenu(tr("&Application Layout"));
  menuActions.push_back(menu->addAction(tr("&Save to..."), this, SLOT(SaveLayout())));
  menuActions.push_back(menu->addAction(tr("&Load from..."), this, SLOT(LoadLayout())));
  menuActions.push_back(menu->addAction(tr("&Clear"), this, SLOT(ClearLayout())));

  // disable/enable actions
  for (auto a : menuActions)
    a->setDisabled(true);
  menuFileOpenAction->setEnabled(true);
}

//----------------------------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
}

//----------------------------------------------------------------------------------------------------

void MainWindow::InsertDockWidget(DockWidget *dw)
{
  dockWidgets.push_back(dw);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::RemoveDockWidget(DockWidget *dw)
{
  for (std::vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
  {
    if (*iter == dw)
    {
      iter = dockWidgets.erase(iter);
      // TODO delete iter?
      break;
    }
  }
}

//----------------------------------------------------------------------------------------------------

int MainWindow::ChooseDialog(DQMPlot **mo, std::string *ident, int x, int y, int x_size, int y_size)
{
  chooseDialog->move(x, y);
  if (x_size != 0 && y_size != 0)
    chooseDialog->resize(x_size, y_size);
  chooseDialog->SetDQMPlotIdent(mo, ident);
  return chooseDialog->exec();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddTab()
{
  AddDockWidget(true);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddTabFrom()
{
  AddDockWidgetFrom(true);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddWindow()
{
  AddDockWidget(false);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddWindowFrom()
{
  AddDockWidgetFrom(false);
}

//----------------------------------------------------------------------------------------------------

DockWidget *MainWindow::AddDockWidget(bool tabbed)
{
#ifdef DEBUG
  cout << ">> MainWindow::AddDockWidget(" << tabbed << ")" << endl;
#endif

  DockWidget *dw = NewDockWidget();

  if (tabbed)
  {
    for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    {
      if ((*iter)->isFloating() == false)
      {
        tabifyDockWidget(*iter, dw);
        break;
      }
    }
  } else {
    dw->resize(640, 480);
    dw->setFloating(true);
    dw->setWindowFlags(Qt::Window);
    dw->show();
    dw->Refresh();
  }

  dockWidgets.push_back(dw);
  return dw;
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddDockWidgetFrom(bool tabbed)
{
  QString path = Q3FileDialog::getOpenFileName(DockWidget::GetDefaultLayoutDirectory().c_str(),
    "layout (*.lay);;all (*)", this, "open file dialog", "Choose a layout to load");

  if (!path.isNull())
    AddDockWidgetFrom(path.toUtf8().constData(), tabbed);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::AddDockWidgetFrom(std::string fileName, bool tabbed)
{
#ifdef DEBUG
  cout << ">> MainWindow::NewDockWidgetFrom(" << fileName << ", " << tabbed << ")" << endl;
#endif

  QString path = fileName.c_str();
  DockWidget *dw = AddDockWidget(tabbed);

  if (!dw->LoadLayout(path.toUtf8().constData()))
    removeDockWidget(dw);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::OpenCanvasInNewWindow(DQMPlot *mo, std::string ident)
{
  DockWidget *dw = new DockWidget(mo, ident, this, Qt::Widget);
  dockWidgets.push_back(dw);
  addDockWidget(Qt::TopDockWidgetArea, dw);
  dw->setFloating(true);
  dw->resize(geometry().width(), geometry().height());
  dw->showFullScreen();
  dw->move(0,0);
  dw->Refresh();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::RefreshCanvas()
{
  statusBar()->showMessage("Refreshing canvases...");
  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->Refresh();
  statusBar()->showMessage("Canvases refreshed.", 5000);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::Refresh()
{
  RefreshCanvas();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::ReloadCanvas()
{
  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->ReloadCanvas();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::ClearCanvas()
{
  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->ClearCanvas();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::EventNrChanged(int n)
{
#ifdef DEBUG
  cout << ">> MainWindow::EventNrChanged" << endl;
#endif

  try
  {
    if (n <= (int) maxEventNr && n >= (int) minEventNr) {
      if (eventNr != (unsigned int) n) {

        // process the event
        statusBar()->showMessage("Processing event...");
        bool result = ProcessManager::GetInstance().RunSingleEventProcessing(runNr, n);
        if (!result)
        {
          string info = "Event " + to_string(n) + " not available.";
          statusBar()->showMessage(info.c_str(), 5000);
        } else {
          statusBar()->showMessage("Event processed.", 5000);
          eventNr = n;
        }

        // spread the eventChanged
        for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
            (*iter)->EventChanged(eventNr);
      }
    }
  }

  catch (cms::Exception &e)
  {
    HandleCmsException("MainWindow::EventNrChanged", e);
  }
}

//----------------------------------------------------------------------------------------------------

void MainWindow::RunNumberChanged(int newRunNr)
{
#ifdef DEBUG
  cout << ">> MainWindow::RunNumberChanged" << endl;
#endif

    const map<unsigned int, ProcessManager::RunInfo>& runInfo = ProcessManager::GetInstance().GetRunInfo();
    if (runInfo.find(newRunNr) == runInfo.end())
      return;

    runNr = newRunNr;

    // process the event
    statusBar()->showMessage("Processing event...");
    ProcessManager::GetInstance().RunSingleEventProcessing(runNr, eventNr);
    statusBar()->showMessage("Event processed.", 5000);
    EventLimitChanged();

    // spread the eventChanged
    for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
        (*iter)->RunChanged(newRunNr);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::RunAndEventNumbersChanged(unsigned int newRunNr, unsigned int newEventNr)
{
  if (newRunNr == runNr && newEventNr == eventNr)
    return;

  runNr = newRunNr;
  eventNr = newEventNr;

  // process the event
  statusBar()->showMessage("Processing event...");
  ProcessManager::GetInstance().RunSingleEventProcessing(runNr, eventNr);
  statusBar()->showMessage("Event processed.", 5000);
  EventLimitChanged();

  // spread the RunAndEventChanged
  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->RunAndEventChanged(runNr, eventNr);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::EventLimitChanged()
{
#ifdef DEBUG
  cout << ">> MainWindow::EventLimitChanged" << endl;
  cout << "\trunInfo.size() = " << ProcessManager::GetInstance().GetRunInfo().size() << endl;
#endif

  const map<unsigned int, ProcessManager::RunInfo>& runInfo = ProcessManager::GetInstance().GetRunInfo();
  minEventNr = runInfo.at(runNr).minEventNr;
  maxEventNr = runInfo.at(runNr).maxEventNr;

#ifdef DEBUG
  cout << "\tlocal runInfo @" << &runInfo << endl;
  cout << "\tevent limit = [" << minEventNr << ", " << maxEventNr << "]" << endl;
#endif

  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->EventLimitChanged(minEventNr, maxEventNr);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::RunsChanged()
{
#ifdef DEBUG
  cout << ">> MainWindow::RunsChanged" << endl;
#endif

  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    (*iter)->RunsChanged();
}

//----------------------------------------------------------------------------------------------------

bool MainWindow::OpenSource()
{
#ifdef DEBUG
  cout << ">> MainWindow::OpenSource()" << endl;
#endif

  // run dialog
  std::vector<std::string> *recoFileNames = new std::vector<std::string>();
  std::string *confFileName = new std::string();
  std::string *layoutFileName = new std::string();
  OpenDialog *dialog = new OpenDialog(recoFileNames, confFileName, layoutFileName, this);
  int status = dialog->exec();

  bool anythingOpened = false;

  if (status == QDialog::Accepted)
    anythingOpened = OpenSource(*recoFileNames, *confFileName, *layoutFileName);

  // release memory;
  delete dialog;
  delete recoFileNames;
  delete confFileName;

  return anythingOpened;
}

//----------------------------------------------------------------------------------------------------

bool MainWindow::OpenSource(const vector<string> &recoFileNames, const string &confFileName, const string &layoutFileName)
{
#ifdef DEBUG
  cout << ">> MainWindow::OpenSource(recoFileNames, confFileName)" << endl;
#endif

  ProcessManager& processManager = ProcessManager::GetInstance();

  // initialize modules
  statusBar()->showMessage("Initializing modules...");
  int moduleInitResult = processManager.InitializeModules(confFileName);

  if (moduleInitResult != 0)
  {
    statusBar()->showMessage("Module initialization failed...", 5000);
    QMessageBox::critical(NULL, "Error", "Module initialization failed. Most likely there is a problem with the config file."
      "<br>See console output for details.");

    processManager.ReleaseModules();

    return false;
  }

  // open input files
  statusBar()->showMessage("Opening input files...");
  int loadInputFileResult = processManager.LoadInputFiles(recoFileNames);

  if (loadInputFileResult != 0)
  {
    statusBar()->showMessage("File opening failed...", 5000);
    QMessageBox::critical(NULL, "Error", "File opening failed. <br>See console output for details.");

    processManager.ReleaseModules();
    processManager.CloseInputFiles();

    return false;
  }
  
  // start cumulative processing
  statusBar()->showMessage("Starting cumulative processing...");
  processManager.RunCumulativeProcessing();
  statusBar()->showMessage("Cumulative processing done.", 5000);

  // update event ranges
  const map<unsigned int, ProcessManager::RunInfo>& runInfo = ProcessManager::GetInstance().GetRunInfo();
  pair<unsigned int, ProcessManager::RunInfo> firstPair = *(runInfo.begin());
  runNr = firstPair.first;
  minEventNr = firstPair.second.minEventNr;
  maxEventNr = firstPair.second.maxEventNr;
  eventNr = firstPair.second.minEventNr;

  RunsChanged();
  EventLimitChanged();
  EventNrChanged(eventNr);

  ReloadCanvas();
  RefreshCanvas();

  // recreate chooseDialog (with uptodate data)
  chooseDialog = new ChoosePlotDialog(this);

  // enable/disable menu actions
  for (auto a : menuActions)
    a->setEnabled(true);
  menuFileOpenAction->setDisabled(true);

  // load layout
  
  if (!layoutFileName.empty())
  {
    if (layoutFileName.find(".apl") != string::npos)
      LoadLayout(layoutFileName);
    else
      AddDockWidgetFrom(layoutFileName, true);
  } else {
    AddDockWidget(true);
  }

  return true;
}

//----------------------------------------------------------------------------------------------------

void MainWindow::CloseSource()
{
#ifdef DEBUG
  cout << ">> MainWindow::CloseRecoFile" << endl;
#endif

  // release chooseDialog
  delete chooseDialog;
  
  // release all plots
  PlotManager::Clear();

  // release ProcessManager components
  ProcessManager& processManager = ProcessManager::GetInstance();
  processManager.ReleaseModules();
  processManager.CloseInputFiles();

  // close layout
  ClearLayout();

  // disable/enable menu entries
  for (auto a : menuActions)
    a->setDisabled(true);
  menuFileOpenAction->setEnabled(true);

  statusBar()->showMessage(tr("Files closed."), 5000);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::SaveLayout(QDomDocument& doc, QDomElement &e)
{
  const QRect &rec = geometry();
  e.setAttribute("x", rec.x());
  e.setAttribute("y", rec.y());
  e.setAttribute("height", rec.height());
  e.setAttribute("width", rec.width());
  e.setAttribute("ifFullScreen", isFullScreen());
  QDesktopWidget qDesktopWidget;
  e.setAttribute("screenNr", qDesktopWidget.screenNumber(this));

  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
  {
    QDomElement dock = doc.createElement("DockWidget");
    (*iter)->SaveLayout(doc, dock);
    dock.setAttribute("dockArea", dockWidgetArea(*iter));
    e.appendChild(dock);
  }
}

//----------------------------------------------------------------------------------------------------

bool MainWindow::LoadLayout(QDomElement &e)
{
  QString temp;
  QRect rec;
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
  if ((temp = e.attribute("ifFullScreen", "")) != "") {
    if (temp == "1")
      showFullScreen();
  }
  if ((temp = e.attribute("screenNr", "")) != "")
  {
    /*
     * not implemented: changing screen to screenNr
     * the same should be done for each dockwidget while saving/loading layout
     */
  }

  // first remove old tabs
  for (vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++)
    removeDockWidget(*iter);

  vector<DockWidget*> newDockWidgets;
  QDomNode n = e.firstChild();
    while( !n.isNull() ) {
      QDomElement e = n.toElement();
        if( !e.isNull() ) {
          if( e.tagName() == "DockWidget" ) {
            DockWidget *dw = NewDockWidget();
            if (newDockWidgets.size() > 0) {
              for (std::vector<DockWidget*>::iterator iter = newDockWidgets.begin(); iter != newDockWidgets.end(); iter++)
                if ((*iter)->isFloating() == false) {
                  tabifyDockWidget(*iter, dw);
                  break;
                }
            }
            newDockWidgets.push_back(dw);
            if (!dw->LoadLayout(e))
              return false;
          } else {
            return false;
          }
      }
      n = n.nextSibling();
  }
  dockWidgets = newDockWidgets;

  return true;
}

//----------------------------------------------------------------------------------------------------

void MainWindow::LoadLayout(std::string fileName)
{
  statusBar()->showMessage("Loading application layout...");

  QString path = fileName.c_str();
  QFile file(path);
  if( !file.open( IO_ReadOnly ) ) {
    QMessageBox::critical(NULL, "A problem with application layout", "The layout file `" + path + "' cannot be opened.");
    statusBar()->showMessage("Application layout NOT loaded.", 5000);
    return;
  }

  QDomDocument doc("layout");
  if( !doc.setContent( &file ) ) {
    QMessageBox::critical(NULL, "A problem with application layout", "The layout file `" + path + "' cannot be parsed. Is it a proper .apl file?");
    statusBar()->showMessage("Application layout NOT loaded.", 5000);
    file.close();
    return;
  }
  file.close();

  CanvasGrid::loadLayoutMissingPlots = false;

  QDomElement root = doc.documentElement();
  if( root.tagName() != "layout" ) {
    QMessageBox::critical(NULL, "A problem with application layout", "The layout file `" + path + "' has wrong structure. Is it a proper .apl file?");
    statusBar()->showMessage("Application layout NOT loaded.", 5000);
    return;
  }

  QDomNode n = root.firstChild();
  while( !n.isNull() ) {
    QDomElement e = n.toElement();
    if( !e.isNull() ) {
      if (e.tagName() != "MainWindow" || !LoadLayout(e)) {
        QMessageBox::critical(NULL, "A problem with application layout", "The layout file `" + path + "' has wrong structure. Is it a proper .apl file?");
        statusBar()->showMessage("Application layout NOT loaded.", 5000);
      }
    }
    n = n.nextSibling();
  }

  if (CanvasGrid::loadLayoutMissingPlots)
    QMessageBox::warning(NULL, "A problem with application layout", "Some plots (see console) could not have been loaded -- they are not available by PlotManager. Does your configuration file let these plots be produced?");

  statusBar()->showMessage("Application layout loaded.", 5000);
}

//----------------------------------------------------------------------------------------------------

void MainWindow::SaveLayout()
{
  try {
    QString path = Q3FileDialog::getSaveFileName(DockWidget::GetDefaultLayoutDirectory().c_str(),
      "application layout (*.apl);;all (*)", this, "save file dialog", "Choose a filename to save layout");

    if (!path.isNull())
    {
      // add extension if not given
      if (path.indexOf('.') == -1)
        path += ".apl";

      QDomDocument doc("layout");
      QDomElement root = doc.createElement("layout");
      doc.appendChild(root);
      QDomElement tabWindow = doc.createElement("MainWindow");
      SaveLayout(doc, tabWindow);
      root.appendChild(tabWindow);

      QFile file(path);
      if (!file.open( IO_WriteOnly )) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Problem in TotemDQM");
        msgBox.setText("Uknown Error. The file cannot be saved.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        statusBar()->showMessage("Layout not saved", 8000);

        return;
      }

      QTextStream ts( &file );
      ts << doc.toString();

      file.close();
      statusBar()->showMessage("Layout saved", 8000);
    }
    else {
      statusBar()->showMessage("Layout not saved", 8000);
    }
  }
  catch (cms::Exception &e) {
    HandleCmsException("MainWindow::SaveLayout", e);
  }
}

//----------------------------------------------------------------------------------------------------

void MainWindow::LoadLayout()
{
  try {
    QString path = Q3FileDialog::getOpenFileName(DockWidget::GetDefaultLayoutDirectory().c_str(),
      "application layout (*.apl);;all (*)", this, "save file dialog", "Choose a layout to load");
    if (!path.isNull()) {
      LoadLayout(path.toUtf8().constData());
    }
  }
  catch (cms::Exception &e) {
    HandleCmsException("MainWindow::LoadLayout", e);
    ClearLayout();
  }
}

//----------------------------------------------------------------------------------------------------

void MainWindow::ClearLayout()
{
#ifdef DEBUG
  cout << ">> MainWindow::ClearLayout" << endl;
#endif

  for (std::vector<DockWidget*>::iterator iter = dockWidgets.begin(); iter != dockWidgets.end(); iter++) {
    removeDockWidget(*iter);
    delete *iter;
  }
  dockWidgets.clear();
}

//----------------------------------------------------------------------------------------------------

void MainWindow::SaveAs()
{
  try {
    char fileName[200];
    int i = 0;
    sprintf(fileName, "output_run_%d_event_%d_%d.root", runNr, eventNr, i);
    while (QFile::exists(fileName)) {
      i++;
      sprintf(fileName, "output_run_%d_event_%d_%d.root", runNr, eventNr, i);
    }
    QString name = Q3FileDialog::getSaveFileName(fileName, "ROOT file (*.root);; all (*)", this, "save file dialog", "Choose ROOT file to save plots");

    if (!name.isNull()) {
      statusBar()->showMessage("Saving ROOT file...");
      PlotManager::SaveAs(name.toUtf8().constData());
      statusBar()->showMessage("ROOT file saved.", 5000);
    }
  }
  catch (cms::Exception &e) {
    statusBar()->showMessage("ROOT file NOT saved.", 5000);
    HandleCmsException("MainWindow::SaveAs", e);
  }
}

//----------------------------------------------------------------------------------------------------

DockWidget *MainWindow::NewDockWidget()
{
#ifdef DEBUG
  cout << ">> MainWindow::NewDockWidget" << endl;
#endif

    try {
      DockWidget *dw;
      dw = new DockWidget(this, Qt::Window);
      connect(dw, SIGNAL(topLevelChanged(bool)), dw, SLOT(ChangeToWindow(bool)));
      dw->RunsChanged();
      dw->RunChanged(runNr);
      dw->EventLimitChanged(minEventNr, maxEventNr);
      dw->EventChanged(eventNr);
      dw->setWindowFlags(Qt::Widget);
      addDockWidget(Qt::TopDockWidgetArea, dw);
      return dw;
    }
    catch (cms::Exception &e) {
      HandleCmsException("MainWindow::NewDockWidget", e);
    }
  return NULL;
}

//----------------------------------------------------------------------------------------------------

void MainWindow::HandleCmsException(const char *where, const cms::Exception &e)
{
  QMessageBox::critical(this, "A problem in TotemDQM", ParseCmsException(where, e));
}

//----------------------------------------------------------------------------------------------------

QString MainWindow::ParseCmsException(const char *where, const cms::Exception &e)
{
  QString m("A cms::Exception caught in <i>");
  m += where;
  m += "</i><hr><nobr>";

  QRegExp beg("---- (.*) BEGIN");
  QRegExp end("---- (.*) END");

  QString prefix;

  QStringList lines(QString(e.what()).split('\n', QString::SkipEmptyParts));
  for (signed int i = 0; i < lines.size(); i++) {
    if (beg.indexIn(lines.at(i)) >= 0) {
      m += prefix + "<b>" + beg.capturedTexts()[1] + "</b><br>";
      prefix += "&nbsp;&nbsp;&nbsp;&nbsp;";
      continue;
    }

    if (end.indexIn(lines.at(i)) >= 0) {
      prefix.chop(24);
      continue;
    }

    m += prefix + lines.at(i) + "<br>";
  }

  m += "</nobr>";
  return m;
}
