#include "TotemDQMLite/GUI/interface/QRootEventHandler.h"

#include <QTimer>

#include <TSystem.h>

//----------------------------------------------------------------------------------------------------
  
QRootEventHandler::~QRootEventHandler()
{
}

//----------------------------------------------------------------------------------------------------

QRootEventHandler::QRootEventHandler(QWidget *parent) : QWidget(parent)
{
   timer = new QTimer(this);
   QObject::connect(timer, SIGNAL(timeout()), this, SLOT(HandleRootEvents()));
   timer->start(50);	// in ms
}

//----------------------------------------------------------------------------------------------------

void QRootEventHandler::HandleRootEvents()
{
   gSystem->ProcessEvents();
}
