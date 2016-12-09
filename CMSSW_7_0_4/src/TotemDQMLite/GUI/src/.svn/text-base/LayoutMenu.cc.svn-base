/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/LayoutMenu.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QStandardItemModel>

#include <string>
#include <iostream>

//#define DEBUG 1

using namespace std;

/**
 * Creates all the Menu structure with layoutBox, eventBox and viewBox
 */
LayoutMenu::LayoutMenu(QWidget *parent, Qt::WindowFlags flags) : 
  QWidget(parent, flags),
  runEventNavigationBox(NULL)
{
#ifdef DEBUG
  cout << ">> LayoutMenu::LayoutMenu, this = " << this << endl;
#endif

  // the layout containing all 3 manipulation boxes
  QHBoxLayout *layout = new QHBoxLayout();

  runEventNavigationBox = new RunEventNavigationBox("Event", GetMainWindow(), this);
  layout->addWidget(runEventNavigationBox);


  // ----- View box
  QGroupBox *viewBox = new QGroupBox("View", this);
  QHBoxLayout *viewLayout = new QHBoxLayout(viewBox);

  refreshButton = new QPushButton("Refresh", this);
  viewLayout->addWidget(refreshButton);
  connect(refreshButton, SIGNAL(clicked()), GetMainWindow(), SLOT(Refresh()));

  screenshotButton = new QPushButton("Screenshot", this);
  viewLayout->addWidget(screenshotButton);
  connect(screenshotButton, SIGNAL(clicked()), parentWidget(), SLOT(Screenshot()));

  saveRootButton = new QPushButton("Save ROOT File", this);
  viewLayout->addWidget(saveRootButton);
  connect(saveRootButton, SIGNAL(clicked()), GetMainWindow(), SLOT(SaveAs()));

  layout->addWidget(viewBox);


  // ----- View box
  
  // col/row +/- buttons
  QGroupBox *layoutBox = new QGroupBox("Window Layout", this);
  QHBoxLayout *windowLayoutLayout = new QHBoxLayout(layoutBox);

  delColButton = new QPushButton("- col");
  delColButton->setFixedSize(35, 20);
  windowLayoutLayout->addWidget(delColButton);

  QVBoxLayout *layoutRows = new QVBoxLayout();
  addRowButton = new QPushButton("+ row");
  layoutRows->addWidget(addRowButton);
  addRowButton->setFixedSize(35, 20);

  delRowButton = new QPushButton("- row");
  layoutRows->addWidget(delRowButton);
  delRowButton->setFixedSize(35, 20);

  windowLayoutLayout->insertLayout(-1, layoutRows);

  addColButton = new QPushButton("+ col");
  addColButton->setFixedSize(35, 20);
  windowLayoutLayout->addWidget(addColButton);

  windowLayoutLayout->insertStretch(-1, 10);

  // save / load layout buttons
  QVBoxLayout *loadSaveLay = new QVBoxLayout();

  loadLayoutButton = new QPushButton("load");
  loadLayoutButton->setFixedSize(60, 20);
  loadSaveLay->addWidget(loadLayoutButton);

  saveLayoutButton = new QPushButton("save");
  saveLayoutButton->setFixedSize(60, 20);
  loadSaveLay->addWidget(saveLayoutButton);

  windowLayoutLayout->insertLayout(-1, loadSaveLay);

  layout->addWidget(layoutBox);

  // apply the complete layout
  setLayout(layout);
}

//----------------------------------------------------------------------------------------------------

void LayoutMenu::EventChanged(int eventNr)
{
  runEventNavigationBox->EventChanged(eventNr);
}

//----------------------------------------------------------------------------------------------------

void LayoutMenu::RunChanged(int runNr)
{
  runEventNavigationBox->RunChanged(runNr);
}

void LayoutMenu::RunAndEventChanged(int runNr, int eventNr)
{
  runEventNavigationBox->RunAndEventNumbersChanged(runNr, eventNr);
}

//----------------------------------------------------------------------------------------------------

void LayoutMenu::EventLimitChanged(int minEventNr, int maxEventNr)
{
  runEventNavigationBox->EventLimitChanged(minEventNr, maxEventNr);
}

//----------------------------------------------------------------------------------------------------

void LayoutMenu::RunsChanged()
{
#ifdef DEBUG
  printf(">> LayoutMenu::RunsChanged\n");
#endif
  
  runEventNavigationBox->RunsChanged();
}

//----------------------------------------------------------------------------------------------------

MainWindow *LayoutMenu::GetMainWindow() {
  return (MainWindow*)parent()->parent()->parent();
}
