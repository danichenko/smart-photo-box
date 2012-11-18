#ifndef _CAPTUREWND_H
#define _CAPTUREWND_H

#include <QWidget>
#include <QImage>
#include <QMutex>

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
		unsigned char *frame;
		int max_frame_size;
		std::string underlyingImageFilename;
	};
}

#endif