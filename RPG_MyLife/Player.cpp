#include "Player.h"
#include "Sprite.h"


#include "GlobalType.h"

#include "State.h"
#include "IdleState.h"
#include "MoveState.h"


Player::Player()
{
	_speed = 2.0f;
	_moveCoolTime = 0.01f;
}
Player::~Player() 
{

}

void Player:: Init(float posX, float posY,int mapX,int mapY)
{
	MoveObject::Init(posX, posY, mapX, mapY);

	_ObjectType = eComponentType::PlAYER;

	SetDirection(eDirection::UP);

	ReplaceState(eState::ES_IDLE, new IdleState());
	ReplaceState(eState::ES_MOVE, new MoveState());

	ChangeState(eState::ES_IDLE);
}

void Player::render()
{
	_state->render();
}

void Player::Update(float deltaTime)
{
	_state->Update(deltaTime);

}