#include "TotemDQMLite/GUI/interface/QRootCanvas.h"

#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>

#include "TCanvas.h"
#include "TVirtualX.h"

//----------------------------------------------------------------------------------------------------

QRootCanvas::~QRootCanvas()
{
	#ifdef DEBUG
  		printf(">> QRootCanvas::~QRootCanvas\n");
  	#endif
}

//----------------------------------------------------------------------------------------------------

QRootCanvas::QRootCanvas(QWidget *parent) : QWidget(parent, 0), canvas(0)
{
	// set options needed to properly update the canvas when resizing the widget
	// and to properly handle context menus and mouse move events
	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_OpaquePaintEvent, true);
	setMinimumSize(100, 100);
	setUpdatesEnabled(kFALSE);
	setMouseTracking(kTRUE);

	// register the QWidget in TVirtualX, giving its native window id
	int wid = gVirtualX->AddWindow((ULong_t)winId(), 100, 100);

	// create the ROOT TCanvas, giving as argument the QWidget registered id
	canvas = new TCanvas("Root Canvas", width(), height(), wid);
}

//----------------------------------------------------------------------------------------------------

void QRootCanvas::mouseMoveEvent(QMouseEvent *e)
{
	if (canvas)
	{
		if (e->buttons() & Qt::LeftButton) {
			canvas->HandleInput(kButton1Motion, e->x(), e->y());
		} else if (e->buttons() & Qt::MidButton) {
			canvas->HandleInput(kButton2Motion, e->x(), e->y());
		} else if (e->buttons() & Qt::RightButton) {
			canvas->HandleInput(kButton3Motion, e->x(), e->y());
		} else {
			canvas->HandleInput(kMouseMotion, e->x(), e->y());
		}
	}
}

//----------------------------------------------------------------------------------------------------

void QRootCanvas::mousePressEvent(QMouseEvent *e)
{
	if (canvas)
	{
		switch (e->button())
		{
			case Qt::LeftButton :
				canvas->HandleInput(kButton1Down, e->x(), e->y());
				break;
			case Qt::MidButton :
				canvas->HandleInput(kButton2Down, e->x(), e->y());
				break;
			case Qt::RightButton :
				canvas->HandleInput(kButton3Down, e->x(), e->y());
				break;
			default:
				break;
		}
	}
}

//----------------------------------------------------------------------------------------------------

void QRootCanvas::mouseReleaseEvent(QMouseEvent *e)
{
	if (canvas)
	{
		switch (e->button())
		{
			case Qt::LeftButton :
				canvas->HandleInput(kButton1Up, e->x(), e->y());
				break;
			case Qt::MidButton :
				canvas->HandleInput(kButton2Up, e->x(), e->y());
				break;
			case Qt::RightButton :
				canvas->HandleInput(kButton3Up, e->x(), e->y());
				break;
			default:
				break;
		}
	}
}

//----------------------------------------------------------------------------------------------------

void QRootCanvas::resizeEvent(QResizeEvent *)
{
	if (canvas)
	{
		canvas->Resize();
		canvas->Update();
	}
}

//----------------------------------------------------------------------------------------------------

void QRootCanvas::paintEvent(QPaintEvent *)
{
	if (canvas)
	{
		canvas->Resize();
		canvas->Update();
	}
}
