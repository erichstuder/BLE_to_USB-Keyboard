#include <Arduino.h>
#include <ArduinoBLE.h>
#include <USBKeyboard.h>
#include <String.h>
#include "Application.h"

namespace Application{
	// UUID considerations:
	// Avoid Base UUID.
	// Base UUID: 00000000-0000-1000-8000-00805F9B34FB
	// Don't use: XXXXXXXX-0000-1000-8000-00805F9B34FB
	// The UUIDs are left as is given by the code examples for the moment.
	static BLEService keyboardInputService("19B10000-E8F2-537E-4F6C-D104768A1214");
	static BLEByteCharacteristic keyboardInputCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite);
	static BLEDevice remoteControl;

	///////////
	static USBKeyboard Keyboard; //<= commenting out this line makes it work !!!!!!!!!!
	///////////


	static void writtenHandler(BLEDevice device, BLECharacteristic characteristic);

	void setup(){
		while(!BLE.begin());
		BLE.setLocalName("BLE_to_USB-Keyboard");
		BLE.setAdvertisedService(keyboardInputService);
		keyboardInputService.addCharacteristic(keyboardInputCharacteristic);
		BLE.addService(keyboardInputService);
		keyboardInputCharacteristic.setEventHandler(BLEWritten, writtenHandler);
		//keyboardInputCharacteristic.writeValue(""); //set initial value
		keyboardInputCharacteristic.writeValue(0x00); //set initial value
		remoteControl = BLE.central();
		BLE.advertise();


		pinMode(LED_BUILTIN, OUTPUT);
	}

	void loop(){
		digitalWrite(LED_BUILTIN, HIGH);
		remoteControl.poll();
		delay(500);
		digitalWrite(LED_BUILTIN, LOW);
		delay(500);
	}

	static void writtenHandler(BLEDevice device, BLECharacteristic characteristic){
		//String input = keyboardInputCharacteristic.value();
		//Keyboard.printf("dummy");
	}
}
