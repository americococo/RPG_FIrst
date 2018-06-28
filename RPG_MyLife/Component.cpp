#include "Component.h"


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

void Component::Init(int posX,int posY)
{
	_posX = posX;
	_posY = posY;
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