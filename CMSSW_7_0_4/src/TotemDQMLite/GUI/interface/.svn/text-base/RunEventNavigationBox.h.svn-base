/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakowski
*
****************************************************************************/

#ifndef _RunEventNavigationBox_h_
#define _RunEventNavigationBox_h_

#include <map>
#include <string>
#include <iostream>

#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVariant>

#include "TotemDQMLite/GUI/interface/MainWindow.h"
#include "TotemDQMLite/GUI/interface/ProcessManager.h"
#include "TotemDQMLite/GUI/interface/EventAwareSpinBox.h"
#include "TotemRawData/DataFormats/interface/TotemRunNumber.h"

class RunEventNavigationBox : public QGroupBox
{
    Q_OBJECT

public:
    RunEventNavigationBox(std::string title, MainWindow *mainWindow, QWidget *parent = 0);
    QComboBox* getRunNrBox() { return runNrBox; }
    QSpinBox* getEventNrBox() { return eventNrBox; }
    void EventLimitChanged(int minEventNr, int maxEventNr);
    void RunsChanged();
    void RunChanged(int runNr);
    void EventChanged(int eventNr);
    void RunAndEventNumbersChanged(int runNr, int eventNr);

public slots:
    void RunNrEditted();
    void EventNrEditted();

private:
    QComboBox *runNrBox;
    QSpinBox *eventNrBox;
    QLabel *eventsRangeLabel;
    MainWindow *mainWindow;

    void CreateAndCustomizeEventNrBox(QWidget * parent);
    void CreateAndCustomizeRunNrBox(QWidget * parent);
    QLayout* CreateRunLayout();
    QLayout* CreateEventLayout();
    QLayout* CreateEventNrLayout();
    QLabel* CreateEventNumberLabel();
    QLabel* CreateRunNumberLabel();
    void BlockSignals(bool block);
};

#endif
