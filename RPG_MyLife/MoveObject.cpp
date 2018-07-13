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
void MoveObject::Init(float posX, float posY, int mapX, int mapY)
{
	Component::Init(posX, posY, mapX,mapY);


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
