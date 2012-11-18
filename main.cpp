#include <qapplication>
#include "mainwnd.h"

int main(int argc, void ** argv) {
	QApplication app(argc, argv);
	setLocale(LC_MESSAGES, "POSIX");

	return app.exec();
}