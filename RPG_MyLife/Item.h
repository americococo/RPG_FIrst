#pragma once
#include "FixedObject.h"


#include "MessageFrom.h"

class Item : public FixedObject
{
public:
	Item();
	~Item();

	void Init(float posX, float posY, int mapX, int mapY);
	void Update(float deltaTime);
	void render();
	void DeInit();

	void ReciverMessage(MessageFrom msgFrom);
};

