#include "UsingItem.h"

#include "Sprite.h"

#include "StageManager.h"
#include "Stage.h"
#include "Room.h"

#include "MoveObject.h"

void UsingItem::Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName)
{
	Item::Init(posX, posY, mapX, mapY, textureFileName,scriptFileName);

	_itemType = eItemType::Item_USING;
	_effectType =  (eEffectType)(rand() % 4);
}

void UsingItem::ReciverMessage(MessageFrom msgFrom)
{
	if (L"UseItem" == msgFrom.message)
	{
		MoveObject * character =(MoveObject*)msgFrom.sender;

		switch (_effectType)
		{
		case Effect_HP_PLUS:
			character->AffectHp(rand() % 5);
			break;
		case Effect_HP_MINUS:
			character->AffectHp(-rand() % 5);
			break;
		case Effect_Power_PLUS:
			character->AffectPower(rand() % 5);
			break;
		case Effect_Power_MINUS:
			character->AffectPower(-rand() % 5);
			break;
		}

		StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY)->AddremoveList(this);
		_sprite->deInit();
		delete this;
		return;
	}
}