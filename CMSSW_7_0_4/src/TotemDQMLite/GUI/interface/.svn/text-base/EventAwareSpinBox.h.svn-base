/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakowski
*
****************************************************************************/

#ifndef _EventAwareSpinBox_h_
#define _EventAwareSpinBox_h_

#include <QSpinBox>
#include <QKeyEvent>
#include "TotemDQMLite/GUI/interface/ProcessManager.h"
#include "TotemDQMLite/GUI/interface/RunEventNavigationBox.h"

class RunEventNavigationBox;

class EventAwareSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    EventAwareSpinBox(RunEventNavigationBox * runEventNavigationBox, QWidget *parent = 0) : QSpinBox(parent),
            runEventNavigationBox(runEventNavigationBox) {};

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    RunEventNavigationBox *runEventNavigationBox;
};

#endif
