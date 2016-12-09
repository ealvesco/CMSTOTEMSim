/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "TotemDQMLite/GUI/interface/OpenDialog.h"

#include <QFileDialog>
#include <Q3FileDialog>
#include <QMessageBox>
#include <QSettings>

#include "FWCore/Utilities/interface/Exception.h"

#include <algorithm>

#include <sys/stat.h>

//----------------------------------------------------------------------------------------------------

const unsigned int HIST_CONF_SIZE = 20;
const unsigned int HIST_DATA_SIZE = 20;

//----------------------------------------------------------------------------------------------------

OpenDialog::OpenDialog(std::vector<std::string> *recoFilenames, std::string *confFileName, std::string *layoutFileName,
  QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    recoFilenames(recoFilenames),
    confFileName(confFileName),
    layoutFileName(layoutFileName),
    recoFilesDirectory("")
{
  setObjectName("Open Dialog");
  setMinimumSize(650, 200);

  char *DQM_DATA_DIR_env;
  if ((DQM_DATA_DIR_env = getenv("DQM_DATA_DIR")))
    recoFilesDirectory = DQM_DATA_DIR_env;

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(PrepareRecoFilesGroupBox());
  layout->addWidget(PrepareConfigurationGroupBox());
  layout->addWidget(PrepareLayoutGroupBox());
  layout->insertLayout(-1, PrepareOpenCloseButtonsLayout());
  setLayout(layout);

  LoadHistory();
}

//----------------------------------------------------------------------------------------------------

QGroupBox* OpenDialog::PrepareRecoFilesGroupBox()
{
  QGroupBox *recoFileBox = new QGroupBox("RECO files");
  QHBoxLayout *recoLayout = new QHBoxLayout(recoFileBox);

  recoFiles = new QTextEdit();
  recoLayout->addWidget(recoFiles);

  QVBoxLayout *recoButtonsLayoutWrapper = new QVBoxLayout();
  QVBoxLayout *recoButtonsLayout = new QVBoxLayout();
  recoAdd = new QPushButton("Add", this);
  connect(recoAdd, SIGNAL(clicked()), this, SLOT(AddReco()));
  recoButtonsLayout->addWidget(recoAdd);
  QPushButton *recoClear = new QPushButton("Clear", this);
  connect(recoClear, SIGNAL(clicked()), this, SLOT(ClearRecoFiles()));
  recoButtonsLayout->addWidget(recoClear);
  recoButtonsLayoutWrapper->insertLayout(-1, recoButtonsLayout);
  recoLayout->insertLayout(-1, recoButtonsLayoutWrapper);

  QHBoxLayout *historyNavigationLayout = new QHBoxLayout();
  QPushButton *historyBackwardButton = new QPushButton("<--", this);
  connect(historyBackwardButton, SIGNAL(clicked()), this, SLOT(HistBackward()));
  QPushButton *historyForwardButton = new QPushButton("-->", this);
  connect(historyForwardButton, SIGNAL(clicked()), this, SLOT(HistForward()));
  historyNavigationLayout->addWidget(historyBackwardButton);
  historyNavigationLayout->addWidget(historyForwardButton);

  recoButtonsLayoutWrapper->insertLayout(-1, historyNavigationLayout);
  return recoFileBox;
}

//----------------------------------------------------------------------------------------------------

QGroupBox* OpenDialog::PrepareConfigurationGroupBox()
{
  QGroupBox *confGroupBox = new QGroupBox("Configuration file");
  QHBoxLayout *confLayout = new QHBoxLayout(confGroupBox);
  confFile = new QComboBox(this);
  confFile->setToolTip("Enter path to configuration file (*.py)");
  confFile->setEditable(true);
  confBrowse = new QPushButton("browse", this);
  confBrowse->setFixedWidth(70);
  connect(confBrowse, SIGNAL(clicked()), this, SLOT(BrowseConf()));
  confEdit = new QPushButton("edit", this);
  confEdit->setFixedWidth(70);
  connect(confEdit, SIGNAL(clicked()), this, SLOT(EditConf()));

  confLayout->addWidget(confFile);
  confLayout->addWidget(confBrowse);
  confLayout->addWidget(confEdit);
  confGroupBox->setFixedHeight(70);
  return confGroupBox;
}

//----------------------------------------------------------------------------------------------------

QGroupBox* OpenDialog::PrepareLayoutGroupBox()
{
  QGroupBox *layoutGroupBox = new QGroupBox("Layout file");
  QHBoxLayout *layoutLayout = new QHBoxLayout(layoutGroupBox);
  layoutFile = new QComboBox(this);
  layoutFile->setToolTip("Enter path to layout file (*.lay or *.apl)");
  layoutFile->setEditable(true);
  layoutBrowse = new QPushButton("browse", this);
  layoutBrowse->setFixedWidth(70);
  connect(layoutBrowse, SIGNAL(clicked()), this, SLOT(BrowseLayout()));

  layoutLayout->addWidget(layoutFile);
  layoutLayout->addWidget(layoutBrowse);
  layoutGroupBox->setFixedHeight(70);
  return layoutGroupBox;
}

//----------------------------------------------------------------------------------------------------

QHBoxLayout* OpenDialog::PrepareOpenCloseButtonsLayout()
{
  QHBoxLayout *openCloseLayout = new QHBoxLayout();
  QPushButton *openButton = new QPushButton("Open", this);
  connect(openButton, SIGNAL(clicked()), this, SLOT(ValidateInput()));
  openButton->setFixedWidth(100);
  QPushButton *closeButton = new QPushButton("Close", this);
  connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
  closeButton->setFixedWidth(100);
  openCloseLayout->addWidget(openButton);
  openCloseLayout->addWidget(closeButton);
  return openCloseLayout;
}

//----------------------------------------------------------------------------------------------------

QString OpenDialog::GetConfigFileName() const
{
  QString fn = "TotemDQMLite_open_file_dialog";
  char *monitorIdentity = getenv("MONITOR_IDENTITY");
  if (monitorIdentity)
    fn += QString("_") + QString(monitorIdentity);

  return fn;
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::SaveHistory()
{
  QSettings settings("TOTEM", GetConfigFileName());

  unsigned int counter = 0;

  // reco files
  counter = 1;
  settings.setValue("recoFiles/" + QString::number(0), recoFiles->toPlainText());
  for (QList<QString>::iterator iter = filesList.begin(); iter != filesList.end(); iter++)
  {
    if (*iter != recoFiles->toPlainText() && *iter != "")
      settings.setValue("recoFiles/" + QString::number(counter++), *iter);

    if (counter >= HIST_DATA_SIZE)
      break;
  }
  settings.setValue("histDataSize", counter);
  
  // config file
  counter = 0;
  QString confCurrentText = confFile->currentText();
  settings.setValue("conf/" + QString::number(counter++), confCurrentText);
  for (int i = 0; i < confFile->count(); i++)
  {
    if (confFile->itemText(i) != confCurrentText)
      settings.setValue("conf/" + QString::number(counter++), confFile->itemText(i));

    if (counter >= HIST_CONF_SIZE)
      break;
  }
  settings.setValue("confHistSize", counter);
  
  // layout file
  counter = 0;
  QString layoutCurrentText = layoutFile->currentText();
  settings.setValue("layout/" + QString::number(counter++), layoutCurrentText);
  for (int i = 0; i < layoutFile->count(); i++)
  {
    if (layoutFile->itemText(i) != layoutCurrentText)
      settings.setValue("layout/" + QString::number(counter++), layoutFile->itemText(i));

    if (counter >= HIST_CONF_SIZE)
      break;
  }
  settings.setValue("layoutHistSize", counter);
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::LoadHistory()
{
  QSettings settings("TOTEM", GetConfigFileName());

  // reco files
  dataHistoryPointer = 0;
  dataHistoryMax = settings.value("histDataSize").toInt();
  int counter = 0;
  for (unsigned int i = 0; i < dataHistoryMax; i++)
  {
    QString temp = settings.value("recoFiles/" + QString::number(i)).toString();
    if (temp != "") {
      filesList.push_back(temp);
      counter++;
    }
  }
  dataHistoryMax = counter;
  recoFiles->append(settings.value("recoFiles/0").toString());

  // config file
  int confHistSize = settings.value("confHistSize").toInt();
  for (int i = 0; i < confHistSize; i++)
    confFile->addItem( settings.value("conf/" + QString::number(i)).toString() );

  // layout file
  int layoutHistSize = settings.value("layoutHistSize").toInt();
  for (int i = 0; i < layoutHistSize; i++)
    layoutFile->addItem( settings.value("layout/" + QString::number(i)).toString() );
}

//----------------------------------------------------------------------------------------------------
// SLOTs

void OpenDialog::BrowseConf()
{
  QString s = Q3FileDialog::getOpenFileName(confFile->currentText(), "python (*.py);;all (*)",
    this, "open file dialog", "Choose a configuration file");

  if (!s.isNull())
    confFile->setCurrentText(s);
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::BrowseLayout()
{
  QString s = Q3FileDialog::getOpenFileName(layoutFile->currentText(), "layout files (*.lay *.apl);;all (*)",
    this, "open file dialog", "Choose a layout file");

  if (!s.isNull())
    layoutFile->setCurrentText(s);
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::AddReco()
{
  Q3FileDialog dialog(recoFilesDirectory.c_str(), " all (*)", this, "Choose RECO files");
  dialog.setMode(Q3FileDialog::ExistingFiles);
  dialog.setViewMode(Q3FileDialog::Detail);

  if(dialog.exec() == QDialog::Accepted)
  {
    QStringList list = dialog.selectedFiles();
    QStringList addedRecoFiles = recoFiles->toPlainText().split("\n", QString::SkipEmptyParts);
    for (QStringList::iterator iter = list.begin(); iter != list.end(); iter++)
    {
      if(!addedRecoFiles.contains(*iter))
        recoFiles->append(*iter);
    }
  }
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::EditConf()
{
  char *editor;
  bool ifFree;
  ifFree = false;
  if (!(editor = getenv("DQM_EDITOR")))
  {
    editor = (char*)malloc(20*sizeof(char));
    strcpy(editor, "kate");
    ifFree = true;
  }

  if (confFile->currentText() == "" || confFile->currentText().isEmpty())
    return;

  char buf[200];
  sprintf(buf, "%s %s", editor, confFile->currentText().toUtf8().constData());
  if (ifFree) 
    free(editor);
  system(buf);
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::HistBackward()
{
  if (dataHistoryPointer < dataHistoryMax - 1)
  {
    recoFiles->clear();
    recoFiles->append(filesList[++dataHistoryPointer]);
  }
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::HistForward()
{
  if (dataHistoryPointer > 0)
  {
    recoFiles->clear();
    recoFiles->append(filesList[--dataHistoryPointer]);
  }
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::ValidateInput()
{
  try {
    // check RECO files
    QStringList list = recoFiles->toPlainText().split("\n", QString::SkipEmptyParts);
    if (list.isEmpty())
    {
      QMessageBox messageBox;
      messageBox.setText("You have to choose at least one RECO file.");
      messageBox.setIcon(QMessageBox::Critical);
      messageBox.exec();
      return;
    }

    for (QStringList::iterator iter = list.begin(); iter != list.end(); iter++)
      recoFilenames->push_back(iter->toUtf8().constData());

    // check config file
    *confFileName = confFile->currentText().toUtf8().constData();
    if (*confFileName != "" && !QFile::exists(confFileName->c_str()))
    {
      QMessageBox msgBox;
      char buf[300];
      sprintf(buf, "Configuration file \"%s\" does not exist.", confFileName->c_str());
      msgBox.setText(buf);
      msgBox.setIcon(QMessageBox::Critical);
      msgBox.exec();
      return;
    }

    // check layout file
    *layoutFileName = layoutFile->currentText().toUtf8().constData();
    if (*layoutFileName != "" && !QFile::exists(layoutFileName->c_str()))
    {
      QMessageBox msgBox;
      char buf[300];
      sprintf(buf, "Layout file \"%s\" does not exist.", layoutFileName->c_str());
      msgBox.setText(buf);
      msgBox.setIcon(QMessageBox::Critical);
      msgBox.exec();
      return;
    }

    SaveHistory();
    accept();
  }

  catch (cms::Exception &e)
  {
    edm::LogError("OpenDialog") << e;
    QMessageBox msgBox;
    msgBox.setText(e.what());
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
  }
}

//----------------------------------------------------------------------------------------------------

void OpenDialog::ClearRecoFiles()
{
  recoFiles->clear();
}
