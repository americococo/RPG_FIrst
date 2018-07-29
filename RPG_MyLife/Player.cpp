#include "Player.h"
#include "Sprite.h"


#include "GlobalType.h"

#include "State.h"
#include "IdleState.h"
#include "MoveState.h"
#include "AttackState.h"

#include "GameSystem.h"

#include "StageManager.h"
#include "Stage.h"
#include "Room.h"

#include "MessagePost.h"

#include "EquipItem.h"
#include "EquipItemWeapon.h"
Player::Player()
{
	_speed = 2.0f;
	_moveCoolTime = 0.01f;
}
Player::~Player() 
{

}

void Player:: Init(float posX, float posY,int mapX,int mapY,int hp,float power)
{
	MoveObject::Init(posX, posY, mapX, mapY,hp,power);

	_ObjectType = eComponentType::PlAYER;

	SetDirection(eDirection::UP);

	ReplaceState(eState::ES_IDLE, new IdleState());
	ReplaceState(eState::ES_MOVE, new MoveState());
	ReplaceState(eState::ES_ATTACK, new AttackState());

	ChangeState(eState::ES_IDLE);
}

void Player::render()
{
	MoveObject::render();
	
}

void Player::Update(float deltaTime)
{
	_state->Update(deltaTime);


	if (GameSystem::GetInstance()->IsKeyDown(VK_SPACE))
	{
		std::list<Component*> componentList = StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY)->GetComponentList();

		for (std::list<Component*>::iterator itr = componentList.begin(); itr != componentList.end(); itr++)
		{
			Component * component = (*itr);
			if (eComponentType::ITEM == component->GetComponentType())
			{
				Component * com = (*itr);

				if (this == com)
					continue;

				float radius = com->GetRadius() + _radius;
				float distance = sqrtf(pow(abs(com->GetPosX() - _posX), 2) + pow(abs(com->GetPosY() - _posY), 2));


				if (distance < radius)
				{

					MessageFrom message;
					message.sender = this;
					message.reciver = com;
					message.message = L"UseItem";
					MessagePost::GetInstance()->SendMessageW(message);

					//Ãæµ¹
					wchar_t  distanceText[256];
					swprintf(distanceText, L"distance:%f\n", distance);		//##testCode
					OutputDebugString(distanceText);
				}
			}
		}


	}
}