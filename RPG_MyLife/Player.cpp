#include "Player.h"
#include "Sprite.h"


#include "GlobalType.h"

#include "State.h"
#include "IdleState.h"

Player::Player()
{
	
}
Player::~Player() 
{

}

void Player:: Init(float posX, float posY)
{
	_ObjectType = eComponentType::PlAYER;

 	_posX = posX;
	_posY = posY;

	SetDirection(eDirection::UP);


	ReplaceState(eState::ES_IDLE, new IdleState());

	ChangeState(eState::ES_IDLE);
}

void Player::render()
{
	_state->render();
}

void Player::Update(float deltaTime)
{
	_state->Update(deltaTime);

	
	float speed=0.003f;


}