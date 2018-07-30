#include "Monster.h"
#include "Sprite.h"

#include "State.h"
#include "MoveState.h"

#include "MonsterIdleState.h"

Monster::Monster()
{
	_speed = 2.0f;
	_moveCoolTime = 0.001;
}
Monster::~Monster()
{

}

void Monster::Init(float posX, float posY, int mapX, int mapY, int hp, float power)
{
	MoveObject::Init(posX, posY, mapX, mapY, hp, power);

	_ObjectType = eComponentType::MONSTER;

	SetDirection(eDirection::UP);

	ReplaceState(eState::ES_IDLE, new MonsterIdleState());
	ReplaceState(eState::ES_MOVE, new MoveState());

	ChangeState(eState::ES_IDLE);
}

void Monster::render()
{
	MoveObject::render();
}

void Monster::Update(float deltaTime)
{
	_state->Update(deltaTime);
}