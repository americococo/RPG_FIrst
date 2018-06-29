#include "Player.h"
#include "Sprite.h"

Player::Player()
{

}
Player::~Player() 
{

}

void Player:: Init(int posX, int posY)
{
	_ObjectType = eComponentType::PlAYER;

	_posX = posX;
	_posY = posY;

	_sprite = new Sprite(L"./Sprite/player/player.png", L"./Sprite/player/player.json");
	_sprite->Init();
	_sprite->setPostition(_posX, _posY);
}

void Player::render()
{
	_sprite->render();
}

void Player::Update(float deltaTime)
{
	_sprite->Update(deltaTime);
}