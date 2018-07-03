#include "Player.h"
#include "Sprite.h"
#include "State.h"

#include "GlobalType.h"

#include "GameSystem.h"
Player::Player()
{
	
}
Player::~Player() 
{

}

void Player:: Init(float posX, float posY)
{
	_ObjectType = eComponentType::PlAYER;

	_state = new State();


 	_posX = posX;
	_posY = posY;

	_direction = eDirection::UP;


	_state->Init(this);
}

void Player::render()
{
	_state->render();
}

void Player::Update(float deltaTime)
{
	_state->Update(deltaTime);

	
	float speed=0.001f;

	if (GameSystem::GetInstance()->IsKeyDown(VK_LEFT))
	{
		_direction = eDirection::LEFT;
		_posX -= speed;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		_direction = eDirection::RIGHT;
		_posX += speed;
	}

	if (GameSystem::GetInstance()->IsKeyDown(VK_UP))
	{
		_direction = eDirection::UP;
		_posY -= speed;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_DOWN))
	{
		_direction = eDirection::DOWN;
		_posY += speed;
	}
}