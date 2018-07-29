#include "MoveObject.h"
#include "GlobalType.h"

#include "State.h"

#include "StageManager.h"
#include "Stage.h"
#include "Room.h"

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>



#include "MessagePost.h"
#include "MessageFrom.h"

#include "EquipItem.h"
#include "EquipItemWeapon.h"
MoveObject::MoveObject()
{
	_direction = eDirection::NONEDIRCTION;
	_state = nullptr;


	_speed = 2.0f;
	_moveCoolTime = 2.0f;
}


MoveObject::~MoveObject()
{
}
void MoveObject::Init(float posX, float posY, int mapX, int mapY,int hp,float power)
{
	Component::Init(posX, posY, mapX,mapY);

	_hp = hp;
	_power = power;

	_attackCoolTime = 0.3f;
	_attackduraction = 0;
}

void MoveObject::render()
{
	_state->render();


	if (false == _equipItem.empty())
	{
		EquipItem * item = _equipItem.front();
		item->SetPos(_posX, _posY + 10);
		item->render();
	}
}
void MoveObject::ChangeState(eState stateType)
{
	if (_state != nullptr)
		_state->Stop();

	_state = _StateMap[stateType];
	_state->Start();
}

void MoveObject::MoveStart(int posx,int posy)
{
	float xMove = (float)posx * _speed;
	float yMove = (float)posy * _speed;


	_posX += xMove;
	_posY += yMove;


	Room * room= StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY);

	std::list<Component*> list = room->GetComponentList();

	std::list<Component*>::iterator itr;
	for (itr = list.begin(); itr != list.end(); itr++)
	{
		Component * com=(*itr);

		if (this == com)
			continue;

		float radius = com->GetRadius() + _radius;
		float distance = sqrtf(pow(abs(com->GetPosX() - _posX), 2) + pow(abs(com->GetPosY() - _posY), 2));


		if (distance < radius)
		{
			
			MessageFrom message;
			message.sender = this;
			message.reciver = com;
			message.message = L"Collison";
			MessagePost::GetInstance()->SendMessageW(message);

			//Ãæµ¹
			wchar_t  distanceText[256];
			swprintf(distanceText, L"distance:%f\n", distance);		//##testCode
			OutputDebugString(distanceText);
		}
	}
	

}
void MoveObject::SetPos(float posX, float posY)
{
	_posX = posX;
	_posY = posY;
}
void MoveObject::ReplaceState(eState stateType,State * changeState)
{
	std::map<eState, State*>::iterator itr = _StateMap.find(stateType);
	if (itr != _StateMap.end())
	{
		delete _StateMap[stateType];
		_StateMap.erase(stateType);
	}

	State * state = changeState;
	state->Init(this);
	_StateMap[stateType] = changeState;
}

void MoveObject::MountEquipItem(EquipItem * item)
{
	if(false== _equipItem.empty())
		_equipItem.pop();

	_equipItem.push(item);
}

void MoveObject::ReduceDurability(int reducePoint)
{
	if (false == _equipItem.empty())
	{
		EquipItem * item = _equipItem.front();
		if (eEquipItemType::EquipITEM_WEAPON == item->GetEquipType())
		{
			((EquipItemWeapon*)item)->ReduceDurability(reducePoint);
			if (((EquipItemWeapon*)item)->GetDurability() <= 0)
			{
				_equipItem.pop();
				item->DeInit();
				delete item;
			}
		}
	}
}