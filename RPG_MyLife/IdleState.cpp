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

	if (GameSystem::GetInstance()->IsKeyDown(VK_LEFT))
	{
		_character->SetDirection(eDirection::LEFT);
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		_character->SetDirection(eDirection::RIGHT);
	}

	if (GameSystem::GetInstance()->IsKeyDown(VK_UP))
	{
		_character->SetDirection(eDirection::UP);
		
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_DOWN))
	{
		_character->SetDirection(eDirection::DOWN);
		
	}

}

void IdleState::Stop()
{

}