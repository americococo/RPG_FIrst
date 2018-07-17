#include "FixedObject.h"


#include "Sprite.h"
FixedObject::FixedObject()
{
}


FixedObject::~FixedObject()
{
}

void FixedObject::Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName)
{
	Component::Init(posX, posY, mapX, mapY);

	_ObjectType = eComponentType::NONE;


	_sprite = new Sprite(textureFileName, scriptFileName);
	_sprite->Init();
	_sprite->setPostition(posX, posY);

	_radius = ((_sprite->GetWidth() + _sprite->Getheight()) / 2) / 2;
}
void FixedObject::ReciverMessage(MessageFrom msgFrom)
{
	Component::ReciverMessage(msgFrom);
}


void FixedObject::SetPos(float posX, float posY)
{
	Component::SetPos(posX, posY);
	_sprite->setPostition(posX, posY);
}
void FixedObject::Update(float deltaTime)
{
	_sprite->Update(deltaTime);
}
void FixedObject::render()
{
	_sprite->render();
}
void FixedObject::DeInit()
{
	_sprite->deInit();
}