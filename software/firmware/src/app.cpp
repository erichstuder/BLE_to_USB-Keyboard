#include <Arduino.h>
#include <ArduinoBLE.h>
#include <USBKeyboard.h>
#include "app.h"
#include "bleRemoteHandler.h"

namespace app{
	// UUID considerations:
	// Avoid Base UUID.
	// Base UUID: 00000000-0000-1000-8000-00805F9B34FB
	// Don't use: XXXXXXXX-0000-1000-8000-00805F9B34FB
	// The UUIDs are left as is given by the code examples for the moment.
	static BLEService keyboardInputService("19B10000-E8F2-537E-4F6C-D104768A1214");
	static BLEStringCharacteristic keyboardInputCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite, 42);
	static BLEDevice remoteControl;

	static USBKeyboard Keyboard;

	//static void writtenHandler(BLEDevice device, BLECharacteristic characteristic);
	static void updateHandler(byte value);

	void setup(){
		/*while(!BLE.begin());
		BLE.setLocalName("BLE_to_USB-Keyboard");
		BLE.setAdvertisedService(keyboardInputService);
		keyboardInputService.addCharacteristic(keyboardInputCharacteristic);
		BLE.addService(keyboardInputService);
		keyboardInputCharacteristic.setEventHandler(BLEWritten, writtenHandler);
		keyboardInputCharacteristic.writeValue(""); //set initial value
		remoteControl = BLE.central();
		BLE.advertise();*/

		bleRemoteHandler::init(updateHandler);
		delay(1000);
		Keyboard.printf("setup done");

	}

	void tick(){
		//remoteControl.poll();
		bleRemoteHandler::tick();
	}

	/*static void writtenHandler(BLEDevice device, BLECharacteristic characteristic){
		String input = keyboardInputCharacteristic.value();
		Keyboard.printf(input.c_str());
	}*/

	static void updateHandler(byte value){
		Keyboard.printf("value %d\n", value);
	}
}
