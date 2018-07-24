#include "AttackState.h"

#include "StageManager.h"
#include "Stage.h"
#include "Room.h"


#include "MoveObject.h"

AttackState::AttackState()
{

}
AttackState::~AttackState()
{

}

void AttackState::Start()
{
	State::Start();


	/*Attackshape * attackshape = new Attackshape();


	attackshape->init(_character);

	StageManager::GetInstance()->GetStage()->GetRoom(_character->GetMapX(),_character->GetMapY())->AddComponent(attackshape);*/

	_character->ChangeState(eState::ES_IDLE);
}