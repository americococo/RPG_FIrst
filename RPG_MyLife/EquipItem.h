#pragma once
#include "Item.h"
class EquipItem : public Item
{
public:
	EquipItem();
	~EquipItem();


public:
	void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName);

	void ReciverMessage(MessageFrom msgFrom);


};

