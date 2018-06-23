#include "Room.h"


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

Room::Room()
{
}


Room::~Room()
{
}
void Room::Init(char * RoomCode,int posx,int posy)
{
	_posX = posx;
	_posY = posy;

	if (RoomCode[eRoomCodeDecode::PlayerStart] == 'o')
	{
		/*Player * player = new Player();
		player->init();
		_componentList.push_back((Component*)(player));*/
	}

}
bool Room::CheckPlayer()
{
	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		if (eComponentType::PlAYER == (*itr)->GetComponentType())
			return true;
	}
	return false;
}

void Room::Update(float deltaTime)
{
	if (false ==CheckPlayer())
	{
		return;
	}


	
	//for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	//{
	//	(*itr)->Update(deltaTime);
	//}
}
void Room::render()
{
	if (false == CheckPlayer())
	{
		return;
	}

	//for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	//{
	//	(*itr)->render();
	//}
}