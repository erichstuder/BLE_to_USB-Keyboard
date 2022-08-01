#include "RemoteControl.h"
#include <Arduino.h>
#include <ArduinoBLE.h>

String RemoteControl::getLocalName(){
	return "RemoteControl";
}

String RemoteControl::getServiceUuid(){
	return "19b10000-e8f2-537e-4f6c-d104768a1214";
}

String RemoteControl::getCharacteristicUuid(){
	return "19b10001-e8f2-537e-4f6c-d104768a1214";
}
