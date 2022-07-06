/*
Boards Manager:  Arduino Mbed OS Nano Boards v3.1.1
Library Manager: Mbed BLE HID v1.3.0
Board: Arduino Nano 33 BLE (https://store.arduino.cc/products/arduino-nano-33-ble)

Note:
Using arduino project as a workaround.
There are problems with "Mbed BLE HID" library in platformio.
This project may be ported to platformio as soon as the problems are fixed.
*/

#include "Application.h"

void setup(){
	Application::setup();
}

void loop(){
	Application::loop();
}
