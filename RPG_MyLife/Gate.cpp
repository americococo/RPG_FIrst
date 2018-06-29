#include "Gate.h"
#include "Sprite.h"



Gate::Gate()
{
}


Gate::~Gate()
{
}
void Gate::Init(int posX, int posY,eDirection GateDirection)
{
	_ObjectType = eComponentType::GATE;

	_GateDirection = GateDirection;

	_posX = posX;
	_posY = posY;

	_sprite = new Sprite(L"./Sprite/Gate/Gate.png", L"./Sprite/Gate/Gate.json");
	_sprite->Init();
	_sprite->setPostition(_posX, _posY);
}
void Gate::Update(float deltaTime)
{
	_sprite->Update(deltaTime);
}
void Gate::render()
{
	_sprite->render();
}
void Gate::DeInit()
{

}

void Gate::ReciverMessage(MessageFrom msgFrom)
{
	
}
