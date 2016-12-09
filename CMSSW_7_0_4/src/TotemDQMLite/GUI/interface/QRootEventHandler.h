#ifndef _QRootEventHandler_h_
#define _QRootEventHandler_h_

#include <QWidget>

class QTimer;

/**
 * Class that assures that ROOT's event loop is regularly run.
 **/
class QRootEventHandler : public QWidget
{
   Q_OBJECT

public:
   QRootEventHandler(QWidget *parent = 0);

   virtual ~QRootEventHandler();

public slots:
   void HandleRootEvents();

protected:
   QTimer *timer;
};

#endif
