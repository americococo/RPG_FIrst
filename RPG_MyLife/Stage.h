#pragma once
#include <Windows.h>
#include <map>

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

	
	std::map<std::pair<int,int >,Room*> _roomList;

public:
	Room * GetRoom(int mapX,int mapY);
};

