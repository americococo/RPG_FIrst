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

void Item::Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName)
{
	FixedObject::Init(posX, posY, mapX, mapY, textureFileName, scriptFileName);

	_ObjectType = eComponentType::ITEM;
	_itemType = eItemType::Item_NONE;
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