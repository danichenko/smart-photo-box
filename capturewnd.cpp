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
	static int old_width = 0;
	static int old_height = 0;
	if (event->type() == CAMERA_EVENT_EVF_TRANSMITED && live_buffer::frame)
	{		
		live_buffer::IsPainting = true;
		int size = live_buffer::frame_size;
		if (max_frame_size < size)
		{
			frame = (unsigned char*)realloc(frame, size);
			max_frame_size = size;
		}
		memcpy(frame, live_buffer::frame, size);
		live_buffer::ImageMutex.unlock();
		QByteArray a = QByteArray::fromRawData(reinterpret_cast<const char *>(frame), size);
		QBuffer b;
		b.setData(a);
		b.open(QIODevice::ReadOnly);
		static QImageReader ir;
		ir.setDevice(&b);
		ir.setFormat("jpeg");
		if (ir.read(&liveImage))
		{
			if (!liveImage.isNull())
			{
				live_buffer::frame_width = liveImage.width();
				live_buffer::frame_height = liveImage.height();
				if (old_width != live_buffer::frame_width || old_height != live_buffer::frame_height)
				{
					setMinimumSize(live_buffer::frame_width, live_buffer::frame_height);
					setMaximumSize(live_buffer::frame_width, live_buffer::frame_height);
				}
				old_width = live_buffer::frame_width;
				old_height = live_buffer::frame_height;
			}			
			update(0, 0, live_buffer::frame_width, live_buffer::frame_height);
		}
		live_buffer::IsPainting = false;
	}	
	event->accept();
}