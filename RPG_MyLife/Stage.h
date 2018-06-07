#pragma once
#include <Windows.h>
#include <vector>
#include <string>

class Room;
class Stage
{
public:
	Stage(LPCWSTR StageDataFile);
	~Stage();


	void Init();
	void Update(float deltaTime);
	void render();


	bool checkingClearStage();


private:
	LPCWSTR _StageDataFile;

	int _StageMaxX;
	int _StageMaxY;


	std::vector<Room*> _roomList;
};

