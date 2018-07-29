#include "AttackState.h"

#include "StageManager.h"
#include "Stage.h"
#include "Room.h"


#include "MoveObject.h"

#include "AttackShape.h"

AttackState::AttackState()
{

}
AttackState::~AttackState()
{

}

void AttackState::Start()
{
	State::Start();


	AttackShape * attackshape = new AttackShape();


	attackshape->Init(_character);

	StageManager::GetInstance()->GetStage()->GetRoom(_character->GetMapX(),_character->GetMapY())->AddComponent(attackshape);
	attackshape->SetPos(_character->GetPosX(), _character->GetPosY());

	_character->ReduceDurability(rand() % 3);
						
	_character->ChangeState(eState::ES_IDLE);
}