#include "capturewnd.h"

#include "buffer.h"
#include "events.h"

#include <QPainter>

smartPhotoBox::CaptureWnd::CaptureWnd(QWidged * parent)
: QWidged(parent)
{
	setMinimumSize(768, 512);
	setMouseTracking(false);
}

smartPhotoBox::CaptureWnd::~CaptureWnd()
{	
}

void smartPhotoBox::CaptureWnd::setUnderlyingImageFilename(std::string filename)
{
	this->underlyingImageFilename = filename;
}

void smartPhotoBox::CaptureWnd::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if (!liveImage.isNull())
	{
		painter.setCompositionMode(QPainter::CompositionMode_Source);
		painter.drawImage(QPoint(0, 0), QImage(underlyingImageFileName));
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painter.drawImage(QPoint(0, 0), liveImage);
	} else {
		QBrush br(QColor(0, 0, 0), Qt::SolidPattern);
		painter.fillRect(0, 0, width(), height(), br);
	}
}

void smartPhotoBox::CaptureWnd::customEvent(QEvent *event)
{

}