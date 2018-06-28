#pragma once
#include <list>

enum eRoomCodeDecode
{
	PlayerStart,
	LEFT,
	RIGHT,
	UP,
	DOWN,
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
	

	bool CheckPlayer();


	void CreateRoomGate(eRoomCodeDecode roomcode);

};

