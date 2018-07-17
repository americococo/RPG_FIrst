#pragma once
#include "Component.h"
#include <Windows.h>

#include "MessageFrom.h"


class Sprite;

class FixedObject :	public Component
{
public:

	FixedObject();
	~FixedObject();


	virtual void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName);
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();

	virtual void SetPos(float posX, float posY);



	virtual void ReciverMessage(MessageFrom msgFrom);
protected:
	Sprite * _sprite;




};

