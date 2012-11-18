#ifndef _EVENTS_H
#define _EVENTS_H

#include <QEvent>
#include <QVariant>

namespace smartPhotoBox {
	class GCameraEvent: public QEvent
	{
	public:
		GCameraEvent(QEvent::Type type, QVariant val = QVariant())
		: QEvent(type)
		, value(val)
		{}

		const QVariant &getValue() const 
		{
			return value;
		}

	private:
		QVariant value;
	};
}

#define CAMERA_EVENT_LV_STARTED		(QEvent::Type)(QEvent::User + 1)
#define CAMERA_EVENT_LV_NOTSTARTED		(QEvent::Type)(QEvent::User + 2)
#define CAMERA_EVENT_NOCAMERA		(QEvent::Type)(QEvent::User + 3)
#define CAMERA_EVENT_EVF_TRANSMITED	(QEvent::Type)(QEvent::User + 4)
#define CAMERA_EVENT_AV_CHANGED 	(QEvent::Type)(QEvent::User + 5)
#define CAMERA_EVENT_TV_CHANGED 	(QEvent::Type)(QEvent::User + 6)
#define CAMERA_EVENT_AVLIST_CHANGED	(QEvent::Type)(QEvent::User + 7)
#define CAMERA_EVENT_TVLIST_CHANGED	(QEvent::Type)(QEvent::User + 8)
#define CAMERA_EVENT_FPS_UPDATED	(QEvent::Type)(QEvent::User + 9)
#define CAMERA_EVENT_AEMODE_CHANGED	(QEvent::Type)(QEvent::User + 10)
#define CAMERA_EVENT_AEMODELIST_CHANGED	(QEvent::Type)(QEvent::User + 11)
#define CAMERA_EVENT_AFMODE_CHANGED	(QEvent::Type)(QEvent::User + 12)
#define CAMERA_EVENT_ZOOM_CHANGED	(QEvent::Type)(QEvent::User + 13)
#define CAMERA_EVENT_ZOOM_CHANGED_STOP	(QEvent::Type)(QEvent::User + 14)
#define CAMERA_EVENT_ZOOMPOS_NEEDCHANGE	(QEvent::Type)(QEvent::User + 15)
#define CAMERA_EVENT_AF_STOPPED		(QEvent::Type)(QEvent::User + 16)
#define CAMERA_EVENT_HISTOGRAM		(QEvent::Type)(QEvent::User + 17)
#define CAMERA_EVENT_HISTOGRAM_CLOSED	(QEvent::Type)(QEvent::User + 18)
#define CAMERA_EVENT_ISO_CHANGED 	(QEvent::Type)(QEvent::User + 19)
#define CAMERA_EVENT_ISOLIST_CHANGED	(QEvent::Type)(QEvent::User + 20)
#define CAMERA_EVENT_FPS_CALCULATED		(QEvent::Type)(QEvent::User + 21)
#define CAMERA_EVENT_UPDATE_COUNTERS	(QEvent::Type)(QEvent::User + 22)
#define CAMERA_EVENT_WRITE_STOPPED	(QEvent::Type)(QEvent::User + 23)
#define CAMERA_EVENT_SHOWMSG		(QEvent::Type)(QEvent::User + 99)
#define CAMERA_EVENT_SHUTDOWN		(QEvent::Type)(QEvent::User + 100)


#endif