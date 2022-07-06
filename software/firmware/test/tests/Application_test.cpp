#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Arduino.h"
#include "Application.h"

TEST_GROUP(Application_test){
	void setup(){}
	void teardown(){
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(Application_test, setup){
	Application::setup();
}

TEST(Application_test, tick){
	//RemoteControl::tick();
}
