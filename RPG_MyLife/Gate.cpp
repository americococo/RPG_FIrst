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
	Component::Init(posX, posY, mapX, mapY);
	_ObjectType = eComponentType::GATE;

	_GateDirection = GateDirection;

	_sprite = new Sprite(L"./Sprite/Gate/Gate.png", L"./Sprite/Gate/Gate.json");
	_sprite->Init();
	_sprite->setPostition(_posX, _posY);

	_radius =( (_sprite->GetWidth() + _sprite->Getheight() ) /2) /2;
}
void Gate::ReciverMessage(MessageFrom msgFrom)
{
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
	_sprite->Update(deltaTime);
}
void Gate::render()
{
	_sprite->render();
}
void Gate::DeInit()
{

}

