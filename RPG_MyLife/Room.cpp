#include "GameSystem.h"

#include "Room.h"
#include "Component.h"



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


	
		CreateRoomGate(eRoomCodeDecode::LEFTDOOR,0, GameSystem::GetInstance()->GetHeight() / 2,eDirectionGATE::LEFTRoom);

	
		CreateRoomGate(eRoomCodeDecode::RIGHTDOOR, GameSystem::GetInstance()->GetWidth(), GameSystem::GetInstance()->GetHeight() / 2,eDirectionGATE::RIGHTRoom);
	
	
		CreateRoomGate(eRoomCodeDecode::UPDOOR, GameSystem::GetInstance()->GetWidth() / 2, 0, eDirectionGATE::UPRoom);


		CreateRoomGate(eRoomCodeDecode::DOWNDOOR, GameSystem::GetInstance()->GetWidth() / 2, GameSystem::GetInstance()->GetHeight(), eDirectionGATE::DOWNRoom);




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

void Room::CreateRoomGate(eRoomCodeDecode roomcode, int gateposX, int gateposY,eDirectionGATE gateDirectioon)
{
	if (_roomCode[roomcode] != 'o')
		return;

	

	Gate * gate = new Gate();
	gate->Init(gateposX, gateposY, _posX, _posY, gateDirectioon);


	if (gateposX == 0)
		gateposX += gate->GetRadius();

	else if (gateposX == GameSystem::GetInstance()->GetWidth())
		gateposX -= gate->GetRadius();

	if (gateposY == 0)
		gateposY += gate->GetRadius();

	else if (gateposY == GameSystem::GetInstance()->GetHeight())
		gateposY -= gate->GetRadius();


	gate->SetPos(gateposX, gateposY);
	
	_componentList.push_back(gate);

}

void Room::Update(float deltaTime)
{

	MessagePost::GetInstance()->ProcessMessageQueue();

	removeUpdate();
	
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
void Room::removeUpdate()
{
	while (_removeList.empty()==false)
	{
		Component * com = _removeList.front();
		_componentList.remove(com);
		_removeList.remove(com);

		
	}
}
void Room::AddremoveList(Component * removeComponent)
{
	_removeList.push_back(removeComponent);
}

void Room::AddComponent(Component * component)
{
	component->SetMapPosition(_posX, _posY);
	component->SetPos(GameSystem::GetInstance()->GetWidth() / 2, GameSystem::GetInstance()->GetHeight() / 2);
	_componentList.push_back(component);
}