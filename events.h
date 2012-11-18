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

#endif