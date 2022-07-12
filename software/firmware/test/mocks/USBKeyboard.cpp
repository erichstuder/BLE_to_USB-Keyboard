#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "USBKeyboard.h"

int USBKeyboard::printf(const char *format, ...){
	mock().actualCall("USBKeyboard::printf")
		.withStringParameter("format", format);
	return 0;
}
