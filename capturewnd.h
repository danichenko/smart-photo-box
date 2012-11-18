#ifndef _CAPTUREWND_H
#define _CAPTUREWND_H

#include <QWidget>
#include <QImage>

namespace smartPhotoBox {
	class CaptureWnd: public QWidget
	{
	public:
		CaptureWnd(QWidget *parent);
		~CaptureWnd();

	protected:
		virtual void paintEvent(QPaintEvent *event);
		virtual void closeEvent(QCloseEvent *event);

	private:
		QImage liveImage;
	};
}

#endif