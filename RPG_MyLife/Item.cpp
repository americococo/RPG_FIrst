#include "Item.h"

#include "Sprite.h"

Item::Item()
{
}


Item::~Item()
{
}

void Item::Init(float posX, float posY, int mapX, int mapY)
{
	FixedObject::Init(posX, posY, mapX, mapY, L"./Sprite/Item/Item.png", L"./Sprite/Item/Item.json");

	_ObjectType = eComponentType::ITEM;
}

void Item::ReciverMessage(MessageFrom msgFrom)
{

}

void Item::Update(float deltaTime)
{
	FixedObject::Update(deltaTime);
}
void Item::render()
{
	FixedObject::render();
}
void Item::DeInit()
{
	FixedObject::DeInit();
}