#include "GameSystem.h"

#include "Room.h"
#include "Component.h"

#include "Gate.h"


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
	
	_roomCode = RoomCode;

	if (RoomCode[eRoomCodeDecode::PlayerStart] == 'o')
	{
		/*Player * player = new Player();
		player->init();
		_componentList.push_back((Component*)(player));*/
	}

	CreateRoomGate(eRoomCodeDecode::LEFT);
	CreateRoomGate(eRoomCodeDecode::RIGHT);
	CreateRoomGate(eRoomCodeDecode::DOWN);
	CreateRoomGate(eRoomCodeDecode::UP);


}
bool Room::CheckPlayer()
{
	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		if (eComponentType::GATE == (*itr)->GetComponentType())
			return true;
	}
	return false;
}
void Room::CreateRoomGate(eRoomCodeDecode roomcode)
{


	if (_roomCode[roomcode] != 'o')
		return;

	int gatePosX, gatePosY;
	switch (roomcode)
	{
	case LEFT:
		gatePosX = 0 + 32 / 2;
		gatePosY = GameSystem::GetInstance()->GetHeight()/2;
		break;
	case RIGHT:
		gatePosX= GameSystem::GetInstance()->GetWidth()-32/2;
		gatePosY = GameSystem::GetInstance()->GetHeight() / 2;
		break;
	case UP:
		gatePosX = GameSystem::GetInstance()->GetWidth()/2;
		gatePosY = 0 + 32/2;
		break;
	case DOWN:
		gatePosX = GameSystem::GetInstance()->GetWidth() / 2;
		gatePosY = GameSystem::GetInstance()->GetHeight() - 32 / 2;
		break;

	default:
		break;
	}


	Gate * gate = new Gate();
	gate->Init(gatePosX, gatePosY);
	_componentList.push_back(gate);

}

void Room::Update(float deltaTime)
{
	if (false ==CheckPlayer())
		return;


	
	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		(*itr)->Update(deltaTime);
	}
}
void Room::render()
{
	if (false == CheckPlayer())
		return;
	
	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		(*itr)->render();
	}
}