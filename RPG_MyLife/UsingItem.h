#pragma once
#include "Item.h"

enum eEffectType
{
	Effect_HP_PLUS,
	Effect_HP_MINUS,
	Effect_Power_PLUS,
	Effect_Power_MINUS,
};

class UsingItem : public Item
{

public:
	void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName);

	void ReciverMessage(MessageFrom msgFrom);



private:
	eEffectType _effectType;

};