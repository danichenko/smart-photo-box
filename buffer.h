#ifndef _BUFFER_H
#define _BUFFER_H

#include <QMutex>

namespace live_buffer
{
	extern QMutex ImageMutex;
	extern unsigned char* frame;
	extern int frame_size;
	extern int frame_width;
	extern int frame_height;
	extern bool IsPainting;
}

#endif