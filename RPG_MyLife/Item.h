#pragma once
#include "FixedObject.h"


#include "MessageFrom.h"
#include <Windows.h>

enum eItemType
{
	Item_USING,
	Item_EQUIMENT,
	Item_NONE,
};

class Item : public FixedObject
{
public:
	Item();
	~Item();

	virtual	void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName);
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();

	virtual void ReciverMessage(MessageFrom msgFrom);


protected:
	eItemType _itemType;

public:
	eItemType GetItemType() { return _itemType; }
};

