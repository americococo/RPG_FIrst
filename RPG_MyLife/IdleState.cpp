#include "IdleState.h"
#include "MoveObject.h"

#include "GameSystem.h"
#include "GlobalType.h"
IdleState::IdleState()
{

}
IdleState::~IdleState()
{

}

void IdleState::Update(float deltaTime)
{
	State::Update(deltaTime);

	if (eState::ES_NONE != _nextState)
	{
		_character->ChangeState(_nextState);
		return;
	}


	eDirection direction=eDirection::NONEDIRCTION;

	if (GameSystem::GetInstance()->IsKeyDown(VK_LEFT))
	{
		_character->SetDirection(eDirection::LEFT);
		direction = eDirection::LEFT;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		_character->SetDirection(eDirection::RIGHT);
		direction = eDirection::RIGHT;
	}

	if (GameSystem::GetInstance()->IsKeyDown(VK_UP))
	{
		_character->SetDirection(eDirection::UP);
		direction = eDirection::UP;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_DOWN))
	{
		_character->SetDirection(eDirection::DOWN);
		direction = eDirection::DOWN;
	}


	if (eDirection::NONEDIRCTION != direction)
		_nextState = eState::ES_MOVE;

	_character->SetAttackDuraction(deltaTime);

	if (GameSystem::GetInstance()->IsKeyDown(VK_CONTROL)&&_character->GetAttackDuraction() >= _character->GetAttackCoolTime()) //attack
	{
		_character->ReSetAttackDuraction();
		_nextState = eState::ES_ATTACK;
	}


}

void IdleState::Stop()
{

}