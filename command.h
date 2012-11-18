#ifndef _COMMAND_H
#define _COMMAND_H

#include <gphoto2/gphoto2.h>
#include <gphoto2/gphoto2-camera.h>

namespace smartPhotoBox {
	class CameraHolder {
		Camera * camera;
		GPContext * gphotoContext;		
	public:
		CameraHolder();

	};

}

#endif