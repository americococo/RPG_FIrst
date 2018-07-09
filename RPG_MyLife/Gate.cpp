#include "Gate.h"
#include "Sprite.h"

Gate::Gate()
{
}


Gate::~Gate()
{
}
void Gate::Init(float posX, float posY,int mapX,int mapY,eDirectionGATE GateDirection)
{
	Component::Init(posX, posY, mapX, mapY);
	_ObjectType = eComponentType::GATE;

	_GateDirection = GateDirection;

	_sprite = new Sprite(L"./Sprite/Gate/Gate.png", L"./Sprite/Gate/Gate.json");
	_sprite->Init();
	_sprite->setPostition(_posX, _posY);

	_radius =( (_sprite->GetWidth() + _sprite->Getheight() ) /2) /2;
}

void Gate::SetGateDirection(eDirectionGATE direction)
{
	_GateDirection = direction;
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
