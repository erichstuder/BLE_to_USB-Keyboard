#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "USBKeyboard.h"

int USBKeyboard::printf(const char *format, ...){
	mock().actualCall("USBKeyboard::printf");
	return mock().returnIntValueOrDefault(0);
}
