#include "ScreenDriver.h"

#ifndef _SCREENLIB
#define _SCREENLIB

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#endif



void ScreenDriver::startDisplay() {
    if (!display.begin(2, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }
    display.clearDisplay();
    display.display();
}

void ScreenDriver::printRect(Rectangle rect, bool doDisplay = false, bool clear = false) {
    if (clear)
        display.clearDisplay();
    display.fillRect(rect.x, rect.y, rect.width, rect.height, 1);
    if (doDisplay)
        display.display();
}

void ScreenDriver::printTria(Triangle tria, bool doDisplay = false, bool clear = false) {
    if (clear)
        display.clearDisplay();
    display.fillTriangle(tria.x1, tria.y1, tria.x2, tria.y2, tria.x3, tria.y3, 1);
    if (doDisplay)
        display.display();
}

void ScreenDriver::printText(const char* text, int x, int y, bool doDisplay = false, bool clear = false) {
    if (clear)
        display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x, y);
    display.println(text);
    if (doDisplay)
        display.display();
}

void ScreenDriver::clearDisplay() {
    display.clearDisplay();
    display.display();
}
