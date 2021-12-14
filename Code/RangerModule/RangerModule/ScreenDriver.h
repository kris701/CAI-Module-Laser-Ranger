// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

struct Rectangle {
	int x;
	int y;
	int width;
	int height;
};
struct Triangle {
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
};

class ScreenDriver {
public:
	ScreenDriver() {};

	void ScreenDriver::printRect(Rectangle rect, bool doDisplay = false, bool clear = false);
	void ScreenDriver::printTria(Triangle tria, bool doDisplay = false, bool clear = false);
	void ScreenDriver::printText(const char* text, int x, int y, bool doDisplay = false, bool clear = false);
	void ScreenDriver::clearDisplay();
	void ScreenDriver::startDisplay();
};

#endif
