#ifndef _QRootCanvas_h_
#define _QRootCanvas_h_

#include <QWidget>

class QPaintEvent;
class QResizeEvent;
class QMouseEvent;
class QPushButton;
class TCanvas;

/**
 * ROOT TCanvas embedded in a Qt QWidget.
 *
 * Implementation based on
 *   - https://root.cern.ch/drupal/content/how-embed-tcanvas-external-applications
 *   - https://root.cern.ch/phpBB3/viewtopic.php?f=3&t=19524&p=84528&hilit=Qt#p84528
 **/
class QRootCanvas : public QWidget
{
	Q_OBJECT

public:
	QRootCanvas(QWidget *parent = NULL);

	virtual ~QRootCanvas();

	TCanvas* GetCanvas()
	{
		return canvas;
	}

protected:
	/// the embedded canvas
	TCanvas *canvas;

	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *e);
	virtual void paintEvent(QPaintEvent *e);
	virtual void resizeEvent(QResizeEvent *e);
};

#endif
