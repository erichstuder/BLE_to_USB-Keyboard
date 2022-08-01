#pragma once

#include "BleAccessory.h"

class RemoteControl : public BleAccessory{
public:
	String getLocalName();
	String getServiceUuid();
	String getCharacteristicUuid();
};
