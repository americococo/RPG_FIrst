#include "Item.h"
#include "Sprite.h"


#include "StageManager.h"
#include "Stage.h"
#include "Room.h"

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

	if (L"UseItem" == msgFrom.message)
	{
		StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY)->AddremoveList(this);
		_sprite->deInit();
		delete this;
		return;
	}
	
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