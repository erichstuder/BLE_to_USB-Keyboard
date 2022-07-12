#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Arduino.h"
#include "ArduinoBLE.h"
#include "App.h"

TEST_GROUP(App_test){
	void setup(){}
	void teardown(){
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(App_test, setup){
	mock().expectOneCall("BLELocalDevice::begin");
	mock().expectOneCall("BLELocalDevice::setLocalName")
		.withParameter("localName", "BLE_to_USB-Keyboard");
	mock().expectOneCall("BLELocalDevice::setAdvertisedService");
	mock().expectOneCall("BLEService::addCharacteristic");
	mock().expectOneCall("BLELocalDevice::addService");
	mock().expectOneCall("BLEStringCharacteristic::setEventHandler")
		.withParameter("event", 3);
	mock().expectOneCall("BLEStringCharacteristic::writeValue")
		.withParameter("value", "");
	mock().expectOneCall("BLELocalDevice::central");
	mock().expectOneCall("BLELocalDevice::advertise");

	App::setup();
}

TEST(App_test, tick){
	mock().expectOneCall("BLEDevice::poll");
	App::tick();
}

TEST(App_test, writtenHandler){
	mock().disable();
	App::setup();
	mock().enable();
	BLECharacteristicEventHandler writtenHandler = (BLECharacteristicEventHandler)mock().getData("eventHandler").getPointerValue();
	
	BLEDevice bleDeviceDummy;
	BLEStringCharacteristic bleStringCharacteristicDummy("dummyUUID", 0, 0);

	String text = ("this is a test");
	mock().expectOneCall("BLEStringCharacteristic::value")
		.andReturnValue(&text);
	mock().expectOneCall("USBKeyboard::printf")
		.withParameter("format", text.c_str());

	writtenHandler(bleDeviceDummy, bleStringCharacteristicDummy);
}
