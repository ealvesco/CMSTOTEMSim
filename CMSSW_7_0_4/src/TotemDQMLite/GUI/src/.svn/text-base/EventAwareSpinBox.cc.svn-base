/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakovski
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/EventAwareSpinBox.h"

#include <iostream>

using namespace std;

void EventAwareSpinBox::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Up)
  {
    ProcessManager::RunEventStruct runEventStruct;
    runEventStruct = ProcessManager::GetInstance().NextEvent();
    runEventNavigationBox->RunAndEventNumbersChanged(runEventStruct.runNr, runEventStruct.eventNr);

    #ifdef DEBUG
      cout << ">> EventAwareSpinBox::keyPressEvent > [/\\] run: " << runEventStruct.runNr << " event: " << runEventStruct.eventNr << endl;
    #endif

    return;
  }

  if(event->key() == Qt::Key_Down)
  {
    ProcessManager::RunEventStruct runEventStruct;
    runEventStruct = ProcessManager::GetInstance().PreviousEvent();
    runEventNavigationBox->RunAndEventNumbersChanged(runEventStruct.runNr, runEventStruct.eventNr);

    #ifdef DEBUG
      cout << ">> EventAwareSpinBox::keyPressEvent > [\\/] run: " << runEventStruct.runNr << " event: " << runEventStruct.eventNr << endl;
    #endif

    return;
  }
  
  // default handler
  QSpinBox::keyPressEvent(event);
}
