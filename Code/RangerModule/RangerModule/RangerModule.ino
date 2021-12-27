#include "ScreenDriver.h"
#include <EEPROM.h>

ScreenDriver screenDriver = ScreenDriver();
#define sensorPin A7
#define sensorMaxValue 600
#define screenHeight 32
#define screenWidth 128

#define calUpPin 6
#define calDownPin 7
#define calAddr 0

int preHeight = 0;
int calValue = 0;

void setup() {
	pinMode(calUpPin, INPUT);
	pinMode(calDownPin, INPUT);
	screenDriver.startDisplay();
	screenDriver.clearDisplay();
	calValue = GetCalibrationValue();
	if (calValue > screenWidth)
		calValue = screenWidth;
}

void loop() {
	if (digitalRead(calUpPin) == 1) {
		calValue++;
		UpdateCalibration(calValue);
	}

	if (digitalRead(calDownPin) == 1) {
		calValue--;
		UpdateCalibration(calValue);
	}

	float reading = analogRead(sensorPin);
	int newWidth = (reading / sensorMaxValue) * screenWidth;
	Triangle calTri = { 0,15,calValue,25,screenWidth,15 };
	screenDriver.printTria(calTri, false, true);
	screenDriver.printText("Calibration",30,0);
	Rectangle rect = {0,30,newWidth,5};
	screenDriver.printRect(rect, true);
	preHeight = newWidth;
	delay(200);
}

void UpdateCalibration(int value) {
	if (value < 0)
		value = 0;
	if (value > screenWidth)
		value = screenWidth;
	EEPROM.write(calAddr, value);
}

int GetCalibrationValue() {
	return EEPROM.read(calAddr);
}