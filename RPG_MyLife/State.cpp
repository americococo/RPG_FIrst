#include "State.h"

#include "Component.h"
#include "Player.h"

#include "Sprite.h"
#include "GlobalType.h"
#include <Windows.h>
State::State()
{

}

State::~State()
{
}

void State::Init(Component * character)
{
	_character = character;
	createSprite();
}
void State::createSprite()
{
	_spriteVector.clear();

	WCHAR textureFileName[256];
	WCHAR scriptFileName[256];


	std::wstring type;


	switch (_character->GetComponentType())
	{
		case eComponentType::ENEMY:
			type = L"Enemy";
			break;
		case eComponentType::PlAYER:
			type = L"Player";
			break;
	}

	wsprintf(textureFileName, L"./Sprite/%s/%s.png",type.c_str(),type.c_str());


	//left
	{
		wsprintf(scriptFileName, L"./Sprite/%s/Left.json", type.c_str());
		Sprite * _sprite = new Sprite(textureFileName, scriptFileName);
		_sprite->Init();
		_spriteVector[eDirection::LEFT] = _sprite;
	}

	//right
	{
		wsprintf(scriptFileName, L"./Sprite/%s/Right.json", type.c_str());
		Sprite * _sprite = new Sprite(textureFileName, scriptFileName);
		_sprite->Init();
		_spriteVector[eDirection::RIGHT] = _sprite;
	}

	//up
	{
		wsprintf(scriptFileName, L"./Sprite/%s/Up.json", type.c_str());
		Sprite * _sprite = new Sprite(textureFileName, scriptFileName);
		_sprite->Init();
		_spriteVector[eDirection::UP]=_sprite;
	}

	//down
	{
		wsprintf(scriptFileName, L"./Sprite/%s/Down.json", type.c_str());
		Sprite * _sprite = new Sprite(textureFileName, scriptFileName);
		_sprite->Init();
		_spriteVector[eDirection::DOWN] = _sprite;
	}
}
void State::Start()
{

}	

void State::render()
{
	_spriteVector[((Player*)(_character))->GetDirection()]->setPostition(_character->GetPosX(), _character->GetPosY());
	_spriteVector[((Player*)(_character))->GetDirection()]->render();

}

void State::Update(float deltaTime)
{
	_spriteVector[((Player*)(_character))->GetDirection()]->Update(deltaTime);
}

void State::Stop()
{

}