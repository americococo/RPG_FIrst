#pragma once
#include <list>

enum eRoomCodeDecode
{
	PlayerStart,
	LEFTDOOR,
	RIGHTDOOR,
	UPDOOR,
	DOWNDOOR,
	IsItem,
	IsEnemy,
	IsBossRoom
};


class Component;
class Room
{
public:
	Room();
	~Room();


	void Init(char * RoomCode,int posx,int posy);
	void Update(float deltaTime);
	void render();

private:
	int _posX;
	int _posY;


	char * _roomCode;


private:
	std::list<Component*> _componentList;
	




	void CreateRoomGate(eRoomCodeDecode roomcode);


public:
	std::list<Component*> GetComponentList();

	bool CheckPlayer();
};

