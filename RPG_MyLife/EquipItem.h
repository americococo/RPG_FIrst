#pragma once
#include "Item.h"

enum eEquipItemType 
{
	EquipITEM_WEAPON,
	EquipITEM_CAP,
	EquipITEM_NONE,
};

class EquipItem : public Item
{
public:
	EquipItem();
	~EquipItem();


public:
	virtual void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName);

	virtual void ReciverMessage(MessageFrom msgFrom);



protected:
	eEquipItemType _equipItemType;

public:
	eEquipItemType GetEquipType() { return _equipItemType; }

};

