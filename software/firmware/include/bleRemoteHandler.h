#pragma once

namespace bleRemoteHandler{
	enum class Command{
		TurnTable_TurnClockwise,
		TurnTable_TurnCounterClockwise,
		Kodi_Up,
	};

	void init(void (*updateHandler)(byte));
	extern void (*tick)();
	extern void (*disconnectAllAccessories)();
	//extern void (*send)(Command command);
};
