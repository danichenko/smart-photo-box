#include "capturewnd.h"

smartPhotoBox::CaptureWnd::CaptureWnd(QWidged * parent)
: QWidged(parent)
{
	setMinimumSize(768, 512);
	setMouseTracking(false);
}

smartPhotoBox::CaptureWnd::~CaptureWnd()
{	
}