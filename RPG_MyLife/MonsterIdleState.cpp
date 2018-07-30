#include "MonsterIdleState.h"

#include "MoveObject.h"
#include "StageManager.h"
#include "Stage.h"
#include "Room.h"

#include <list>

MonsterIdleState::MonsterIdleState()
{
}

MonsterIdleState::~MonsterIdleState()
{
}
void MonsterIdleState::Init(MoveObject * character)
{
	State::Init(character);
	_IdleSkipTime = 0.02f;
	_duractionTime = 0.0f;
}

void MonsterIdleState::Update(float deltaTime)
{
	State::Update(deltaTime);

	_duractionTime += deltaTime;

	if (!(_duractionTime >= _IdleSkipTime))
		return;
	
	_duractionTime = 0.0f;

	if (eState::ES_NONE != _nextState)
	{
		_character->ChangeState(_nextState);
		return;
	}

	Room * room = StageManager::GetInstance()->GetStage()->GetRoom(_character->GetMapX(), _character->GetMapY());

	std::list<Component*>::iterator itr;
	std::list<Component*> list = room->GetComponentList();

	Component * target=nullptr;

	for (itr = list.begin(); itr != list.end(); itr++)
	{
		if (eComponentType::PlAYER == (*itr)->GetComponentType())
		{
			target = (*itr);
			break;
		}
	}

	if (target != nullptr)
	{
		if (0 > target->GetPosX() - _character->GetPosX())
		{
			_character->SetDirection(eDirection::LEFT);
			_nextState = eState::ES_MOVE;
			return;
		}
		if (0 < target->GetPosX() - _character->GetPosX())
		{
			_character->SetDirection(eDirection::RIGHT);
			_nextState = eState::ES_MOVE;
			return;
		}

		if (0 > target->GetPosY() - _character->GetPosY())
		{
			_character->SetDirection(eDirection::UP);
			_nextState = eState::ES_MOVE;
			return;
		}
		if (0 < target->GetPosY() - _character->GetPosY())
		{
			_character->SetDirection(eDirection::DOWN);
			_nextState = eState::ES_MOVE;
			return;
		}
		
	}

}