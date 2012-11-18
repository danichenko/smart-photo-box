#ifndef _CAPTUREWND_H
#define _CAPTUREWND_H

#include <QWidget>
#include <QImage>

#include <string>

namespace smartPhotoBox {
	class CaptureWnd: public QWidget
	{
	public:
		CaptureWnd(QWidget *parent);
		~CaptureWnd();

		void setUnderlyingImageFilename(std::string filename);

	protected:
		virtual void paintEvent(QPaintEvent *event);
		virtual void customEvent(QEvent *event);	

	private:
		QImage liveImage;
		std::string underlyingImageFilename;
	};
}

#endif