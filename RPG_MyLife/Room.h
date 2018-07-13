#pragma once
#include <list>
#include "Gate.h"	
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
	

	std::list<Component*> _removeList;


	void CreateRoomGate(eRoomCodeDecode roomcode,int gateposX,int gateposY,eDirectionGATE gateDirection);


public:
	std::list<Component*> GetComponentList();

	bool CheckPlayer();


private:
	void removeUpdate();

public:
	void AddremoveList(Component * removeComponent);

	void AddComponent(Component * component);
};

