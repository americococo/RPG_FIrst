#include "Component.h"

#include "Sprite.h"


Component::Component()
{
	_ObjectType = eComponentType::NONE;
}


Component::~Component()
{
}

eComponentType Component::GetComponentType()
{
	return _ObjectType;
}

void Component::SetPos(float posX, float posY)
{
	_posX = posX; _posY = posY;
	_sprite->setPostition(_posX, _posY);
}
void Component::ReciverMessage(MessageFrom msgFrom)
{
	if (L"Collison" == msgFrom.message)
	{
		//�浹ó��
	}
}

void Component::Init(float posX,float posY,int mapX,int mapY)
{
	_posX = posX;
	_posY = posY;

	_mapX = mapX;
	_mapY = mapY;

	_ObjectType = eComponentType::NONE;
}
void Component::Update(float deltaTime)
{

}
void Component::render()
{

}
void Component::DeInit()
{

}