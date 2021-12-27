# CAI-Module-Laser-Ranger
This is a project about making an extension module for my Snapmaker Original printer. This is also an extension to [another of my projects](https://github.com/kris701/CAI), and is directly connected to it. It is also designed to be mounted on my [toolhead extension project](https://github.com/kris701/SnapMaker-Toolhead-Extensions).
The purpose of this module is to making calibration of the Snapmaker Laser module easier, since it can be a bit of a pain to calibrate it every time you need to use it. Instead, this is a system where a little screen displays how far above the bed that the module is. This makes it a lot easier to calibrate is, as it removes the need to use that little calibration paper that comes with the printer.

<p align="center">
  <img height=200 src="https://user-images.githubusercontent.com/22596587/147480393-424a66a5-3b6e-4cbc-af8e-528a6d4380fe.JPG">
  <img height=200 src="https://user-images.githubusercontent.com/22596587/147480454-2e9807bb-b6c5-4c79-91d2-7f844ae046c4.gif">
</p>

The system consists of a little OLED screen, a infrared proximity sensor and two buttons to calibrate it. The buttons can be held down, to move the little triangle in the display up or down. The last set calibration value is saved in the EEPROM of the Arduino Nano that controls it, so that its not lost when the power goes off.

<p align="center">
  <img height=200 src="https://user-images.githubusercontent.com/22596587/147480698-1e751271-8fe4-486c-852a-c9d01f52b9e0.gif">
  <img height=200 src="https://user-images.githubusercontent.com/22596587/147480402-2de05300-d51e-4753-be0a-d2c4028b9bc8.JPG">
</p>

This then makes it so that you only really have to calibrate it once (with the calibration paper), and then you can just use the ranger module from there on out.
