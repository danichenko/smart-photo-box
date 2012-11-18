#include <command.h>
#include <stdexcept>

using std::runtime_error;

smartPhotoBox::CameraHolder::CameraHolder() 
{
	gphotoContext = gp_context_new();
	if (!photoContext) {
		throw new runtime_error("Failed to initialize gphoto2 context");
	}	
}