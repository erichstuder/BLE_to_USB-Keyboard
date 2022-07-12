#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "ArduinoBLE.h"

BLEService::BLEService(const char* uuid){}

void BLEService::addCharacteristic(BLECharacteristic& characteristic){
	mock().actualCall("BLEService::addCharacteristic");
}

void BLEDevice::poll(){
	mock().actualCall("BLEDevice::poll");
}

BLEStringCharacteristic::BLEStringCharacteristic(const char* uuid, unsigned char properties, int valueSize){}

int BLEStringCharacteristic::writeValue(const String& value){
	mock().actualCall("BLEStringCharacteristic::writeValue")
		.withStringParameter("value", value.c_str());
	return 1;
}

String BLEStringCharacteristic::value(void){
	mock().actualCall("BLEStringCharacteristic::value");
	return *(static_cast<String*>(mock().pointerReturnValue()));
}

void BLEStringCharacteristic::setEventHandler(int event, BLECharacteristicEventHandler eventHandler){
	mock().actualCall("BLEStringCharacteristic::setEventHandler")
		.withParameter("event", event);
	mock().setData("eventHandler", (void*)eventHandler);
	CHECK(eventHandler != NULL);
}

int BLELocalDevice::begin(){
	mock().actualCall("BLELocalDevice::begin");
	return 1;
}

bool BLELocalDevice::setAdvertisedService(const BLEService& service){
	mock().actualCall("BLELocalDevice::setAdvertisedService");
	return true;
}

bool BLELocalDevice::setLocalName(const char *localName){
	mock().actualCall("BLELocalDevice::setLocalName")
		.withParameter("localName", localName);
	return true;
}

void BLELocalDevice::addService(BLEService& service){
	mock().actualCall("BLELocalDevice::addService");
}

int BLELocalDevice::advertise(){
	mock().actualCall("BLELocalDevice::advertise");
	return 0;
}

BLEDevice BLELocalDevice::central(){
	mock().actualCall("BLELocalDevice::central");
	return BLEDevice();
}

BLELocalDevice BLEObj;
BLELocalDevice& BLE = BLEObj;
