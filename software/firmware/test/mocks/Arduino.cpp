#include "CppUTestExt/MockSupport.h"
#include "Arduino.h"
#include <cstring>


String::String(const char *cstr){
	size_t len = strlen(cstr);
	memcpy(buffer, cstr, len);
	buffer[len] = '\0';
}

const char* String::c_str() const{
	return this->buffer;
}

/*
void pinMode(pin_size_t pin, PinMode mode){
	mock().actualCall("pinMode")
		.withParameter("pin", pin)
		.withParameter("mode", mode);
}

void digitalWrite(pin_size_t pin, PinStatus val){
	mock().actualCall("digitalWrite")
		.withParameter("pin", pin)
		.withParameter("val", val);
}

void delay(unsigned long ms){
	mock().actualCall("delay")
		.withParameter("ms", ms);
}

unsigned long millis(void){
	mock().actualCall("millis");
	return mock().returnIntValueOrDefault(0);
}
*/
