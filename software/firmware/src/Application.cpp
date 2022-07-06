#include <Arduino.h>
//#include <PluggableUSBHID.h>
#include <USBKeyboard.h>
//#include <Nano33BleHID.h>
#include "Application.h"

namespace Application{

	static USBKeyboard Keyboard;

	void setup(){

	}

	void loop(){
		delay(1000);
  		Keyboard.printf("Hello world\n\r");
	}
}
