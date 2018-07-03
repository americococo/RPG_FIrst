#include "Component.h"
#include "MessageFrom.h"

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
void Component::ReciverMessage(MessageFrom msgFrom)
{
	if (L"Collison" == msgFrom.message)
	{
		//충돌처리
	}
}

void Component::Init(float posX,float posY)
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