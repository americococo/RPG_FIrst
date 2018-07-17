#include "Gate.h"
#include "Sprite.h"
#include "StageManager.h"
#include "Stage.h"
#include "Room.h"
Gate::Gate()
{
}


Gate::~Gate()
{
}
void Gate::Init(float posX, float posY,int mapX,int mapY,eDirectionGATE GateDirection)
{
	FixedObject::Init(posX, posY, mapX, mapY, L"./Sprite/Gate/Gate.png", L"./Sprite/Gate/Gate.json");
	_ObjectType = eComponentType::GATE;

	_GateDirection = GateDirection;
}
void Gate::ReciverMessage(MessageFrom msgFrom)
{

	FixedObject::ReciverMessage(msgFrom);

	if (L"Collison" == msgFrom.message)
	{
		Component * sender =msgFrom.sender;
		Component * reciver= msgFrom.reciver;

		if (sender->GetComponentType() == eComponentType::PlAYER)
		{
			Room * presentRoom = StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY);


			int mx =_mapX, my= _mapY;

			switch (_GateDirection)
			{
			case LEFTRoom: mx--;
				break;
			case RIGHTRoom: mx++;
				break;
			case UPRoom: my--;
				break;
			case DOWNRoom: my++;
				break;
			}


			Room * nextRoom= StageManager::GetInstance()->GetStage()->GetRoom(mx, my);


			std::list<Component*> comlist = presentRoom->GetComponentList();


			presentRoom->AddremoveList(sender);
			
			nextRoom->AddComponent(sender);

		}
	}
}
void Gate::SetGateDirection(eDirectionGATE direction)
{
	_GateDirection = direction;
}
void Gate::Update(float deltaTime)
{
	FixedObject::Update(deltaTime);
}
void Gate::render()
{
	FixedObject::render();
}
void Gate::DeInit()
{
	FixedObject::DeInit();
}

