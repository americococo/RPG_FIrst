#include "GameSystem.h"

#include "Room.h"
#include "Component.h"

#include "Gate.h"

#include "Player.h"
#include "MessagePost.h"

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
		Player * player = new Player();
		player->Init(GameSystem::GetInstance()->GetWidth() / 2, GameSystem::GetInstance()->GetHeight() / 2,_posX,_posY);
		_componentList.push_back(player);
	}


	if (RoomCode[eRoomCodeDecode::LEFTDOOR] == 'o')
		CreateRoomGate(eRoomCodeDecode::LEFTDOOR);
	if (RoomCode[eRoomCodeDecode::RIGHTDOOR] == 'o')
		CreateRoomGate(eRoomCodeDecode::RIGHTDOOR);
	
	if (RoomCode[eRoomCodeDecode::UPDOOR] == 'o')
		CreateRoomGate(eRoomCodeDecode::UPDOOR);

	if (RoomCode[eRoomCodeDecode::DOWNDOOR] == 'o')
		CreateRoomGate(eRoomCodeDecode::DOWNDOOR);




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
std::list<Component*> Room::GetComponentList()
{
	return _componentList;
}

void Room::CreateRoomGate(eRoomCodeDecode roomcode)
{
	int gatePosX=0, gatePosY=0;
	eDirectionGATE direction=eDirectionGATE::NONERoom;

	Gate * gate = new Gate();
	gate->Init(gatePosX, gatePosY, _posX, _posY, direction);

 	switch (roomcode)
	{
	case eRoomCodeDecode::LEFTDOOR:
		gatePosX = 0 + gate->GetRadius();
		gatePosY = GameSystem::GetInstance()->GetHeight()/2;
		direction = eDirectionGATE::LEFTRoom;
		break;
	case eRoomCodeDecode::RIGHTDOOR:
		gatePosX= GameSystem::GetInstance()->GetWidth()- gate->GetRadius();
		gatePosY = GameSystem::GetInstance()->GetHeight() / 2;
		direction = eDirectionGATE::RIGHTRoom;
		break;
	case eRoomCodeDecode::UPDOOR:
		gatePosX = GameSystem::GetInstance()->GetWidth()/2;
		gatePosY = 0 + gate->GetRadius();
		direction = eDirectionGATE::UPRoom;
		break;
	case eRoomCodeDecode::DOWNDOOR:
		gatePosX = GameSystem::GetInstance()->GetWidth() / 2;
		gatePosY = GameSystem::GetInstance()->GetHeight() - gate->GetRadius();
		direction = eDirectionGATE::DOWNRoom;
		break;

	}

	gate->SetPos(gatePosX, gatePosY);
	
	gate->SetGateDirection(direction);
	_componentList.push_back(gate);

}

void Room::Update(float deltaTime)
{

	MessagePost::GetInstance()->ProcessMessageQueue();
	
	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		(*itr)->Update(deltaTime);
	}
}
void Room::render()
{

	for (std::list<Component*>::iterator itr = _componentList.begin(); itr != _componentList.end(); itr++)
	{
		(*itr)->render();
	}
}