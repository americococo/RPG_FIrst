#include "EquipItem.h"

#include "Sprite.h"


#include "StageManager.h"
#include "Stage.h"
#include "Room.h"


#include "MoveObject.h"

EquipItem::EquipItem()
{
}


EquipItem::~EquipItem()
{
}

void EquipItem::Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName)
{
	Item::Init(posX, posY, mapX, mapY, textureFileName, scriptFileName);

	_itemType = eItemType::Item_EQUIMENT;
}

void EquipItem::ReciverMessage(MessageFrom msgFrom)
{
	if (L"UseItem" == msgFrom.message)
	{
		MoveObject * character = (MoveObject*)msgFrom.sender;

		character->MountEquipItem(this);

		StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY)->AddremoveList(this);

		return;
	}
}
